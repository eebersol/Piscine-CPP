#ifndef INTERN_H
# define INTERN_H

# include <string>
# include <iostream>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{
	private:
		Intern &operator=(Intern const & rhs);
	public:
		/* Canonnique */
			Intern();
			Intern(Intern const & src);
			~Intern(void);
		/* Function */
			Form *makeForm(std::string nameForm, std::string target);
};

std::ostream & operator<<( std::ostream & o, Intern const & f);

#endif
