#include <iostream>
#include "HashTable.h"



int main() {

	HashTable ht(10, 0.75);
	Date d1(12, 12, 98);
	Date d2(15, 06, 93);

	Employee emp1("Avanov", "A.I.", d1, "Manager", 3);
	Employee emp11("Vonava", "I.A.", d1, "Manager", 3);
	Employee emp2("Sidorov", "S.A.", d2, "Administrator", 4);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Добавление в пустую таблицу
	ht.AddRecord(emp1);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Добавление с коллизией
	ht.AddRecord(emp11);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Удаление записи с коллизией
	ht.DelRecord(emp11);

	for (int i = 0; i < 3; i++) {
		emp1.surname[0] += 1;
		emp1.initials[0] += 1;
		emp1.dob.yy -= 1;
		ht.AddRecord(emp1);
		emp2.surname[3] += 2;
		emp2.initials[0] += 2;
		emp2.dob.yy -= 1;
		ht.AddRecord(emp2);
	}

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	for (int i = 0; i < 5; i++) {
		ht.DelRecord(emp1);
		emp1.surname[0] -= 1;
		emp1.initials[0] -= 1;
		emp1.dob.yy += 1;
		ht.DelRecord(emp2);
		emp2.surname[3] -= 2;
		emp2.initials[0] -= 2;
		emp2.dob.yy += 1;
	}

	cout << "_____________________________________________" << endl << endl;
	cout << ht;
	
	for (int i = 0; i < 5; i++) {
		emp1.surname[0] += 1;
		emp1.initials[0] += 1;
		emp1.dob.yy -= 1;
		ht.AddRecord(emp1);
		emp2.surname[3] += 2;
		emp2.initials[0] += 2;
		emp2.dob.yy -= 1;
		ht.AddRecord(emp2);
	}
	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	return 0;

	//класс циклическая очередь с приоритерным выходом . Хвост указвает на полседнюю добавленную
}