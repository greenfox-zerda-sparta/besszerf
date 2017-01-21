using System;
using System.Net;
using System.Net.Sockets;
using System.Collections.Generic;
using System.Text;

namespace Chatserver
{
    class Server
    {
        public static string data;

        Socket listener;
        Dictionary<Socket, string> SocketSet;
        List<Socket> ToRemove;
        byte[] bytes;

        public Server()
        {
            // Data buffer for incoming data.
            //            byte[] bytes = new Byte[1024];
            // Establish the local endpoint for the socket.
            // Dns.GetHostName returns the name of the 
            // host running the application.
            IPHostEntry ipHostInfo = Dns.Resolve(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 11000);
            SocketSet = new Dictionary<Socket, string>();
            // Create a TCP/IP socket.
            listener = new Socket(AddressFamily.InterNetwork,
                SocketType.Stream, ProtocolType.Tcp);
            listener.Blocking = false;
            ToRemove = new List<Socket>();
            try
            {
                listener.Bind(localEndPoint);
                listener.Listen(10);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

        }

        public void Run()
        {
            Console.WriteLine("Server is running...");
            while (true)
            {
                ReceiveConnections();
                Messaging();
                RemoveDisconnectedClients();
            }
        }

        private void ReceiveConnections()
        {
            try
            {
                Socket tempSocket = listener.Accept();
                Console.WriteLine("Connected client number {0}", SocketSet.Count + 1);
                data = "Enter your name >";
                Send(tempSocket);
                data = null;
                while (data == null)
                {
                    Receive(tempSocket);
                }
                data = data.Remove(data.Length - 1, 1);
                SocketSet.Add(tempSocket, data);
                data = null;
            }
            catch { }
        }

        private void Messaging()
        {
            foreach (KeyValuePair<Socket, string> Socket in SocketSet)
            {
                Receive(Socket.Key); // Receiving from one
                if (data != null)
                {
                    data = Socket.Value + "> " + data;
                    foreach (KeyValuePair<Socket, string> Handler in SocketSet)
                    {
                        if (Socket.Key == Handler.Key) //Sending to the others
                        {
                            continue;
                        }
                        Send(Handler.Key);
                    }

                }
            }
        }

        private void RemoveDisconnectedClients()
        {
            // Removing disonnected Sockets from SocketSet
            for (int i = 0; i < ToRemove.Count; ++i)
            {
                SocketSet.Remove(ToRemove[i]);
            }
            ToRemove.Clear();
        }

        private void Send(Socket handler)
        {
            // Echo the data back to the client.
            try
            {
                byte[] msg = Encoding.UTF8.GetBytes(data);
                handler.Send(msg);
            }
            catch
            {
                Console.WriteLine("Client {0} is disconnected", SocketSet[handler]);
                ToRemove.Add(handler);
            }
        }

        private void Receive(Socket handler)
        {
            bytes = new byte[1024];
            data = null;
            if (handler.Available > 0)
            {
                int bytesRec = handler.Receive(bytes);
                data += Encoding.UTF8.GetString(bytes, 0, bytesRec);
                if (data.IndexOf("\n") > -1)
                {
                    // Show the data on the console.
                    string name = "";
                    if (SocketSet.ContainsKey(handler))
                    {
                       name = SocketSet[handler];
                    }
                    Console.Write("{0}> {1}", name, data);
                }
            }
        }

        ~Server()
        {
            foreach (KeyValuePair<Socket, string> handler in SocketSet)
            {
                handler.Key.Shutdown(SocketShutdown.Both);
                handler.Key.Close();
            }
            SocketSet.Clear();
        }
    }
}
