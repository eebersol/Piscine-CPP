# include "PresidentialPardonForm.hpp"

/*• PresidentialPardonForm (Required grades : sign 25, exec 5). Action : Tells us
<target> has been pardoned by Zaphod Beeblebrox */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5, target){};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) {
	*this = src;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {};

 PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	if ( this != &src ) {
		//do something
	}
	return *this;
}

void  PresidentialPardonForm::beSigned(Bureaucrat &b) {
	if (b.get_grade() <=  get_grade())
		_signed = true;
	else
		throw  Form::GradeTooLowException();
}

void PresidentialPardonForm::action() const {
	std::cout << "Tells us " << get_target()  << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


std::ostream & operator<<(std::ostream & o,  PresidentialPardonForm const & rhs) {
	o << rhs.get_name() << " must be sign by grade " << rhs.get_grade() << " and must be executed by grade " << rhs.get_exec() << (rhs.get_signed() == true ? ", is signed" : ", is not signed") << std::endl;
	return o;
};