//
// Created by Shaza Ali on 27/10/2024.
//

#ifndef CSE332LAB_TICTACTOE_H
#define CSE332LAB_TICTACTOE_H

#include<string>
#include<sstream>
#include<iostream>
#include<sstream>
#include<ctime>
#include<cstdlib>

class BoardSetUp{

    //board is 5 by 5
    std::string board[6][6];

    //coordinates of X or O
    unsigned int xCoord;
    unsigned int yCoord;

    //player movement tracking
    std::string horizMove;
    std::string vertMove;

    //play turns tracking
    std::string trackPlayer;

    //total moves made tracker (will be relative to space on board and presence or absence of a win)
    unsigned int movesMade;

public:
    BoardSetUp(bool gameStart);
    friend std::ostream& operator << (std::ostream& output, const BoardSetUp& boarddimensions);

    int turnPrompt(unsigned int& x, unsigned int& y);
    int turn();
    int play();

    bool autoPlay;
    bool draw();
    bool done();
    bool possWin();
    bool preventWin();
    bool checkWinOpportunity(const std::string& playerMove);

    void updatePlayerMoves();
    void printBoard() const;
    void random_move();
    void auto_player();

};

enum errors{
    quit = 1,
    tie = 2
};
#endif //CSE332LAB_TICTACTOE_H
