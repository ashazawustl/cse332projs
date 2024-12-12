#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/CommandPrompt.h"
#include "mockos/TouchCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/PasswordProxy.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/CreateAndEditParsingStrategy.h"
#include "mockos/MacroCommand.h"
#include <iostream>


using namespace std;

int main() {
    //dynamically allocate objects
    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();

    //setting up the command prompt with the assistance of the FileSystem and FileFactory
    CommandPrompt cmdp;
    cmdp.setFileSystem(fs);
    cmdp.setFileFactory(ff);

    //adding the commands that've been created for this lab
    AbstractCommand* touch = new TouchCommand(fs, ff);
    AbstractCommand* ls = new LSCommand(fs);
    AbstractCommand* remove = new RemoveCommand(fs);
    AbstractCommand* cat = new CatCommand(fs);
    AbstractCommand* display = new DisplayCommand(fs);
    AbstractCommand* copy = new CopyCommand(fs);
    cmdp.addCommand("cp", copy);
    cmdp.addCommand("ds", display);
    cmdp.addCommand("cat", cat);
    cmdp.addCommand("touch", touch);
    cmdp.addCommand("ls", ls);
    cmdp.addCommand("rm", remove);

    //adding the MacroCommands created for this lab
    MacroCommand* rename = new MacroCommand(fs);
    AbstractParsingStrategy* renamePs = new RenameParsingStrategy();
    rename->setParseStrategy(renamePs);
    rename->addCommand(copy);
    rename->addCommand(remove);

    cmdp.addCommand("rn", rename);

    MacroCommand* createAndEdit = new MacroCommand(fs);
    AbstractParsingStrategy* createAndEditPs= new CreateAndEditParsingStrategy();
    createAndEdit->setParseStrategy(createAndEditPs);
    createAndEdit->addCommand(touch);
    createAndEdit->addCommand(cat);

    cmdp.addCommand("cne", createAndEdit);

    //test command prompt
    int result = cmdp.run();

    //checking for errors
    if (result != quit) {
        cerr << "Command prompt terminated with an error." << endl;
        delete fs;
        delete ff;

        return result;
    }

    //verify file creation after command execution-> keeping commented to demonstrate the PasswordPRoxy/ password protection check
//     string filename = "newfile1.txt";
//     AbstractFile* checkFile = fs->openFile(filename);
//     if (checkFile) {
//         cout << "File '" << filename << "' successfully created and found in the file system." << endl;
//     //check if file is wrapped with PasswordProxy
//     PasswordProxy* proxyCheck = dynamic_cast<PasswordProxy*>(checkFile);
//     if (proxyCheck) {
//         cout << "File '" << filename << "' is password-protected." << endl;
//     } else {
//         cout << "File '" << filename << "' is not password-protected." << endl;
//     }
//         fs->closeFile(checkFile);
//     } else {
//         cerr << "File '" << filename << "' was not found in the file system." << endl;
//     }
//
//    //clean up
//    delete fs;
//    delete ff;

    return command_prompt_success;
}

