//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "EPiece.h"
#include "CMove.h"
#include "CInterface.h"

#include <array>

class CBoard
{
private:
    CSquare m_Board[8][8];

public:
    void Print ( const CInterface & interface ) const;

    bool MakeMove ( const CMove & move );

    explicit CBoard ();



};