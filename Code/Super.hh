/** @file Super.hh
    @brief Especificació de la classe CLASSE
*/
#ifndef SUPER_HH
#define SUPER_HH

#include "Seccio.hh"
#include "Vendes.hh"
#include "Caixa.hh"
#include "Producte.hh"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Super {
private:
	/** @class  Super
      @brief Representa un supermercat
      Un supermercat té 
	*/
 
    vector<Caixa> Caixes;
    vector<Producte> Productes;
    int rengles;
    int columnes;
    int caixes;


public:
	/** @brief Constructora per defecte de la classe 
	*\pre Cert
	*\post Es construeix un supermercat buit sense caixes.
	*/
	Super();

	/** @brief Operació consultora del millor camí per a un client del supermercat.
	*\pre El p.i. és l'identificador d'un client del supermercat
	*\post Escriu pel canal de sortida estàndar la llargada del millor camí, seguit de la 
	seqüència òptima de camins que ha de fer el client.
	*/
	void Consultar_Best_Path(int &id);

	/** @brief Operacio que afegeix productes al supermercat.
	*\pre Entren pel p.i. productes
	*\post Els productes s'han afegit a les seccions corresponents del supermercat.
	*/
	void Sim_pagament(int normal, int rapida);
	
	/** @brief
	*\pre
	*\post
	*/
	void inicialitzar();  
	
	/** @brief
	*\pre
	*\post
	*/
	void Esc_Productes_Seccio(string &si);
	
	/** @brief
	*\pre
	*\post
	*/
	void Consultar_Producte(string item);
};
#endif
