
#include "micromouseserver.h"

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
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/
    /*
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

    grid[x][y]++;

    if (direction == 0) {
        left = grid[x-1][y];
        right = grid[x+1][y];
        forward = grid[x][y+1];
    } else if (direction = 1) {
        left = grid[x][y+1];
        right = grid[x][y-1];
        forward = grid[x+1][y];
    } else if (direction = 2) {
        left = grid[x+1][y];
        right = grid[x-1][y];
        forward = grid[x][y-1];
    } else if (direction = 3) {
        left = grid[x][y-1];
        right = grid[x][y+1];
        forward = grid[x-1][y];
    }

    if (count == 4) {
        foundFinish();
    } else if (!isWallLeft() && left <= forward && left <= right) {
        turnLeft();

        if (direction == 0) direction = 3;
        else direction--;

        moveForward();

        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;

        count++;
    } else if (!isWallForward() && forward <= right && forward <= left) {
        count = 0;
        moveForward();

        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else x--;

    } else if (!isWallRight() && right <= forward && right <= left) {
        count = 0;
        turnRight();

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

