#ifndef Form_HPP
# define Form_HPP
# include <iostream>
# include <new>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		const int			gradeEx;
		const int			gradeSig;
		bool				sign;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
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
std::ostream& operator<<(std::ostream& os, const Form& f);
#endif

