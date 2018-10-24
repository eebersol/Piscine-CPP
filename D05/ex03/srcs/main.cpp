#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
class Form;
class Bureaucrat;
int main(void)
{
    {
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("presidential request", "Bender");
        rrf = someRandomIntern.makeForm("dsdasdat", "Bender");
    }
}