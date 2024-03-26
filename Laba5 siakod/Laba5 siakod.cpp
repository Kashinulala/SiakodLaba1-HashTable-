#include <iostream>
#include "HashTable.h"



int main() {
	const int N = 10;
	HashTable ht(10, 0.75);
	Date d1(12, 12, 98);
	Date d2(15, 06, 93);

	Employee emp1("Ivanov", "I.I.", d1, "Manager", 3);
	Employee emp2("Sidorov", "S.A.", d2, "Administrator", 4);
	ht.AddRecord(emp1);
	ht.AddRecord(emp2);

	for (int i = 0; i < 7; i++) {
		emp1.surname += "a";
		emp1.initials += "b";
		if (ht.AddRecord(emp1) == 2) cout << "11" << endl;
		emp2.surname += "a";
		emp2.initials += "b";
		if (ht.AddRecord(emp2) == 2) cout << "11" << endl;
	}

	cout << ht;
	/*cout << "_____________________________________________" << endl << endl;
	ht.DelRecord(emp1);
	ht.AddRecord(emp1);
	cout << ht;*/
	return 1;
}