
#import "../inc/followpath.h"
#import "../inc/motors.h"
#include <Arduino.h>
#include <deque>

FollowPath::FollowPath()
{

}

void FollowPath::pushMovement(char move)
{
    if(pathlist.front().movement == move)
    {
        ++pathlist.front().amount;
    }
    else
    {
        pathlist.push_front(command{move,1});   
    }
}

void FollowPath::runList()
{
    command currMove;
    while (!pathlist.empty())
    {
        currMove = pathlist.pop_front();
        switch(currMove.movement)
        {
            case 'l':
                turnLeft(150,90 * currMove.amount);
                break;
            case 'r':
                turnRight(150,90 * currMove.amount);
                break;
            case 'f':
                forwardTillDistance(150, 16 * currMove.amount);
                break;
        }
    }
}