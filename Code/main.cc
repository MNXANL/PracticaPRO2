/**
 * @mainpage Pàgina principal del Doxygen per a la pràctica de PRO2
 
En aquesta pràctica l'objectiu és dissenyar i simular un supermercat optimitzat, que vol
trobar tant els recorreguts òptims per als clients com organitzar eficientment les caixes del supermercat.
*/

/** @file main.cc
    @brief Programa principal de la practica de Programació 2.
*/

#include <iostream>
#include <string>
#include <Super.hh>
using namespace std;

/** @brief Funció principal de la pràctica.
*/
int main () {
	string str;
	cin >>str;
	Super s;
		while (str != "sortir") {
		switch(str) {
			case "inicialitzar":
				s.Llegir_Super();
				s.Afegir_Productes();
			case "carregar":
				Vendes v;
				int L;
				cin >>L;
				v.Carregar_Dades(L);
			case "informacio":
				string item;
				cin >>item;
				s.Consultar_Producte(item);
			case "productes":
				string si;
				cin >>si;
				s.Esc_Productes_Seccio(si);
			case "millor cami":
				int id;
				cin >> id;
				s.Consultar_Best_Path(id);
			case "simular pagament":
				int nbox;
				cin >>nbox;
				for (int i = 0; i != nbox; ++i) {
					int tn, tr;
					cin >>tn >>tr;
					s.Sim_pagament(tn, tr);
				}
			default:
				cout << "error" << endl;
		}
		cin >>str;
	}
}
