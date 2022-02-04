#include "stdafx.h"
#include "roverhelper.h"

std::vector<std::string> RoverHelper::m_str_vec_input;
//converts character to compass point
CompassPoint RoverHelper::charToCommPoint(char cChar)
{
    switch(cChar)
    {
    case 'N':
        return North;
    case 'E':
        return East;
    case 'W':
        return West;
    case 'S':
        return South;
    }
    return static_cast<CompassPoint> (-1);
}

//converts compass point to character
char RoverHelper::CommPointToChar(CompassPoint cDirection)
{
    switch(cDirection)
    {
    case North:
        return 'N';
    case East:
        return 'E';
    case West:
        return 'W';
    case South:
        return 'S';
    }
    return ' ';
}

//reads the upper-right Coordinates of the plateau
PositionPoint RoverHelper::readGridLimit()
{
    stringstream strStreamLine( m_str_vec_input[0] );
    PositionPoint gridlimits;
    strStreamLine >> gridlimits.x >> gridlimits.y;
    return gridlimits;
}

//reads rover's position
RoverPos RoverHelper::readRoverPos(int iRoverIndex)
{
    size_t st_index;
    if (iRoverIndex == 0)
    {
        st_index = 1;
    }
    else
    {
        st_index = iRoverIndex + 2;
    }
    stringstream strStreamLine( m_str_vec_input[st_index] );
    PositionPoint roverPosPoint;
    char roverDir;
    strStreamLine >> roverPosPoint.x >> roverPosPoint.y >> roverDir;
    RoverPos iniRoverPos(roverPosPoint, charToCommPoint(roverDir));
    return iniRoverPos;
}

//reads rover's position
std::string RoverHelper::readRoverCommand(int iRoverIndex)
{
    size_t st_index;
    if (iRoverIndex == 0)
    {
        st_index = 2;
    }
    else
    {
        st_index = iRoverIndex + 3;
    }
    return m_str_vec_input[st_index];
}


//read input from file
bool RoverHelper::readInput()
{
    m_str_vec_input.clear();
    string strLine;
    ifstream infile;
    infile.open ("input.txt");
    if (infile.is_open())
    {
        while(!infile.eof()) // To get you all the lines.
        {
            getline(infile,strLine);
            if (strLine == "")
            {
                continue;
            }
            m_str_vec_input.push_back(strLine);
        }
        infile.close();
    }
    if (m_str_vec_input.size() < 3)
    {
        return false;
    }
    return true;
}