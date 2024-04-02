#pragma once
#include "Employee.h"
#include "AdditionalFunctions.h"

class HashTable{

	private:
		Employee* table;
		int* status;
		unsigned N;
		unsigned cur_N;
		unsigned min_N;
		float k;

	public:
		
		HashTable(unsigned _N, float _k) {
			table = new Employee[_N];
			N = _N;
			if (_k >= 0.8) {
				k = 0.8;
			}
			else {
				k = _k;
			}
			min_N = _N;
			cur_N = 0;
			status = new int[_N];
			for (int i = 0; i < _N; i++) {
				status[i] = 0;
			}
		}

		~HashTable() {
			delete [] table;
			delete [] status;
		}
		
		int GetSize() const{
			return N;
		}

		friend ostream& operator << (ostream& os, const HashTable& ht) {
			for (int i = 0; i < ht.N; i++) {
				if (ht.status[i] == 1) {
					os << "[" << i << "] " << ht.table[i] << " | status: " << ht.status[i] << endl;
				}
				else os << "[" << i << "] " << " status: " << ht.status[i] << endl;
			}
			return os << endl;
		}

		//Хеш-функция 1, складывает кодировки символов фамилии,
		//инициалов, дату рождения сотрудника
		int HashFunc1(Employee rec) {
			int hf1;
			hf1 = (GetStrSum(rec.surname) + GetStrSum(rec.initials) + rec.dob.dd + rec.dob.mm + rec.dob.yy) % N;
			return hf1;
		}


		//Хеш-функция 2, последовательное опробование (+1)
		//adr - адрес предыдущей записи; int i - номер попытки
		int HashFunc2(int adr) {			//int HashFunc2(int adr, int i) {
			return (adr + 1) % N;			//return (adr + i * i) % N;
		}


		//Поиск записи в таблице
		bool SearchRec(Employee rec) {
			int adr = HashFunc1(rec);
			if ((rec == table[adr]) && (status[adr] == 1))
				return true;
			else {
				adr = HashFunc2(adr);
				while (status[adr] != 0) {
					if ((table[adr] == rec) && (status[adr] == 1)) {
						return true;
					}
					else 
						adr = HashFunc2(adr);
				}
				return false;
			}
		}



		int AddRecord(Employee rec) {

			if(cur_N > (N * k)) Resize(1);
			
			bool add_fl = false;
			int add_adr;
			int adr;
			adr = HashFunc1(rec);

			for (int i = 0; i < N; i++) {
				if ((status[adr] == 1) && (table[adr] == rec)) {
					return 1;
				}
				if (status[adr] == 0) {
					if (add_fl == true) {
						table[add_adr] = rec;
						status[add_adr] = 1;
					}
					else {
						table[adr] = rec;
						status[adr] = 1;
					}
					cur_N++;
					return 0;
				}
				if ((add_fl == false) && (status[adr] == 2)) {
					add_fl = true;
					add_adr = adr;
				}
				adr = HashFunc2(adr);
			}
			if (add_fl == true) {
				table[add_adr] = rec;
				status[add_adr] = 1;
				cur_N++;
				return 0;
			}
		}


		int DelRecord(Employee rec) {

			if (cur_N < (N * (1 - k))) Resize(0);

			int adr = HashFunc1(rec);
			if ((rec == table[adr]) && (status[adr] == 1)) {
				status[adr] = 2;
				cur_N--;
				return 1;
			}
			else {
				adr = HashFunc2(adr);
				int i = 0;
				while (status[adr] != 0) {
					if ((table[adr] == rec) && (status[adr] == 1)) {
						status[adr] = 2;
						cur_N--;
						return 1;
					}
					else 
						adr = HashFunc2(adr);
					if (i > N) {
						return 0;
					}
					i++;
				}
				return 0;
			}
		}

		//direction - отвечает за расширение/сужение таблицы;
		//1 - расширение, 0 - сужение;
		int Resize(int direction) {

			int prev_N = N;

			if (direction == 1) {
				N += 10;
			}
			else if (N - 10 >= min_N) {
				N -= 10;
			}
			else {
				return -1;
			}

			Employee* prev_table; //указатель на таблицу до расширения
			int* prev_status;

			Employee* emp_arr{ new Employee[N] };
			int* stat_arr{ new int[N] };

			for (int i = 0; i < N; i++) {
				stat_arr[i] = 0;
			}

			prev_status = status;
			prev_table = table;
			table = emp_arr;
			status = stat_arr;
			cur_N = 0;

			for (int i = 0; i < prev_N; i++) {
				if (prev_status[i] == 1) {
					AddRecord(prev_table[i]);
				}
			}

			delete[] prev_status;
			delete[] prev_table;

			return 0;
		}	
};