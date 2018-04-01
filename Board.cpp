//
// Created by alexa on 4/1/2018.
//

#include "Board.h"
#include "iostream"
using namespace std;

Board::Board() {}//default constructor
Board::~Board() {}//default destructor

void Board::initialize() {
    _board.resize(SIZE, std::vector<int>(SIZE, NO_VAL));
    clear();
}

void Board::clear() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            _board[i][j] = NO_VAL;
        }
    }
}


void Board::show() const {//toString()
    string res="";
    addAux(res);
    addHorizontalLine(res);
    for (int i = 0; i < SIZE; i++) {
        res+=to_string(i+1);
        for (int j = 0; j < SIZE; j++) {
            res+="| ";
            if (_board[i][j] == NO_VAL) res += '-';
            else if (_board[i][j] == X_VAL) res += 'X';
            else res += 'O';
            res += ' ';
        }
        res += " |\n";
    }
    addHorizontalLine(res);
    addAux(res);
    cout << "\n" << res;
}

int Board::checkVictoryConditions() const {
    int cnt = 1;

    for (int i = 0; i < SIZE; i++) {//row
        cnt = 1;
        for (int j = 0; j < SIZE-1; j++) {
            if ((getVal(i,j) == getVal(i,j+1)) && (getVal(i,j) != NO_VAL)){
                cnt++;
                if (cnt == ROW_CPT) {
                    return VIC_VAL;
                }
            } else {
                cnt = 1;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {//col
        cnt = 1;
        for (int j = 0; j < SIZE-1; j++) {
            if ((getVal(j, i) == getVal(j+1, i)) && (getVal(j, i) != NO_VAL)) {
                cnt++;
                if (cnt == ROW_CPT) {
                    return VIC_VAL;
                }
            } else {
                cnt = 1;
            }
        }
    }

    for (int i = 1; i < SIZE-ROW_CPT+1; i++) {//main diagonal left->right
        cnt = 1;
        for (int k = 0; k < (SIZE-i-1); k++) {
            if ((getVal(k, i+k) == getVal(k+1, i + k+1)) && (getVal(k, i+k) != NO_VAL)) {
                cnt++;
                if (cnt == ROW_CPT) {
                    return VIC_VAL;
                }
            } else {
                cnt = 1;
            }
        }
    }

    for (int i = 0; i < SIZE - ROW_CPT + 1; i++) {//counter-diagonal left->right
        cnt = 1;
        for (int k = 0; k < (SIZE - i-1); k++) {
            if ((getVal(i+k, k) == getVal(i+k + 1, k + 1)) && (getVal(i+k, k) != NO_VAL)) {
                cnt++;
                if (cnt == ROW_CPT) {
                    return VIC_VAL;
                }
            } else {
                cnt = 1;
            }
        }
    }

    for (int i = 0; i < SIZE - ROW_CPT + 1; i++) {//main diagonal right->left
        cnt = 1;
        for (int k = 0; k < (SIZE - i-1); k++) {
            if ((getVal(SIZE-1-k,i + k) == getVal(SIZE-1-(k + 1), i + k + 1)) && (getVal(SIZE-1-k, i + k) != NO_VAL)) {
                cnt++;
                if (cnt == ROW_CPT) {
                    return VIC_VAL;
                }
            } else {
                cnt = 1;
            }
        }
    }

    for (int i = 1; i < SIZE - ROW_CPT + 1; i++) {//anti-diagonal left-right
        cnt = 1;
        for (int k = 0; k < (SIZE - i-1); k++) {
            if ((getVal(SIZE-1-i - k, k) == getVal(SIZE-i - k- 2, k + 1)) && (getVal(SIZE -1 - i - k, k) != NO_VAL)) {
                cnt++;
                if (cnt == ROW_CPT) {
                    return VIC_VAL;
                }
            } else {
                cnt = 1;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {//tie
        for (int j = 0; j < SIZE; j++) {
            if (_board[i][j] == NO_VAL) {
                return NO_VAL;
            }
        }
    }
    return TIE_VAL;
}

void Board::addHorizontalLine(std::string& s) const {//for a nice output
    s += "-";
    for (int x = 0; x < SIZE; x++) {
        s += "----";
    }
    s += "--\n";
}

void Board::addAux(std::string& s) const {
    s += " ";
    for (int i = 1; i <= SIZE; i++) {
        s += "| " + std::to_string(i) + " ";
    }
    s += "|\n";
}

void Board::setVal(int x, int y, int cellState) {
    _board[x][y] = cellState;
}

int Board::getVal(int x, int y) const {
    return _board[x][y];
}

int Board::getSize() const {
    return _board.size();
}
