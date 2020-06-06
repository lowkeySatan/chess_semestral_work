//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CSquare.h"

void CSquare::Print()
{
    std::cout << 'K' << 'w';
}

EColour CSquare::GetColour() const
{
    return m_colour;
}

EPiece CSquare::GetPiece() const
{
    return m_piece;
}

