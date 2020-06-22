//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "EColour.h"
#include "CPlayer.h"

//! Artificial playerr class
/*!
    Class that manages getting input from artificial player.
    Derived from CPlayer.
 */

class CPlayerArtificial : public CPlayer
{
private:
    int m_AI_Strength; //! Instance of the game

    //! Random AI
    /*!
        Random AI, not very smart
        \param board current state of board
        \return move to be made
     */
    std::string RandAI( const CBoard & board );

    //! Pseudo-random AI
    /*!
        Doesnt put pieces at risk and takes when possible
        \param board current state of board
        \return move to be made
     */
    std::string SemiRandAI( const CBoard & board );

    //! Minimax AI
    /*!
        AI using Minimax algorithm
        \param board current state of board
        \return move to be made
     */
    std::string Minimax_T1( const CBoard & board );

public:
    //! Awaits move
    /*!
        Virtual method that reads next move.
        If player is human, move is read from console
        \param board current state of board
        \return move to be made
     */
    virtual std::string AwaitMove( const CBoard & board );

    //! Constructor
    /*!
        Assigns colour to player and AI strength
        \param colour to be assigned
        \param str AI strength
     */
    CPlayerArtificial ( const EColour & colour, const int & str );





};