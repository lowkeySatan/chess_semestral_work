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
    m_WhiteType = std::stoi ( s );

    std::cout << "Choose black player: 0 human, 1 extremely easy AI, 2 very easy AI, 3 easy AI\n";
    std::getline ( std::cin, s );
    while ( s.size() > 1 || ( s[0] != '0' && s[0] != '1' && s[0] != '2' && s[0] != '3' ) )
    {
        std::cout << "Please enter a valid input.\n";
        std::getline ( std::cin, s );
    }
    m_BlackType = std::stoi ( s );


    if ( m_WhiteType != 0 )
        m_PlayerWhite = new CPlayerArtificial ( EColour::WHITE, m_WhiteType );
    else
        m_PlayerWhite = new CPlayer ( EColour::WHITE );
    if ( m_BlackType != 0 )
        m_PlayerBlack = new CPlayerArtificial ( EColour::BLACK, m_BlackType );
    else
        m_PlayerBlack = new CPlayer ( EColour::BLACK );

    m_WhiteTurn = true;

    m_Board.New();
}

void CGame::Print( const std::string & message ) const
{
    //!Clears console
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
    std::string tmp = "examples/";
    tmp += filename;
    std::ifstream in ( tmp );
    if ( !in.is_open() )
        return false;
    std::getline ( in, tmp );
    if ( tmp.size() == 4 )
        if ( ( tmp[0] == '0' || tmp[0] == '1' || tmp[0] == '2' || tmp[0] == '3' ) && tmp[1] == ' ' && ( tmp[2] == '0' || tmp[2] == '1' || tmp[2] == '2' || tmp[2] == '3' ) && tmp[3] == '\n' ){
            m_WhiteType = tmp[0] + '0';
            m_BlackType = tmp[2] + '0';
        }
    m_Board.New();
    m_WhiteTurn = true;
    while ( std::getline ( in, tmp ) ) //!Loads game by playing moves
    {
        if ( !this->MakeMove ( tmp ) ){
            m_Board.New();
            return false;
        }
    }

    if ( m_WhiteType != 0 )
        m_PlayerWhite = new CPlayerArtificial ( EColour::WHITE, m_WhiteType );
    else
        m_PlayerWhite = new CPlayer ( EColour::WHITE );
    if ( m_BlackType != 0 )
        m_PlayerBlack = new CPlayerArtificial ( EColour::BLACK, m_BlackType );
    else
        m_PlayerBlack = new CPlayer ( EColour::BLACK );
    return true;
}

bool CGame::Save(const std::string &filename) const
{
    std::string tmp = "examples/";
    tmp += filename;
    std::ofstream out ( tmp, std::ios::trunc );//!Deletes file content
    if ( !out.is_open() )
        return false;

    out << m_WhiteType << ' ' << m_BlackType << '\n';
    for (const auto & i : m_MoveLog) {//!Saves made moves
        out << i << '\n';
    }
    out.close();
    return true;
}

std::stringstream CGame::AwaitMove()
{
    std::stringstream ss;//!Reads player moves
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
    CMove move(moveStr); //!Makes move that was inputed
    if (move.MakeMove(m_Board, m_WhiteTurn)) {
        m_MoveLog.push_back(move);
        this->SwitchTurn();
        m_Board.m_EP_Allowed--;
        return true;
    }
    return false;
}
