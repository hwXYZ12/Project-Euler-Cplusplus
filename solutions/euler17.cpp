// project euler problem 17 - euler17.cpp
#include <iostream>
#include <fstream>

static std::ofstream out;
static const char fileName[] = "euler17.txt";

// compute the number of letters of an integer written in words
long long lettersInNumber(long long & x);

int main()
{

	using std::cout;
	using std::endl;

	out.open(fileName);

	// find the sum of the number of letters
	// in all numbers from 1 to 1000 inclusive
	long long total = 0;
	for (long long i = 1; i <= 1000; i = i + 1)
	{
		cout << i << " : " << lettersInNumber(i) << endl;
		out << i << " : " << lettersInNumber(i) << endl;
		total += lettersInNumber(i);
	}

	cout << "Solution: " << total << endl;
	out << "Solution: " << total << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}


// compute the number of letters of an integer written in words
long long lettersInNumber(long long & x)
{
	const static long long digits[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
	const static long long tens[] = { 0, 6, 6, 5, 5, 5, 7, 6, 6 };
	const static long long hundred = 7;
	const static long long and = 3;
	const static long long teens[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
	const static long long thousand = 11;

	if (x == 1000)
		return thousand;

	if (x > 1000 || x < 0)
		return -1;

	// get each digit
	long long d[3] = { 0 };
	long long temp = x;
	for (int i = 0; i < 3; ++i)
	{
		d[i] = temp % 10;
		temp /= 10;
	}

	long long sum = 0;
	if (d[2] > 0)
		sum += digits[d[2]] + hundred;
	if (d[2] > 0 && (d[1] > 0 || d[0] > 0))
		sum += and;
	if (d[1] > 1)
		sum += tens[d[1]-1] + digits[d[0]]; //small correction factor of -1
	else if (d[1] == 1)
		sum += teens[d[0]];
	else if (d[1] == 0)
		sum += digits[d[0]];


	return sum;
}