//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <iostream>
#include "EPiece.h"
#include "EColour.h"


class CSquare
{
private:
    EPiece m_Piece;
    EColour m_PieceColour;
    EColour m_Colour;

public:
    explicit CSquare ( EColour colour = EColour::BLANK, EPiece piece = EPiece::EMPTY, EColour pieceColour = EColour::BLANK );

    EPiece GetPiece() const;

    EColour GetColour() const;

    friend std::ostream & operator << ( std::ostream & os, const CSquare & square );

    void ChangePiece ( const EPiece & piece, const EColour & colour );
};