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
    CSquare ( EPiece piece = EPiece::EMPTY, EColour colour = EColour::BLANK );

    EPiece & GetPiece();

    EColour & GetColour();

    std::ostream & Print ( std::ostream & os );

};