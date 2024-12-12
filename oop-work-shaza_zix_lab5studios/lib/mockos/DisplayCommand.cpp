#include "mockos/DisplayCommand.h"


using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fs) : AbstractCommand(), fileSystem(fs) {}

int DisplayCommand::execute(string args) {
    //parse input to extract filename and optional -d flag
    istringstream iss(args);
    string filename, option;
    iss >> filename >> option;

    //filename check
    if (filename.empty()) {
        cerr << "Error: No filename provided." << endl;
        return invalid_filename;
    }

    //open file
    AbstractFile* file = fileSystem->openFile(filename);
    if (!file) {
        cerr << "Error: File '" << filename << "' not found or access denied." << endl;
        return file_not_found;
    }

    //display mode, checking whether content formatted or not
    bool unformatted = false;

    if (!option.empty())
    {
        if (option == "-d") {
            unformatted = true;
        }
        else
        {
            cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
        }
    }

    //BasicDisplayVisitor for display
    BasicDisplayVisitor visitor(unformatted);
    file->accept(&visitor);

    //close file
    fileSystem->closeFile(file);

    return success;
}

void DisplayCommand::displayInfo() {
    cout << "ds displays a file's contents. Usage:" << endl;
    cout << " ds <filename> to display formatted contents" << endl;
    cout << " ds <filename> -d to display raw data" << endl;
}

DisplayCommand::~DisplayCommand()
{
    fileSystem = nullptr;
}