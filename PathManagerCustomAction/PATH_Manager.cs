using System;
using System.Collections.Generic;

namespace PathManagerCustomAction
{
    class PATH_Manager
    {
        public PATH_Manager(string programPath)
        {
            _targetProgramPath = programPath;
            _currentSystemPATH = GetSystemPATH();
        }

        public void AddToPATH()
        {
            if (DoesProgramExistInPATH())
            {
                throw new SystemException("The path already exists in PATH.");
            }

            _currentSystemPATH.Add(_targetProgramPath);
            SetSystemPATH();
        }

        public void RemoveFromPATH()
        {
            if (!DoesProgramExistInPATH())
            {
                throw new SystemException("The Program Path does not exist in the PATH.");
            }

            _currentSystemPATH.Remove(_targetProgramPath);
            SetSystemPATH();
        }

        bool DoesProgramExistInPATH()
        {
            foreach (string path in _currentSystemPATH)
            {
                if (path == _targetProgramPath)
                {
                    return true;
                }
            }
            return false;
        }

        void SetSystemPATH()
        {
            string newPATH = String.Join(";", _currentSystemPATH);
            Environment.SetEnvironmentVariable("Path", newPATH, EnvironmentVariableTarget.Machine);
        }

        List<string> GetSystemPATH()
        {
            var envVariables = Environment.GetEnvironmentVariables();
            string allPathEntries = envVariables["Path"].ToString();

            char[] charSeparators = new char[] { ';' };
            string[] rawPaths = allPathEntries.Split(charSeparators, StringSplitOptions.RemoveEmptyEntries);

            return new List<string>(rawPaths);
        }

        readonly string _targetProgramPath;
        List<string> _currentSystemPATH;
    }
}
