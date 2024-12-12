#include "mockos/BasicDisplayVisitor.h"
#include <iostream>

using namespace std;

BasicDisplayVisitor::BasicDisplayVisitor(bool unformatted) : unformatted(unformatted) {}

void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
    vector<char> contents = file->read();
    for (char c : contents) {
        cout << c;
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
    vector<char> contents = file->read();
    unsigned int size_of_row = sqrt(file->getSize());

    for (int row = 0; row < size_of_row; ++row) {
        for (int col = 0; col < size_of_row; ++col) {
            cout << contents[row * size_of_row + col];
        }
        if (!unformatted) //for formatted version:
        {
            cout << endl;
        }
    }
    cout << endl;
}