//DG31, Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;
/*
ESPECIFICACION
{ N >= 0 && rachas = 0 && desdeUltimaRacha = 0}
victoriasSeguidas(v[0...N) de ent, rachas : ent, desdeUltimaRacha : ent) dev maxVictorias : ent
{maxVictorias = (max i,j : 0 <= i <= j < N && esRacha(i,j): j + 1 - i) && rachas = (#i,j : 0 <= i <= j < N && esRacha(i,j): (j + 1 - i = maxVictorias)) && desdeUltimaRacha = (#i: 0 <= i < N: (forAll p,q: (i <= p <= q < N && esRacha(p,q)): p + 1 - q < maxVictorias)} // Es decir, el contador de todos los i, tales que les rachas posteriores, son menores que la máxima
esRacha(i,j) = (forAll p: 0 <= i <= p <= j < N: v[p] > 0)

El coste es lineal, ya que solo recorro el vector una vez accediendo a cada elemento
*/
int victoriasSeguidas(vector <int> const& v, int & rachas, int & desdeUltimaRacha){
	int maxVictorias = 0, victorias = 0;
	for (int i = 0; i < v.size(); ++i){
		if (v[i] > 0) {
			victorias++;
			if (victorias > maxVictorias) {
				maxVictorias = victorias;
				rachas = 1;
				desdeUltimaRacha = 0;
			}
			else if (victorias == maxVictorias){
				rachas++;
				desdeUltimaRacha = 0;
			}
			else desdeUltimaRacha++;
		}
		else {
			victorias = 0;
			desdeUltimaRacha++;
		}
	}
	return maxVictorias;
}

bool resuelveCaso() {
	int partidos;
	cin >> partidos;
	if (!std::cin) // fin de la entrada
		return false;
	int valor;
	vector <int> v;
	for (int i = 0; i < partidos; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	int rachas = 0, desdeUltimaRacha = 0;
	int maxVictorias = victoriasSeguidas(v, rachas, desdeUltimaRacha);
	cout << maxVictorias << " " << rachas << " " << desdeUltimaRacha << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
