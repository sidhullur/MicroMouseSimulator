
#include "micromouseserver.h"
#include <iostream>
using namespace std;

void microMouseServer::studentAI()
{

    static int count;
    static int grid [20][20];
    static int direction;
    /*  0
     *3   1
     *  2
     */
    static int x;
    static int y;

    static int left;
    static int right;
    static int forward;

    /*

    // Unislanded Maze Solution:
    if (isWallRight() && !isWallForward())
    {
        moveForward();
        count = 0;
    }
    if (!isWallRight())
    {
        turnRight();
        moveForward();
        count = 0;
    }
    if (isWallRight() && isWallForward() && isWallLeft())
    {
        turnLeft();
        turnLeft();
        count = 0;
    }
    if (isWallRight() && isWallForward())
    {
        turnLeft();
        moveForward();
        count = count + 1;
    }
    if (count == 3)
    {
        foundFinish();
    }
    */

    // Islanded Maze Solution
    grid[x][y]++;

    if (direction == 0) {
        left = grid[x-1][y];
        right = grid[x+1][y];
        forward = grid[x][y+1];
    } else if (direction == 1) {
        left = grid[x][y+1];
        right = grid[x][y-1];
        forward = grid[x+1][y];
    } else if (direction == 2) {
        left = grid[x+1][y];
        right = grid[x-1][y];
        forward = grid[x][y-1];
    } else if (direction == 3) {
        left = grid[x][y-1];
        right = grid[x][y+1];
        forward = grid[x-1][y];
    }

    if (count == 4) {
        foundFinish();
    } else if (!isWallLeft() && ((left <= forward && left <= right) || (isWallRight() && isWallForward()))) {
        turnLeft();
        count = 0;

        if (direction == 0) direction = 3;
        else direction--;

        moveForward();

        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;
    } else if (!isWallForward() && (forward <= right || (isWallLeft() && isWallRight()))) {
        count = 0;
        moveForward();

        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;

    } else if (!isWallRight() && ((right <= left && right <= forward) || (isWallLeft() && isWallForward()))) {
        turnRight();
        count++;

        if (direction == 3) direction = 0;
        else direction++;

        moveForward();

        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;
    } else {
        turnLeft();
        turnLeft();

        if (direction == 2) direction = 0;
        else if (direction == 3) direction = 1;
        else direction++;
    }

}

