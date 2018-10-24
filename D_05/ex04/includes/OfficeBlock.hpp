#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

# include <string>
# include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

class Form;
class Intern;
class Bureaucrat;

class OfficeBlock
{
	private:
		OfficeBlock(OfficeBlock const & src);
		Intern *_intern;
		Bureaucrat *_SigningBureaucrat;
		Bureaucrat *_ExecutingBureaucrat;
		OfficeBlock &operator=(OfficeBlock const & rhs);
	public:
		/* Canonnique */
			OfficeBlock(Intern *intern, Bureaucrat *SigningBureaucrat, Bureaucrat *ExecutingBureaucrat);
			OfficeBlock(void);
			~OfficeBlock(void);
		/* Settter */
			void setNewIntern(Intern *intern);
			void setNewSigningBureaucrat(Bureaucrat *SigningBureaucrat);
			void setNewExecutingBureaucrat(Bureaucrat *ExecutingBureaucrat);	
		/* Function */
			void doBureaucracy(std::string formName, std::string target);

		class IncompleteTeamException : public std::exception
		{	
			public : 
				IncompleteTeamException(void);
				IncompleteTeamException(IncompleteTeamException const & srcs);
				virtual ~IncompleteTeamException(void) throw();
				virtual const char *what() const throw();
			private:
				IncompleteTeamException &operator=(IncompleteTeamException const & rhs);
		};
};

std::ostream & operator<<( std::ostream & o, OfficeBlock const & f);

#endif
