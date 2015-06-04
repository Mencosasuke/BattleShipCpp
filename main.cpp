#include <iostream>
#include <windows.h>

#include "Nodo.h"

using namespace std;

void comenzarJuego(Nodo **cabecera){
	
	Nodo *auxV = (*cabecera)->abajo;
	Nodo *auxH = auxV->derecha;
	
	while(auxV != NULL){
		while(auxH != NULL){
			cout<<" "<<auxH->valor<<"  ";
			auxH = auxH->derecha;
			Sleep(500);
		}
		cout<<endl<<endl;
		auxV = auxV->abajo;
		if(auxV != NULL){
			auxH = auxV->derecha;	
		}
		
	}
}

void crearLista(int nf, int nc){
	Nodo *cabecera = new Nodo();
	Nodo *ultimoH = NULL;
	Nodo *ultimoV = NULL;
	
	for(int i = 0; i < nc; i++){
		Nodo *p = new Nodo();
		p->valor = i + 1;
		
		if(cabecera->derecha == NULL){
			p->izquierda = cabecera;
			cabecera->derecha = p;
			ultimoH = cabecera->derecha;
		}else{
			p->izquierda = ultimoH;
			ultimoH->derecha = p;
			ultimoH = ultimoH->derecha;
		}
	}
	
	for(int i = 0; i < nf; i++){
		Nodo *p = new Nodo();
		p->valor = i + 1;
		
		if(cabecera->abajo == NULL){
			p->arriba = cabecera;
			cabecera->abajo = p;
			ultimoV = cabecera->abajo;
		}else{
			p->arriba = ultimoV;
			ultimoV->abajo = p;
			ultimoV = ultimoV->abajo;
		}
	}
	
	/*Nodo *aux = cabecera->derecha;
	while(aux != NULL){
		if(aux->derecha != NULL){
			cout<<" "<<aux->izquierda->valor<<" "<<aux->valor<<" "<<aux->derecha->valor<<" || ";
		}
		aux = aux->derecha;
	}
	cout<<endl<<endl;
	aux = cabecera->abajo;
	while(aux != NULL){
		if(aux->abajo != NULL){
			cout<<" "<<aux->arriba->valor<<" "<<aux->valor<<" "<<aux->abajo->valor<<" || ";	
		}
		aux = aux->abajo;
	}*/

	Nodo *auxH = cabecera->derecha;
	Nodo *auxV = cabecera->abajo;
	Nodo *auxUltimoH = cabecera->derecha;
	Nodo *auxUltimoV = cabecera->abajo;
	//int x = 1;
	// Inserta nuevos nodos en toda la matriz
	while(auxV != NULL){
		while(auxH != NULL){
			Nodo *q = new Nodo();
			//q->valor = x;
			//x++;
			
			q->izquierda = auxUltimoV;
			auxUltimoV->derecha = q;
			
			q->arriba = auxUltimoH;
			auxUltimoH->abajo = q;
			
			auxUltimoH = auxUltimoH->derecha;
			auxUltimoV = q;
			
			auxH = auxH->derecha;
			//cout<<q->arriba->valor<<"-"<<q->valor<<"-"<<"||";
			//cout<<q->izquierda->valor<<"-"<<q->valor<<"-"<<"||";
		}
		auxUltimoH = auxV->derecha;
		auxH = cabecera->derecha;
		auxV = auxV->abajo;
		auxUltimoV = auxV;
		//cout<<endl;
	}
	
	comenzarJuego(&cabecera);
	
	/*auxV = cabecera->abajo;
	auxH = auxV->derecha;
	
	while(auxV != NULL){
		while(auxH != NULL){
			/*if(auxH->arriba != NULL){
				cout<<auxH->arriba->valor<<"^";
			}
			if(auxH->abajo != NULL){
				cout<<auxH->abajo->valor<<"v";
			}
			cout<<" "<<auxH->valor<<"  ";
			/*if(auxH->izquierda != NULL){
				cout<<"<"<<auxH->izquierda->valor;
			}
			if(auxH->derecha != NULL){
				cout<<">"<<auxH->derecha->valor;
			}
			cout<<"\t";
			auxH = auxH->derecha;
		}
		cout<<endl<<endl;
		auxV = auxV->abajo;
		if(auxV != NULL){
			auxH = auxV->derecha;	
		}
		
	}
	
	system("pause");*/
}

int main(int argc, char** argv) {
	// Opción del menú
	int op = 0;
	// Dimension con que se creará la matriz
	int noCol = 0;
	int noFil = 0;
	
	do{
		system("cls");
		cout<<"*****************MENU*****************\n";
		cout<<"*         1 - NUEVO JUEGO            *\n";
		cout<<"*         2 - SALIR                  *\n";
		cout<<"**************************************\n\n";
		cout<<"Escriba la opcion que desee: [ ]\b\b";
		cin>>op;
		cin.ignore();
		switch(op){
			case 1:
				do{
					system("cls");
					cout<<"\nCuantas columnas desea? (minimo 5) [ ]\b\b";
					cin>>noCol;
					cin.ignore();
				}while(noCol < 5);
				
				do{
					system("cls");
					cout<<"\nCuantas filas desea? (minimo 5) [ ]\b\b";
					cin>>noFil;
					cin.ignore();
				}while(noFil < 5);
				system("cls");
				
				crearLista(noFil, noCol);
				
				break;
			case 2:
				cout<<"\n\nGracias por jugar!"<<endl;
				break;
			default:
				cout<<"\n\nIngrese una opcion valida."<<endl;
				break;
		}
		system("pause");
	}while(op != 2);
}
