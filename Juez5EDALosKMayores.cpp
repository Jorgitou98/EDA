#include "conjunto.h"

bool resuelveCaso() {
	char datos;
	int k;
	cin >> datos;
	if (!std::cin)
		return false;
	cin >> k;
	if (datos == 'N'){
		set <int> cjto = set<int>(3);
		int elem, pos;
		cin >> elem;
		while (elem != -1){
			if (cjto.size() < k) cjto.insert(elem);
			else if (cjto.lowerElement() < elem && !cjto.contains(elem, pos)){ // En este caso me da iual la posicion. Es por reutilizar la funcion y no hacer otra que solo mire si esta
				cjto.eraseLowerElement();
				cjto.insert(elem);
			}
			cin >> elem;
		}
		cout << cjto;
	}
	else if (datos == 'P'){
		set <string> cjto = set<string>(3);
		string cadena;
		int pos;
		cin >> cadena;
		while (cadena != "FIN"){
			if (cjto.size() < k) cjto.insert(cadena);
			else if (cjto.lowerElement() < cadena && !cjto.contains(cadena, pos)){
				cjto.eraseLowerElement();
				cjto.insert(cadena);
			}
			cin >> cadena;
		}
		cout << cjto;
	}
		return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}