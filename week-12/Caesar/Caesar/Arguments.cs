using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Caesar
{
    class Arguments
    {
        private string[] args;
        private int argsLength;
        public int ArgsLength{ get { return argsLength; } }
        private string inputFileName;
        public string InputFileName { get { return inputFileName; } }
        private bool isFlagS;
        public bool IsFlagS { get { return isFlagS; } }
        private bool isArgS;
        public bool IsArgS { get { return isArgS; } }
        private int shift;
        public int Shift { get { return shift; } }
        private bool isFlagO;
        public bool IsFlagO { get { return isFlagO; } }
        private bool isArgO;
        public bool IsArgO { get { return isArgO; } }
        private string outputFileName;
        public string OutputFileName { get { return outputFileName; } }

        public Arguments(ref string[] args)
        {
            this.args = args;
            argsLength = args.Length;
            inputFileName = "";
            outputFileName = "";
            isFlagS = false;
            shift = 100;
            isFlagO = false;
            isArgS = false;
            isArgO = false;
            ParseInputFileName();
            ParseShift();
            ParseOutput();
        }

        private void ParseInputFileName()
        {
            string FileName;
            try
            {
                FileName = args[0];
            }
            catch
            {
                FileName = "";
            }
            if (FileName == "-s" || FileName == "-o")
            {
                FileName = "";
            }
            inputFileName = FileName;
        }

        private void ParseShift()
        {
            int IndexOfFlagS = GetIndexFlag("-s");
            isFlagS = IndexOfFlagS > -1;
            string ShiftArg = GetArg(IndexOfFlagS + 1);
            isArgS = ShiftArg.Length > 0 && ShiftArg != "-o";
            if (isArgS)
            {
                try
                {
                    shift = Int32.Parse(ShiftArg) % 26;

                }
                catch {}
            }
        }

        private int GetIndexFlag(string Flag)
        {
            for (int i = 0; i < args.Length; i++)
            {
                if (args[i] == Flag)
                {
                    return i;
                }
            }
            return -1;
        }

        private string GetArg(int index)
        {
            try
            {
                return args[index];
            }
            catch
            {
                return "";
            }
        }

        private void ParseOutput()
        {
            int IndexOfFlagO = GetIndexFlag("-o");
            isFlagO = IndexOfFlagO > -1;
            string outFile = GetArg(IndexOfFlagO + 1);
            isArgO = outFile.Length > 0 && outFile != "-s";
            if (isArgO)
            {
                outputFileName = outFile;
            }
        }
    }
}
