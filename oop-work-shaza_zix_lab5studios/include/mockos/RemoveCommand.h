#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;

class RemoveCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;

public:
    RemoveCommand(AbstractFileSystem* fs);
    virtual int execute(string args);
    virtual void displayInfo();
    virtual ~RemoveCommand();
};

#endif //REMOVECOMMAND_H
