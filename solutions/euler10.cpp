// project euler problem 10 - euler10.cpp
// https://projecteuler.net/problem=10 for problem statement
#include <iostream>;
#include <stack>;
#include <set>;
#include <algorithm>;

typedef long long INT;

int main()
{
	// Sum all primes under 2 million
	using std::set;

	set<INT> primes;
	primes.insert(2);
	bool isPrime = true;
	INT i = 3;
	INT last = 3;
	while (i < 2000000)
	{
		for_each(primes.begin(), primes.upper_bound(ceil(sqrt(i))),
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

	// Compute sum
	INT sum = 0;
	for_each(primes.begin(), primes.end(),
		[&sum](INT x)
		{
			sum += x;
		});


	std::cout << "Sum of primes under 2 million: " << sum;
	std::cout << std::endl;
	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}