//@author Simon Vavra <vavrasim@fit.cvut.cz>

#include "CMove.h"

bool CMove::MakeMove(CBoard &board,const bool &whiteTurn)
{
    //!Decides if you can move selected piece and the calls respective method for each piece
    EPiece piece = board.m_Board[y1][x1].GetPiece();
    EColour colour = board.m_Board[y1][x1].GetColour();
    if ( colour == EColour::BLANK ) return false;
    if ( colour == EColour::BLACK && whiteTurn ) return false;
    if ( colour == EColour::WHITE && !whiteTurn ) return false;
    switch (piece)
    {
        case EPiece::PAWN:
            return this->PawnMove(board, piece, colour);
        case EPiece::ROOK:
            return this->RookMove(board, piece, colour);
        case EPiece::KNIGHT:
            return this->KnightMove(board, piece, colour);
        case EPiece::BISHOP:
            return this->BishopMove(board, piece, colour);
        case EPiece::QUEEN:
            return this->QueenMove(board, piece, colour);
        case EPiece::KING:
            return this->KingMove(board, piece, colour);
        case EPiece::EMPTY:
            return false;
    }
    return false;
}

CMove::CMove(const std::string &move)
{
    //!Parses move to usable form
    m_MoveTranscript = move;
    x1 = ( move[0] - 'a' );
    y1 = ( move[1] - '1' );
    x2 = ( move[2] - 'a' );
    y2 = ( move[3] - '1' );
}

