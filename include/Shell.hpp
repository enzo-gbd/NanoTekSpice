/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-enzo.gouband [SSH: 10.211.55.8]
** File description:
** Shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <iostream>
#include <sstream>

class Shell
{
public:
    class Error : public std::exception
    {
    private:
        std::string m_message;

    public:
        Error(std::string const &message) throw()
            : m_message(message) {}
        virtual ~Error() throw() {}

        const char *what() const noexcept override { return m_message.c_str(); }
    };
    class Warning : public std::exception
    {
    private:
        std::string m_message;

    public:
        Warning(std::string const &message) throw()
            : m_message(message) {}
        virtual ~Warning() throw() {}

        const char *what() const noexcept override { return m_message.c_str(); }
    };
    Shell(std::istream &stream) { m_in = &stream; }
    ~Shell(){}

    void next();

    template <typename T>
    T extract()
    {
        T value;
        m_stream >> value;
        if (m_stream.fail()) {
            std::stringstream().swap(m_stream);
        }
        return value;
    }

protected:
private:
    std::istream *m_in;
    std::stringstream m_stream;
};

#endif /* !SHELL_HPP_ */