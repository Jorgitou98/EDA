// Jorge Villarrubia Elvira

#include <iostream>
#include <vector>
using namespace std;

/* ESPECIFICACION
{(∃k (ent): k >= 0: N = 2^k) && 0 <= ini <= fin < N}
bool parcialmenteOrdenado(v[0...N), ini : ent, fin : ent) dev ordenParcial : bool
{ordenParcial = (forAll i, j : (0 <= i < j < N) ^ esSegmentoMitad(i,j,N) : ordenadoEnParte(v[i,j])}

esSegmentoMitad(i, j, N) = (∃k (ent): 0 <= k <= log2(N): ((j+1-i) = 2^k && (2^k % i = 0))

ordenadoEnParte(v[i,j]) = ((min k: i <= k <= (ini + (fin - ini)/2): v[k]) <= (min k: (ini + (fin - ini)/2) + 1 <= k <= j: v[k])) && ((max k: i <= k <= (ini + (fin - ini)/2): v[k]) >= (max k: (ini + (fin - ini)/2) + 1 <= k <= j: v[k]))

Se está diciendo que todos los segmentos de tamaño potencia de 2 menores o iguales que el total, que empiecen en una posición i múltiplo del tamaño, deben cumplir la propiedad.
Por ejemplo, para un vector de tamaño 16, estaría el segmento [0,15], ya que el 0 es la única posición multiplo de 2^4 = 16. De tamaño 8 = 2^3 estaría el [0,7]y el [8,15] ya que son los divisores de 8 que hay entre las posiciones. (Se sigue para 2^2 y 2^1)

T(n)={ k1 si 0 <= n <= 1
       2*T(n/2) + k2 si n>1              Utilizando el teorema de la división sale un coste en orden exacto de n^log2(2) = n. Coste lineal
*/

bool parcialmenteOrdenado(vector <int> const& v, int ini, int fin, int & max, int & min){
	bool ordenParcial;
	if (fin - ini == 1){
		ordenParcial = (v[fin] >= v[ini]);
		if (v[fin] >= v[ini]) {
			max = v[fin];
			min = v[ini];
		}
		else {
			max = v[ini];
			min = v[fin];
		}
	}
	else if (fin == ini) {
		ordenParcial = true; // Si se trata de un vector con un solo elemento
	}
	else{
		int max1 = 0, max2 = 0;
		int min1 = 0, min2 = 0;
			ordenParcial = parcialmenteOrdenado(v, ini, ini + (fin - ini) / 2, max1, min1) && parcialmenteOrdenado(v, ini + (fin - ini) / 2 + 1, fin, max2, min2);
			if (max2 >= max1 && min1 <= min2) {
				max = max1;
				min = min1;
			}
		else ordenParcial = false;
	}
	return ordenParcial;
}


bool resuelveCaso() {
	int valor;
	cin >> valor;
	if (valor == 0)
		return false;
	vector <int> v;
	while (valor != 0){
		v.push_back(valor);
		cin >> valor;
	}
	int max, min;
	bool ordenParcial = parcialmenteOrdenado(v, 0, v.size() - 1, max, min);
	if (ordenParcial) cout << "SI\n";
	else cout << "NO\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}