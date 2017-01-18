using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Caesar
{
    class Program
    {
        static void Main(string[] args)
        {
            CaesarApp myApp = new CaesarApp(ref args);
            myApp.Run();
        }
    }
}
