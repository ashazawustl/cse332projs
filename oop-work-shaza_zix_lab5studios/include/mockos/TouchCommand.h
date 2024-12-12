#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H

#include "AbstractCommand.h"
#include "PasswordProxy.h"
#include <iostream>

class TouchCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;

public:
    TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff);
    virtual int execute(std::string filename) ;
    virtual void displayInfo() ;
    virtual ~TouchCommand() ;
};

enum{
    filecreate_fail = 5,
    fileadd_fail = 6,
    filename_too_long = 7,
};

#endif // TOUCHCOMMAND_H
