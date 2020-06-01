//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CBoard.h"
#include "CMove.h"

#include <iostream>
#include <string>
#include <vector>


class CGame
{
private:
    CBoard m_board;
    std::vector<CMove> m_moveLog;

public:
    CGame ();

    void NewGame();

    bool Load ( const std::string & filename );

    bool Save ( const std::string & filename ) const;


};