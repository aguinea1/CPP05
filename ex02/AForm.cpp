
#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeEx(gradeToExecute), gradeSig(gradeToSign), sign(false) {}

AForm::AForm() : name("Default Form"), gradeEx(50), gradeSig(100), sign(false) {}

AForm::AForm(const Form& other)
	: name(other.name), gradeEx(other.gradeEx), gradeSig(other.gradeSig), sign(other.sign) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->sign = other.sign;
	}
	return *this;
}

AForm::~AForm() {}

std::string	Form::getName() const {return name;}
bool		Form::getIsSigned() const {return sign;}
int			Form::getGradeToSign() const{return gradeSig;}
int			Form::getGradeToExecute() const{return gradeEx;}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > gradeSig)
				throw GradeTooLowException();
	sign = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "AForm: " << f.getName()
	   << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
	   << ", Grade to Sign: " << f.getGradeToSign()
	   << ", Grade to Execute: " << f.getGradeToExecute();
	return os;
}
