# include "RobotomyRequestForm.hpp"

/*RobotomyRequestForm (Required grades : sign 72, exec 45). Action : Makes some
drilling noises, and tells us that <target> has been robotomized successfully 50%
of the time. the rest of times, tells us it’s a failure.*/

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45, target) {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {
	*this = src;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {};

void  RobotomyRequestForm::beSigned(Bureaucrat &b) {
	if (b.get_grade() <=  get_grade())
		_signed = true;
	else
		throw  Form::GradeTooLowException();
}

void RobotomyRequestForm::action() const {
	std::srand(time(nullptr));
	std::cout << "Make some drilling noises and has been robotomized ";
	if ((std::rand() % 2) == 0)
		std::cout << " successfully";
	else
		std::cout << " failure";
	std::cout << std::endl;

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & src ) {
	if ( this != &src ) {
		//do something
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o,  RobotomyRequestForm const & rhs) {
	o << rhs.get_name() << " must be sign by grade " << rhs.get_grade() << " and must be executed by grade " << rhs.get_exec() << (rhs.get_signed() == true ? ", is signed" : ", is not signed")  << std::endl;;
	return o;
};