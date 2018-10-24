#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <string>
# include <iostream>
# include "Form.hpp"

class  ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
	public:
		/* Cannonique */
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm( ShrubberyCreationForm const & src);
			~ShrubberyCreationForm(void);
		 /* Function */
		 	void beSigned(Bureaucrat &b);
			void action() const;

};

std::ostream & operator<<( std::ostream & o,  ShrubberyCreationForm const & f);

#endif
