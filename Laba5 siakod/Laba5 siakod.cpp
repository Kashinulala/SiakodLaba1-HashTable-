#include <iostream>
#include "HashTable.h"



/*ostream& operator<<(ostream& os, const HashTable& ht) {
	for (int i = 0; i < ht.GetSize(); i++) {
		return os << ht.GetEmp(i) << ' | ' << ht.GetStat(i) << endl;
	}
}*/

int main() {
	//HashTable ht(10, 2);
	Date d;
	d.dd = 1;
	d.mm = 1;
	d.yy = 1;
	cout << d;
	return 1;
}