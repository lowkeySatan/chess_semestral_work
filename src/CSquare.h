//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <iostream>
#include "EPiece.h"
#include "EColour.h"


class CSquare
{
private:
    EPiece m_piece;
    EColour m_colour;

public:
    explicit CSquare ( EPiece piece = EPiece::EMPTY, EColour colour = EColour::BLANK )
    {
        m_piece = piece;
        m_colour = colour;
    }
    EPiece GetPiece() const;

    EColour GetColour() const;

    void Print ();

};