//@author Simon Vavra <vavrasim@fit.cvut.cz>

#pragma once

#include <iostream>
#include <string>


class CInterface
{
private:
    std::istream & m_Input;
    std::ostream & m_Output;

public:
    void Print();


};