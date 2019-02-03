//DG31, Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;

/*
El algoritmo tiene coste lineal. Lo justifcaremos con el teorema de la división
a = 2 (Se hacen 2 llamadas recursivas, una con cada mitad del vector)
b = 2 (Aproximadamente se divide el vector por la mitad con cada llamada
k = 0 (El coste de preparar llamadas y devolver resultados es constante)

T(n) = {k0           si n <= 1
        2T(n/2) + k1 si n > 1       a= 2 > 1 = 2^0 = b^k --> Coste n^logb(a) = n^log2(2) = n^1 = n
*/


bool crecientePorLosPelos(vector <int> const& v, int ini, int fin){
	if (ini >= fin) return true;
	else{
		int mitad = (ini + fin) / 2;
		if ((v[mitad + 1] - v[mitad] > 1) || (mitad > 0 && v[mitad] - v[mitad - 1] > 1)) return false;
		else return (crecientePorLosPelos(v, ini, mitad - 1) && crecientePorLosPelos(v, mitad + 1, fin));
	}
}

void resuelveCaso() {
	int n;
	cin >> n;
	vector <int> v;
	int valor;
	for (int i = 0; i < n; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	bool cumple = crecientePorLosPelos(v, 0, v.size()-1);
	if (cumple) cout << "SI\n";
	else cout << "NO\n";
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}