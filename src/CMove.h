//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CBoard.h"
#include "EPiece.h"
#include "EColour.h"

#include <string>

class CMove
{
public:
    std::string m_destination;
    std::string m_origin;
    EPiece m_piece;
    EColour m_colour;

    bool Validate  ( const CBoard & board ) const;

};