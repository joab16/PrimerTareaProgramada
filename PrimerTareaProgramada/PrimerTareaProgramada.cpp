#include <iostream>
#include <stdlib.h>
#include "stdafx.h"
#include "Lista_Posicionada_Arreglo.h"
#include "Lista_Posicionada_DE.h"
#include "Lista_Posicionada_SE.h"
#include "ListaIndexadaArreglo.h"
#include "ListaIndexadaSE.h"
//#include "ListaOrdenadaArreglo.h"
#include "ListaOrdenadaLSE.h"
#include "Posicion.h"
#include "Pila.h"


//typedef ListaOrdenadaArreglo ListaOrdenada;
typedef ListaOrdenadaLSE ListaOrdenada;
typedef ListaIndexadaArreglo ListaIndexada;
//typedef ListaOrdenadaLSE ListaOrdenada;
using namespace std;

void menu();
void listaOrdenadaArreglo();
void listaOrdenadaLSE();
void listaIndexadaArreglo();
void listaIndexadaSE();
void listaPosicionadaSE();
void listaPosicionadaDE();
void listaPosicionadaArreglo();
void pila();

ListaOrdenada *L1 = new ListaOrdenada;
ListaOrdenada *L2 = new ListaOrdenada;
ListaOrdenada *L3 = new ListaOrdenada;
ListaIndexada *LI = new ListaIndexada;
ListaIndexada *LI2 = new ListaIndexada;
ListaIndexada *LI3 = new ListaIndexada();
ListaIndexada *Laux = new ListaIndexada();


bool iguales(ListaOrdenada *L1, ListaOrdenada *L2);
void copiar(ListaOrdenada *L1, ListaOrdenada *L2);
bool contenida(ListaOrdenada *L1, ListaOrdenada *L2);
bool pertenece(ListaOrdenada *L1, elemento elem);
void eliminar(ListaOrdenada *L1, ListaOrdenada *L2);
void union1(ListaOrdenada *L1, ListaOrdenada *L2);
void union2(ListaOrdenada *L1, ListaOrdenada *L2, ListaOrdenada *L3);
ListaOrdenada interseccion1(ListaOrdenada *L1, ListaOrdenada *L2);
ListaOrdenada interseccion2(ListaOrdenada *L1, ListaOrdenada *L2);

//Joab
void Listar(ListaIndexada *L);
bool Simetrica(ListaIndexada *L);
void Invertir(ListaIndexada *L);
bool Buscar(ListaIndexada *L, int e);
void EliminarElementosRepetidos(ListaIndexada *L);
bool SubLista(ListaIndexada *L1, ListaIndexada *L2);
bool Iguales(ListaIndexada *L1, ListaIndexada *L2);
void BurbujaOriginal(ListaIndexada *L);
void BurbujaBiDir(ListaIndexada *L);
void SeleccionIterativo(ListaIndexada *L);
void SeleccionRecursivo(ListaIndexada *L);
void SeleccionRecursivo(ListaIndexada *L, int primera);
void SeleccionRecursivoPila(ListaIndexada *L, int primera);
void Insercion(ListaIndexada *L, int inicio, int fin);
int EncuentraPivote(ListaIndexada *L, int i, int j);
int Particion(ListaIndexada *L, int i, int j, int pivote);
void QuickSortAho(ListaIndexada *L);
void QuickSortAho(ListaIndexada *L, int i, int j);
void QuickSort(ListaIndexada *L, int i, int j);
void QuickSort(ListaIndexada *L);
ListaIndexada* MergeSort(ListaIndexada* L);
ListaIndexada* Merge(ListaIndexada* L1, ListaIndexada* L2);
void UnionOrd(ListaIndexada *L1, ListaIndexada *L2);
void Union(ListaIndexada *L1, ListaIndexada *L2);
ListaIndexada* InterseccionOrd(ListaIndexada *L1, ListaIndexada *L2);
ListaIndexada* Interseccion(ListaIndexada *L1, ListaIndexada *L2);
void EliminarInterseccionOrd(ListaIndexada *L1, ListaIndexada *L2);
void EliminarInterseccion(ListaIndexada *L1, ListaIndexada *L2);

int main()
{
	menu();	
	//L1->Iniciar();
	//L1->Agregar(0);
	//L1->Agregar(4);
	//L1->Agregar(7);
	//L1->Agregar(15);
	//L1->Listar();
	//L2->Iniciar();
	//L2->Agregar(0);
	//L2->Agregar(4);
	//L2->Agregar(15);
	////L2->Agregar(1);
	//L2->Agregar(7);
	////L2->Agregar(21);
	//L2->Listar();
	//L3->Iniciar();

	//copiar(L1, L2);
	//iguales(L1, L2);
	//eliminar(L1, L2);
	//contenida(L1, L2);
	//pertenece(L1, 15);
	//union1(L1, L2);
	//union2(L1, L2, L3);
	//L3->Listar();
	//interseccion1(L1, L2);
	//interseccion2(L1, L2);
	
	system("pause");
	return 0;
}

