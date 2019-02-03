//DG 31, Jorge Villarrubia Elvira

#include <iostream>
#include <vector>
using namespace std;

/*ESPECIFICACIÓN DE RESOLVER
{a.size() >= 2 ^ def(a)^}
		fun resolver( a[] : de ent) dev seCumple: bool
{a[1] > a[0] -> (seCumple = (forall j: 2 <= i < a.size(): j[i] > j[i-1])), a[1] < a[0] -> (seCumple = (forall j: 2 <= i < a.size(): j[i] < j[i-1])), (a[1] = a[0] -> !seCumple)
*/
bool resolver(vector <int> a){
	bool seCumple = true;
	int i = 2;
	if (a[1] > a[0]){
		while (i < a.size() && seCumple){      // La función de cota es C = a.size-i, es siempre >= 0 y disminuye en cada iteración
			if (a[i] <= a[i - 1]) seCumple = false;   // Un posible invariante podría ser I = (1 <= i <= a.size() ^ (!seCumple <-> ∃j: 2 <= j < i: a[j] <= a[j-1]))
			i++;
		}
	}
	else if (a[1] < a[0]){
		while (i < a.size() && seCumple){      // La función de cota es C = a.size-i, es siempre >= 0 y disminuye en cada iteración
			if (a[i] >= a[i - 1]) seCumple = false;   // Un posible invariante podría ser I = (1 <= i <= a.size() ^ (!seCumple <-> ∃j: 2 <= j < i: a[j] >= a[j-1]))
			i++;
		}
	}
	else seCumple = false;
	return seCumple;
}



bool resuelveCaso() {
	int personajes, valor;
	vector <int> a;
	cin >> personajes;
	for (int i = 0; i < personajes; ++i) {
		cin >> valor;
		a.push_back(valor);
	}
	if (personajes == 0)
		return false;
	bool seCumple = resolver(a);
	if (seCumple) cout << "DALTON\n";
	else cout << "DESCONOCIDOS\n";

		return true;
}
int main() {
	while (resuelveCaso());
	//system("pause");
	return 0;
}