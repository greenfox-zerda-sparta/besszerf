﻿using System;

namespace Todo
{
    class Arguments
    {
        private string[] _args;

        public Arguments(string[] args)
        {
            _args = args;
            string FirstArgument = GetFirstArgument();
            if (FirstArgument == "")
            {
                PrintUsage();
                return;
            }
            if (FirstArgument == "-l")
            {
               List();
                return;
            }
            if (FirstArgument == "-a")
            {
                Add();
                return;
            }
            if (FirstArgument == "-r")
            {
                Remove();
                return;
            }
            if (FirstArgument == "-c")
            {
                Check();
                return;
            }
            if(FirstArgument[0] == '-')
            {
                Console.WriteLine("Unsupported argument.");
                Console.WriteLine();
            }
            PrintUsage();
        }

        private string GetFirstArgument()
        {
            string result = "";
            try
            {
                result = _args[0];
            } catch { }
            return result;
        }

        private void PrintUsage()
        {
            Console.WriteLine("   CLI Todo application");
            Console.WriteLine("   ====================");
            Console.WriteLine();
            Console.WriteLine("   Command line arguments:");
            Console.WriteLine("    -l   Lists all the tasks");
            Console.WriteLine("    -a   Adds a new task");
            Console.WriteLine("    -r   Removes a task");
            Console.WriteLine("    -c   Completes a task");
        }

        private void List()
        {
            if (_args.Length > 1)
            {
                Console.WriteLine("Too many arguments.");
                return;
            }
             Console.WriteLine("Listing...");
        }

        private void Add()
        {
            if(_args.Length > 2)
            {
                Console.WriteLine("Too many arguments.");
                return;
            }
            if(_args.Length < 2)
            {
                Console.WriteLine("No task is provided.");
                return;
            }
            Console.WriteLine("Adding task...");
        }

        private void Remove()
        {
            if (_args.Length > 2)
            {
                Console.WriteLine("Too many arguments.");
                return;
            }
            if (_args.Length < 2)
            {
                Console.WriteLine("No index is provided.");
                return;
            }
            int index;
            try
            {
                index = Int32.Parse(_args[1]);
            }
            catch
            {
                Console.WriteLine("Index is not a number.");
                return;
            }
            Console.WriteLine("Removing item {0}...", index);
        }

        private void Check()
        {
            if (_args.Length > 2)
            {
                Console.WriteLine("Too many arguments.");
                return;
            }
            if (_args.Length < 2)
            {
                Console.WriteLine("No index is provided.");
                return;
            }
            int index;
            try
            {
                index = Int32.Parse(_args[1]);
            }
            catch
            {
                Console.WriteLine("Index is not a number.");
                return;
            }
            Console.WriteLine("Checking item {0}...", index);
        }


    }
}