void menu()
{

	//listaOrdenadaArreglo();
	//listaOrdenadaLSE();
	//listaPosicionadaDE();
	//listaPosicionadaSE();
	//pila();
	//listaPosicionadaArreglo();
	//listaIndexadaArreglo();
	//listaIndexadaSE();

	int salida = 0;
	posicion p1;
	elemento e1;
	int opcion = 0;
	//ListaOrdenada *lista = new ListaOrdenada;
	int modelo = 0;
	cout << "                Que herramienta desea utilizar?" << endl;
	cout << "Las herramientas son: 1-Lista Posicionada, 2-Lista Indexada, 3-Lista Ordenada" << endl;
	cin >> modelo;
	L1->Iniciar();
	L2->Iniciar();
	L3->Iniciar();
	LI->Iniciar();
	LI2->Iniciar();
	for (int i = 0; i < 25; i++)
	{
		LI->Insertar(rand() % 20 + 1, i);
		LI2->Insertar(rand() % 40 + 1, i);
	}	
	if (modelo == 2)
	{
		while (salida != -1)
		{
			cout << "Las funciones que puede realizar son: -1 = Salir, 1 = Listar, 2 = Simétrica, 3 = Invertir, 4 = Buscar, 5 = Eliminar elementos repetidos" << endl;
			cout << "6 = Sublista, 7 = Iguales, 8 = Burbuja Original, 9 = Burbuja Bidireccional, 10 = Selección Iterativa, 11 = Selección Recursiva" << endl;
			cout << "12 = Selección Recursiva con pila propia, 13 = Inserción, 14 = QuickSortAho, 15 = QuickSort, 16 = MergeSort " << endl;
			cout << "17 = UniónOrd, 18 = Unión, 19 = IntersecciónOrd, 20 = Intersección, 21 = EliminarIntersecciónOrd, 22 = EliminarIntersección" << endl;
			cin >> salida;
			switch (salida)
			{
			case 1:
				Listar(LI);
				break;
			case 2:
				Listar(LI);
				if (Simetrica(LI))
					cout << "La lista es simétrica." << endl;
				else
					cout << "La lista no es simétrica." << endl;				
				Laux->Iniciar();
				Laux->Insertar(1, 0);
				Laux->Insertar(2, 1);
				Laux->Insertar(3, 2);
				Laux->Insertar(3, 3);
				Laux->Insertar(2, 4);
				Laux->Insertar(1, 5);
				Listar(Laux);
				if (Simetrica(Laux))
					cout << "La lista es simétrica." << endl;
				else
					cout << "La lista no es simétrica." << endl;
				Laux->Destruir();
				Laux->~ListaIndexadaArreglo();
				break;
			case 3:
				cout << "Lista antes de invertir" << endl;
				Listar(LI);
				Invertir(LI);
				cout << "Lista después de invertir" << endl;
				Listar(LI);
				break;
			case 4:
				Listar(LI);
				int e;
				cout << "Escriba el elemento que desea buscar: ";
				cin >> e;
				if (Buscar(LI, e))
					cout << "Elemento encontrado." << endl;
				else
					cout << "Elemento no encontrado." << endl;
				break;
			case 5:
				cout << "Lista antes de eliminar repetidos" << endl;
				Listar(LI);
				EliminarElementosRepetidos(LI);
				cout << "Lista después de eliminar repetidos" << endl;
				Listar(LI);
				break;
			case 6:
				cout << "Lista 1:" << endl;
				Listar(LI);
				cout << "Lista 2:" << endl;
				Listar(LI2);
				if (SubLista(LI, LI2))
					cout << "La lista 1 es sublista de la 2" << endl;
				else
					cout << "La lista 1 es no sublista de la 2" << endl;
				break;
			case 7:
				if (Iguales(LI, LI2))
					cout << "Las listas son iguales" << endl;
				else
					cout << "Las listas no son iguales" << endl;
				break;
			case 8:
				cout << "Lista antes de ordenarla con burbuja original:" << endl;
				Listar(LI);
				BurbujaOriginal(LI);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 9:
				cout << "Lista antes de ordenarla con burbuja bidir:" << endl;
				Listar(LI);
				BurbujaBiDir(LI);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 10:
				cout << "Lista antes de ordenarla con Selección Iterativa:" << endl;
				Listar(LI);
				SeleccionIterativo(LI);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 11:
				cout << "Lista antes de ordenarla con Selección Recursiva:" << endl;
				Listar(LI);
				SeleccionRecursivo(LI);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 12:
				cout << "Lista antes de ordenarla con Selección Recursiva y Pila propia:" << endl;
				Listar(LI);
				SeleccionRecursivoPila(LI, 0);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 13:
				cout << "Lista antes de ordenarla con Inserción:" << endl;
				Listar(LI);
				Insercion(LI, 0, LI->NumElem()-1);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 14:
				cout << "Lista antes de ordenarla con QuickSortAho:" << endl;
				Listar(LI);
				QuickSortAho(LI);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 15:
				cout << "Lista antes de ordenarla con QuickSort:" << endl;
				Listar(LI);
				QuickSort(LI);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 16:
				cout << "Lista antes de ordenarla con MergeSort:" << endl;
				Listar(LI);
				LI = MergeSort(LI);
				cout << "Lista despues de ordenarla:" << endl;
				Listar(LI);
				break;
			case 17:
				EliminarElementosRepetidos(LI);
				EliminarElementosRepetidos(LI2);
				BurbujaOriginal(LI);
				BurbujaOriginal(LI2);
				cout << "Lista 1:" << endl;
				Listar(LI);
				cout << "Lista 2:" << endl;
				Listar(LI2);
				UnionOrd(LI, LI2);
				Listar(LI);
				break;
			case 18:
				EliminarElementosRepetidos(LI);
				EliminarElementosRepetidos(LI2);
				cout << "Lista 1:" << endl;
				Listar(LI);
				cout << "Lista 2:" << endl;
				Listar(LI2);
				Union(LI, LI2);
				Listar(LI);				
				break;
			case 19:
				EliminarElementosRepetidos(LI);
				EliminarElementosRepetidos(LI2);
				BurbujaOriginal(LI);
				BurbujaOriginal(LI2);
				cout << "Lista 1:" << endl;
				Listar(LI);
				cout << "Lista 2:" << endl;
				Listar(LI2);				
				LI3 = InterseccionOrd(LI, LI2);
				cout << "Lista intersección:" << endl;
				Listar(LI3);
				LI3->Destruir();
				break;
			case 20:
				EliminarElementosRepetidos(LI);
				EliminarElementosRepetidos(LI2);
				cout << "Lista 1:" << endl;
				Listar(LI);
				cout << "Lista 2:" << endl;
				Listar(LI2);				
				LI3 = Interseccion(LI, LI2);
				cout << "Lista intersección:" << endl;
				Listar(LI3);
				LI3->Destruir();
				break;
			case 21:
				EliminarElementosRepetidos(LI);
				EliminarElementosRepetidos(LI2);
				BurbujaOriginal(LI);
				BurbujaOriginal(LI2);
				cout << "Lista 1:" << endl;
				Listar(LI);
				cout << "Lista 2:" << endl;
				Listar(LI2);
				EliminarInterseccionOrd(LI, LI2);
				cout << "Lista luego de eliminar interseccion:" << endl;
				Listar(LI);
				break;
			case 22:
				EliminarElementosRepetidos(LI);
				EliminarElementosRepetidos(LI2);
				cout << "Lista 1:" << endl;
				Listar(LI);
				cout << "Lista 2:" << endl;
				Listar(LI2);
				EliminarInterseccion(LI, LI2);
				cout << "Lista luego de eliminar interseccion:" << endl;
				Listar(LI);
				break;
			case -1:
			default:
				LI->Destruir();
				LI2->Destruir();
				break;
			}
			system("pause");
		}
	}
	else if (modelo == 3)
	{
		cout << "Las funciones que puede realizar son: -1 = Salir, 1 = Agregar, 2 = Borrar, 3 = Primero, 4 = Siguiente, 5 = Ultimo, \n 6 = Anterior, 7 = Listar, 8 = Iguales, 9 = Copiar, 10 = Contenida, 11 = Pertenece, 12 = EliminarIntersec, \n 13 = Union1, 14 = Union2, 15 = Interseccion1, 16 = Interseccion2" << endl;
	}
	while(salida != -1)
	{   
	switch (modelo)
	{
	case 1:
		cout << "Las funciones que puede realizar son: -1 = Salir, 1 = Insertar, 3 = Borrar,\n 4 = ModificarElemento, 5 = Intercambiar, 6 = Primera, 7 = Ultima, 8 = Siguiente, 9 = Anterior, 10 = Recuperar," << endl;
		cin >> salida;
		switch (salida)
		{
		case 1:
			cout << "Cual elemento desea insertar?" << endl;
			cin >> e1;
			L1->Agregar(e1);
			break;
		default:
			cout << "Digito una opcion invalida" << endl;
			break;
		}
	case 2:
		cout << "Las funciones que puede realizar son: 1 = Insertar, 2 = AgregarAlFinal, 3 = Borrar,\n 4 = ModificarElemento, 5 = Intercambiar, 6 = Primera,\n 7 = Ultima, 8 = Siguiente, 9 = Anterior,\n 10 = Recuperar," << endl;
		cin >> salida;
		switch (salida)
		{
		case 1:
			cout << "Cual elemento desea insertar?" << endl;
			cin >> e1;
			L1->Agregar(e1);
			break;
		default:
			cout << "Digito una opcion invalida" << endl;
			break;
		}
	case 3:
		//cout << "Las funciones que puede realizar son: -1 = Salir, 1 = Agregar, 2 = Borrar, 3 = Primero, 4 = Siguiente, 5 = Ultimo, \n 6 = Anterior, 7 = Listar, 8 = Iguales, 9 = Copiar, 10 = Contenida, 11 = Pertenece, 12 = EliminarIntersec, \n 13 = Union1, 14 = Union2, 15 = Interseccion1, 16 = Interseccion2" << endl;
		cout << "Escriba el numero con la funcion que desea realizar ahora?" << endl;
		//cout <<"Que desea hacer ahora?"
		cin >> salida;
		switch (salida)
		{
		case 1:
			cout << "En cual lista desea agregar elementos? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				cout << "Cual elemento desea insertar?" << endl;
				cin >> e1;
				L1->Agregar(e1);
			}
			else if(opcion == 2)
			{ 
				cout << "Cual elemento desea insertar?" << endl;
				cin >> e1;
				L2->Agregar(e1);
			}
			break;
		case 2:
			cout << "En cual lista desea borrar elementos? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				cout << "Cual elemento desea borrar?" << endl;
				cin >> e1;
				L1->Borrar(e1);
			}
			else if (opcion == 2)
			{
				cout << "Cual elemento desea borrar?" << endl;
				cin >> e1;
				L2->Borrar(e1);
			}
			break;
		case 3:
			cout << "De cual lista desea conocer el primer elemento? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				L1->Primero();
			}
			else if (e1 == 2)
			{
				L2->Primero();
			}
			break;
		case 4:
			cout << "De cual lista desea conocer el siguiente elemento? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				cout << "Ingrese el elemento para el que desea saber el siguiente" << endl;
				cin >> e1;
				cout << "El siguiente elemento es: " << L1->Siguiente(e1) << endl;
			}
			else if (opcion == 2)
			{
				cout << "Ingrese el elemento para el que desea saber el siguiente" << endl;
				cin >> e1;
				cout << "El siguiente elemento es: " << L2->Siguiente(e1) << endl;
			}
			break;
		case 5:
			cout << "De cual lista desea conocer el ultimo elemento? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				L1->Ultimo();
			}
			else if (opcion == 2)
			{
				L2->Ultimo();
			}
			break;
		case 6:
			cout << "De cual lista desea conocer el anterior elemento? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				cout << "Ingrese el elemento para el que desea saber el anterior" << endl;
				cin >> e1;
				cout << "El elemento anterior es: " << L1->Anterior(e1) << endl;
			}
			else if (opcion == 2)
			{
				cout << "Ingrese el elemento para el que desea saber el anterior" << endl;
				cin >> e1;
				cout << "El elemento anterior es: " << L2->Anterior(e1) << endl;
			}
			break;
		case 7:
			cout << "Cual lista desea imprimir? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				L1->Listar();
				cout << endl;
			}
			else if (opcion == 2)
			{
				L2->Listar();
				cout << endl;
			}
			break;
		case 8:
			if (iguales(L1, L2) == true)
			{
				cout << "La lista L1 es igual a la lista L2" << endl;
			}
			else if (!iguales(L1, L2))
			{
				cout << "La lista L1 es diferente a la lista L2" << endl;
			}
			break;
		case 9:
			copiar(L1, L2);
			L2->Listar();
			cout << endl;
			break;
		case 10:
			if (contenida(L1, L2) == true)
			{
				cout << "La lista L1 si esta contenida en L2" << endl;
			}
			else if (contenida(L1, L2) == false)
			{
				cout << "La lista L1 no esta contenida en L2" << endl;
			}
			break;
		case 11:
			cout << "En cual lista desea saber si el elemento pertenece? 1 = L1, 2 = L2" << endl;
			cin >> opcion;
			if (opcion == 1)
			{
				cout << "Ingrese el elemento para saber si pertenece a la lista" << endl;
				cin >> e1;
				if (pertenece(L1, e1)== true)
				{
					cout << "El elemento si pertenece a la lista" << endl;
				}
				else if (!pertenece(L1, e1))
				{
					cout << "El elemento no pertenece a la lista" << endl;

				}
			}
			else if (opcion == 2)
			{
				cout << "Ingrese el elemento para saber si pertenece a la lista" << endl;
				cin >> e1;
				if(pertenece(L2, e1) == true)
				{ 
					cout << "El elemento si pertenece a la lista" << endl;
				}
				else if (!pertenece(L2, e1))
				{
					cout << "El elemento no pertenece a la lista" << endl;

				}
			}
			break;
		case 12:
			eliminar(L1, L2);
			cout << "Despues de eliminar la interseccion los elementos en la lista L1" << endl;
			L1->Listar();
			cout << endl;
			break;
		case 13:
			cout << "1 forma: Despues de unir los elementos de L1 y L2 en la lista L1" << endl;
			union1(L1, L2);
			L1->Listar();
			break;
		case 14:
			cout << "2 forma: Despues de unir los elementos de L1 y L2 en la lista L3" << endl;
			union2(L1, L2, L3);
			L3->Listar();
			break;
		case 15:
			cout << "1 forma: Despues de ingresar en L3 los elementos que estan tanto en L1 como L2" << endl;
			interseccion1(L1, L2);
			break;
		case 16:
			cout << "2 forma: Despues de ingresar en L3 los elementos que estan tanto en L1 como L2" << endl;
			interseccion2(L1, L2);
			break;
		default:
			cout << "Digito una opcion invalida" << endl;
			break;

		}
	}
	//break;

	}
	cout << "Desea seguir utilizando el programa?\n" << "1 = si, -1 = no" << endl;
	cin >> salida;
}

