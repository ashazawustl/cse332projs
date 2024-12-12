#ifndef ABSTRACTFILEFACTORY_H
#define ABSTRACTFILEFACTORY_H
#include <vector>
#include <string>
#include "AbstractFile.h"

using namespace std;

class AbstractFileFactory
{
    //per assignment expectations, creation of file sis not contingent upon their extensions but rather is handled by an AbstractFileFactory
public:
    AbstractFileFactory();
    virtual ~AbstractFileFactory() = 0;
    virtual AbstractFile* createFile(string filename) = 0;
};

inline AbstractFileFactory::AbstractFileFactory() {}
inline AbstractFileFactory::~AbstractFileFactory() {}


#endif //ABSTRACTFILEFACTORY_H