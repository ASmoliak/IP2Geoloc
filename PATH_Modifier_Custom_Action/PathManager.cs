using System;

namespace PATH_Modifier_Custom_Action
{
    class PathManager
    {
        public PathManager(string programPath)
        {
            _programPath = programPath;
        }

        public void AddProgramToPath()
        {
            if (DoesProgramExistInPath())
            {
                throw new SystemException("The path already exists in the PATH env variable.");
            }
        }

        public void RemoveProgramFromPath()
        {
            if (!DoesProgramExistInPath())
            {
                throw new SystemException("The Program Path does not exist in the PATH env variable.");
            }
        }

        bool DoesProgramExistInPath()
        {
            bool returnValue = false;
            return returnValue;
        }

        string _programPath;
    }
}
