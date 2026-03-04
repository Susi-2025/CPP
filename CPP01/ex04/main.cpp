
#include "main.hpp"

int main(int ac, char **av)
{
	std::string read_text, content;
	//1. check valid input
	if (ac != 4)
	{
		std::cout << "It is wrong. The correct structure is ./sed <filename> <s1> <s2> " <<std::endl;
		return 1;
	}
	//2. check open file name
	std::ifstream read_file(av[1]);
	if (!read_file)
	{
		std::cout << "File error to read" << std::endl;
		return 1;
	}
	//3. read the content
	while (getline(read_file, read_text))
	{
		content = ft_strcon(content, read_text);
		if (!read_file.eof())
			content += "\n";
	}
	//4. close read file
	read_file.close();
	//5. replace content inside the file;
	content = ft_str_replace(content, av[2], av[3]);
	//6. create new file name
	std::string new_filename = ft_strcon(av[1],".replace");

	//7. write new file
	std::ofstream new_file;
	new_file.open(new_filename.c_str());
	if (!new_file)
	{
		std::cout << "New file error to write" << std::endl;
		return 1;
	}
	//8. write content to new file
	new_file << content;
	//9. close new file
	new_file.close();
	return 0;
}
