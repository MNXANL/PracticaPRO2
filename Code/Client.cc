#include "Client.hh"

void Client::Llegir_Productes_Client() {
	//Revisar!
	list<pair <string, int> >::iterator it;
	for (it = lprod.begin(); it != lprod.end(); ++it) {
		pair<string, int> ps;
		cin >> ps.first >> ps.second;
		lprod.insert(lprod.end(),ps);
	}
}


Client::Client(){

}

int Client::Consultar_Comprador_ID() const{
	return compr_id;
}

    list <pair <string, int> > lprod;
string Client::Consultar_temps_ticket() const {
	return temps_ticket;
}

bool Client::te_Producte_Client(string &str) {
	list<pair <string, int> >::iterator it;
	for (it = lprod.begin(); it != lprod.end(); ++it) {
		if ((*it).first == str) return true;
	}
	return false;
}



void Client::Llegir_Client() {
	//Revisar!
}
