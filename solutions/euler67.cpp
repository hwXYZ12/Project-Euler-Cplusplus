// project euler problem 18 & 67 - euler67.cpp
#include <iostream>
#include <fstream>

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "euler67out.txt";
static const char fileNameIn[] = "euler67in.txt";

int main()
{

	using std::cout;
	using std::endl;

	out.open(fileNameOut);
	in.open(fileNameIn);

	// read in the triangle
	static const int rows = 100;
	int vals[rows][rows] = { 0 }; // row, column

	int whichRow = 1, temp = 0;
	while (!in.eof())
	{
		for (int i = 0; i < whichRow; ++i)
		{
			if (in >> temp)
				vals[whichRow - 1][i] = temp;
		}
		++whichRow;
	}

	// perform the dynamic programming algorithm
	// on the triangle
	for (int i = rows - 2; i >= 0; --i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			if (vals[i + 1][j] < vals[i + 1][j + 1])
				vals[i][j] += vals[i + 1][j + 1];
			else
				vals[i][j] += vals[i + 1][j];
		}
	}

	// print the triangle - debug
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << vals[i - 1][j] << " ";
			out << vals[i - 1][j] << " ";
		}
		cout << endl;
		out << endl;
	}

	// root should now contain the answer we're looking for
	cout << "Solution: " << vals[0][0] << endl;
	out << "Solution: " << vals[0][0] << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

