#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat carlota("carlota", 50);
		Bureaucrat lucas("lucas", 140);
		Form taxForm("Tax Form", 100, 50);
		std::cout << taxForm << std::endl;
		lucas.signForm(taxForm);  // should fail (grade too low)
		carlota.signForm(taxForm);  // should succeed
		std::cout << taxForm << std::endl;
	} 
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
