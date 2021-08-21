//
// Created by richa on 20/08/21.
//

#ifndef SNAKEANDLADDER_SNAKEANDLADDERBOARD_H
#define SNAKEANDLADDER_SNAKEANDLADDERBOARD_H
#include<bits/stdc++.h>
#include "Snake.h"
#include "Ladder.h"

using namespace std;
class SnakeAndLadderBoard {
    int size;
    list<Snake> snakes;
    list<Ladder> ladders;
    map<string, int> playerPieces;

public:
    SnakeAndLadderBoard(int size) : size(size) {}

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        SnakeAndLadderBoard::size = size;
    }

    const list<Snake> &getSnakes() const {
        return snakes;
    }

    void setSnakes(const list<Snake> &snakes) {
        SnakeAndLadderBoard::snakes = snakes;
    }

    const list<Ladder> &getLadders() const {
        return ladders;
    }

    void setLadders(const list<Ladder> &ladders) {
        SnakeAndLadderBoard::ladders = ladders;
    }

    const map<string, int> &getPlayerPieces() const {
        return playerPieces;
    }

    void setPlayers(const map<string, int> &playerPieces) {
        SnakeAndLadderBoard::playerPieces = playerPieces;
    }

};


#endif //SNAKEANDLADDER_SNAKEANDLADDERBOARD_H
