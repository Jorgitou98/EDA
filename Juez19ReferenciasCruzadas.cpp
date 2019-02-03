#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctype.h>
#include <sstream>
using namespace std;

void pasaAMinuscula(string & palabra){
	for (int i = 0; i < palabra.size(); ++i){
		if (isupper(palabra[i])){
			palabra[i] = tolower(palabra[i]);
		}
	}
}


bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)
		return false;
	char aux;
	cin.get(aux);
	string linea, palabra;
	map <string, vector<int>> palabrasTexto;
	stringstream ss;
	for (int i = 0; i < N; ++i){ // Coste lineal en el numero de palabras del texto
		getline(cin, linea);
		ss.clear();
		ss << linea;
		while (ss >> palabra){
			if (palabra.size() > 2){
				pasaAMinuscula(palabra);
				if (palabrasTexto.count(palabra)){
					if (palabrasTexto.at(palabra).back() != i + 1){
						palabrasTexto.at(palabra).push_back(i + 1);
					}
				}
				else palabrasTexto.insert({ palabra, { i + 1 } });
			}
		}
	}

	for (auto par: palabrasTexto){
		cout << par.first << " ";
		for (int i = 0; i < par.second.size(); ++i){
			cout << par.second[i];
			if (i < par.second.size() - 1) cout << " ";
		}
		cout << '\n';
	}
	cout << "----\n";


		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}