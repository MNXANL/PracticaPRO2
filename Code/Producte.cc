#include "Producte.hh"


Producte() {
	preu = 0;
	temps = 0;
}

Producte::Producte(string& n, double& m, int& t) {
	this->n = nom;
	this->m = preu;
	this->n = temps;
}

string Producte::Consultar_nom() const {
	return nom;
}

double Producte::Consultar_preu() const {
	return preu;
}

int Producte::Consultar_temps() const {
	return  temps;
}