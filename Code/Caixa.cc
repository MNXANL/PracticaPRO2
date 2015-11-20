#include "Caixa.hh"



Caixa::Caixa(){
	sumTemps = 0;
}

void Caixa::afegir_client_cua (Client& c) {
	//Operaciones «++sumTemps» van aqui
	waitc.push(c);
}


int Caixa::Consultar_Temps_Espera() const {
	return sumTemps;
}
