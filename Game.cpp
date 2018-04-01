//
// Created by alexa on 4/1/2018.
//simple 3x3 tic-tac-toe using minimax AI algorithm
//

#include <iostream>
#include <cstdlib>
#include "Game.h"
#include <cmath>

using namespace std;

void Game::_handleMenu() {

    cout << "Welcome to a new game\n";
    cout << "Would you like to play in a multiplayer mode? (y/n):";

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); ++i) {//shortest toLower() possible
        input[i] = tolower(input[i]);
    }

    if (input == "exit") {
        _gameState = State::EXIT;
    }

    if (input == "n") {
        _gameState = State::SP;
    } else _gameState = State::MP;


    bool flag;
    char inp = ' ';

    if (input != "exit") {

        cout << ("\nPlease, choose X or O (X goes first):");
        do {
            flag = true;
            if (!(std::cin >> inp)) {
                std::cout << "Invalid input!";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                flag = false;
            } else if (inp == 'x' || inp == 'X') {
                _humanPlayer = X_VAL;
                _pcPlayer = O_VAL;
                _currentPlayer = _humanPlayer;

            } else if (inp == 'o' || inp == 'O') {
                _humanPlayer = O_VAL;
                _pcPlayer = X_VAL;
                _currentPlayer = _pcPlayer;

            } else {
                std::cout << "Please, input x or y";
                flag = false;
            }
        } while (!flag);
    }

}

void Game::_changePlayer() {
    if (_currentPlayer == _humanPlayer) {
        _currentPlayer = _pcPlayer;
    } else {
        _currentPlayer = _humanPlayer;
    }
}

void Game::_displayresult(int gameEnd) {
    if (gameEnd == VIC_VAL) {
        if (_currentPlayer == _humanPlayer) {
            if (_gameState == State::MP) {
                if (_humanPlayer == X_VAL)cout << "Player#1 won! Congratulations\n";
            } else {
                cout << ("You won. Congrats!\n");
            }
        } else {
            if (_gameState == State::MP) {
                if (_pcPlayer == O_VAL)cout << "Player#2 won! Congratulations\n";
            } else {
                cout << ("You lost. Try again\n");
            }
        }
    } else {
        cout << ("Draw. Thanks for a nice game.\n");
    }
}


void Game::_humanMove(int player) {
    bool moveMade = false;
    while (!moveMade) {
        int x = -1, y = -1;
        while (!(1 <= x && x <= 3) && !(1 <= y && y <= 3)) {
            cout << "Please, input X and Y:" << ("Input X: ");
            std::cin >> x;
            cout << ("Input Y: ");
            std::cin >> y;

        }
        cout << "<" << x << "," << y << ">";
        x--;
        y--;
        if (_board.getVal(x, y) == NO_VAL) {
            _board.setVal(x, y, player);
            moveMade = true;
        } else {
            cout << ("Please, try another cell. This one is already taken.");
        }
    }

}

void Game::_aiMove() {
    if (_gameState == State::MP) _humanMove(_pcPlayer);
    else _ai.makeMove(_board, _pcPlayer);
}

void Game::run() {
    _handleMenu();
    _board.initialize();
    while (_gameState != State::EXIT) {

        _board.show();

        if (_gameState == State::SP || _gameState == State::MP) {
            if (_currentPlayer == _humanPlayer) {
                _humanMove(_humanPlayer);
            } else {
                _aiMove();
            }
        }
        int gameEnd = _board.checkVictoryConditions();
        if (gameEnd == VIC_VAL || gameEnd == TIE_VAL) {
            for (int i = 0; i < 4; i++) {
                cout << "\n";
            }
            _board.show();
            _displayresult(gameEnd);
            cout << "Press 'e' to exit. Press any other key to play another game\n";
            char inp;
            cin >> inp;
            if (inp == 'e' || inp == 'E') _gameState = State::EXIT;
            else run();
        } else {
            _changePlayer();

            for (int i = 0; i < 4; i++) {//to add some space to console
                cout << "\n\n";
            }
        }
        cout << "Thanks for the attention\n";
    }

}

Game::Game() {}//default constructors-destructors
Game::~Game() {}
