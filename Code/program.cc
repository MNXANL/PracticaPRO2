
/**
 * @mainpage Documentació Doxygen de la pràctica de PRO2 del QT 2015/2016 
 
Aquesta pràctica es composa d'un programa modular que té com a objectiu principal 
gestionar un supermercat, amb les dades dels clients i els seus productes. Així, podem calcular 
el camí òptim per als productes d'un client i simular les caixes del supermercat per minimitzar 
el temps de caixa dels clients. A més, ens permet consultar la informació dels productes i de 
quins n'hi han a la secció, sempre i quan estiguin al supermercat.

Es composa de les classes <em>Super</em>, <em>Caixa</em>, <em>Client</em> i <em>Producte</em>.



Pràctica desenvolupada per a l'assignatura de Programació 2 de la Facultat d'Informàtica de 
Barcelona el quadrimestre de tardor de 2015/2016 per Jaime Arroyo i Miguel Moreno.

*/

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

#include "Super.hh"
using namespace std;


/** @brief Programa principal de la pràctica de PRO2.
*/
int main () {
	string str;
	cin >>str;
	Super s;
	bool inicial, carregat;
	inicial = carregat = false;
	while (str != "sortir") {
		if (str == "inicialitzar"){
			Super X;
			X.Inicialitzar();
			s = X;
			inicial = true;
			carregat = false;
		}
		
		else if (str == "carregar"){
			if (inicial) {
				int L;
				cin >> L;
				s.Carregar_Dades(L);
				carregat = true;
			}
			else cout << "error" << endl;
		}
		
		else if(str == "informacio"){
			if (inicial) {
				string item;
				cin >>item;
				cout << "informacio " << item << ":" << endl;
				s.Consultar_Producte(item);
				cout << endl;
			}
			else cout << "error" << endl;
		}
		
		else if (str == "productes"){
			if (inicial){
				string si;
				cin >>si;
				cout << "productes " << si << ":" << endl;
				s.Esc_Productes_Seccio(si);	 
				cout << endl;
			}
			else cout << "error" << endl;
		}
		
		else if (str == "millor"){
			int id;
			string a;
			cin >> a;
			if (a=="cami" and inicial and carregat){
				cin >> id;
				s.Consultar_Best_Path(id);
			}
			else cout << "error" << endl;
		}
		
		else if (str == "simular"){
			string a;
			cin >> a;
			if (a == "pagament" and inicial and carregat){
				int nbox;
				cin >>	nbox;
				cout << "simular pagament:" << endl;
				for (int i = 0; i != nbox; ++i) {
					int CN, CR;
					cin >> CN >> CR;
					s.Sim_Pagament(CN, CR);
				}
				cout << endl;
			}
			else cout << "error" << endl;
		}
		//else cout << "error" << endl;
		cin >>str;
	}
}
