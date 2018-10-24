#ifndef CENTRALBUREAUCRACY_H
# define CENTRALBUREAUCRACY_H

# include <string>
# include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

class Form;
class Intern;

class CentralBureaucracy
{
	private:
		OfficeBlock _blocks[20];
		std::string _formName[1080];
		std::string _targetName[1080];
		int 		_queueUpIndex;
		int 		_lastplace;

		CentralBureaucracy(CentralBureaucracy const & src);
		CentralBureaucracy &operator=(CentralBureaucracy const & rhs);
	public:
		/* Canonnique */
			CentralBureaucracy(Intern *intern, Bureaucrat *SigningBureaucrat, Bureaucrat *ExecutingBureaucrat);
			CentralBureaucracy(void);
			~CentralBureaucracy(void);
		/* Function */
			void doBureaucracy(void);
			void queueUp(std::string formName, std::string target);
			void feed(Bureaucrat *src);
		class InvalidFormNameOrTargetName : public std::exception
		{	
			public : 
				InvalidFormNameOrTargetName(void);
				InvalidFormNameOrTargetName(InvalidFormNameOrTargetName const & srcs);
				virtual ~InvalidFormNameOrTargetName(void) throw();
				virtual const char *what() const throw();
			private:
				InvalidFormNameOrTargetName &operator=(InvalidFormNameOrTargetName const & rhs);
		};
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

std::ostream & operator<<( std::ostream & o, CentralBureaucracy const & f);

#endif
