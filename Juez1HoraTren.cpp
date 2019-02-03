
#include "Hora1.h"
using namespace std;



bool resuelveCaso() {
	int trenes, numConsultas;
	cin >> trenes >> numConsultas;
	if (trenes == 0 && numConsultas == 0)
		return false;
	vector <hora> vTren;
	hora elemento;
	for (int i = 0; i < trenes; ++i){
		cin >> elemento;
		vTren.push_back(elemento);
	}
	for (int i = 0; i < numConsultas; ++i){
		try{
			cin >> elemento;
			bool sacado = false;
			int j = 0;
			while (!sacado && j < trenes){
				if (elemento < vTren[j] || elemento == vTren[j]) {
					cout << vTren[j] << '\n';
					sacado = true;
				}
				j++;
			}
			if (!sacado) cout << "NO\n";
		}
		catch (domain_error e){
			cout << e.what() << '\n';
		}
	}
	cout << "---\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}