//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CSquare.h"

EColour CSquare::GetColour() const
{
    return m_PieceColour;
}

EPiece CSquare::GetPiece() const
{
    return m_Piece;
}

CSquare::CSquare(EColour colour, EPiece piece, EColour pieceColour)
{
    m_Colour = colour;
    m_Piece = piece;
    m_PieceColour = pieceColour;
}

std::ostream & operator << ( std::ostream & os, const CSquare & square )
{
    switch ( square.m_Piece )
    {
        case EPiece::PAWN:
            os << 'p';
            break;
        case EPiece::ROOK:
            os << 'R';
            break;
        case EPiece::KNIGHT:
            os << 'N';
            break;
        case EPiece::BISHOP:
            os << 'B';
            break;
        case EPiece::QUEEN:
            os << 'Q';
            break;
        case EPiece::KING:
            os << 'K';
            break;
        case EPiece::EMPTY:
            if ( square.m_Colour == EColour::WHITE )
                return os << "██";
            else
                return os << "  ";
    }
    if ( square.m_PieceColour == EColour::WHITE )
        return os << 'w';
    else
        return os << 'b';
}

void CSquare::ChangePiece(const EPiece &piece, const EColour &colour)
{
    m_Piece = piece;
    m_PieceColour = colour;
}

