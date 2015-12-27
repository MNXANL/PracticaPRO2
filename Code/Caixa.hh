/** @file Caixa.hh
	@brief Especificació de la classe Caixa
*/
#ifndef CAIXA_HH
#define CAIXA_HH

#include "Client.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

class Caixa {
private:
	/** @class  Caixa
		@brief Representa una caixa del supermercat.

		Conserva la suma dels temps, té dos booleans que determinen si la caixa és ràpida i oberta, 
		respectivament, i el temps d'espera en caixa.
	*/
	int sumTemps;
	bool es_rapid;
	bool lliure;
	int cola;
	string wait;

public:
	//CONSTRUCTORA

	/** @brief Constructora per defecte de Caixa
	*\pre Cert
	*\post Crea una caixa sense elements a la cua ni suma de temps.
	*/
	Caixa();

	//CONSULTORES
	/** @brief Consulta el temps d'espera de la caixa
		*\pre cert
		*\post Retorna el temps d'espera de la cua de la caixa.
	*/
	int Consultar_Temps_Espera() const;

	/** @brief Consultora de cua de la caixa.
		*\pre Cert
		*\post Retorna el número d'elements en cua de la caixa.
	*/
	int Consulta_Cola() const;

	/** @brief Consultora del temps d'espera del producte.
		*\pre Cert.
		*\post Retorna el temps d'espera del producte.
	*/
	string Consultar_Temps_Caixa() const;
	
	/** @brief Consultora de caixa oberta.
		*\pre Cert.
		*\post Retorna cert si la caixa és oberta; si és tancada, retornarà fals.
	*/ 
	bool Consultar_Caixa_Oberta() const;
	
	/** @brief 
		*\pre Cert.
		*\post Retorna cert si és una caixa ràpida; si és normal retornarà fals.
	*/
	bool Consultar_Caixa_Rapida() const;

	//MODIFICADORES
	/** @brief Operació de suma d'un element a una cua de la caixa.
		*\pre <em>a</em> té format "hh:mm:ss"
		*\post S'ha sumat un element a la cua; a passa a ser el temps d'espera de la caixa.
	*/
	void Sumar_Element_Cua(string &a);

	/** @brief Operació que anula la cua de la caixa.
		*\pre Cert
		*\post La caixa no té elements en cua.
	*/
	void Null_Cua();
	
	/** @brief Modificadora de caixa ràpida
		*\pre <em>tipo</em> denota si la caixa serà ràpida (śi és cert) 
		*\post Si <em>tipo</em> és cert, la caixa és ràpida; altrament és normal.
	*/
	void Modificar_Caixa_Rapida(bool &tipo);

	/** @brief Operació modificadora de caixa oberta.
		*\pre <em>tipo</em> denota si la caixa serà oberta (si és cert)
		*\post Si <em>tipo</em> és cert, la caixa és oberta; altrament és tancada.
	*/
	void Modificar_Caixa_Oberta(bool &tipo);
};
#endif
