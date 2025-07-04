#include "AForm.hpp"

AForm::AForm()
    : name("default"), gradeEx(150), gradeSig(150), sign(false) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), gradeEx(gradeToExecute), gradeSig(gradeToSign), sign(false)
{
    if (gradeSig < 1 || gradeEx < 1)
        throw GradeTooHighException();
    if (gradeSig > 150 || gradeEx > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), gradeEx(other.gradeEx), gradeSig(other.gradeSig), sign(other.sign) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        sign = other.sign;
    }
    return *this;
}

AForm::~AForm() {}


std::string AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return sign;
}

int AForm::getGradeToSign() const {
    return gradeSig;
}

int AForm::getGradeToExecute() const {
    return gradeEx;
}


void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeSig)
        throw GradeTooLowException();
    sign = true;
}


const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName()
       << " [Sign grade: " << f.getGradeToSign()
       << ", Exec grade: " << f.getGradeToExecute()
       << ", Signed: " << (f.isSigned() ? "Yes" : "No") << "]";
    return os;
}

