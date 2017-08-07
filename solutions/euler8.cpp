// project euler problem 8 - euler8.cpp
// https://projecteuler.net/problem=8 for problem statement
#include <iostream>;
#include <fstream>;
#include <deque>;
#include <algorithm>;

typedef long long INT;
const char * INPUT_PATH = "euler8input.txt";


int main()
{
	using std::ifstream;
	using std::deque;

	// get text file containing numbers
	ifstream in;
	in.open(INPUT_PATH);

	/*	parse the values and compute
		the product of 13 consecutive
		values using a deque
	*/
	deque<INT> numbers;
	INT maxProd = 1;

	// init the deque
	INT temp = 0, temp2 = 1;
	char c;
	for (int i = 1; i <= 13; ++i)
	{
		in >> c;
		temp = c - '0';
		numbers.push_back(temp);
	}
	for_each(numbers.begin(), numbers.end(),
	[&temp2](INT x)
	{
		temp2 *= x;
	});
	maxProd = temp2;

	// push the next value from the file
	// and pop the first value from the front
	// of the deque
	while (!in.eof())
	{
		in >> c;
		temp = c - '0';
		numbers.pop_front();
		numbers.push_back(temp);
		temp2 = 1;
		for_each(numbers.begin(), numbers.end(),
			[&temp2](INT x)
		{
			temp2 *= x;
		});
		if (temp2 >= maxProd)
			maxProd = temp2;
	}

	std::cout << "The value you are searching for is: " << maxProd;
	std::cout << std::endl;
	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}