//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CBoard.h"

void CBoard::Print() const
{
    std::cout << "        ____  ___   ____  ___   ____  ____  ____  _  _ \n"
              << "        |__|  |__]  |     |  \\  |___  |___  | __  |__| \n"
              << "        |  |  |__]  |___  |__/  |___  |     |__]  |  | \n"
              << "      ╔════════════════════════════════════════════════╗\n      ║"
              << "██████      ██████      ██████      ██████      ║ \n  /|  ║"
              << "██████      ██████      ██████      ██████      ║ \n   |  ║"
              << "██████      ██████      ██████      ██████      ║ \n  __  ║"
              << "      ██████      ██████      ██████      ██████║ \n   _) ║"
              << "      ██████      ██████      ██████      ██████║ \n  /__ ║"
              << "      ██████      ██████      ██████      ██████║ \n  __  ║"
              << "██████      ██████      ██████      ██████      ║ \n  __) ║"
              << "██████      ██████      ██████      ██████      ║ \n  __) ║"
              << "██████      ██████      ██████      ██████      ║ \n      ║"
              << "      ██████      ██████      ██████      ██████║ \n  |_| ║"
              << "      ██████      ██████      ██████      ██████║ \n    | ║"
              << "      ██████      ██████      ██████      ██████║ \n  ___ ║"
              << "██████      ██████      ██████      ██████      ║ \n  |_  ║"
              << "██████      ██████      ██████      ██████      ║ \n  __) ║"
              << "██████      ██████      ██████      ██████      ║ \n   __ ║"
              << "      ██████      ██████      ██████      ██████║ \n  |_  ║"
              << "      ██████      ██████      ██████      ██████║ \n  |_) ║"
              << "      ██████      ██████      ██████      ██████║ \n  __  ║"
              << "██████      ██████      ██████      ██████      ║ \n   /  ║"
              << "██████      ██████      ██████      ██████      ║ \n  /   ║"
              << "██████      ██████      ██████      ██████      ║ \n   _  ║"
              << "      ██████      ██████      ██████      ██████║ \n  (_) ║"
              << "      ██████      ██████      ██████      ██████║ \n  (_) ║"
              << "      ██████      ██████      ██████      ██████║ \n  "
              << "    ╚════════════════════════════════════════════════╝\n\n\n";
}

bool CBoard::CheckGameState()
{
    return true;
}

/*CBoard::CBoard()
{
    m_Board[0][0] = CSquare ( EPiece::ROOK, EColour::BLACK );
    m_Board[0][1] = CSquare ( EPiece::KNIGHT, EColour::BLACK );
    m_Board[0][2] = CSquare ( EPiece::BISHOP, EColour::BLACK );
    m_Board[0][3] = CSquare ( EPiece::QUEEN, EColour::BLACK );
    m_Board[0][4] = CSquare ( EPiece::KING, EColour::BLACK );
    m_Board[0][5] = CSquare ( EPiece::BISHOP, EColour::BLACK );
    m_Board[0][6] = CSquare ( EPiece::KNIGHT, EColour::BLACK );
    m_Board[0][7] = CSquare ( EPiece::ROOK, EColour::BLACK );

    m_Board[7][0] = CSquare ( EPiece::ROOK, EColour::WHITE );
    m_Board[7][1] = CSquare ( EPiece::KNIGHT, EColour::WHITE );
    m_Board[7][2] = CSquare ( EPiece::BISHOP, EColour::WHITE );
    m_Board[7][3] = CSquare ( EPiece::QUEEN, EColour::WHITE );
    m_Board[7][4] = CSquare ( EPiece::KING, EColour::WHITE );
    m_Board[7][5] = CSquare ( EPiece::BISHOP, EColour::WHITE );
    m_Board[7][6] = CSquare ( EPiece::KNIGHT, EColour::WHITE );
    m_Board[7][7] = CSquare ( EPiece::ROOK, EColour::WHITE );

    for (int i = 1; i < 7; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ( i == 1 )
                m_Board[i][j] = CSquare ( EPiece::PAWN, EColour::BLACK );
            else if ( i == 7 )
                m_Board[i][j] = CSquare ( EPiece::PAWN, EColour::WHITE );
            else
                m_Board[7][0] = CSquare ();
        }
    }
}*/

