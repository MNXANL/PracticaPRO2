/** @file Super.hh
    @brief Especificació de la classe CLASSE
*/
#ifndef SUPER_HH
#define SUPER_HH

#include "Seccio.hh"
#include "Vendes.hh"
#include "Caixa.hh"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Super {
private:
	/** @class  Super
      @brief Representa un supermercat
      Un supermercat té 
	*/
	map <string, Seccio> Layout;
	vector<Caixa> Caixes;
	//const static string MAX_SIZE = "Z9";
	const static int MAX_BOX = 20;


public:
	/** @brief Constructora per defecte de la classe 
	\pre Cert
	\post Es construeix un supermercat buit sense caixes.
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
	void Afegir_Productes();

    /** @brief Lectura de dades del supermercat
	*\pre Cert
	*\post S'han llegit les dades de la mida del supermercat i les caixes, i s'han afegit un conjunt de productes al supermercat.
	*/
	void Llegir_Super();

	/** @brief
	*\pre El p.i. és una secció del supermercat.
	*\post Escriu els productes que es troben a la secció del supermercat, per ordre alfabétic.
	*/
    void Esc_Productes_Seccio(string &si);

};
#endif
