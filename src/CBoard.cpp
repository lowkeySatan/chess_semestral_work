//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CBoard.h"

CBoard::CBoard()
{
    this->New();
}

void CBoard::New()
{
    m_LeftCastlingB = true;
    m_LeftCastlingW = true;
    m_RightCastlingB = true;
    m_RightCastlingW = true;
    m_EP_Allowed = 0;
    m_Score = 0;
    m_Board[0][0] = CSquare ( EColour::WHITE, EPiece::ROOK, EColour::BLACK );
    m_Board[0][1] = CSquare ( EColour::BLACK, EPiece::KNIGHT, EColour::BLACK );
    m_Board[0][2] = CSquare ( EColour::WHITE, EPiece::BISHOP, EColour::BLACK );
    m_Board[0][3] = CSquare ( EColour::BLACK, EPiece::QUEEN, EColour::BLACK );
    m_Board[0][4] = CSquare ( EColour::WHITE, EPiece::KING, EColour::BLACK );
    m_Board[0][5] = CSquare ( EColour::BLACK, EPiece::BISHOP, EColour::BLACK );
    m_Board[0][6] = CSquare ( EColour::WHITE, EPiece::KNIGHT, EColour::BLACK );
    m_Board[0][7] = CSquare ( EColour::BLACK, EPiece::ROOK, EColour::BLACK );
    for (int i = 0; i < 8; ++i)
    {
        if ( i%2 )
            m_Board[1][i] = CSquare ( EColour::WHITE, EPiece::PAWN, EColour::BLACK );
        else
            m_Board[1][i] = CSquare ( EColour::BLACK, EPiece::PAWN, EColour::BLACK );
    }
    m_Board[7][0] = CSquare ( EColour::BLACK, EPiece::ROOK, EColour::WHITE );
    m_Board[7][1] = CSquare ( EColour::WHITE, EPiece::KNIGHT, EColour::WHITE );
    m_Board[7][2] = CSquare ( EColour::BLACK, EPiece::BISHOP, EColour::WHITE );
    m_Board[7][3] = CSquare ( EColour::WHITE, EPiece::QUEEN, EColour::WHITE );
    m_Board[7][4] = CSquare ( EColour::BLACK, EPiece::KING, EColour::WHITE );
    m_Board[7][5] = CSquare ( EColour::WHITE, EPiece::BISHOP, EColour::WHITE );
    m_Board[7][6] = CSquare ( EColour::BLACK, EPiece::KNIGHT, EColour::WHITE );
    m_Board[7][7] = CSquare ( EColour::WHITE, EPiece::ROOK, EColour::WHITE );
    for (int i = 0; i < 8; ++i)
    {
        if ( i%2 )
            m_Board[6][i] = CSquare ( EColour::BLACK, EPiece::PAWN, EColour::WHITE );
        else
            m_Board[6][i] = CSquare ( EColour::WHITE, EPiece::PAWN, EColour::WHITE );
    }
    for (int i = 2; i < 6; ++i)
        for (int j = 0; j < 8; ++j)
        {
            if ( i%2 )
            {
                if ( j%2 )
                    m_Board[i][j] = CSquare ( EColour::WHITE, EPiece::EMPTY, EColour::BLANK );
                else
                    m_Board[i][j] = CSquare ( EColour::BLACK, EPiece::EMPTY, EColour::BLANK );
            }
            else
            {
                if ( j%2 )
                    m_Board[i][j] = CSquare ( EColour::BLACK, EPiece::EMPTY, EColour::BLANK );
                else
                    m_Board[i][j] = CSquare ( EColour::WHITE, EPiece::EMPTY, EColour::BLANK );
            }
        }
}

