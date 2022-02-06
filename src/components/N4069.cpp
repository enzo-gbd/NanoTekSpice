/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-enzo.gouband [SSH: 10.211.55.8]
** File description:
** N4069
*/

#include "../../include/IComponent.hpp"

using N4069 = nts::component::primitive::N4069;

N4069::N4069()
{
    this->m_chipset.push_back(nts::component::primitive::N4069::not_gate_t{
        {1U, nts::Tristate::UNDEFINED},
        {2U, nts::Tristate::UNDEFINED}
    });
    this->m_chipset.push_back(nts::component::primitive::N4069::not_gate_t{
        {3U, nts::Tristate::UNDEFINED},
        {4U, nts::Tristate::UNDEFINED}
    });
    this->m_chipset.push_back(nts::component::primitive::N4069::not_gate_t{
        {5U, nts::Tristate::UNDEFINED},
        {6U, nts::Tristate::UNDEFINED}
    });
    this->m_chipset.push_back(nts::component::primitive::N4069::not_gate_t{
        {8U, nts::Tristate::UNDEFINED},
        {9U, nts::Tristate::UNDEFINED}
    });
    this->m_chipset.push_back(nts::component::primitive::N4069::not_gate_t{
        {10U, nts::Tristate::UNDEFINED},
        {11U, nts::Tristate::UNDEFINED}
    });
    this->m_chipset.push_back(nts::component::primitive::N4069::not_gate_t{
        {12U, nts::Tristate::UNDEFINED},
        {13U, nts::Tristate::UNDEFINED}
    });
}

N4069::~N4069()
{
}

void N4069::simulate(std::size_t tick)
{

}

nts::Tristate N4069::compute(std::size_t pin)
{
    return nts::Tristate::UNDEFINED;
}

void N4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->getPin(pin, nts::IO::OUTPUT).link = new nts::pin_t(other.getPin(otherPin, nts::IO::INPUT));
}

nts::pin_t &N4069::getPin(id_t id, IO IO_pin)
{
    if (id < 0 || id > 13 || id == 7) {
        throw Error(402, "Requested pin does not exist.", 3);
        static pin_t null;
        return null;
    }
    if (IO_pin == nts::IO::INPUT) {
        for (auto &x : this->m_chipset) {
            if (x.input.id == (unsigned int)id)
                return x.output;
        }
        throw Error(402, "Can't assign an input pin to an output pin.", 3);
    } else if (IO_pin == nts::IO::OUTPUT) {
        for (auto &x : this->m_chipset) {
            if (x.output.id == (unsigned int)id)
                return x.output;
        }
        throw Error(402, "Can't assign an input pin to an other input pin.", 3);
    }
    static pin_t null;
    return null;
}

void N4069::dump()
{
    printf("NOT:\n");
    for (auto x : this->m_chipset)
        printf("(%u, %s) ==> (%u, %s)\n",
        x.input.id, x.input.state == nts::Tristate::UNDEFINED ? "UNDEFINED" : "BOOL",
        x.output.id, x.output.state == nts::Tristate::UNDEFINED ? "UNDEFINED" : "BOOL");
    {
        pin_t pin = this->getPin(2, nts::IO::OUTPUT);
        printf("pin%u%slinked with a pin%s\n", pin.id, pin.link != nullptr ? " " : " not ", pin.link != nullptr ? std::to_string(pin.link->id).c_str() : "");
    }
    {
        pin_t pin = this->getPin(4, nts::IO::OUTPUT);
        printf("pin%u%slinked with a pin%s\n", pin.id, pin.link != nullptr ? " " : " not ", pin.link != nullptr ? std::to_string(pin.link->id).c_str() : "");
    }
    {
        pin_t pin = this->getPin(6, nts::IO::OUTPUT);
        printf("pin%u%slinked with a pin%s\n", pin.id, pin.link != nullptr ? " " : " not ", pin.link != nullptr ? std::to_string(pin.link->id).c_str() : "");
    }
    {
        pin_t pin = this->getPin(9, nts::IO::OUTPUT);
        printf("pin%u%slinked with a pin%s\n", pin.id, pin.link != nullptr ? " " : " not ", pin.link != nullptr ? std::to_string(pin.link->id).c_str() : "");
    }
    {
        pin_t pin = this->getPin(11, nts::IO::OUTPUT);
        printf("pin%u%slinked with a pin%s\n", pin.id, pin.link != nullptr ? " " : " not ", pin.link != nullptr ? std::to_string(pin.link->id).c_str() : "");
    }
    {
        pin_t pin = this->getPin(13, nts::IO::OUTPUT);
        printf("pin%u%slinked with a pin%s\n", pin.id, pin.link != nullptr ? " " : " not ", pin.link != nullptr ? std::to_string(pin.link->id).c_str() : "");
    }
}
