#pragma once
#include <string>
using namespace std;

struct Date {

	unsigned dd;
	unsigned mm;
	unsigned yy;

	bool operator == (const Date& date) const {
		return (dd == date.dd) && (mm == date.mm) && (yy == date.yy);
	};
};

struct Employee {
	string surname;
	string initials;
	Date dob;
	string prof;
	unsigned period;

	bool operator == (const Employee& emp) const {
		return (surname == emp.surname) && (initials == emp.initials) && (dob == emp.dob) && (prof == emp.prof) && (period == emp.period);
	};
};