/**

Prueba de la Estructura de Datos Lista Indexada implementada por Lista Simplemente Enlazada

*/

void listaIndexadaSE()
{
	ListaIndexadaSE* listaIndexada = new ListaIndexadaSE();
	listaIndexada->Iniciar();
	cout << "---Lista Indexada implementada por Lista Simplemente Enlazada---" << endl;
	cout << endl;
	int i = 1;
	while (i <= 5)
	{
		int e = rand() % 100 + 1;
		listaIndexada->Insertar(e, i);
		cout << "Elemento " << e << " insertado en el indice " << i << endl;
		++i;
	}
	if (listaIndexada->Vacia())
	{
		cout << "Lista vacia" << endl;
	}
	else
	{
		cout << "Lista no vacia" << endl;
	}

	cout << "Cantidad de elementos en la lista: " << listaIndexada->NumElem() << endl;

	cout << "Eliminando un elemento de la lista " << endl;
	listaIndexada->Borrar(3);

	cout << "Cantidad de elementos en la lista: " << listaIndexada->NumElem() << endl;

	cout << "Elemento en la posicion 1: " << listaIndexada->Recuperar(1) << endl;
	cout << "Elemento en la posicion 2: " << listaIndexada->Recuperar(2) << endl;

	listaIndexada->Intercambiar(1, 2);

	cout << "Elemento en la posicion 1: " << listaIndexada->Recuperar(1) << endl;
	cout << "Elemento en la posicion 2: " << listaIndexada->Recuperar(2) << endl;

	cout << "Elemento en la posicion 1 sin modificar: " << listaIndexada->Recuperar(1) << endl;
	listaIndexada->ModificarElemento(rand() % 100 + 1, 1);
	cout << "Elemento en la posicion 1 modificado: " << listaIndexada->Recuperar(1) << endl;

	//    listaIndexada->Vaciar();
	//    if (listaIndexada->Vacia())
	//    {
	//        cout << "Lista vacia" << endl;
	//    }
	//    else
	//    {
	//        cout << "Lista no vacia" << endl;
	//    }
	//cout << "Lista vaciada, cantidad de elementos en la lista: " << listaIndexada->NumElem() << endl;

	//listaIndexada->Destruir();

}

/**

Prueba de la Estructura de Datos Lista Indexada implementada por Arreglo

*/
/*void listaIndexadaArreglo()
{
	ListaArreglo* listaIndexada = new ListaArreglo();
	listaIndexada->Iniciar();
	cout << "---Lista Indexada implementada por Arreglo---" << endl;
	cout << endl;
	int i = 1;
	while (i <= 5)
	{
		int e = rand() % 100 + 1;
		listaIndexada->Insertar(e, i);
		cout << "Elemento " << e << " insertado en el indice " << i << endl;
		++i;
	}
	if (listaIndexada->Vacia())
	{
		cout << "Lista vacia" << endl;
	}
	else
	{
		cout << "Lista no vacia" << endl;
	}

	cout << "Cantidad de elementos en la lista: " << listaIndexada->NumElem() << endl;

	cout << "Eliminando un elemento de la lista " << endl;
	listaIndexada->Borrar(3);

	cout << "Cantidad de elementos en la lista: " << listaIndexada->NumElem() << endl;

	cout << "Elemento en la posicion 1: " << listaIndexada->Recuperar(1) << endl;
	cout << "Elemento en la posicion 2: " << listaIndexada->Recuperar(2) << endl;

	listaIndexada->Intercambiar(1, 2);

	cout << "Elemento en la posicion 1: " << listaIndexada->Recuperar(1) << endl;
	cout << "Elemento en la posicion 2: " << listaIndexada->Recuperar(2) << endl;

	cout << "Elemento en la posicion 4 sin modificar: " << listaIndexada->Recuperar(4) << endl;
	listaIndexada->ModificarElemento(rand() % 100 + 1, 4);
	cout << "Elemento en la posicion 4 modificado: " << listaIndexada->Recuperar(4) << endl;

	listaIndexada->Vaciar();
	cout << "Lista vaciada, cantidad de elementos en la lista: " << listaIndexada->NumElem() << endl;

	listaIndexada->Destruir();
	cout << endl;
}*/


/**

Prueba de la Estructura de Datos Lista Ordenada implementada por Arreglo

*/
//void listaOrdenadaArreglo()
//{
//	ListaOrdenada *lista = new ListaOrdenada;
//	lista->Iniciar();
//	cout << "---Lista Ordenada implementada por Arreglo---" << endl;
//	cout << endl;
//	cout << "Se agregan los elementos 3, 1, 2, 4, 8, 5 en este orden" << endl;
//	lista->Agregar(3);
//	lista->Agregar(1);
//	lista->Agregar(2);
//	lista->Agregar(4);
//	lista->Agregar(8);
//	lista->Agregar(5);
//	lista->Listar();
//	if (lista->Vacia() == true)
//	{
//		cout << "Lista vacia" << endl;
//	}
//	else
//	{
//		cout << "La lista no esta vacia" << endl;
//	}
//
//	cout << "Cantidad de elementos en la lista: " << lista->NumElem() << endl;
//
//	cout << "Si eliminamos el primer elemento de la lista " << endl;
//	lista->Borrar(1);
//	lista->Listar();
//
//	cout << "Si eliminamos el ultimo elemento de la lista " << endl;
//	lista->Borrar(8);
//	lista->Listar();
//
//	cout << "Si eliminamos un elemento en medio de la lista " << endl;
//	lista->Borrar(3);
//	lista->Listar();
//
//	cout << "Cantidad de elementos en la lista despues de borrar: " << lista->NumElem() << endl;
//
//	cout << "Primer elemento en la lista: " << lista->Primero() << endl;
//	cout << "El elemento siguiente al 4 es: " << lista->Siguiente(4) << endl;
//	cout << "Ultimo elemento en la lista: " << lista->Ultimo() << endl;
//	cout << "Elemento en la posicion anterior al 5: " << lista->Anterior(5) << endl;
//
//	cout << "Al vaciar la lista" << endl;
//	lista->Vaciar();
//	cout << "Cantidad de elementos en la lista: " << lista->NumElem() << endl;
//
//	lista->Destruir();
//	cout << "Lista destruida" << endl;
//	cout << endl;
//
//}

