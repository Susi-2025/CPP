
#ifndef HARL_HPP
#define HARL_HPP

#include <string>

enum levels
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void unknown(void);
	public:
		void complain(std::string level);

};

#endif