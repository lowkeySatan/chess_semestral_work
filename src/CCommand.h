//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <string>
#include <istream>
#include <sstream>
#include "ECommand.h"
#include "CGame.h"

//! Class managing commands
/*!
    Class that manages reading and resolving commands
 */

class CCommand
{
private:

    std::string m_Command; //! Command entered
    std::string m_Param; //! Parameter entered

    //! Resolves command for switch case
    /*!
        Resolves command based on enum class
     */
    ECommand Resolve ();

public:

    //! Does commands
    /*!
        Does actions based on commands entered
        \param game current instance of game
        \return return integer on how app loop changes and return message to be displayed
     */
    std::pair <int, std::string> Do ( CGame & game );

    friend std::istream & operator >> ( std::istream & is, CCommand & command );

};

