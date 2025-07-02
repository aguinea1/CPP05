#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>
# include <new>
# include <string>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		const int			gradeEx;
		const int			gradeSig;
		bool				sign;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const Form& other);
		AForm& operator=(const AForm& other);
		~AForm();
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& b);
		class GradeTooHighException : public std::exception {
			public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public: const char* what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const AForm& f);
#endif

