using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Caesar
{
    class CaesarApp
    {
        private string InputText;
        private Arguments myArgs;
        private Error myError;

        public CaesarApp(ref string[] args)
        {
            myArgs = new Arguments(ref args);
            myError = new Error(ref myArgs);
        }

        public void Run()
        {
            if (myError.ErrorMessage != "")
            {
                Console.WriteLine(myError.ErrorMessage);
                return;
            }
        }
    }
}
