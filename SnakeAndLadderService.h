//
// Created by richa on 20/08/21.
//

#ifndef SNAKEANDLADDER_SNAKEANDLADDERSERVICE_H
#define SNAKEANDLADDER_SNAKEANDLADDERSERVICE_H

using namespace std;
#include "../models/SnakeAndLadderBoard.h"
#include "../models/Player.h"
#include "DiceRollService.h"

class SnakeAndLadderService {
    SnakeAndLadderBoard snakeAndLadderBoard = SnakeAndLadderBoard(0);
    queue<Player> players;
    DiceRollService diceRollService;

    int numberOfDice;
    int sizeOfBoard;
    int numberOfPlayers;

    bool shouldGameContinueTillLastPlayer;
    bool shouldAllowMultipleDiceRollsOnSix;

    static const int defaultNoOfDice = 1;
    static const int defaultBoardSize = 100;

public:
    SnakeAndLadderService(int sizeOfBoard, int numberOfDice){
        this->sizeOfBoard = sizeOfBoard;
        this->snakeAndLadderBoard = SnakeAndLadderBoard(sizeOfBoard);
        this->numberOfDice = numberOfDice;
    }

    SnakeAndLadderService():SnakeAndLadderService(defaultBoardSize, defaultNoOfDice) {}

    void setSizeOfBoard(int sizeOfBoard) {
        SnakeAndLadderService::sizeOfBoard = sizeOfBoard;
    }

    void setNumberOfDice(int numberOfDice) {
        SnakeAndLadderService::numberOfDice = numberOfDice;
    }

    void setShouldGameContinueTillLastPlayer(bool shouldGameContinueTillLastPlayer) {
        SnakeAndLadderService::shouldGameContinueTillLastPlayer = shouldGameContinueTillLastPlayer;
    }

    void setShouldAllowMultipleDiceRollsOnSix(bool shouldAllowMultipleDiceRollsOnSix) {
        SnakeAndLadderService::shouldAllowMultipleDiceRollsOnSix = shouldAllowMultipleDiceRollsOnSix;
    }

    //Setting Snakes, Ladders and Players on the SnakeAndLadderBoard
    void setPlayers(list<Player> players){
        map<string, int> playerPieces;
        this->numberOfPlayers = players.size();
        for(Player player: players){
            this->players.push(player);
            playerPieces.insert({player.getId(), 0});
        }
        snakeAndLadderBoard.setPlayers(playerPieces);
//        cout<<"Following players set in Service"<<endl;
//        for(Player player: players){
//            cout<<player.getName()<<"-"<<player.getId()<<endl;
//        }
    }

    void setSnakes(list<Snake> snakes){
        snakeAndLadderBoard.setSnakes(snakes);
    }

    void setLadders(list<Ladder> ladders){
        snakeAndLadderBoard.setLadders(ladders);
    }

    // Main logic of the game

    //Checking if a player has won or not
    bool hasWon(Player player){
        int playerPosition = snakeAndLadderBoard.getPlayerPieces().at(player.getId());
        int winningPosition = snakeAndLadderBoard.getSize();
        return (playerPosition == winningPosition);
    }

    // New Position after trying for snakes and ladders
    int trySnakeAndLadder(int newPosition){
        int prevPosition;

        do{
            prevPosition = newPosition;
            for(Snake snake: snakeAndLadderBoard.getSnakes()){
                if(newPosition == snake.getHead()){
                    newPosition = snake.getTail();
                }
            }
            for(Ladder ladder: snakeAndLadderBoard.getLadders()){
                if(newPosition == ladder.getFirstStep()){
                    newPosition = ladder.getLastStep();
                }
            }
        }while(prevPosition!=newPosition);
        return newPosition;
    }

    //Moving a player at a dice roll
    void movePlayer(Player player, int diceRoll){
        int oldPosition = snakeAndLadderBoard.getPlayerPieces().at(player.getId());
        int newPosition = oldPosition + diceRoll;

        int boardSize = snakeAndLadderBoard.getSize();
        if(newPosition > boardSize){
            newPosition = oldPosition;
        }
        else{
            newPosition = trySnakeAndLadder(newPosition);
        }
        map<string, int> currentPlayerPieces = snakeAndLadderBoard.getPlayerPieces();
        currentPlayerPieces[player.getId()] = newPosition;
        snakeAndLadderBoard.setPlayers(currentPlayerPieces);

        cout<<"Player "<<player.getName()<<" rolled a "<<diceRoll<<" and moved from "<<oldPosition<<" to "<<newPosition<<endl;
    }

    //To check how many players are playing
    bool isGameCompleted(){
        int currentPlayers = players.size();

        if(!shouldGameContinueTillLastPlayer){
            return currentPlayers < numberOfPlayers;
        }
        return currentPlayers == 1;
    }

    //Obtain a dice roll
    int getDiceRoll(){
        int diceRoll = diceRollService.diceRoll(numberOfDice);
        int count = 0;
        if(diceRoll == 6 and shouldAllowMultipleDiceRollsOnSix){
            while(diceRoll == 6 and count < 3){
                count++;
                diceRoll = diceRollService.diceRoll(numberOfDice);
            }
            if(count == 3){
                diceRoll = 0;
            }
        }
        return diceRoll;
    }
    //Starting point of the game. It uses the isGameCompleted Function.
    void startGame(){
        cout<<"Starting the Game: "<<endl;
        while(!isGameCompleted()){
            int diceRoll = getDiceRoll();
            Player currentPlayer = players.front();
            players.pop();

            movePlayer(currentPlayer, diceRoll);
            if(hasWon(currentPlayer)){
                cout<<"Player "<<currentPlayer.getName()<<" has won!"<<endl;
                map<string, int> currentPlayerPieces = snakeAndLadderBoard.getPlayerPieces();
                currentPlayerPieces.erase(currentPlayer.getId());
                snakeAndLadderBoard.setPlayers(currentPlayerPieces);
            }
            else{
                players.push(currentPlayer);
            }
        }
    }
};


#endif //SNAKEANDLADDER_SNAKEANDLADDERSERVICE_H
