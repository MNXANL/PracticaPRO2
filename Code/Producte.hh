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
    string producte_id;
    double preu;
    int temps;
    string seccio;
    
public:
	/** @brief Constructora per defecte de producte.
	*\pre cert
	*\post Crea un producte sense nom, preu o temps.
	*/
	Producte();
//Consultoras
	
	/** @brief Consultora del nom del producte.
	*\pre Cert.
	*\post Retorna el nom del producte.
	*/
	string Consultar_nom() const;
	
	/** @brief Consultora de secció de la classe.
	*\pre Cert.
	*\post Retorna la secció del producte.
	*/
	string Consultar_seccio();

	/** @brief Consultora de preu de la classe.
	*\pre Cert.
	*\post Retorna el preu del producte.
	*/
	double Consultar_preu() const;

	/** @brief Consultora de temps de caixer del producte.
	*\pre Cert.
	*\post Retorna el temps de caixer del producte.
	*/
	int Consultar_temps() const;
	
	string Consultar_seccio();
	
//Lectura/Escritura
	
	/** @brief
	*\pre
	*\post
	*/s
	void llegir_producte();
	
	/** @brief
	*\pre
	*\post
	*/
	void escriure_producte();
	
};
#endif
