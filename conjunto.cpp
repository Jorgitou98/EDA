#include "conjunto.h"
template <class T>
set::set(): contador(0), capacidad(8), datos(new int[capacidad]) {}
template <class T>
set::~set() { delete[] datos; }
template <class T>
void set::insert(int e) {
	if (!contains(e)) {
		if (empty()){
			datos[contador] = e;
			++contador;
		}
		else {
			size_t pos;
			if (!busquedaBinaria(0, contador - 1, pos, e)){
				if (contador == capacidad) amplia();
				for (int i = contador; i > pos; ++i){
					datos[i] = datos[i - 1];
					datos[contador] = e;
				}
				++contador;
			}
		}
	}

}
template <class T>
bool set::busquedaBinaria(size_t ini, size_t fin, size_t &pos, T e){
	if (ini >= fin){
		if (datos[ini] == e) {
			pos = ini;
			return true;
		}
		else {
			pos = -1;
			return false;
		}
	}
	else{
		size_t mitad = (ini + fin) / 2;
		if (datos[mitad] == e){
			pos = mitad;
			return true;
		}
		else if (datos[mitad] < e) return busquedaBinaria(mitad + 1, fin, pos, e);
		else return busquedaBinaria(ini, mitad - 1, pos, e);
	}
}

template <class T>
bool set::contains(int e) const {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}
template <class T>
void set::amplia() {
	int * nuevos = new int[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = datos[i];
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}


bool resuelveCaso() {
	h leer los datos de la entrada i
	if (!std::cin)
		return false;
	Solucion sol = resolver(datos);
	h escribir sol i
		return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}