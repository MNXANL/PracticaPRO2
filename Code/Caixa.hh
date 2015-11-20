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
      Té una cua que marca els clients que es troben a la cua de la caixa. A més, va sumant 
      els temps d'espera dels clients que es troben a la cua.
    */
	queue<Client> waitc; //Clients esperant a Caixa
	int sumTemps;
	const static int MAX_PROD_RAPID = 10;
	

public:
	/** @brief Constructora per defecte de Caixa
	*\pre Cert
	*\post Crea una caixa sense clients i amb la suma de temps de la cua nul.
	*/
	Caixa();
	
	/** @brief Constructora per defecte de Caixa
	*\pre Cert
	*\post Crea una caixa sense clients i amb la suma de temps de la cua nul.
	*/
	void afegir_client_cua (Client& c);
	
	/** @brief Consulta el temps d'espera de la caixa
	*\pre Hi han clients a la cua waitc.
	*\post Retorna el temps d'espera de la cua de la caixa.
	*/
	int Consultar_Temps_Espera() const;

};
#endif
