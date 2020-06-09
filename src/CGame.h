//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CBoard.h"
#include "CMove.h"
#include "CPlayer.h"
#include "CPlayerArtificial.h"

#include <iostream>
#include <string>
#include <vector>


class CGame
{
private:
    CBoard m_Board;
    std::vector<CMove> m_MoveLog;
    CPlayer * m_PlayerWhite;
    CPlayer * m_PlayerBlack;
    bool m_WhiteTurn;

public:

    CGame() = default;

    void NewGame();

    bool Load ( const std::string & filename );

    bool Save ( const std::string & filename ) const;

    void Print ( const std::string & message ) const;

    void SwitchTurn ();

    bool MakeMove (const std::string & move );

    std::stringstream AwaitMove ();

};
