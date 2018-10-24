#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <string>
# include <iostream>
# include "Form.hpp"
# include <time.h>

class  RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);
	public:
		/* Cannonique */
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm( RobotomyRequestForm const & src);
			~RobotomyRequestForm(void);
		/* Function */
			void action() const;
			void beSigned(Bureaucrat &b);

};

std::ostream & operator<<( std::ostream & o,  RobotomyRequestForm const & f);

#endif
