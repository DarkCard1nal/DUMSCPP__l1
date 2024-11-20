#include <iostream>
#include <vector>
#include <map>
#include <print>
#include <string>
#include <numeric>

#define AUTHOR "'ComandLineArgs' by Shkilnyi V. CS31"

using StringVectorMap = std::map<std::string, std::vector<std::string>>;

StringVectorMap getCountArgs(std::vector<std::string> arguments)
{
	StringVectorMap countArgs;
	std::string str, fullStr, word;
	size_t pos, tmp;

	for (auto it = arguments.begin(); it != arguments.end(); ++it)
	{
		str = *it;
		fullStr = str;
		tmp = str.rfind('.');
		if (tmp == std::string::npos)
		{
			countArgs[""].push_back(*it);
		}
		else
		{
			do
			{
				pos = tmp;
				word = fullStr.substr(pos);
				countArgs[word].push_back(*it);
				str = str.substr(0, pos);
				tmp = str.rfind('.');
			} while (tmp != std::string::npos && pos - tmp > 1);
		}
	}
	return countArgs;
}

void printMapInfo(StringVectorMap countArgs)
{
	std::println("Types of extensions: {}", countArgs.size());
	std::println("List of extensions and files:");

	for (const auto &pair : countArgs)
	{
		std::println("'{}' : {}", pair.first, pair.second.size());
		for (const auto &str : pair.second)
		{
			std::println("\t{}", str);
		}
	}
}

std::string vecArgsToStr(std::vector<std::string> arguments)
{
	return std::accumulate(arguments.begin(), arguments.end(), std::string(),
		[](const std::string &a, const std::string &b)
		{
			return a.empty() ? b : a + " " + b;
		});
}

template <typename Func, typename T>
bool test(const T &a, const T &b, int num = 0, const std::string &message = "", Func println = [](const auto &val)
	{
		std::println(val);
	})
{
	if (a != b)
	{
		std::println("Test {} Feiled! {}", num, message);
		std::println("Current: ");
		println(b);
		std::println("Actual: ");
		println(a);
		std::println();
		return false;
	}
	
	return true;
}

bool testGetCountArgs()
{
	std::println("Start testing");
	int pass = 0;
	int i, j;
	std::string result = "";
	std::vector<std::string> fileNames = {"1file1", "f_i-l/e[2]", "file 3", ""};
	std::vector<std::string> fileExtension = {".txt", ".", ""};
	std::vector<std::string> testVector;
	StringVectorMap testMap;

	for (const auto &fileName : fileNames)
	{
		for (i = 0; i < fileExtension.size(); i++)
		{
			for (j = i; j < fileExtension.size(); j++)
			{
				testVector.push_back(fileName + fileExtension[i] + fileExtension[j]);
				if (fileExtension[i] + fileExtension[j] != "..")
				{
					testMap[fileExtension[i] + fileExtension[j]].push_back(testVector.back());
				}
				if (fileExtension[j] != "")
				{
					testMap[fileExtension[j]].push_back(testVector.back());
				}
			}
		}
		if (test(getCountArgs(testVector), testMap, result.length(), 
			"Not equally! Test:\n" + vecArgsToStr(testVector), printMapInfo))
		{
			pass++;
			result += '.';
		}
		else
		{
			result += 'F';
		}
		testVector.clear();
		testMap.clear();
		std::print(".");
	}
	std::println();
	std::println("Stop testing");
	std::println("Result: {}", result);
	std::println("Passed {}/{} tests", pass, result.length());

	if (pass == result.length())
	{
		return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	std::println(AUTHOR);
	std::println("This program counts and collects file names according to their extension");
	if (argc > 1)
	{
		std::vector<std::string> arguments(argv, argv + argc);
		arguments.erase(arguments.begin());

		StringVectorMap countArgs;

		countArgs = getCountArgs(arguments);

		std::println("The number of files: {}", arguments.size());
		printMapInfo(countArgs);
	}
	else
	{
		std::println("Comand line arguments not found!");
		std::println("Example: ./l1 myfile.txt mydoc.doc yourdoc.doc otherfile.txt");

		if (testGetCountArgs())
		{
			std::println("All tests passed!");
		}
		else
		{
			std::println("Some tests failed!");
		}
	}

	return 0;
}
