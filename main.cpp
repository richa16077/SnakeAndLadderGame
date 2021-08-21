#include<bits/stdc++.h>
#include "../models/Snake.h"
#include "../models/Ladder.h"
#include "../models/Player.h"
#include "../services/SnakeAndLadderService.h"

using namespace std;

int main() {
    cout<<"Enter the number of snakes:"<<endl;
    int s;
    cin>>s;
    list<Snake> snakes;

    for(int i=0; i<s; i++){
        int start, end;
        cin>>start>>end;
        Snake snake(start, end);
        snakes.push_back(snake);
    }

    cout<<"Enter the number of ladders:"<<endl;
    int l;
    cin>>l;
    list<Ladder> ladders;

    for(int i=0; i<l; i++){
        int head, tail;
        cin>>head>>tail;
        Ladder ladder(head, tail);
        ladders.push_back(ladder);
    }

    cout<<"Enter the number of players:"<<endl;
    int p;
    cin>>p;
    list<Player> players;

    for(int i=0; i<p; i++){
        string name;
        cin>>name;
        Player player(name);
        players.push_back(player);
    }

    cout<<"Do you wish to allow multiple dice rolls on 6? (Enter Y/y for YES, any other key for NO): "<<endl;
    char multipleSix;
    bool multipleDiceRollsOnSix;
    cin>>multipleSix;

    if(multipleSix == 'Y' or multipleSix == 'y'){
        multipleDiceRollsOnSix = true;
    }
    else{
        multipleDiceRollsOnSix = false;
    }

    cout<<"Enter the Number of Dice: "<<endl;
    int numberOfDice;
    cin>>numberOfDice;

    cout<<"Enter the size of the board: "<<endl;
    int sizeOfBoard;
    cin>>sizeOfBoard;

    cout<<"Should Game continue till the last player? (Enter Y/y for YES, any other key for NO): "<<endl;
    char gameContinue;
    cin>>gameContinue;
    bool gameContinueTillLastPlayer;
    if(gameContinue == 'Y' or gameContinue == 'y'){
        gameContinueTillLastPlayer = true;
    }
    else{
        gameContinueTillLastPlayer = false;
    }

    SnakeAndLadderService snakeAndLadderService;
    snakeAndLadderService.setSizeOfBoard(sizeOfBoard);
    snakeAndLadderService.setShouldGameContinueTillLastPlayer(gameContinueTillLastPlayer);
    snakeAndLadderService.setShouldAllowMultipleDiceRollsOnSix(multipleDiceRollsOnSix);
    snakeAndLadderService.setNumberOfDice(numberOfDice);
    snakeAndLadderService.setPlayers(players);
    snakeAndLadderService.setSnakes(snakes);
    snakeAndLadderService.setLadders(ladders);
    snakeAndLadderService.startGame();
    return 0;
}
