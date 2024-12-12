#include "mockos/CreateAndEditParsingStrategy.h"

using namespace std;

vector<string> CreateAndEditParsingStrategy::parse(string args)
{
    istringstream iss(args);
    string currentArg;
    vector<string> parsed;

    while (iss >> currentArg)
    {
        parsed.push_back(currentArg);
    }

    if (parsed[0].find('.') == string::npos) //is a valid file name with an extension
    {
        cout << "Invalid file name" << endl;
        return {}; //return empty vector
    }

    if (parsed.size() != 1)
    {
        cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
    }

    vector<string> converted;
    converted.push_back(parsed[0]); // "<file_name>" input for touch command
    converted.push_back(parsed[0]); // "<file_name>" input for cat command

    return converted;
}
