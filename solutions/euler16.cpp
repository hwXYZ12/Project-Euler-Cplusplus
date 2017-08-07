// project euler problem 16 - euler16.cpp
#include <iostream>;
#include <vector>;
#include <algorithm>;

typedef long long INT;

int main()
{

	using std::vector;
	using std::cout;
	using std::cin;
	using std::endl;

	INT sum = 0;

	// compute 2^1000 with alot of memory
	vector<int> digits;
	digits.push_back(1);
	bool carry = false;
	INT j = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		j = digits.size();
		carry = false;
		for (INT x=0; x < j; ++x)
		{
			digits[x] *= 2;
			if (carry)
			{
				++digits[x];
			}

			carry = false;
			if (digits[x] >= 10)
			{
				carry = true;
				digits[x] -= 10;
				if (x == j - 1)
				{
					digits.push_back(1);
				}
			}
		}

		// print the digits
		for (int q = digits.size() - 1; q >= 0; --q)
			cout << digits[q];
		cout << endl;
	}

	// sum the digits
	for_each(digits.begin(), digits.end(),
		[&sum](int digit)
	{
		sum += digit;
	});

	cout << "Sum of digits of 2^1000: " << sum;
	cout << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}