#include <iostream>
#include <string>
#include "Super.hh"
using namespace std;

int main () {
	string str;
	cin >>str;
	Super s;
	bool ini, charge = false; //ERROR si NO inicialitzat o carregat
	while (str != "sortir") {
		if(str == "inicialitzar"){
			s.inicialitzar();
			ini = true;
		}
		else if(str == "carregar"){               
			int L;
			cin >> L;
			s.Carregar_Dades(L);
			charge = true;
		}
		else if(str == "informacio"){
			string item;
			cin >>item;
			cout << "informacio " << item << ":" << endl;
			s.Consultar_Producte(item);	
			cout << endl;
		}
		else if(str == "productes"){
			string si;
			cin >>si;
			cout << "productes " << si << ":" << endl;
			s.Esc_Productes_Seccio(si);	 
			cout << endl;
		}
		else if(str == "millor"){
			string a;
			cin >> a;
			if (a == "cami") {
				int id;
				cin >> id;
				cout << "millor cami << id << ":" << endl;
				s.Consultar_Best_Path(id);
			}
			else{
				cout << "error" << endl;
				cin >> str;
			}
		}
		else if(str == "simular"){
			string a;
			cin >> a;
			if (a == "pagament") {
				int nbox;
				cin >>	nbox;
				cout << "simular pagament:" << endl;
					for (int i = 0; i != nbox; ++i) {
						int CN, CR;
						cin >> CN >> CR;
						s.Sim_pagament(CN, CR);
				}
				cout << endl;
			}
			else {
				cout << "error" << endl;
				cin >> str;
			}
		}
		else cout << "error" << endl;
		cin >>str;
	}
}
