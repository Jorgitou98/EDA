//DG31, Jorge Villarrubia Elvira
#include <iostream>
#include <vector>
using namespace std;

/*
El coste del algoritmo es logarítimo. Lo justificaremos con el teorema de la division

a = 1. Ya que hacemos una única llamada recursiva con una mitad del vector o la otra
b = 2. Ya que aproximadamente se divide el vector por la mitad con cada llamada recursiva
k = 0. Ya que todas las operaciones para preparar las llamadas y devolver el resultado se hacen en tiempo constante

La recurrencia que se obtiene es:

T(N) = k0            si N = 0  // Caso base
       T(N/2) + k1   si N > 0                 Por tanto a = 1 = 2^0 = b^k, con lo que el coste es n^k*log(n) = n^0*log(n) = log(n)
*/




int posElementoSolo(vector <int> const& v, int ini, int fin){
	if (ini == fin) return ini; // Si solo queda un elemento por comprobar, este es el desemparejado
	else{
		int mitad = (ini + fin) / 2;
		int elem = v[mitad];
		if (elem == v[mitad - 1]){ // Compruebo si coincide con el elemento de su izquierda
			if ((mitad - 1) % 2 == 0) return posElementoSolo(v, mitad + 1, fin); 
			/* Si coincide y la posicion de su izquierda es par, entonces esta pareja tiene numero par de elementos antes. Luego todos estan emparejados. Me voy a la otra mitad */
			else return posElementoSolo(v, ini, mitad - 2);
			/* Si coincide y la posicion de su izquierda es impar, entonces esta pareja tiene numero impar de elementos antes. Luego hay alguno sin emparejar. Me voy a esa parte del vector */
		}
		else if (elem == v[mitad + 1]){ // Si no coincide con el de la izquierda, lo compruebo con el de la derecha
			if (mitad % 2 == 0) return posElementoSolo(v, mitad + 2, fin);
			/* Si coincide y esa posicion es par, entonces esta pareja tiene numero par de elementos antes. Luego todos estan emparejados. Me voy a la otra mitad */
			else return posElementoSolo(v, ini, mitad - 1);
			/* Si coincide y lesa posicion es impar, entonces esta pareja tiene numero impar de elementos antes. Luego hay alguno sin emparejar. Me voy a esa parte del vector */
		}
		else return mitad; // Si no coincide con el de la izquierda ni el de la derecha, por estar ordenado, este es el elemento desemparejado
	}
}

void resuelveCaso() {
	int numElem, valor;
	vector <int> v;
	cin >> numElem;
	for (int i = 0; i < numElem; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	int pos = posElementoSolo(v, 0, v.size() -1);
	cout << pos << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	system("pause");
	return 0;
}