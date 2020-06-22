//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <iostream>
#include "CSquare.h"

//! Class managing board and game state
/*!
    Class that manages board and various game states
    and performs operations such as capturing pieces.
 */
class CBoard
{
public:
    bool m_LeftCastlingW;//! Determines whether castling is possible
    bool m_RightCastlingW;//! Determines whether castling is possible
    bool m_LeftCastlingB;//! Determines whether castling is possible
    bool m_RightCastlingB;//! Determines whether castling is possible
    short m_Score;//! Keeps track of score positive score is in favor of white, negative for black
    std::pair <int, int> m_EnPassant;//! Holds position of latest possible EnPassant
    int m_EP_Allowed;//! Determines whether EnPassant is allowed
    CSquare m_Board[8][8];//! Holds positions of all pieces

    //! Constructor
    /*!
        Constructs board as per standard rules.
     */
    CBoard ();

    //! Prints board
    /*!
        Prints current board state, score, which player is playing
        and current game state such as check
        \param wTurn determines which player's turn it is
     */
    void Print ( const bool & wTurn ) const;

    //! Changes piece
    /*!
        Changes piece based on parameters
        \param x horizontal position
        \param y vertical position
        \param colour colour of piece to be added
        \param piece piece which should be added
     */
    void ChangePiece ( const int & x, const int & y, const EPiece & piece, const EColour & colour );

    //! Checks game state
    /*!
        Used for determining possible moves and current game state
        \return 0 for neutral, 1 for black being in check, -1 for white, 2 for both
     */
    int CheckGameState() const;

    //! Changes score
    /*!
        Changes score according to predetermined values
        \param piece which piece was captured
        \param colour which colour was captured
     */
    void ChangeScore ( const EPiece & piece, const EColour & colour );

    //! Checks for check
    /*!
        Checks for all possible dangers for king
        \param x king's horizontal position
        \param y king's vertical position
        \param colour colour of enemy pieces
     */
    bool CheckCheck( const EColour & colour, const int & x, const int & y ) const;

    //! New board
    /*!
        Sets game board to default
     */
    void New ();
};