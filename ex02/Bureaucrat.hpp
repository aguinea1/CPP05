#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP
# include <iostream>
# include <new>
# include <string>

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int		grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		std::string getName() const;
		int			getGrade() const;
		void		IncrementGrade(int IG);//--IG
		void		DecrementGrade(int DG);//++DG
		void		signForm(Form& form);
};
#endif
