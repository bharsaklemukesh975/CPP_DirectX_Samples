#include "stdafx.h"
#include "plateau.h"

//constructor of plateau class
Plateau::Plateau(int upperX, int upperY )
    : m_strct_lower_left_cord(PositionPoint(0,0)),
    m_strct_upper_right_cord(PositionPoint(upperX, upperY))
{
    init();
}

//returns initialization status of plateau
bool Plateau::isInit()
{
    return m_binitialise;
}

//initialization of plateau
void Plateau::init()
{
    m_binitialise = validatePlateauCoordinates();
}

//add visited position of a rover
bool Plateau::addVisitedPosition(PositionPoint addPoint)
{
    if (std::find_if(m_vec_strct_visited_points.begin(),m_vec_strct_visited_points.end(), 
        [=] (PositionPoint &p)
    { 
        return (p.x == addPoint.x && p.y == addPoint.y);
    }) != m_vec_strct_visited_points.end())
    {
        return false;
    }
    m_vec_strct_visited_points.push_back(addPoint);
    return true;
}

//read plateau size
PositionPoint Plateau::GetPlateauLimit()
{
    return m_strct_upper_right_cord;
}

//validate plateau Coordinates
bool Plateau::validatePlateauCoordinates()
{
    if ( m_strct_upper_right_cord.x < m_strct_lower_left_cord.x || m_strct_upper_right_cord.y < m_strct_lower_left_cord.y)
    {
        cout << "Invalid upper-right Coordinates of the plateau";
        return false;
    }
    return true;
}