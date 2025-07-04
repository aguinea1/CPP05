#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat president("sami", 1); // Grado suficientemente alto
        PresidentialPardonForm pardonForm("ayOUB");

        std::cout << pardonForm << std::endl;

        // El presidente firma el formulario
        president.signForm(pardonForm);

        std::cout << pardonForm << std::endl;

        // El presidente ejecuta el formulario
        president.executeForm(pardonForm);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

