#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
#include <fstream>  
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
		std::string const  _name;
		int const _grade;
		int const _exec;
		bool _signed;
		std::string const _target;
		Form &operator=(Form const & rhs);

	public:
		/* Cannonique */
			Form();
			Form(std::string name, int  grade, int exec, std::string target);
			Form(Form const & src);
			~Form(void);
		/* GETTER */
			std::string const 	get_name() 		const;
			std::string const 	get_target() 	const;
			int   				get_grade() 	const;
			int   				get_exec() 		const;
			bool 				get_signed() 	const;
		/* Function */
			void beSigned(Bureaucrat &b);
			virtual void execute(Bureaucrat const & executor) const;
			virtual void action() const = 0;

		class GradeTooHighException : public std::exception
		{
			public : 
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const & srcs);
				virtual ~GradeTooHighException() throw();
				virtual const char *what() const throw();
			private:
				GradeTooHighException &operator=(GradeTooHighException const & rhs);
		};
		class GradeTooLowException : public std::exception 
		{
			public : 
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const & srcs);
				virtual ~GradeTooLowException() throw();
				virtual const char *what() const throw();
			private:
				GradeTooLowException &operator=(GradeTooLowException const & rhs);
		};
		class NotSignedException : public std::exception 
		{
			public : 
				NotSignedException();
				NotSignedException(NotSignedException const & srcs);
				virtual ~NotSignedException() throw();
				virtual const char *what() const throw();
			private:
				NotSignedException &operator=(NotSignedException const & rhs);
		};
		class AlreadySignedException : public std::exception 
		{
			public : 
				AlreadySignedException();
				AlreadySignedException(AlreadySignedException const & srcs);
				virtual ~AlreadySignedException() throw();
				virtual const char *what() const throw();
			private:
				AlreadySignedException &operator=(AlreadySignedException const & rhs);
		};
};

std::ostream & operator<<( std::ostream & o, Form const & f);

#endif
