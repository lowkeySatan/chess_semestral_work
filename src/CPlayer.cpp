//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CPlayer.h"

std::string CPlayer::AwaitMove(const CBoard &board)
{
    std::string s;
    std::cin >> s;
    return s;
}

CPlayer::CPlayer(const EColour &colour)
{
    m_PlayerColour = colour;
}

short CPlayer::GetStrength()
{
    return 0;
}