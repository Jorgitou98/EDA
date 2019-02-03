// Jorge Villarrubia Elvira

/*
ESPECIFICACION
{(0 < N < 10^8) && (esPolidivisible(N)) && (tam(N) <= D <= 18)}
proc poliDivisible(num : long long ent, maxDigitos : ent, divisor : ent)
{(forAll num : esSuRaiz(N, num): (esPolidivisible(N) -> cout (num))) && ordenAlfabeticoSalida()}

esPolidivisible(N) <-> (forAll i : 1 <= i <= tam(N): (N / (10 ^ (tam(N)-i)) / i) = 0) 
// Las primeras i cifras del numero quedan determinadas por dividirlo entre 10 elevado a su tamaño - i;
   Y luego si esas primeras i cifras son divisibles entre el propio i se cumple la propiedad. Si se cumple para todas las cifras,es polidivisible

 tam(N) = (#i : 0 <= i < N: (N / 10^i) > 0) 
 // Un numero tiene tantas cifras como divisiones por diferentes potencias de 10, con cociente distinto de 0, admita.

 esSuRaiz(N, num) <-> ( (num / (10^ tam(num) - tam(N))) = N)   // N es raiz de num, si quedandome con las tam(N) primeras difras de num, obtengo N

 ordenAlfabeticoSalida() // Predicado que me devuelve si los strings mostrados por pantalla están en orden alfabético. No se muy bien como especificarlo


 Para ver el coste, sea n = maxDigitos - tam(raiz):

 T(n) =  k0           si divisor = maxDigitos
         T(n-1) + k2  si divisior < maxDigitos           Utilizando el teorma de la resta, sale un coste de n^(k+1) con k = 0, luego orden exacto n. Coste lineal

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void poliDivisible(long long int num, int maxDigitos, int divisor);

void escribePolidivisibles(long long raiz, int maxDigitos){
	string numero;
	numero = to_string(raiz);
	poliDivisible(raiz, maxDigitos, numero.size());
}

void poliDivisible(long long int num, int maxDigitos, int divisor){
	if (divisor <= maxDigitos){
		if (num % divisor == 0){
			cout << num << '\n';
			for (int i = 0; i < 10; ++i) poliDivisible(num * 10 + i, maxDigitos, divisor + 1);
		}
	}
}


bool resuelveCaso() {
	long long int num;
	int maxDigitos;
	cin >> num >> maxDigitos;
	string numero;
	numero = to_string(num);
	if (!std::cin)
		return false;
	escribePolidivisibles(num, maxDigitos);
	cout << "---\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}