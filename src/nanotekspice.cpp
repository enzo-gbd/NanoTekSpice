#include <iostream>
#include <memory>
#include "../include/Command.hpp"
#include "../include/Shell.hpp"
#include "../include/IComponent.hpp"

int NanoTekspice()
{
    Shell shell(std::cin);
    Command command;
    std::vector<std::unique_ptr<nts::IComponent>> components;
    components.push_back(std::unique_ptr<nts::IComponent>(new nts::component::primitive::N4071));
    components.push_back(std::unique_ptr<nts::IComponent>(new nts::component::primitive::N4001));
    components.push_back(std::unique_ptr<nts::IComponent>(new nts::component::primitive::N4030));
    components.push_back(std::unique_ptr<nts::IComponent>(new nts::component::primitive::N4081));
    components.push_back(std::unique_ptr<nts::IComponent>(new nts::component::primitive::N4011));
    components.push_back(std::unique_ptr<nts::IComponent>(new nts::component::primitive::N4069));

    command.registerCommand("exit", [](){ throw Error(1, "exit", 1); });
    command.registerCommand("dump", [&components](){
        for (const auto &x : components) {
            x->dump();
            std::cout << std::endl;
        }
    });
    command.registerCommand("simulate", [](){ std::cout << "oui je simulate\n"; });
    command.registerCommand("loop", [](){ std::cout << "oui je loop\n"; });
    command.registerCommand("display", [](){ std::cout << "oui je dump\n"; });
    while (true)
    {
        try {
            std::cout << "> " << std::flush;
            shell.next();
            command.executeCommand(shell.extract<std::string>());
        }
        catch (const Shell::Error &e) {
            std::cout << e.what() << std::endl;
            break;
        }
        catch (const Command::Error &e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        catch (const Error &e) {
            if (std::string(e.what()) != std::string("exit"))
                throw e;
            break;
        }
        catch (const std::exception &e) {
            throw e;
            continue;
        }
    }
    return 0;
}