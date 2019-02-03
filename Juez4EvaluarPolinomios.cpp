#include "Polinomio.h"
bool resuelveCaso() {
	int coeficiente, exponente;
	cin >> coeficiente >> exponente;
	if (!std::cin)
		return false;
	polinomio p;
	while (coeficiente != 0 || exponente != 0){
		monomio m = monomio(coeficiente, exponente);
		p.anadirMonomio(m);
		cin >> coeficiente >> exponente;
	}
	int numEv, x;
	cin >> numEv;
	for (int i = 0; i < numEv; ++i){
		cin >> x;
		cout << p.evPolinomio(x) << " ";
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}