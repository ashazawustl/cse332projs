//
// Created by Shaza Ali on 13/10/2024.
//

#ifndef CSE332LAB_GAME_BOARD_H
#define CSE332LAB_GAME_BOARD_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "game-pieces.h"

bool boardDimensions(std::ifstream &inputFile, unsigned int &width, unsigned int &height);
int readFileStream(std::ifstream &inputFilestream, std::vector<game_piece> &gamepieces, unsigned int width, unsigned int height);
int printGameBoard(const std::vector<game_piece> &gamepieces, unsigned int width, unsigned int height);
int printAdjacentPieces(const std::vector<game_piece>& gamepieces, unsigned int width, unsigned int height);

#endif //CSE332LAB_GAME_BOARD_H
