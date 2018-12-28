using System;

namespace PATH_Modifier_Custom_Action
{
    class Program
    {
        #region Constants
        const int ERROR_RETURN_VALUe = 1;
        const int SUCCESS_RETURN_VALUE = 0;
        const int THREE_ARGUMENTS = 3;
        const string INSTALL_PATH_ARGUMENT = "--install_path";
        const string UNINSTALL_PATH_ARGUMENT = "--uninstall_path";

        #endregion

        static int Main(string[] args)
        {
            if (args.Length != THREE_ARGUMENTS)
            {
                Console.WriteLine("<ERROR> There are not enough arguments to execute this program.");
                return DoesUserContinueInstall();
            }

             
            string path = ExtractPathFromArgs(args);
            if (!ValidatePath(path))
            {
                Console.WriteLine("<ERROR> The input program path for the PATH env variable is incorrect!");
                return DoesUserContinueInstall();
            }


            return SUCCESS_RETURN_VALUE;
        }

        static int DoesUserContinueInstall()
        {
            Console.WriteLine("<CRITICAL> Failed to add to PATH.");
            Console.WriteLine("<QUERY> Continue installation without adding the program path to the PATH env variable? (Y/N)");
            string answerToQuestionChar = Console.ReadKey().Key.ToString();
            if (answerToQuestionChar == "Y")
            {
                return SUCCESS_RETURN_VALUE;
            }
            else
            {
                return ERROR_RETURN_VALUe;
            }
        }

        static bool ValidatePath(string path)
        {
            return Uri.IsWellFormedUriString(path, UriKind.Absolute);
        }

        static string ExtractActionFromArgs(string[] args)
        {
            string secondArgument = args[1];
            return secondArgument;
        }

        static string ExtractPathFromArgs(string[] args)
        {
            string thirdArgument = args[2];
            return thirdArgument;
        }

    }
}
