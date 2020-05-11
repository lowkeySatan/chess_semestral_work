//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CInterface.h"
#include "CBoard.h"
#include "CMove.h"

#include <iostream>
#include <string>
#include <vector>

class CGame
{
private:
    CBoard m_board;
    std::vector<CMove>;

public:
    CGame ();

    CGame & NewGame();

    void Print ( const CInterface & interface ) const;

    bool Load ( const std::string & filename );

    bool Save ( const std::string & filename ) const;

};