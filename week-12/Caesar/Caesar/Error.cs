using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Caesar
{
    class Error
    {
        private string errorMessage;
        public string ErrorMessage { get { return errorMessage; } }

        public Error(ref Arguments ArgumentInstance)
        {
            errorMessage = "";
            if (ArgumentInstance.InputFileName == "")
            {
                errorMessage = "No filename is provided.";
            }
            else if (MissingShiftArgument(ref ArgumentInstance))
            {
                errorMessage = "No shift is provided.";
            }
            else if (IsInvalidShiftArg(ref ArgumentInstance))
            {
                errorMessage = "Shift argument is invalid.";
            }
            else if (MissingOutFileArgument(ref ArgumentInstance))
            {
                errorMessage = "No output file name is provided.";
            }
            else if (TooManyArguments(ref ArgumentInstance))
            {
                errorMessage = "Too many arguments.";
            }
        }

        private bool MissingShiftArgument(ref Arguments aInstance)
        {
            return (!aInstance.IsFlagS || !aInstance.IsArgS);
        }

        private bool IsInvalidShiftArg(ref Arguments aInstance)
        {
            return (aInstance.Shift > 26);
        }

        private bool MissingArguments(ref Arguments aInstance)
        {
            return (aInstance.IsFlagS && aInstance.IsFlagO && !aInstance.IsArgS && !aInstance.IsArgO);
        }

        private bool MissingOutFileArgument(ref Arguments aInstance)
        {
            return (aInstance.IsFlagO && !aInstance.IsArgO);
        }

        private bool TooManyArguments(ref Arguments aInstance)
        {
            return (aInstance.ArgsLength > 5 || (aInstance.ArgsLength > 3 && !aInstance.IsFlagO));
        }

    }
}