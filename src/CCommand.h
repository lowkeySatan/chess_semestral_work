//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <string>
#include <istream>
#include <sstream>
#include "ECommand.h"
#include "CGame.h"

class CCommand
{
private:

    std::string m_Command;
    std::string m_Param;

    ECommand Resolve ();

public:

    std::pair <int, std::string> Do ( CGame & game );

    friend std::istream & operator >> ( std::istream & is, CCommand & command );

};

