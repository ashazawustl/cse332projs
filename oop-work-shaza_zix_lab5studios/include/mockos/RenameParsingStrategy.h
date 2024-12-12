#ifndef RENAMEPARSINGSTRATEGY_H
#define RENAMEPARSINGSTRATEGY_H

#include "AbstractParsingStrategy.h"
#include "RemoveCommand.h"

using namespace std;

class RenameParsingStrategy : public AbstractParsingStrategy {

public:
    virtual vector<string> parse(string args);
    virtual ~RenameParsingStrategy() = default;
};

#endif //RENAMEPARSINGSTRATEGY_H
