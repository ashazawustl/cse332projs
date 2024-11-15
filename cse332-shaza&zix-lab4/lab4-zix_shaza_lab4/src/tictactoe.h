//
// Created by Zix on 2024/10/23.
//

/*
 *tictactoe.h
 *created by Zix Chen c.zixin@wustl.edu
 *is the header file for the tictactoe class
 *declares the attributes of the tictactoe class, a simple tictactoe game
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <ostream>
#include <vector>
#include <tuple>
#include <string>
#include "GameBase.h"

using namespace std;

class TicTacToeGame: public GameBase{
public:

    TicTacToeGame(); //constructor for tictactoe
    ~TicTacToeGame(); //destructor for tictactoe
    //overridden functions for tictactoe functionality
    void print() override;
    bool done() override;
    bool draw() override;
    int turn() override;
    //ostream operator for helping with the print function to display the game
    friend ostream& operator<<(ostream& osRef, const TicTacToeGame& gameRef);

};

#endif //TICTACTOE_H