#ifndef CATCOMMAND_H
#define CATCOMMAND_H

#include "AbstractCommand.h"
#include <iostream>
#include <sstream>


class CatCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;

public:
    CatCommand(AbstractFileSystem* fs);

    virtual ~CatCommand();

    virtual int execute(std::string args) ;
    virtual void displayInfo() ;

};

#endif //CATCOMMAND_H
