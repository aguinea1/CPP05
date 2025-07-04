#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat ayoub("ayoub", 40);
        RobotomyRequestForm form("fran");
        std::cout << form << std::endl;
        ayoub.signForm(form);
        std::cout << form << std::endl;
        ayoub.executeForm(form);
        ayoub.executeForm(form);
        ayooub.executeForm(form);

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

