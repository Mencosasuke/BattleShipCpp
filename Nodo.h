#include <iostream>
using namespace std;

class Nodo{
	public:
		Nodo *arriba;
		Nodo *abajo;
		Nodo *izquierda;
		Nodo *derecha;
		int valor;
		int x;
		int y;
		bool cabecera;
		Nodo();
};

Nodo::Nodo(){
	arriba = NULL;
	abajo = NULL;
	izquierda = NULL;
	derecha = NULL;
	valor = 0;
	x = 0;
	y = 0;
	cabecera = false;
}
