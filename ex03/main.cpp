#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Intern someIntern;
        Bureaucrat boss("Big Boss", 1);

        AForm* shrubbery = someIntern.makeForm("shrubbery creation", "Garden");
        AForm* robotomy = someIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someIntern.makeForm("presidential pardon", "Frodo");

        std::cout << "\n--- Signing and Executing Forms ---\n" << std::endl;

        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);

        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);

        boss.signForm(*pardon);
        boss.executeForm(*pardon);

        delete shrubbery;
        delete robotomy;
        delete pardon;

        std::cout << "\n--- Invalid Form ---\n" << std::endl;
        AForm* fail = someIntern.makeForm("magic banana", "nobody");
        delete fail;  // won't reach here if exception is thrown

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

