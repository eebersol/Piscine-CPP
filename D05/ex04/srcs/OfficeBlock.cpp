# include "OfficeBlock.hpp"


OfficeBlock::OfficeBlock()
{

}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *SigningBureaucrat, Bureaucrat *ExecutingBureaucrat)
{
	setNewIntern(intern);
	setNewSigningBureaucrat(SigningBureaucrat);
	setNewExecutingBureaucrat(ExecutingBureaucrat) ;
}

OfficeBlock::OfficeBlock(OfficeBlock const &src)
{
	*this = src;
}

OfficeBlock::~OfficeBlock(void)
{

}

/* Incomplete team */
OfficeBlock::IncompleteTeamException::IncompleteTeamException(void){ return ; };
OfficeBlock::IncompleteTeamException::~IncompleteTeamException(void) throw() { return ; } ;
OfficeBlock::IncompleteTeamException::IncompleteTeamException(IncompleteTeamException const & srcs) {
	*this = srcs;
	return ;
}
const char *OfficeBlock::IncompleteTeamException::what() const throw() { return ("Incomplete team."); };
OfficeBlock::IncompleteTeamException &OfficeBlock::IncompleteTeamException::operator= (const IncompleteTeamException &rhs)
{
	(void)rhs;
	return (*this);
}


/* Setter */

void OfficeBlock::setNewIntern(Intern *intern) {
	_intern = intern;
}
void OfficeBlock::setNewSigningBureaucrat(Bureaucrat *SigningBureaucrat) {
	_SigningBureaucrat = SigningBureaucrat;
}
void OfficeBlock::setNewExecutingBureaucrat(Bureaucrat *ExecutingBureaucrat) {
	_ExecutingBureaucrat = ExecutingBureaucrat;
}
/* Its only "useful" function will be doBureaucracy, it takes a form name and a target
name. It will attempt to, in order, make the intern create the requested form, have the
second bureaucrat sign it, and have the second bureaucrat execute it. The messages
printed by the intern and bureaucrats will provide a log of what’s happening. When an
error occurs, it must result in an exception being raised from this function : You are
free to modify what you did before to make this elegant. Remember : Specific errors are
always cool. */

void OfficeBlock::doBureaucracy(std::string formName, std::string target)
{
	if (_intern == nullptr || _SigningBureaucrat == nullptr || _ExecutingBureaucrat == nullptr)
	{
		throw IncompleteTeamException();
	}
	else
	{
		Form *_form  = _intern->makeForm(formName, target);
		_SigningBureaucrat->signForm(*_form);
		_ExecutingBureaucrat->executeForm(*_form);
	}
}


OfficeBlock &		OfficeBlock::operator=( OfficeBlock const & src ) {
	if ( this != &src ) {
		//do something
	}
	return *this;
}
