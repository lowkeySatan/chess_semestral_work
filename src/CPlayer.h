//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <string>
#include <sstream>
#include "EColour.h"
#include "CBoard.h"

//! Player class
/*!
    Class that manages getting input from user.
    Base class for CPlayerArtificial.
 */
class CPlayer
{
protected:
    EColour m_PlayerColour; //! Colour of player

public:

    //! Constructor
    /*!
        Assigns colour to player
        \param colour to be assigned
     */
    explicit CPlayer ( const EColour & colour );

    //! Awaits move
    /*!
        Virtual method that reads next move.
        If player is human, move is read from console
        \param board current state of board
        \return move to be made
     */
    virtual std::string AwaitMove( const CBoard & board );
};