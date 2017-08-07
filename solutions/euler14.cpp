// project euler problem 14 - euler14.cpp
#include <iostream>
#include <fstream>
#include "BigInt.h"

static std::ofstream out;
static const char fileName[] = "euler14.txt";

// compute the size of a collatz sequence beginning at
// x and ending at 1.
long long collatzSize(long long & x);

int main()
{

	using std::cout;
	using std::endl;
	using std::ofstream;
	using BIGINT::BigInt;

	// check numbers less than 1000000 for the size
	// of the collatz sequence that starts with that
	// value and find the largest such sequence
	long long max = 1, startValue = 1, temp = 0, x = 1000000;
	for (long long i = 1; i < x; i = i + 1)
	{
		temp = collatzSize(i);
		if (temp > max)
		{
			max = temp;
			startValue = i;
		}
	}

	out.open(fileName);

	cout << "Solution: " << startValue << endl;
	out << "Solution: " << startValue << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

// compute the size of a collatz sequence beginning at
// x and ending at 1.
long long collatzSize(long long & x)
{
	using BIGINT::BigInt;

	long long count = 1, val = x;
	while (val > 1)
	{
		if (val % 2 == 0)
			val = val / 2;
		else
			val = 3 * val + 1;
		count = count + 1;
	}

	return count;
}