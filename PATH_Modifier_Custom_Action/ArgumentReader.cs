using System;

namespace PATH_Modifier_Custom_Action
{
    enum PathVariableAction
    {
        InstallPathVariable,
        UninstallPathVariable
    }

    class ArgumentReader
    {
        const string INSTALL_PATH_ARGUMENT = "--install_path";
        const string UNINSTALL_PATH_ARGUMENT = "--uninstall_path";
        const int REQUIRED_ARGUMENT_COUNT = 3;

        public ArgumentReader(string[] arguments)
        {
            _arguments = arguments;
            if(!IsArgCountCorrect())
            {
                throw new ArgumentException("The argument count is incorrect.");
            }

            SetArgumentsAndCheckValidity();
        }

        public PathVariableAction GetActionValue()
        {
            return ConvertToPathAction();
        }

        public string GetProgramPath()
        {
            return _path;
        }
        
        void SetArgumentsAndCheckValidity()
        {
            SetActionFromArgs();
            if(!IsActionValid())
            {
                throw new ArgumentException("The action argument is invalid.");
            }

            SetPathFromArgs();
            if(!IsPathValid())
            {
                throw new ArgumentException("The path argument is invalid.");
            }
        }

        void SetActionFromArgs()
        {
            _action = _arguments[1];
        }

        void SetPathFromArgs()
        {
            _path = _arguments[2];
        }

        bool IsActionValid()
        {
            return _action == INSTALL_PATH_ARGUMENT || _action == UNINSTALL_PATH_ARGUMENT;
        }

        bool IsPathValid()
        {
            return Uri.IsWellFormedUriString(_path, UriKind.Absolute);
        }

        bool IsArgCountCorrect()
        {
            return _arguments.Length == REQUIRED_ARGUMENT_COUNT;
        }

        PathVariableAction ConvertToPathAction()
        {
            if(_action == INSTALL_PATH_ARGUMENT)
            {
                return PathVariableAction.InstallPathVariable;
            }
            else
            {
                return PathVariableAction.UninstallPathVariable;
            }
        }

        string[] _arguments;
        string _path, _action;
    }
}