#include <iostream>
#include "Reserva.h"
#include "Material.h"
#include <fstream>

using namespace std;

int archivos(Material* mat[], Reserva res[]) {
	ifstream archivo_mat, archivo_res;
	archivo_mat.open("Material.txt");
	archivo_res.open("Reserva.txt");

	int cont = 0;
	Fecha def(0, 0, 0);

	for (int x = 0; x < 30; x++) {
		mat[x] = new Disco(-1, "-1", -1, "-1");
	}

	for (int y = 0; y < 60; y++) {
		res[y].setFechaReservacion(def);
		res[y].setIdCliente(-1);
		res[y].setIdMaterial(-1);
	}

	int i = 0;
	int id, dato1;
	string titulo, clave, dato2;
	while (!archivo_mat.eof()) {
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
	while (!archivo_res.eof()) {
		archivo_res >> d >> m >> a >> id_m >> id_c;
		Fecha f_res(d, m, a);
		res[j].setFechaReservacion(f_res);
		res[j].setIdMaterial(id_m);
		res[j].setIdCliente(id_c);
		cont = cont + 1;
		j++;
	}

	archivo_mat.close();
	archivo_res.close();
	return cont;
}

void Reservar(Reserva res[], Fecha f, int id_cl, int id_mat, int contador) {
	ofstream archivo_res;
	ifstream archivo_act;
	archivo_res.open("Reserva.txt");
	int j = 0;
	res[contador-1].setFechaReservacion(f);
	res[contador-1].setIdCliente(id_cl);
	res[contador-1].setIdMaterial(id_mat);

	while (res[j].getIdMaterial() != -1) {
			archivo_res << res[j].getFechaReservacion().getDD() << " ";
			archivo_res << res[j].getFechaReservacion().getMM() << " ";
			archivo_res << res[j].getFechaReservacion().getAA() << " ";
			archivo_res << res[j].getIdMaterial() << " ";
			archivo_res << res[j].getIdCliente();
			archivo_res << endl;

		j++;
	}
	//	archivo_res << f.getDD() << " " << f.getMM() << " " << f.getAA() << " ";
	//	archivo_res << id_mat << " ";
	//	archivo_res << id_cl << endl;
	//archivo_res.close(); // aqui el archivo txt ya está actualizado

}

int VerificarMaterial(Material* mat[], int mater) {
	bool Existe = false;
	for (int c = 0; c < 30; c++) {
		if (mater == mat[c]->getIdMaterial())
		{
			Existe = true;
		}
	}
	while (Existe == false) {
		cout << "id del material no existe, ingrese denuevo: ";
		cin >> mater;
		cout << endl;
		for (int c = 0; c < 30; c++) {
			if (mater == mat[c]->getIdMaterial())
			{
				Existe = true;
			}
		}
	}
	return mater;
}
void OpcionA(Material* mat[]) {
	int i = 0;
	while (i < 30 && mat[i]->getIdMaterial() != -1)
	{
		mat[i]->muestraDatos();
		i++;
	}
}

void OpcionB(Reserva res[], Material* mat[]) {
	int j = 0;
	int r = 0;
	int dias_pres = 0;
	string nombre;
	while (j < 60 && res[j].getIdCliente() != -1)
	{
		int a = res[j].getIdMaterial();

		while (r < 30)
		{
			if (a == mat[r]->getIdMaterial()) {
				dias_pres = mat[r]->cantidadDiasPrestamo();
				nombre = mat[r]->getTitulo();
			}
			r++;
		}
		r = 0;

		cout << endl;
		cout << "Fecha Inicio: " << res[j].getFechaReservacion() << endl;
		cout << "Fecha Fin: " << res[j].calculaFechaFinReserva(dias_pres) << endl;
		cout << "Nombre Material: " << nombre << endl;
		cout << "Id cliente: " << res[j].getIdCliente() << endl;


		j++;
	}
}

void OpcionC(Reserva res[], Material* mat[]) {
	int material;
	int r = 0;
	int dias_pres = 0;
	string nombre;
	cout << "ingrese el id del material: ";
	cin >> material;

	bool Existe = false;
	bool Existe2 = false;

	for (int c = 0; c < 30; c++) {
		if (material == mat[c]->getIdMaterial())
		{
			Existe = true;
		}
	}
	while (Existe == false) {
		cout << "id del material no existe, ingrese denuevo: ";
		cin >> material;
		cout << endl;
		for (int c = 0; c < 30; c++) {
			if (material == mat[c]->getIdMaterial())
			{
				Existe = true;
			}
		}
	}

	for (int j = 0; j < 60; j++) {
		while (r < 30)
		{
			if (material == mat[r]->getIdMaterial()) {
				dias_pres = mat[r]->cantidadDiasPrestamo();
				nombre = mat[r]->getTitulo();
			}
			r++;
		}
		//r = 0; // dasfgf

		if (material == res[j].getIdMaterial()) {
			cout << endl;
			Existe2 = true;
			cout << "Nombre Material: " << nombre << endl;
			cout << "Fecha Inicio: " << res[j].getFechaReservacion() << endl;
			cout << "Fecha Fin: " << res[j].calculaFechaFinReserva(dias_pres) << endl;
		}
	}
	if (Existe2 == false) {
		cout << "No hay reservaciones de este material. " << endl;
	}
}

void OpcionD(Reserva res[], Material* mat[]) {
	int d, m, a;
	int r = 0;
	int dias_pres = 0;
	int idMaterial = 0;
	string nombre;

	cout << "ingrese el dia: ";
	cin >> d;
	cout << endl;
	cout << "ingrese el mes (en numero): ";
	cin >> m;
	cout << endl;
	cout << "Ingrese el año: ";
	cin >> a;
	cout << endl;
	Fecha f_res(d, m, a);

	bool reservacion = false;

	for (int j = 0; j < 60; j++) {

		if (f_res == res[j].getFechaReservacion()) {
			idMaterial = res[j].getIdMaterial();
			while (r < 30)
			{
				if (idMaterial == mat[r]->getIdMaterial()) {
					dias_pres = mat[r]->cantidadDiasPrestamo();
					nombre = mat[r]->getTitulo();
				}
				r++;
			}
			r = 0;
			reservacion = true;
			cout << "Nombre: " << nombre << endl;
			cout << "id Cliente: " << res[j].getIdCliente() << endl;
			cout << "Fin reservacion: " << res[j].calculaFechaFinReserva(dias_pres);
			cout << endl << endl;
		}

	}
	if (reservacion == false) {
		cout << "No hay reservaciones en esta fecha. " << endl;
	}

}

void OpcionE(Reserva res[], Material* mat[], int contador) {
	int id_mat, id_cl, d, m, a;
	cout << "Ingrese id de material a reservar: ";
	cin >> id_mat;
	cout << endl;
	id_mat = VerificarMaterial(mat, id_mat);

	cout << "Ingrese id del cliente: ";
	cin >> id_cl;
	cout << endl;
	cout << "Ingrese fecha de reservacion a continuación." << endl;
	cout << "ingrese el dia: ";
	cin >> d;
	cout << endl;
	cout << "ingrese el mes (en numero): ";
	cin >> m;
	cout << endl;
	cout << "Ingrese el año: ";
	cin >> a;
	cout << endl;
	Fecha f_res(d, m, a);

	bool disponible = false;

	for (int j = 0; j < 60; j++) {

		if (f_res == res[j].getFechaReservacion()) {
			if (id_mat == res[j].getIdMaterial()) {
				disponible = false;
				break;
			}
			else {
				disponible = true;
			}
		}
		else {
			disponible = true;
		}

	}

	if (disponible == true) {
		Reservar(res, f_res, id_cl, id_mat, contador);// Ingresar al archivo la nueva reserva
		cout << "Reservación exitosa!" << endl;
	}
	else {
		cout << "Material no disponible. Material reservado." << endl;
	}


}

int main() {
	Material* mat[30] = {};
	Reserva res[60] = {};

	while (true) {
		int contador = archivos(mat, res);

		cout << endl;
		cout << "Ingrese una de las siguientes opciones porfavor: " << endl;
		cout << "[1] Consulta lista de materiales" << endl;
		cout << "[2] Consulta lista de reservaciones" << endl;
		cout << "[3] Consultar reservaciones de una material dado" << endl;
		cout << "[4] Consultar reservaciones de una fecha dada" << endl;
		cout << "[5] Hacer una reservacion" << endl;
		cout << "[6] Terminar" << endl;
		cout << "[7] Salir" << endl;
		int respuesta;
		bool salir = false;
		cin >> respuesta;

		switch (respuesta) {
		case 1:
			OpcionA(mat);
			break;
		case 2:
			OpcionB(res, mat);
			break;
		case 3:
			OpcionC(res, mat);
			break;
		case 4:
			OpcionD(res, mat);
			break;
		case 5:
			OpcionE(res, mat, contador);
			break;
		case 6:
			//OpcionF(actores, peliculas);
			break;
		case 7:
			cout << "Quisiera salir de la aplicacion? (SI = 1, NO = 2)" << endl;
			int respuesta2;
			cin >> respuesta2;
			if (respuesta2 == 1) {
				salir = true;
				break;
			}
			else {}
			break;

		default:
			cout << "numero invalido, intente denuevo" << endl;
		}

		if (salir == true) {
			break;
		}
	}
	return 0;
}