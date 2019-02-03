// DG31, Jorge Villarrubia Elvira
#ifndef HORA_H
#define HORA_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;
class hora{
	private:
		int segundos, minutos, horas;
	public:
		int getSegundos(){
			return segundos;
		}
		int getMinutos(){
			return minutos;
		}
		int getHoras(){
			return horas;
		}
		hora(int horas1, int minutos1, int segundos1){
			if (horas1 < 0 || horas1 > 23) throw domain_error("ERROR");
			if (minutos1 < 0 || minutos1 > 59) throw domain_error("ERROR");
			if (segundos1 < 0 || segundos1 > 59) throw domain_error("ERROR");
			horas = horas1;
			minutos = minutos1;
			segundos = segundos1;
		}
		hora(){};
		bool operator<(hora const& hora2) const{
			if (horas < hora2.horas) return true;
			else if (horas > hora2.horas) return false;
			else{
				if (minutos <  hora2.minutos) return true;
				else if (minutos >  hora2.minutos) return false;
				else{
					if (segundos <  hora2.segundos) return true;
					else return false;
				}
			}
		}
		bool operator==(hora const& hora2){
			return (horas == hora2.horas && minutos == hora2.minutos && segundos == hora2.segundos);
		}

		hora operator+(hora const& hora1){
			hora resultado;
			int seg = (segundos + hora1.segundos);
			resultado.segundos = seg % 60;
			int min = minutos + hora1.minutos + (seg / 60);
			resultado.minutos = min  % 60;
			int h = horas + hora1.horas + min / 60;
			if (h > 23) throw domain_error("ERROR");
			else resultado.horas = h;
			return resultado;
		}

};

class pelicula{
	private:
	 string nombrePeli;
	 hora finPeli;
	public:
		pelicula(){}
		pelicula(hora iniPeli, hora duracion, string nombre){
			finPeli = iniPeli + duracion;
			nombrePeli = nombre;
		}
		hora getFinPeli(){
			return finPeli;
		}
		string getNombre(){
			return nombrePeli;
		}
		bool operator <(pelicula const& peli2){
			if (finPeli < peli2.finPeli || finPeli == peli2.finPeli && nombrePeli < peli2.nombrePeli) return true;
			else return false;
		}
};


inline ostream & operator <<(ostream & out, hora hora2){
	out << setfill('0') << setw(2) << hora2.getHoras() << ":" << setfill('0') << setw(2) << hora2.getMinutos() << ":" << setfill('0') << setw(2) << hora2.getSegundos();
	return out;
}
inline istream & operator >>(istream & in, hora &hora2){
	int horas1, minutos1, segundos1;
	char aux;
	in >> horas1 >> aux >> minutos1 >> aux >> segundos1;
	hora2 = hora(horas1, minutos1, segundos1);
	return in;
}
#endif