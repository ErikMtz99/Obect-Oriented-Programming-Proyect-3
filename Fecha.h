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

	bool operator>(Fecha f);
	bool operator>=(Fecha f);
	bool operator<(Fecha f);
	bool operator<=(Fecha f);
	bool operator==(Fecha f);
	Fecha operator+(int dias);
	void operator>>(Fecha in);
	void operator<<(Fecha out);
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

bool Fecha::operator>(Fecha f) {
	bool mayor = false;
	if (aa > f.aa) {
		mayor = true;
	}
	else if (aa == f.aa) {
		if (mm > f.mm) {
			mayor = true;
		}
		else if (mm == f.mm) {
			if (dd > f.dd) {
				mayor = true;
			}
		}
	}
	return mayor;
}
bool Fecha::operator>=(Fecha f) {
	bool mayor = false;
	if (aa > f.aa) {
		mayor = true;
	}
	else if (aa == f.aa) {
		if (mm > f.mm) {
			mayor = true;
		}
		else if (mm == f.mm) {
			if (dd > f.dd) {
				mayor = true;
			}
			else if (dd == f.dd) {
				mayor = true;
			}
		}
	}
	return mayor;
}
bool Fecha::operator<(Fecha f) {
	bool menor = false;
	if (aa < f.aa) {
		menor = true;
	}
	else if (aa == f.aa) {
		if (mm < f.mm) {
			menor = true;
		}
		else if (mm == f.mm) {
			if (dd < f.dd) {
				menor = true;
			}
		}
	}
	return menor;
}
bool Fecha::operator<=(Fecha f) {
	bool menor = false;
	if (aa < f.aa) {
		menor = true;
	}
	else if (aa == f.aa) {
		if (mm < f.mm) {
			menor = true;
		}
		else if (mm == f.mm) {
			if (dd < f.dd) {
				menor = true;
			}
			else if (dd == f.dd) {
				menor = true;
			}
		}
	}
	return menor;
}
bool Fecha::operator==(Fecha f) {
	bool igual = false;
	if (aa == f.aa) {
		if (mm == f.mm) {
			if (dd == f.dd) {
				igual = true;
			}
		}
	}
	return igual;
}
Fecha Fecha::operator+(int dias) { // checarlo bien!!

	int dias_mes[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sumar_anios = dias / 365;
	int sobra = dias % 365;

	aa += sumar_anios;

	for (int i = 0; i <= sobra; i++) {
		if (dd < dias_mes[mm - 1])
			dd++;
		else if ((dd == dias_mes[mm - 1]) && (mm < 12))
		{
			dd = 1;
			mm++;
		}
		else if ((dd == dias_mes[mm - 1]) && (mm == 12))
		{
			dd = 1;
			mm = 1;
			aa++;
		}
		else
			cout << "Error setting date!";
	}

	Fecha f(dd, mm, aa);
	return f;

	// REFERENCIA: http://www.cplusplus.com/forum/beginner/147077/ 

	//int suma = dd + dias;
	//int c = suma / 30;
	//if (suma > 30) {
	//	int mc = mm + c;
	//	int a = mc / 12;
	//	dd = suma - (30 * c);
	//	mm = mc - (12 * a);

	//	if (mc == 12*a) {
	//		mm = 12;
	//	}
	//	else if (mc > 12*a){

	//	}

	//}
	//	else {
	//		dd = suma;
	//	}
}
void Fecha::operator>>(Fecha in) {

}
void Fecha::operator<<(Fecha out) {

}