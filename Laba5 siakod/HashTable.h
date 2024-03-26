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
			k = _k;
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
				os << ht.table[i] << " | " << ht.status[i] << endl;
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
						break;
					}
					else 
						adr = HashFunc2(adr);
				}
				return false;
			}
		}



		int AddRecord(Employee rec) {

			if(cur_N >= (N * k)) Resize();
			bool add_fl = false;
			int add_adr;

			int adr = HashFunc1(rec);
			if (status[adr] == 0) {
				table[adr] = rec;
				status[adr] = 1;
				cur_N++;
				return 0;
			}
			if ((status[adr] == 1) && (rec == table[adr])) {
				return 1;
			}
			if (status[adr] == 2) {
				add_fl = true;
				add_adr = adr;
			}

			for (int i = 0; i < N; i++) {
				adr = HashFunc2(adr);
				if ((status[adr] == 1) && (table[adr] == rec)) {
					table[add_adr] = rec;
					status[add_adr] = 1;
					status[adr] = 2;
					cur_N++;
					return 0;
				}
				if (status[adr] == 0) {
					table[adr] = rec;
					status[adr] = 1;
					cur_N++;
					return 0;
				}
				if ((add_fl == false) && (status[adr] == 2)) {
					add_fl = true;
					add_adr = adr;
				}
			}
			if (add_fl == true) {
				table[adr] = rec;
				status[adr] = 1;
				cur_N++;
				return 0;
			}
			else return 2;

			//дописать случай когда места нет (return 2 или расширение таблицы)
		}


		int DelRecord(Employee rec) {

			if (cur_N <= (N * (1 - k))) Resize();
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

		int Resize() {

			int N_2 = 0;

			if (cur_N >= (N * k)) {
				N_2 = N + 10;
			}
			else if (cur_N <= (N * (1 - k))) {
				N_2 = N - 10;
			}

			if (N_2 >= min_N) {

				Employee* emp_arr{new Employee[cur_N]};
				int q = cur_N; //кол-во записей в текущей таблице
				int j = 0;

				for (int i = 0; i < N; i++) {
					if (status[i] == 1) {
						emp_arr[j] = table[i];
						j++;
					}
				}

				N = N_2;
				delete[] table;
				table = new Employee[N];
				cur_N = 0;
				delete[] status;
				status = new int[N];
				for (int i = 0; i < N; i++) {
					status[i] = 0;
				}

				for (int i = 0; i < q; i++) {
					AddRecord(emp_arr[i]);
				}

				delete[] emp_arr;

				return 1;

			}
			else return 0;

		}
			

};