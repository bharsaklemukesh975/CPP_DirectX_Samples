#include "stdafx.h"
#include "marsroverexploration.h"

//Constructor of MarsRoverExploration
MarsRoverExploration::MarsRoverExploration()
{
    m_vec_str_output.clear();
    init();

}

//function to initialize mars rover exploration
void MarsRoverExploration::init()
{
    m_rover_squad_limit = (int)RoverHelper::m_str_vec_input.size() - 1;
    m_rover_squad_limit = m_rover_squad_limit/2;
    PositionPoint PlateauLimits = RoverHelper::readGridLimit();//read Plateau limit
    m_roverPlateau = new Plateau(PlateauLimits.x, PlateauLimits.y);
    if (!m_roverPlateau->isInit())
    {
        m_binitialise = false;
        return;
    }
    Rover::m_RoverPosLimit = m_roverPlateau->GetPlateauLimit();
    m_binitialise = true;
}

// returns initialization status of mars rover exploration
bool MarsRoverExploration::isInit()
{
    return m_binitialise;
}

//rover's start exploration using input command
void MarsRoverExploration::startExploration()
{
    semaphore = CreateSemaphore(0, 1, 1, 0);
    for (int roverIndex = 0; roverIndex < m_rover_squad_limit; roverIndex++)
    {
        RoverPos roverPosition = RoverHelper::readRoverPos(roverIndex);
        PositionPoint intialPos(roverPosition.roverCoordinates.x, roverPosition.roverCoordinates.y);
        RoverPos initialRoverPos(intialPos, roverPosition.roverDirection);
        m_roverSquad.push_back(new Rover(initialRoverPos));

        ThreadData *tempThread = new ThreadData();
        tempThread->roverIndex = roverIndex;
        tempThread->strCommand = RoverHelper::readRoverCommand(roverIndex);
        tempThread->pMarsRoverExploration = this;
        HANDLE tempHandle = (HANDLE)_beginthreadex(0, 0, &runRoverThread, (void*)tempThread, 0, 0);//starting rover thread to explorer plateau
        m_vecThreadStruct.push_back(tempThread);
        m_vecHndThread.push_back(tempHandle);
    }
    for (size_t roverThreadIndex = 0; roverThreadIndex < m_vecHndThread.size();roverThreadIndex++)
    {
        WaitForSingleObject(m_vecHndThread[roverThreadIndex], INFINITE);
    }
}

//Terminate all rover's thread
void MarsRoverExploration::closeRoversThread()
{
    for (size_t roverThreadIndex = 0; roverThreadIndex < m_vecHndThread.size();roverThreadIndex++)
    {
        CloseHandle(m_vecHndThread[roverThreadIndex]); 
    }
}

//close semaphore
void MarsRoverExploration::closeSemaphoreHandle()
{
    if(semaphore)
    {
        CloseHandle(semaphore);
    }
}

//release all rover's thread data 
void MarsRoverExploration::releaseThreadData()
{
    for (size_t threadDataIndex = 0; threadDataIndex < m_vecThreadStruct.size();threadDataIndex++)
    {
        delete m_vecThreadStruct[threadDataIndex];
    }
}

//release rover's resources
void MarsRoverExploration::releaseRovers()
{
    for (size_t roverIndex = 0; roverIndex < m_roverSquad.size(); roverIndex++)
    {
        if (m_roverSquad[roverIndex])
        {
            delete m_roverSquad[roverIndex];
        }
    }
}

//release plateau resources
void MarsRoverExploration::releasePlateau()
{
    if (m_roverPlateau)
    {
        delete m_roverPlateau;
    }
}

//releasing memories/resources
void MarsRoverExploration::release()
{
    closeRoversThread();
    closeSemaphoreHandle();
    releaseThreadData();
    releasePlateau();
}

//print final position and direction of rovers
void MarsRoverExploration::printOutput()
{
    cout << endl << "Output:" << endl;
    for (size_t outputLineIndex = 0; outputLineIndex < m_vec_str_output.size(); outputLineIndex++ )
    {
        cout << m_vec_str_output[outputLineIndex] << endl;
    }
}

unsigned int __stdcall MarsRoverExploration::runRoverThread(void* obj)
{
    ThreadData* tempStrctData = static_cast<ThreadData*>(obj);
    tempStrctData->pMarsRoverExploration->runRover(tempStrctData->roverIndex, tempStrctData->strCommand);
    return 0;
}

//rover exploring the plateau sequentially
void MarsRoverExploration::runRover(size_t roverIndex, std::string strCommand)
{
    WaitForSingleObject(semaphore, INFINITE);// entering into critical section
    if (m_roverSquad[roverIndex]->Explore(strCommand))
    {
        PositionPoint finalPos = m_roverSquad[roverIndex]->GetPos();
        string strRoverOutput;
        if (m_roverPlateau->addVisitedPosition(finalPos))
        {
            strRoverOutput = to_string(_LONGLONG(finalPos.x)) + " " +
                to_string(_LONGLONG(finalPos.y)) + " " +
                RoverHelper::CommPointToChar(m_roverSquad[roverIndex]->GetHeading());
        }
        else
        {
            strRoverOutput = "E R R";
        }
        m_vec_str_output.push_back(strRoverOutput);
    }
    ReleaseSemaphore(semaphore, 1, 0);//exiting from critical section
}