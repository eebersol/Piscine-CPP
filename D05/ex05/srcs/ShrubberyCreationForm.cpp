# include "ShrubberyCreationForm.hpp"

/*ShrubberyCreation ShrubberyCreationForm (Required grades : sign 145, exec 137). Action : Create
a file called <target>_shrubbery, and write ASCII trees inside it, in the current
directory. */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137, target) {};


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

void  ShrubberyCreationForm::beSigned(Bureaucrat &b){
	if (b.get_grade() <=  get_grade())
		_signed = true;
	else
		throw  Form::GradeTooLowException();
}

void ShrubberyCreationForm::action() const{
	std::ofstream outfile (get_target());
	outfile << "      .\n   __/ \\__\n   \\     /\n   /.'o'.\\\n    .o.'.\n   .'.'o'.\n  o'.o.'.o.\n .'.o.'.'.o.\n.o.'.o.'.o.'.\n   [_____]\n    \\___/ \n";
	outfile.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	if ( this != &src ) {
		//do something
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o,  ShrubberyCreationForm const & rhs){
	o << rhs.get_name() << " must be sign by grade " << rhs.get_grade() << " and must be executed by grade " << rhs.get_exec() << (rhs.get_signed() == true ? ", is signed" : ", is not signed") << std::endl;;
	return o;
};