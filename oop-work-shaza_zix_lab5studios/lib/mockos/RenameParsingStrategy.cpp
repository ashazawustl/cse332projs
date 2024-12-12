#include "mockos/RenameParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string args)
{
    istringstream iss(args);
    string currentArg;
    vector<string> parsed;

    while (iss >> currentArg)
    {
        parsed.push_back(currentArg);
    }

    if (parsed[0].find('.') == string::npos) //check if it's a valid file name with an extension
    {
        cout << "Invalid file name" << endl;
        return {}; // return empty vector
    }

    if (parsed.size() != 2)
    {
        cout << "Invalid parameter. Proceeding as if no parameter was passed" << endl;
    }

    vector<string> converted;
    string concatenated = parsed[0] + " " + parsed[1]; // "<existing_file> <new_name>"
    converted.push_back(concatenated);
    converted.push_back(parsed[0]); // "<existing_file>"

    return converted;
}
