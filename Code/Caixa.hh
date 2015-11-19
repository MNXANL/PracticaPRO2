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

};
#endif
