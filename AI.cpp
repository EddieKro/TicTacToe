//
// Created by alexa on 4/1/2018.
//

#include "AI.h"


void AI::initialize(int masterPlayer) {
    _aiPlayer = masterPlayer;
    if (_aiPlayer == X_VAL) {
        _humanPlayer = O_VAL;
    } else {
        _humanPlayer = X_VAL;
    }
}

void AI::makeMove(Board & board, int masterPlayer) {
    AI::initialize(masterPlayer);

    AI_Move bestMove = _getBest(board, _aiPlayer);
    board.setVal(bestMove.x, bestMove.y, _aiPlayer);
}

AI::AI() {}


AI::~AI() {}

AI_Move AI::_getBest(Board & board, int player) {

    int rv = board.checkVictoryConditions();
    if (rv == VIC_VAL && player == _aiPlayer) { //This is to see if the previous move was a win. by this time the player has changed.
        return AI_Move(-10);
    } else if (rv == VIC_VAL && player == _humanPlayer) {
        return AI_Move(10);
    } else if (rv == TIE_VAL) {
        return AI_Move(0);
    }

    std::vector<AI_Move> moves;

    //recursive function to get moves vector
    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            if (board.getVal(i,j) == NO_VAL) {

                AI_Move move;
                move.x = i;
                move.y = j;
                board.setVal(i, j, player);
                if (player == _aiPlayer) {
                    move.score = _getBest(board, _humanPlayer).score;
                } else {
                    move.score = _getBest(board, _aiPlayer).score;
                }
                moves.push_back(move);
                board.setVal(i, j, NO_VAL);
            }
        }
    }

    //pick the best move for the current player
    int bestMove = 0;
    if (player == _aiPlayer) {
        int bestScore = -1000000;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i].score > bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    } else {
        int bestScore = 1000000;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i].score < bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }

    }
    //return the best move
    return moves[bestMove];

}