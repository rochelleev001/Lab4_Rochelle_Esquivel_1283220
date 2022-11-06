#pragma once
including namespace std;
//Creacion de métodos
void menu1(Pila pila[]);
void menuJuego(Pila pila[]);
void reglas(void);
void comandos(void);
void imprimir_Pila(Pila pila[], int i);
void MostrarPilas(Pila pila[]);
int ValidarPilas(Pila pila[], int o, int d);
int pilaVacia(Pila pila[], int i);
int SalidadePilas(Pila pila[], int o, int d);
int identificarCarta(Pila pila[], int o, int d, int c);