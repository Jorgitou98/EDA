//DG31, Jorge Villarrubia
#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <cmath>
#include <cstddef>
using namespace std;

template<class T>
class complejo{
	private:
		T parteReal, parteImaginaria;
	public:
		complejo(T real, T imaginario){
			parteReal = real;
			parteImaginaria = imaginario;
		}
		complejo operator+(complejo const& numC){
			complejo resultado = complejo(parteReal + numC.parteReal, parteImaginaria + numC.parteImaginaria);
			return resultado;
		}
		complejo operator*(complejo const& numC){
			T real = parteReal * numC.parteReal - parteImaginaria * numC.parteImaginaria;
			T imagin = parteImaginaria * numC.parteReal + parteReal * numC.parteImaginaria;
			complejo resultado = complejo(real, imagin);
			return resultado;
		}
		T modulo(){
			return sqrt(pow(parteReal, 2) + pow(parteImaginaria, 2));
		}
};

#endif