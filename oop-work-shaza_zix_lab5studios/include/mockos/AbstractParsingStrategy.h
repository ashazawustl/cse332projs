#ifndef ABSTRACTPARSINGSTRATEGY_H
#define ABSTRACTPARSINGSTRATEGY_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AbstractParsingStrategy {

//function to parse through a given string vector in order to name files, add contents to files, etc
public:
    virtual vector<string> parse(string) = 0;
    virtual ~AbstractParsingStrategy() = default;
};

#endif //ABSTRACTPARSINGSTRATEGY_H
