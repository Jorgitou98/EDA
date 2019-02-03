#include <iostream>
#include <string>
#include "Fecha.h"
#include "Consutorio.h"
using namespace std;

void realizaOperacion(string operacion, consultorio& consul){
	string medico;
	if (operacion == "nuevoMedico"){
		cin >> medico;
		consul.nuevoMedico(medico);
	}
	else if (operacion == "pideConsulta"){
		string paciente;
		int dia, hora, minutos;
		cin >> paciente >> medico >> dia >> hora >> minutos;
		fecha fechaEscogida = fecha(dia, hora, minutos);
		try{
			consul.pideConsulta(paciente, medico, fechaEscogida);
		}
		catch (invalid_argument ia){
			cout << ia.what() << '\n' << "---\n";
		}
	}
	else if (operacion == "siguientePaciente"){
		cin >> medico;
		try{
			string paciente = consul.siguientePaciente(medico);
			cout << "Siguiente paciente doctor " << medico << '\n' << paciente << '\n';
		}
		catch (invalid_argument ia){
			cout << ia.what() << '\n';
		}
		cout << "---\n";
	}
	else if (operacion == "atiendeConsulta"){
		cin >> medico;
		try{
			consul.atiendeConsulta(medico);
		}
		catch (invalid_argument ia){
			cout << ia.what() << '\n' << "---\n";
		}
	}
	else if (operacion == "listaPacientes"){
		int dia;
		cin >> medico >> dia;
		try{
			list <pair<fecha, string>> lista = consul.listaPacientes(medico, dia);
			cout << "Doctor " << medico << " dia " << dia << '\n';
			for (auto l : lista){
				cout << l.second << " " << l.first << '\n';
			}
		}
		catch (invalid_argument ia){
			cout << ia.what() << '\n';
		}
		cout << "---\n";
	}
}


bool resuelveCaso() {
	int operaciones;
	cin >> operaciones;
	if (!std::cin)
		return false;
	string operacion;
	consultorio consul;
	for (int i = 0; i < operaciones; ++i){
		cin >> operacion;
		realizaOperacion(operacion, consul);
	}
	cout << "------\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}