#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 52
using namespace std;

int main()
{
	menu1(pilas);
}

//carta
typedef struct {
	int color;
	int estado;
	int numCarta;
} Carta;

Carta V[MAX];

//pilas
typedef struct {
	Carta c;
	int base; 
	int top;
}Pila;
Pila pilas[13];

//Creacion de métodos
void menu1(Pila pila[]);
void menuJuego(Pila pila[]);
void reglas(void);
void comandos(void);
void imprimir_Pila(Pila pila[], int i);
void MostrarPilas(Pila pila[]);
int ValidarPilas(Pila pila[], int o, int d);
int pilaVacia(Pila pila[], int i);

void reglas() {
	cout << "		 JUEGO EL SOLITARIO        " << endl;
	cout << "**********************************\n" << endl;
	cout << "Reglas del juego: \n" << endl;
	cout << "Hay 7 pilas de juego en donde se colocarán cartas\n" << endl;
	cout << "de forma decreciente consecutiva y de colores alternantes.\n" << endl;
	cout << "Si se logra llenar cada una de las 13 cartas de un mismo palo en cada pila de salida\n" << endl;
	cout << "se gana el juego, y se pierde cuando no se puede hacer ningun movimiento.\n" << endl;
}
void comandos() {
	cout << "*********************\n" << endl;
	cout << "Eliminar: 	0:\n" << endl;
	cout << "Guardar: 	1:[*]\n" << endl;
	cout << "**********************\n" << endl;
	cout << "G1:\n" << endl;
	cout << "G2:\n" << endl;
	cout << "G3:\n" << endl;
	cout << "G4:\n" << endl;
	cout << "G5:\n" << endl;
	cout << "G6:\n" << endl;
	cout << "G7:\n" << endl;
}
void MostrarPilas(Pila pila[]) {
	cout << "\n**********************\n" << endl;
	cout << "Eliminar:     0:" << (pila, 0) << endl;
	cout << "Guardar:      1:[*]" << endl;
	cout << "\n**********************\n\n" << endl;
	cout << "G1:"; imprimir_Pila(pila, 1);
	cout << "G2:"; imprimir_Pila (pila, 2);
	cout << "G3:"; imprimir_Pila(pila, 3);
	cout << "G4:"; imprimir_Pila(pila, 4);
	cout << "G5:"; imprimir_Pila(pila, 5);
	cout << "G6:"; imprimir_Pila(pila, 6);
	cout << "G7:"; imprimir_Pila(pila, 7);
}
//validez de pilas y verificar que no estén vacías
int ValidarPilas(Pila pila[], int o, int d) {
	if (d < 2 || o == 1 || o < 0 || o > 7) //7 pilas 
		return 0;

	if (pilaVacia(pila, o))
		return 0;

	if (pilaVacia(pila, d))
		if (V[pila[o].top].numCarta != 13) //cantidad de cartas
			return 0;

	if (pilaVacia(pila, d) == 0) {
		if (V[pila[o].top].color == V[pila[d].top].color)
			return 0;
		if (V[pila[o].top].numCarta != (V[pila[d].top].numCarta - 1))
			return 0;
	}
	return 1;
}


