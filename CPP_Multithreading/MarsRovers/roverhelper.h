#pragma once

#ifndef ROVER_HELPER_H 
#define  ROVER_HELPER_H
#include <fstream>
#include "commonheader.h"

using namespace std;
/*--------------------------------------------------------------------------
Class of Helper function for mars exploration
--------------------------------------------------------------------------*/
class RoverHelper
{
    
public:
    static std::vector<std::string> m_str_vec_input;
    static bool readInput();
    static CompassPoint charToCommPoint(char cChar);
    static char CommPointToChar(CompassPoint cDirection);
    static PositionPoint readGridLimit();
    static RoverPos readRoverPos(int iRoverIndex);
    static std::string readRoverCommand(int iRoverIndex);

};
#endif ROVER_HELPER_H