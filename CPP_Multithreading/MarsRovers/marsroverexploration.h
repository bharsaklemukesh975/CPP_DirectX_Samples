#pragma once

#ifndef MARS_ROVER_EXPLORATION_H 
#define  MARS_ROVER_EXPLORATION_H
#include <process.h>
#include "rover.h"
#include "plateau.h"
#include "roverhelper.h"

/*--------------------------------------------------------------------------
Represents a data for rover thread
--------------------------------------------------------------------------*/
struct ThreadData;

/*--------------------------------------------------------------------------
Class for mars rover exploration
--------------------------------------------------------------------------*/
class MarsRoverExploration
{
    Plateau *m_roverPlateau; 
    vector<IRover*> m_roverSquad;
    bool m_binitialise;
    int m_rover_squad_limit;
    vector<string> m_vec_str_output;
    std::vector<HANDLE> m_vecHndThread;
    std::vector<ThreadData*> m_vecThreadStruct;
    HANDLE semaphore;

    void init();
    static unsigned int __stdcall runRoverThread(void* obj);
    void runRover(size_t roverIndex, std::string strCommand);
    void closeRoversThread();
    void closeSemaphoreHandle();
    void releaseThreadData();
    void releaseRovers();
    void releasePlateau();
public:
    MarsRoverExploration();
    bool isInit();
    void startExploration();
    void release();
    void printOutput();
};

struct ThreadData
{
    unsigned int iThreadID;
    std::string strCommand;
    size_t roverIndex;
    MarsRoverExploration* pMarsRoverExploration;
};

#endif MARS_ROVER_EXPLORATION_H