// DG31, Jorge Villarrubia
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


void optimiza(vector <int> & u, vector <vector <int>> const& v, vector <int> &productosDelSuper, int & suma, int j, int n, int s, int &min, bool & solucion, vector <int> const& minimoCadaProducto, int estimacion){
	for (int i = 0; i < s; ++i){
			u.push_back(v[i][j]);
			productosDelSuper[i]++;
			suma += v[i][j];
			if (productosDelSuper[i] <= 3){
				if (j < n - 1 && (suma + estimacion < min)) optimiza(u, v, productosDelSuper, suma, j + 1, n, s, min, solucion, minimoCadaProducto, estimacion - minimoCadaProducto[j+1]);
				else if (j == n-1){
					solucion = true;
					if (suma < min) min = suma;
				}
			}
			productosDelSuper[i]--;
			suma -= v[i][j];
			u.pop_back();
	}
}


void resuelveCaso() {
	int s, n;
	cin >> s >> n;
	vector <vector <int>> v;
	vector <int> u;
	int valor;
	for (int i = 0; i < s; ++i){
		for (int j = 0; j < n; ++j){
			cin >> valor;
			u.push_back(valor);
		}
		v.push_back(u);
		u.clear();
	}
	int minimoColumna, estimacion = 0;
	vector <int> minimoCadaProducto;
	for (int j = 0; j < n; ++j){
		minimoColumna = INT_MAX;
		for (int i = 0; i < s; ++i){
			int elem = v[i][j];
			if (elem < minimoColumna) minimoColumna = elem;
		}
		estimacion += minimoColumna;
		minimoCadaProducto.push_back(minimoColumna);
	}

	vector <int> productosDelSuper(s, 0);
	int suma = 0;
	int min = INT_MAX;
	int colocados = 0;
	bool solucion = false;
	vector <bool> columna(n, false);
	optimiza(u, v, productosDelSuper, suma, 0, n, s, min, solucion, minimoCadaProducto, estimacion - minimoCadaProducto[0]);
	if (solucion) cout << min << '\n';
	else cout << "Sin solucion factible\n";
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}