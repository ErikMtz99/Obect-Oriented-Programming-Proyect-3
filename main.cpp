#include <iostream>
#include "Reserva.h"
#include "Material.h"
#include <fstream>

using namespace std;

void archivos(Material* mat[], Reserva res[]) {
	ifstream archivo_mat, archivo_res;
	archivo_mat.open("Material.txt");
	archivo_res.open("Reserva.txt");

	int i = 0;
	int id, dato1;
	string titulo, clave, dato2;
	while (i < 30) {
		archivo_mat >> id >> titulo >> clave >> dato1 >> dato2;

		if (clave == "L")
			mat[i] = new Libro(id, titulo, dato1, dato2);

		else if (clave == "D")
			mat[i] = new Disco(id, titulo, dato1, dato2);


		else if (clave == "S")
			mat[i] = new Software(id, titulo, dato1, dato2);

		else {
			cout << "Clave invalida " << endl;
		}

		
		i++;
	}

	int j = 0;
	int d, m, a, id_m, id_c;
	while (j < 60) {
		archivo_res >> d >> m >> a >> id_m >> id_c;

		Fecha f_res(d, m, a);
		res[j].setFechaReservacion(f_res);
		res[j].setIdMaterial(id_m);
		res[j].setIdCliente(id_c);
		j++;
	}

	archivo_mat.close();
	archivo_res.close();
}

int main() {
	Material* mat[30];
	Reserva res[60];
	archivos(mat, res);

	mat[15]->muestraDatos();
	mat[20]->muestraDatos();
	cout << endl;
	cout << res[1].getFechaReservacion();

	return 0;
}