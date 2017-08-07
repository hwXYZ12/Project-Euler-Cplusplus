// project euler problem 4 - euler4.cpp
#include <iostream>;
#include <stack>;

typedef long long INT;

// helper method to check if a given integer
// is a palindromic number
bool isPalindrome(INT);

int main()
{
	// Compute largest palindromic number that
	// can be produced by multiplying two
	// 3 digit numbers
	
	// Brute force algorithm that finds every possible
	// 3 digit product and also keeps a tab and the largest
	// such product. Once the whole search space is purveyed
	// the largest number is printed.

	INT val = 111 * 111, temp = 0;
	for (INT i = 111; i <= 999; ++i)
	{
		for (INT j = 111; j <= 999; ++j)
		{
			temp = i*j;
			if (isPalindrome(temp) && temp >= val)
				val = temp;
		}
	}


	std::cout	<< "Largest Palindromic number achieved by multiplying two"
				<< "\n3-digit numbers: " << val;
	std::cout << std::endl;
	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

bool isPalindrome(INT n)
{
	using std::stack;
	stack<INT> s;
	// get number of digits
	INT temp = n, count = 0;
	while (temp != 0)
	{
		temp /= 10;
		++count;
	}
	if (count % 2 == 0)
	{
		for (INT i = 1; i <= count / 2; ++i)
		{
			s.push(n % 10);
			n /= 10;
		}
		for (INT i = count / 2 + 1; i <= count; ++i)
		{
			if (s.top() == n % 10)
				s.pop();
			n /= 10;
		}
	}
	else
	{
		for (INT i = 1; i <= count / 2; ++i)
		{
			s.push(n % 10);
			n /= 10;
		}
		for (INT i = count / 2 + 2; i <= count; ++i)
		{
			if (s.top() == n % 10)
				s.pop();
			n /= 10;
		}
	}

	// if you've removed all of the
	// digits that you appended then
	// the number is a palindrome
	if (s.empty())
		return true;
	return false;
}