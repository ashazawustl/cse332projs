//
// Created by Shaza Ali on 01/11/2024.
//

#ifndef CSE332LAB_GOMOKU_H
#define CSE332LAB_GOMOKU_H
#include "GameBase.h"
#include <string>



class GomokuGame: public GameBase{

public:
    int boardDim; //initialization for board dimensions
    GomokuGame(int boardDim); //constructor for Gomoku that takes in the board dimensions
    ~GomokuGame(); //destructor for Gomoku
    //overridden functions for Gomoku functionality
    bool done() override;
    bool draw() override;
    int turn() override;
    void print() override;
    //ostream operator for helping with the print function to display the game
    friend ostream& operator<<(ostream& out, const GomokuGame& gameRef);

private:
    unsigned int gomokuMoves; //moves made in the Gomoku game
    string displayPieces[2] =  {"B", "W"}; //What pieces are valid in this game (B and W)
    unsigned int numWin = 5; //the number of pieces in a row to win
};



#endif //CSE332LAB_GOMOKU_H