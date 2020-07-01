#include "player.h"
#include "createmaze.h"

#include <iostream>

player::player()
{
    playerCol = savedMaze.getEntrance();
    playerRow = 0;
    map = savedMaze.getMap();
    map[playerRow][playerCol] = " o";
}

void player::movePlayerUp()
{

    if(playerCol != 0)
    {
        if(map[playerRow-1][playerCol]!="\u25A0")
        {
            map[playerRow-1][playerCol] = " o";
            map[playerRow][playerCol] = " -";
            playerRow = playerRow-1;
        }
    }
}

void player::movePlayerDown()
{
    if(map[playerRow+1][playerCol]!="\u25A0")
    {
        map[playerRow+1][playerCol] = " o";
        map[playerRow][playerCol] = " -";
        playerRow = playerRow+1;
    }
}

void player::movePlayerRight()
{
    if(map[playerRow][playerCol+1]!="\u25A0")
    {
        map[playerRow][playerCol+1] = " o";
        map[playerRow][playerCol] = " -";
        playerCol = playerCol+1;
    }
}

void player::movePlayerLeft()
{
    if(map[playerRow][playerCol-1]!="\u25A0")
    {
        map[playerRow][playerCol-1] = " o";
        map[playerRow][playerCol] = " -";
        playerCol = playerCol-1;
    }
}

int player::getPlayerRow()
{
    return playerRow;
}

std::ostream& operator<<(std::ostream& out, const player& pop)
{
  for(int i = 0; i< pop.totalRows; i++)
  {
    for(int j = 0; j<pop.totalCols; j++)
    {
      out<<pop.map[i][j]<<" ";
    }
    out<<endl;
  }
  return out;
}
