//
// Created by Shaza Ali on 13/10/2024.
//

#include "game-pieces.h"
#include "lab2header.h"
#include <string>
#include <iostream>

using namespace std;

std::string piece_colorString(piece_color piece){
    string color;
    switch(piece){
        case red:
            color = "red";
            break;
        case black:
            color = "black";
            break;
        case white:
            color = "white";
            break;
        case invalid_color:
            color = "invalid color";
            break;
        case no_color:
            color = "no color";
            break;
    }
    toLowerCase(color);
    return color;
}

piece_color getStringforColor(std::string &str){
    if(str == "red"){
        return red;
    } else if (str == "black"){
        return black;
    } else if (str == "white"){
        return white;
    } else if (str == "no color" || str == "    "  || str.empty()){
        return no_color;
    } else {
        return invalid_color;
    }
}

piece_color getColorfromString(std::string &str2){
    piece_color color = getStringforColor(str2);
    std::string colorStr = piece_colorString(color);
    return getStringforColor(colorStr);
}

void return_game_piece(game_piece &piece){
    cout << "Name of the Piece: " << piece.piecename << endl;
    cout << "Color of the Piece: " << piece_colorString(piece.piececolor) << endl;
    cout << "Piece Display: " << piece.pieceonboard << endl;
}