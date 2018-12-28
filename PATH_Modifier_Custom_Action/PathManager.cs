using System;

namespace PATH_Modifier_Custom_Action
{
    class PathManager
    {
        #region C'tor and 'dtor
        public PathManager(string programPath)
        {
            _programPath = programPath;
        }
        #endregion

        #region Public Methods
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
        #endregion

        #region Private Methods
        bool DoesProgramExistInPath()
        {
            bool returnValue = false;
            return returnValue;
        }
        #endregion

        #region Private Members
        string _programPath;
        #endregion
    }
}
