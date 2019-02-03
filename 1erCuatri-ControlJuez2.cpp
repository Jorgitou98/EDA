// Jorge Villarrubia Elvira

#include <iostream>
#include <vector>
using namespace std;


bool estaBalanceado(int &peso);

bool estaBalanceado(int &peso){
	int p1, d1, p2, d2;
	cin >> p1 >> d1 >> p2 >> d2;
	bool balanceado1, balanceado2, balanceado;

	if (p1 == 0){
		balanceado1 = estaBalanceado(p1);
	}
	else{
		peso = p1;
		balanceado1 = true;
	}
	if (p2 == 0){
		balanceado2 = estaBalanceado(p2);
	}
	else {
		peso = p2;
		balanceado2 = true;
	}
	balanceado = (p1 * d1 == p2 * d2) && balanceado1 && balanceado2;
	peso = p1 + p2;
	return balanceado;
}

void resuelveCaso() {
	int peso;
	bool balanceado = estaBalanceado(peso);
	if (balanceado) cout << "SI\n";
	else cout << "NO\n";
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	system("pause");
	return 0;
}
