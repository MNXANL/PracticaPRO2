/** @file Client.hh
	@brief Especificació de la classe Client
*/
#ifndef CLIENT_HH
#define CLIENT_HH

#include "Producte.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif

using namespace std;

class Client {
private:
	/** @class  Client
		@brief Representa un client del supermercat.

		Un client té un identificador, un temps de tiquet (en format hh:mm:ss), el temps d'espera (en segons), 
		el nombre de productes que té, un vector format per un parell amb el nom dels productes i la seva quantitat, i 
		les unitats que té el client en total.
	*/
	int compr_id;
	string temps_ticket;
	int mida;
	vector < pair <string, int> > lprod;
	int unitats;
	int temps_de_pagar;

	//OPERACIONS PRIVADES

	/** @brief Lectora dels productes del client.
		*\pre <em>N</em> > 0.
		*\post S'han llegit els productes del client i s'haurà obtingut el seu temps de pagament.
	*/
	void Llegir_Productes_Client(int &N, vector<Producte> &Productes);
    
public:
	//CONSTRUCTORA

	/** @brief Consultora per defecte de la classe Client.
		*\pre Cert.
		*\post Retorna un client amb identificador 0, sense productes i amb temps de tiquet 0.
	*/
	Client();

	//CONSULTORES

	/** @brief Consultora de mida dels productes d'un client.
		*\pre Cert.
		*\post Retorna el número de productes del client.
	*/
	int Consultar_Mida_Client() const;

	/** @brief Consultora del producte i-èssim del client.
		*\pre Hi han productes a lprod (és a dir, lprod.first.size() != 0). 0 <= <em>v[i]</em> < lprod.first.size().
		*\post Retorna el nom del producte de la posició i-èssima.
	*/
	string Consultar_prod_iessim_llista(int &i) const;

	/** @brief Consultora del temps de pagament del client.
		*\pre Cert.
		*\post Retorna el temps de pagament del client.
	*/
	int Consultar_Temps_Pagament() const;

	/** @brief Consultora de identificador de compra del client.
		*\pre Cert.
		*\post Retorna l'identificador de compra.
	*/
	int Consultar_Comprador_ID() const;

	/** @brief Consultora del número de productes d'un client.
		*\pre lprod.first.size() != 0.
		*\post Retorna el número de productes del client
	*/
	int Consultar_Num_Productes() const;

	/** @brief Consultora de temps de tiquet.
		*\pre Cert.
		*\post Retorna el temps de tiquet amb el format hh:mm:ss.
	*/
	string Consultar_temps_ticket() const;

	/** @brief Modificadora del temps de tiquet del client.
		*\pre <em>a</em> és un string amb format "hh:mm:ss".
		*\post El temps de tiquet passa a ser el temps passat pel paràmetre implícit.
	*/
	void Modifica_Temps_Ticket(string &a);


	/** @brief Lectora de client.
		*\pre Cert.
		*\post S'haurà llegit un client amb un identificador, un temps de tiquet i temps de pagament, 
		i una llista de productes, amb la seva quantitat.
	*/
	void Llegir_Client(vector<Producte> &Productes);


	/** @brief Funció per veure si un client va a parar a una caixa ràpida o normal.
		*\pre Hi ha com a mínim una caixa oberta.
		*\post Retorna cert si el client va una caixa ràpida; si va a una caixa normal, retornarà fals.
	*/
	bool Es_Client_Rapid() const;

};
#endif
