// Jorge Villarrubia

#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <class T>
class InvierteSegmento : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	// imprime la lista enlazada
	void print(std::ostream & o = std::cout) const {
		Nodo* punt = this->prim;
		for (int i = 0; i < this->nelems; ++i){
			o << punt->elem << " ";
			punt = punt->sig;
		}
	}

	// invierte el segmento que comienza en la posición P y tiene longitud L
	void invierte(size_t P, size_t L) {

		Nodo* punt = this->prim;
		if (P > 1) { // Separo el caso de que P == 1, porque no pudo llevar su anterior
			int i = 0;
			for (i = 0; i + 2 < P; ++i){ // Me coloco justo antes del primer elemento del segmento a invertir;
				punt = punt->sig;
			}
			Nodo* primInvertir = punt; // Me lo guardo

			for (int j = i; j + 2 < L + P; ++j){ // Me coloco en el ultimo a invertir
				punt = punt->sig;
			}
			Nodo* finInvertir = punt; // Me lo guardo
			for (int i = 0; i < L - 1; ++i){
				Nodo* siguiente = primInvertir->sig;
				primInvertir->sig = (primInvertir->sig)->sig; // Me salto uno al apuntar
				siguiente->sig = finInvertir->sig;
				finInvertir->sig = siguiente;
			}
		}
		else if (P == 1){
			for (int i = 0; i + 1 < L; ++i){ // Me coloco en el ultimo a invertir
				punt = punt->sig;
			}
			Nodo* finInvertir = punt; // Me lo guardo
			for (int i = 0; i < L - 1; ++i){
				Nodo* siguiente = this->prim->sig;
				this->prim->sig = finInvertir->sig;
				finInvertir->sig = this->prim;
				this->prim = siguiente;
			}
		}
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, InvierteSegmento<T> const&
	lista) {
	lista.print(o);
	return o;
}

bool resuelveCaso() {
	int N, P, L;
	cin >> N >> P >> L;
	if (!cin)
		return false;

	InvierteSegmento<int> lista;
	for (size_t i = 0; i < N; ++i) {
		int num;
		cin >> num;
		lista.push(num);
	}

	lista.invierte(P, L);

	cout << lista << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
