//
// Created by Shaza Ali on 13/10/2024.
//

#ifndef CSE332LAB_GAME_PIECES_H
#define CSE332LAB_GAME_PIECES_H

#include <string>

enum piece_color{
    red ,
    black  ,
    white ,
    invalid_color ,
    no_color
};

std::string piece_colorString(piece_color piece);
piece_color getStringforColor(std::string &str);
piece_color getColorfromString(std::string &str2);
struct game_piece{
    piece_color piececolor;
    std::string piecename;
    std::string pieceonboard;
};

#endif //CSE332LAB_GAME_PIECES_H
