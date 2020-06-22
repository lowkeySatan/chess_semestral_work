//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <iostream>
#include "EPiece.h"
#include "EColour.h"

//! Square class
/*!
    Class that manages single square on board.
 */

class CSquare
{
private:
    EPiece m_Piece; //! Piece in square
    EColour m_PieceColour; //! Colour of piece
    EColour m_Colour; //! Colour of square

public:
    //! Constructor
    /*!
        Simple constructor, assigns respective values
        \param colour of square
        \param piece
        \param pieceColour
     */
    explicit CSquare ( EColour colour = EColour::BLANK, EPiece piece = EPiece::EMPTY, EColour pieceColour = EColour::BLANK );

    //! Piece getter
    /*!
        \return piece in square
     */
    EPiece GetPiece() const;

    //! Colour getter
    /*!
        \return colour of piece in square
     */
    EColour GetColour() const;

    friend std::ostream & operator << ( std::ostream & os, const CSquare & square );

    //! Changes square values
    /*!
        \param piece to be changed to
        \param colour to be changed to
     */
    void ChangePiece ( const EPiece & piece, const EColour & colour );
};