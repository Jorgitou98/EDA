#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
El coste del algoritmo es lineal. Lo justificaremos con el teorema de la division

a = 2. Ya que hacemos dos llamadas recursivas con una mitad del vector y con la otra
b = 2. Ya que aproximadamente se divide el vector por la mitad con cada llamada recursiva
k = 0. Ya que todas las operaciones para preparar las llamadas y devolver el resultado se hacen en tiempo constante

La recurrencia que se obtiene es:

T(N) = k0              si N = 0  // Caso base
       2*T(N/2) + k1   si N > 0                 Por tanto a = 2 > 1 = 2^0 = b^k, con lo que el coste es n^logb(a) = n^log2(2) = n^1 = n
*/
struct tJugador{
	string nombre;
	int numCanicas;
};
tJugador vencedor(vector <tJugador> & v, int ini, int fin, int & posicion){
	if (ini == fin){
		posicion = ini;
		return v[ini];
	}
	else{
		int pos1, pos2;
		int mitad = (ini + fin) / 2;
		tJugador primerGanador, segundoGanador;
		primerGanador = vencedor(v, ini, mitad, pos1);
		segundoGanador = vencedor(v, mitad + 1, fin, pos2);
		if (primerGanador.numCanicas >= segundoGanador.numCanicas){
			posicion = pos1;
			v[pos1].numCanicas += v[pos2].numCanicas / 2;
			primerGanador.numCanicas += segundoGanador.numCanicas / 2;
			return primerGanador;
		}
		else{
			posicion = pos2;
			v[pos2].numCanicas += v[pos1].numCanicas / 2;
			segundoGanador.numCanicas += primerGanador.numCanicas / 2;
			return segundoGanador;
		}
	}
}

bool resuelveCaso() {
	int numJugadores;
	cin >> numJugadores;
	if (!std::cin) // fin de la entrada
		return false;
	vector <tJugador> v;
	tJugador jugador;
	for (int i = 0; i < numJugadores; ++i){
		cin >> jugador.nombre >> jugador.numCanicas;
		v.push_back(jugador);
	}
	int posicion = 0;
	tJugador jugadorGana = vencedor(v, 0, v.size() -1 , posicion);
	cout << jugadorGana.nombre << " " << jugadorGana.numCanicas << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
