// DG31, Jorge Villarrubia
#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class monomio{
	private:
		int coeficiente, grado;
	public:
		monomio(int coef1, int grado1){
			coeficiente = coef1;
			grado = grado1;
		}
		int getGrado(){
			return grado;
		}
		void setNuevoCoeficiente(int masCoeficiente){
			coeficiente += masCoeficiente;
		}
		int getCoeficiente(){
			return coeficiente;
		}

		
};
class polinomio{
	private:
		vector <monomio> poli;

	public:	
		void anadirMonomio(monomio m){
			if (poli.size() == 0){
				poli.push_back(m);
			}
			else{
				int i = 0;
				int miGrado = m.getGrado();
				bool colocado = false;
				while (!colocado && i < poli.size()){
					if (poli[i].getGrado() == miGrado) {
						poli[miGrado].setNuevoCoeficiente(m.getCoeficiente());
						colocado = true;
					}
					else if (poli[i].getGrado() > miGrado) {
						auto it = poli.begin();
						poli.insert(it+i, 1, m);
						colocado = true;
					}
					++i;
				}
				if (!colocado){
					poli.push_back(m);
				}
			}
		}
		int evPolinomio(int x){
			int resultado = 0;
			int ultimaPotencia = 1;
			int ultimoGrado = 0;
			for (int i = 0; i < poli.size(); ++i){
				ultimaPotencia *= pow(x, poli[i].getGrado() - ultimoGrado);
				ultimoGrado = poli[i].getGrado();
				resultado += poli[i].getCoeficiente() * ultimaPotencia;
			}
			return resultado;
		}
};

#endif