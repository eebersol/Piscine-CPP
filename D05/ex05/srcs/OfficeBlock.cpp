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
void OfficeBlock::setNewIntern(Intern *intern) {_intern = intern;}
void OfficeBlock::setNewSigningBureaucrat(Bureaucrat *SigningBureaucrat) {_SigningBureaucrat = SigningBureaucrat;}
void OfficeBlock::setNewExecutingBureaucrat(Bureaucrat *ExecutingBureaucrat) {_ExecutingBureaucrat = ExecutingBureaucrat;}
/* Getter */
Intern 		*OfficeBlock::getNewIntern(void) { return _intern; }
Bureaucrat  *OfficeBlock::getNewSigningBureaucrat(void) { return _SigningBureaucrat; }
Bureaucrat  *OfficeBlock::getNewExecutingBureaucrat(void) { return _ExecutingBureaucrat; }


bool OfficeBlock::completTeam(void) {
	if (_intern == nullptr || _SigningBureaucrat == nullptr || _ExecutingBureaucrat == nullptr)
		return false;
	else
		return true;
}

bool OfficeBlock::missingSigning(void) {
	return (!_SigningBureaucrat);
}
bool OfficeBlock::missingExecuting(void) {
	return (!_ExecutingBureaucrat);
}
bool OfficeBlock::missingIntern(void) {
	return (!_ExecutingBureaucrat);
}


void OfficeBlock::doBureaucracy(std::string formName, std::string target){
	if (!completTeam())
		throw IncompleteTeamException();
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
