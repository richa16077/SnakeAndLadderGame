//
// Created by richa on 20/08/21.
//

#ifndef SNAKEANDLADDER_LADDER_H
#define SNAKEANDLADDER_LADDER_H


class Ladder {
    int firstStep;
    int lastStep;

public:
    Ladder(int firstStep, int lastStep) : firstStep(firstStep), lastStep(lastStep) {}

    int getFirstStep() const {
        return firstStep;
    }

    void setFirstStep(int firstStep) {
        Ladder::firstStep = firstStep;
    }

    int getLastStep() const {
        return lastStep;
    }

    void setLastStep(int lastStep) {
        Ladder::lastStep = lastStep;
    }
};


#endif //SNAKEANDLADDER_LADDER_H