/**

Prueba de la Estructura de Datos Lista Ordenada implementada por Lista Simplemente Enlazada

*/
//void listaOrdenadaLSE()
//{
//	ListaOrdenada lista;
//	lista.Iniciar();
//	cout << "---Lista Ordenada implementada por Lista Simplemente Enlazada---" << endl;
//	cout << endl;
//	cout << "Se agregan los elementos 3, 1, 2, 4, 8, 5 en ese orden, pero se ordenan al mismo tiempo que se agregan" << endl;
//	lista.Agregar(3);
//	lista.Agregar(1);
//	lista.Agregar(2);
//	lista.Agregar(4);
//	lista.Agregar(8);
//	lista.Agregar(5);
//	lista.Listar();
//	if (lista.Vacia() == true)
//	{
//		cout << "Lista vacia" << endl;
//	}
//	else
//	{
//		cout << "La lista no esta vacia" << endl;
//	}
//
//	cout << "Cantidad de elementos en la lista: " << lista.NumElem() << endl;
//
//	cout << "Si eliminamos el primer elemento de la lista " << endl;
//	lista.Borrar(1);
//	lista.Listar();
//
//	cout << "Si eliminamos el ultimo elemento de la lista " << endl;
//	lista.Borrar(8);
//	lista.Listar();
//
//	cout << "Si eliminamos un elemento en medio de la lista " << endl;
//	lista.Borrar(3);
//	lista.Listar();
//
//	cout << "Cantidad de elementos en la lista despues de borrar: " << lista.NumElem() << endl;
//
//	cout << "Primer elemento en la lista: " << lista.Primero() << endl;
//	cout << "El elemento siguiente al 4 es: " << lista.Siguiente(4) << endl;
//	cout << "Ultimo elemento en la lista: " << lista.Ultimo() << endl;
//	cout << "Elemento en la posicion anterior al 5: " << lista.Anterior(5) << endl;
//
//	cout << "Al vaciar la lista" << endl;
//	lista.Vaciar();
//	cout << "Cantidad de elementos en la lista: " << lista.NumElem() << endl;
//
//	lista.Destruir();
//	cout << endl;
//
//
//}

/**

Prueba de la Estructura de Datos Lista Posicionada implementada por una Lista Simplemente Enlazada

*/
//void listaPosicionadaSE()
//{
//	cout << "---Lista Posicionada implementada por una Lista Simplemente Enlazada---" << endl;
//	cout << endl;
//	Lista_Posicionada_SE Lista;
//	Lista.iniciar();
//	cout << "Se agregan los elementos 10,14,16,12,8 usanndo los métodos: insertar y agregarAlFinal" << endl;
//	Lista.agregarAlFinal(10);
//	Lista.agregarAlFinal(14);
//	Lista.agregarAlFinal(16);
//	Lista.insertar(12, Lista.siguiente(Lista.primera()));
//	Lista.insertar(8, Lista.primera());
//	posS p = Lista.primera();
//	cout << "Los elementos de la Lista son:" << endl;
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Borramos el primer elemento de la Lista(8)" << endl;
//	Lista.borrar(Lista.primera());
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Modificamos el segundo elemento de la Lista(12) por un 13" << endl;
//	Lista.modificarElemento(13, Lista.siguiente(Lista.primera()));
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Intercambiamos el primer elemento(10) con el ultimno de la Lista(16)" << endl;
//	Lista.intercambiar(Lista.primera(), Lista.ultima());
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Eliminamos la posicion anterior a la ultima de la Lista(14)" << endl;
//	Lista.borrar((Lista.anterior(Lista.ultima())));
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Verificamos si la la lista no esta vacia" << endl;
//	int elementos = Lista.numElem();
//	if (Lista.vacia())
//	{
//		cout << "La lista se encuentra vacia" << endl;
//	}
//	else
//	{
//		cout << "La Lista no esta vacia, en realidad contiene: " << elementos << " elementos" << endl;
//	}
//	cout << "Ahora si vaciaremos la lista" << endl;
//	Lista.vaciar();
//	elementos = Lista.numElem();
//	if (Lista.vacia())
//	{
//		cout << "Ahora la Lista si esta vacia, es decir contiene: " << elementos << " elementos" << endl;
//	}
//	else
//	{
//		cout << "La Lista no esta vacia" << endl;
//	}
//	cout << "Procederemos a destruir la Lista, gracias por probarla" << endl;
//	Lista.destruir();
//	cout << "Lista destruida" << endl;
//	cout << endl;
//	//LO QUE SIGUE ES PROBANDO QUE EL PROGRAMA SE CAE CUANDO SE LE AGREGA UN ELEMENTO DESPUES DE DESTRUIDA LA LISTA
//	//    cout << "Los elementos de la Lista son:" << endl;
//	//    p = Lista.primera();
//	//    Lista.agregarAlFinal(12);
//	//    for (int i = 0; i < Lista.numElem(); i++) {
//	//        cout << Lista.recuperar(p) << endl;
//	//        p = Lista.siguiente(p);
//	//    }
//}

/**

Prueba de la Estructura de Datos Lista Posicionada implementada por una Lista Doblemente Enlazada

*/

//void listaPosicionadaDE()
//{
//	cout << "---Lista Posicionada implementada por una Lista Doblemente Enlazada---" << endl;
//	cout << endl;
//	Lista_Posicionada_DE Lista;
//	Lista.iniciar();
//	cout << "Se agregan los elementos 10,14,16,12,8 usanndo los métodos: insertar y agregarAlFinal" << endl;
//	Lista.agregarAlFinal(10);
//	Lista.agregarAlFinal(14);
//	Lista.agregarAlFinal(16);
//	Lista.insertar(12, Lista.siguiente(Lista.primera()));
//	Lista.insertar(8, Lista.primera());
//	pos p = Lista.primera();
//	cout << "Los elementos de la Lista son:" << endl;
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Borramos el primer elemento de la Lista(8)" << endl;
//	Lista.borrar(Lista.primera());
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Modificamos el segundo elemento de la Lista(12) por un 13" << endl;
//	Lista.modificarElemento(13, Lista.siguiente(Lista.primera()));
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Intercambiamos el primer elemento(10) con el ultimno de la Lista(16)" << endl;
//	Lista.intercambiar(Lista.primera(), Lista.ultima());
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Eliminamos la posicion anterior a la ultima de la Lista(14)" << endl;
//	Lista.borrar((Lista.anterior(Lista.ultima())));
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Verificamos si la la lista no esta vacia" << endl;
//	int elementos = Lista.numElem();
//	if (Lista.vacia())
//	{
//		cout << "La lista se encuentra vacia" << endl;
//	}
//	else
//	{
//		cout << "La Lista no esta vacia, en realidad contiene: " << elementos << " elementos" << endl;
//	}
//	cout << "Ahora si vaciaremos la lista" << endl;
//	Lista.vaciar();
//	elementos = Lista.numElem();
//	if (Lista.vacia())
//	{
//		cout << "Ahora la Lista si esta vacia, es decir contiene: " << elementos << " elementos" << endl;
//	}
//	else
//	{
//		cout << "La Lista no esta vacia" << endl;
//	}
//	cout << "Procederemos a destruir la Lista, gracias por probarla" << endl;
//	Lista.destruir();
//	cout << "Lista destruida" << endl;
//	cout << endl;
//	//LO QUE SIGUE ES PROBANDO QUE EL PROGRAMA SE CAE CUANDO SE LE AGREGA UN ELEMENTO DESPUES DE DESTRUIDA LA LISTA
//	/*cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	Lista.agregarAlFinal(12);
//	for (int i = 0; i < Lista.numElem(); i++) {
//	cout << Lista.recuperar(p) << endl;
//	p = Lista.siguiente(p);
//	}
//	*/
//}

/**

Prueba de la Estructura de Datos Lista Posicionada implementada por un Arreglo

*/

