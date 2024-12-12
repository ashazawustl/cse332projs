#ifndef COMMANDPROMPT_H
#define COMMANDPROMPT_H

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CommandPrompt {
private:
    //map to store command names and corresponding command objects
    std::map<std::string, AbstractCommand*> commands;
    //pointer to the file system
    AbstractFileSystem* fileSystem;
    //pointer to the file factory
    AbstractFileFactory* fileFactory;
protected:
    //method to list available commands
    void listCommands() const;
    //prompt user for input
    std::string prompt() const;

public:
    //constructor to initialize pointers to null
    CommandPrompt();
    //set the file system
    void setFileSystem(AbstractFileSystem* fs);
    //set the file factory
    void setFileFactory(AbstractFileFactory* ff);
    //add a command to the command map
    int addCommand(const std::string& name, AbstractCommand* command);
    //main prompt loop
    int run();
    //destructor to clean up resources
    ~CommandPrompt();
};

enum{
    command_prompt_success = 0 ,
    command_exists = 1,
    quit = 2

};

#endif // COMMANDPROMPT_H
