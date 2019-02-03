#include <iostream>
#include "bintree_eda.h"
using namespace std;

template <class T>
int equipos(bintree<T> const& arbol, int & maxExcursionistas) {
	if (arbol.empty()) {
		maxExcursionistas = 0;
		return 0;
	}
	else {
		int maxExcursionistas1, maxExcursionistas2;
		int equipos1 = equipos(arbol.left(), maxExcursionistas1);
		int equipos2 = equipos(arbol.right(), maxExcursionistas2);
		int m = max(maxExcursionistas1, maxExcursionistas2);
		if (equipos1 != 0 || equipos2 != 0) {
			if (arbol.root() == 0) maxExcursionistas = m;
			else maxExcursionistas = m + arbol.root();
			return equipos1 + equipos2;
		}
		else if (arbol.root() != 0) {
			maxExcursionistas = arbol.root();
			return 1;
		}
		else {
			maxExcursionistas = 0;
			return 0;
		}
	}
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int maxExcursionistas;
	int numEquipos = equipos(arbol, maxExcursionistas);
	cout << numEquipos << " " << maxExcursionistas << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
