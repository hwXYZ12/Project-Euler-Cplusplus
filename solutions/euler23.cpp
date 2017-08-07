// project euler problem 23 - euler23.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "euler23out.txt";
static const char fileNameIn[] = "euler23in.txt";

bool isAbundant(int x);
std::vector<int> properDivisors(int n);
bool isSumOfAbundantNumbers(std::vector<int> & abundantNumbers, int x);

int main()
{

	using std::cout;
	using std::endl;
	using std::vector;
	using std::string;
	using std::getline;

	// find all abundant numbers less than or equal to 28123
	vector<int> abundant;
	for (int i = 28123; i >= 2; --i)
		if (isAbundant(i))
			abundant.push_back(i);

	// find all numbers less than or equal to 28123 that can NOT
	// be written as the sum of two abundant numbers
	vector<int> notSumOfTwoAbundantNumbers;
	for (int i = 1; i <= 28123; ++i)
	{
		if (!isSumOfAbundantNumbers(abundant, i))
			notSumOfTwoAbundantNumbers.push_back(i);
	}

	// compute the sum of these numbers
	int sum = 0;
	for (int x : notSumOfTwoAbundantNumbers)
		sum += x;

	cout << "The sum: " << sum << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

std::vector<int> properDivisors(int n)
{
	using std::vector;

	vector<int> ret;
	ret.push_back(1);
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			// n is divisible by i, so
			// add i to our list of proper divisors
			ret.push_back(i);
		}
	}

	return ret;
}

bool isAbundant(int x)
{
	using std::vector;
	vector<int> v = properDivisors(x);
	int sum = 0;
	for (int i : v)
	{
		sum += i;
	}
	return (sum > x);
}

bool isSumOfAbundantNumbers(std::vector<int> & abundantNumbers, int x)
{
	for (int i : abundantNumbers)
	{
		if ((x > i) && find(abundantNumbers.begin(), abundantNumbers.end(), x - i) != abundantNumbers.end())
			return true;
	}
	return false;
}

