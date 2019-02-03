#ifndef EntreValores_h
#define EntreValores_h
#include "Persona.h"
class entreValores{
private:
	int minIntervalo, maxIntervalo;
public:
	entreValores(int min, int max): minIntervalo(min), maxIntervalo(max){}
	bool operator()(persona p){
		return (minIntervalo > p.getEdad() || p.getEdad() > maxIntervalo);
	}
};
#endif