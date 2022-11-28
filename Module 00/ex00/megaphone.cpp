#include <iostream>

int main(int ac, char **av){
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)toupper(av[i][j]);
		if (i != ac - 1)
			std::cout << ' ';
		if (i == ac - 1)
			std::cout << std::endl;
	}
	return (0);
}