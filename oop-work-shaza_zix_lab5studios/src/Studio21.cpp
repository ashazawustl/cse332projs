#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/CommandPrompt.h"
#include "mockos/TouchCommand.h"
#include <iostream>

using namespace std;

int main() {
    //dynamically allocate objects
    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();

    //create a TouchCommand and pass it to CommandPrompt
    AbstractCommand* touch = new TouchCommand(fs, ff);
    CommandPrompt cp;
    cp.setFileSystem(fs);
    cp.setFileFactory(ff);
    cp.addCommand("touch", touch);

    //test command prompt
    int result = cp.run();

    if (result != quit) {
        cerr << "Command prompt terminated with an error." << endl;
        delete touch;
        delete fs;
        delete ff;
        return result;
    }

    //verify file creation after command execution
    string filename = "newfile1.txt";
    AbstractFile* checkFile = fs->openFile(filename);
    if (checkFile) {
        cout << "File '" << filename << "' successfully created and found in the file system." << endl;
        fs->closeFile(checkFile);
    } else {
        cerr << "File '" << filename << "' was not found in the file system." << endl;
    }

    //clean up
    delete fs;
    delete ff;

    return command_prompt_success;
}