//void listaPosicionadaArreglo()
//{
//	cout << "---Lista Posicionada implementada por un Arreglo---" << endl;
//	cout << endl;
//	Lista_Posicionada_Arreglo Lista;
//	Lista.iniciar();
//	cout << "Se agregan los elementos 10,14,16,12,8 usanndo los métodos: insertar y agregarAlFinal" << endl;
//	Lista.agregarAlFinal(10);
//	Lista.agregarAlFinal(14);
//	Lista.agregarAlFinal(16);
//	Lista.insertar(12, Lista.siguiente(Lista.primera()));
//	Lista.insertar(8, Lista.primera());
//	posA p = Lista.primera();
//	cout << "Los elementos de la Lista son:" << endl;
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Borramos el primer elemento de la Lista(8)" << endl;
//	Lista.borrar(Lista.primera());
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Modificamos el segundo elemento de la Lista(12) por un 13" << endl;
//	Lista.modificarElemento(13, Lista.siguiente(Lista.primera()));
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Intercambiamos el primer elemento(10) con el ultimno de la Lista(16)" << endl;
//	Lista.intercambiar(Lista.primera(), Lista.ultima());
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Eliminamos la posicion anterior a la ultima de la Lista(14)" << endl;
//	Lista.borrar((Lista.anterior(Lista.ultima())));
//	cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	for (int i = 0; i < Lista.numElem(); i++)
//	{
//		cout << Lista.recuperar(p) << endl;
//		p = Lista.siguiente(p);
//	}
//	cout << "Verificamos si la la lista no esta vacia" << endl;
//	int elementos = Lista.numElem();
//	if (Lista.vacia())
//	{
//		cout << "La lista se encuentra vacia" << endl;
//	}
//	else
//	{
//		cout << "La Lista no esta vacia, en realidad contiene: " << elementos << " elementos" << endl;
//	}
//	cout << "Ahora si vaciaremos la lista" << endl;
//	Lista.vaciar();
//	elementos = Lista.numElem();
//	if (Lista.vacia())
//	{
//		cout << "Ahora la Lista si esta vacia, es decir contiene: " << elementos << " elementos" << endl;
//	}
//	else
//	{
//		cout << "La Lista no esta vacia" << endl;
//	}
//	cout << "Procederemos a destruir la Lista, gracias por probarla" << endl;
//	Lista.destruir();
//	cout << "Lista destruida" << endl;
//	cout << endl;
//	//LO QUE SIGUE ES PROBANDO QUE EL PROGRAMA SE CAE CUANDO SE LE AGREGA UN ELEMENTO DESPUES DE DESTRUIDA LA LISTA
//	/*cout << "Los elementos de la Lista son:" << endl;
//	p = Lista.primera();
//	Lista.agregarAlFinal(12);
//	for (int i = 0; i < Lista.numElem(); i++) {
//	cout << Lista.recuperar(p) << endl;
//	p = Lista.siguiente(p);
//	}*/
//}

/**

Prueba de la Estructura de Datos Pila implementada por Lista Simplemente Enlazada
*/
void pila()
{
	cout << "---Pila implementada por Lista Simplemente Enlazada---" << endl;
	cout << endl;
	Pila Pila;
	Pila.iniciar();
	cout << "Se ponen los elementos: 10,12,14,16 a la Pila" << endl;
	Pila.poner(16);
	Pila.poner(14);
	Pila.poner(12);
	Pila.poner(10);
	int cantElem = Pila.numElem();
	cout << "Los elementos de la pila son:" << endl;
	for (int i = 0; i < cantElem; i++)
	{
		cout << Pila.quitar() << endl;
	}
	cout << "Como utilizamos el metodo quitar para mostra los elementos de la Pila entonces la Pila se vacio" << endl;
	cout << "El numero de elementos de la pila es: " << Pila.numElem() << " elementos" << endl;
	cout << "Procedemos a poner los elementos anteriores en la Pila" << endl;
	Pila.poner(16);
	Pila.poner(14);
	Pila.poner(12);
	Pila.poner(10);
	cout << "Verificamos que la Pila no esta vacia" << endl;
	if (Pila.vacia())
	{
		cout << "La Pila esta vacia" << endl;
	}
	else
	{
		cout << "La Pila efectivamente no esta vacia, " << "contiene: " << Pila.numElem() << " elementos" << endl;
	}
	cout << "Preguntamos que elemento es el Tope de la Pila, el cual deberia ser 10" << endl;
	cout << "El Tope de la Pila es: " << Pila.tope() << endl;
	cout << "Procedemos a vaciar la Pila que contiene: " << Pila.numElem() << " elementos" << endl;
	Pila.vaciar();
	if (Pila.vacia())
	{
		cout << "Ahora la Pila si se encuentra vacia" << endl;
	}
	else
	{
		cout << "La Pila no se encuentra vacia" << endl;
	}
	cout << "Por ultimo destruiremos la Pila, gracias por probarla" << endl;
	Pila.destruir();
	cout << "Pila destruida" << endl;
	cout << endl;
}


/**
Nombre: iguales
Parámetros: ListaOrdenada L1, ListaOrdenada L2
Efecto: Averigua si L1 es igual a L2
Requiere: Listas inicializadas
Modifica:

*/

bool iguales(ListaOrdenada *L1, ListaOrdenada *L2)
{
	int i = 1;
	elemento elem1 = L1->Primero();
	elemento elem2 = L2->Primero();
	if (L1->NumElem() != L2->NumElem())
	{
		//cout << "No son iguales" << endl;
		return false;
	}
	else
	{
		while (elem1 == elem2 && i < L1->NumElem())
		{
			elem1 = L1->Siguiente(elem1);
			elem2 = L2->Siguiente(elem2);
			i++;
		}
		if (L1->Ultimo() == L2->Ultimo())
		{
			//cout << "Son iguales" << endl;
			return true;
		}
		else
		{
			//cout << "No son iguales" << endl;
			return false;
		}
	}
}


/**
Nombre: copiar
Parámetros:  ListaOrdenada L1, ListaOrdenada L2
Efecto: Hace la lista L2 igual a la lista L1
Requiere: Listas inicializadas
Modifica: L2

*/
void copiar(ListaOrdenada *L1, ListaOrdenada *L2)
{

	int i = 0;
	elemento e1 = L1->Primero();
	L2->Vaciar();
	while (i != L1->NumElem())
	{
		L2->Agregar(e1);
		i++;
		if (e1 != L1->Ultimo())
		{
			e1 = L1->Siguiente(e1);
		}
	}
	//L2->Listar();
}


/**
Nombre: contenida
Parámetros: ListaOrdenada L1, ListaOrdenada L2
Efecto: Averigua si todos los elementos de L1 están en L2
Requiere: Listas inicializadas
Modifica:

*/
bool contenida(ListaOrdenada *L1, ListaOrdenada *L2)
{
	elemento e1 = L1->Primero();
	elemento e2 = L2->Primero();
    bool contenida = false;
	if (iguales(L1, L2))  //si ambas listas son iguales esta contenida 
	{
		//cout << "La lista esta contenida" << endl;
		return true;
	}
	else
	{
		if (L1->NumElem() > L2->NumElem()) //si el numero de elementos de L1 es mayor, que el de L2 no puede estar contenida en L2
		{
			//cout << "La lista no esta contenida" << endl;
			return false;
		}
		while (!contenida)
		{
			if (e1 == e2)
			{
				if (e1 == L1->Ultimo())
				{
					contenida = true;
					//cout << "La lista esta contenida" << endl;
					return contenida;
				}
				else if (e2 == L2->Ultimo())
				{
					contenida = true;
					//cout << "La lista esta contenida" << endl;
					return contenida;
				}
				else if(e1 != L1->Ultimo() && e2 != L2->Ultimo())
				{
					e1 = L1->Siguiente(e1);
					e2 = L2->Siguiente(e2);
					contenida = false;
				}
			}
			else if(e1 != e2)
			{
				if(e1 < e2)
				{
					contenida = false;
					//cout << "La lista no esta contenida" << endl;
					return false;
				}
				else if (e1 > e2 && e2 != L2->Ultimo())
				{
					e2 = L2->Siguiente(e2);
					contenida = false;
				}
				else if (e1 == L1->Ultimo())
				{
					contenida = false;
					//cout << "La lista no esta contenida" << endl;
					return contenida;
				}
				else if (e2 == L2->Ultimo())
				{
					contenida = false;
					//cout << "La lista no esta contenida" << endl;
					return contenida;
				}
			}
		}		
	}
}


/**
Nombre: pertenece
Parámetros: ListaOrdenada L1, elemento e
Efecto: Averigua si un elemento está en L
Requiere: Lista inicializada
Modifica:

*/
bool pertenece(ListaOrdenada *L1, elemento e)
{
	elemento e1 = L1->Primero();
	while (e1 != e && e1 != L1->Ultimo())
	{
		e1 = L1->Siguiente(e1);
		if (e1 > e)
		{
			//cout << "EL elemento no pertenece a lista" << endl;
			return false;
		}
	}
	if (e1 == e)
	{
		//cout << "EL elemento pertenece a lista" << endl;
		return true;
	}
	else if (e1 == L1->Ultimo() && e1 != e)
	{
		//cout << "EL elemento no pertenece a lista" << endl;
		return false;
	}
}


