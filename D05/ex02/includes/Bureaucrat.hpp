#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const  _name;
		int _grade;
		Bureaucrat &operator=(Bureaucrat const & rhs);

	public:
		/* Canonnique */
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(Bureaucrat const & src);
			~Bureaucrat(void);
		/* GETTER */
			std::string const get_name() const;
			int  		get_grade() const;
		/* Function */
			void downgrade();
			void upgrade();
			void signForm(Form &f);
			void executeForm(Form const & form);

		class GradeTooHighException : public std::exception
		{	
			public: 
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & srcs);
				virtual ~GradeTooHighException(void) throw();
				virtual const char *what() const throw();
			private:
				GradeTooHighException &operator=(GradeTooHighException const & rhs);
		};
		class GradeTooLowException : public std::exception 
		{
			public: 
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & srcs);
				virtual ~GradeTooLowException(void) throw();
				virtual const char *what() const throw();
			private:
				GradeTooLowException &operator=(GradeTooLowException const & rhs);
		};
		class AlreadySignedException : public std::exception 
		{
			public: 
				AlreadySignedException(void);
				AlreadySignedException(AlreadySignedException const & srcs);
				virtual ~AlreadySignedException(void) throw();
				virtual const char *what() const throw();
			private:
				AlreadySignedException &operator=(AlreadySignedException const & rhs);
		};
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & f);

#endif
