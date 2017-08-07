// project euler problem 19 - euler19.cpp
#include <iostream>
#include <fstream>
#include <iomanip>

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "euler19out.txt";
static const char fileNameIn[] = "euler19in.txt";
static const int MONTHS_IN_A_YEAR = 12;
static const int DAYS_IN_A_WEEK = 7;
static const char* MONTH_NAMES[] = { "January", "February", "March",
									"April", "May", "June",
									"July", "August", "September",
									"October", "November", "December" };
static const char* WEEKDAY_NAMES[] = { "Monday", "Tuesday", "Wednesday", "Thursday",
										"Friday", "Saturday", "Sunday" };
static const int DAYS_PER_MONTH[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const int MONTH_STRING_WIDTH = 20;
static const int START_YEAR = 1901;
static const int END_YEAR = 2000;
static const int FEBRUARY = 1;
static const int SUNDAY = 6;
static const int IMLAZY = 366;

int main()
{

	using std::cout;
	using std::endl;
	using std::setw;
	using std::left;

	out.open(fileNameOut);
	in.open(fileNameIn);

	cout << setw(MONTH_STRING_WIDTH) << left << "Month"
		<< setw(MONTH_STRING_WIDTH) << left << "First Day" 
		<< setw(MONTH_STRING_WIDTH) << left << "Day of the Week"
		<< endl;
	out << setw(MONTH_STRING_WIDTH) << left << "Month"
		<< setw(MONTH_STRING_WIDTH) << left << "First Day"
		<< setw(MONTH_STRING_WIDTH) << left << "Day of the Week"
		<< endl;
	int j = IMLAZY, count = 0;
	for (int year = START_YEAR; year <= END_YEAR; ++year)
	{
		for (int i = 0; i < MONTHS_IN_A_YEAR; ++i)
		{
			cout << setw(MONTH_STRING_WIDTH) << left << MONTH_NAMES[i]
				<< setw(MONTH_STRING_WIDTH) << left << j
				<< setw(MONTH_STRING_WIDTH) << left << WEEKDAY_NAMES[(j - 1) % DAYS_IN_A_WEEK]
				<< endl;
			out << setw(MONTH_STRING_WIDTH) << left << MONTH_NAMES[i]
				<< setw(MONTH_STRING_WIDTH) << left << j
				<< setw(MONTH_STRING_WIDTH) << left << WEEKDAY_NAMES[(j - 1) % DAYS_IN_A_WEEK]
				<< endl;
			if ((j - 1) % DAYS_IN_A_WEEK == SUNDAY)
				++count;

			// accounting for leap years, specifically February
			if (i == FEBRUARY && year % 4 == 0)
			{
				if (year % 100 == 0)
				{
					if (year % 400 == 0)
					{
						++j;
					}
				}
				else
				{
					++j;
				}
			}
			j += DAYS_PER_MONTH[i];
		}
	}
	out << "Number of months that start on Sunday in the 19th Century: " << count << endl;
	cout << "Number of months that start on Sunday in the 19th Century: " << count << endl;


	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

