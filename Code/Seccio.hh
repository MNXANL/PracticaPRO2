/** @file Seccio.hh
    @brief Especificació de la classe Seccio
*/
#ifndef SECCIO_HH
#define SECCIO_HH

#include "Producte.hh"
#include <iostream>
#include <list>
using namespace std;

class Seccio {
private:
	/** @class  Secció
      @brief Representa una secció del supermercat.
      Aquesta secció té una llista de productes
	*/
    list<Producte> lprod;

public:
	/*@brief Constructora per defecte de la classe 
	*\pre Cert
	*\post 
	*/
	Seccio();

	/*@brief Consultora de secció buida
	*\pre Cert
	*\post Retorna true si la secció és buida; altrament retorna false.
	*/
	bool Es_seccio_buida() const;

	/*@brief Operacio escriptora
	*\pre LPROD no és buit
	*\post Escriu pel canal d'entrada estàndar els productes de LPROD.
	*/
	void Escriure_Productes();
};
#endif
