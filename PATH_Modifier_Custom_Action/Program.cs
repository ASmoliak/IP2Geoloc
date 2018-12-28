using System;

namespace PATH_Modifier_Custom_Action
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
                ArgumentReader customActionArgReader = new ArgumentReader(args);
                PathVariableAction actionToExecute = customActionArgReader.GetActionValue();
                string path = customActionArgReader.GetProgramPath();

                PathManager customActionPathManager = new PathManager(path);
                if(actionToExecute == PathVariableAction.InstallPathVariable)
                {
                    customActionPathManager.AddProgramToPath();
                }
                else 
                {
                    customActionPathManager.RemoveProgramFromPath();
                }
                
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("<CRITICAL> Custom action failed, failed to add to PATH.");
                programReturnValue = GetCustomActionReturnValue();
            }
            return programReturnValue;
        }

        static int GetCustomActionReturnValue()
        {
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
    }
}
