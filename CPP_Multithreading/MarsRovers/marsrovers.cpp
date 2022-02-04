// MarsRovers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "marsroverexploration.h"
#include "roverhelper.h"

//main function
int main()
{
    if (RoverHelper::readInput())
    {
        MarsRoverExploration * marsRoverExplorer = new MarsRoverExploration();
        if (marsRoverExplorer->isInit())
        {
            marsRoverExplorer->startExploration();
            marsRoverExplorer->printOutput();//printing final output
        }
        marsRoverExplorer->release();//releasing resources
        delete marsRoverExplorer;
    }
    else
    {
        cout << "input.txt is in wrong format or not present";
    }
    _getch();
	return 0;
}

