#include "mockos/CopyCommand.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fs) : AbstractCommand(), fileSystem(fs) {}

int CopyCommand::execute(std::string args) {
    istringstream iss(args);
    string originalFileName, newBaseName;

    iss >> originalFileName >> newBaseName;

    string extra;
    if (iss >> extra)
    {
        cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
    }

    //check arguments
    if (originalFileName.empty() || newBaseName.empty()) {
        cout << "Error: Invalid arguments. Usage: cp <file_to_copy> <new_name_with_no_extension>" << endl;
        return invalid_copycommand_arg;
    }
    if (newBaseName.find('.') != string::npos)
    {
        cout << "Error: Invalid new name. Usage: cp <file_to_copy> <new_name_with_no_extension>" << endl;
        return invalid_copycommand_arg;
    }

    //open original file
    AbstractFile* originalFile = fileSystem->openFile(originalFileName);
    if (!originalFile) {
        cout << "Error: File '" << originalFileName << "' not found." << endl;
        return file_not_found;
    }

    //get file extension from the original file
    size_t dotIndex = originalFileName.find_last_of('.');
    if (dotIndex == string::npos) {
        cout << "Error: Original file must have an extension." << endl;
        fileSystem->closeFile(originalFile);
        return invalid_copycommand_arg;
    }
    string extension = originalFileName.substr(dotIndex);

    //create new file name
    string newFileName = newBaseName + extension;

    //clone original file with the new name
    AbstractFile* copiedFile = originalFile->clone(newFileName);
    fileSystem->closeFile(originalFile); //close the original file

    if (!copiedFile) {
        cout << "Error: Failed to copy the file." << endl;
        return copy_failed;
    }

    //add the copied file to the file system
    int result = fileSystem->addFile(newFileName, copiedFile);
    if (result != success) {
        cout << "Error: Failed to add the copied file to the file system." << endl;
        delete copiedFile;
        return add_file_failed;
    }

    return success;
}

void CopyCommand::displayInfo() {
    cout << "cp copies a file." << endl;
    cout << "cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

CopyCommand::~CopyCommand()
{
    fileSystem = nullptr;
}