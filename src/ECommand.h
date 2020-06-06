//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

enum class ECommand : int
{
    EXIT = -1,
    HELP = 0,
    NEWGAME = 1,
    LOADGAME = 2,
    SAVEGAME = 3,
    MOVE = 4,
    OTHER = 5
};