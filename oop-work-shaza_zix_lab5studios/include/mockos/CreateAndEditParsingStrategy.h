#ifndef CREATEANDEDITPARSINGSTRATEGY_H
#define CREATEANDEDITPARSINGSTRATEGY_H

#include "AbstractParsingStrategy.h"
#include "TouchCommand.h"
#include "CatCommand.h"

using namespace std;

class CreateAndEditParsingStrategy : public AbstractParsingStrategy {

public:
    virtual vector<string> parse(string args);
    virtual ~CreateAndEditParsingStrategy() = default;
};

#endif //CREATEANDEDITPARSINGSTRATEGY_H
