#include "Seccio.hh"

Seccio::Seccio();

bool Seccio::Es_seccio_buida() const{
	return lprod.empty();
}

void Seccio::Escriure_Productes() {
	list<Producte>::iterator it;
	for (it = l.begin; it != l.end(); ++it) {
		cout << (*it).Consultar_nom() << ' ';
	}
	cout << endl;
}