#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <string>
# include <iostream>
# include "Form.hpp"

class  PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm &operator=(PresidentialPardonForm const & rhs);
	public:
		/* Cannonique */
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm( PresidentialPardonForm const & src);
			~PresidentialPardonForm(void);
		 /* Function  */
		 	void beSigned(Bureaucrat &b);
			void action() const;

};

std::ostream & operator<<( std::ostream & o,  PresidentialPardonForm const & f);

#endif
