#include <iostream>
#include "bintree_eda.h"
using namespace std;

template <class T>
class extiendeArbol : public bintree<T>{
	using Link = typename bintree<T>::Link;
	public:
		extiendeArbol() : bintree<T>(){};
		extiendeArbol(extiendeArbol<T> const& l, T const& e, extiendeArbol<T> const& r) : bintree<T>(l, e, r){}
		int nodos(){
			return nodosArbol(this->raiz);
		}
		int hojas(){
			return hojasArbol(this->raiz);
		}
		int altura(){
			return alturaArbol(this->raiz);
		}
	private:
		int nodosArbol(Link const& raiz){ // Coste lineal en el numero de nodos
			if (raiz == nullptr) return 0;
			else{
				return 1 + nodosArbol(raiz->left) + nodosArbol(raiz->right);
			}
		}

		int hojasArbol(Link const& raiz){ // Coste lineal en el numero de nodos
			if (raiz == nullptr) return 0;
			else{
				if (raiz->left == nullptr && raiz->right == nullptr) return 1;
				else if (raiz->left == nullptr && raiz->right != nullptr) return hojasArbol(raiz->right);
				else if (raiz->left != nullptr && raiz->right == nullptr) return hojasArbol(raiz->left);
				else return hojasArbol(raiz->left) + hojasArbol(raiz->right);
			}
		}
		int alturaArbol(Link const& raiz){ // Coste lineal en el numero de nodos
			if(raiz == nullptr) return 0;
			else{
				int alt1 = alturaArbol(raiz->left), alt2 = alturaArbol(raiz->right);
				if (alt1 >= alt2) return alt1 + 1;
				else return alt2 + 1;
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

void resuelveCaso() {
	extiendeArbol<char> arbol1;
	arbol1 = leerArbol_ext('.');
	cout << arbol1.nodos() << " " << arbol1.hojas() << " " << arbol1.altura() << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
