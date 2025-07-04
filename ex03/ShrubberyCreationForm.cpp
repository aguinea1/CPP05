#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const {
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!this->isSigned()) {
        throw AForm::FormNotSignedException();
    }

    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream outFile((target + "_shrubbery").c_str());
	if (!outFile) {
        std::cerr << "Error: could not open file " << target + "_shrubbery" << std::endl;
        return;
    }

outFile <<
"                              &&& &&  & &&\n"
"                          && &\\/&\\|& ()|/ @, &&\n"
"                          &\\/(/&/&||/& /_/)_&/_&\n"
"                       &() &\\/&|()|/&\\/ '%\" & ()\n"
"                      &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"                    &&   && & &| &| /& & % ()& /&&\n"
"                     ()&_---()&\\&\\|&&-&&--%---()~\n"
"                        &&     \\|||\n"
"                                  |||\n"
"                                  |||\n"
"                                  |||\n"
"                            , -=-~  .-^- _\n"
"                         .-\"\"\"\"\"\"\"\"\"\"\"\"\"\"-.\n"
"                        /`-._          _.-'\\\n"
"                       /     `\"\"\"\"\"\"\"\"`     \\\n"
"                      ;                     ;\n"
"                      |    _--_   _--_      |\n"
"                      ;   /    \\ /    \\     ;\n"
"                       \\  \\o_o / \\o_o /    /\n"
"                        `\"-.__|   |__.-\"`\n"
"                             |   |\n"
"                             |   |\n"
"                             |   |\n"
"                             |   |\n"
"                             |   |\n"
"                       _____/     \\_____\n"
"                      /                  \\\n"
"                     /                    \\\n"
"                    /                      \\\n"
"                   /                        \\\n"
"                  /                          \\\n"
"                 /                            \\\n"
"                /                              \\\n"
"               /                                \\\n"
"              /                                  \\\n"
"             /                                    \\\n"
"            /                                      \\\n"
"           /                                        \\\n"
"          /                                          \\\n"
"         /                                            \\\n"
"        /                                              \\\n"
"       /                                                \\\n"
"      /                                                  \\\n"
"     /                                                    \\\n"
"    /                                                      \\\n"
"   /                                                        \\\n"
"  /                                                          \\\n"
" /                                                            \\\n"
"/______________________________________________________________\\\n"
"                         |||||||||||||||||||||\n"
"                         |||||||||||||||||||||\n"
"                         |||||||||||||||||||||\n"
"                         |||||||||||||||||||||\n"
"                         |||||||||||||||||||||\n"
"                         |||||||||||||||||||||\n"
"                         |||||||||||||||||||||\n"
"                         |||||||||||||||||||||\n";

    outFile.close();
}

