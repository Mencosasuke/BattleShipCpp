#include <iostream>
#include <windows.h>
#include <time.h>

#include "Nodo.h"

using namespace std;

const int IDENTIFICADOR_VACIO = 0;				// Espacio vacío ( _ )
const int IDENTIFICADOR_NAVIO = 1;				// Navíos intactos ( o )
const int IDENTIFICADOR_NAVIO_DESTRUIDO = 2;	// Navíos destruidos ( x )
const int IDENTIFICADOR_DISPARO_FALLADO = 3;	// Disparos fallados ( - )

void comenzarJuego(Nodo **cabecera, int nf, int nc){
	
	// Variables necesarias para el control del juego
	int aciertosJugador = 0;
	int aciertosRival = 0;
	int contador;
	
	int turnos = (nf * nc) / 4;
	
	int cordNaveEnemigoX [turnos];
	int cordNaveEnemigoY [turnos];
	int cordDispEnemigoX [turnos];
	int cordDispEnemigoY [turnos];
	
	// Valida que la seleccion de coordenadas (para enemigo o jugador) no haya sido elegida
	bool seleccionValida = false;
	
	srand(time(0));
	
	// Se eligen las coordenadas de los barcos y los disparos enemigos
	for( int i = 0; i < turnos; i++){
		
		// Seleccion de coordenadas de barcos enemigo
		do{
			cordNaveEnemigoX[i] = rand() % nc + 1;
			cordNaveEnemigoY[i] = rand() % nf + 1;
			for(int j = 0; j < turnos; j++){
				if( j != i && (cordNaveEnemigoX[j] == cordNaveEnemigoX[i] && cordNaveEnemigoY[j] == cordNaveEnemigoY[i])){
					seleccionValida = false;
					break;
				}
				seleccionValida = true;
			}
		}while(!seleccionValida);
		seleccionValida = false;
		
		// Seleccion de coordenadas de disparos enemigo
		do{
			cordDispEnemigoX[i] = rand() % nc + 1;
			cordDispEnemigoY[i] = rand() % nf + (nf + 1);
			for(int j = 0; j < turnos; j++){
				if( j != i && (cordDispEnemigoX[j] == cordDispEnemigoX[i] && cordDispEnemigoY[j] == cordDispEnemigoY[i])){
					seleccionValida = false;
					break;
				}
				seleccionValida = true;
			}
		}while(!seleccionValida);
		seleccionValida = false;
	}
	
	cout<<"COORDENADAS NAVES RIVAL: "<<endl;
	for( int i = 0; i < turnos; i++){
		cout<<cordNaveEnemigoY[i]<<","<<cordNaveEnemigoX[i]<<endl;
	}
	cout<<"COORDENADAS DISPAROS RIVAL: "<<endl;
	for( int i = 0; i < turnos; i++){
		cout<<cordDispEnemigoY[i]<<","<<cordDispEnemigoX[i]<<endl;
	}
	
	// Se eligen las coordenadas de los barcos y los disparos del jugador
	
	int cordNaveJugadorX [turnos];
	int cordNaveJugadorY [turnos];
	int cordDispJugadorX [turnos];
	int cordDispJugadorY [turnos];
	
	int cordX = 0;
	int cordY = 0;
	
	//system("cls");
	cout<<"*************** INGRESO COORDENADAS DE BARCOS JUGADOR ***************"<<endl<<endl;

	for( int i = 0; i < turnos; i++){
		
		// Seleccion de coordenadas de barcos jugador
		do{
			// Selección de coordenada X
			do{
				cout<<"Ingrese coordenada X: [  ]\b\b\b";
				cin>>cordX;
				cin.ignore();
				if(cordX > 0 && cordX <= nc){
					seleccionValida = true;
				}else{
					cout<<"Coordenada fuera de rango. Intente de nuevo."<<endl;
				}
			}while(!seleccionValida);
			seleccionValida = false;
			
			// Selección de coordenada Y
			do{
				cout<<"Ingrese coordenada Y: [  ]\b\b\b";
				cin>>cordY;
				cin.ignore();
				if(cordY > nf && cordY <= (nf*2)){
					seleccionValida = true;
				}else{
					cout<<"Coordenada fuera de rango. Intente de nuevo."<<endl;
				}
			}while(!seleccionValida);
			seleccionValida = false;
			
			for(int j = 0; j < turnos; j++){
				if( j != i && (cordNaveJugadorX[j] == cordX && cordNaveJugadorY[j] == cordY)){
					seleccionValida = false;
					cout<<endl<<endl<<"Esta coordenada ya existe. Elija otra por favor."<<endl<<endl;
					break;
				}
				seleccionValida = true;
			}
			if(seleccionValida){
				cordNaveJugadorX[i] = cordX;
				cordNaveJugadorY[i] = cordY;
			}
		}while(!seleccionValida);		
	}
	
	//system("cls");
	cout<<"COORDENADAS NAVES JUGADOR: "<<endl;
	for( int i = 0; i < turnos; i++){
		cout<<cordNaveJugadorY[i]<<","<<cordNaveJugadorX[i]<<endl;
	}
	cout<<"*************** INGRESO COORDENADAS DE ATAQUE A OPONENTE ***************"<<endl<<endl;

	for( int i = 0; i < turnos; i++){
		// Seleccion de coordenadas de disparos jugador
		do{
			// Selección de coordenada X
			do{
				cout<<"Ingrese coordenada X: [  ]\b\b\b";
				cin>>cordX;
				cin.ignore();
				if(cordX > 0 && cordX <= nc){
					seleccionValida = true;
				}else{
					cout<<"Coordenada fuera de rango. Intente de nuevo."<<endl;
				}
			}while(!seleccionValida);
			seleccionValida = false;
			
			// Selección de coordenada Y
			do{
				cout<<"Ingrese coordenada Y: [  ]\b\b\b";
				cin>>cordY;
				cin.ignore();
				if(cordY > 0 && cordY <= nf){
					seleccionValida = true;
				}else{
					cout<<"Coordenada fuera de rango. Intente de nuevo."<<endl;
				}
			}while(!seleccionValida);
			seleccionValida = false;
			
			for(int j = 0; j < turnos; j++){
				if( j != i && (cordDispJugadorX[j] == cordDispJugadorX[i] && cordNaveJugadorY[j] == cordNaveJugadorY[i])){
					seleccionValida = false;
					cout<<endl<<endl<<"Esta coordenada ya existe. Elija otra por favor."<<endl<<endl;
					break;
				}
				seleccionValida = true;
			}
			if(seleccionValida){
				cordDispJugadorX[i] = cordX;
				cordDispJugadorY[i] = cordY;
			}
		}while(!seleccionValida);
	}
	
	
	cout<<"COORDENADAS DISPAROS RIVAL: "<<endl;
	for( int i = 0; i < turnos; i++){
		cout<<cordDispJugadorY[i]<<","<<cordDispJugadorX[i]<<endl;
	}
	
	system("pause");
	
	system("cls");
	
	// Imprime el tablero del juego.
	system("cls");
	Nodo *auxV = (*cabecera);
	Nodo *auxH = auxV;
	
	contador = 0;
	while(auxV != NULL){
		
		while(auxH != NULL){
			//if(auxH->valor == IDENTIFICADOR_VACIO){
			if(auxH->cabecera){
				cout<<" "<<auxH->valor<<" ";
			}else{
				cout<<" \xDC ";
				//cout<<" "<<auxH->y<<","<<auxH->x<<" ";
				//cout<<" "<<auxH->valor<<" ";
			}
				//cout<<" "<<auxH->y<<","<<auxH->x<<" ";
				//cout<<" "<<auxH->valor<<" ";
			//}
			auxH = auxH->derecha;
			//Sleep(100);
		}
		if(contador == nf){
			cout<<endl<<endl;
			for(int i = 0; i <= nc; i++){
				cout<<"---";
			}
		}
		cout<<endl<<endl;
		auxV = auxV->abajo;
		auxH = auxV;
		contador++;
	}
	
	system("pause");
	
	// Inicia con el recorrido de la matriz para cambiar el estado a los nodos coordenada seleccionados.
	
	auxV = (*cabecera)->abajo;
	auxH = auxV->derecha;
	
	while(auxV != NULL){
		// Cambia el valor de los nodos para mostrar las SOLO LAS NAVES
		while(auxH != NULL){
			// Camia el valor para la nave enemiga o del jugador
			for( int i = 0; i < turnos; i++){
				if(cordNaveEnemigoX[i] == auxH->x && cordNaveEnemigoY[i] == auxH->y){
					auxH->valor = IDENTIFICADOR_NAVIO;
				}
				if(cordNaveJugadorX[i] == auxH->x && (cordNaveJugadorY[i]) == auxH->y){
					auxH->valor = IDENTIFICADOR_NAVIO;
				}
			}
			auxH = auxH->derecha;
		}
		auxV = auxV->abajo;
		if(auxV != NULL){
			auxH = auxV->derecha;
		}
	}
	
	auxV = (*cabecera)->abajo;
	auxH = auxV->derecha;
	
	while(auxV != NULL){
		// Cambia el valor de los nodos para mostrar los DISPAROS
		while(auxH != NULL){
			// Camia el valor para la nave enemiga o del jugador si el disparo acerto o no, e imprime los disparos es que acertaron
			// Hace la suma de disparos acertados por cada jugador.
			for( int i = 0; i < turnos; i++){
				if(cordDispEnemigoX[i] == auxH->x && cordDispEnemigoY[i] == auxH->y){
					if(auxH->valor = IDENTIFICADOR_NAVIO){
						auxH->valor = IDENTIFICADOR_NAVIO_DESTRUIDO;
						aciertosRival++;
					}else{
						auxH->valor = IDENTIFICADOR_DISPARO_FALLADO;
					}
				}
				if(cordDispJugadorX[i] == auxH->x && cordDispJugadorY[i] == auxH->y){
					if(auxH->valor = IDENTIFICADOR_NAVIO){
						auxH->valor = IDENTIFICADOR_NAVIO_DESTRUIDO;
						aciertosJugador++;
					}else{
						auxH->valor = IDENTIFICADOR_DISPARO_FALLADO;
					}
				}
			}
			auxH = auxH->derecha;
		}
		auxV = auxV->abajo;
		if(auxV != NULL){
			auxH = auxV->derecha;
		}
	}
	
	//auxV = (*cabecera);
	//auxH = auxV;
	auxV = (*cabecera)->abajo;
	auxH = auxV->derecha;
	
	contador = 0;
	while(auxV != NULL){
		
		while(auxH != NULL){
			//if(auxH->cabecera){
			//	cout<<" "<<auxH->valor<<" ";
			//}else{
				switch(auxH->valor){
					case IDENTIFICADOR_VACIO:
						cout<<" \xDC ";
						break;
					case IDENTIFICADOR_NAVIO:
						cout<<" o ";
						break;
					case IDENTIFICADOR_NAVIO_DESTRUIDO:
						cout<<" - ";
						break;
					case IDENTIFICADOR_DISPARO_FALLADO:
						cout<<" x ";
						break;
				}
			//}			
			auxH = auxH->derecha;
		}
		if(contador == nf){
			cout<<endl<<endl;
			for(int i = 0; i < nc; i++){
				cout<<"---";
			}
		}
		cout<<endl<<endl;
		auxV = auxV->abajo;
		if(auxV != NULL){
			auxH = auxV->derecha;	
		}
		contador++;
	}
	
	if(aciertosJugador > aciertosRival){
		cout<<endl<<endl<<"******* JUGADOR HA GANADO *******";
	}else if(aciertosJugador < aciertosRival){
		cout<<endl<<endl<<"******* JUGADOR HA PERDIDO *******";
	}else{
		cout<<endl<<endl<<"******* ES UN EMPATE *******";
	}
	
	system("pause");
	
	// Limpia el esapcio en memoria reservado para la matriz en memoria
	
	Nodo *pDel = (*cabecera);
	Nodo *temp = NULL;
	
	auxV = (*cabecera)->abajo;
	auxH = auxV->derecha;
	
	do{
		while(pDel != NULL)
		{
		  temp = pDel->derecha;
		  delete[] pDel;
		  pDel = temp;
		}
		pDel = auxV;
		auxV = auxV->abajo;
	}while(auxV->abajo != NULL);
	
	system("pause");
}

