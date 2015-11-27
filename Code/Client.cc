#include "Client.hh"
#include "Super.hh"
void Client::Llegir_Client(vector<Producte> Productes) {
	cin >> compr_id >> temps_ticket >> mida;
	Llegir_Productes_Client(mida, Productes);
}


void Client::Llegir_Productes_Client(int N, vector<Producte> Productes) {	
	lprod = vector < pair <string, int> >(N);
	unitats=0;
	temps_de_pagar = 0;
	for (int i = 0; i < mida; ++i) {
		pair<string, int> ps;
		cin >> ps.first >> ps.second;
		unitats += ps.second;
		lprod[i].first = ps.first;
		lprod[i].second = ps.second;
		for(int j=0; j < Productes.size(); ++j){
		  if(lprod[i].first == Productes[j].Consultar_nom()){
		    temps_de_pagar += Productes[j].Consultar_temps()*lprod[i].second;
		  }
		}
	}
}


Client::Client(){

}

string Client::llista(int i){
  return lprod[i].first;
}

int Client::temps_tarda(){
  return temps_de_pagar;
}
int Client::Consultar_Comprador_ID(){
	return compr_id;
}

int Client::num_productes(){
  return lprod.size();
}
    
string Client::Consultar_temps_ticket(){
	return temps_ticket;
}

void Client::modifica_temps_ticket(string a){
  temps_ticket = a;
}
bool Client::es_rapid(){
      return unitats <= 10;
}




