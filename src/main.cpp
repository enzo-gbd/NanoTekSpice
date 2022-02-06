/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** nanotekspice
*/

#include "../include/Nanotekspice.hpp"

int main()
{
    try
    {
        NanoTekspice();
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
