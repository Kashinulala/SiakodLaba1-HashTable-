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

	Date() {
		dd = 0;
		mm = 0;
		yy = 0;
	}

	Date(unsigned dd, unsigned mm, unsigned yy)
		: dd(dd), mm(mm), yy(yy)
	{
	}
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

	Employee(){
		surname = "";
		initials = "";
		prof = "";
		period = 0;
	};

	Employee(const string& surname, const string& initials, const Date& dob, const string& prof, unsigned period)
		: surname(surname), initials(initials), dob(dob), prof(prof), period(period)
	{
	}	
};