#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
	private:
    AForm* createShrubbery(const std::string& target);
    AForm* createRobotomy(const std::string& target);
    AForm* createPresidential(const std::string& target);

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

    class UnknownFormException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif

