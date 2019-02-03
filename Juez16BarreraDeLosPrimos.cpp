#include <iostream>
#include "bintree_eda.h"
using namespace std;


bool esPrimo(int num){
	int a = 0;
	for (int i = 1; i<(num + 1); i++){
		if (num % i == 0){
			a++;
		}
	}
	return a == 2;
}

void multiploSieteAccesible(bintree <int> const& arbol, bool & haySolucion, int & solucion, int altActual, int & altSol){
	if (arbol.empty()){
		haySolucion = false;
	}
	else if (esPrimo(arbol.root())){
		haySolucion = false;
	}
	else if (arbol.root() % 7 == 0){
		haySolucion = true;
		solucion = arbol.root();
		altSol = altActual;
	}
	else{
		bool haySolucion1, haySolucion2;
		int solucion1, solucion2, altSol1, altSol2;
		multiploSieteAccesible(arbol.left(), haySolucion1, solucion1, altActual + 1, altSol1);
		multiploSieteAccesible(arbol.right(), haySolucion2, solucion2, altActual + 1, altSol2);
		haySolucion = (haySolucion1 || haySolucion2);
		if (haySolucion1) {
			if (haySolucion2 && altSol2 < altSol1){
				solucion = solucion2;
				altSol = altSol2;
			}
			else{
				solucion = solucion1;
				altSol = altSol1;
			}
		}
		else if (haySolucion2) {
			solucion = solucion2;
			altSol = altSol2;
		}
	}
}

void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	bool haySolucion;
	int solucion, altSol;
	multiploSieteAccesible(arbol, haySolucion, solucion, 1, altSol);
	if (!haySolucion) cout << "NO HAY\n";
	else cout << solucion << " " << altSol << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}