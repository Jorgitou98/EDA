//DG31, Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;

/* ESPECIFICACION
{N >= 0 && d > 0}
bool crecienteYDiver (V[0..N): de ent, d: ent) dev cumple: bool
{cumple = (esCrecientePorLosPelos(V,N) && divertido(V,N))}

esCrecientePorLosPelos(V,N) = (forAll i: 1 <= i < n : (v[i] - v[i-1] >= 0 && v[i] - v[i-1] <=1))
divertido(V,N) = (maxIguales(V,N) <= d)
maxIguales (V,N) = (max i: 0 <= i < N : (#j : 0 <= j < N : v[i] = v[j]))



INV = {0 <= n <= N && esCrecientePorLosPelos(V,n) && divertido(V,n))
b = {n < N && cumple}
c = {N - n}

*/



bool crecienteYDiver(vector <int> const& v, int d){ // Si cumple ser creciente por los pelos, los elementos igales tienen que ir seguidos
	int maxIguales = 1;
	bool cumple = true;
	int i = 1;
	while (cumple && i < v.size()){
		if (v[i] == v[i - 1]) maxIguales++;
		else maxIguales = 1;
		cumple = (v[i] - v[i - 1] >= 0) && (v[i] - v[i - 1] <= 1) && (maxIguales <= d);
		++i;
	}
	return cumple;
}

void resuelveCaso() {
	int n, d;
	cin >> d >> n;
	vector <int> v;
	int valor;
	for (int i = 0; i < n; ++i){
		cin >> valor;
		v.push_back(valor);
	}
	bool cumple = crecienteYDiver(v, d);
	if (cumple) cout << "SI\n";
	else cout << "NO\n";
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}