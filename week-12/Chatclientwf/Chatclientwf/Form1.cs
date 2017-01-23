using System;
using System.Threading;
using System.Windows.Forms;

namespace Chatclientwf
{
    public partial class Form1 : Form
    {
        private bool _isConnect;
        private Client _myClient;
        private string _messageToSend;
        private string _receivedMessage;
        ManualResetEvent _shutdownEvent = new ManualResetEvent(false);
        ManualResetEvent _pauseEvent = new ManualResetEvent(true);
        Thread _thread;
        delegate void SetTextCallback(string text);

        public Form1()
        {
            _myClient = new Client();
            InitializeComponent();
            button1.Enabled = false;
            textBox3.Text = _myClient.ServerIp;
            textBox4.Text = _myClient.NameOfUser;
            _isConnect = true;
            _messageToSend = "";
            _receivedMessage = "";
            Start_thread();
            Pause_thread();
        }

        private void button2_MouseClick(object sender, MouseEventArgs e)
        {
            if (_isConnect)
            {
                button2.Text = "Disconnect";
                textBox3.ReadOnly = true;
                textBox4.ReadOnly = true;
                _myClient.ServerIp = textBox3.Text;
                _myClient.NameOfUser = textBox4.Text;
                _myClient.Connect();
                Resume_thread();
                button1.Enabled = true;
            }
            else
            {
                button2.Text = "Connect";
                textBox3.ReadOnly = false;
                textBox4.ReadOnly = false;
                button1.Enabled = false;
                _myClient.Disconnect();
                Pause_thread();
            }
            _isConnect = !_isConnect;
        }

        private void button1_MouseClick(object sender, MouseEventArgs e)
        {
            _messageToSend = textBox1.Text;
            textBox1.Text = "";
            textBox2.AppendText(_messageToSend + Environment.NewLine);
            _myClient.Send(_messageToSend);
        }

        private void SetText(string NewText)
        {

            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox2.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText);
                this.Invoke(d, new object[] { NewText });
            }
            else
            {
                this.textBox2.AppendText(NewText + Environment.NewLine);
            }
        }

        private void UpdateIncomingMessages()
        {
            while (true)
            {
                _pauseEvent.WaitOne(Timeout.Infinite);
                if (_shutdownEvent.WaitOne(0))
                {
                    break;
                }

                _receivedMessage = _myClient.Receive();
                if (_receivedMessage != "")
                {
                    SetText(_receivedMessage);
                }
            }
        }

        void Start_thread()
        {
            _thread = new Thread(UpdateIncomingMessages);
 //           _thread.IsBackground = true;
            _thread.Start();

        }

        public void Pause_thread()
        {
            _pauseEvent.Reset();
        }

        public void Resume_thread()
        {
            _pauseEvent.Set();
        }

        public void Stop_thread()
        {
            _shutdownEvent.Set();
            _pauseEvent.Set();
            _thread.Join();
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (!_isConnect)
            {
                _myClient.Disconnect();
                Pause_thread();
            }
            Stop_thread();
        }
    }
}
