//DG31, Jorge Villarrubia Elvira
#include"queue.h"
bool resuelveCaso() {
	int valor;
	cin >> valor;
	if (!std::cin)
		return false;
	queue <int> cola = queue<int>();
	while (valor != 0){
		cola.push(valor);
		cin >> valor;
	}
	cola.duplicaElementos();
	cola.muestraContenido();
	cola.~queue();
		return true;
}
int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	while (resuelveCaso());
	return 0;
}