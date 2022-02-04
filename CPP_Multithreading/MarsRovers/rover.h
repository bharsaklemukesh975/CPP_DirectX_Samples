#pragma once

#ifndef ROVER_H 
#define  ROVER_H
#include "irover.h"

using namespace std;

/*--------------------------------------------------------------------------
Represents a Rover
--------------------------------------------------------------------------*/
class Rover : public IRover
{

private:
    RoverPos m_RoverPos;
    static const int m_xpos[MAXDIRECTION];
    static const int m_ypos[MAXDIRECTION];
    bool m_binitialise;

    Rover();
    void init();
    void rotateLeft();
    void rotateRight();
    void movePosition();
    bool validateRoverPositionAndDirection();
public:
    static PositionPoint m_RoverPosLimit;
    Rover( RoverPos intialRoverPos );
    bool Explore(std::string strCommand);
    PositionPoint GetPos();
    CompassPoint GetHeading();
    bool isInit(); 
};

#endif ROVER_H