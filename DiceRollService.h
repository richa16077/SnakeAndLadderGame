//
// Created by richa on 20/08/21.
//

#ifndef SNAKEANDLADDER_DICEROLLSERVICE_H
#define SNAKEANDLADDER_DICEROLLSERVICE_H


#include <ctime>
#include <cstdlib>

class DiceRollService {
public:
    static int diceRoll(int numberOfDice){

        //srand(time(0));
        return (rand() % (6*numberOfDice))+numberOfDice;
    }
};


#endif //SNAKEANDLADDER_DICEROLLSERVICE_H
