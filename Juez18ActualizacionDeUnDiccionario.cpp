#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

void variacionesEnDiccionario(map <string, int> const& dic1, map <string, int> const& dic2, vector <string> & nuevos, vector <string> & quitados,
	vector <string> & modificados){

	auto it1 = dic1.begin();
	auto it2 = dic2.begin();
	while (it1 != dic1.end() || it2 != dic2.end()){
		if (it1 == dic1.end()){
			nuevos.push_back(it2->first);
			it2++;
		}
		else if (it2 == dic2.end()){
			quitados.push_back(it1->first);
			it1++;
		}
		else{
			if (it1->first == it2->first && it1->second != it2->second){
				modificados.push_back(it1->first);
				it1++;
				it2++;
			}
			else if (it1->first > it2->first){
				nuevos.push_back(it2->first);
				it2++;
			}
			else if (it1->first < it2->first){
				quitados.push_back(it1->first);
				it1++;
			}
			else{
				it1++;
				it2++;
			}
		}
	}
}



void resuelveCaso() {
	string linea1, linea2;
	getline(cin, linea1);
	stringstream ss;
	ss << linea1;
	string clave;
	int valor;
	map <string, int> dic1, dic2;
	while (ss >> clave >> valor){
		dic1.insert({ clave, valor });
	}
	getline(cin, linea2);
	ss.clear();
	ss << linea2;
	while (ss >> clave >> valor){
		dic2.insert({ clave, valor });
	}
	vector <string> nuevos;
	vector <string> quitados;
	vector <string> modificados;
	variacionesEnDiccionario(dic1, dic2, nuevos, quitados, modificados);
	if (nuevos.size() == 0 && quitados.size() == 0 && modificados.size() == 0) cout << "Sin cambios\n";
	else{
		if (nuevos.size() > 0) {
			cout << "+ ";
			for (int i = 0; i < nuevos.size(); ++i){
				cout << nuevos[i];
				if (i < nuevos.size()) cout << " ";
			}
			cout << '\n';
		}

		if (quitados.size() > 0) {
			cout << "- ";
			for (int i = 0; i < quitados.size(); ++i){
				cout << quitados[i];
				if (i < quitados.size()) cout << " ";
			}
			cout << '\n';
		}

		if (modificados.size() > 0) {
			cout << "* ";
			for (int i = 0; i < modificados.size(); ++i){
				cout << modificados[i];
				if (i < modificados.size()) cout << " ";
			}
			cout << '\n';
		}
	}
	cout << "----\n";
}
int main() {
	char aux;
	int numCasos;
	std::cin >> numCasos;
	cin.get(aux);
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}