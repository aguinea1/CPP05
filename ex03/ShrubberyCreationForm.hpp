#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

public:
    // Constructor
    ShrubberyCreationForm(const std::string& target);
    
    // Copia y asignación
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    // Destructor
    ~ShrubberyCreationForm();

    // Getter
    const std::string& getTarget() const;

    // Método de ejecución
    void execute(Bureaucrat const & executor) const;
};

#endif

