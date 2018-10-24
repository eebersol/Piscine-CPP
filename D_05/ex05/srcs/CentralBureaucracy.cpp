# include "CentralBureaucracy.hpp"


CentralBureaucracy::CentralBureaucracy(void)
{
	_queueUpIndex = 0;
	 _lastplace = 0;
}

void CentralBureaucracy::queueUp(std::string formName, std::string target)
{
	if (!formName.empty() && !target.empty())
	{
		_formName[_queueUpIndex]  	= formName;
		_targetName[_queueUpIndex]  = target;
		_queueUpIndex++;
	}
	else
		throw InvalidFormNameOrTargetName();

}
void CentralBureaucracy::doBureaucracy(void)
{
	int _indexBureau = 0;
	srand(time(nullptr));


	for (int i = 0 ; i < _queueUpIndex; i++)
	{
		_indexBureau = rand () % _lastplace;
		_blocks[_indexBureau].doBureaucracy(_formName[_indexBureau], _targetName[_indexBureau]);
	}
}

void CentralBureaucracy::feed(Bureaucrat *src)
{
	if (_lastplace == 20)
	{
		std::cout << src->get_name() << " rejected cause office are full." << std::endl;
	}
	else {
		for (int i = 0; i < 20; i++)
		{
			std::cout << (_blocks[i].missingIntern() == true ? 1 : 0 )<< std::endl;
			if (_blocks[i].missingIntern())
				_blocks[i].setNewIntern(new Intern());
			if (_blocks[i].missingSigning())
				_blocks[i].setNewSigningBureaucrat(src);
			if (_blocks[i].missingExecuting())
			{
				_blocks[i].setNewExecutingBureaucrat(src);
				_lastplace++;
			}
		}
	}
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src)
{
	*this = src;
}

CentralBureaucracy::~CentralBureaucracy(void)
{

}
/* Incomplete team */
CentralBureaucracy::InvalidFormNameOrTargetName::InvalidFormNameOrTargetName(void){ return ; };
CentralBureaucracy::InvalidFormNameOrTargetName::~InvalidFormNameOrTargetName(void) throw() { return ; } ;
CentralBureaucracy::InvalidFormNameOrTargetName::InvalidFormNameOrTargetName(InvalidFormNameOrTargetName const & srcs) {
	*this = srcs;
	return ;
}
const char *CentralBureaucracy::InvalidFormNameOrTargetName::what() const throw() { return ("Invalid form name or target name."); };
CentralBureaucracy::InvalidFormNameOrTargetName &CentralBureaucracy::InvalidFormNameOrTargetName::operator= (const InvalidFormNameOrTargetName &rhs)
{
	(void)rhs;
	return (*this);
}
/* Incomplete team */
CentralBureaucracy::IncompleteTeamException::IncompleteTeamException(void){ return ; };
CentralBureaucracy::IncompleteTeamException::~IncompleteTeamException(void) throw() { return ; } ;
CentralBureaucracy::IncompleteTeamException::IncompleteTeamException(IncompleteTeamException const & srcs) {
	*this = srcs;
	return ;
}
const char *CentralBureaucracy::IncompleteTeamException::what() const throw() { return ("Incomplete team."); };
CentralBureaucracy::IncompleteTeamException &CentralBureaucracy::IncompleteTeamException::operator= (const IncompleteTeamException &rhs)
{
	(void)rhs;
	return (*this);
}

/* Its only "useful" function will be doBureaucracy, it takes a form name and a target
name. It will attempt to, in order, make the intern create the requested form, have the
second bureaucrat sign it, and have the second bureaucrat execute it. The messages
printed by the intern and bureaucrats will provide a log of what’s happening. When an
error occurs, it must result in an exception being raised from this function : You are
free to modify what you did before to make this elegant. Remember : Specific errors are
always cool. */


CentralBureaucracy &		CentralBureaucracy::operator=( CentralBureaucracy const & src ) {
	if ( this != &src ) {
		//do something
	}
	return *this;
}
