#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "OfficeBlock.hpp"
#include "Intern.hpp"
class Form;
class Bureaucrat;

int main()
{
	Intern *idiotOne = new Intern();
	Bureaucrat *hermes = new Bureaucrat("Hermes Conrad", 1);
	Bureaucrat *bob = new Bureaucrat("Bobby Bobson", 1);
	OfficeBlock ob;
	ob.setNewIntern(idiotOne);
	ob.setNewSigningBureaucrat(bob);
	ob.setNewExecutingBureaucrat(hermes);
	try
	{
		ob.doBureaucracy("presidential request", "Pigley");
	}
	catch (Intern::InvalidFormNameException & e)
	{
		 std::cout << "-" << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		 std::cout << "" << e.what() << std::endl;
	}
}