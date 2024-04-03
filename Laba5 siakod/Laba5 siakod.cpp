#include <iostream>
#include "HashTable.h"



int main() {

	setlocale(LC_ALL, "Russian");

	HashTable ht(10, 0.75);
	Date d1(12, 12, 98);
	Date d2(15, 06, 93);

	Employee emp1("Avanov", "A.I.", d1, "Manager", 3);
	Employee emp11("Vonava", "I.A.", d1, "Manager", 3);
	Employee emp2("Sidorov", "S.A.", d2, "Administrator", 4);
	Employee emp3 = emp2;

	cout << "Пустая таблица" << endl << endl;
	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Добавление в пустую таблицу
	cout << "Добавление в пустую таблицу" << endl << endl;
	ht.AddRecord(emp1);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Добавление существующей записи
	cout << "Добавление существующей записи" << endl << endl;
	ht.AddRecord(emp1);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;
	

	//Добавление с коллизией
	cout << "Добавление с коллизией" << endl << endl;
	ht.AddRecord(emp11);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

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

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Добавление записи в заполненную на 80% таблицу
	cout << "Добавление записи в заполненную на 80% таблицу" << endl << endl;
	ht.AddRecord(emp3);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

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

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Удаление из таблицы заполненной на 20% (N = 10; k = 0, 75)
	cout << "Удаление из таблицы заполненной на 20% (N = 10; k = 0, 75)" << endl << endl;
	ht.DelRecord(emp3);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

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

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Добавление записи с несколькими коллизиями 
	cout << "Добавление записи с несколькими коллизиями" << endl << endl;
	Employee emp4("Vaanov", "A.I.", d1, "Manager", 3);
	ht.AddRecord(emp4);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Удаление существующей записи (по второй хеш-функции)
	cout << "Удаление существующей записи (по второй хеш-функции)" << endl << endl;
	ht.DelRecord(emp4);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

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

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Поиск по первой/второй хеш-функции, поиск несуществующей записи
	cout << "Поиск по первой/второй хеш-функции, поиск несуществующей записи" << endl << endl;
	if (ht.SearchRec(emp11) == true) cout << "1";
	if (ht.SearchRec(emp1) == true) cout << "1";
	if (ht.SearchRec(emp2) == false) cout << "1";

	if (ht.DelRecord(emp2) == 0) cout << "1";

	//Удаление по первой хеш-функции
	cout << endl;
	cout << "Удаление по первой хеш-функции" << endl << endl;

	ht.DelRecord(emp1);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	//Удаление всех записей из таблицы
	cout << "Удаление всех записей из таблицы" << endl << endl;
	ht.DelRecord(emp11);

	cout << ht;
	cout << "_____________________________________________" << endl << endl;

	return 0;

	//класс циклическая очередь с приоритерным выходом . Хвост указвает на полседнюю добавленную
}