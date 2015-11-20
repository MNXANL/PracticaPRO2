#include "Caixa.hh"



Caixa::Caixa(){
	sumTemps = 0;
}

int Caixa::Consultar_Temps_Espera() const {
	return sumTemps;
}
