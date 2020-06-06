//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <string>
#include <sstream>
#include "EColour.h"
#include "CBoard.h"


class CPlayer
{
protected:
    EColour m_PlayerColour;

    virtual short GetStrength();

public:

    CPlayer ( const EColour & colour );

    virtual std::string AwaitMove( const CBoard & board );
};