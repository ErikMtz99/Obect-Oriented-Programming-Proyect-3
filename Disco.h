#include <iostream>
#include "Material.h"

using namespace std;

class Disco : public Material {
public:
	Disco();
	Disco(int i, string t, int d, string g);
	void setDuracion(int d) { duracion = d; };
	void setGenero(string g) { Genero = g; };
	int getDuracion() { return duracion; };
	string getGenero() { return Genero; };

	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int duracion;
	string Genero;
};

Disco::Disco() :Material() {
	duracion = 0;
	Genero = "NA";
}
Disco::Disco(int i, string t, int d, string g) : Material(i, t) {
	duracion = d;
	Genero = g;
}

void Disco::muestraDatos() {
	cout << "            Disco" << endl;
	cout << "id: " << idMaterial << endl;
	cout << "titulo: " << titulo << endl;
	cout << "duracion: " << duracion<< endl;
	cout << "Genero: " << Genero << endl;
}

int Disco::cantidadDiasPrestamo() {
	int t_disco = 2;
	return t_disco;
}