void CBoard::Print (const bool &wTurn) const
{
    std::cout << "\n        ____  ___   ____  ___   ____  ____  ____  _  _ \n"
              << "        |__|  |__]  |     |  \\  |___  |___  | __  |__| \n"
              << "        |  |  |__]  |___  |__/  |___  |     |__]  |  | \n"
              << "      ╔════════════════════════════════════════════════╗ Legend:\n      ║"
              << "██████      ██████      ██████      ██████      ║ Q - Queen\n  /|  ║"
              << "██" << m_Board[0][0] << "██  " << m_Board[0][1] << "  ██" << m_Board[0][2] << "██  " << m_Board[0][3] << "  ██" << m_Board[0][4] << "██  "  << m_Board[0][5] << "  ██" << m_Board[0][6] << "██  " << m_Board[0][7] << "  ║ K - King\n   |  ║"
              << "██████      ██████      ██████      ██████      ║ R - Rook\n  __  ║"
              << "      ██████      ██████      ██████      ██████║ B - Bishop\n   _) ║"
              << "  " << m_Board[1][0] << "  ██" << m_Board[1][1] << "██  " << m_Board[1][2] << "  ██" << m_Board[1][3] << "██  "  << m_Board[1][4] << "  ██" << m_Board[1][5] << "██  " << m_Board[1][6] << "  ██" << m_Board[1][7] << "██║ N - Knight\n  /__ ║"
              << "      ██████      ██████      ██████      ██████║ p - Pawn\n  __  ║"
              << "██████      ██████      ██████      ██████      ║ pw - White Pawn\n  __) ║"
              << "██" << m_Board[2][0] << "██  " << m_Board[2][1] << "  ██" << m_Board[2][2] << "██  " << m_Board[2][3] << "  ██" << m_Board[2][4] << "██  "  << m_Board[2][5] << "  ██" << m_Board[2][6] << "██  " << m_Board[2][7] << "  ║ pb - Black Pawn\n  __) ║"
              << "██████      ██████      ██████      ██████      ║ \n      ║"
              << "      ██████      ██████      ██████      ██████║ \n  |_| ║"
              << "  " << m_Board[3][0] << "  ██" << m_Board[3][1] << "██  " << m_Board[3][2] << "  ██" << m_Board[3][3] << "██  "  << m_Board[3][4] << "  ██" << m_Board[3][5] << "██  " << m_Board[3][6] << "  ██" << m_Board[3][7] << "██║ Score: " << m_Score <<"\n    | ║"
              << "      ██████      ██████      ██████      ██████║ \n  ___ ║"
              << "██████      ██████      ██████      ██████      ║ \n  |_  ║"
              << "██" << m_Board[4][0] << "██  " << m_Board[4][1] << "  ██" << m_Board[4][2] << "██  " << m_Board[4][3] << "  ██" << m_Board[4][4] << "██  "  << m_Board[4][5] << "  ██" << m_Board[4][6] << "██  " << m_Board[4][7] << "  ║ Turn: ";
                if (wTurn) std::cout << "White";
                else std::cout << "Black";
    std::cout << "\n  __) ║"
              << "██████      ██████      ██████      ██████      ║ \n   __ ║"
              << "      ██████      ██████      ██████      ██████║ \n  |_  ║"
              << "  " << m_Board[5][0] << "  ██" << m_Board[5][1] << "██  " << m_Board[5][2] << "  ██" << m_Board[5][3] << "██  "  << m_Board[5][4] << "  ██" << m_Board[5][5] << "██  " << m_Board[5][6] << "  ██" << m_Board[5][7] << "██║ GameStatus: ";
    switch ( this->CheckGameState() ) {
        case 0:
            std::cout << "Neutral";
            break;
        case 1:
            std::cout << "Black Check";
            break;
        case -1:
            std::cout << "White Check";
            break;
    }
    std::cout << "\n  |_) ║"
              << "      ██████      ██████      ██████      ██████║ \n   __ ║"
              << "██████      ██████      ██████      ██████      ║ \n    / ║"
              << "██" << m_Board[6][0] << "██  " << m_Board[6][1] << "  ██" << m_Board[6][2] << "██  " << m_Board[6][3] << "  ██" << m_Board[6][4] << "██  "  << m_Board[6][5] << "  ██" << m_Board[6][6] << "██  " << m_Board[6][7] << "  ║ \n   /  ║"
              << "██████      ██████      ██████      ██████      ║ \n   _  ║"
              << "      ██████      ██████      ██████      ██████║ \n  (_) ║"
              << "  " << m_Board[7][0] << "  ██" << m_Board[7][1] << "██  " << m_Board[7][2] << "  ██" << m_Board[7][3] << "██  "  << m_Board[7][4] << "  ██" << m_Board[7][5] << "██  " << m_Board[7][6] << "  ██" << m_Board[7][7] << "██║ \n  (_) ║"
              << "      ██████      ██████      ██████      ██████║ \n  "
              << "    ╚════════════════════════════════════════════════╝\n\n\n";
}

