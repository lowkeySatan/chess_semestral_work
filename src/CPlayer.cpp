//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CPlayer.h"

std::string CPlayer::AwaitMove(const CBoard &board)
{
    //!Reads move from console
    std::string s;
    std::getline ( std::cin, s );
    return s;
}

CPlayer::CPlayer(const EColour &colour)
{
    m_PlayerColour = colour;
}
