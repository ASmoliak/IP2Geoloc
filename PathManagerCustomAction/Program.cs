using System;

namespace PathManagerCustomAction
{
    class Program
    {
        const int ERROR_RETURN_VALUe = 1;
        const int SUCCESS_RETURN_VALUE = 0;

        static int Main(string[] args)
        {
            int programReturnValue = SUCCESS_RETURN_VALUE;
            try
            {
                ArgumentParser customActionArgReader = new ArgumentParser(args);
                PathVariableAction actionToExecute = customActionArgReader.GetActionValue();
                string path = customActionArgReader.GetProgramPath();

                PATH_Manager customActionPathManager = new PATH_Manager(path);
                if (actionToExecute == PathVariableAction.InstallPathVariable)
                {
                    customActionPathManager.AddToPATH();
                }
                else
                {
                    customActionPathManager.RemoveFromPATH();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine("<CRITICAL> Custom action failed, failed to add to PATH.");
                programReturnValue = GetCustomActionReturnValue();
            }

            return programReturnValue;
        }

        static int GetCustomActionReturnValue()
        {
            Console.WriteLine("<QUERY> Continue installation without adding the program path to the PATH env variable? (Y/N)");
            string answerToQuestionChar = Console.ReadKey().Key.ToString().ToUpper();
            if (answerToQuestionChar == "Y")
            {
                return SUCCESS_RETURN_VALUE;
            }
            else
            {
                return ERROR_RETURN_VALUe;
            }
        }
    }
}