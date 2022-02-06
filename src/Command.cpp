/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-enzo.gouband [SSH: 10.211.55.8]
** File description:
** Command
*/

#include "../include/Command.hpp"

void Command::registerCommand(const std::string& name, const std::function<void()>& function)
{
    if (m_map.find(name) != m_map.end())
        throw Error("Already registered command");
    m_map.emplace(name, function);
}

void Command::executeCommand(const std::string& name)
{
    if (m_map.find(name) == m_map.end())
        throw Error("Unknow command");
    m_map[name]();
}