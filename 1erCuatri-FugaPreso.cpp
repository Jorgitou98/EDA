// DG31 Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;
/*
ESPECIFICACION
{(N = (car2 - car1)) && ordenadoEstrictamente(v, N) && sonDelIntervalo(car1, car2, v) && (0 <= ini <= fin < N)} Que N tenga ese tamaño y todos los caracteres del vector sean de intervalo implica que falta exactemente un caracter
letraFalta(v[0...N): char, carMedio: char, ini: ent, fin: ent) dev letraQueFalta : char
{letraQueFalta = i (char): car1 <= i <= car2: (∄ j: 0 <= j < N : v[j] = i)}


ordenadoEstrictamente(v, N) = (forAll i, j: 0 <= i < j < N: v[i] < v[j])
sonDelIntervalo(car1, car2, v)  = (forAll i: 0 <= i < N: car1 <= v[i] <= car2)


COSTE:  a = 1 (Una llamada recusiva) b = 2 (Divido el vector por la mitad con cada llamada) k = 0 (Las asignaciones, los calculos y preparar las llamadas es constante)

T(n) =  k0           si n = 1
        T(n/2) + k1  si n > 1        a = 1 = b^k = 2^0. Utilizando el teorema de la división, coste exacto (n^k)*log(n) = log(n).


*/


char letraFalta(vector <char> const& v, char carMedio, int ini, int fin){
	if (ini == fin){
		if (v[ini] == carMedio) return carMedio + 1;
		else return carMedio;
	}
	else{
		int mitad = ini + (fin - ini) / 2;
		if (v[mitad] == carMedio){
			int avanceLetra = ((fin - mitad - 1) / 2) + 1;
			letraFalta(v, carMedio + avanceLetra, mitad + 1, fin);
		}
		else{
			int retrocedeLetra = mitad - ini - ((mitad - ini) / 2);
				letraFalta(v, carMedio - retrocedeLetra, ini, mitad);

		}
	}
}




void resuelveCaso() {
	char carIni, carFin;
	cin >> carIni >> carFin;
	vector <char> v;
	char valor;
	for (int i = 0; i < (carFin - carIni); ++i){
		cin >> valor;
		v.push_back(valor);
	}
	char carMitad = carIni + ((v.size() - 1 ) / 2);
	char letraQueFalta = letraFalta(v, carMitad, 0, v.size() -1);
	cout << letraQueFalta << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	system("pause");
	return 0;
}