#include <iostream>
#include <vector>
#include "TreeMap_AVL.h"
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
		int elem, k1, k2;
		map<int, int> arbol;
		for (int i = 0; i < n; ++i) {
			cin >> elem;
			arbol.insert({ elem,1 });
		}
		cin >> k1 >> k2;
		vector<int> v = arbol.inorderValues(k1, k2);
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i];
			if (i < v.size() - 1) cout << " ";
		}
		cout << '\n';

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}