void crearLista(int nf, int nc){
	Nodo *cabecera = new Nodo();
	Nodo *ultimoH = NULL;
	Nodo *ultimoV = NULL;
	
	for(int i = 0; i < nc; i++){
		Nodo *p = new Nodo();
		p->valor = i + 1;
		p->cabecera = true;
		
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
	
	for(int i = 0; i < nf * 2; i++){
		Nodo *p = new Nodo();
		p->valor = i + 1;
		p->cabecera = true;
		
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

	Nodo *auxH = cabecera->derecha;
	Nodo *auxV = cabecera->abajo;
	Nodo *auxUltimoH = cabecera->derecha;
	Nodo *auxUltimoV = cabecera->abajo;
	
	int x = 1;
	int y = 1;
	//int h = 1;
	// Inserta nuevos nodos en toda la matriz
	while(auxV != NULL){
		while(auxH != NULL){
			Nodo *q = new Nodo();
			//q->valor = h;
			//h++;
			q->x = x;
			q->y = y;
			x++;
			
			q->izquierda = auxUltimoV;
			auxUltimoV->derecha = q;
			
			q->arriba = auxUltimoH;
			auxUltimoH->abajo = q;
			
			auxUltimoH = auxUltimoH->derecha;
			auxUltimoV = q;
			
			auxH = auxH->derecha;
		}
		auxUltimoH = auxV->derecha;
		auxH = cabecera->derecha;
		auxV = auxV->abajo;
		auxUltimoV = auxV;
		y++;
		x = 1;
	}
	
	comenzarJuego(&cabecera, nf, nc);
	
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
				}while(noCol < 3);
				
				do{
					system("cls");
					cout<<"\nCuantas filas desea? (minimo 5) [ ]\b\b";
					cin>>noFil;
					cin.ignore();
				}while(noFil < 3);
				system("cls");
				
				crearLista(noFil, noCol);
				
				break;
			case 2:
				cout<<"\n\nGracias por jugar!"<<endl;
				Sleep(2000);
				break;
			default:
				cout<<"\n\nIngrese una opcion valida."<<endl;
				Sleep(2000);
				break;
		}
	}while(op != 2);
}
