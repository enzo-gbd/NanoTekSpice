/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-bsminishell2-enzo.gouband [SSH: 10.211.55.8]
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <memory>
#include "Nanotekspice.hpp"
namespace nts
{
    enum class Tristate
    {
        UNDEFINED = -1,
        TRUE = 1,
        FALSE = 0
    };

    enum class IO
    {
        INPUT = 0,
        OUTPUT = 1
    };

    struct pin_t
    {
        unsigned id;
        nts::Tristate state;
        nts::pin_t *link;
    };
    class IComponent
    {
    public:
        IComponent() = default;
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual pin_t &getPin(id_t id, IO IO_pin) = 0;
        virtual void dump() = 0;
    };
namespace component
{
namespace primitive
{
    struct gate_t
    {
        struct input_pin_pair_t
        {
            pin_t A_pin;
            pin_t B_pin;
        } typedef in_pair_t;

        in_pair_t input;
        pin_t output;
    };
    using chipset_t = std::vector<gate_t>;

    class N4071 : public nts::IComponent { // OR
    public:
        N4071();
        ~N4071();

        void simulate(std::size_t tick);
        Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
        pin_t &getPin(id_t id, IO IO_pin);
        void dump();

    protected:
    private:
        chipset_t m_chipset;
    };

    class N4001 : public nts::IComponent { // NOR
    public:
        N4001();
        ~N4001();

        void simulate(std::size_t tick);
        Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        pin_t &getPin(id_t id, IO IO_pin);
        void dump();

    protected:
    private:
        chipset_t m_chipset;
    };

    class N4030 : public nts::IComponent { // XOR
    public:
        N4030();
        ~N4030();

        void simulate(std::size_t tick);
        Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        pin_t &getPin(id_t id, IO IO_pin);
        void dump();

    protected:
    private:
        chipset_t m_chipset;
    };

    class N4081 : public nts::IComponent { // AND
    public:
        N4081();
        ~N4081();

        void simulate(std::size_t tick);
        Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        pin_t &getPin(id_t id, IO IO_pin);
        void dump();

    protected:
    private:
        chipset_t m_chipset;
    };

    class N4011 : public nts::IComponent { // NAND
    public:
        N4011();
        ~N4011();

        void simulate(std::size_t tick);
        Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        pin_t &getPin(id_t id, IO IO_pin);
        void dump();

    protected:
    private:
        chipset_t m_chipset;
    };

    class N4069 : public nts::IComponent { // NOT
        struct not_gate_t {
            pin_t input;
            pin_t output;
        };
        using chipset_t = std::vector<not_gate_t>;

    public:
        N4069();
        ~N4069();

        void simulate(std::size_t tick);
        Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        pin_t &getPin(id_t id, IO IO_pin);
        void dump();

    protected:
    private:
        chipset_t m_chipset;
    };
} //    namespace primitive
} //    namespace component
}

#endif /* !ICOMPONENT_HPP_ */
