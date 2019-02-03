#include <iostream>
using namespace std;


int maxLongRamas(){
	int elem, max = 0;
	cin >> elem;
	if (elem == 0) return 1;
	else{
		for (int i = 0; i < elem; ++i){
			int maxLongRama = maxLongRamas();
			if (maxLongRama + 1 > max) max = maxLongRama + 1;
		}
		return max;
	}
}


void resuelveCaso() {
	int max = maxLongRamas();
	cout << max << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
