using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Chatclientwf
{
    class Client
    {
        private Socket sender;
        private byte[] bytes;
        private string _nameOfUser;
        public string NameOfUser { get { return _nameOfUser; } set { _nameOfUser = value; } }
        private bool _isConnected;
        private string _serverIP;
        public string ServerIp { get { return _serverIP; } set { _serverIP = value; } }

        public Client()
        {
            bytes = new byte[1024];
            _nameOfUser = "Feri";
            _serverIP = Dns.GetHostName();
            _isConnected = false;

        }

        public void Connect()
        {
             while (!_isConnected)
            {
                try
                {
                    IPHostEntry ipHostInfo = Dns.Resolve(_serverIP);
                    IPAddress ipAddress = ipHostInfo.AddressList[0];
                    IPEndPoint remoteEP = new IPEndPoint(ipAddress, 11000);

                    sender = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                    try
                    {
                        sender.Connect(remoteEP);
                        Console.WriteLine("Socket connected to {0}", sender.RemoteEndPoint.ToString());
                        _isConnected = true;

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

            if (_isConnected)
            {
                while (true)
                {
                    if (sender.Available > 0)
                    {
                        int bytesRec = sender.Receive(bytes);
                        Send(_nameOfUser);
                        break;
                    }
                }
            }
        }

         public void Send(string message)
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

        public string Receive()
        {
            try
            {
                while (sender.Available > 0)
                {
                    int bytesRec = sender.Receive(bytes);
                    return Encoding.UTF8.GetString(bytes, 0, bytesRec);
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
            return "";
        }

        public void Disconnect()
        {
            _isConnected = false;
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


        ~Client()
        {
            if (_isConnected)
            {
                Disconnect();
            }
        }
    }
}
