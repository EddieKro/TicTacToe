//
// Created by alexa on 4/1/2018.
//

#ifndef TICTACTOE_AI_H
#define TICTACTOE_AI_H


#include "Board.h"

struct AI_Move {
    AI_Move() {};
    AI_Move(int Score) : score(Score) {};
    int x;
    int y;
    int score;
};

class AI {
public:
    //Initialize master player
    void initialize(int masterPlayer);
    void makeMove(Board& board, int masterPlayer);
    AI();
    ~AI();

private:
    AI_Move _getBest(Board& board, int player);
    int _aiPlayer;
    int _humanPlayer;
};



#endif //TICTACTOE_AI_H
