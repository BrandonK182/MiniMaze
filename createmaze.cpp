#include "createmaze.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

createMaze::createMaze()
{
    srand (time(NULL));


    for(int i=0;i<totalRows;i++)
    {
      for(int j=0;j<totalCols;j++)
      {
        map[i][j] = "\u25A0";
      }
    }

    entrance = rand() % 5;
    entrance = 2*entrance + 1;

    firstMove(map, entrance);
    generate(map, 1, entrance);
    cExit(map);
}

/******************************************************************************
 *  AUTHORS        : Brandon Kieng
 *  Recursion Maze
 * ***************************************************************************/
using namespace std;
/**********************************************************
 * LAB 14 - Recursion Maze
 *_________________________________________________________
 * This program converts creates a maze by moveing two spaces
 * at a time based on a random entrance point, then constantly
 * a random generation function that avoids the boarders. It
 * finishes of the maze by placing an exit at the end of the
 * maze on the opposite wall of the entrance.
 *_________________________________________________________
 * INPUT:
 *  none
 *
 * OUTPUT:
 * string map[][] - 2d array that contains the boundaries
 *                  for the maze
 ***********************************************************/

/*****************************************
* void firstMove
* function forces the first move of the generation to be two
* spacees south of the entrance
* Parameters: string a[][] - boundaries
*             int atCol - column to place entrance at
*****************************************/
void createMaze::firstMove(string a[totalRows][totalCols], int atCol)
{
  a[0][atCol] = " -";
  a[1][atCol] = " -";
}

/**********
* directions
* 0 - north
* 1 - east
* 2 - south
* 3 - west
**************/

/*******************************************
* bool outOfBounds
* funtion that determinses if a path for generation is going out of
* the set boundaries
* Parameters: string a[][] - boundaries
*             int atRow - current row
*             int atCol - current column
* Returns: bool OOB - true if out of boundaries
***********************************************/
void createMaze::generate(string a[totalRows][totalCols],int atRow, int atCol)
{
  int direc;
  int newRow = atRow;
  int newCol = atCol;
  bool repeat = true;
  bool skip = false;

  while (repeat == true)
  {
    // if there is a movement option
    if(outOfBounds(atRow, atCol,0) == true || taken(a, atRow, atCol, 0) == true)
    {
      if(outOfBounds(atRow, atCol,1) == true || taken(a, atRow, atCol, 1) == true)
      {
        if(outOfBounds( atRow, atCol,2) == true || taken(a, atRow, atCol, 2) == true)
        {
          if(outOfBounds( atRow, atCol,3) == true || taken(a, atRow, atCol, 3) == true)
          {
            repeat = false;
            skip = true;
          }
        }
      }
    }

    if(skip == false)
    {
      direc = rand() %4;

      //if the maze tries to make a new exit or leave dead end
      while(outOfBounds(atRow, atCol, direc)==true || taken(a, atRow, atCol, direc) == true)
      {
        direc = rand() %4;
      }

      //generating
      //North
      if(direc == 0)
      {
        newRow = atRow -2;
        a[atRow-1][atCol]= " -";
        a[atRow-2][atCol]= " -";
      }
      //East
      if(direc == 1)
      {
        newCol = atCol + 2;
        a[atRow][atCol+1]= " -";
        a[atRow][atCol+2]= " -";
      }
      //south
      if(direc == 2)
      {
        newRow = atRow +2;
        a[atRow+1][atCol]= " -";
        a[atRow+2][atCol]= " -";
      }
      //west
      if(direc == 3)
      {
        newCol = atCol - 2;
        a[atRow][atCol-1]= " -";
        a[atRow][atCol-2]= " -";
      }
      generate(a,newRow,newCol);
    }
  }
}


/*******************************************
* bool outOfBounds
* funtion that determinses if a path for generation is going out of
* the set boundaries
* Parameters: string a[][] - boundaries
*             int atRow - current row
*             int atCol - current column
* Returns: bool OOB - true if out of boundaries
***********************************************/
bool createMaze::outOfBounds(int atRow, int atCol, int direc)
{
  bool OOB = false;
  if(atRow == 1 && direc == 0 )
  {
    OOB = true;
  }
  if(atRow == totalRows-2 && direc == 2)
  {
    OOB = true;
  }
  if(atCol == 1 && direc == 3)
  {
    OOB = true;
  }
  if(atCol == totalCols-2 && direc == 1)
  {
    OOB = true;
  }
  return OOB;
}


/*****************************************
* bool taken
* function that determines that if a path for generation is traveling
* already has been traveled down before
* Parameters: string a[][] - boundaries
*             int atRow - current row
*             int atCol - current column
* Return: bool taken - true of path already been there
*********************************************/
bool createMaze::taken(string a[totalRows][totalCols],int atRow, int atCol, int direc)
{
  bool taken = false;
  if(atRow != 1)
  {
    if(direc == 0 && a[atRow-2][atCol]== " -")
    {
      taken = true;
    }
  }
  if(atRow != 9)
  {
    if(direc == 2 && a[atRow+2][atCol]== " -")
    {
      taken = true;
    }
  }
  if(atCol != 1)
  {
    if(direc == 3 && a[atRow][atCol-2] == " -")
    {
      taken = true;
    }
  }
  if(atCol != 11)
  {
    if(direc == 1 && a[atRow][atCol+2] == " -")
    {
      taken = true;
    }
  }
  return taken;
}


/*****************************************
* void exit
* function that creates a random exit on the opposite
* wall to that of the enterance
* Parameters: string a[][] - boundaries
*********************************************/
void createMaze::cExit(string a[totalRows][totalCols])
{
  exit = rand() % 5;
  exit = 2*exit + 1;
  a[totalRows-1][exit] = " -";
}


/*****************************************
* void display
* function that displays the contents of the array
* Parameters: string a[][] - boundaries
*********************************************/
void createMaze::display(string a[totalRows][totalCols])
{
  for(int i = 0; i< totalRows; i++)
  {
    for(int j = 0; j<totalCols; j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}

std::ostream& operator<<(std::ostream& out, const createMaze& pop)
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

string** createMaze::getMap()
{
    string** temp;
    temp = new string*[totalRows];

    for (int i = 0; i < totalCols; i++)
    {
          temp[i] = new string[totalCols];
    }
    for(int i = 0; i< totalRows; i++)
    {
      for(int j = 0; j<totalCols; j++)
      {
        temp[i][j] = map[i][j];
      }
    }
 return temp;
}

int createMaze::getEntrance()
{
    return entrance;
}

int createMaze::getExit()
{
    return exit;
}
