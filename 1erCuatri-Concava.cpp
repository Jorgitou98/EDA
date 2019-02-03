//DG31 Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;

/*
ESPECIFICACION
{∃ i : 0 <= i < N && hayMinimo (v, i, N): (forAll j: j ≠ i && (0 <= j < N) : !hayMinimo(v, j, N)) && 0 <= ini <= fin < N} // Hay un minimo y solo uno en el vector
minimo(v[0...N): ent, ini: ent, fin: ent) dev min: ent
{min = (i : 0 <= i < N: esMinimo(v, i, N))}


esMinimo(v, i, N) = (forAll j: 0 <= j < i: v[j] < v[i]) && (forAll p: i < p < N: v[i] < v[p] 
Puedo definir el predicado así porque se asegura que a derecha del minimo es estrictamente creciente y a izquierda decreciente. Realmente esta no es la condicion de ser un minimo como tal. Pero si del que nos interesa en el ejercicio


COSTE:  a = 1 (Una llamada recusiva) b = 2 (Divido el vector por la mitad con cada llamada) k = 0 (Las asignaciones, los calculos y preparar las llamadas es constante)

T(n) =  k0   si n = 1
T(n/2) + k1  si n > 1        a = 1 = b^k = 2^0. Utilizando el teorema de la división, coste exacto (n^k)*log(n) = log(n).


*/

int minimo(vector <int> const& v, int ini, int fin){
	int mitad = ini + (fin - ini) / 2;
	if (ini == fin) return v[ini];
	else{
		int medio = v[mitad];
		if (medio < v[mitad + 1]){
			if (mitad == 0 || v[mitad - 1] > medio) return medio;
			else{
				return minimo(v, ini, mitad -1);
				}
			}
		else {
			return minimo(v, mitad + 1, fin);
			}
	}
}

bool resuelveCaso() {
	int numElem;
	cin >> numElem;
	if (!std::cin)//findelaentrada
		return false;
	vector <int> v;
	int valor;
	for (int i = 0; i < numElem; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	int min = minimo(v, 0, v.size() -1);
	cout << min << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}