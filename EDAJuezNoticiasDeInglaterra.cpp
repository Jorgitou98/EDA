#include <iostream>
#include <vector>
using namespace std;

struct tFiguraDiagonal {
	bool hayReina;
	bool hayTorre;
};

void torresReinas(int & soluciones, int t, int r, vector <bool> &columnasMarcadas, vector <tFiguraDiagonal> &diagonalesMarcadas, int fila, int N, vector<vector<bool>> const& posRotas) {
	for (int i = 0; i < N; ++i) {
		if (!posRotas[fila][i] && !columnasMarcadas[i] && !diagonalesMarcadas[i - fila + N].hayReina && !diagonalesMarcadas[i - fila + N].hayTorre && !diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayReina && !diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayTorre && r > 0) {
			columnasMarcadas[i] = true;
			diagonalesMarcadas[i - fila + N].hayReina = true;
			diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayReina = true;
			if (fila == N - 1) soluciones++;
			else torresReinas(soluciones, t, r - 1, columnasMarcadas, diagonalesMarcadas, fila + 1, N, posRotas);
			columnasMarcadas[i] = false;
			diagonalesMarcadas[i - fila + N].hayReina = false;
			diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayReina = false;
		}
		if (!posRotas[fila][i] && !columnasMarcadas[i] && !diagonalesMarcadas[i - fila + N].hayReina && !diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayReina && t > 0) {
			bool habiaYaTorreDiagonal1 = diagonalesMarcadas[i - fila + N].hayTorre;
			bool habiaYaTorreDiagonal2 = diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayTorre;
			columnasMarcadas[i] = true;
			diagonalesMarcadas[i - fila + N].hayTorre = true;
			diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayTorre = true;
			if (fila == N - 1) soluciones++;
			else torresReinas(soluciones, t - 1, r, columnasMarcadas, diagonalesMarcadas, fila + 1, N, posRotas);
			columnasMarcadas[i] = false;
			if (!habiaYaTorreDiagonal1) diagonalesMarcadas[i - fila + N].hayTorre = false;
			if (!habiaYaTorreDiagonal2) diagonalesMarcadas[(i + 1 + fila + 1 + 2 * N - 2) - 1].hayTorre = false;
		}
	}
}



bool resuelveCaso() {
	int t, r;
	cin >> t >> r;
	if (!std::cin)
		return false;
	int rotas;
	cin >> rotas;
	int pos1, pos2;
	vector<vector<bool>> posRotas;
	for (int i = 0; i < t + r; ++i) {
		vector<bool> posRota1(t+r, false);
		posRotas.push_back(posRota1);
	}
	for (int i = 0; i < rotas; ++i) {
		cin >> pos1 >> pos2;
		posRotas[pos1-1][pos2-1] = true;
	}
	int soluciones = 0;
	vector <bool> columnasMarcadas(t + r, false);
	vector <tFiguraDiagonal> diagonalesMarcadas;
	tFiguraDiagonal valor;
	valor.hayReina = false;
	valor.hayTorre = false;
	for (int j = 0; j < 4 * (t + r) - 2; ++j) {
		diagonalesMarcadas.push_back(valor);
	}
	torresReinas(soluciones, t, r, columnasMarcadas, diagonalesMarcadas, 0, t + r, posRotas);
	cout << soluciones << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}