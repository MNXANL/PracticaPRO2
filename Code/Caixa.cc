#include "Caixa.hh"

Caixa::Caixa(){}


int Caixa::Consultar_Temps_Espera() const {
	return sumTemps;
}

void Caixa::tipus(bool tipo){
  es_rapid = tipo;
}
int Caixa::Consulta_Cola(){
  return cola;
}

void Caixa::sumar_cola(string a){
  ++cola;
  wait = a;
}
void Caixa::ini_cola(){
  cola = 0;
}

string Caixa::espera(){
  return wait;
}
bool Caixa::es_libre(){
  return lliure;
}
bool Caixa::es_rapida(){
  return es_rapida();
}

void Caixa::libre(bool tipo){
  lliure = tipo;
}
