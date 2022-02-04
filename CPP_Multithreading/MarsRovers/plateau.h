#pragma once

#ifndef PLATEAU_H 
#define  PLATEAU_H

#include "rover.h"

using namespace std;

/*--------------------------------------------------------------------------
Represents rectangular Plateau
--------------------------------------------------------------------------*/
class Plateau
{
private:
    PositionPoint m_strct_lower_left_cord;
    PositionPoint m_strct_upper_right_cord;
    std::vector<PositionPoint> m_vec_strct_visited_points; 
    bool m_binitialise;

    Plateau();
    void init();
    bool validatePlateauCoordinates();
public:
    Plateau(int upperX, int upperY );
    bool isInit();
    bool addVisitedPosition(PositionPoint);
    PositionPoint GetPlateauLimit();
};

#endif PLATEAU_H