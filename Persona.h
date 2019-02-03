#ifndef Persona_h
#define Persona_h
#include <iostream>
#include <string>
using namespace std;

class persona{
 private:
	string nombre;
	int edad;
 public:
	 persona(){}
	 persona(int ed, string nom) : edad(ed), nombre(nom){}
	 string getNombre(){
		 return nombre;
	 }
	 int getEdad(){
		 return edad;
	 }

};

inline ostream &operator << (ostream & out, persona persona1){
	string cad = persona1.getNombre();
	out << cad.substr(1, cad.size()) << '\n';
		return out;
}

#endif