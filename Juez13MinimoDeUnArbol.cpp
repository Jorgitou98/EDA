#include <iostream>
#include <string>
#include "bintree_eda.h"
using namespace std;

template <class T>
class extiendeArbol : public bintree<T>{
	using Link = typename bintree<T>::Link;
public:
	extiendeArbol() : bintree<T>(){};
	extiendeArbol(extiendeArbol<T> const& l, T const& e, extiendeArbol<T> const& r) : bintree<T>(l, e, r){}
	T minimo(){
		return minArbol(this->raiz);
	}
private:
	T minArbol(Link const& raiz){ // Coste lineal en el numero de nodos
		if (raiz->left == nullptr && raiz->right == nullptr) return raiz->elem;
		else{
			T minIzqda, minDerecha;
			if (raiz->left != nullptr) {
				minIzqda = minArbol(raiz->left);
				if (raiz->right != nullptr) {
					minDerecha = minArbol(raiz->right);
					if (minIzqda <= raiz->elem && minIzqda <= minDerecha) return minIzqda;
					else if (raiz->elem <= minIzqda && raiz->elem <= minDerecha) return raiz->elem;
					else return minDerecha;
				}
				else{
					if (minIzqda <= raiz->elem) return minIzqda;
					else return raiz->elem;
				}
			}
			else {
				minDerecha = minArbol(raiz->right);
				if (minDerecha <= raiz->elem) return minDerecha;
				else return raiz->elem;
			}
		}
	}

};

template <typename T>
inline extiendeArbol<T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return{ iz, raiz, dr };
	}
}

#include <iostream>
using namespace std;
bool resuelveCaso() {
	char car;
	cin >> car;
	if (!std::cin)
		return false;

	if (car == 'N'){
		extiendeArbol<int> arbol1;
		arbol1 = leerArbol_ext<int>(-1);
		if (!arbol1.empty()) cout << arbol1.minimo();
	}
	else{
		extiendeArbol<string> arbol1;
		arbol1 = leerArbol_ext<string>("#");
		if (!arbol1.empty()) cout << arbol1.minimo();
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}