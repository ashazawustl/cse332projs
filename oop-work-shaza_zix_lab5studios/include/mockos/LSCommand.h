#ifndef LSCOMMAND_H
#define LSCOMMAND_H

#include <set>

#include "AbstractCommand.h"
#include "MetadataDisplayVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <iostream>

using namespace std;

class LSCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;

public:
    LSCommand(AbstractFileSystem* fs);
    virtual int execute(string args);
    virtual void displayInfo();
    virtual ~LSCommand();
};

#endif //LSCOMMAND_H
