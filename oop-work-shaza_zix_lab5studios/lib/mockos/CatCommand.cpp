#include "mockos/CatCommand.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fs) : AbstractCommand(), fileSystem(fs)
{}

int CatCommand::execute(string args) {
    //parse input to extract filename and optional -a flag
    istringstream iss(args);
    string filename, option;
    iss >> filename;
    iss >> option;

    //filename check
    if (filename.empty()) {
        cout << "Error: No filename provided." << endl;
        return invalid_filename;
    }

    //open file
    AbstractFile* file = fileSystem->openFile(filename);
    if (!file) {
        cout << "Error: File '" << filename << "' not found or access denied." << endl;
        return file_not_found;
    }

    vector<char> currentContents;
    if (!option.empty())
    {
        if (option == "-a") {
            //display current contents if -a option is provided
            currentContents = file->read();
            for (char c : currentContents) {
                cout << c;
            }
            cout << endl;
        }
        else
        {
            cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
        }
    }


    //prompt user for input
    cout << "Enter input (type ':wq' to save and quit, ':q' to quit without saving):" << endl;
    vector<char> newData;
    string line;

    int line_count = 0;
    while (getline(cin, line)) {
        if (line == ":wq") {
            break;
        } else if (line == ":q") {
            fileSystem->closeFile(file);
            cout << "User quit without saving." << endl;
            return success;
        } else {
            if (line_count != 0)
            {
                newData.push_back('\n');
            }
            newData.insert(newData.end(), line.begin(), line.end());
            line_count++;
        }
    }

    //write or append data to the file
    int writeResult;
    if (option == "-a") {
        writeResult = file->append(newData);
    } else {
        writeResult = file->write(newData);
    }

    if (writeResult != success) {
        cerr << "Error: Failed to write to the file." << endl;
        fileSystem->closeFile(file);
        return file_access_denied;
    }

    //close file
    fileSystem->closeFile(file);
    return success;
}

void CatCommand::displayInfo() {
    cout << "cat writes to or appends to a file. Usage:" << endl;
    cout << "  cat <filename> to overwrite file contents" << endl;
    cout << "  cat <filename> -a to append to file contents" << endl;
}

CatCommand::~CatCommand()
{
    fileSystem = nullptr;
}