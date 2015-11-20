#include "Caixa.hh"


pair<bool, bool> status;
queue<Client> waitc; //Clients esperant a Caixa
const static int MAX_PROD_RAPID = 10;
int sumTemps;

Caixa::Caixa(){
	status.first = status.second = false;
	sumTemps = 0;
}

int Caixa::Consultar_Temps_Espera() const {
	return sumTemps;
}

bool Caixa::es_Oberta() const {
	return status.first;
}

bool Caixa::es_Rapida() const {
	return status.second;
}