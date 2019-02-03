#include <iostream>
#include "bintree_eda.h"
using namespace std;

void zurdo(bintree <int> const& arbol, int & hojaSol, int & dragones){
	if (arbol.root() > 2){
		hojaSol = arbol.root();
		dragones = 0;
	}
	else{
		bintree<int> izqda = arbol.left(), derecha = arbol.right();
		if (!izqda.empty() && !derecha.empty()){
			int hojaSolI, hojaSolD, dragonesI, dragonesD;
			zurdo(izqda, hojaSolI, dragonesI);
			zurdo(derecha, hojaSolD, dragonesD);
			if (dragonesI <= dragonesD) {
				hojaSol = hojaSolI;
				if (arbol.root() == 1) dragones = dragonesI + 1;
				else dragones = dragonesI;
			}
			else {
				hojaSol = hojaSolD;
				if (arbol.root() == 1) dragones = dragonesD + 1;
				else dragones = dragonesD;
			}
		}
		else if (!izqda.empty()){
			int hojaSolI, dragonesI;
			zurdo(izqda, hojaSolI, dragonesI);
			hojaSol = hojaSolI;
			if (arbol.root() == 1) dragones = dragonesI + 1;
			else dragones = dragonesI;
		}
		else if (!derecha.empty()){
			int hojaSolD, dragonesD;
			zurdo(derecha, hojaSolD, dragonesD);
			hojaSol = hojaSolD;
			if (arbol.root() == 1) dragones = dragonesD + 1;
			else dragones = dragonesD;
		}
	}
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int hojaSol, dragones;
	zurdo(arbol, hojaSol, dragones);
	cout << hojaSol << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
