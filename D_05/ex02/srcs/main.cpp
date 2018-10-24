#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Form;
class Bureaucrat;
int main(void)
{
    PresidentialPardonForm      p("bob");
    RobotomyRequestForm         r("alice");
    ShrubberyCreationForm       s("alice");
    Bureaucrat bob("Bob", 150);
    Bureaucrat alice("Alice", 1);
    std::cout << p;
    std::cout << r;
    std::cout << s;
    std::cout << bob;
    std::cout << alice;
    try {
        alice.signForm(p);
    } catch (Form::AlreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }
    try {
        bob.signForm(p);
    } catch (Form::AlreadySignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    }

    try {
        alice.signForm(p);
    } catch (Form::AlreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }
    try {
        alice.signForm(r);
    } catch (Form::AlreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }
    try {
        alice.signForm(s);
    } catch (Form::AlreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }
    try {
        p.execute(bob);
    } catch (Form::AlreadySignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "BOB -> " << e.what() << std::endl;
    }
    try {
        p.execute(alice);
    } catch (Form::AlreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }
     try {
        r.execute(alice);
    } catch (Form::AlreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }
     try {
        s.execute(alice);
    } catch (Form::AlreadySignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (Form::NotSignedException e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ALICE -> " << e.what() << std::endl;
    }
    std::cout << p;
    std::cout << r;
    std::cout << s;
    return 0;
}