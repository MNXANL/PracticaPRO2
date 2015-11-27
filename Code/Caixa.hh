/** @file Caixa.hh
    @brief Especificació de la classe Caixa
*/
#ifndef CAIXA_HH
#define CAIXA_HH

#include <iostream>
#include <queue>
#include "Client.hh"
using namespace std;

class Caixa {
private:
	/** @class  Caixa
      @brief Representa una Caixa
      Un parell de booleans té el tipus de caixa (status.first determina si és obert o tancat, i status.second
      si és normal o ràpida). Té una cua que marca els clients que es troben a la cua de la caixa. A més, va sumant els
      temps d'espera dels clients que es troben a la cua.
    */
    int sumTemps;
    bool es_rapid;
    bool lliure;
    int cola;
    string wait;
public:
	/** @brief
	*\pre
	*\post
	*/
	Caixa();

	/** @brief Consulta el temps d'espera de la caixa
	*\pre Hi han clients a la cua WAITC.
	*\post Retorna el temps d'espera de la cua de la caixa.
	*/
	string espera();
	
	/** @brief
	*\pre
	*\post
	*/
	int Consultar_Temps_Espera() const;
	
	/** @brief
	*\pre
	*\post
	*/
	bool es_rapida();
	
	/** @brief
	*\pre
	*\post
	*/
	bool es_libre();
	
	/** @brief
	*\pre
	*\post
	*/
	void tipus(bool tipo);
	
	/** @brief
	*\pre
	*\post
	*/
	void libre(bool tipo);
	
	/** @brief
	*\pre
	*\post
	*/
	int Consulta_Cola();
	
	/** @brief
	*\pre
	*\post
	*/
	void sumar_cola(string a);
	
	/** @brief
	*\pre
	*\post
	*/
	void ini_cola();
	
	/** @brief
	*\pre
	*\post
	*/
	int num_prod();
};
#endif
