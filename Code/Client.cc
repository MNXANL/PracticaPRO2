#include "Client.hh"
#include "Super.hh"


void Client::Llegir_Client(vector<Producte> &Productes) {
	cin >> compr_id >> temps_ticket >> mida;
	Llegir_Productes_Client(mida, Productes);
}


void Client::Llegir_Productes_Client(int &N, vector<Producte>& Productes) {	
	lprod = vector < pair <string, int> >(N);
	for (int i = 0; i != mida; ++i) {
		pair<string, int> ps;
		cin >> ps.first >> ps.second;
		unitats += ps.second;
		lprod[i] = ps;
		for (int j = 0; j < Productes.size(); ++j){
			if (lprod[i].first == Productes[j].Consultar_nom()){
				temps_de_pagar += Productes[j].Consultar_temps()*lprod[i].second;
			}
		}
	}
}


Client::Client(){
	compr_id = 0;
	unitats = 0;
	temps_de_pagar = 0;
}

int Client::Consultar_Mida_Client() const{
	return mida;
}

string Client::Consultar_prod_iessim_llista(int &i) const{
	return lprod[i].first;
}

int Client::Consultar_Temps_Pagament() const{
	return temps_de_pagar;
}

int Client::Consultar_Comprador_ID() const{
	return compr_id;
}

int Client::Consultar_Num_Productes() const{
	return lprod.size();
}
	
string Client::Consultar_temps_ticket() const{
	return temps_ticket;
}

void Client::Modifica_Temps_Ticket(string &a){
	temps_ticket = a;
}

bool Client::Es_Client_Rapid() const{
	return unitats <= 10;
}




