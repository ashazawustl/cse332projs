//
// Created by Zix on 2024/10/23.
//
/*
 *enums.h
 *created by Zix Chen c.zixin@wustl.edu
 *enumerates the integers used for identifying various scenarios
 *used to avoid hard coding
 */

#ifndef ENUMS_H
#define ENUMS_H

enum codes  //for identifying game scenarios
{
    game_ends = 0, //code for the end of a game given a win, loss, draw
    x_valid_move = 1, //code for a valid move from one player (X is arbitrary and is set as X because of default functionality from tictactoe)
    o_valid_move = 2, //code for a valid move from another player
    game_draw = 3, //code for a tie
    quit_game = 4, //code indicating a player has quit the game
    read_move_success = 5, //code to read whether a move made was valid and successful
};

enum errors
{
    invalid_argv = 6, //not the correct arg input
    too_many_argv = 7, //too many args
    not_enough_argv = 8 //not enough arg inputs
};

#endif //ENUMS_H