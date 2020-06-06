//@author Simon Vavra <vavrasim@fit.cvut.cz>
#include "CApplication.h"

void CApplication::Run()
{
    while ( m_Running )
    {
        this->MenuLoop();
    }
}

void CApplication::MenuLoop()
{
    if ( !m_InGame ) this->PrintMenu();
    else m_CGame.Print( m_Message );
    this->AwaitCommand();
}

void CApplication::PrintMenu()
{
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #endif

    std::cout << "\n\n"
              << "    ▄████████    ▄█     █▄       ▄████████    ▄████████    ▄████████\n"
              << "    ███    ███   ███    ███     ███    ███   ███    ███   ███    ███\n"
              << "    ███    █▀    ███    ███     ███    █▀    ███    █▀    ███    █▀\n"
              << "    ███         ▄███▄▄▄▄███▄▄  ▄███▄▄▄       ███          ███\n"
              << "    ███        ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ▀███████████ ▀███████████\n"
              << "    ███    █▄    ███    ███     ███    █▄           ███          ███\n"
              << "    ███    ███   ███    ███     ███    ███    ▄█    ███    ▄█    ███\n"
              << "    ████████▀    ███    █▀      ██████████  ▄████████▀   ▄████████▀\n\n"
              << "    by Šimon Vávra\n\n\n\n\n\n\n"
              << "Enter a command or type \"help\":\n\n"
              << m_Message << std::endl;
}

void CApplication::AwaitCommand()
{
    CCommand command;
    std::pair <int, std::string> outcome;
    if ( !m_InGame )
        std::cin >> command;
    else
        m_CGame.AwaitMove() >> command;
    outcome = command.Do ( m_CGame );
    if ( outcome.first == -1 ) m_Running = false; //exit app
    if ( outcome.first ==  1 ) m_InGame = true;   //starts game
    if ( outcome.first ==  2 ) m_InGame = false;  //exits game
    if ( outcome.first ==  3 && m_InGame ) m_CGame.SwitchTurn(); //invalid move, current player plays again
    m_Message = outcome.second;
}