#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "AbstractCommand.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>

class DisplayCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;

public:
    DisplayCommand(AbstractFileSystem* fs);

    virtual ~DisplayCommand();

    virtual int execute(std::string args) ;
    virtual void displayInfo() ;
};


#endif //DISPLAYCOMMAND_H
