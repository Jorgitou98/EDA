#include <iostream>
#include "bintree_eda.h"
using namespace std;

void rios(bintree<int> const& arbol, int& navegables, int & caudal){ 
	if (arbol.empty()){
		caudal = 0;
		navegables = 0;
	}
	else{
		int caudal1, navegables1, caudal2, navegables2;
		bintree<int> izqda = arbol.left();
		bintree <int> der = arbol.right();
		if (izqda.empty() && der.empty()){
			caudal = 1;
			navegables = 0;
		}
		else{
			rios(izqda, navegables1, caudal1);
			rios(der, navegables2, caudal2);
			caudal = max(caudal1 + caudal2 - arbol.root(), 0);
			if (caudal >= 3) navegables = navegables1 + navegables2 + 1;
			else navegables = navegables1 + navegables2;
		}
	}
}



void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int navegables1, navegables2, caudal1, caudal2;

	rios(arbol.left(), navegables1, caudal1);
	rios(arbol.right(), navegables2, caudal2);
	cout << navegables1 + navegables2 << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}

