// project euler problem 7 - euler7.cpp
#include <iostream>;
#include <stack>;
#include <set>;
#include <algorithm>;

typedef long long INT;

int main()
{
	// Compute the 10001st prime number
	using std::set;

	set<INT> primes;
	primes.insert(2);
	bool isPrime = true;
	INT i = 3;
	INT last = 3;
	while (primes.size() < 10001)
	{
		for_each(primes.begin(), primes.end(),
			[&i, &isPrime](INT x)
			{
				if (i % x == 0)
					isPrime = false;
			});
		if (isPrime)
		{
			primes.insert(i);
			last = i;
		}
		i += 2;
		isPrime = true;
	}

	std::cout << "10001st prime number is: " << last;
	std::cout << std::endl;
	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}