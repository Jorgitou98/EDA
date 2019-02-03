#include <iostream>
#include "queue_eda.h"
using namespace std;

template <class T>
class queueExtendida : public queue<T>{
	using Nodo = typename queue<T>::Nodo;
private:
	void vaciaLista(){
		this->prim = nullptr;
		this->ult = nullptr;
		this->nelems = 0;
	}

	Nodo* inicio(){
		return this->prim;
	}

	Nodo* fin(){
		return this->ult;
	}

	size_t elem(){
		return this->nelems;
	}

public:

	void insertaLista(queueExtendida <T> & inserta, int p){
		Nodo* ant = nullptr;
		Nodo* act = this->prim;
		for (int i = 0; i < p; ++i){
			ant = act;
			act = act->sig;
		}
		if (ant != nullptr)	ant->sig = inserta.inicio();
		else this->prim = inserta.inicio();

		Nodo * ultimo = inserta.fin();
		ultimo->sig = act;

		if (act == nullptr) this->ult = inserta.fin();

		this->nelems += inserta.elem();
		inserta.vaciaLista();
	}

	void mostrar(){
		for (Nodo* act = this->prim; act != nullptr; act = act->sig){
			cout << act->elem << " ";
		}
	}

};





bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	int elem;
	queueExtendida<int> cola;
	for (int i = 0; i < n; ++i){
		cin >> elem;
		cola.push(elem);
	}
	int m, p;
	cin >> m >> p;
	queueExtendida <int> insertar;
	for (int i = 0; i < m; ++i){
		cin >> elem;
		insertar.push(elem);
	}

	cola.insertaLista(insertar, p);
	cola.mostrar();
	cout << '\n';


		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}