#include "Logger.hpp"

Logger::Logger(std::string filename)
{
	this->filename = filename;
};

Logger::~Logger()
{
	std::cout << "In Logger destructor" << std::endl;
};

void Logger::logToConsole(std::string message)
{
	std::cout << makeLogEntry(message) << std::endl;
};

void Logger::logToFile(std::string message)
{
	std::ofstream ofs;
  	ofs.open (this->filename, std::ofstream::app);
	ofs << makeLogEntry(message);
	ofs.close();
};

std::string Logger::_displayTimestamp(void)
{
	time_t		current_time = time(NULL);
	struct tm	*local_t = localtime(&current_time);
	char		time_str[32];

	strftime(time_str, sizeof(time_str), "[%Y%m%d_%H%M%S]", local_t);
	return time_str;
};

std::string Logger::makeLogEntry(std::string message)
{
	std::string log;

	log = _displayTimestamp() + " - "  + message + "\n";
	return log;
};

void Logger::log(std::string const & dest, std::string const & message)
{

	if (!dest.empty() && !message.empty())
	{
		this->message = message;

		void (Logger::*FuncPtr[2])(std::string message) = {&Logger::logToFile, &Logger::logToConsole};
		std::string type[2] = {"file", "console"};
		dest != "console" ? (this->*FuncPtr[0])(message) : (this->*FuncPtr[1])(message);
	}
	else
		std::cout << "Invalid dest or message, please retry." << std::endl;
}

