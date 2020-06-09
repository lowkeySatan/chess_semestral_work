//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CBoard.h"
#include "EPiece.h"
#include "EColour.h"

#include <string>

class CMove
{
private:
    std::string m_MoveTranscript;
    int x1, y1, x2, y2;
public:

    explicit CMove( const std::string & move );

    bool MakeMove  ( CBoard & board, const bool & whiteTurn );

    bool PawnMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    bool RookMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    bool KnightMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    bool BishopMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    bool QueenMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    bool KingMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    bool CheckPathVert ( const CBoard & board ) const;

    bool CheckPathHor ( const CBoard & board ) const;

    bool CheckPathDiag ( const CBoard & board ) const;

    bool Take ( CBoard & board, const EPiece & piece, const EColour & colour );

    bool Castling ( CBoard & board );




};