#include <iostream>
using namespace std;

class Nodo{
	public:
		Nodo *arriba;
		Nodo *abajo;
		Nodo *izquierda;
		Nodo *derecha;
		int valor;
		
		Nodo();
};

Nodo::Nodo(){
	arriba = NULL;
	abajo = NULL;
	izquierda = NULL;
	derecha = NULL;
	valor = 0;
}
