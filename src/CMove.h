//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CSquare.h"
#include "CBoard.h"

#include <string>

class CMove
{
public:
    std::string m_destination;
    std::string m_origin;
    EPiece m_piece;

    void Print ( const CInterface & interface ) const;

    bool Validate  ( const CBoard & board ) const;

};