/**
Nombre: eliminar
Parámetros: ListaOrdenada L1, ListaOrdenada L2
Efecto: Elimina de L1 los elementos que están en L2
Requiere: Listas inicializadas
Modifica: L1, L1 NumElem

*/
void eliminar(ListaOrdenada *L1, ListaOrdenada *L2)
{
	elemento e1 = L1->Primero();
	elemento e2 = L2->Primero();
	elemento aux;
	if (iguales(L1, L2) == true)
	{
		L1->Vaciar();
	}
	else
	{
		while (e1 != L1->Ultimo())
		{
			if (e1 == e2)
			{
				aux = L1->Siguiente(e1);
				L1->Borrar(e1);
				e1 = aux;
				if (e2 != L2->Ultimo())
				{
					e2 = L2->Siguiente(e2);
					//i++;
				}
			}
			else if(e1 > e2)
			{
				if(e2 != L2->Ultimo())
				{
					e2 = L2->Siguiente(e2);
				}
				if(e2 == L2->Ultimo())
				{
					e1 = L1->Ultimo();
				}	
			}
			else if (e1 < e2 && e1 != L1->Ultimo())
			{
				e1 = L1->Siguiente(e1);
			}
		}
		if (e1 == L1->Ultimo())
		{
			if (e1 == e2)
			{
				L1->Borrar(e1);
			}
			else if (e1 > e2)
			{
				while (e1 < e2 && e2 != L2->Ultimo())
				{
					e2 = L2->Siguiente(e2);
				}
				if (e1 == e2)
				{
					L1->Borrar(e1);
				}
			}
		}
	}
	
}


/**
Nombre: union1
Parámetros: ListaOrdenada *L1, ListaOrdenada *L2
Efecto: Le agrega a L1 los elementos que están en  L2
Requiere: Listas inicializadas
Modifica: L1, NumElem de L1

*/
void union1(ListaOrdenada *L1, ListaOrdenada *L2)
{
	elemento e2 = L2->Primero();
	int i = 0;
	while (i != L2->NumElem())
	{
		if (pertenece(L1, e2) == true)
		{
			e2 = L2->Siguiente(e2);
			i++;
		}
		else
		{
			L1->Agregar(e2);
			e2 = L2->Siguiente(e2);
			i++;
		}
	}
}


/**
Nombre: union2
Parámetros: ListaOrdenada *L1, ListaOrdenada *L2, ListaOrdenada *L3
Efecto: Deja en L3 el resultado de la unión de L1 y L2
Requiere: Listas inicializadas
Modifica: L3, NumElem L3

*/
void union2(ListaOrdenada *L1, ListaOrdenada *L2, ListaOrdenada *L3)
{
	copiar(L1, L3);
	elemento e2 = L2->Primero();
	int i = 0;
	while (i != L2->NumElem())
	{
		if (pertenece(L1, e2) == true)
		{
			e2 = L2->Siguiente(e2);
			i++;
		}
		else
		{
			L3->Agregar(e2);
			e2 = L2->Siguiente(e2);
			i++;
		}
	}
}


/**
Nombre: interseccion1
Parámetros: ListaOrdenada *L1, ListaOrdenada *L2
Efecto: Crea la lista L3, de manera que L3 tendrá los elementos que están tanto en L1 como en L2 y la devuelve. Se usa el algoritmo auxiliar de búsqueda Pertenece
Requiere: Listas inicializadas
Modifica:  L3, NumElem de L3

*/
ListaOrdenada interseccion1(ListaOrdenada *L1, ListaOrdenada *L2)
{
	ListaOrdenada *L3 = new ListaOrdenada;
	L3->Iniciar();
	elemento e1 = L1->Primero();
	int i = 0;
	while (i != L1->NumElem())
	{
		if (pertenece(L2, e1) == true)
		{
			L3->Agregar(e1);
			e1 = L1->Siguiente(e1);
			i++;
		}
		else
		{
			e1 = L1->Siguiente(e1);
			i++;
		}
	}
	L3->Listar();
	return *L3;
}


/**
Nombre: interseccion2
Parámetros: ListaOrdenada L1, ListaOrdenada L2
Efecto: Crea la lista L3, de manera que L3 tendrá los elementos que están tanto en L1 como en L2.
El algoritmo se mueve simultáneamente en ambas listas.
Requiere: Listas inicializadas
Modifica: 

*/
ListaOrdenada interseccion2(ListaOrdenada *L1, ListaOrdenada *L2)
{
	ListaOrdenada *L3 = new ListaOrdenada;
	L3->Iniciar();
	elemento e1 = L1->Primero();
	elemento e2 = L2->Primero();
	elemento aux;
	while (e1 != L1->Ultimo())
	{
		if (e1 == e2)
		{
			aux = L1->Siguiente(e1);
			L3->Agregar(e1);
			e1 = aux;
			if (e2 != L2->Ultimo())
			{
				e2 = L2->Siguiente(e2);
			}
		}
		else if (e1 > e2)
		{
			if (e2 != L2->Ultimo())
			{
				e2 = L2->Siguiente(e2);
			}
			if (e2 == L2->Ultimo())
			{
				e1 = L1->Ultimo();
			}
		}
		else if (e1 < e2 && e1 != L1->Ultimo())
		{
			e1 = L1->Siguiente(e1);
		}
	}
	if (e1 == L1->Ultimo())
	{
		if (e1 == e2)
		{
			L3->Agregar(e1);
		}
		else if (e1 > e2)
		{
			while (e1 < e2 && e2 != L2->Ultimo())
			{
				e2 = L2->Siguiente(e2);
			}
			if (e1 == e2)
			{
				L3->Agregar(e1);
			}
		}
	}
	L3->Listar();
	return *L3;
}

//Joab

/**
Nombre: Listar
Parámetros: Lista indexada L
Efecto: Lista en pantalla los elementos de la lista LI
Requiere: Lista global LI inicializada
Modifica:

*/
void Listar(ListaIndexada *L)
{
	int i = 0;
	cout << "Los elementos de la lista son: " << endl;
	while (i < L->NumElem())
	{
		cout << L->Recuperar(i) << ", ";
		++i;
		if (i % 50 == 0) 
		{
			cout << endl;
		}
	}
	cout << endl;
	cout << "Fin de la lista." << endl;
	//system("pause");	
}

/**
Nombre: Simetrica
Parámetros: Lista indexada L
Efecto: Verifica si una lista es simétrica y devuelve el booleano correspondiente
Requiere: Lista inicializada
Modifica:

*/
bool Simetrica(ListaIndexada *L)
{
	int p = 0, q = L->NumElem() - 1;
	int repeticion = 0;
	bool simetrica = true;
	while ((repeticion < ceil(L->NumElem() / 2)) && simetrica)
	{
		if (L->Recuperar(p) != L->Recuperar(q))
		{
			simetrica = false;
		}
		else
		{
			++p;
			--q;
			++repeticion;
		}
	}
	return simetrica;
}

/**
Nombre: Invertir
Parámetros: ListaIndexada L
Efecto: Invierte los elementos de la lista L
Requiere: Lista L inicializada
Modifica: L

*/
void Invertir(ListaIndexada *L)
{
	int p = 0, q = L->NumElem() - 1;
	int repeticion = 0;
	while (repeticion < ceil(L->NumElem() / 2))
	{
		L->Intercambiar(p, q);
		++p;
		--q;
		++repeticion;
	}
}

/**
Nombre: Buscar
Parámetros: ListaIndexada L, elemento e
Efecto: Busca un elemento dado en la lista, devuelve el booleano correspondiente
Requiere: Lista L inicializada
Modifica:

*/
bool Buscar(ListaIndexada *L, int e)
{
	int i = 0;
	bool encontrado = false;

	while (i < L->NumElem() && !encontrado)
	{
		if (L->Recuperar(i) == e)
		{
			encontrado = true;
		}
		++i;
	}
	return encontrado;
}

/**
Nombre: EliminarElementosRepetidos
Parámetros: ListaIndexada L
Efecto: Elimina los elementos repetidos de una lista
Requiere: Lista global LI inicializada
Modifica: L

*/
void EliminarElementosRepetidos(ListaIndexada *L)
{
	int p = 0, q;
	bool borrado = false;
	while (p < L->NumElem())
	{
		q = p + 1;
		
		while (q < L->NumElem())
		{
			if (L->Recuperar(q) == L->Recuperar(p))
			{
				L->Borrar(q);
				borrado = true;
			}
			else
				++q;
		}
		++p;
	}
}

