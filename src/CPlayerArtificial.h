//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "EColour.h"
#include "CPlayer.h"

class CPlayerArtificial : public CPlayer
{
private:
    short m_AI_Strength;

    std::string RandAI( const CBoard & board );

    std::string SemiRandAI( const CBoard & board );

    std::string Minimax_T1( const CBoard & board );

    virtual short GetStrength();

public:
    virtual std::string AwaitMove( const CBoard & board );

    CPlayerArtificial ( const EColour & colour, const short & str );





};