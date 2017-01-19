﻿using System;
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
        List<Socket> SocketSet;
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
            SocketSet = new List<Socket>();
            // Create a TCP/IP socket.
            listener = new Socket(AddressFamily.InterNetwork,
                SocketType.Stream, ProtocolType.Tcp);
            listener.Blocking = false;
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

        private void ReceiveConnections()
        {
            try
            {
                SocketSet.Add(listener.Accept());
                Console.WriteLine("Connected client number {0}", SocketSet.Count);
            }
            catch { }
        }

        public void Run()
        {
            Console.WriteLine("Server is running...");
            while (true)
            {
                ReceiveConnections();
                for(int i = 0; i < SocketSet.Count; ++i)
                {
                    Receive(SocketSet[i]); // Receiving from one
                    if(data != null)
                    {
                        for (int k = 0; k < SocketSet.Count; ++k)
                        {
                            if(i == k) //Sending to the others
                            {
                                continue;
                            }
                            Send(SocketSet[k]);
                        }

                    }
                }
            }
        }

        private void Send(Socket handler)
        {
            // Echo the data back to the client.
            byte[] msg = Encoding.ASCII.GetBytes(data);

            handler.Send(msg);
        }

        private void Receive(Socket handler)
        {
            bytes = new byte[1024];
            data = null;
            if (handler.Available > 0)
            {
                 int bytesRec = handler.Receive(bytes);
                data += Encoding.ASCII.GetString(bytes, 0, bytesRec);
                if (data.IndexOf("\n") > -1)
                {
                    // Show the data on the console.
                    Console.Write(data);
                }
            }
        }

        ~Server()
        {
            foreach (Socket handler in SocketSet)
            {
                handler.Shutdown(SocketShutdown.Both);
                handler.Close();
            }
        }
    }
}
