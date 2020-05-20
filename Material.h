#include <iostream>

using namespace std;

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

