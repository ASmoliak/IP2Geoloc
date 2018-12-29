using System;
using System.Windows.Forms;

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
                string errorMessage = e.Message + "\n" + "Continue installer?";
                DialogResult userAnswer = MessageBox.Show(errorMessage, "Exception occured", MessageBoxButtons.YesNo, 
                    MessageBoxIcon.Error);
                programReturnValue = (userAnswer == DialogResult.Yes) ? SUCCESS_RETURN_VALUE : ERROR_RETURN_VALUe;
            }

            return programReturnValue;
        }
    }
}