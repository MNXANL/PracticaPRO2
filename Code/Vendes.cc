
#include "Client.hh"
#include <iostream>
#include <vector>
using namespace std;


void Vendes::Carregar_Dades(int& mida) {
	vc = vector<Client> (mida);
	for (int i = 0; i != mida; ++i) {
		vc[i].Llegir_Client();
	}
}


string Vendes::Consultar_Temps_Sec() const {
	return temps;
}


void Vendes::Sim_pagament(int &cn, int &cr) {
	
}