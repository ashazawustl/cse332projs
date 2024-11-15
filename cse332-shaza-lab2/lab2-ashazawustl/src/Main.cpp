/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 2
 * Author: Shaza Ali
*/

#include <iostream>
#include <string>
#include <cctype>
#include "lab2header.h"
#include <fstream>
#include "game-pieces.h"
#include "game-board.h"
#include <vector>

using namespace std;

//Usage message from Lab 1, modified
int Usage(const char * program_name, const char * user_message){
    cout<< "Usage: " << program_name <<endl;
    cout << user_message << endl;
    return invalidargs;
}

//take in C-style strings and convert to lower case, solution from  https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
void toLowerCase(std::string& st){
    std::transform(st.begin(), st.end(), st.begin(), [] (unsigned char character) {return std::tolower(character);});
}


int main(int argc, char* argv[]) {

    if (argc != fileopen) {
        return Usage(argv[0], "Please provide the name of the input file.");
    }

    ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file " << argv[1] << endl;
        return filenotopen;
    }

    unsigned int width = 0, height = 0;

    int result = boardDimensions(inputFile, width, height);

    while (result != success) {
        if (result == filenotopen) {
            cerr << "Error: Could not open the file." << endl;
            return filenotopen;
        } else if (result == invalidformat) {
            cerr << "Error: Invalid format for board dimensions." << endl;
            return invalidformat;
        } else if (result == wrongsize) {
            cerr << "Error: Invalid size of the board dimensions." << endl;
            return wrongsize;
        }

        result = boardDimensions(inputFile, width, height);
        if (result == filenotopen) {
            cerr << "Error: Could not open the file." << endl;
            return filenotopen;
        }
    }

    vector<game_piece> gamepieces(width * height);
    for (unsigned int i = 0; i < width * height; ++i) {
        gamepieces[i].piececolor = no_color;
        gamepieces[i].piecename = "";
        gamepieces[i].pieceonboard = " ";
    }

    result = readFileStream(inputFile, gamepieces, width, height);

    if (result != success) {
        cerr << "Error: Failed to read game pieces." << endl;
        return result;
    }

    result = printGameBoard(gamepieces, width, height);

    if (result != success) {
        cerr << "Error: Failed to print the game board." << endl;
        return result;
    }

    //extra credit, adjacent pieces
    int adjacent = printAdjacentPieces(gamepieces, width, height);
    if (adjacent != success) {
        return adjacent;
    }
    return success;
}



