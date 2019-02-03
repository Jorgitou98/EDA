#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "ipud.h"
using namespace std;

void realizaOperacion(string operacion, ipud& ipod){
	string cancion, artista;
	int duracion;
	if (operacion == "addSong"){
		cin >> cancion >> artista >> duracion;
		try{
			ipod.addSong(cancion, artista, duracion);
		}
		catch (domain_error e){
			cout << e.what() << " addSong\n";
		}
	}
	else if (operacion == "addToPlaylist"){
		cin >> cancion;
		try{
			ipod.addToPlaylist(cancion);
		}
		catch (domain_error e){
			cout << e.what() << " addToPlaylist\n";
		}
	}
	else if (operacion == "current"){
		try{
			ipod.current();
		}
		catch (domain_error e){
			cout << e.what() << " current\n";
		}
	}
	else if (operacion == "play"){
		ipod.play();
		cout << '\n';
	}
	else if (operacion == "totalTime"){
		cout << "Tiempo total " << ipod.totalTime() << '\n';
	}
	else if (operacion == "recent"){
		int N;
		cin >> N;
		list <string> l = ipod.recent(N);
		if (l.size() > 0){
			cout << "Las " << l.size() << " mas recientes\n";
			for (auto e : l){
				cout << "    " << e << '\n';
			}
		}
		else cout << "No hay canciones recientes\n";
	}
	else if (operacion == "deleteSong"){
		cin >> cancion;
		ipod.deleteSong(cancion);
	}
}



bool resuelveCaso() {
	string operacion;
	cin >> operacion;
	if (!std::cin)
		return false;
	ipud ipod;
	while (operacion != "FIN"){
		realizaOperacion(operacion, ipod);
		cin >> operacion;
	}
	cout << "----\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}