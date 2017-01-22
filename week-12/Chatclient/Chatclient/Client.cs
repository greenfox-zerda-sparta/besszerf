using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Chatclient
{
    class Client
    {

        private Socket sender;
        private byte[] bytes;
        private string _nameOfUser;
        private bool connected;
        private string serverIP;

        public Client()
        {
            bytes = new byte[1024];
            _nameOfUser = "";
            connected = false;
            serverIP = Dns.GetHostName();
            Connect();

        }

        public void Connect()
        {
            while (!connected)
            {
                try
                {
                    IPHostEntry ipHostInfo = Dns.Resolve(serverIP);
                    IPAddress ipAddress = ipHostInfo.AddressList[0];
                    IPEndPoint remoteEP = new IPEndPoint(ipAddress, 11000);

                    sender = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                    try
                    {
                        sender.Connect(remoteEP);
                        Console.WriteLine("Socket connected to {0}", sender.RemoteEndPoint.ToString());
                        connected = true;

                    }
                    catch (ArgumentNullException ane)
                    {
                        Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
                    }
                    catch (SocketException se)
                    {
                        Console.WriteLine("SocketException : {0}", se.ToString());
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine("Unexpected exception : {0}", e.ToString());
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.ToString());
                }
            }

            if (connected)
            {
                if (sender.Available > 0)
                {
                    int bytesRec = sender.Receive(bytes);
                    Console.Write(Encoding.UTF8.GetString(bytes, 0, bytesRec));
                    _nameOfUser = Console.ReadLine();
                    Send(_nameOfUser);
                }
            }
        }

        public void Run()
        {
            string message;
            message = "";
            while (true)
            {
                Receive();
                if (Console.KeyAvailable)
                {
                    message = Console.ReadLine();
                    Send(message);
                    if (message == "quit!")
                    {
                        break;
                    }
                }
            }
        }

        private void Send(string message)
        {
            message += "\n";
            try
            {
                byte[] msg = Encoding.UTF8.GetBytes(message);
                int bytesSent = sender.Send(msg);
            }
            catch (ArgumentNullException ane)
            {
                Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
            }
            catch (SocketException se)
            {
                Console.WriteLine("SocketException : {0}", se.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine("Unexpected exception : {0}", e.ToString());
            }
        }

        private void Receive()
        {
            try
            {
                while (sender.Available > 0)
                {
                    int bytesRec = sender.Receive(bytes);
                    Console.Write(Encoding.UTF8.GetString(bytes, 0, bytesRec));
                }
            }
            catch (ArgumentNullException ane)
            {
                Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
            }
            catch (SocketException se)
            {
                Console.WriteLine("SocketException : {0}", se.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine("Unexpected exception : {0}", e.ToString());
            }
        }

        ~Client()
        {
            try
            {
                sender.Shutdown(SocketShutdown.Both);
                sender.Close();
            }
            catch (ArgumentNullException ane)
            {
                Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
            }
            catch (SocketException se)
            {
                Console.WriteLine("SocketException : {0}", se.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine("Unexpected exception : {0}", e.ToString());
            }
        }
    }
}