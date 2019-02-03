#include"Complejo.h"


void resuelveCaso(){
	float real, imaginario;
	int iteraciones;
	cin >> real >> imaginario >> iteraciones;
	complejo <float> c = complejo<float>(real, imaginario);
	complejo <float> z = complejo<float>(0, 0);
	int i = 0;
	bool cumple = true;
	while (cumple && i < iteraciones){
		z = z * z + c;
		if (z.modulo() > 2) cumple = false;
		i++;
	}
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