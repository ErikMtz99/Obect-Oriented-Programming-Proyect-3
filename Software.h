#include <iostream>
#include "Material.h"

using namespace std;

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

Software::Software(int i, string t, int v, string so) : Material(i,t) {
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
