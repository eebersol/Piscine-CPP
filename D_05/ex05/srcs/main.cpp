#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"
class Form;
class Bureaucrat;
int main(void)
{
        Bureaucrat              *b[20];
        CentralBureaucracy      cb;
        std::string     names[20] = {"Misha Antonio",
                                        "Jonell Neidert",
                                        "Cristi Guillory",
                                        "Brigid Welsh",
                                        "Veta Ottley",
                                        "Claudia Arzu",
                                        "Alix Brazan",
                                        "Lavelle Argento",
                                        "Levi Hinkle",
                                        "Junior Bhatia",
                                        "Ara Bumpus",
                                        "Beatrice Echavarria",
                                        "Demetrius Friedlander",
                                        "Pandora Hallinan",
                                        "Sammy Cromwell",
                                        "Etta Hastings",
                                        "Lizzie Vitela",
                                        "Meghann Shires",
                                        "Genna Miedema",
                                        "Henry Salvas"};
        
        std::string target[27] = {"Brooks",
                    "Rachel","Edwards",
                    "Christopher","Perez",
                    "Thomas","Baker",
                    "Sara","Moore",
                    "Chris","Bailey",
                    "Roger","Johnson",
                    "Marilyn","Thompson",
                    "Anthony","Evans",
                    "Julie","Hall",
                    "Paula","Phillips",
                    "Annie","Hernandez",
                    "Dorothy","Murphy",
                    "Alice","Howard"};
        srand(time(nullptr));
        for (int i = 0; i < 20;i++) {
                b[i] = new Bureaucrat(names[i], 1);
                cb.feed(b[i]);
        }
        for (int j =0; j < 1080;j++) {

                cb.queueUp("robotomy request", target[(rand() % 27)]);
        }
        try
        {
            std::cout << "GO DODOD" << std::endl;
            cb.doBureaucracy();
        }
        catch (Intern::InvalidFormNameException e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (OfficeBlock::IncompleteTeamException e)
        {
            std::cout << e.what() << std::endl;
        }
        return 0;
}