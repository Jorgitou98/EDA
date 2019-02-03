//DG31 Jorge Villarrubia
#include <iostream>
#include <vector>
using namespace std;

void manerasNReinas(int N, vector <bool> &marcaColumnas, vector <bool> &marcaDiagonales, int fila, int&maneras){
	for (int i = 0; i < N; ++i){
		if (!marcaColumnas[i] && !marcaDiagonales[i - fila + N] && !marcaDiagonales[(i + 1 + fila + 1 + 2 * N - 2) - 1]){
			marcaColumnas[i] = true;
			marcaDiagonales[i - fila + N] = true;
			marcaDiagonales[(i + 1 + fila + 1 + 2 * N - 2) - 1] = true;
			if (fila == N - 1) maneras++;
			else{
				manerasNReinas(N, marcaColumnas, marcaDiagonales, fila +1, maneras);
			}
			marcaColumnas[i] = false;
			marcaDiagonales[i - fila + N] = false;
			marcaDiagonales[(i + 1 + fila + 1 + 2 * N - 2) - 1] = false;
		}
	}
}

void resuelveCaso() {
	int N;
	cin >> N;
	vector <bool> marcaColumna (N, false);
	vector <bool> marcaDiagonal(4 * N - 2, false);
	int maneras = 0;
	manerasNReinas(N, marcaColumna, marcaDiagonal, 0, maneras);
	cout << maneras << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}