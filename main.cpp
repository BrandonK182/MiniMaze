#include "player.h"

#include <iostream>

using namespace std;

bool win;
player savedPlayer;
void start();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();


int main()
{
    char move;
    char answer;
    bool playAgain = true;
    while(playAgain == true)
    {
        start();
        win = false;
        while(win==false)
        {
            cin>>move;
            if(move=='w' || move=='W')
            {
                moveUp();
            }
            if(move=='s' || move=='S')
            {
                moveDown();
            }
            if(move=='a' || move=='A')
            {
                moveLeft();
            }
            if(move=='d' || move=='D')
            {
                moveRight();
            }
        }
        cout<<"play again? Y/N"<<endl;
        cin>>answer;
        if(answer == 'Y' || answer == 'y')
        {
            playAgain = true;
        }
        else
        {
            playAgain = false;
        }
    }
    return 0;
}

void start()
{
    player aPlayer;
    savedPlayer = aPlayer;
    cout<<savedPlayer;
}

void moveUp()
{
    savedPlayer.movePlayerUp();
    cout<<savedPlayer;
}

void moveRight()
{
    savedPlayer.movePlayerRight();
    cout<<savedPlayer;
}

void moveDown()
{
    savedPlayer.movePlayerDown();
    if(savedPlayer.getPlayerRow()==savedPlayer.totalRows)
    {
        cout<<"you win!"<<endl;
        win = true;
    }
    else
    {
        cout<<savedPlayer;
    }
}

void moveLeft()
{
    savedPlayer.movePlayerLeft();
    cout<<savedPlayer;
}
