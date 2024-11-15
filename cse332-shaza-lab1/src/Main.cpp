/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 1
 * Author: Shaza Ali
*/

#include <iostream>
#include "lab1header.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int parse(vector<string> &stl, char* str){
    str= const_cast<char*> ("input_file.txt"); //any file name here
    ifstream input(str);
    string strings;
    if(!input){
        cout << "Can't open this file";
        return emptyfile;
    }
    if(input.is_open()){
        while(input>>strings){
            stl.push_back(strings);
                cout<<strings<< " ";
            }
            input.close();

            if(stl.empty()){
                cout << "File is empty";
                return emptyfile;
            }
        }
        return success;
    }

err Usage(const char *){
    cout<<"This program will take an input file such as input_file.txt that contains text strings and different kinds of whitespace then parse through it to extract one string at a time from the file until there are no strings left to parse." <<endl;
    return invalidargs;
}

int main(int argc, char** argv) {
    if(argc!=expargc){
        return Usage(argv[name]);
    }

    vector<string> parsed_Str;
    int final_Str = parse(parsed_Str, argv[inputname]);
    if(final_Str!=success){
        return final_Str;
    }

    vector<int> check_Int;
    for(const auto& str:parsed_Str){
        bool number = true;

        istringstream iss(str);
        double value;
        iss >> value;

        if(iss.fail()|| !iss.eof()){
            number = false;
        }

        for(char character:str){
            if(!isdigit(character)){
                number = false;
                break;
            }
        }
        if(number){
            int num = static_cast<int> (value);
            check_Int.push_back(num);
        }
        else{
            cout<<str<<endl;
        }
    }
    for(const auto& thing:check_Int){
        cout<<thing<< " ";
    }
    cout<<endl;
    return success;
}
