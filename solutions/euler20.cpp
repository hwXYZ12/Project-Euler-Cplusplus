// project euler problem 20 - euler20.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include "BigInt.h";

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "euler20out.txt";
static const char fileNameIn[] = "euler20in.txt";
static const int PROBLEM_PARAMETER_1 = 100;

int main()
{

	using std::cout;
	using std::endl;
	using std::setw;
	using std::left;
	using BIGINT::BigInt;
	using BIGINT::factorial;

	//out.open(fileNameOut);
	//in.open(fileNameIn);

	BigInt x = factorial(PROBLEM_PARAMETER_1);

	// compute the sum of the digits of x
	BigInt digit = 0, sum = 0;
	while (x > 0)
	{
		digit = x % 10;
		x = x / 10;
		sum = sum + digit;
	}

	cout << "The sum: " << sum << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

