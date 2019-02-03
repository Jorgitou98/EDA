#include "Hora.h"

bool resuelveCaso() {
	int pelis;
	cin >> pelis;
	if (pelis == 0)
		return false;
	hora inicio, duracion;
	string nomPelicula;
	pelicula peli;
	vector <pelicula> vectPelis;
	for (int i = 0; i < pelis; ++i){
		cin >> inicio >> duracion;
		getline(cin, nomPelicula);
		peli = pelicula(inicio, duracion, nomPelicula);
		vectPelis.push_back(peli);
	}
	sort(vectPelis.begin(), vectPelis.end());
	for (int i = 0; i < pelis; ++i){
		cout << vectPelis[i].getFinPeli() << vectPelis[i].getNombre() << '\n';
	}
	cout << "---\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