/**
Nombre: Sublista
Parámetros: ListaIndexada L1, ListaIndexada L2
Efecto: Averigua si L1 está contenida en L2
Requiere: Listas L1 y L2 inicializadas
Modifica:

*/
bool SubLista(ListaIndexada *L1, ListaIndexada * L2)
{
	bool subLista = false, iguales;
	int p = 0, q = 0;
	while ((p < L1->NumElem()) && (q < L2->NumElem()) && !subLista)
	{
		iguales = true;
		while (p < L1->NumElem() && iguales)
		{
			if (L1->Recuperar(p) == L2->Recuperar(q))
			{
				++p;
				++q;
			}
			else
			{
				iguales = false;
				q = 0;
				++p;
			}
		}
	}
	if (iguales && q == L2->NumElem())
	{
		subLista = true;
	}
	return subLista;
}

/**
Nombre: Iguales
Parámetros: ListaIndexada L1, ListaIndexada L2
Efecto: Averigua si L1 es igual a L2
Requiere: Listas L1 y L2 inicializadas
Modifica:

*/
bool Iguales(ListaIndexada *L1, ListaIndexada * L2)
{
	bool iguales = true;
	if (L1->NumElem() != L2->NumElem())
	{
		return false;
	}
	else
	{
		int p = 0, q = 0;
		while (iguales && p < L1->NumElem())
		{
			if (L1->Recuperar(p) != L2->Recuperar(q))
			{
				iguales = false;
			}
			++p;
			++q;
		}
	}
	return iguales;
}

/**
Nombre: BurbujaOriginal
Parámetros: ListaIndexada L
Efecto: Ordena los elementos de la lista usando el algoritmo burbuja
Requiere: Lista L inicializada
Modifica: L

*/
void BurbujaOriginal(ListaIndexada *L)
{
	int p, q;
	for (int i = L->NumElem() - 1; i > 0; --i)
	{
		p = 0;
		q = 1;
		for (int j = i; j > 0; --j)
		{
			if (L->Recuperar(p) > L->Recuperar(q))
			{
				L->Intercambiar(p, q);
			}
			++p;
			++q;
		}
	}
}

/**
Nombre: BurbujaBiDir
Parámetros: ListaIndexada L
Efecto: Ordena los elementos de la lista usando el algoritmo burbujabidireccional
Requiere: Lista L inicializada
Modifica: L

*/
void BurbujaBiDir(ListaIndexada *L)
{
	int p = 0, q;
	bool derecha = true;
	for (int i = L->NumElem() - 1; i > 0; --i)
	{
		if (derecha)
		{
			q = p + 1;
			for (int j = i; j > 0; --j)
			{
				if (L->Recuperar(p) > L->Recuperar(q))
				{
					L->Intercambiar(p, q);
				}
				if (j > 1)
				{
					++p;
					++q;
				}
			}
		}
		else
		{
			q = p - 1;
			for (int k = i; k > 0; --k)
			{
				if (L->Recuperar(p) < L->Recuperar(q))
				{
					L->Intercambiar(p, q);
				}
				if (k > 1)
				{
					--p;
					--q;
				}
			}
		}
		derecha = !derecha;
	}
}

/**
Nombre: SeleccionIterativo
Parámetros: ListaIndexada L
Efecto: Ordena los elementos de la lista usando el algoritmo Selección Iterativo
Requiere: Lista L inicializada
Modifica: L

*/
void SeleccionIterativo(ListaIndexada *L)
{
	int actual = 0, menor, recorrido;
	for (int i = 0; i < L->NumElem() - 1; ++i)
	{
		menor = actual;
		recorrido = menor + 1;
		for (int j = i + 1; j < L->NumElem(); ++j)
		{
			if (L->Recuperar(menor) > L->Recuperar(recorrido)) 
			{
				menor = recorrido;
			}
			++recorrido;
		}
		L->Intercambiar(actual, menor);
		++actual;
	}
}

/**
Nombre: SeleccionRecursivo
Parámetros: ListaIndexada L
Efecto: Llama Selección Recursivo
Requiere: Lista L inicializada
Modifica: L

*/
void SeleccionRecursivo(ListaIndexada *L)
{
	SeleccionRecursivo(L, 0);
}

/**
Nombre: SeleccionRecursivo
Parámetros: ListaIndexada L, int primera
Efecto: Ordena los elementos de la lista usando el algoritmo Selección Recursivo
Requiere: Lista L inicializada
Modifica: L

*/
void SeleccionRecursivo(ListaIndexada *L, int primera)
{
	if (primera < L->NumElem() - 1)
	{
		int menor = primera;
		int recorrido = primera + 1;
		while (recorrido < L->NumElem())
		{
			if (L->Recuperar(menor) > L->Recuperar(recorrido))
			{
				menor = recorrido;
			}
			++recorrido;
		}
		L->Intercambiar(primera, menor);
		SeleccionRecursivo(L, primera + 1);
	}
}

/**
Nombre: SeleccionRecursivoPila
Parámetros: ListaIndexada L
Efecto: Ordena los elementos de la lista usando el algoritmo Selección Recursivo pero sin usar la pila del compilador
Requiere: Lista L inicializada
Modifica: L

*/
void SeleccionRecursivoPila(ListaIndexada *L, int primera)
{
	if (primera >= L->NumElem() - 1)
	{
		return;
	}
	Pila *pilaAux = new Pila();
	pilaAux->iniciar();
	pilaAux->poner(primera);
	while (!pilaAux->vacia())
	{
		int indiceActual = pilaAux->quitar();
		if (indiceActual < L->NumElem() - 1)
		{
			pilaAux->poner(indiceActual + 1);
			int minimo = indiceActual;
			for (int indice = indiceActual + 1; indice < L->NumElem(); ++indice)
			{
				if (L->Recuperar(indice) < L->Recuperar(minimo))
					minimo = indice;
			}
			L->Intercambiar(indiceActual, minimo);
		}
	}
}

/**
Nombre: Insercion
Parámetros: ListaIndexada L, int inicio, int fin
Efecto: Ordena los elementos de la lista usando el algoritmo Insercion
Requiere: Lista L inicializada
Modifica: L

*/
void Insercion(ListaIndexada *L, int inicio, int fin)
{
	int actual = inicio + 1;
	int p, q, i, j, k = 0;
	bool ordenado;

	while (k <= fin)
	{
		ordenado = false;
		p = actual;
		i = k;
		q = p - 1;
		j = p - 1;
		while (j < fin && !ordenado)
		{
			if (L->Recuperar(q) > L->Recuperar(p))
			{
				L->Intercambiar(p, q);
				--q;
				--j;
				--p;
				--i;
			}
			else
			{
				ordenado = true;
			}
		}
		++actual;
		++k;
	}
}


/**
Nombre: EncuentraPivote
Parámetros: int i, int j
Efecto: Encuentra el pivote que usara el quick sort para ordenar la lista
Requiere: Lista global inicializada
Modifica: 

*/
int EncuentraPivote(ListaIndexada *L, int i, int j)
{
	int primeraClave = L->Recuperar(i);
	int k;
	for (k = i + 1; k <= j; ++k)
	{
		if (L->Recuperar(k) > primeraClave)
		{
			return k;
		}
		else if (L->Recuperar(k) < primeraClave)
		{
			return i;
		}
	}
	return -1;
}

/**
Nombre: Particion
Parámetros: int i, int j, int pivote
Efecto: Establece la particion a usar por el quick sort
Requiere: Lista global inicializada
Modifica: 

*/
int Particion(ListaIndexada *L, int i, int j, int pivote)
{
	int z = i, d = j;
	do
	{
		L->Intercambiar(z, d);
		while (L->Recuperar(z) < pivote)
		{
			++z;
		}
		while (L->Recuperar(d) >= pivote)
		{
			--d;
		}
	} while (z <= d);
	return z;
}

/**
Nombre: QuickSortAho
Parámetros: 
Efecto: Llama al metodo de ordenamiento recursivo QuickSortAho
Requiere: Lista global inicializada
Modifica: 

*/
void QuickSortAho(ListaIndexada *L)
{
	QuickSortAho(L, 0, L->NumElem() - 1);
}

/**
Nombre: QuickSortAho
Parámetros:
Efecto: Ordena una lista indexada usando el algoritmo Quick Sort version Aho
Requiere: Lista global inicializada
Modifica: Lista global

*/
void QuickSortAho(ListaIndexada *L, int i, int j)
{
	int pivote;
	int indicePivote;
	int k;

	indicePivote = EncuentraPivote(L, i, j);
	if (indicePivote != -1)
	{
		pivote = LI->Recuperar(indicePivote);
		k = Particion(L, i, j, pivote);
		QuickSortAho(L, i, k - 1);
		QuickSortAho(L, k, j);
	}
}

