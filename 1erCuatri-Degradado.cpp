// Jorge Vllarrubia Elvira

#include <iostream>
#include <vector>
using namespace std;

/* ESPECIFICACION
{(∃k (ent): k >= 0: N = 2^k) && 0 <= ini <= fin < N}
bool esDegradado(v[0...N), ini : ent, fin : ent) dev degradado : bool
{degradado = (forAll i, j : (ini <= i < j <= fin) ^ esSegmentoMitad(i,j,N) : menorSumaIzqdaQueDerecha(v[i,j])}

esSegmentoMitad(i, j, N) = (∃k (ent): 0 <= k <= log2(N): ((j+1-i) = 2^k && (2^k % i = 0))

menorSumaIzqdaQueDerecha(v[i,j]) = ((Σk: i <= k <= (ini + (fin - ini)/2): v[k]) < (Σ k: (ini + (fin - ini)/2) + 1 <= k <= j: v[k]))

Se está diciendo que todos los segmentos de tamaño potencia de 2 menores o iguales que el total, que empiecen en una posición i múltiplo del tamaño, deben cumplir la propiedad.
Por ejemplo, para un vector de tamaño 16, estaría el segmento [0,15], ya que el 0 es la única posición multiplo de 2^4 = 16. De tamaño 8 = 2^3 estaría el [0,7]y el [8,15] ya que son los divisores de 8 que hay entre las posiciones. (Se sigue para 2^2 y 2^1)

T(n)={ k1 si 0 <= n <= 1
       2*T(n/2) + k2 si n>1              Utilizando el teorema de la división sale un coste en orden exacto de n^log2(2) = n. Coste lineal
*/


bool esDegradado(vector <int> const& v, int ini, int fin, int & suma);

bool esDegradado(vector <int> const& v, int ini, int fin, int & suma){
	bool degradado;
	if (fin == ini) degradado = true;
	else if ((fin - ini) == 1) {
		degradado = (v[fin] > v[ini]);
		suma = v[fin] + v[ini];
	}
	else{
		int mitad = (fin - ini) / 2;
		int suma1 = 0, suma2 = 0;
		degradado = esDegradado(v, ini, ini + mitad, suma1) && esDegradado(v, ini + mitad + 1, fin, suma2);
		if (suma2 > suma1) {
			suma = suma1 + suma2;
		}
		else degradado = false;
	}

	return degradado;
}

bool resuelveCaso() {
	int filas, columnas;
	cin >> filas >> columnas;
if (!std::cin)
		return false;
bool degradado = true;
int valor;
for (int i = 0; i < filas; ++i){
	vector <int> v;
	for (int j = 0; j < columnas; ++j){
		cin >> valor;
		v.push_back(valor);
	}
	if (degradado){
		int suma;
		degradado = esDegradado(v, 0, v.size() - 1, suma);
	}
}

if (degradado) cout << "SI\n";
else cout << "NO\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}