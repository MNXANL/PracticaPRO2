#include "Super.hh"


Super::Super() {
	rengles = 0;
	columnes = 0;
	caixes = 0;
	num_producte = 0;
	MidaCami = 0;
}


int Super::dist(string &a, string &b){
	int vert, hor;
	vert = abs(a[0] - b[0]);
	hor = abs((a[1] - '0') - (b[1] - '0'));
	return vert + hor;
}

bool Super::menor(vector<string> &a, vector<string> &b){
	for(int i = 0; i < a.size(); ++i){
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

void Super::permute (vector<string> &v, int i, vector<string> &result, string &ini, string &fin, int suma) {
	if (i == v.size()-1) {
		if (i == 1) suma = dist(v[i-1], ini);
		suma += dist(v[i], v[i-1]);
		suma += dist(v[i], fin);
		if (suma < MidaCami) {
			MidaCami = suma;
			result = v;
		}
		if (suma == MidaCami and menor(v, result)){
			result = v;
		}
	}
	else {
		for (int j = i; j < v.size(); ++j) {
			swap(v[i], v[j]);
			if (i > 0){
				if (i == 1) suma = dist(v[i-1], ini);
				suma += dist(v[i], v[i-1]);
			}
			if (suma < MidaCami) {
				permute(v, i+1, result, ini, fin, suma);
			}
			if (i > 0) suma -= dist(v[i], v[i-1]);
			swap(v[i], v[j]); //BCKTRCK
		}
	}
}


bool alfabetico(const string &a, const string &b) {
	return a < b;
}

void Super::settovector(vector<string> &v, set<string> &s) {
	set<string>::iterator it = s.begin();
	for (int i = 0; i != v.size(); ++i) {
		v[i] = (*it); 
		++it;
	}
	s.clear();
}

void Super::Consultar_Best_Path(int &id) {
	Client x;
	MidaCami = rengles*columnes;
	bool keep = true;
	for (int i = 0; i < VClients.size() and keep; ++i){
		if (id == VClients[i].Consultar_Comprador_ID()){
			x = VClients[i];
			keep = false;
		}
	}
	if (not keep) {
		vector <string> prod(x.Consultar_Mida_Client());
		set <string, less<string> > lper;
		string ultima = "A0";
		ultima[1] = columnes + '0';
		for(int i = 0; i < x.Consultar_Mida_Client(); ++i){
			prod[i] = x.Consultar_prod_iessim_llista(i);
		}
		for(int k = 0; k < x.Consultar_Mida_Client(); ++k){
			keep = true;
			for (int i = 0; i != num_producte and keep; ++i){
				if (Productes[i].Consultar_nom() == prod[k]){
					prod[k] = Productes[i].Consultar_seccio();
					if(prod[k] != "A1" and prod[k] != ultima){
						lper.insert(prod[k]);
					}
					keep = false;
				}
			}
		}
		vector<string> cami (lper.size(), ultima);
		vector<string> perm (lper.size());
		settovector(perm, lper);
		string primera = "A1";
		if (columnes == 1){
			if (cami.size() > 0){
				cami = perm; 
				string a = cami[cami.size()-1];
				MidaCami = (a[0] - 'A')*rengles;
			}
			else MidaCami = 0;
		}
		else if (perm.size() != 0) {
			int now = 0;
			permute(perm, 0, cami, primera, ultima, now);
		}
		else {
			MidaCami = dist(primera, ultima);
		}
		cout << "millor cami " << id << ":" << endl << MidaCami << endl << "A1 ";
		bool escrit = false;
		if (cami.size() > 0){
			cout << cami[0] << " ";
			for (int i = 1; i < cami.size(); ++i){
				if (cami[i] != cami[i-1] and cami[i] != ultima){
					cout << cami[i] << " ";
					escrit = true;
				}
			}
		}
		if (escrit) cout << ultima << " ";
		else if (not escrit and ultima != "A1") cout << ultima << " ";
		cout << endl << endl;	
	}

	else cout << "millor cami " << id << ":" << endl<< "error" << endl << endl;
}


bool mayorstring(string &a, string &b){
	if (a.size() == b.size()) {
		bool resultat;
		int a1 = ((a[0] -'0')*10 + (a[1]-'0'));
		int b1 = ((b[0] -'0')*10 + (b[1]-'0'));
		if(a1 < b1) resultat = true;
		else if(a1 > b1) resultat = false;
		else {
			int a2 = ((a[3] -'0')*10 + (a[4]-'0'));
			int b2 = ((b[3] -'0')*10 + (b[4]-'0'));
			
			if (a2 < b2)  resultat = true;
			else if (a2 > b2) resultat = false;
			else { 
				int a3 = ((a[6] -'0')*10 + (a[7]-'0'));
				int b3 = ((b[6] -'0')*10 + (b[7]-'0'));
				if(a3 < b3) resultat = true;
				else resultat = false;
			}
		}
		return resultat;
	}
	else return true;
}

bool mayor(Client x, Client y){
	string a = x.Consultar_temps_ticket();
	string b = y.Consultar_temps_ticket();
	bool greater = mayorstring(a, b);
	return greater;
}

void Super::Carregar_Dades(int& medida) {
	VClients = vector<Client> (medida);
	for (int i = 0; i != medida; ++i) {
		VClients[i].Llegir_Client(Productes);
	}
}

int Super::Consulta_Num_Productes() const{
	return num_producte;
}

void Super::Inicialitzar(){
	cin >> rengles >> columnes >> caixes >> num_producte;
	Caixes = vector <Caixa>(caixes);
	Productes = vector <Producte>(num_producte);
	for (int i = 0; i != num_producte; ++i) {
		Productes[i].Llegir_Producte();
	}
}

int Super::Consultar_Caixes() const{
	return caixes;
}

void Super::Esc_Productes_Seccio(string &si) {
	bool buit = true;
	list <string> aux;
	for (int i = 0; i != Productes.size(); ++i){
		if(Productes[i].Consultar_seccio() == si){
			buit = false;
			aux.push_back(Productes[i].Consultar_nom());
		}
	}
	if (buit) cout << "seccio buida" << endl;
	else {
		aux.sort(alfabetico);
		for (list<string>::iterator it = aux.begin(); it != aux.end(); ++it) {
			cout << (*it) << endl;
		}
	}
}

void Super::Posicio_Que_Toca(int& ini, vector<Caixa> &VCaixa, Client &person, int &pos){
	pos = VCaixa.size()-1;
	int fin = pos;
	int min = VCaixa[fin].Consulta_Cola();
	for (int i = fin; i >= ini; --i) {
		string x = VCaixa[i].Consultar_Temps_Caixa();
		string y = person.Consultar_temps_ticket();
		if (mayorstring(x, y)) {
			VCaixa[i].Null_Cua();
		}
		if (VCaixa[i].Consulta_Cola() < min){
			min = VCaixa[i].Consulta_Cola();
			pos = i;
		}
	}
}

string Super::Suma_Temps(string hora, int suma){
	char res[] = "00:00:00";
	int segons = hora[7] -'0' + (hora[6]-'0')*10;
	int minuts = hora[4] -'0' + (hora[3]-'0')*10;
	int hores = hora[1] -'0' + (hora[0]-'0')*10;
	segons += suma;
	while(segons >= 60){
		segons -= 60;
		++minuts;
	}
	while(minuts >= 60){
		minuts -= 60;
		++hores;
	}
	while(hores >= 24){
		hores -= 24;
	}
	
	res[0] = hores/10 +'0';
	res[1] = hores%10 + '0';
	res[3] = minuts/10 + '0';
	res[4] = minuts%10 + '0';
	res[6] = segons/10 + '0';
	res[7] = segons%10 + '0';
	return res;
} 

int Super::Diferencia(string &a, string &b){
	int segonsa = a[7] -'0' + (a[6]-'0')*10;
	int minutsa = a[4] -'0' + (a[3]-'0')*10;
	int horesa = a[1] -'0' + (a[0]-'0')*10;
	int totala = horesa*3600 + minutsa*60 + segonsa;
	int segonsb = b[7] -'0' + (b[6]-'0')*10;
	int minutsb = b[4] -'0' + (b[3]-'0')*10;
	int horesb = b[1] -'0' + (b[0]-'0')*10;
	int totalb = horesb*3600 + minutsb*60 + segonsb;
	return totalb - totala;
}

void Super::Sim_Pagament(int &normal, int &rapida){	
	bool es_fast = true;
	int start;
	start = caixes - normal - rapida; 
	string temps_total = "00:00:00";
	int temps_espera = 0;
	for (int i = start; i < Caixes.size(); ++i){
		Caixes[i].Null_Cua();
		if (i == rapida + start) es_fast = false;
		Caixes[i].Modificar_Caixa_Rapida(es_fast);
	}
	sort(VClients.begin(), VClients.end(), mayor);
	for (int i = 0; i < VClients.size(); ++i) {
		int pagament = VClients[i].Consultar_Temps_Pagament();  
		cout << VClients[i].Consultar_Comprador_ID() << " ";
		int comenca = start; //Comença
		if (not VClients[i].Es_Client_Rapid()) comenca += rapida;
		int pos;
		Posicio_Que_Toca(comenca, Caixes, VClients[i], pos);
		string arriba = Suma_Temps(VClients[i].Consultar_temps_ticket(), caixes-pos-1);
		string aux = arriba;      
		if (Caixes[pos].Consulta_Cola() > 0) {
			string abajo = Caixes[pos].Consultar_Temps_Caixa();
			if (mayorstring(abajo, arriba)) {
				Caixes[pos].Null_Cua();
			}
			else {
				arriba = Suma_Temps(Caixes[pos].Consultar_Temps_Caixa(), 1);
			}
		}
		string fin = Suma_Temps(arriba, pagament-1);
		Caixes[pos].Sumar_Element_Cua(fin);
		cout << pos + 1 << " " << arriba << " ";
		cout << fin << endl;
		string ini = VClients[i].Consultar_temps_ticket();
		temps_espera += Diferencia(ini, fin);     
	}
	temps_total = Suma_Temps(temps_total, temps_espera+VClients.size());
	cout << temps_total << endl;
}

void Super::Consultar_Producte(string &item){
	bool found = false;
	for(int i = 0; i != Productes.size() and not found; ++i){
		if(Productes[i].Consultar_nom() == item){
			Productes[i].Escriure_Producte();
			found = true;
		}
	}
	if (not found) cout << "error" << endl;
}
