#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "autoescuela.h"
using namespace std;

void realizaOperacion(string operacion, autoescuela& escuela){
	string alumno, profesor;
	if (operacion == "alta"){
		cin >> alumno >> profesor;
		escuela.alta(alumno, profesor);
	}
	else if (operacion == "es_alumno"){
		cin >> alumno >> profesor;
		if (escuela.es_alumno(alumno, profesor)) cout << alumno + " es alumno de " + profesor;
		else cout << alumno + " no es alumno de " + profesor;
		cout << '\n';
	}
	else if (operacion == "puntuacion"){
		cin >> alumno;
		try{
			int punt = escuela.puntuaciones(alumno);
			cout << "Puntuacion de " << alumno << ": " << punt;
		}
		catch (domain_error ia){
			cout << "ERROR";
		}
		cout << "\n";
	}
	else if (operacion == "actualizar"){
		int punt;
		cin >> alumno >> punt;
		try{
			escuela.actualizar(alumno, punt);
		}
		catch (domain_error ia){
			cout << "ERROR\n";
		}
	}
	else if (operacion == "examen"){
		int punt;
		cin >> profesor >> punt;
		list <string> v = escuela.examen(profesor, punt);
		cout << "Alumnos de " << profesor << " a examen:\n";
		for (string i: v){
			cout << i << '\n';
		}
	}
	else if (operacion == "aprobar"){
		cin >> alumno;
		try{
			escuela.aprobar(alumno);
		}
		catch (domain_error ia){
			cout << "ERROR\n";
		}
	}
}



bool resuelveCaso() {
	string operacion;
	cin >> operacion;
	if (!std::cin)
		return false;
	autoescuela escuela;
	while (operacion != "FIN"){
		realizaOperacion(operacion, escuela);
		cin >> operacion;
	}
	cout << "------\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}