#include "Producte.hh"


Producte::Producte() {
	preu = temps = 0;
}

string Producte::Consultar_nom() const{
	return producte_id;
}

double Producte::Consultar_preu() const{
	return preu;
}

string Producte::Consultar_seccio() const{
	return seccio;
}

int Producte::Consultar_temps() const{
	return temps;
}

void Producte::Llegir_Producte(){
	cin >> producte_id >> preu >> seccio >> temps;
}
void Producte::Escriure_Producte(){
	cout << producte_id << " "<< preu << " " << seccio << " " << temps << endl;
}