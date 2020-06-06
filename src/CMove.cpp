//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CMove.h"

void CMove::Print()
{
    std::cout << "Pawn on e5\n";
}

bool CMove::Validate(const CBoard &board) const
{
    return true;
}