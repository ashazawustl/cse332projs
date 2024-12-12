#include "mockos/RemoveCommand.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fs): AbstractCommand(), fileSystem(fs) {}

//override displayInfo
void RemoveCommand::displayInfo() {
    cout << "rm remove the file with the provided name from the file system." << endl;
}

//override execute
int RemoveCommand::execute(string args) {
    istringstream iss(args);
    string arg;
    vector<string> parsedArgs;
    while (iss >> arg)
    {
        parsedArgs.push_back(arg);
    }

    if (parsedArgs.size() != 1)
    {
        cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
    }

    int result = fileSystem->deleteFile(parsedArgs[0]);

    switch (result)
    {
        case delete_file_success:
            return success;
        case file_already_open:
            return file_already_open;
        case file_does_not_exist:
            return file_does_not_exist;
    }
    return result;
}

RemoveCommand::~RemoveCommand() {
    fileSystem = nullptr;
}
