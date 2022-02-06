/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-enzo.gouband [SSH: 10.211.55.8]
** File description:
** Shell
*/

#include "../include/Shell.hpp"

void Shell::next()
{
    std::string line;
    getline(*m_in, line);
    if (m_in->fail()) {
        if (m_in->eof())
            throw Error("End of input");
        throw Error("Input failed");
    }
    std::stringstream().swap(m_stream);
    m_stream << line;
}