#include "Bureaucrat.hpp"

int main() {
	try {
		// Create a Bureaucrat with a valid grade
		Bureaucrat Carlota("Carlota", 75);
		std::cout << Carlota.getName() << " has grade " << Carlota.getGrade() << std::endl;

		// Try incrementing the grade
		Carlota.IncrementGrade(10); // Grade becomes 65

		// Try decrementing the grade
		Carlota.DecrementGrade(20); // Grade becomes 85

		// Test too high grade
		Bureaucrat lucas("Lucas", 0); // Should throw GradeTooHighException
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;

	try {
		// Test too low grade
		Bureaucrat xenia("Xenia", 150);
		xenia.DecrementGrade(10); // Should throw GradeTooLowException
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
