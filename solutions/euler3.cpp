// project euler problem 3 - euler3.cpp
#include <iostream>;
#include <fstream>;
#include <list>;
#include <vector>;
#include "Pair.h";

typedef long long INT;

const char * PRIMES_FILE_PATH = "primes.txt";

// Will compute the prime factorization of
// the given integer n in the form of a list of
// pairs of integers and populate a list of pairs of integers
// objects to the factorization
void getPrimeFactorization(std::list<PAIR::Pair<INT, INT>> & pf, INT n);

int main()
{

	using std::list;
	using PAIR::Pair;
	using std::cout;
	using std::cin;
	using std::endl;

	while (cin)
	{
		std::cout << "Please enter a positive integer. We will compute the prime factorization"
		"\nof this integer and display it. Enter integer <q to quit>: ";

		INT x;
		cin >> x;
		if (!cin)
			break;

		list<Pair<INT, INT>> factors;
		getPrimeFactorization(factors, x);

		// cleans up factors for display
		auto pair = factors.begin();
		while (pair != factors.end())
		{
			auto j = pair;
			j++;
			for (j; j != factors.end(); ++j)
			{
				if (pair->first() == j->first())
					pair->second() += j->second();
			}
			j = pair;
			++j;
			for (j; j != factors.end(); ++j)
			{
				if (pair->first() == j->first())
					j->second() = pair->second();
			}
			++pair;
		}
		factors.unique(
		[](Pair<INT, INT> & p1, Pair<INT, INT> & p2)
		{
			return p1.first() == p2.first();
		});

		cout << "\nPrime Factorization: ";
		for (auto pair = factors.begin(); pair != factors.end(); ++pair)
		{
			cout << pair->first() << "^" << pair->second();
			if (++pair != factors.end())
				cout << "*";
			--pair;
		}

		cout << endl << endl;
	}
	

	cin.clear();
	while (cin.get() != '\n');

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

// Will compute the prime factorization of
// the given integer n in the form of a list of
// pairs of integers and populate a list of pairs of integers
// objects to the factorization
void getPrimeFactorization(std::list<PAIR::Pair<INT, INT>> & pf, INT n)
{
	using PAIR::Pair;

	/*	We're going to do a recursive divide and conquer
		algorithm based off the idea that if n is not prime
		then there are two numbers a & b s.t. a*b = n
		which implies either a < sqrt(n) or b < sqrt(n)
		Thus in sqrt(n) time we can determine a factor
		of n and in turn we can repeat this process to
		reduce n to its simplest terms.
	*/

	// check that we aren't trying to get
	// the prime factors of 1
	if (n == 1)
		return;

	// check that n isn't divisible by 2
	if (n % 2 == 0)
	{	
		INT x = 1;
		n /= 2;
		while (n % 2 == 0)
		{
			++x;
			n /= 2;
		}
		pf.push_back(Pair<INT,INT>(2, x));
		// n should no longer be divisible by 2
		// so we can make a call to generate more
		// primes
		getPrimeFactorization(pf, n);
	}
	else
	{
		// find a number that divides n
		INT lim = ceil(sqrt(n));
		INT i = 3;
		for (i; i <= lim; i += 2)
		{
			if (n % i == 0)
			{
				// found a divisor of n
				// we want to combine the prime factorization
				// of i with the prime factorization of
				// n / i
				getPrimeFactorization(pf, i);
				n /= i;
				while (n % i == 0)
				{
					n /= i;
					getPrimeFactorization(pf, i);
				}
				// n should no longer be divisible by i
				// so we can make a call to generate more
				// primes
				getPrimeFactorization(pf, n);
				return;
			}
		}
		// in the case that we do not find anything that divides
		// n we can safely state that n is a prime number
		// thus we append a prime factor to our list of pairs
		pf.push_back(Pair<INT, INT>(n, 1));
	}

}