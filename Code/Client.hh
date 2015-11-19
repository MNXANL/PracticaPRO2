/** @file Client.hh
    @brief Especificació de la classe CjtClient
*/
#ifndef CLIENT_HH
#define CLIENT_HH

#include "Producte.hh"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Client {
private:
	/** @class  Client
      @brief Representa un client 
      Un client té un identificador, un temps d´espera (en format hh:mm:ss), i una llista formada
      pels productes de cada client amb el nom dels productes i la seva quantitat.
	*/
    int id;
    string temps_ticket;
    list <pair <string, int> > lprod;

public:
	/*@brief Consultora per defecte de la classe Client
	*\pre Cert
	*\post Retorna un client amb identificador 0, sense productes a la llista i amb temps de tiquet 0.
	*/
	Client();

};
#endif
