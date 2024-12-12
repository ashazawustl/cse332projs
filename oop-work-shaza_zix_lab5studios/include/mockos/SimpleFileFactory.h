#ifndef SIMPLEFILEFACTORY_H
#define SIMPLEFILEFACTORY_H
#include <vector>
#include <string>
#include "AbstractFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

class SimpleFileFactory: public AbstractFileFactory
{
public:
    SimpleFileFactory();
    virtual ~SimpleFileFactory();
    virtual AbstractFile* createFile(string filename);
};


#endif //SIMPLEFILEFACTORY_H