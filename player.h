#ifndef PLAYER_H
#define PLAYER_H
#include "createmaze.h"

class player
{
public:
    const static int totalRows = 11; //Rows iin the matrix
    const static int totalCols = 13; //Columns in the matrix
    player();
    void movePlayerUp();
    void movePlayerDown();
    void movePlayerLeft();
    void movePlayerRight();
    int getPlayerRow();

    friend std::ostream& operator<<(std::ostream&, const player&);

private:
    createMaze savedMaze;
    string** map;
    int playerRow;
    int playerCol;
};

#endif // PLAYER_H
