
#include <iostream>
#include <fstream>  

std::string 	find_occurence(std::string s1, std::string s2, std::string filetext)
{
	std::string::size_type n = 0;

	if (!s2.empty() && !s1.empty())
	{
		while ((n = filetext.find(s1,n)) != std::string::npos )
		{
			filetext.replace(n, s1.size(), s2);
			n += s2.size();
		}
		return filetext;
	}
	else
	{
		std::cout << "Error :  search or repalce invalid." << std::endl;
		exit(-1);
	}

}

std::string read_file(std::string filename)
{
	std::string final;

	std::ifstream myReadFile;
		myReadFile.open(filename);
	char output[100];
 	if (myReadFile.is_open()) 
 	{
 		while (!myReadFile.eof()) 
 		{
			myReadFile  >> output;
			std::cout << "OUTPUT : " << output << std::endl;
			final += output;
			if (!myReadFile.eof())
				final += " ";
			else
				final += "\n";
		}
		myReadFile.close();
		return final;
	}
	else
		std::cout << "Fail open" << std::endl;
	return "";
}

void create_file(std::string filename, std::string filetext)
{
	std::ofstream outfile (filename);
	outfile << filetext;
	outfile.close();
}

int main(int ac, char**av)
{
	std::string filetext;
	std::string filename;

	if (ac !=  4)
		std::cout << "Invalide argument number : ./replace [FILENAME] [S1] [S2]" << std::endl;
	else
	{
		filename = av[1];
		if (!filename.empty())
		{
			filetext = read_file(av[1]);
			if (!filetext.empty())
			{
				filetext = find_occurence(av[2], av[3], filetext);
				create_file(filename + ".replace", filetext);
			}
			else
				std::cout << "Error : invalid filetext." << std::endl;
		}
		else
			std::cout << "Error : invalid filename." << std::endl;
	}

}