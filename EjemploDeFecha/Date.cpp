#include "Date.h"

Date::Date() {

}

bool Date::leapYear() {
	if (year % 4 == 0) {
		if (year >= 400 && year % 400 != 0) {
			LeapYear = false;
		}
		else {
			LeapYear = true;
		}
	}
	else {
		LeapYear = false;
	}
	return LeapYear;
}

bool Date::validationDate() {
	bool lYear;
	lYear = leapYear();
	if (lYear) {
		if (month == 2 && day <= 29) {
			cout << "La fecha ingresada es valida." << endl;
			return true;
		}
		else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day <= 31) {
			cout << "La fecha ingresada es valida." << endl;
			return true;
		}
		else if ((month == 4 || 6 || 9 || 11) && day <= 30) {
			cout << "La fecha ingresada es valida." << endl;
			return true;
		}
	}
	else {
		if (month == 2 && day <= 28) {
			cout << "La fecha ingresada es valida." << endl;
			return true;
		}
		else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && day <= 31) {
			cout << "La fecha ingresada es valida." << endl;
			return true;
		}
		else if ((month == 4 || 6 || 9 || 11) && day <= 30) {
			cout << "La fecha ingresada es valida." << endl;
			return true;
		}
	}
	cout << "La fecha ingresada no es valida vuelva a ingresar una porfavor." << endl;
	return false;
}

void Date::getDateSystem() {
	tm* time = localtime(&now);

	setDay(time->tm_mday);
	setMonth(1 + time->tm_mon);
	setYear(1900 + time->tm_year);
}

void Date::printDate() {
	if (type) {
		cout << day << " / " << month << " / " << year;
	}
	else {
		cout << month << " / " << day << " / " << year;
	}
}

void Date::setType(bool T) {
	type = T;
}

void Date::setDay(int D) {
	day = D;
}

void Date::setMonth(int M) {
	month = M;
}

void Date::setYear(int Y) {
	year = Y;
}

