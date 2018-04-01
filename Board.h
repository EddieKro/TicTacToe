//
// Created by alexa on 4/1/2018.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <string>
#include <vector>

//some constants
const int SIZE = 3; //3x3 version //=board.getSize();
const int ROW_CPT = SIZE;//number of tiles needed to be filled to win

//board values indexes
const int NO_VAL = 0;
const int X_VAL = 1;
const int O_VAL = 2;

const int TIE_VAL = -1;//in case of a tie
const int VIC_VAL = 10;//in case of a victory

class Board {
public:

    Board();
    ~Board();

    void initialize();
    void clear();
    void show() const;

    int checkVictoryConditions() const;

    //in-place getters-setters
    void setVal(int x, int y, int cellState);
    int getVal(int x, int y) const;
    int getSize() const;

private:
    std::vector<std::vector<int>> _board;

    void addHorizontalLine(std::string &s) const;
    void addAux(std::string &s) const;
};


#endif //TICTACTOE_BOARD_H
