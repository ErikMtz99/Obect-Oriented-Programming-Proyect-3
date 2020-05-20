#include <iostream>
#include "Fecha.h"

using namespace std;

class Reserva {
public:
	Reserva();
	Reserva(int m, int c, Fecha f);
	void setIdMaterial(int i) { idMaterial = i; };
	void setIdCliente(int c) { idCliente = c; };
	void setFechaReservacion(Fecha f) { fechaReservacion = f; };
	int getIdMaterial() { return idMaterial; };
	int getIdCliente() { return idCliente; };
	Fecha getFechaReservacion() { return fechaReservacion; };

	Fecha calculaFechaFinReserva(int cantDias);

private:
	int idMaterial, idCliente;
	Fecha fechaReservacion;
};

Reserva::Reserva() {
	Fecha rd;
	idMaterial = 0;
	idCliente = 0;
	fechaReservacion = rd;
}
Reserva::Reserva(int m, int c, Fecha f) {
	idMaterial = m;
	idCliente = c;
	fechaReservacion = f;
}

Fecha Reserva::calculaFechaFinReserva(int cantDias) {
	int anio = fechaReservacion.getAA();
	int mess = fechaReservacion.getMM();
	int diaa = fechaReservacion.getDD();
	if (mess = 12) {
		if (diaa + cantDias > 30) {
			diaa = (diaa + cantDias) - 30;
			mess = 1;
			anio = anio + 1;
		}
		else {
			diaa = (diaa + cantDias);
		}
	}
	else {
		if (diaa + cantDias > 30) {
			diaa = (diaa + cantDias) - 30;
			mess = mess + 1;
		}
		else {
			diaa = (diaa + cantDias);
		}
	}
	Fecha fin_reserva(diaa, mess, anio);
	return fin_reserva;
}