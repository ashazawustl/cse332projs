//
// Created by Shaza Ali on 13/10/2024.
//

#include "game-board.h"
#include "lab2header.h"
#include "game-pieces.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool boardDimensions(std::ifstream &inputFile, unsigned int &width, unsigned int &height) {
    if (!inputFile.is_open()) {
        cerr << "File not open." << endl;
        return false;
    }
    string dim;
    if (getline(inputFile, dim)) {
        stringstream ss(dim);
        if (ss >> width >> height) {
            cout << "Game board dimensions read successfully!" << endl;
            cout << "Width: " << width << ", Height: " << height << endl;
            return true;
        } else {
            cerr << "Invalid dimensions format" << endl;
            return false;
        }
    } else {
        cerr << "Couldn't read from file" << endl;
        return false;
    }
}

int readFileStream(std::ifstream &inputFilestream, std::vector<game_piece> &gamepieces, unsigned int width, unsigned int height) {
    if (!inputFilestream.is_open()) {
        cerr << "Input file not open" << endl;
        return filenotopen;
    }

    string fileline;
    bool validpiece = false;
    while (getline(inputFilestream, fileline)) {
        stringstream ss(fileline);
        string colorStr, piecename, pieceonboard;
        unsigned int xCoord, yCoord;

        if (ss >> colorStr >> piecename >> pieceonboard >> xCoord >> yCoord) {
            piece_color color = getColorfromString(colorStr);

            if (color == invalid_color || xCoord >= width || yCoord >= height) {
                cerr << "Invalid color or out of bounds: " << fileline << endl;
                continue; // Skip this line
            }

            unsigned int index = yCoord * width + xCoord;
            if (index < gamepieces.size()) {
                gamepieces[index].piececolor = color;
                gamepieces[index].piecename = piecename;
                gamepieces[index].pieceonboard = pieceonboard;
                validpiece = true;
            } else {
                cerr << "Out of bounds: " << xCoord << ", " << yCoord << endl;
            }
        } else {
            cerr << "Invalid read from file: " << fileline << endl;
        }
    }
    return validpiece ? success : invalidformat;
}

int printGameBoard(const std::vector<game_piece> &gamepieces, unsigned int width, unsigned int height) {
    if (gamepieces.size() != width * height) {
        cerr << "Size mismatch" << endl;
        return wrongsize;
    }

    for (int row = height - 1; row >= 0; --row) {
        for (unsigned int col = 0; col < width; ++col) {
            unsigned int index = width * row + col;
            const game_piece &piece = gamepieces[index];

            if (piece.piececolor != no_color) {
                cout << piece.pieceonboard << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    return success;
}

//extra credit, adjacent pieces
int printAdjacentPieces(const std::vector<game_piece>& gamepieces, unsigned int width, unsigned int height) {
    if (gamepieces.size() != width * height) {
        cerr << "Size mismatch" << endl;
        return wrongsize;
    }

    const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (unsigned int row = 0; row < height; ++row) {
        for (unsigned int col = 0; col < width; ++col) {
            unsigned int index = width * row + col;

            const game_piece& piece = gamepieces[index];

            if (piece.piececolor != no_color) {
                cout << "Square (" << col << ", " << row << "): "
                     << piece.piecename << " (" << piece_colorString(piece.piececolor) << ")";

                cout << " Adjacent: ";

                bool first = true;
                for (int i = 0; i < 8; ++i) {
                    int adj_x = col + dx[i];
                    int adj_y = row + dy[i];

                    if (adj_x >= 0 && adj_x < width && adj_y >= 0 && adj_y < height) {
                        unsigned int adj_index = width * adj_y + adj_x;
                        const game_piece& adj_piece = gamepieces[adj_index];

                        if (adj_piece.piececolor != no_color) {
                            if (first) {
                                first = false;
                            } else {
                                cout << ", ";
                            }
                            cout << adj_piece.piecename << " (" << piece_colorString(adj_piece.piececolor) << ")";
                        }
                    }
                }

                cout << endl;
            }
        }
    }

    return success;
}