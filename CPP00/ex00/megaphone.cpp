
#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOSE *" << std::endl;
        return 0;
    }
    for(int i = 1; i < ac; i++)
    {
        for(int j = 0; av[i][j]; j++)
            std::cout<< (char)std::toupper(av[i][j]);
        if(i < ac - 1)
            std::cout <<" ";
    }
    std::cout << std::endl;
    return 0;
}