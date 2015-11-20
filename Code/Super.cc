#include "Super.hh"


Super::Super() {
	
}

void Super::Consultar_Best_Path(int &id) {
	
}


void Super::Afegir_Productes(){
	
}

void Super::Llegir_Super() {
	char c[] = "XX";
	cin >> c[0] >>c[1];
	int box; cin >>box;
	
}

void Super::Esc_Productes_Seccio(string &si) {
	map<string, Seccio>::iterator it = layout.find(si);
	if (it == end) cout << "error" << endl;
	else {
		Seccio sec = it->second;
		sec.Escriure_Productes();
	}
}