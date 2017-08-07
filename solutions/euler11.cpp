// project euler problem 11 - euler11.cpp
// https://projecteuler.net/problem=11 for problem statement
#include <iostream>;
#include <fstream>;
#include <algorithm>;

typedef long long INT;
const char * INPUT_PATH = "euler11input.txt";
const int GRID_SIZE = 20;
const int PROD_SIZE = 4;

int main()
{
	using std::ifstream;

	// read in a 20x20 grid of numbers
	ifstream in;
	in.open(INPUT_PATH);
	INT data[GRID_SIZE][GRID_SIZE];

	int t, col, row;
	t = col = row = 0;
	while (!in.eof())
	{
		in >> t;
		data[col][row] = t;
		++col;
		if (col >= GRID_SIZE)
		{
			++row;
			col = 0;
		}

	}

	/*	We have 4 directions in our grid
		of data that we are interested in:
		diagonal left, diagonal right, vertical
		and horizontal. We are tasked with finding
		the largest product of 4 adjacent values
		in any of the 4 directions.*/

	INT maxProd = 0, temp = 1;
	// compute largest of products in the
	// horizontal direction
	col = row = 0;
	while (row < GRID_SIZE)
	{
		temp = 1;
		for (int i = 0; i < PROD_SIZE; ++i)
		{
			temp *= data[col+i][row];
		}
		if (temp >= maxProd)
			maxProd = temp;
		++col;
		if (col >= GRID_SIZE - PROD_SIZE)
		{
			col = 0;
			++row;
		}
	}

	// compute largest of products in the
	// vertical direction
	col = row = 0;
	while (col < GRID_SIZE)
	{
		temp = 1;
		for (int i = 0; i < PROD_SIZE; ++i)
		{
			temp *= data[col][row+i];
		}
		if (temp >= maxProd)
			maxProd = temp;
		++row;
		if (row >= GRID_SIZE - PROD_SIZE)
		{
			row = 0;
			++col;
		}
	}

	// compute largest of products in the
	// right diagonal direction
	col = row = 0;
	while (row < GRID_SIZE - PROD_SIZE)
	{
		temp = 1;
		for (int i = 0; i < PROD_SIZE; ++i)
		{
			temp *= data[col + i][row+i];
		}
		if (temp >= maxProd)
			maxProd = temp;
		++col;
		if (col >= GRID_SIZE - PROD_SIZE)
		{
			col = 0;
			++row;
		}
	}

	// compute largest of products in the
	// left diagonal direction
	col = PROD_SIZE - 1;
	row = 0;
	while (row < GRID_SIZE - PROD_SIZE)
	{
		temp = 1;
		for (int i = 0; i < PROD_SIZE; ++i)
		{
			temp *= data[col - i][row + i];
		}
		if (temp >= maxProd)
			maxProd = temp;
		++col;
		if (col >= GRID_SIZE)
		{
			col = PROD_SIZE - 1;
			++row;
		}
	}
	


	std::cout << "The largest product: " << maxProd;
	std::cout << std::endl;
	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}