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
        private bool _firstRun;
        public Client()
        {
            // Data buffer for incoming data.
            //            byte[] bytes = new byte[1024];
            bytes = new byte[1024];
            _firstRun = true;
            _nameOfUser = "";

            // Connect to a remote device.
            try
            {
                // Establish the remote endpoint for the socket.
                // This example uses port 11000 on the local computer.
                IPHostEntry ipHostInfo = Dns.Resolve(Dns.GetHostName());
                IPAddress ipAddress = ipHostInfo.AddressList[0];
                IPEndPoint remoteEP = new IPEndPoint(ipAddress, 11000);

                // Create a TCP/IP  socket.
                //Socket sender = new Socket(AddressFamily.InterNetwork,
                //    SocketType.Stream, ProtocolType.Tcp);
                sender = new Socket(AddressFamily.InterNetwork,
                     SocketType.Stream, ProtocolType.Tcp);

                // Connect the socket to the remote endpoint. Catch any errors.
                try
                {
                    sender.Connect(remoteEP);

                    Console.WriteLine("Socket connected to {0}",
                        sender.RemoteEndPoint.ToString());



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

        public void Run()
        {
            string message;
            while (true)
            {
                if(_firstRun)
                {
                    Console.Write("Enter your name ");
                }
                Console.Write(_nameOfUser + "> ");
                message = Console.ReadLine();
                if (message != "" && !_firstRun)
                {
                    Send(_nameOfUser + ": " + message);
                    Receive();
                }
                if (message == "quit!")
                {
                    break;
                }
                if (_firstRun)
                {
                    _nameOfUser = message;
                    _firstRun = false;
                    message = "";
                }
            }

        }

        private void Send(string message)
        {
            message += "\n";
            try
            {
                // Encode the data string into a byte array.
                byte[] msg = Encoding.ASCII.GetBytes(message);

                // Send the data through the socket.
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
                // Receive the response from the remote device.
                int bytesRec = sender.Receive(bytes);
                Console.Write(Encoding.ASCII.GetString(bytes, 0, bytesRec));
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
                // Release the socket.
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
