#include "Caixa.hh"

Caixa::Caixa(){
	sumTemps = 0;
	cola = 0;
}


int Caixa::Consultar_Temps_Espera() const {
	return sumTemps;
}

void Caixa::Modificar_Caixa_Rapida(bool &tipo){
	es_rapid = tipo;
}

int Caixa::Consulta_Cola() const{
	return cola;
}

void Caixa::Sumar_Element_Cua(string &a){
	++cola;
	wait = a;
}

void Caixa::Null_Cua(){ 
	cola = 0;
}

string Caixa::Consultar_Temps_Caixa() const{
	return wait;
}

bool Caixa::Consultar_Caixa_Oberta() const{
	return lliure;
}

bool Caixa::Consultar_Caixa_Rapida() const{
	return es_rapid;
}

void Caixa::Modificar_Caixa_Oberta(bool &tipo){
	lliure = tipo;
}
