//
// Created by Shaza Ali on 03/11/2024.
//

#include "GameBase.h"
#include "tictactoe.h"
#include "enums.h"
#include "Gomoku.h"
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

//initializing the constructor for GameBase which takes care of basic functions for both games in this lab
GameBase::GameBase(int w, int h) : width(w), height(h), board(h, vector<string>(w, " ")) {
    gap = longestDisplayString.length() - 1;
}

//dustructor for GameBase
GameBase::~GameBase() {}

//this function takes in newPeiece as a string whose length is compared to the currently present longestDisplayString and updates longestDisplayString so that it's newPiece if it's longer. This is used for formatting purposes ont he board, hence the gap variable to determine space gaps on both boards.
bool GameBase::updateVariables(string newPiece) {
    if (newPiece.length() > longestDisplayString.length()) {
        longestDisplayString = newPiece;
        gap = longestDisplayString.length() + 1;
        return true;
    }
    return false;
}

//this just returns the value of that longestDisplayString's size for use in the game(s) functions
int GameBase::maxDisplayStringLength() const {
    return longestDisplayString.size();
}

//gets board height
int GameBase::getHeight() const {
    return height;
}

//gets board width
int GameBase::getWidth() const {
    return width;
}

//gets the entire board with both dimensions (height and width)
const vector<vector<string>>& GameBase::getBoard() const {
    return board;
}

//prompts the user for their input piece or the option to quit and iterates through every new line entered into the input stream if multiple moves are entered at once like on Gomoku draw.txt test file
int GameBase::prompt(unsigned int& xRef, unsigned int& yRef) {
    string input;
    int x = -1, y = -1;

    while (true) {
        cout << "place your next piece (\"x,y\") or type quit to exit: ";
        getline(cin, input);
        replace(input.begin(), input.end(), ',', ' '); //replacing comma with space for iss
        istringstream iss(input);
        string quitPhrase;

        if (iss >> quitPhrase && quitPhrase == "quit") {
            if (iss.eof()) {
                cout << "goodbye!" << endl; //stopping the game on 'quit'
                return quit_game;
            }
            cout << "extra input after (\"quit\") detected" << endl; //prevents invalid quit requests
        } else {
            iss.clear();
            iss.str(input);

            if (iss >> x >> y) {
                if (x < 0 || y < 0) {
                    cout << "positive coordinates only." << endl; //validates a move input
                } else {
                    xRef = x;
                    yRef = y;
                    return read_move_success;
                }
            } else {
                cout << "Invalid input format. Usage: (\"x,y\") or (\"quit\")" << endl; //validates format of move input
            }
        }
    }
}

//this function helps use the turn() function to alternate turns with every piece played and outputs how many turns were played, who won(if anybody) at the end of the game
int GameBase::play() {
    this->print();
    int move, turns = 0;

    while (true) {
        move = this->turn();
        turns++;
        if (move == quit_game) {
            cout << turns << " turns played, player quit game." << endl;
            return quit_game;
        }
        if (this->draw()) {
            cout << "draw: " << turns << " turns played, no winning moves remain." << endl;
            return game_draw;
        }
        if (this->done()) {
            cout << ((move == x_valid_move) ? "Player X's victory!" : "Player O's victory!") << endl;
            return game_ends;
        }
    }
}

//creates game for either TicTacToe or Gomoku depending which user input is made
GameBase* GameBase::createGame(int argc, char* argv[]) {
    if (string(argv[1]) == "TicTacToe") {
        return new TicTacToeGame(); // TicTacToeGame object
    }
    if (string(argv[1]) == "Gomoku")
    {
        return new GomokuGame(20); //  GomokuGame object
    }
    return nullptr;
}