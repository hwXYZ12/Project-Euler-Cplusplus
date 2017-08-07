// project euler problem 24 - euler24.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "euler24out.txt";
static const char fileNameIn[] = "euler24in.txt";

int factorial(int i)
{
	int fact = 1;
	for (int c = 2; c <= i; c++)
		fact = fact * c;
	return fact;
}

int main()
{

	using std::cout;
	using std::endl;
	using std::vector;
	using std::string;
	using std::getline;

	int n = 10;
	vector<int> digits;
	for (int i = 0; i < n; ++i)
	{
		digits.push_back(i);
	}

	int target = 1000000;

	/*	The first (n - 1)! lexicographically ordered
		permutations all begin with the first digit, the next (n-1)!
		(n - 1)! lexicographically ordered
		permutations all begin with the second digit and so on.
		We want to determine the first digit of the target permutation so we must
		determine target / (n - 1)! and note that this number defines which
		digit the permutation will begin with.

		If we decrement n then we have a similar situation in order to
		determine the next digit in the permutation. I believe that this
		may be repeated until every digit of the target permutation is determined.
	*/
	// change the target to reflect what one intuitively means by targetTH place
	target -= 1;
	vector<int> answer;
	for (int x = 0; x < n; ++x)
	{
		int whichBlock = target / factorial(digits.size() - 1), nextDigit = digits[whichBlock];
		target -= whichBlock*factorial(digits.size() - 1);
		digits.erase(std::remove(digits.begin(), digits.end(), nextDigit), digits.end());
		answer.push_back(nextDigit);
	}

	cout << "Answer: ";
	for (int x : answer)
		cout << x;
	cout << endl;

	cout << target << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

