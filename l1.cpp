#include <iostream>
#include <vector>
#include <map>
#include <print>
#include <string>

int main(int argc, char *argv[])
{
	std::vector<std::string> arguments(argv, argv + argc);
	arguments.erase(arguments.begin());

	std::map<std::string, std::vector<std::string *>> countArgs;
	std::string str, fullStr, word;
	size_t pos, tmp;

	for (auto it = arguments.begin(); it != arguments.end(); ++it)
	{
		str = *it;
		fullStr = str;
		tmp = str.rfind('.');
		if (tmp == std::string::npos)
		{
			countArgs[""].push_back(&(*it));
		}
		else
		{
			do
			{
				pos = tmp;
				word = fullStr.substr(pos);
				countArgs[word].push_back(&(*it));
				str = str.substr(0, pos);
				tmp = str.rfind('.');
			} while (tmp != std::string::npos && pos - tmp > 1);
		}
	}
	
	std::println("the number of files: {}", arguments.size());
	std::println("types of extensions: {}", countArgs.size());
	std::println("List of extensions and files:");

	for (const auto &pair : countArgs)
	{
		std::println("'{}' : {}", pair.first, pair.second.size());
		for (const auto &ptr : pair.second)
		{
			std::println("\t{}", *ptr);
		}
	}

	return 0;
}
