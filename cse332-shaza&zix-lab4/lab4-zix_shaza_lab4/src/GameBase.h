//
// Created by Shaza Ali on 03/11/2024.
//

#ifndef CSE332LAB_GAMEBASE_H
#define CSE332LAB_GAMEBASE_H
#include <memory>
#include <string>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

class GameBase {
protected:
    int width ; //initializing board width var
    int height ; //initializing board height var
    string longestDisplayString; //the longest display string for a piece
    vector<vector<string>> board; //initializing the game baord

public:
    //constructor and destructor for GameBase, with variable of width and height
    GameBase(int w, int h);
    virtual ~GameBase();

    //pure virtual functions for main gameplay functionality
    virtual void print() = 0;
    virtual bool done() = 0;
    virtual bool draw() = 0;
    virtual int turn() = 0;

    //play function for main gameplay
    int play();

    //static function createGame that will take in player arguments to determine which game to create and whether arguments taken in are valid
    static GameBase* createGame(int argc, char* argv[]);

    //prompting user to enter their move coordinated
    virtual int prompt(unsigned int & xRef, unsigned int & yRef);
    //functions to get the board width and board height
    int getWidth() const;
    int getHeight() const;
    //function to get the entire board dimensions/board in general
    const vector<vector<string>>& getBoard() const;

    //variables to determine the longest display string for pieces and update what that string is
    int maxDisplayStringLength() const;
    int gap = 1;
    bool updateVariables(string newPiece);

    bool playerXTurn = true; //for indicating whose turn it is
    vector<tuple<string, int, int>> XValidMoves; //valid moves made by player X
    vector<tuple<string, int, int>> OValidMoves; //valid moves made by player O
    string X_pawn = "X"; //mainly for tictactoe
    string O_pawn = "O"; //mainly for tictactoe
    char newPiece;
};


#endif //CSE332LAB_GAMEBASE_H