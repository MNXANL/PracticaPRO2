#include "Producte.hh"


Producte::Producte() {

}

string Producte::Consultar_nom() {
	return producte_id;
}

double Producte::Consultar_preu() {
	return preu;
}

string Producte::Consultar_seccio() {
	return seccio;
}
int Producte::Consultar_temps()  {
	return  temps;
}

void Producte::llegir_producte(){
    cin >> producte_id >> preu >> seccio >> temps;
}
void Producte::escriure_producte(){
    cout << producte_id << " "<< preu << " " << seccio << " " << temps << endl;
}