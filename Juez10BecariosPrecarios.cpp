#include <iostream>
using namespace std;


int maxLongRamas(int k, int jefesActuales){
	int elem, becariosPrecarios = 0;
	cin >> elem;
	if (elem == 0) {
		if (jefesActuales >= k) return 1;
		else return 0;
	}
	else{
		for (int i = 0; i < elem; ++i){
			becariosPrecarios += maxLongRamas(k, jefesActuales + 1);
		}
		return becariosPrecarios;
	}
}

bool resuelveCaso() {
	int k;
	cin >> k;
	if (!std::cin)
		return false;
	int becariosPrecarios = maxLongRamas(k, 0);
	cout << becariosPrecarios << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
