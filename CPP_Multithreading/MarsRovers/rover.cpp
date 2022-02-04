
#include "stdafx.h"
#include "rover.h"

// arrays for the x and y movements depending on the current direction of rover
const int Rover::m_xpos[MAXDIRECTION] = {0, 1, 0, -1};
const int Rover::m_ypos[MAXDIRECTION] = {1, 0, -1, 0};
PositionPoint Rover::m_RoverPosLimit;

//rotate rover left by 90 degree
void Rover :: rotateLeft()
{
    switch (m_RoverPos.roverDirection)
    { 
    case North: 
        m_RoverPos.roverDirection = West; 
        break;
    case West:
        m_RoverPos.roverDirection = South;
        break;
    case South:
        m_RoverPos.roverDirection = East;
        break;
    case East:
        m_RoverPos.roverDirection = North;
        break;
    }
}

//rotate rover right by 90 degree
void Rover :: rotateRight()
{
    switch (m_RoverPos.roverDirection)
    { 
    case North:
        m_RoverPos.roverDirection = East;
        break;
    case West:
        m_RoverPos.roverDirection = North;
        break;
    case South:
        m_RoverPos.roverDirection = West;
        break;
    case East:
        m_RoverPos.roverDirection = South;
        break;
    }
}

//move forward one grid point
void Rover::movePosition()
{
    m_RoverPos.roverCoordinates.x += m_xpos[m_RoverPos.roverDirection];
    m_RoverPos.roverCoordinates.y += m_ypos[m_RoverPos.roverDirection];
}

//get rover's current Coordinates
PositionPoint Rover::GetPos()
{
    return m_RoverPos.roverCoordinates;
}

//get rover's current direction
CompassPoint Rover::GetHeading()
{
    return m_RoverPos.roverDirection;
}

//rover executes input command
bool Rover::Explore(std::string strCommand)
{
    if (isInit())
    {
        for (size_t cmdIndex = 0;cmdIndex < strCommand.size(); cmdIndex++ )
        {
            switch(strCommand.at(cmdIndex))
            {
            case 'R':
                rotateRight();
                break;
            case 'L':
                rotateLeft();
                break;
            case 'M':
                movePosition();
                break;
            default:
                return false;
            }
        }
        return true;
    }
    return false;
}

//initialization of rover
void Rover::init()
{
    m_binitialise = validateRoverPositionAndDirection();
}

//validate rover's current position and direction
bool Rover::validateRoverPositionAndDirection()
{
    if (m_RoverPos.roverCoordinates.x < 0 
        || m_RoverPos.roverCoordinates.y < 0
        || m_RoverPos.roverCoordinates.x > m_RoverPosLimit.x 
        || m_RoverPos.roverCoordinates.y > m_RoverPosLimit.y
        || m_RoverPos.roverDirection < 0 
        || m_RoverPos.roverDirection >= MAXDIRECTION)
    {
        cout << "Invalid instructions";
        return false;
    }
    return true;
}

//read initialization status
bool Rover::isInit()
{
    return m_binitialise;
}

//constructor of rover
Rover::Rover( RoverPos intialRoverPos )
    : m_RoverPos(intialRoverPos)
{
    init();
}