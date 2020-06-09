//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CGame.h"

void CGame::NewGame()
{
    std::cout << "Choose white player: 0 human, 1 extremely easy AI, 2 very easy AI, 3 easy AI\n";
    std::string s;
    std::getline ( std::cin, s );
    while ( s.size() > 1 || ( s[0] != '0' && s[0] != '1' && s[0] != '2' && s[0] != '3' ) )
    {
        std::cout << "Please enter a valid input.\n";
        std::getline ( std::cin, s );
    }
    auto option1 = (short)std::stoi ( s );

    std::cout << "Choose black player: 0 human, 1 extremely easy AI, 2 very easy AI, 3 easy AI\n";
    std::getline ( std::cin, s );
    while ( s.size() > 1 || ( s[0] != '0' && s[0] != '1' && s[0] != '2' && s[0] != '3' ) )
    {
        std::cout << "Please enter a valid input.\n";
        std::getline ( std::cin, s );
    }
    auto option2 = (short)std::stoi ( s );

    if ( option1 != 0 )
        m_PlayerWhite = new CPlayerArtificial ( EColour::WHITE, option1 );
    else
        m_PlayerWhite = new CPlayer ( EColour::WHITE );
    if ( option2 != 0 )
        m_PlayerBlack = new CPlayerArtificial ( EColour::BLACK, option2 );
    else
        m_PlayerBlack = new CPlayer ( EColour::BLACK );

    m_WhiteTurn = true;
}

void CGame::Print( const std::string & message ) const
{
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #endif
    m_Board.Print( m_WhiteTurn );
    std::cout << message;
}

bool CGame::Load(const std::string &filename)
{
    return true;
}

bool CGame::Save(const std::string &filename) const
{
    return true;
}

std::stringstream CGame::AwaitMove()
{
    std::stringstream ss;
    if ( m_WhiteTurn )
         ss.str ( m_PlayerWhite->AwaitMove ( m_Board ) );
    else
        ss.str ( m_PlayerBlack->AwaitMove ( m_Board ) );
    return ss;
}

void CGame::SwitchTurn()
{
    m_WhiteTurn = !m_WhiteTurn;
}

bool CGame::MakeMove(const std::string &moveStr)
{
    CMove move ( moveStr );
    if ( move.MakeMove( m_Board, m_WhiteTurn ) )
    {
        m_MoveLog.push_back(move);
        this->SwitchTurn();
        m_Board.m_EP_Allowed--;
        return true;
    }
    return false;
}
