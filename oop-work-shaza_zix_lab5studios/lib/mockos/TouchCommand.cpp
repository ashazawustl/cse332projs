#include "mockos/TouchCommand.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
        : AbstractCommand(), fileSystem(fs), fileFactory(ff) {}

//override displayInfo
void TouchCommand::displayInfo() {
    cout << "touch creates a file. It can be invoked with the command: touch <filename> which creates a regular file and touch <filename> -p which creates a password-protected file" << endl;
}

//override execute
int TouchCommand::execute(string input) {
    //parse input to extract filename and optional -p flag
    size_t spacePos = input.find(' ');
    string filename;
    string option;
    if (spacePos != string::npos) {
        filename = input.substr(0, spacePos); //filename before space
        option = input.substr(spacePos + 1); //option after the space
    } else {
        filename = input; //no option entered
    }

    if (filename.empty()) {
        cout << "Error: No filename provided." << endl;
        return invalid_filename;
    }
    if (filename.length() > max_file_name_length)
    {
        return filename_too_long;
    }

    //use file factory to create a file
    AbstractFile* newFile = fileFactory->createFile(filename);
    if (!newFile) {
        cout << "Error: File creation failed for " << filename << "." << endl;
        return filecreate_fail;
    }

    //if -p option specified, prompt for a password
    if (!option.empty())
    {
        if (option == "-p") {
            cout << "Enter password: ";
            string password;
            cin >> password;

            //wrap file in a PasswordProxy
            newFile = new PasswordProxy(newFile, password);
        }
        else
        {
            cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
        }
    }


    //add file to file system
    int result = fileSystem->addFile(filename, newFile);
    if (result != 0) {
        delete newFile; //delete created file
        cout << "Error: Failed to add file " << filename << " to the file system." << endl;
        return fileadd_fail;
    }

    return success;
}

TouchCommand::~TouchCommand() {
    fileSystem = nullptr;
    fileFactory = nullptr;
}
