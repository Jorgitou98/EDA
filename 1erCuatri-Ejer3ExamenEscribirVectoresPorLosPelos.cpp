//DG31, Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;


void porLosPelos(vector <int> & camino, int iguales, int n, int d, int elemento){
	camino.push_back(elemento);
	int k = camino.size();
	if (k == n){
		for (int i = 0; i < k; ++i) {
			cout << camino[i];
			if (i != (k - 1)) cout << " ";
		}
		cout << '\n';
	}
	else{
		if (iguales < d) porLosPelos(camino, iguales + 1, n, d, elemento);
		porLosPelos(camino, 1, n, d, elemento + 1);
	}
	camino.pop_back();
}

void resuelveCaso() {
	int n, d, e;
	cin >> n >> d >> e;
	vector <int> v;
	porLosPelos(v, 1, n, d, e);
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}