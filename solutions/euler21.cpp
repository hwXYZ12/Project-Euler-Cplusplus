// project euler problem 21 - euler21.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "BigInt.h";

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "euler21out.txt";
static const char fileNameIn[] = "euler21in.txt";
static const int PROBLEM_PARAMETER_1 = 10000;

int main()
{

	using std::cout;
	using std::endl;
	using std::vector;

	// populate proper divisor sums, O(n^2)
	int d[PROBLEM_PARAMETER_1] = { 0 };
	int sum = 0;
	for (int i = 1; i < PROBLEM_PARAMETER_1; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (i % j == 0)
				sum += j;
		}
		d[i] = sum;
		sum = 0;
	}

	vector<int> ret;
	// determine amicable pairs using divisor sums
	for (int i = 1; i < PROBLEM_PARAMETER_1; ++i)
	{
		for (int j = i + 1; j < PROBLEM_PARAMETER_1; ++j)
		{
			if (d[i] == j && d[j] == i)
			{
				ret.push_back(i);
				ret.push_back(j);
			}
		}
	}
	sort(ret.begin(), ret.end());
	unique(ret.begin(), ret.end());
	
	// compute sum and print
	sum = 0;
	for (int x : ret)
		sum += x;

	cout << "The sum: " << sum << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

