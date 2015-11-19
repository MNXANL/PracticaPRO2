/** @file Producte.hh
    @brief Especificació de la classe Producte
*/
#ifndef PRODUCTE_HH
#define PRODUCTE_HH

//#include "class.hh"
#include <iostream>
#include <string>
using namespace std;

class Producte {
private:
	/** @class  Producte
      @brief Representa un producte del supermercat 
      
      Un producte té un nom, un preu amb dos decimals, i un temps de caixa associats.
	*/
    string nom;
    double preu;
    int temps;
    
public:
	/*@brief Constructora per defecte de producte.
	*\pre cert
	*\post Crea un producte sense nom, preu o temps.
	*/
	Producte();

	/*@brief Constructora de producte amb paràmetres.
	*\pre N no és un string buit; M >= 0.00; T >= 0.
	*\post Crea un producte amb el nom, preu i temps passats pel p.i.
	*/
	Producte(string& n, double& m, int& t);

	/*@brief Consultora del nom del producte.
	*\pre Cert.
	*\post Retorna el nom del producte.
	*/
	string Consultar_nom() const;

	/*@brief Consultora de preu de la classe.
	*\pre Cert.
	*\post Retorna el preu del producte.
	*/
	double Consultar_preu() const;

	/*@brief Consultora de temps de caixer del producte.
	*\pre Cert.
	*\post Retorna el temps de caixer del producte.
	*/
	int Consultar_temps() const;
};
#endif
