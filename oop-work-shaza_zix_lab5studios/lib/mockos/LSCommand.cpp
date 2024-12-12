#include "mockos/LSCommand.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* fs)
        : AbstractCommand(), fileSystem(fs) {}

//override displayInfo
void LSCommand::displayInfo() {
    cout << "ls outputs to the terminal the names of all files currently in the file systeme. It can be invoked with the command: 'ls' with optional parameter '-m'" << endl;
}

//override execute
int LSCommand::execute(string args) {
    set<string> file_names = this->fileSystem->getFileNames();
    if (args != "-m")
    {
        if (!args.empty())
        {
            cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
        }
        int count = 0; // Counter to track how many files are printed on the current line
        for (const string& file_name : file_names) {
            cout << file_name;
            if (count == 0) {
                for (int i = 0; i < max_file_name_length - file_name.length(); i++)
                {
                    cout << " ";
                }
            }
            count++;
            if (count == 2) { // Print a newline after two file names
                cout << endl;
                count = 0;
            }
        }
        if (count != 0) { //if there's an incomplete line, add a final newline
            cout << endl;
        }
    }
    else
    {
        AbstractFileVisitor* visitor = new MetadataDisplayVisitor();
        for (const string& file_name : file_names)
        {
            AbstractFile * file = fileSystem->openFile(file_name);
            if (file != nullptr) //file exists and is not alr open
            {
                try
                {
                    file->accept(visitor);
                }
                catch (int empty_visitor_pointer)
                {
                    return empty_visitor_pointer;
                }
                fileSystem->closeFile(file);
            }
        }
    }
    return success;
}


LSCommand::~LSCommand() {
    fileSystem = nullptr;
}
