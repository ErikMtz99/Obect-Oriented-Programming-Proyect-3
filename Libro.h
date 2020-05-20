#include <iostream>
#include "Material.h"

using namespace std;

class Libro : public Material {
public:
	Libro();
	Libro(int i, string t, int n, string a);
	void setNumPag(int n) { numPag = n; };
	void setAutor(string a) { Autor = a; };
	int getNumPag() { return numPag; };
	string getAutor() { return Autor; };

	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int numPag;
	string Autor;
};

Libro::Libro() :Material() {
	numPag = 0;
	Autor = "NA";
}
Libro::Libro(int i, string t, int n, string a) : Material(i, t) {
	numPag = n;
	Autor = a;
}

void Libro::muestraDatos() {
	cout << "            Libro" << endl;
	cout << "id: " << idMaterial << endl;
	cout << "titulo: " << titulo << endl;
	cout << "numero pagina: " << numPag << endl;
	cout << "Autor: " << Autor << endl;
}

int Libro::cantidadDiasPrestamo() {
	int t_libro = 7;
	return t_libro;
}
