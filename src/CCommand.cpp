//@author Simon Vavra <vavrasim@fit.cvut.cz>


#include "CCommand.h"

std::istream & operator >> ( std::istream & is, CCommand & command )
{
    std::string s;
    std::getline ( is, s );
    command.m_Command = s.substr( 0, s.find(' ') );
    if ( s.find(' ') < s.size() ) command.m_Param = s.substr( s.find(' ') + 1 );
    return is;
}

ECommand CCommand::Resolve()
{
    if ( m_Command == "exit" ) return ECommand::EXIT;
    if ( m_Command == "help" ) return ECommand::HELP;
    if ( m_Command == "loadgame" ) return ECommand::LOADGAME;
    if ( m_Command == "newgame" ) return ECommand::NEWGAME;
    if ( m_Command == "savegame" ) return ECommand::SAVEGAME;
    if ( m_Command.size() == 4 ) return ECommand::MOVE;
    else return ECommand::OTHER;
}


std::pair<int, std::string> CCommand::Do ( CGame & game )
{
    std::string s;
    switch ( Resolve() ) {
        case ECommand::EXIT:
            if ( !m_Param.empty() ) return std::make_pair ( 0, "exit: Parameter not allowed\n" );
            return std::make_pair ( -1, "" );

        case ECommand::HELP:
            if ( !m_Param.empty() ) return std::make_pair ( 0, "help: Parameter not allowed\n" );
            return std::make_pair ( 0, "exit                  - Exits game (All unsaved progress will be lost!)\nhelp                  - Displays help (duh)\nloadgame \"filename\"   - Loads game from .chs file\nsavegame \"filename\"   - Saves game to .chs file\nnewgame               - Starts new game, prompts for additional info\n");

        case ECommand::LOADGAME:
            if ( m_Param.empty() ) return std::make_pair ( 0, "loadgame: Missing filename\n" );
            s = "Loaded from ";
            s+= this->m_Param;
            s+= '\n';
            game.Load( m_Param );
            return std::make_pair ( 1, s );

        case ECommand::SAVEGAME:
            if ( m_Param.empty() ) return std::make_pair ( 0, "savegame: Missing filename\n" );
            s = "Successfully saved to ";
            s+= this->m_Param;
            s+= '\n';
            game.Save( m_Param );
            return std::make_pair ( 2, s );

        case ECommand::NEWGAME:
            if ( !m_Param.empty() ) return std::make_pair ( 0, "newgame: Parameter not allowed\n" );
            game.NewGame();
            return std::make_pair ( 1, "Successfully started new game\n" );

        case ECommand::MOVE:
            if ( !m_Param.empty() ) return std::make_pair ( 3, "move: Parameter not allowed\n" );
            s = "Invalid move: ";
            s += m_Command;
            s += '\n';
            return std::make_pair ( 3, s );

        case ECommand::OTHER:
            s = "Invalid command: ";
            s += m_Command;
            s += '\n';
            return std::make_pair ( 0, s );

        default:
            return std::make_pair ( 0, "Just how?\n" );

    }
}
