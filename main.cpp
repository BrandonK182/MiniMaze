#include "mainwindow.h"

#include <iostream>

using namespace std;

int main()
{
    char move;
    bool win = false;
    start();
    while(win==false)
    {
        cin>>move;
        if(move=='w' || move=='W')
        {
            moveUp();
        }
        if(move=='s' || move=='S')
        {
            movedown();
        }
        if(move=='a' || move=='A')
        {
            moveLeft();
        }
        if(move=='d' || move=='D')
        {
            moveRight();
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
        cout<<"you win!";
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
