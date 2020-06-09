//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CPlayerArtificial.h"

std::string CPlayerArtificial::AwaitMove(const CBoard &board)
{
    if ( this->GetStrength() == 1 ) return RandAI ( board );
    if ( this->GetStrength() == 2 ) return SemiRandAI ( board );
    if ( this->GetStrength() == 3 ) return  Minimax_T1 ( board );
    else return "fail\n";
}

CPlayerArtificial::CPlayerArtificial(const EColour &colour, const short &str)
        : CPlayer(colour)
        {
            m_AI_Strength = str;
        }

std::string CPlayerArtificial::RandAI(const CBoard &board)
{
    std::cin.get();
    return "rand\n";
}

std::string CPlayerArtificial::SemiRandAI(const CBoard &board)
{
    std::cin.get();
    return "semi\n";
}

std::string CPlayerArtificial::Minimax_T1(const CBoard &board)
{
    std::cin.get();
    return "mini\n";
}

short CPlayerArtificial::GetStrength()
{
    return m_AI_Strength;
}