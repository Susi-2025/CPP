
#include <iostream>
#include <fstream>
#include <string>
#include "../includes/contents.hpp"

int main(int ac, char** av)
{
	if (ac != 4)
	{	
		std::cout << "Usage <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	//check open and read permission
	std::ifstream in_file(av[1]);
	if (!in_file)
	{
		std::cerr << "File is not exist or can't be read" << std::endl;
		return 1;
	}
	// create new file
	std::string out_file_name = av[1];
	out_file_name += ".replace";
	std::ofstream out_file(out_file_name);
	if (!out_file.is_open())
	{
		std::cerr << "Error in creating replacing file" << std::endl;
		in_file.close();
		out_file.close();
		return 1;
	}
	std::string contents;
	std::string before_contents;
	while(getline(in_file, contents))
	{
		before_contents += contents;
		if (!in_file.eof())
			before_contents += '\n';
	}
	in_file.close();
	std::string final_contents = replace_contents(before_contents, av[2], av[3]);
	out_file << final_contents;
	out_file.close();
	return 0;
}