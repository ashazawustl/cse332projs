/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 4
 * Author: Zix Chen & Shaza Ali
*/

#include <iostream>
#include "GameBase.h"
#include <sstream>
#include <string>
#include "enums.h"

using namespace std;

//outputs usage message upon the entry of invalid input stream arguments
int usageMessage(const string & x, const string & y)
{
    cerr << "Usage: " << x << " " << y << endl;
    return invalid_argv;
}

/*determines the argument count form the input stream and calls createGame to determine whether game
creation is either failed or successful depending on whether there's not enough args,
too many args, or too little args entered by the user*/

int main(int argc, char *argv[]) {
    if (argc == 2)
    {
        shared_ptr<GameBase> game(GameBase::createGame(argc, argv));

        if (game == nullptr)
        {
            cout << "failed to create game" << endl;
            usageMessage("./lab_4", "<game_name> (TicTacToe or Gomoku)");
            return invalid_argv;
        } try {
            int result = game->play();
            return result;
        } catch (const int error_code){
            return error_code;
        }
    }
    if (argc > 2)
    {
        cout << "too many arguments" << endl;
        usageMessage("./lab_4", "<game_name> (TicTacToe or Gomoku)");
        return too_many_argv;
    }
    cout << "not enough arguments" << endl;
    usageMessage("./lab_4", "<game_name> (TicTacToe or Gomoku)");
    return not_enough_argv;
}
