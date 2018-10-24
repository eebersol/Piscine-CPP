# include "Form.hpp"


Form::Form() : _name("no_name"), _grade(0), _exec(0), _signed(false), _target("no_target"){};

Form::Form(std::string name, int  grade, int exec, std::string target) : _name(name), _grade(grade), _exec(exec), _signed(false), _target(target){
	if (grade < 1 || exec < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150 || exec > 150)
		throw Bureaucrat::GradeTooLowException();

}

Form::Form(Form const &src) : _name(get_name()), _grade(get_grade()), _exec(get_exec()), _signed(get_signed()){
	*this = src;
}

Form::~Form(void) {}

/* GETTER */
std::string const  Form::get_name()   const { return _name; };
std::string const  Form::get_target() const { return _target; };
int  Form::get_grade()  const { return _grade; };
int  Form::get_exec()   const { return _exec; };
bool Form::get_signed() const { return _signed; };


/* High */
Form::GradeTooHighException::GradeTooHighException(void){ return ; };
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & srcs) {
	*this = srcs;
	return ;
}
Form::GradeTooHighException::~GradeTooHighException() throw() { return ; };
const char *Form::GradeTooHighException::what() const throw() { return ("The Grade to Hight.");};
Form::GradeTooHighException &Form::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
	(void)rhs;
	return (*this);
}

/* Low */
Form::GradeTooLowException::GradeTooLowException(void){ return ; };
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & srcs) {
	*this = srcs;
	return ;
}
Form::GradeTooLowException::~GradeTooLowException() throw() { return ; };
const char *Form::GradeTooLowException::GradeTooLowException::what() const throw() {return ("The Grade to Low.");};
Form::GradeTooLowException &Form::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
	(void)rhs;
	return (*this);
}

/* NotSigned */
Form::NotSignedException::NotSignedException(void){ return ; };
Form::NotSignedException::NotSignedException(NotSignedException const & srcs) {
	*this = srcs;
	return ;
}
Form::NotSignedException::~NotSignedException() throw() { return ; };
const char *Form::NotSignedException::what() const throw() {return ("The form is not signed.");};
Form::NotSignedException &Form::NotSignedException::operator= (const NotSignedException &rhs)
{
	(void)rhs;
	return (*this);
}

/* NotSigned */
Form::AlreadySignedException::AlreadySignedException(void){ return ; };
Form::AlreadySignedException::AlreadySignedException(AlreadySignedException const & srcs) {
	*this = srcs;
	return ;
}
Form::AlreadySignedException::~AlreadySignedException() throw() { return ; };
const char *Form::AlreadySignedException::what() const throw() {return ("The form us already signed.");};
Form::AlreadySignedException &Form::AlreadySignedException::operator= (const AlreadySignedException &rhs)
{
	(void)rhs;
	return (*this);
}

void Form::execute(Bureaucrat const & executor) const {
	if (executor.get_grade() <= get_grade() && get_signed() == true) {
		std::cout << executor.get_name() << " executes " << get_name() << std::endl;
		action();
	}
	else if (get_signed() == false)
		throw Form::NotSignedException();
	else if (get_signed() == true)
		throw Form::GradeTooLowException();
	else
		throw Form::AlreadySignedException();
}

void Form::beSigned(Bureaucrat &b) {
	if (b.get_grade() <=  get_grade())
		_signed = true;
	else if (get_signed() == true)
		throw Form::AlreadySignedException();
	else
		throw Form::GradeTooLowException();
}

Form &		Form::operator=( Form const & src ) {
	if ( this != &src ) {
		//do something
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	o << rhs.get_name() << " must be sign by grade " << rhs.get_grade() << " and must be executed by grade " << rhs.get_exec() << (rhs.get_signed() == true ? ", is signed" : " and is not signed") << std::endl;;
	return o;
};
