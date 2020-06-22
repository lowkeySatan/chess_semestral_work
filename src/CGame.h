//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CBoard.h"
#include "CMove.h"
#include "CPlayer.h"
#include "CPlayerArtificial.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//! Game class
/*!
    Class that manages running of current game
    saves, loads or starts a new game
    and manages players.
 */
class CGame
{
private:
    CBoard m_Board; //! Instance of the board
    std::vector<CMove> m_MoveLog; //! Log containing moves
    CPlayer * m_PlayerWhite; //! White player artificial or human
    CPlayer * m_PlayerBlack; //! Black player artificial or human
    int m_WhiteType; //! White player type, 0 human, 1 2 3 AI strength
    int m_BlackType; //! Black player type, 0 human, 1 2 3 AI strength
    bool m_WhiteTurn; //! Manages whose turn it is

public:

    //! Default constructor
    CGame() = default;

    //! Starts new game
    /*!
        Starts new game, asks player for additional info
     */
    void NewGame();

    //! Loads game
    /*!
        Loads game from a file
        \param filename name of life to be loaded
        \return whether operation was successful
     */
    bool Load ( const std::string & filename );

    //! Saves game
    /*!
        Saves game from a file
        \param filename name of life to be saved to
        \return whether operation was successful
     */
    bool Save ( const std::string & filename ) const;

    //! Prints game status
    /*!
        Prints current status of game
        \param message message to be displayed
     */
    void Print ( const std::string & message ) const;

    //! Switches which player is on turn
    void SwitchTurn ();

    //! Makes move
    /*!
        Checks whether move entered is possible
        \param move move entered
        \return whether move was allowed
     */
    bool MakeMove (const std::string & move );

    //! Reads move
    /*!
        Reads entered move, either from console or AI
        \return ss containing move
     */
    std::stringstream AwaitMove ();

};
