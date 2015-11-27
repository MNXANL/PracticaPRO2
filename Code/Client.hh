/** @file Client.hh
    @brief Especificació de la classe CjtClient
*/
#ifndef CLIENT_HH
#define CLIENT_HH

#include "Super.hh"
#include "Producte.hh"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Client {
private:
	/** @class  Client
      @brief Representa un client.
      Un client té un identificador, un temps d´espera (en format hh:mm:ss), i una llista formada
      pels productes de cada client amb el nom dels productes i la seva quantitat.
	*/
    int compr_id;
    string temps_ticket;
    int mida;
    vector < pair <string, int> > lprod;
    int unitats;

public:
	/** @brief Consultora per defecte de la classe Client
	*\pre Cert
	*\post Retorna un client amb identificador 0, sense productes a la llista i amb temps de tiquet 0.
	*/
	Client();
	
	void Llegir_Productes_Client(int N);
	/** @brief Consultora de identificador de compra del client.
	*\pre Cert.
	*\post Retorna l'identificador de compra.
	*/
	int Consultar_Comprador_ID() const;

	/** @brief Consultora de temps de tiquet.
	*\pre Cert.
	*\post Retorna el temps de tiquet amb el format hh:mm:ss.
	*/
	string Consultar_temps_ticket() const;

	/** @brief Consultora de producte d'un client.
	*\pre La llista LPROD té almenys un producte.
	*\post Retorna true si el client té el producte passat pel p.i.
	*/
	bool te_Producte_Client(string &str);

	/** @brief Lectora de client.
	*\pre Cert.
	*\post Es llegeix un client amb un identificador, un temps de tiquet i una llista de productes, amb la seva quantitat.
	*/
	void Llegir_Client();
	
	//Funcion para si va a una caja rapida o a una caja lenta.
	bool es_rapid();
	int temps_pagament();
};
#endif
