//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <string>
#include <utility>
#include <iostream>
#include "CGame.h"
#include "CCommand.h"

//! Application class
/*!
    Class that manages running of program such as game loop,
    or getting commands from user.
 */


class CApplication
{
private:

    CGame m_CGame; //! Instance of the game
    bool m_Running;//! Boolean determining whether app runs
    bool m_InGame; //! Boolean determining whether user is in-game
    std::string m_Message; //! Holds message to be displayed

public:
    //! Constructor
    /*!
        Simple constructor, application runs and user is not in-game
     */
    CApplication (){
        m_Running = true;
        m_InGame = false;
    };

    //! App loop
    /*!
        Either displays main menu or displays board.
     */
    void Run();

    //! Prints main menu
    /*!
        Clears console and prints menu
     */
    void PrintMenu ();

    //! Reads user command
    /*!
        Reads commands and decides the state of the game,
        kills the app or starts game loop
     */
    void AwaitCommand ();
};