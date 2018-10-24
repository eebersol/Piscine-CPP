#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const  _name;
		int const _grade;
		int const _exec;
		bool _signed;
		Form &			operator=( Form const & rhs );

	public:
		Form();
		Form(std::string name, int  grade, int exec);
		Form(Form const & src);
		~Form(void);
		/* GETTER */
		std::string const get_name() const;
		int   get_grade() const;
		int   get_exec() const;
		bool  get_signed() const;
		/* Function */
		void beSigned(Bureaucrat &b);


		class GradeTooHighException : public std::exception
		{	
			public : 
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & srcs);
				virtual ~GradeTooHighException(void) throw();
				virtual const char *what() const throw();
			private:
				GradeTooHighException &operator=(GradeTooHighException const & rhs);
		};
		class GradeTooLowException : public std::exception 
		{
			public : 
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & srcs);
				virtual ~GradeTooLowException(void) throw();
				virtual const char *what() const throw();
			private:
				GradeTooLowException &operator=(GradeTooLowException const & rhs);
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
