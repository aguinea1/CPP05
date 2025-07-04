#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << name << " bureaucrat created with grade " << grade << std::endl;
}

Bureaucrat::~Bureaucrat(){

}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::string	Bureaucrat::getName() const {
	return name;
}

int	Bureaucrat::getGrade() const {
	return grade;
}

void	Bureaucrat::DecrementGrade(int DG){
	grade += DG;
	if (DG > 150){
		grade -= DG;
		throw GradeTooLowException();
	}
	else
		std::cout << name <<" bureaucrat grade " << grade << std::endl;
}

void	Bureaucrat::IncrementGrade(int IG){
	grade -= IG;
	if (IG < 1){
		grade += IG;
		throw GradeTooLowException();
	}
	else
		std::cout << name <<" bureaucrat grade " << grade << std::endl;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName()
		          << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because: " << e.what() << std::endl;
    }
}
