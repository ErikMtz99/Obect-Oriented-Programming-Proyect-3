#include <iostream>

using namespace std;

class Fecha {
public:
	Fecha();
	Fecha(int d, int m, int a);
	void setDD(int d) { dd = d; };
	void setMM(int m) { mm = m; };
	void setAA(int a) { aa = a; };
	void setFecha(int d, int m, int a);
	int getDD() { return dd; };
	int getMM() { return mm; };
	int getAA() { return aa; };

private:
	int dd, mm, aa;
};
Fecha::Fecha() {
	dd = 0;
	mm = 0;
	aa = 0;
}
Fecha::Fecha(int d, int m, int a) {
	dd = d;
	mm = m;
	aa = a;
}
void Fecha::setFecha(int d, int m, int a) {
	dd = d;
	mm = m;
	aa = a;
}