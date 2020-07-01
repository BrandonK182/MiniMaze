#ifndef CREATEMAZE_H
#define CREATEMAZE_H

#include <string>
using namespace std;

class createMaze
{
public:
    createMaze();
    const static int totalRows = 11; //Rows iin the matrix
    const static int totalCols = 13; //Columns in the matrix
    /*****************************************
    * void firstMove
    * function forces the first move of the generation to be two
    * spacees south of the entrance
    * Parameters: string a[][] - boundaries
    *             int atCol - column to place entrance at
    *****************************************/
    void firstMove(string a[totalRows][totalCols], int atCol);

    /******************************************
    * void generate
    * function that generates the rest of the maze bazed on the
    * first path created from the other function
    * Parameters: string a[][] - boundaries
    *             int atRow - current row
    *             int atCol - current column
    *******************************************/
    void generate(string a[totalRows][totalCols],int atRow, int atCol);

    /*******************************************
    * bool outOfBounds
    * funtion that determinses if a path for generation is going out of
    * the set boundaries
    * Parameters: string a[][] - boundaries
    *             int atRow - current row
    *             int atCol - current column
    * Returns: bool OOB - true if out of boundaries
    ***********************************************/
    bool outOfBounds(int atRow, int atCol, int direc);

    /*****************************************
    * bool taken
    * function that determines that if a path for generation is traveling
    * already has been traveled down before
    * Parameters: string a[][] - boundaries
    *             int atRow - current row
    *             int atCol - current column
    * Return: bool taken - true of path already been there
    *********************************************/
    bool taken(string a[totalRows][totalCols],int atRow, int atCol, int direc);

    /*****************************************
    * void exit
    * function that creates a random exit on the opposite
    * wall to that of the enterance
    * Parameters: string a[][] - boundaries
    *********************************************/
    void cExit(string a[totalRows][totalCols]);

    /*****************************************
    * void display
    * function that displays the contents of the array
    * Parameters: string a[][] - boundaries
    *********************************************/
    void display(string a[totalRows][totalCols]);

    friend std::ostream& operator<<(std::ostream&, const createMaze&);

    string** getMap();
    int getEntrance();
    int getExit();

private:
    int entrance;
    int exit;
    string map[totalRows][totalCols];
};

#endif // CREATEMAZE_H