/**
Nombre: QuickSort
Parámetros:
Efecto: Llama al metodo de ordenamiento recursivo QuickSort
Requiere: Lista global inicializada
Modifica:

*/
void QuickSort(ListaIndexada *L)
{
	QuickSort(L, 0, L->NumElem() - 1);
}

/**
Nombre: QuickSort
Parámetros: ListaIndexada L, int i, int j
Efecto: Ordena una lista, si la lista es de 50 elementos o menos usa insercion
Requiere: Lista global inicializada
Modifica:

*/
void QuickSort(ListaIndexada *L, int i, int j)
{
	if (j - i <= 50)
	{
		//TODO: Llamar al metodo insercion
	}
	else
	{
		int pivote;
		int indicePivote;
		int k;

		indicePivote = EncuentraPivote(L, i, j);
		if (indicePivote != 0)
		{
			pivote = L->Recuperar(indicePivote);
			k = Particion(L, i, j, pivote);
			QuickSort(L, i, k - 1);
			QuickSort(L, k, j);
		}
	}
}


/**
Nombre: MergeSort
Parámetros: ListaIndexada L
Efecto: Devuelve una lista ordenada a partir de una lista dada
Requiere: Lista inicializada
Modifica: 

*/
ListaIndexada * MergeSort(ListaIndexada* L)
{
	if (L->NumElem() <= 1)
	{
		return L;
	}
	else
	{
		ListaIndexada *listaIzquierda = new ListaIndexada(); 
		ListaIndexada *listaDerecha = new ListaIndexada();
		listaDerecha->Iniciar();
		listaIzquierda->Iniciar();
		//int p = 0; TODO: Revisar si es necesaria esta variable
		for (int i = 0; i < L->NumElem(); ++i)
		{
			if (i < (L->NumElem() / 2))
			{
				listaIzquierda->Insertar(L->Recuperar(i), listaIzquierda->NumElem());
			}
			else
			{
				listaDerecha->Insertar(L->Recuperar(i), listaDerecha->NumElem());
			}
			//++p;
		}
		listaIzquierda = MergeSort(listaIzquierda);
		listaDerecha = MergeSort(listaDerecha);

		ListaIndexada *listaOrdenada = new ListaIndexada();
		listaOrdenada = Merge(listaIzquierda, listaDerecha);
		listaIzquierda->Destruir();
		listaDerecha->Destruir();
		return listaOrdenada;
	}
}

/**
Nombre: Merge
Parámetros: ListaIndexada L1, ListaIndexada L2
Efecto: Devuelve una lista a partir de la mezcla de dos listas
Requiere: Listas inicializadas
Modifica:

*/
ListaIndexada * Merge(ListaIndexada* L1, ListaIndexada* L2)
{
	ListaIndexada *listaMezclada = new ListaIndexada();
	listaMezclada->Iniciar();
	int i1 = 0, i2 = 0;
	while (i1 < L1->NumElem() && i2 < L2->NumElem())
	{
		if (L1->Recuperar(i1) <= L2->Recuperar(i2))
		{
			listaMezclada->Insertar(L1->Recuperar(i1), listaMezclada->NumElem());
			i1++;
		}
		else
		{
			listaMezclada->Insertar(L2->Recuperar(i2), listaMezclada->NumElem());
			i2++;
		}
	}
	while (i1 < L1->NumElem())
	{
		listaMezclada->Insertar(L1->Recuperar(i1), listaMezclada->NumElem());
		i1++;
	}
	while (i2 < L2->NumElem())
	{
		listaMezclada->Insertar(L2->Recuperar(i2), listaMezclada->NumElem());
		i2++;
	}
	return listaMezclada;
}

void UnionOrd(ListaIndexada * L1, ListaIndexada * L2)
{
	int i1 = 0, i2 = 0;
	bool encontrado;
	while (i2 < L2->NumElem())
	{
		encontrado = false;
		while (i1 < L1->NumElem() && !encontrado)
		{
			if (L2->Recuperar(i2) != L1->Recuperar(i1))
			{
				++i1;
			}
			else
			{				
				encontrado = true;
			}
		}
		if (!encontrado)
		{
			int i = 0;
			while (L1->Recuperar(i) < L2->Recuperar(i2) && i < L1->NumElem())
			{
				i++;
			}
			L1->Insertar(L2->Recuperar(i2), i);
		}
		++i2;
		i1 = 0;
	}
}

/**
Nombre: Union
Parámetros: ListaIndexada L2
Efecto: le agrega a LI los elementos que están en L2, de manera que en LI no queden elementos repetidos
Requiere: Listas inicializadas
Modifica: LI

*/
void Union(ListaIndexada *L1, ListaIndexada * L2)
{
	int i1 = 0, i2 = 0;
	bool encontrado;
	while (i2 < L2->NumElem())
	{
		encontrado = false;
		while (i1 < L1->NumElem() && !encontrado)
		{
			if (L2->Recuperar(i2) != L1->Recuperar(i1))
			{
				++i1;
			}
			else
			{
				encontrado = true;
			}
		}
		if (!encontrado)
		{
			L1->Insertar(L2->Recuperar(i2), L1->NumElem());
		}
		++i2;
		i1 = 0;
	}
}

/**
Nombre: InterseccionOrd
Parámetros: ListaIndexada L2
Efecto: Deja en L3 el resultado de la intersección de L1 y L2
Requiere: Listas LI y L2 inicializadas, ordenadas y sin elementos repetidos
Modifica: L3

*/
ListaIndexada * InterseccionOrd(ListaIndexada *L1, ListaIndexada * L2)
{
	int i1 = 0, i2 = 0;
	ListaIndexada *L3 = new ListaIndexada();
	L3->Iniciar();

	while (i1 < L1->NumElem() && i2 < L2->NumElem())
	{
		if (L1->Recuperar(i1) == L2->Recuperar(i2))
		{
			L3->Insertar(L1->Recuperar(i1), L3->NumElem());
			++i1;
			++i2;
		}
		else if(L1->Recuperar(i1) > L2->Recuperar(i2))
		{
			++i2;
		}
		else
		{
			++i1;
		}
	}
	return L3;
}

/**
Nombre: Interseccion
Parámetros: ListaIndexada L2
Efecto: Deja en L3 el resultado de la intersección de L1 y L2
Requiere: Listas LI y L2 inicializadas y sin elementos repetidos
Modifica: L3

*/
ListaIndexada * Interseccion(ListaIndexada *L1, ListaIndexada * L2)
{
	int i1, i2 = 0;
	bool encontrado;
	ListaIndexada *L3 = new ListaIndexada();
	L3->Iniciar();
	while (i2 < L2->NumElem())
	{
		encontrado = false;
		i1 = 0;		
		while (!encontrado && i1 < L1->NumElem())
		{
			if (L2->Recuperar(i2) == L1->Recuperar(i1))
			{
				L3->Insertar(L2->Recuperar(i2), L3->NumElem());
				encontrado = true;
			}
			else
			{
				++i1;
			}
		}
		++i2;
	}
	return L3;
}

/**
Nombre: EliminarInterseccionOrd
Parámetros: ListaIndexada L2
Efecto: Elimina de LI los elemenetos de la intersección con L2
Requiere: Listas LI y L2 inicializadas, ordenadas y sin elementos repetidos
Modifica: LI

*/
void EliminarInterseccionOrd(ListaIndexada *L1, ListaIndexada * L2)
{
	int i1 = 0, i2 = 0;
	while (i1 < L1->NumElem() && i2 < L2->NumElem())
	{
		if (L1->Recuperar(i1) == L2->Recuperar(i2))
		{
			L1->Borrar(i1);
			++i2;
		}
		else if (L1->Recuperar(i1) > L2->Recuperar(i2))
		{
			++i2;
		}
		else
		{
			++i1;
		}
	}
}

/**
Nombre: EliminarInterseccion
Parámetros: ListaIndexada L2
Efecto: Elimina de LI los elemenetos de la intersección con L2
Requiere: Listas LI y L2 inicializadas y sin elementos repetidos
Modifica: LI

*/
void EliminarInterseccion(ListaIndexada *L1, ListaIndexada * L2)
{
	int i1, i2 = 0;
	bool encontrado;
	while (i2 < L2->NumElem())
	{
		encontrado = false;
		i1 = 0;
		while (i1 < L1->NumElem() && !encontrado)
		{
			if (L1->Recuperar(i1) == L2->Recuperar(i2))
			{
				L1->Borrar(i1);
				encontrado = true;
			}
			else
			{
				++i1;
			}
		}
		++i2;
	}
}
