/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-enzo.gouband [SSH: 10.211.55.8]
** File description:
** Command
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <iostream>
#include <functional>
#include <map>

class Command {
    public:
    class Error : public std::exception
    {
    private:
        std::string m_message;

    public:
        Error(std::string const &message) throw()
            : m_message(message) {}
        virtual ~Error() throw() {}

        const char *what() const noexcept override {return m_message.c_str();}
    };

        Command() {}
        ~Command() {}

        void registerCommand(const std::string& name, const std::function<void()>& function);
        void executeCommand(const std::string& name);

    protected:
    private:
        std::map<std::string, const std::function<void()>> m_map;
};

#endif /* !COMMAND_HPP_ */
