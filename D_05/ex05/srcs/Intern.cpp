# include "Intern.hpp"


Intern::Intern(void)
{

}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern(void)
{

}

Intern &		Intern::operator=( Intern const & src ) {
	if ( this != &src ) {
		//do something
	}
	return *this;
}

/* Invalid For name */
Intern::InvalidFormNameException::InvalidFormNameException(void){ return ; };
Intern::InvalidFormNameException::~InvalidFormNameException(void) throw() { return ; } ;
Intern::InvalidFormNameException::InvalidFormNameException(InvalidFormNameException const & srcs) {
	*this = srcs;
	return ;
}
const char *Intern::InvalidFormNameException::what() const throw() { return ("Invalid form name."); };
Intern::InvalidFormNameException &Intern::InvalidFormNameException::operator= (const InvalidFormNameException &rhs)
{
	(void)rhs;
	return (*this);
}

Form *Intern::makeForm(std::string nameForm, std::string target)
{
	Form *form(nullptr);

	if (nameForm == "presidential request")
		form = new PresidentialPardonForm(target);
	else if (nameForm == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (nameForm == "shrubbery request")
		form = new ShrubberyCreationForm(target);

	if (form == nullptr)
		throw InvalidFormNameException();

	return (form);

}