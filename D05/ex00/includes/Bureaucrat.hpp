#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		std::string const  _name;
		int _grade;
		Bureaucrat &			operator=( Bureaucrat const & rhs );

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		/* GETTER */
		std::string const get_name() const;
		int  		get_grade() const;
		/* Function */
		void downgrade();
		void upgrade();

		class GradeTooHighException : public std::exception
		{	
			private :
				GradeTooHighException &operator=(GradeTooHighException const & rhs);
			public : 
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & srcs);
				virtual ~GradeTooHighException(void) throw();
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			private :
				GradeTooLowException &operator=(GradeTooLowException const & rhs);
			public : 
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & srcs);
				virtual ~GradeTooLowException(void) throw();
				virtual const char *what() const throw();
		};

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & f);

#endif
