//
// Created by richa on 20/08/21.
//

#ifndef SNAKEANDLADDER_PLAYER_H
#define SNAKEANDLADDER_PLAYER_H
#include<string>
using namespace std;
static int currentID = 0;

class Player {
    std::string name;
    std::string id;

public:
    Player(const string &name) : name(name) {
        id = currentID++;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Player::name = name;
    }

    const std::string &getId() const {
        return id;
    }

    void setId(const std::string &id) {
        Player::id = id;
    }

};


#endif //SNAKEANDLADDER_PLAYER_H
