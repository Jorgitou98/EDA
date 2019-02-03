// DG31, Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;

void solucionOptima(vector<vector<int>> const& v, vector <bool> & columna, int &minimo, int &suma, int n, int fila, vector <int> const & minimosFilas){
	for (int j = 0; j < n; ++j){
		if (!columna[j]){
			columna[j] = true;
			suma = suma + v[fila][j]; // Marco por donde voy
			if (fila < n - 1){
				int costeEstimado = suma + minimosFilas[n - 2 - fila];
				if (costeEstimado < minimo) solucionOptima(v, columna, minimo, suma, n, fila + 1, minimosFilas);
			}
			else {
				if (suma < minimo) minimo = suma;
			}
			columna[j] = false;
			suma = suma - v[fila][j];
		}
	}
}
bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector <vector <int>> v;
	vector <int> u;
	int valor;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> valor;
			u.push_back(valor);
		}
		v.push_back(u);
		u.clear();
	}
	vector <int> minimosFilas;
	int sumaFilasQueLlevo = 0;
	for (int i = v.size()-1; i >= 0; --i){
		int minFila = 10000;
		for (int j = 0; j < v.size(); ++j){
			if (v[i][j] < minFila) minFila = v[i][j];
		}
		sumaFilasQueLlevo = sumaFilasQueLlevo + minFila;
		minimosFilas.push_back(sumaFilasQueLlevo);
	}
	int minimo = n * 10000;
	int suma = 0;
	vector <bool> t(n, false);
	solucionOptima(v, t, minimo, suma, v.size(), 0, minimosFilas);
	cout << minimo << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}