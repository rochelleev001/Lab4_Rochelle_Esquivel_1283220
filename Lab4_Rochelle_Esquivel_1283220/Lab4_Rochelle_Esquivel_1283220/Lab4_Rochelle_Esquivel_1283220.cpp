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
	int fin; 
	int inicio;
}Pila;
Pila pilas[13];

//Creacion de métodos
void menu1(Pila pila[]);
void menuJuego(Pila pila[]);
void reglas(void);
void comandos(void);
void imprimir_Pila(Pila pila[], int i);
void MostrarPilas(Pila pila[]);
void ApilarCartas(Pila pila[], int o, int d, int c);
void Apilar(Pila pila[], int i, Carta x);
void IntercambiarPos(Pila pila[], int a, int b);
void crearTopes(Pila pila[]);
Carta Desapilar(Pila pila[], int i, Carta x);
int ValidarPilas(Pila pila[], int o, int d);
int pilaVacia(Pila pila[], int i);
int SalidadePilas(Pila pila[], int o, int d);
int identificarCarta(Pila pila[], int o, int d, int c);
int OrdenCartas(Pila pila[], int* contador);
int tam_Pila(Pila pila[], int i);
void Desbordar(Pila pila[], int i);


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
	if (d < 2 || o == 1 || o < 0 || o > 7) {
		return 0;
	} //7 pilas 
	if (pilaVacia(pila, o)) {
		return 0;
	}
		
	if (pilaVacia(pila, d)) {
		if (V[pila[o].inicio].numCarta != 13) {
			return 0;
		} //cantidad de cartas
			
	}
		

	if (pilaVacia(pila, d) == 0) {
		if (V[pila[o].inicio].color == V[pila[d].inicio].color) {
			return 0;
		}
		if (V[pila[o].inicio].numCarta != (V[pila[d].inicio].numCarta - 1)) {
			return 0;
		}
			
	}
	return 1;
}
int SalidadePilas(Pila pila[], int o, int d) {
	if (d > 13) {
		return 0;
	}
		
	if (pilaVacia(pila, d) == 0) {
		if (V[pila[o].inicio].numCarta != (V[pila[d].inicio].numCarta + 1)) {
			return 0;
		}	
	}	
	return 1;
}
int identificarCarta(Pila pila[], int o, int d, int c) { // buscar carta e identificar pila
	int indice = -1;
	for (int i = pila[o].inicio; i >= pila[o].fin + 1; i--) {
		if (V[i].estado == 0) break;
		if (V[i].numCarta == c) indice = i;
	}
	if (indice != -1) {
		if (pilaVacia(pila, d)) return indice;

		if (V[indice].numCarta == (V[pila[d].inicio].numCarta - 1)
			&& V[indice].color != V[pila[d].inicio].color)
			return indice;
	}
	return -1;
}
void ApilarCartas(Pila pila[], int o, int d, int c) {
	Carta temp;
	int indice = identificarCarta(pila, o, d, c);
	if (indice != -1) {
		int count = 0;
		count = pila[o].inicio - indice;
		Carta cart[count + 1];
		for (int i = 0; i < count + 1; i++)
			cart[i] = Desapilar(pila, o, temp);
		for (int i = 0; i < count + 1; i++)
			Apilar(pila, d, cart[count - i]);

		if (pilaVacia(pila, o) == 0)
			V[pila[o].inicio].estado = 1;
	}
}
int OrdenCartas(Pila pila[], int* contador) {
	int o, d, c;
	char opc;
	Carta aux;

	if (scanf("%d %d", &o, &d) == 2) {

		if (d < 7) {

			if (pilaVacia(pila, d)) {
				if (V[pila[o].inicio].numCarta == 13) {
					aux = Desapilar(pila, o, aux);
					Apilar(pila, d, aux);
					if (o != 0)
						V[pila[o].inicio].estado = 1;
					V[pila[d].inicio].estado = 1;
				}
			}
			if (ValidarPilas(pila, o, d) == 1) {

				aux = Desapilar(pila, o, aux);
				Apilar(pila, d, aux);
				V[pila[o].inicio].estado = 1;
				V[pila[d].inicio].estado = 1;
			}
		}
		else {
			if (SalidadePilas(pila, o, d) == 1) {
				aux = Desapilar(pila, o, aux);
				Apilar(pila, d, aux);
				V[pila[o].inicio].estado = 1;
				V[pila[d].inicio].estado = 1;
			}
		}

	}
	else if (scanf("%c", &opc) == 1) {
		if (opc == 'w' || opc == 'W') {
			return 1;
		}
		if (opc == 'd' || opc == 'D') {
			//Si la pila de reserva no esta vacia
			if (tam_Pila(pila, 1) != 0) {
				//Si la pila 0 esta vacia, hacer pop a pila 1 y luego push a pila 0.
				if (pilaVacia(pila, 0) == 1) {
					aux = Desapilar(pila, 1, aux);
					Apilar(pila, 0, aux);
					V[pila[0].inicio].estado = 1;
				}
				//Si la pila 0 no esta vacia, intercabiar pila 1 con pila 0.
				else {
					(*contador)++;
					IntercambiarPos(pila, pila[0].inicio, pila[1].inicio -
						(*contador % (tam_Pila(pila, 1) - 1)));
					V[pila[0].inicio].estado = 1;
				}
			}
		}
		if (opc == 'c') {
			scanf("%d %d %d", &o, &d, &c);
			ApilarCartas(pila, o, d, c);
		}
		if (opc == 'n') {
			system("clear");
			menu1(pila);
		}
		return 0;

	}
	if (pila) {
		return 0;
	}
		
}
void menu1(Pila pila[]) {
	int opc = 1;
	int value;
	while (opc) {
		cout << "\t\tBienvenido al juego El solitario\n\n" << endl;
		cout << "1. Reglas del juego\n" << endl;
		cout << "2. Comandos del juego\n" << endl;
		cout << "3. Empezar a jugar\n" << endl;
		cout << "4. Salir\n" << endl;

		cout << "Ingrese Opcion\n" << endl;
		scanf("%d", &opc);

		switch (opc) {

		case 1:	reglas();
			break;

		case 2:	comandos();
			break;
		case 3: menuJuego(pila);
			break;

		case 4:	opc = 0;
			break;

		default: cout << "Ingrese opcion valida\n" << endl;
			break;
		}
	}
}
void Apilar(Pila pila[], int i, Carta x) {
	pilas[13].fin = MAX;
	if (pila[i].inicio == pila[i + 1].fin)
		Desbordar(pila, i);

	pila[i].inicio = pila[i].inicio + 1;
	V[pila[i].inicio] = x;
}
Carta Desapilar(Pila pila[], int i, Carta x) {
	if (pila[i].inicio == pila[i].fin)
		x.numCarta = 0; //Si la pila esta vacia, retorna 0.
	else {
		x = V[pila[i].inicio];
		pila[i].inicio = pila[i].inicio - 1;
	}
	return x;
}

// actualizar topes y bases en la pila
void crearTopes(Pila pila[]) { 
	for (int i = 0; i <= 12; i++) 
		pila[i].fin = pila[i].inicio = (int)(i * ((float)(MAX) / 13)); 
}
void Desbordar(Pila pila[], int i) {
	int j = i;

	int flat = 0;
	while (pila[j].inicio < MAX) {
		j++;
		if (pila[j].inicio < pila[j + 1].fin) {
			flat = 1; 
			break;
		}
	}

	if (flat == 1) {

		for (int k = pila[j].inicio; k >= pila[i + 1].fin + 1; k--) 
			V[k + 1] = V[k];

		for (int k = i + 1; k <= j; k++) {
			pila[k].fin = pila[k].fin + 1;
			pila[k].inicio = pila[k].inicio + 1;
		}
	}

	else {
		j = i;
		while (1) {
			j--;
			if (pila[j].inicio < pila[j + 1].fin) {
				break;
			}
		}
		for (int k = pila[j + 1].fin; k < pila[i].inicio; k++)
			V[k] = V[k + 1];

		for (int k = j + 1; k <= i; k++) {
			pila[k].fin = pila[k].fin - 1;
			pila[k].inicio = pila[k].inicio - 1;
		}
	}
}