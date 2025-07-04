#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

const char* Intern::UnknownFormException::what() const throw() {
    return "InternException: Unknown form requested";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formCreators[3])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    throw UnknownFormException();
}

// Métodos privados para crear cada tipo de formulario
AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

