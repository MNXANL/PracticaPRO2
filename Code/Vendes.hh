/** @file Vendes.hh
    @brief Especificació de la classe Vendes
*/
#ifndef VENDES_HH
#define VENDES_HH

#include "Client.hh"
#include <iostream>
#include <vector>
using namespace std;

class Vendes {
private:
	/** @class  Vendes
      @brief Representa la informació de vendes del supermercat
      ...
	*/
    vector<Client> vc;
    string temps;

public:

	/*@brief Constructora per defecte de la classe Vendes
	*\pre Cert
	*\post Crea informació de vendes sense clients ni temps associat.
	*/
	Vendes();

	/*@brief Operació carregadora de dades de vendes.
	*\pre mida >= 0
	*\post S'han carregat dades a un vector de clients de mida MIDA.
	*/
	void Carregar_Dades(int& mida);
	
	/*@brief Operació carregadora de dades de vendes.
	*\pre mida >= 0
	*\post 
	*/
	string Consultar_Temps_Sec() const;
	
	/*@brief Operació que simula el pagament de 
	*\pre cn > 0; cn + cr <= Caixes totals
	*\post Escriu pel canal d'entrada estàndar el temps mitjà de pagament del client.
	*/
	void Sim_pagament(int &cn, int &cr);
};
#endif
