//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once
#include "CInterface.h"
#include "CGame.h"



class CApplication
{
private:
    CInterface m_CInterface;
    CGame m_CGame;
public:
    void Run();
    bool AwaitCommand();
};