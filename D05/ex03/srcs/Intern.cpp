# include "Intern.hpp"


Intern::Intern()
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


Form *Intern::makeForm(std::string nameForm, std::string target)
{
	Form *form(nullptr);

	if (nameForm == "presidential request")
	{
		form = new PresidentialPardonForm(target);
	}
	else if (nameForm == "robotomy request")
	{
		form = new RobotomyRequestForm(target);
	}
	else if (nameForm == "shrubbery request")
	{
		form = new ShrubberyCreationForm(target);
	}

	if (form == nullptr)
		std::cout << "Intern can't create form for " << target << " because " << nameForm << "don't exist. " << std::endl;
	else
		std::cout << "Intern create " << nameForm << " for bureaucrat " << target << std::endl;

	return (form);

}