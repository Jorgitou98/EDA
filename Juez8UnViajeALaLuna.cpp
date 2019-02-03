#include "List.h"
#include "EntreValores.h"
bool resuelveCaso() {
	int personas, edadMinima, edadMaxima;
	cin >> personas >> edadMinima >> edadMaxima;
	if (personas == 0 && edadMinima == 0 && edadMaxima == 0)
		return false;
	list<persona> lista = list <persona>();
	int edad;
	string nombre;
	char aux;
	for (int i = 0; i < personas; ++i){
		cin >> edad;
		getline(cin, nombre);
		lista.push_back(persona(edad, nombre));
	}
	entreValores pred = entreValores(edadMinima, edadMaxima);
	lista.remove_if(pred);
	for (persona p : lista){
		cout << p;
	}
	cout << "---" << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}