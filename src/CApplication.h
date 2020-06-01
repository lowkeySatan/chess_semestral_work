//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once
#include "CGame.h"



class CApplication
{
private:

    CGame m_CGame;
    bool m_Running;

public:

    CApplication (){
        m_Running = true;
    };

    void Run();

    void GameLoop();

    void Print ();
};