int CBoard::CheckGameState() const
{
    bool blackCheck = false;
    bool whiteCheck = false;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) { //!Finds both kings and decides whether they're in check
            if ( m_Board[i][j].GetPiece() == EPiece::KING ){
                if ( m_Board[i][j].GetColour() == EColour::WHITE )
                    whiteCheck = this->CheckCheck( EColour::BLACK, j, i );
                else
                    blackCheck = this->CheckCheck( EColour::WHITE, j, i );
            }
        }
    if ( whiteCheck && blackCheck ) return 2;
    if ( whiteCheck ) return -1;
    if ( blackCheck ) return 1;
    return 0;
}

void CBoard::ChangePiece(const int &x, const int &y, const EPiece &piece, const EColour &colour)
{
    m_Board[x][y].ChangePiece ( piece, colour );
}

void CBoard::ChangeScore(const EPiece &piece, const EColour &colour)
{
    switch (piece) {
        case EPiece::PAWN:
            if ( colour == EColour::WHITE )
                m_Score += -1;
            else
                m_Score += 1;
            break;
        case EPiece::ROOK:
            if ( colour == EColour::WHITE )
                m_Score += -5;
            else
                m_Score += 5;
            break;
        case EPiece::KNIGHT:
            if ( colour == EColour::WHITE )
                m_Score += -3;
            else
                m_Score += 3;
            break;
        case EPiece::BISHOP:
            if ( colour == EColour::WHITE )
                m_Score += -3;
            else
                m_Score += 3;
            break;
        case EPiece::QUEEN:
            if ( colour == EColour::WHITE )
                m_Score += -9;
            else
                m_Score += 9;
            break;
        case EPiece::KING:
            if ( colour == EColour::WHITE )
                m_Score += -999;
            else
                m_Score += 999;
            break;
        case EPiece::EMPTY:
            break;
    }
}

