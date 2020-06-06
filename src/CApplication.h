//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <string>
#include <utility>
#include <iostream>
#include "CGame.h"
#include "CCommand.h"



class CApplication
{
private:

    CGame m_CGame;
    bool m_Running;
    bool m_InGame;
    std::string m_Message;

public:

    CApplication (){
        m_Running = true;
        m_InGame = false;
    };

    void Run();

    void MenuLoop();

    void PrintMenu ();

    void AwaitCommand ();
};