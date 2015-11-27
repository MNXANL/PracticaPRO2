#include "Super.hh"
#include "Producte.hh"

Super::Super() {
	
}

void Super::Consultar_Best_Path(int &id) {
	
}


void Super::inicialitzar(){
	cin >> rengles >> columnes >> caixes;
	int n;
	cin >> n;
	Productes = vector <Producte>(n);
	for(int i = 0; i < n; ++i) {
	  Productes[i].llegir_producte();
	}
}
void Super::Sim_pagament(int normal, int rapida){
  //Done
}

void Super::Esc_Productes_Seccio(string &si) {
	bool first = true;
	bool buit = true;
	for(int i = 0; i < Productes.size(); ++i){
	  if(Productes[i].Consultar_seccio() == si){
	    buit = false;
	    if(not first) cout << " ";
	    first = false;
	    cout << Productes[i].Consultar_nom();
	  }
	}
	if(buit) cout << "seccio buida" << endl;
	else cout << endl;
}
void Super::Consultar_Producte(string item){
	bool sigue = true;
	for(int i = 0; i < Productes.size() and sigue; ++i){
	  if(Productes[i].Consultar_nom() == item){
	    Productes[i].escriure_producte();
	    sigue = false;
	  }
	}
}