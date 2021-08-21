//
// Created by richa on 20/08/21.
//

#ifndef SNAKEANDLADDER_SNAKE_H
#define SNAKEANDLADDER_SNAKE_H


class Snake {
    int head;
    int tail;

public:
    Snake(int head, int tail) : head(head), tail(tail) {}

    int getHead() const {
        return head;
    }

    void setHead(int head) {
        Snake::head = head;
    }

    int getTail() const {
        return tail;
    }

    void setTail(int tail) {
        Snake::tail = tail;
    }
};


#endif //SNAKEANDLADDER_SNAKE_H
