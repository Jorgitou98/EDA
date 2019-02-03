//Jorge Villarrubia Elvira

#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

int diaQueVendra(vector <int> const& v);

int diaQueVendra(vector <int> const& v){
	int menorDif;
	for (int i = 0; i < v.size(); ++i){
		menorDif = menorDif + v[i];
	}
	int derecha = 0, izquierda = menorDif;
	for (int i = 0; i < v.size(); ++i){
		derecha = derecha + v[i];
		izquierda = izquierda - v[i];
		if (abs(derecha - izquierda) < abs(menorDif)) {
			menorDif =
		}
	}
}

bool resuelveCaso() {
	int aperturas;
	cin >> aperturas;
	if (aperturas == 0)
		return false;
	vector <int> v;
	int valor;
	for (int i = 0; i < aperturas; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	int pos = diaQueVendra(v);
	cout << pos << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}