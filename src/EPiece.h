//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once


enum class EPiece : char
{
    PAWN = 'P',
    ROOK = 'R',
    KNIGHT = 'N',
    BISHOP = 'B',
    QUEEN = 'Q',
    KING = 'K',
    EMPTY = ' '
};

//std::ostream & operator << ( std::ostream & os, const EPiece & piece )