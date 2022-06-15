#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#pragma warning(disable : 4996)


using namespace std;

class Date
{
private:
	int day, month, year;
	string dateInString;
	bool type = NULL, LeapYear = NULL;
	time_t now = time(0);
public:
	Date();
	Date(int inDay, int inMonth, int inYear)
		:month(inMonth), day(inDay), year(inYear) {};

	Date& operator ++ () {
		bool lYear;
		lYear = leapYear();
		if (lYear) {
			if (month == 2 && day == 29) {
				day = 1;
				++month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 31) {
				if (month == 12 && day == 31) {
					++year;
					month = 1;
					day = 1;
				}
				else {
					++month;
					day = 1;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day == 30) {
				++month;
				day = 1;
			}
			else {
				++day;
			}
		}
		else if (!lYear) {
			if (month == 2 && day == 28) {
				day = 1;
				++month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 31) {
				if (month == 12 && day == 31) {
					++year;
					month = 1;
					day = 1;
				}
				else {
					++month;
					day = 1;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day == 31) {
				++month;
				day = 1;
			}
			else {
				++day;
			}
		}
		return *this;
	}

	Date& operator -- () {
		bool lYear;
		lYear = leapYear();
		if (lYear) {
			if (month == 2 && day == 1) {
				day = 31;
				--month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 1) {
				if (month == 1 && day == 1) {
					--year;
					month = 12;
					day = 31;
				}
				else if (month == 3) {
					--month;
					day = 29;
				}
				else if (month == 8) {
					--month;
					day = 31;
				}
				else {
					--month;
					day = 30;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day == 1) {
				--month;
				day = 31;
			}
		}
		else if (!lYear) {
			if (month == 2 && day == 1) {
				day = 31;
				--month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 1) {
				if (month == 1 && day == 1) {
					--year;
					month = 12;
					day = 31;
				}
				else if (month == 3) {
					--month;
					day = 28;
				}
				else if (month == 8) {
					--month;
					day = 31;
				}
				else {
					--month;
					day = 30;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day == 1) {
				--month;
				day = 31;
			}
		}
		else {
			--day;
		}
		return *this;
	}

	Date operator ++ (int) {
		Date copy(month, day, year);
		bool lYear;
		lYear = leapYear();
		if (lYear) {
			if (month == 2 && day == 29) {
				day = 1;
				++month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 31) {
				if (month == 12 && day == 31) {
					++year;
					month = 1;
					day = 1;
				}
				else {
					++month;
					day = 1;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day == 30) {
				++month;
				day = 1;
			}
		}
		else if (!lYear) {
			if (month == 2 && day == 28) {
				day = 1;
				++month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 31) {
				if (month == 12 && day == 31) {
					++year;
					month = 1;
					day = 1;
				}
				else {
					++month;
					day = 1;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day <= 30) {
				++month;
				day = 1;
			}
		}
		else {
			++day;
		}
		return copy;
	}

	Date operator -- (int) {
		Date copy(month, day, year);
		bool lYear;
		lYear = leapYear();
		if (lYear) {
			if (month == 2 && day == 1) {
				day = 31;
				--month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 1) {
				if (month == 1 && day == 1) {
					--year;
					month = 12;
					day = 31;
				}
				else if (month == 3) {
					--month;
					day = 29;
				}
				else if (month == 8) {
					--month;
					day = 31;
				}
				else {
					--month;
					day = 30;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day == 1) {
				--month;
				day = 31;
			}
		}
		else if (!lYear) {
			if (month == 2 && day == 1) {
				day = 31;
				--month;
			}
			else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day == 1) {
				if (month == 1 && day == 1) {
					--year;
					month = 12;
					day = 31;
				}
				else if (month == 3) {
					--month;
					day = 28;
				}
				else if (month == 8) {
					--month;
					day = 31;
				}
				else {
					--month;
					day = 30;
				}
			}
			else if ((month == 4 || 6 || 9 || 11) && day == 1) {
				--month;
				day = 31;
			}
		}
		else {
			--day;
		}
		return copy;
	}

	operator const char* () {
		if (!type) {
			ostringstream formattedDate;
			formattedDate << month << " / " << day << " / " << year;

			dateInString = formattedDate.str();
			return dateInString.c_str();
		}
		else {
			ostringstream formattedDate;
			formattedDate << day << " / " << month << " / " << year;

			dateInString = formattedDate.str();
			return dateInString.c_str();
		}
	}

	bool leapYear();

	bool validationDate();

	void getDateSystem();

	void printDate();

	void setType(bool);

	void setDay(int);

	void setMonth(int);

	void setYear(int);
};

