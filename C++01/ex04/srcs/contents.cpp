
#include <string>

std::string replace_contents(std::string contents, std::string search_str, std::string replace_str)
{
	if (contents.empty())
		return contents;
	
	std::string out;
	size_t i = 0;
	
	while (i < contents.length())
	{
		if (contents.compare(i, search_str.length(), search_str) == 0)
		{
			out += replace_str;
			i += search_str.length();
		}
		else
		{
			out += contents[i];
			i++;
		}
	}
	return out;

}