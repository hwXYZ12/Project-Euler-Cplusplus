// project euler problem 22 - euler22.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "BigInt.h"

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "euler22out.txt";
static const char fileNameIn[] = "euler22in.txt";

int main()
{

	using std::cout;
	using std::endl;
	using std::vector;
	using std::string;
	using std::getline;

	in.open(fileNameIn);

	// read in the input
	vector<string> names;
	string x;
	while (getline(in, x, ','))
		names.push_back(x);

	// sort names
	sort(names.begin(), names.end());

	// get "alphabetical value" of each name,
	// multiply it by its sorted position, and add it
	// to the running sum
	int total = 0;
	for (int i = 0; i < names.size(); ++i)
	{
		int namesum = 0;
		for (int j = 0; j < names[i].size(); ++j)
		{
			if (isalpha(names[i][j]))
			{
				namesum += tolower(names[i][j]) - 'a' + 1;
			}
		}
		total += namesum * (i + 1);
	}

	cout << "The sum: " << total << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

