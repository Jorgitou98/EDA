#include "Hora1.h"
#include "queue_eda.h"


template <class T>
class nuevaCola: public queue <T>{
	public:
	void eliminaPares(){
		using Nodo = typename queue<T>::Nodo;
		Nodo* puntActual = this->prim;
		while (puntActual != nullptr){
		Nodo * borrar = puntActual->sig;
			if (borrar != nullptr){
				puntActual->sig = borrar->sig;
				delete borrar;
				this->nelems--;
			}
			puntActual = puntActual->sig;
		}
	}
};



bool resuelveCaso() {
	int horas;
	cin >> horas;
	if (horas == 0)
		return false;
	hora hora1;
	nuevaCola <hora> cola;
	for (int i = 0; i < horas; ++i){
		cin >> hora1;
		cola.push(hora1);
	}
	cola.eliminaPares();
	while (!cola.empty()){
		cout << cola.front();
		if (cola.size() > 1) cout << " ";
		cola.pop(); // Ya no voy a hacer nada con ella asi que la destruyo segun la voy sacando
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}