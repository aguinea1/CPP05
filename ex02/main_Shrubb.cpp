#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat carlota("carlota", 100);

        ShrubberyCreationForm shrubberyForm("xenia");

        std::cout << "Intentando firmar el formulario..." << std::endl;
        carlota.signForm(shrubberyForm);

        std::cout << "Intentando ejecutar el formulario..." << std::endl;
        carlota.executeForm(shrubberyForm);

        std::cout << "Formulario ejecutado con éxito. Revisa el archivo 'xenia_shrubbery'.\n";

    } catch (std::exception& e) {
        std::cerr << "Se produjo una excepción: " << e.what() << std::endl;
    }

    return 0;
}

