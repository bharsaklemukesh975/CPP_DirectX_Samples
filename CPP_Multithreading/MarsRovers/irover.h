#ifndef IROVER_H 
#define  IROVER_H

#include "stdafx.h"
#include "commonheader.h"

//interface for Rover 
class IRover {
public:
    virtual bool Explore(std::string strCommand) = 0;
    virtual PositionPoint GetPos() = 0;
    virtual CompassPoint GetHeading() = 0; 
};

#endif IROVER_H