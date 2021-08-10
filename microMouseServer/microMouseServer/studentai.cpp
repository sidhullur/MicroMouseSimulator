
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
    cout << count;


    if(!isWallLeft()) {
        if (direction == 0) left = grid[x-1][y];
        else if (direction == 1) left = grid[x][y+1];
        else if (direction == 2) left = grid[x+1][y];
        else left = grid[x][y-1];
    } else left = INT_MAX;

    if(!isWallForward()) {
        if (direction == 0) forward = grid[x][y+1];
        else if (direction == 1) forward = grid[x+1][y];
        else if (direction == 2) forward = grid[x][y-1];
        else forward = grid[x-1][y];
    } else forward = INT_MAX;

    if(!isWallRight()) {
        if (direction == 0) right = grid[x+1][y];
        else if (direction == 1) right = grid[x][y-1];
        else if (direction == 2) right = grid[x-1][y];
        else right = grid[x][y+1];
    } else right = INT_MAX;

    if(!isWallLeft() && left <= forward && left <= right) {
        turnLeft();
        count = 0;

        if (direction == 0) direction = 3;
        else direction--;

        moveForward();
        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;
    } else if (!isWallForward() && forward <= right && forward <= left) {
        count = 0;
        moveForward();
        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;
    } else if (!isWallRight() && right <= forward && right <= left) {
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
        count = 0;
        if (direction == 2) direction = 0;
        else if (direction == 3) direction = 1;
        else direction+=2;
    }
    if(count == 3) foundFinish(); // Finished if three consecutive turns right (left-hand rule)







































    /* First Attempt of Islanded Maze:
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

    */

}
