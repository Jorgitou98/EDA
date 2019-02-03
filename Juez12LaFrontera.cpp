#include <iostream>
#include <vector>
#include <stack>
#include "bintree_eda.h"
using namespace std;

template <class T>
class extiendeArbol : public bintree<T>{
	using Link = typename bintree<T>::Link;
public:
	extiendeArbol() : bintree<T>(){};
	extiendeArbol(extiendeArbol<T> const& l, T const& e, extiendeArbol<T> const& r) : bintree<T>(l, e, r){}
	vector <T> devuelveFrontera(){
		stack <Link> pila;
		vector <T> v;
		frontera(v, this->raiz, pila);
		return v;
	}
private:
	void frontera(vector <T> &v, Link const& raiz, stack <Link> & pila){
		if (raiz != nullptr){
			if (raiz->left == nullptr && raiz->right == nullptr) {
				v.push_back(raiz->elem);
				if (!pila.empty()){
					Link sig = pila.top();
					pila.pop();
					frontera(v, sig, pila);
				}
			}
			else if (raiz->left != nullptr && raiz->right != nullptr){
				pila.push(raiz->right);
				return frontera(v, raiz->left, pila);
			}
			else if (raiz->left == nullptr && raiz->right != nullptr){
				return frontera(v, raiz->right, pila);
			}
			else{
				return frontera(v, raiz->left, pila);
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

void resuelveCaso() {
	extiendeArbol<int> arbol1;
	arbol1 = leerArbol_ext(-1);
	vector <int> v = arbol1.devuelveFrontera();
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
