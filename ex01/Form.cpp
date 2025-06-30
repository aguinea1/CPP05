
#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeEx(gradeToExecute), gradeSig(gradeToSign), sign(false) {}

Form::Form() : name("Default Form"), gradeEx(50), gradeSig(100), sign(false) {}

Form::Form(const Form& other)
	: name(other.name), gradeEx(other.gradeEx), gradeSig(other.gradeSig), sign(other.sign) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->sign = other.sign;
	}
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const {return name;}
bool		Form::getIsSigned() const {return sign;}
int			Form::getGradeToSign() const{return gradeSig;}
int			Form::getGradeToExecute() const{return gradeEx;}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > gradeSig)
				throw GradeTooLowException();
	sign = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form: " << f.getName()
	   << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
	   << ", Grade to Sign: " << f.getGradeToSign()
	   << ", Grade to Execute: " << f.getGradeToExecute();
	return os;
}
