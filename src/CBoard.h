//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <iostream>
#include "CSquare.h"
class Cmove;

class CBoard
{
public:
    bool m_LeftCastlingW;

    bool m_RightCastlingW;

    bool m_LeftCastlingB;

    bool m_RightCastlingB;

    short m_Score;

    std::pair <int, int> m_EnPassant;

    int m_EP_Allowed;

    CSquare m_Board[8][8];

    CBoard ();

    void Print ( const bool & wTurn ) const;

    void ChangePiece ( const int & x, const int & y, const EPiece & piece, const EColour & colour );

    int CheckGameState() const;

    void ChangeScore ( const EPiece & piece, const EColour & colour );

    bool CheckCheck( const EColour & colour, const int & x, const int & y ) const;
};