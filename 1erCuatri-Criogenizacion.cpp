// DG31, Jorge Villarrubia Elvira

#include <iostream>
#include <vector>
using namespace std;

const int CENTINELA = 0;

void criogenizacion(vector <long long int> const & v, int n, long long int &mayor, long long int &fMayor, long long int &menor, long long int &fMenor);


/* Especificación
{0 < N  & ^ (forall i : 0 <= i < N : 0 < v[i] < 10^8) }
proc criogenizacion (v[0...N) de ll ent, n: ent, mayor: ll ent, fMayor: ll ent, menor: ll ent, fMenor: ll ent)
{ (mayor = max i : 0 <= i < n : v[i]) ^ (fMayor = #j: 0 <= j < n: v[j] = mayor} ^ (menor = min i : 0 <= i < n : v[i]) ^ (fMenor = #j: 0 <= j < n: v[j] = menor)}

*/

/* 
INVARIANTE
I ≡ {mayor = max j: 0 <= j < i : v[j] ^ (fMayor = #j: 0 <= j < i: v[j] = mayor} ^ (menor = min j : 0 <= j < i : v[j]) ^ (fMenor = #j: 0 <= j < i: v[j] = menor)}

FUNCION DE COTA
C ≡ N - i
*/
void criogenizacion(vector <long long int> const & v, int n, long long int &mayor, long long int &fMayor, long long int &menor, long long int &fMenor){
	mayor = v[0], menor = v[0], fMayor = 1, fMenor = 1;
	for (int i = 1; i < n; ++i){
		if (v[i] == mayor) fMayor++;
		else if (v[i] > mayor){
			mayor = v[i];
			fMayor = 1;
		}
		if (v[i] == menor) fMenor++;
		else if (v[i] < menor){
			menor = v[i];
			fMenor = 1;
		}
	}
}
void resuelveCaso() {
	long long int valor;
	vector <long long int> v;
	long long int mayor, fMayor, menor, fMenor;
	cin >> valor;
	while (valor != CENTINELA){
		v.push_back(valor);
		cin >> valor;
	}
	criogenizacion(v, v.size(), mayor, fMayor, menor, fMenor);
	cout << menor << " " << fMenor << " " << mayor << " " << fMayor << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}