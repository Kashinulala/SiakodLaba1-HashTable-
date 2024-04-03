#include <iostream>
#include "HashTable.h"



int main() {

	HashTable ht(10, 0.75);
	Date d1(12, 12, 98);
	Date d2(15, 06, 93);

	Employee emp1("Avanov", "A.I.", d1, "Manager", 3);
	Employee emp11("Vonava", "I.A.", d1, "Manager", 3);
	Employee emp2("Sidorov", "S.A.", d2, "Administrator", 4);
	Employee emp3 = emp2;

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Добавление в пустую таблицу
	ht.AddRecord(emp1);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Добавление существующей записи
	ht.AddRecord(emp1);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Добавление с коллизией
	ht.AddRecord(emp11);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;


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

	//Добавление записи в заполненную на 80% таблицу

	ht.AddRecord(emp3);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	for (int i = 0; i < 2; i++) {
		ht.DelRecord(emp1);
		emp1.surname[0] -= 1;
		emp1.initials[0] -= 1;
		emp1.dob.yy += 1;
		ht.DelRecord(emp2);
		emp2.surname[3] -= 2;
		emp2.initials[0] -= 2;
		emp2.dob.yy += 1;
	}
	ht.DelRecord(emp1);
	emp1.surname[0] -= 1;
	emp1.initials[0] -= 1;
	emp1.dob.yy += 1;

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Удаление из таблицы заполненной на 20% (N = 10; k = 0, 75)

	ht.DelRecord(emp3);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	ht.DelRecord(emp2);
	emp2.surname[3] -= 2;
	emp2.initials[0] -= 2;
	emp2.dob.yy += 1;
	
	for (int i = 0; i < 2; i++) {
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

	//Добавление записи с несколькими коллизиями 
	Employee emp4("Vaanov", "A.I.", d1, "Manager", 3);
	ht.AddRecord(emp4);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	//Удаление существующей записи (по второй хеш-функции)
	ht.DelRecord(emp4);

	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	for (int i = 0; i < 2; i++) {
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

	if (ht.SearchRec(emp11) == true) cout << "1";
	if (ht.SearchRec(emp1) == true) cout << "1";
	if (ht.SearchRec(emp2) == false) cout << "1";

	if (ht.DelRecord(emp2) == 0) cout << "1";

	cout << endl;
	ht.DelRecord(emp1);
	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	ht.DelRecord(emp11);
	cout << "_____________________________________________" << endl << endl;
	cout << ht;

	return 0;

	//класс циклическая очередь с приоритерным выходом . Хвост указвает на полседнюю добавленную
}