//
// Created by alexa on 4/1/2018.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "Board.h"
#include "AI.h"

enum class State{MENU, SP,MP, EXIT};

class Game {
public:


    void run();

    Game();

    ~Game();

private:

    void _handleMenu();
    void _changePlayer();
    void _displayresult(int gameEnd);
    void _humanMove(int player);
    void _aiMove();

    Board _board;
    State _gameState;
    int _currentPlayer;
    int _pcPlayer;
    int _humanPlayer;

    AI _ai;

};


#endif //TICTACTOE_GAME_H