bool CBoard::CheckCheck(const EColour &colour, const int &x, const int &y) const {
    bool flag = false;
    EPiece piece;
    for (int i = 0; i < x; ++i) { //horizontal left
        piece = m_Board[y][i].GetPiece();
        if (piece != EPiece::EMPTY)
            flag = (piece == EPiece::ROOK || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - x) == 1)) && m_Board[y][i].GetColour() == colour;
    }
    if (flag)
        return true;
    flag = false;

    for (int i = 8; i > x; --i) { //horizontal right
        piece = m_Board[y][i].GetPiece();
        if (piece != EPiece::EMPTY)
            flag = (piece == EPiece::ROOK || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - x) == 1)) && m_Board[y][i].GetColour() == colour;
    }
    if (flag)
        return true;
    flag = false;

    for (int i = 0; i < y; ++i) { //vertical up
        piece = m_Board[i][x].GetPiece();
        if (piece != EPiece::EMPTY)
            flag = (piece == EPiece::ROOK || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - x) == 1)) && m_Board[i][x].GetColour() == colour;
    }
    if (flag)
        return true;
    flag = false;

    for (int i = 8; i > y; --i) { //vertical down
        piece = m_Board[i][x].GetPiece();
        if (piece != EPiece::EMPTY)
            flag = (piece == EPiece::ROOK || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - y) == 1)) && m_Board[i][x].GetColour() == colour;
    }
    if (flag)
        return true;
    flag = false;

    int j = y, i = x;
    while (j < 8 && i < 8) { //diagonal right down
        i++;
        j++;
        piece = m_Board[j][i].GetPiece();
        if (piece != EPiece::EMPTY) {
            if ((piece == EPiece::BISHOP || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - y) == 1) || (piece == EPiece::PAWN && colour == EColour::WHITE && i-y == 1))
            && m_Board[j][i].GetColour() == colour ){
                flag = true;
                break;
            }
            else
                break;
        }
    }
    if (flag)
        return true;
    flag = false;

    j = y;
    i = x;
    while (j < 8 && i >= 0) { //diagonal left down
        j++;
        i--;
        piece = m_Board[j][i].GetPiece();
        if (piece != EPiece::EMPTY) {
            if ((piece == EPiece::BISHOP || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - y) == 1) || (piece == EPiece::PAWN && colour == EColour::WHITE && i-y == 1))
                && m_Board[j][i].GetColour() == colour ) {
                flag = true;
                break;
            }
            else
                break;
        }
    }
    if (flag)
        return true;
    flag = false;

    j = y;
    i = x;
    while (j >= 0 && i >= 0) { //diagonal left up
        j--;
        i--;
        piece = m_Board[j][i].GetPiece();
        if (piece != EPiece::EMPTY) {
            if ((piece == EPiece::BISHOP || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - y) == 1) || (piece == EPiece::PAWN && colour == EColour::BLACK && i-y == -1))
                && m_Board[j][i].GetColour() == colour ){
                flag = true;
                break;
            }
            else
                break;
        }
    }
    if (flag)
        return true;
    flag = false;

    j = y;
    i = x;
    while (j >= 0 && i < 8) { //diagonal right up
        j--;
        i++;
        piece = m_Board[j][i].GetPiece();
        if (piece != EPiece::EMPTY) {
            if ((piece == EPiece::BISHOP || piece == EPiece::QUEEN || (piece == EPiece::KING && abs(i - y) == 1) || (piece == EPiece::PAWN && colour == EColour::BLACK && i-y == -1))
                && m_Board[j][i].GetColour() == colour ){
                flag = true;
                break;
            }
            else
                break;
        }
    }
    if (flag){
        return true;
    }

    if ( y > 1 ){//knights
        if ( x > 0 )
            if ( m_Board[y-2][x-1].GetPiece() == EPiece::KNIGHT && m_Board[y-2][x-1].GetColour() == colour )
                return true;
        if ( x < 7 )
            if ( m_Board[y-2][x+1].GetPiece() == EPiece::KNIGHT && m_Board[y-2][x+1].GetColour() == colour )
                return true;
    }

    if ( y < 6 ){
        if ( x > 0 )
            if ( m_Board[y+2][x-1].GetPiece() == EPiece::KNIGHT && m_Board[y-2][x-1].GetColour() == colour )
                return true;
        if ( x < 7 )
            if ( m_Board[y+2][x+1].GetPiece() == EPiece::KNIGHT && m_Board[y-2][x+1].GetColour() == colour )
                return true;
    }

    if ( x > 1 ){
        if ( y > 0 )
            if ( m_Board[y-1][x-2].GetPiece() == EPiece::KNIGHT && m_Board[y-1][x-2].GetColour() == colour )
                return true;
        if ( y < 7 )
            if ( m_Board[y+1][x-2].GetPiece() == EPiece::KNIGHT && m_Board[y+1][x-2].GetColour() == colour )
                return true;
    }

    if ( x < 6 ){
        if ( y > 0 )
            if ( m_Board[y-1][x+2].GetPiece() == EPiece::KNIGHT && m_Board[y-1][x+2].GetColour() == colour )
                return true;
        if ( y < 7 )
            if ( m_Board[y+1][x+2].GetPiece() == EPiece::KNIGHT && m_Board[y+1][x+2].GetColour() == colour )
                return true;
    }
    return false;
}

