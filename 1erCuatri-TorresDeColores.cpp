// DG31, Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;


void escribeTorre(vector <char> const& u){
	for (int i = 0; i < u.size(); ++i){
		if (u[i] == 'a') cout << "azul ";
		else if (u[i] == 'r') cout << "rojo ";
		else cout << "verde ";
	}
	cout << '\n';
}

void torre(int altura, int aRestan, int rRestan, int vRestan, vector <char> &u, int aTotal, int rTotal, int vTotal, bool &haySolucion){
	if (aRestan > 0 && u.size() < altura){
		u.push_back('a'); // Marco la azul que pongo
		if (rTotal > aTotal + 1 + vTotal && u.size() == altura) {
			escribeTorre(u);
			haySolucion = true;
		}
		torre(altura, aRestan - 1, rRestan, vRestan, u, aTotal+1, rTotal, vTotal, haySolucion);
		u.pop_back();  // Desmarco el azul puesto
	}
	if (rRestan > 0 && u.size() < altura){
		u.push_back('r'); // Marco la azul que pongo
		if (rTotal + 1 > aTotal + vTotal && u.size() == altura) {
			escribeTorre(u);
			haySolucion = true;
		}
		torre(altura, aRestan, rRestan - 1, vRestan, u, aTotal, rTotal + 1, vTotal, haySolucion);
		u.pop_back();  // Desmarco el azul puesto
	}
	if (vRestan > 0 && u[u.size() - 1] != 'v' && vTotal < aTotal && u.size() < altura){
		u.push_back('v'); // Marco la azul que pongo
		if (rTotal > aTotal + vTotal + 1 && u.size() == altura) {
			escribeTorre(u);
			haySolucion = true;
		}
		torre(altura, aRestan, rRestan, vRestan - 1, u, aTotal, rTotal, vTotal + 1, haySolucion);
		u.pop_back();  // Desmarco el azul puesto
	}
}




bool resuelveCaso() {
	int alt, a, r, v;
	cin >> alt >> a >> r >> v;
	if (alt == 0 && a == 0 && r == 0 && v == 0)
		return false;
	if (r > 0) {
		vector <char> u;
		u.push_back('r');
		bool haySolucion = false;
		torre(alt, a, r - 1, v, u, 0, 1, 0, haySolucion);
		if (!haySolucion) cout << "SIN SOLUCION \n";
	}
	else cout << "SIN SOLUCION \n";
		return true;
}
int main() {
	while (resuelveCaso());
	system("pause");
	return 0;
}