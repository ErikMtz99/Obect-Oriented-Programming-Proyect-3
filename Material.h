#include <iostream>

using namespace std;

// ********************** Clase Material **********************************

class Material {
public:
	Material();
	Material(int i, string t);
	void setIdMaterial(int i) { idMaterial = i; };
	void setTitulo(string t) { titulo = t; };
	int getIdMaterial() { return idMaterial; };
	string getTitulo() { return titulo; };

	virtual void muestraDatos() = 0;
	virtual int cantidadDiasPrestamo() = 0;

protected:
	int idMaterial;
	string titulo;
};

Material::Material() {
	idMaterial = 0;
	titulo = "NA";
}

Material::Material(int i, string t) {
	idMaterial = i;
	titulo = t;
}

// ********************** Clase Libro **********************************

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

// ********************** Clase Software **********************************

class Software : public Material {
public:
	Software();
	Software(int i, string t, int v, string so);
	void setVersion(int v) { version = v; };
	void setSO(string so) { SO = so; };
	int getVersion() { return version; };
	string getSO() { return SO; };

	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int version;
	string SO;
};

Software::Software() :Material() {
	version = 0;
	SO = "NA";
}

Software::Software(int i, string t, int v, string so) : Material(i, t) {
	version = v;
	SO = so;
}

void Software::muestraDatos() {
	cout << "            Software" << endl;
	cout << "id: " << idMaterial << endl;
	cout << "titulo: " << titulo << endl;
	cout << "version: " << version << endl;
	cout << "SO: " << SO << endl;
}

int Software::cantidadDiasPrestamo() {
	int t_software = 1;
	return t_software;
}

// ********************** Clase Disco **********************************

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
	cout << "duracion: " << duracion << endl;
	cout << "Genero: " << Genero << endl;
}

int Disco::cantidadDiasPrestamo() {
	int t_disco = 2;
	return t_disco;
}