bool CMove::PawnMove( CBoard &board, const EPiece &piece, const EColour &colour)
{
    if ( colour == EColour::WHITE ){ //!Movement differs for white and black pawns
        if (y1 - y2 == 1 || y1 - y2 == 2) {
            if (y1 - y2 == 2 && y1 != 6)
                return false;
            if (x1 == x2) {
                if (this->CheckPathVert(board)) { //!Either moves forward or captures enemy pieces
                    if (board.m_Board[y2][x2].GetPiece() == EPiece::EMPTY) {
                        board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
                        board.ChangePiece(y2, x2, piece, colour);
                        int tmp = board.CheckGameState();
                        if (tmp == -1 || tmp == 2) {//!Puts own king in check, undo move
                            board.ChangePiece(y2, x2, EPiece::EMPTY, EColour::BLANK);
                            board.ChangePiece(y1, x1, piece, colour);
                            return false;
                        }
                        if (y1 - y2 == 2) { //!Makes enpassant possible
                            board.m_EP_Allowed = 2;
                            board.m_EnPassant = std::make_pair(y1 - 1, x1);
                        }
                        if ( y2 == 0 ) //!Pawn promotion
                            board.ChangePiece(y2, x2, EPiece::QUEEN, EColour::WHITE);
                        return true;
                    }
                }
            } else {
                if (y1 - y2 == 1 && abs(x1 - x2) == 1) {//!Captures
                    if (board.m_Board[y2][x2].GetPiece() != EPiece::EMPTY && board.m_Board[y2][x2].GetColour() != colour) {
                        EPiece tmpPiece = board.m_Board[y2][x2].GetPiece();
                        EColour tmpColour = board.m_Board[y2][x2].GetColour();
                        board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
                        board.ChangePiece(y2, x2, piece, colour);
                        int tmp = board.CheckGameState();
                        if (tmp == -1 || tmp == 2) {//!Puts own king in check, undo move
                            board.ChangePiece(y2, x2, tmpPiece, tmpColour);
                            board.ChangePiece(y1, x1, piece, colour);
                            return false;
                        }
                        board.ChangeScore(tmpPiece, tmpColour);
                        if ( y2 == 0 ) //!Pawn promotion
                            board.ChangePiece(y2, x2, EPiece::QUEEN, EColour::WHITE);
                        return true;
                    }

                    if (board.m_EnPassant.first == y2 && board.m_EnPassant.second == x2 && board.m_EP_Allowed) { //!Checks for enpassant
                        board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
                        board.ChangePiece(y2, x2, piece, colour);
                        board.ChangePiece(y2 + 1, x2, EPiece::EMPTY, EColour::BLANK);
                        int tmp = board.CheckGameState();
                        if (tmp == -1 || tmp == 2) {//!Puts own king in check, undo move
                            board.ChangePiece(y2, x2, EPiece::EMPTY, EColour::BLANK);
                            board.ChangePiece(y1, x1, piece, colour);
                            board.ChangePiece(y2 + 1, x2, EPiece::PAWN, EColour::BLACK);
                            return false;
                        }
                        board.ChangeScore(EPiece::PAWN, EColour::BLACK);
                        return true;
                    }
                }
            }
        }
    }
    else{
        if ( y2 - y1 == 1 || y2 - y1 == 2 ){
            if ( y2 - y1 == 2 && y1 != 1 )
                return false;
            if ( x1 == x2 ){
                if (this->CheckPathVert(board)) {//!Either moves forward or captures enemy pieces
                    if (board.m_Board[y2][x2].GetPiece() == EPiece::EMPTY){
                        board.ChangePiece( y1, x1, EPiece::EMPTY, EColour::BLANK );
                        board.ChangePiece( y2, x2, piece, colour );
                        int tmp = board.CheckGameState();
                        if ( tmp == 1 || tmp == 2 ) {//!Puts own king in check, undo move
                            board.ChangePiece(y2, x2, EPiece::EMPTY, EColour::BLANK);
                            board.ChangePiece(y1, x1, piece, colour);
                            return false;
                        }
                        if ( y2 - y1 == 2 ) {//!Makes enpassant possible
                            board.m_EP_Allowed = 2;
                            board.m_EnPassant = std::make_pair(y1 + 1, x1);
                        }
                        if ( y2 == 7 ) //!Pawn promotion
                            board.ChangePiece(y2, x2, EPiece::QUEEN, EColour::BLACK);
                        return true;
                    }
                }
            }
            else{
                if ( y2 - y1 == 1 && abs( x1 - x2) == 1 ){//!Captures
                    if ( board.m_Board[y2][x2].GetPiece() != EPiece::EMPTY && board.m_Board[y2][x2].GetColour() != colour ){
                        EPiece tmpPiece = board.m_Board[y2][x2].GetPiece();
                        EColour tmpColour = board.m_Board[y2][x2].GetColour();
                        board.ChangePiece( y1, x1, EPiece::EMPTY, EColour::BLANK );
                        board.ChangePiece( y2, x2, piece, colour );
                        int tmp = board.CheckGameState();
                        if ( tmp == 1 || tmp == 2 ) {//!Puts own king in check, undo move
                            board.ChangePiece(y2, x2, tmpPiece, tmpColour);
                            board.ChangePiece(y1, x1, piece, colour);
                            return false;
                        }
                        board.ChangeScore ( tmpPiece, tmpColour);
                        return true;
                    }
                    if ( board.m_EnPassant.first == y2 && board.m_EnPassant.second == x2 && board.m_EP_Allowed ){//!Checks for enpassant
                        board.ChangePiece( y1, x1, EPiece::EMPTY, EColour::BLANK );
                        board.ChangePiece( y2, x2, piece, colour );
                        board.ChangePiece( y2-1, x2, EPiece::EMPTY, EColour::BLANK );
                        int tmp = board.CheckGameState();
                        if ( tmp == 1 || tmp == 2 ) {//!Puts own king in check, undo move
                            board.ChangePiece(y2, x2, EPiece::EMPTY, EColour::BLANK);
                            board.ChangePiece(y1, x1, piece, colour);
                            board.ChangePiece( y2-1, x2, EPiece::PAWN, EColour::WHITE );
                            return false;
                        }
                        board.ChangeScore ( EPiece::PAWN, EColour::WHITE);
                        if ( y2 == 7 ) //!Pawn promotion
                            board.ChangePiece(y2, x2, EPiece::QUEEN, EColour::BLACK);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool CMove::RookMove(CBoard &board, const EPiece &piece, const EColour &colour) {
    if ( (x1 == x2 && this->CheckPathHor(board)) || ( y1 == y2 && this->CheckPathVert(board)) ) //!Checks pathing
        if ( this->Take(board, piece, colour) ){ //!Captures piece at destination
            if ( x1 == 0 && y1 == 0) board.m_LeftCastlingB = false;//!Forbids respective castling
            else if ( x1 == 7 && y1 == 0) board.m_RightCastlingB = false;
            else if ( x1 == 0 && y1 == 7) board.m_LeftCastlingW = false;
            else if ( x1 == 7 && y1 == 7) board.m_RightCastlingW = false;
            return true;
        }
    return false;
}

bool CMove::KnightMove(CBoard &board, const EPiece &piece, const EColour &colour) {
    if ( (abs( x1 - x2) == 2 && abs( y1 - y2) == 1) || (abs( x1 - x2) == 1 && abs( y1 - y2) == 2) )//!Checks pathing
        if ( this->Take(board, piece, colour) )//!Captures piece at destination
            return true;
    return false;
}

bool CMove::BishopMove(CBoard &board, const EPiece &piece, const EColour &colour) {
    if ( abs(x1 - x2) == abs(y1 - y2) && this->CheckPathDiag(board) )//!Checks pathing
        if ( this->Take(board, piece, colour) )//!Captures piece at destination
            return true;
    return false;
}

bool CMove::QueenMove(CBoard &board, const EPiece &piece, const EColour &colour) {
    if ( (abs(x1 - x2) == abs(y1 - y2) && this->CheckPathDiag(board)) || (x1 == x2 && this->CheckPathVert(board)) || ( y1 == y2 && this->CheckPathHor(board)) )//!Checks pathing
        if ( this->Take(board, piece, colour) )//!Captures piece at destination
            return true;
    return false;
}

bool CMove::KingMove(CBoard &board, const EPiece &piece, const EColour &colour) {
    if ( ( abs(x1 - x2) == 1 || (abs(x1 - x2) == 0 || abs(y1 - y2) == 1 || abs(y1 - y2) == 0) ) && ( abs(x1 - x2) > 1 && abs(y1 - y2) > 1 ) && !( abs(x1 - x2) == 0 && abs(y1 - y2) == 0 ) )//!Checks pathing
        if ( this->Take(board, piece, colour) ) {//!Captures piece at destination
            if ( colour == EColour::WHITE ){//!Forbids respective castling
                board.m_RightCastlingW = false;
                board.m_LeftCastlingW = false;
            }
            else{
                board.m_RightCastlingB = false;
                board.m_LeftCastlingB = false;
            }
            return true;
        }
    if ( ( abs(x1 - x2) == 2 || abs(x1 - x2) == 3 ) && y1 == y2 ) {//!Castling
        if (this->Castling(board))
            return true;
    }
    return false;
}

bool CMove::CheckPathVert(const CBoard &board) const
{
    int a, b;
    if ( y1 > y2 )
    {
        a = y2 + 1;
        b = y1;
    }
    else
    {
        a = y1 + 1;
        b = y2;
    }
    for (int i = a; i < b; ++i)
        if ( board.m_Board[i][x1].GetPiece() != EPiece::EMPTY )
            return false;
    return true;
}

bool CMove::CheckPathHor(const CBoard &board) const
{
    int a, b;
    if ( x1 > x2 )
    {
        a = x2 + 1;
        b = x1;
    }
    else
    {
        a = x1 + 1;
        b = x2;
    }
    for (int i = a; i < b; ++i)
        if ( board.m_Board[y1][i].GetPiece() != EPiece::EMPTY )
            return false;
    return true;
}

bool CMove::CheckPathDiag(const CBoard &board) const
{
    if ( x1 > x2 && y1 > y2 )
    {
        int j = y1 - 1;
        int i = x1 - 1;
        while (j > y2 && i > x2) { //left up
            if (board.m_Board[j][i].GetPiece() != EPiece::EMPTY)
                return false;
            j--;
            i--;
        }
    }
    if ( x1 < x2 && y1 < y2 )
    {
        int j = y1 + 1;
        int i = x1 + 1;
        while (j < y2 && i < x2) { //right down
            if (board.m_Board[j][i].GetPiece() != EPiece::EMPTY)
                return false;
            j++;
            i++;
        }
    }
    if ( x1 > x2 && y1 < y2 )
    {
        int j = y1 + 1;
        int i = x1 - 1;
        while (j < y2 && i > x2) { //left down
            if (board.m_Board[j][i].GetPiece() != EPiece::EMPTY)
                return false;
            j++;
            i--;
        }
    }
    if ( x1 < x2 && y1 > y2 )
    {
        int j = y1 - 1;
        int i = x1 + 1;
        while (j > y2 && i < x2) { //left down
            if (board.m_Board[j][i].GetPiece() != EPiece::EMPTY)
                return false;
            j--;
            i++;
        }
    }
    return true;
}

bool CMove::Take( CBoard & board, const EPiece & piece, const EColour & colour )
{
    //!Captures enemy piece
    EPiece tmpPiece = board.m_Board[y2][x2].GetPiece();
    EColour tmpColour = board.m_Board[y2][x2].GetColour();
    if ( tmpColour == colour )//!Captures pieces of same colour is forbidden
        return false;
    board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
    board.ChangePiece(y2, x2, piece, colour);
    int tmp = board.CheckGameState();
    if ( ( tmp == 1 && colour == EColour::BLACK ) || ( tmp == -1 && colour == EColour::WHITE ) || tmp == 2 ) {//!Puts own king in check, undo move
        board.ChangePiece(y2, x2, tmpPiece, tmpColour);
        board.ChangePiece(y1, x1, piece, colour);
        return false;
    }
    board.ChangeScore(tmpPiece, tmpColour);
    return true;
}

bool CMove::Castling(CBoard &board) {
    if ( x2 == 6 && y2 == 0 && board.m_RightCastlingB ){//!Checks if castling is possible
        if ( board.m_Board[y1][x1+1].GetPiece() == EPiece::EMPTY && board.m_Board[y1][x2].GetPiece() == EPiece::EMPTY ){
            if (board.CheckGameState() != 1){
                board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
                board.ChangePiece(y1, x1+1, EPiece::KING, EColour::BLACK);
                if (board.CheckGameState() != 1){
                    board.ChangePiece(y1, x1+1, EPiece::EMPTY, EColour::BLANK);
                    board.ChangePiece(y1, x2, EPiece::KING, EColour::BLACK);
                    if (board.CheckGameState() != 1){
                        board.ChangePiece(y1, x1+1, EPiece::ROOK, EColour::BLACK);
                        board.ChangePiece(y1, 7, EPiece::EMPTY, EColour::BLANK);
                        return true;
                    }
                }
            }
            board.ChangePiece(y1, x1, EPiece::KING, EColour::BLACK);
            board.ChangePiece(y1, x1+1, EPiece::EMPTY, EColour::BLANK);
            board.ChangePiece(y1, x2, EPiece::EMPTY, EColour::BLANK);
        }
    }

    if ( x2 == 6 && y2 == 0 && board.m_LeftCastlingB ){
        if ( board.m_Board[y1][x1-1].GetPiece() == EPiece::EMPTY && board.m_Board[y1][x2].GetPiece() == EPiece::EMPTY ){
            if (board.CheckGameState() != 1){
                board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
                board.ChangePiece(y1, x1-1, EPiece::KING, EColour::BLACK);
                if (board.CheckGameState() != 1){
                    board.ChangePiece(y1, x1-1, EPiece::EMPTY, EColour::BLANK);
                    board.ChangePiece(y1, x2, EPiece::KING, EColour::BLACK);
                    if (board.CheckGameState() != 1){
                        board.ChangePiece(y1, x1-1, EPiece::ROOK, EColour::BLACK);
                        board.ChangePiece(y1, 0, EPiece::EMPTY, EColour::BLANK);
                        return true;
                    }
                }
            }
            board.ChangePiece(y1, x1, EPiece::KING, EColour::BLACK);
            board.ChangePiece(y1, x1-1, EPiece::EMPTY, EColour::BLANK);
            board.ChangePiece(y1, x2, EPiece::EMPTY, EColour::BLANK);
        }
    }

    if ( x2 == 6 && y2 == 7 && board.m_RightCastlingW ){
        if ( board.m_Board[y1][x1+1].GetPiece() == EPiece::EMPTY && board.m_Board[y1][x2].GetPiece() == EPiece::EMPTY ){
            if (board.CheckGameState() != -1){
                board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
                board.ChangePiece(y1, x1+1, EPiece::KING, EColour::WHITE);
                if (board.CheckGameState() != -1){
                    board.ChangePiece(y1, x1+1, EPiece::EMPTY, EColour::BLANK);
                    board.ChangePiece(y1, x2, EPiece::KING, EColour::WHITE);
                    if (board.CheckGameState() != -1){
                        board.ChangePiece(y1, x1+1, EPiece::ROOK, EColour::WHITE);
                        board.ChangePiece(y1, 7, EPiece::EMPTY, EColour::BLANK);
                        return true;
                    }
                }
            }
            board.ChangePiece(y1, x1, EPiece::KING, EColour::WHITE);
            board.ChangePiece(y1, x1+1, EPiece::EMPTY, EColour::BLANK);
            board.ChangePiece(y1, x2, EPiece::EMPTY, EColour::BLANK);
        }
    }

    if ( x2 == 2 && y2 == 7 && board.m_LeftCastlingW){
        if ( board.m_Board[y1][x1-1].GetPiece() == EPiece::EMPTY && board.m_Board[y1][x2].GetPiece() == EPiece::EMPTY ){
            if (board.CheckGameState() != -1){
                board.ChangePiece(y1, x1, EPiece::EMPTY, EColour::BLANK);
                board.ChangePiece(y1, x1-1, EPiece::KING, EColour::WHITE);
                if (board.CheckGameState() != -1){
                    board.ChangePiece(y1, x1-1, EPiece::EMPTY, EColour::BLANK);
                    board.ChangePiece(y1, x2, EPiece::KING, EColour::WHITE);
                    if (board.CheckGameState() != -1){
                        board.ChangePiece(y1, 0, EPiece::EMPTY, EColour::BLANK);
                        board.ChangePiece(y1, x1-1, EPiece::ROOK, EColour::WHITE);
                        return true;
                    }
                }
            }
            board.ChangePiece(y1, x1, EPiece::KING, EColour::WHITE);
            board.ChangePiece(y1, x1+1, EPiece::EMPTY, EColour::BLANK);
            board.ChangePiece(y1, x2, EPiece::EMPTY, EColour::BLANK);
        }
    }
    return false;
}

std::ostream & operator << ( std::ostream &os, const CMove &move ) {
    os << move.m_MoveTranscript;
    return os;
}
