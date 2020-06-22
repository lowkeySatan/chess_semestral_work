//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include "CBoard.h"
#include "EPiece.h"
#include "EColour.h"

#include <string>

//! Move class
/*!
    Class that manages rules of the game
 */
class CMove
{
private:
    std::string m_MoveTranscript; //! Transcript of the entered move
    int x1, y1, x2, y2; //! Coordinates of the move origin/destination
public:

    //! Constructor
    /*!
        Constructor that parses move entered
        \param move move to be parsed
     */
    explicit CMove( const std::string & move );

    //! Makes moves
    /*!
        Decides which method will be used
        \param board current state of board
        \param whiteTurn which player is on turn
        \return whether the move was allowed
     */
    bool MakeMove  ( CBoard & board, const bool & whiteTurn );

    //! Pawn move
    /*!
        Rules for pawns
        \param board current state of board
        \param piece at destination
        \param colour of piece at destination
        \return whether the move was allowed
     */
    bool PawnMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    //! Rook move
    /*!
        Rules for rooks
        \param board current state of board
        \param piece at destination
        \param colour of piece at destination
        \return whether the move was allowed
     */
    bool RookMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    //! Knight move
    /*!
        Rules for knights
        \param board current state of board
        \param piece at destination
        \param colour of piece at destination
        \return whether the move was allowed
     */
    bool KnightMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    //! Bishop move
    /*!
        Rules for bishops
        \param board current state of board
        \param piece at destination
        \param colour of piece at destination
        \return whether the move was allowed
     */
    bool BishopMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    //! Queen move
    /*!
        Rules for queens
        \param board current state of board
        \param piece at destination
        \param colour of piece at destination
        \return whether the move was allowed
     */
    bool QueenMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    //! King move
    /*!
        Rules for kings
        \param board current state of board
        \param piece at destination
        \param colour of piece at destination
        \return whether the move was allowed
     */
    bool KingMove ( CBoard & board, const EPiece & piece, const EColour & colour );

    //! Checks vertical path
    /*!
        Checks vertical path for obstacles
        \param board current state of board
        \return whether the move was allowed
     */
    bool CheckPathVert ( const CBoard & board ) const;

    //! Checks horizontal path
    /*!
        Checks horizontal path for obstacles
        \param board current state of board
        \return whether the move was allowed
     */
    bool CheckPathHor ( const CBoard & board ) const;

    //! Checks diagonal path
    /*!
        Checks diagonal path for obstacles
        \param board current state of board
        \return whether the move was allowed
     */
    bool CheckPathDiag ( const CBoard & board ) const;

    //! Captures piece
    /*!
        Captures enemy piece
        \param board current state of board
        \param piece to be captured
        \param colour of captured piece
        \return whether the move was allowed
     */
    bool Take ( CBoard & board, const EPiece & piece, const EColour & colour );

    //! Manages castling
    /*!
        Checks whether castling is possible
        \param board current state of board
     */
    bool Castling ( CBoard & board );

    friend std::ostream & operator << ( std::ostream & os, const CMove & move );




};