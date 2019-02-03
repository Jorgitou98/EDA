#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int maxCapsSeguidosSinRepetir(vector <int> const& v){ // Coste lineal en el numero de capitulos del vector. Las inserciones y consultas a count son constantes
	unordered_map <int, int> capsEmitidos;
	int max = 0, maxActual = 0, principioCicloNoRepetidos = 0; 
	for (int i = 0; i < v.size(); ++i){
		if (capsEmitidos.count(v[i]) && capsEmitidos.at(v[i]) >= principioCicloNoRepetidos) {
			maxActual = i - capsEmitidos.at(v[i]);
			principioCicloNoRepetidos = capsEmitidos.at(v[i]) + 1;
			capsEmitidos.at(v[i]) = i;
		}
		else if (!capsEmitidos.count(v[i])){
			capsEmitidos.insert({ v[i], i });
			maxActual++;
		}
		else{
			capsEmitidos.at(v[i]) = i;
			maxActual++;
		}
		if (maxActual > max) max = maxActual;
	}
	return max;
}

void resuelveCaso() {
	int numCapitulos, capitulo;
	vector <int> vCaps;
	cin >> numCapitulos;
	for (int i = 0; i < numCapitulos; ++i){
		cin >> capitulo;
		vCaps.push_back(capitulo);
	}
	cout << maxCapsSeguidosSinRepetir(vCaps) << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}