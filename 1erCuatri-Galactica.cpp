//DG31, Jorge Villarrubia
/*
El coste del algoritmo es n * log(n). Lo justificaremos con el teorema de la division

a = 2. Ya que hacemos dos llamadas recursivas, con una mitad y la otra de vector para ordenarlo
b = 2. Ya que aproximadamente se divide el vector por la mitad con cada llamada recursiva
k = 1. Ya que la fusion de los elementos de manera ordenada requiere que lo recorramos. Coste lineal esta parte

La recurrencia que se obtiene es:

T(N) = k0                  si N = 0  // Caso base
       2 * T(N/2) + n*k1   si N > 0                 Por tanto a = 2 = 2^1 = b^k, con lo que el coste es n^k*log(n) = n^1*log(n) = n*log(n)
*/
#include <iostream>
#include <vector>
using namespace std;

int fusiona(vector<int>& v, int ini, int med, int fin) {
	vector<int> aux(fin - ini + 1);
	int i = ini; 
	int j = med + 1; 
	int k = 0; 
	int cont = 0;

	while (i <= med && j <= fin) {
		if (v[i] < v[j]) {
			aux[k] = v[i];
			i++;
		}
		else {
			aux[k] = v[j];
			cont = cont + (j - ini - k);
			j++;
		}
		k++;
	}

	while (i <= med) {
		aux[k] = v[i];
		i++;
		k++;
	}

	while (j <= fin) {
		aux[k] = v[j];
		j++;
		k++;
	}


	for (int n = 0; n < aux.size(); ++n) v[ini + n] = aux[n];
	return cont;
}

void merge_sort(vector<int>& v, int ini, int fin, int &cont) {

	if (ini < fin) {

		int med = (ini + fin) / 2;
		merge_sort(v, ini, med, cont);
		merge_sort(v, med + 1, fin, cont);
		cont = cont + fusiona(v, ini, med, fin);
	}
}


bool resuelveCaso() {
	int numNaves;
	cin >> numNaves;
	if (!std::cin) // fin de la entrada
		return false;
	int valor;
	vector <int> v;
	for (int i = 0; i < numNaves; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	int cont = 0;
	merge_sort(v, 0, v.size() - 1, cont);
	cout << cont << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}