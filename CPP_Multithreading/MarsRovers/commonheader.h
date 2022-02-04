#ifndef COMMON_HEADER_H 
#define  COMMON_HEADER_H

#define MAXDIRECTION 4

/*--------------------------------------------------------------------------
Represents a location in a 2D integer Coordinates
--------------------------------------------------------------------------*/

typedef struct _point
{
    int x;
    int y;
    
    _point(int ix, int iy)
    {
        x = ix;
        y = iy;
    }
    _point(){}
}PositionPoint;

/*--------------------------------------------------------------------------
Represents a cardinal direction
--------------------------------------------------------------------------*/

typedef enum _compassPoint
{
    North,
    East,
    South,
    West
}CompassPoint;


/*--------------------------------------------------------------------------
Represents a position and direction of a Rover
--------------------------------------------------------------------------*/

typedef struct _roverPos {
    PositionPoint roverCoordinates;
    CompassPoint roverDirection; 
    _roverPos(PositionPoint roverCord, CompassPoint roverDir) 
        : roverCoordinates(roverCord), roverDirection(roverDir) {}
}RoverPos;

#endif COMMON_HEADER_H