/** @file Caixa.hh
    @brief Especificació de la classe Caixa
*/
#ifndef CAIXA_HH
#define CAIXA_HH

#include "Client.hh"

//No inclosos al diagrama GRAPHVIZ!
#ifndef NO_DIAGRAM	
#include <iostream>
#include <queue>
using namespace std;
//...
#endif

class Caixa {
private:
	/** @class  Caixa
      @brief Representa una Caixa
      Un parell de booleans té el tipus de caixa (status.first determina si és obert o tancat, i status.second
      si és normal o ràpida). Té una cua que marca els clients que es troben a la cua de la caixa. A més, va sumant els
      temps d'espera dels clients que es troben a la cua.
	*/
    pair<bool, bool> status;
    queue<Client> waitc; //Clients esperant a Caixa
    const static int MAX_PROD_RAPID = 10;
    int sumTemps;

public:
	/*@brief
	*\pre
	*\post
	*/
	Caixa();

	/*@brief Consulta el temps d'espera de la caixa
	*\pre Hi han clients a la cua WAITC.
	*\post Retorna el temps d'espera de la cua de la caixa.
	*/
	int Consultar_Temps_Espera();
	
	/*@brief Consultora de caixa oberta
	*\pre cert
	*\post Retorna true si la caixa és oberta
	*/
	bool es_Oberta() const;
	
	/*@brief Consultora de caixa ràpida
	*\pre cert
	*\post Retorna true si la caixa és ràpida
	*/
	bool es_Rapida() const;
};
#endif
