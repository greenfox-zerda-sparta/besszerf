using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Chatclient
{
    class Program
    {

        public static int Main(String[] args)
        {
            Client myClient = new Client();
            string message;
            while (true)
            {
                Console.Write(">> ");
                message = Console.ReadLine();
                myClient.Send(message);
                myClient.Receive();
                if (message == "quit!")
                {
                    break;
                }
            }
            return 0;
        }

    }
}
