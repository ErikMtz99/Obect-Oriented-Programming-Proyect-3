#include <iostream>
#include "Reserva.h"
#include "Material.h"

using namespace std;

int main() {
	Fecha f(8, 7, 2022), f2(3,8,2022);
	bool r = f == f2;
	Fecha f3 = f + 17;
	cout << f3.getDD() << " " << f3.getMM() << " " << f3.getAA() << endl;
	//cout << r << endl;
	return 0;
}