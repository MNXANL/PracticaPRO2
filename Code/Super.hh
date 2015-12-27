/** @file Super.hh
	@brief Especificació de la classe Super
*/
#ifndef SUPER_HH
#define SUPER_HH

#include "Caixa.hh"
#include "Producte.hh"
#include "Client.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <cmath>
#endif
using namespace std;

	//COMPARADORS
	/** @brief Comparador de dues strings.
		*\pre <em>a</em> i <em>b</em> tenen format "hh:mm:ss".
		*\post Retorna cert si <em>a < b</em>; altrament retorna fals.
	*/
	bool mayorstring(string &a, string &b);
	
	/** @brief Comparador de temps de dos clients.
		*\pre Cert.
		*\post Retorna cert si els <em>temps de x < temps de y </em>; altrament retorna fals.
	*/
	bool mayor(Client x, Client y) ;

	/** @brief Comparador que ordena alfabèticament dues paraules.
		*\pre Cert.
		*\post Retorna cert si <em>a < b</em>; altrament retorna fals.
	*/
	bool alfabetico(const string &a, const string &b);

class Super {
private:
	/** @class  Super
		@brief Representa un supermercat.

		Un supermercat té tres vectors format per les seves caixes, productes i clients, a més de 
		la seva mida (rengles per columnes), les seves caixes, el número de productes del supermercat
		i la mida del camí mínim (MidaCami).
	*/

	vector<Caixa> Caixes;
	vector<Producte> Productes;
	vector<Client> VClients;
	int rengles;
	int columnes;
	int caixes;
	int num_producte;
	int MidaCami;


	//OPERACIONS PRIVADES
	/** @brief Operació consultora de distància entre dues seccions.
		*\pre <em>a</em> i <em>b</em> són dues seccions del supermercat.
		*\post Retorna la distància entre les posicions <em>a</em> i <em>b</em>.
	*/
	int dist(string &a, string &b);

	/** @brief Consultora de número menor.
		*\pre <em>a</em> i <em>b</em> tenen la mateixa mida.
		*\post Retorna cert si <em>a < b</em>; altrament retorna fals.
	*/
	bool menor(vector<string> &a, vector<string> &b);

	/** @brief Operació que realitza les permutacions per trobar el camí òptim.
		*\pre <em>v</em> té el vector principal de les permutacions en ordre alfabètic; <em>i</em> té la posició de la iteració
		actual del vector; <em>ini</em> i <em>fin</em> tenen les posicions A1 i A[rengles] respectivament, i <em>suma</em> té el sumatori dels elements 
		de les distàncies entre v[0..i].
		*\post Result té la seqüència del camí òptim mínim excepte les posicions <em>ini</em> i fin. Al paràmetre privat 
		CamiMinim s'indica la llargada del camí òptim.
	*/
	void permute (vector<string> &v, int i, vector<string> &result, string &ini, string &fin, int suma);

	/** @brief Operació que inserta els elements d'un conjunt en un vector.
		*\pre El tamanys de <em>s</em> i <em>v</em> són el mateix.
		*\post Els elements del conjunt <em>s</em> passen a <em>v</em>; <em>s</em> és buida.
	*/
	void settovector(vector<string> &v, set<string> &s);


	/** @brief Operació consultora de la posició d'un client en la caixa de menor cua.
		*\pre <em>ini</em> és la posició inicial del client, <em>person</em> és un client del supermercat.
		*\post <em>pos</em> assigna a quina caixa va el client.
	*/
	void Posicio_Que_Toca(int& ini, vector<Caixa> &VCaixa, Client &person, int &pos);

	/** @brief Operació de suma de temps entre un temps determinat i els segons a afegir.
		*\pre <em>hora</em> té format "hh:mm:ss", i suma representa segons.
		*\post Retorna un string amb els temps d'<em>hora</em> amb els segons de <em>suma</em> afegits.
	*/
	string Suma_Temps(string hora, int suma);

	/** @brief Operacio de diferència de dos intervals de temps.
		*\pre <em>a</em> i <em>b</em> tenen un format "hh:mm:ss".
		*\post Retorna la diferència de temps entre <em>a</em> i <em>b</em>.
	*/
	int Diferencia(string &a, string &b);


public:
	//CONSTRUCTORA

	/** @brief Constructora per defecte de la classe.
		*\pre Cert.
		*\post Es construeix un supermercat buit sense caixes.
	*/
	Super();

	//CONSULTORES

	/** @brief Operació consultora del millor camí per a un client del supermercat.
		*\pre El p.i. és l'identificador d'un client del supermercat.
		*\post Escriu pel canal de sortida estàndar la llargada del millor camí, seguit de la 
		seqüència òptima de camins que ha de fer el client.
	*/
	void Consultar_Best_Path(int &id);

	/** @brief Consultora del número de caixes del supermercat
		*\pre Cert.
		*\post Retorna el número de caixes del supermercat.
	*/
	int Consultar_Caixes() const;
	
	/** @brief Consultora de producte
		*\pre El supermercat té al menys un producte
		*\post Si <em>item</em> es troba a supermercat, escriurà pel canal de sortida les seves dades. 
		En cas contrari, escriurà «error».
	*/
	void Consultar_Producte(string &item);

	/** @brief Consultora del número de productes del supermercat.
		*\pre Cert.
		*\post Retorna el número de productes del supermercat.
	*/
	int Consulta_Num_Productes() const;

	//MODIFICADORES I OPERACIONS

	/** @brief Operació de simulació del pagament d'un supermercat
		*\pre <em>normal+rapida</em> < caixes; <em>normal</em> no és igual a 0.
		*\post Escriu pel canal de sortida estàndar una simulació del pagament amb les caixes normals i ràpides del p.i.
	*/
	void Sim_Pagament(int &normal, int &rapida);

	//LECTURA I ESCRIPTURA

	/** @brief Inicialitzadora i lectora de dades del supermercat.
		*\pre Cert.
		*\post Ha inicialitzat el supermercat, amb un tamany, caixes i productes escrits pel canal d'entrada.
	*/
	void Inicialitzar();  

	/** @brief Operacio de lectura que afegeix productes al supermercat.
		*\pre <em>medida</em> > 0.
		*\post S'han llegit pel canal d'entrada i afegits al supermercat les dades de tants clients com <em>medida</em>.
	*/
	void Carregar_Dades(int& medida);

	/** @brief Escriptora dels productes d'una secció.
		*\pre <em>si</em> forma part dels productes del supermercat.
		*\post Escriu pel canal de sortida els productes de la secció <em>si</em>.
	*/
	void Esc_Productes_Seccio(string &si);

};
#endif
