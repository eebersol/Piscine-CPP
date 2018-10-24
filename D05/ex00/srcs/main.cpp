#include "Bureaucrat.hpp"

int main() {

	try {
		Bureaucrat bob("Bob", 151);
		std::cout << bob;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 0);
		std::cout << bob;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 150);
		std::cout << bob;
		bob.upgrade();
		std::cout << bob;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob;
		bob.downgrade();
		std::cout << bob;
		} catch (Bureaucrat::GradeTooHighException e) {
			std::cout << "GradeTooHighException";
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException e) {
			std::cout << "GradeTooLowException";
			std::cout << e.what() << std::endl;
		} catch (std::exception &e) {
			std::cout << "exception";
			std::cout << e.what() << std::endl;
		}

	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob;
		bob.upgrade();
		std::cout << bob;
	} catch (Bureaucrat::GradeTooHighException e) {
		std::cout << "GradeTooHighException";
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException e) {
		std::cout << "GradeTooLowException";
		std::cout << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception";
		std::cout << e.what() << std::endl;
	}

	return 0;
}