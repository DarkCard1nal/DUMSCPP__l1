#include "l1.h"
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	std::vector<std::string> arguments(argv, argv + argc);
	arguments.erase(arguments.begin());

	std::cout << arguments.size() << '\n';

	for (const auto &arg : arguments)
	{
		std::cout << arg << '\n';
	}

	return 0;
}
