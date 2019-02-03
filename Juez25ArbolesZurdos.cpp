#include <iostream>
#include "bintree_eda.h"
using namespace std;



void zurdo(bintree <char> const& arbol, bool &esZurdo, int & descendientes){
	if (arbol.empty()){
		esZurdo = true;
		descendientes = 0;
	}
	else if (arbol.left().empty() && arbol.right().empty()){
		esZurdo = true;
		descendientes = 1;
	}
	else{
		bool esZurdoI,esZurdoD;
		int descendientesI, descendientesD;
		zurdo(arbol.left(), esZurdoI, descendientesI);
		zurdo(arbol.right(), esZurdoD, descendientesD);
		esZurdo = esZurdoI && esZurdoD && (descendientesI > (descendientesD + descendientesI) /2);
		descendientes = descendientesI + descendientesD + 1;
	}
}


void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	bool esZurdo;
	int descendientes;
	zurdo(arbol, esZurdo, descendientes);
	if (esZurdo) cout << "SI\n";
	else cout << "NO\n";


}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
