
#include <string>

std::string	ft_str_replace(std::string origin, std::string s1, std::string s2)
{
	size_t i = 0;
	std::string res;

	if (s1.empty())
		return origin;

	while(i < origin.length())
	{
		if (origin.compare(i, s1.length(), s1) == 0)
		{
			res += s2;
			i += s1.length();
		}
		else
		{
			res += origin[i];
			i++;
		}
	}

	return res;
}