/** @file Producte.hh
	@brief Especificació de la classe Producte
*/
#ifndef PRODUCTE_HH
#define PRODUCTE_HH


#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
using namespace std;

class Producte {
private:
	/** @class  Producte
		@brief Representa un producte del supermercat 

		Un producte té un nom, un preu amb dos decimals, la secció on es troba i un temps de caixa associats.
	*/
	string producte_id;
	double preu;
	string seccio;
	int temps;

public:
	//CONSTRUCTORA

	/** @brief Constructora per defecte de producte.
	*\pre Cert.
	*\post Crea un producte sense nom, preu o temps.
	*/
	Producte();

	//CONSULTORES

	/** @brief Consultora de nom del producte.
	*\pre Cert.
	*\post Retorna el nom del producte.
	*/
	string Consultar_nom() const;

	/** @brief Consultora de secció del producte.
	*\pre Cert.
	*\post Retorna la secció del producte.
	*/
	string Consultar_seccio() const;

	/** @brief Consultora de preu del producte.
	*\pre Cert.
	*\post Retorna el preu del producte.
	*/
	double Consultar_preu() const;

	/** @brief Consultora de temps del producte.
	*\pre Cert.
	*\post Retorna el temps del producte.
	*/
	int Consultar_temps() const;

	//LECTURA I ESCRIPTURA
	
	/** @brief Lectora de producte.
	*\pre Cert.
	*\post Llegeix les dades del producte (el identificador de producte, el seu preu, secció i temps).
	*/
	void Llegir_Producte();

	/** @brief Escriptora de producte.
	*\pre El producte té dades.
	*\post Escriu el identificador de producte, el preu, secció i temps del producte.
	*/
	void Escriure_Producte();
};
#endif
