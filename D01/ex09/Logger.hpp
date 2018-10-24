#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <ctime>
#include <fstream>

class Logger
{
	public:
		Logger(std::string filename);
		~Logger();
		void log(std::string const & dest, std::string const & message);

			
	private:
		std::string message;
		std::string filename;
		std::string makeLogEntry(std::string message);
		void logToConsole(std::string messagee);
		void logToFile(std::string messagee);
		std::string _displayTimestamp(void);

};

#endif