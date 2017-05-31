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

bool iguales(ListaOrdenada *L1, ListaOrdenada *L2);
void copiar(ListaOrdenada *L1, ListaOrdenada *L2);
bool contenida(ListaOrdenada *L1, ListaOrdenada *L2);
bool pertenece(ListaOrdenada *L1, elemento elem);
void eliminar(ListaOrdenada *L1, ListaOrdenada *L2);
void union1(ListaOrdenada *L1, ListaOrdenada *L2);
void union2(ListaOrdenada *L1, ListaOrdenada *L2, ListaOrdenada *L3);
ListaOrdenada interseccion1(ListaOrdenada *L1, ListaOrdenada *L2);
ListaOrdenada interseccion2(ListaOrdenada *L1, ListaOrdenada *L2);

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
	posicion p2;
	elemento e1;
	elemento e2;
	int modelo = 0;
	cout << "                Que herramienta desea utilizar?" << endl;
	cout << "Las herramientas son: 1-Lista Posicionada, 2-Lista Indexada, 3-Lista Ordenada" << endl;
	cin >> modelo;
	while(salida != -1)
	{   
	switch (modelo)
	{
	case 1:
		cout << "Las funciones que puede realizar son: -1 = Salir, 1 = Insertar, 3 = Borrar,\n 4 = ModificarElemento, 5 = Intercambiar, 6 = Primera,\n 7 = Ultima, 8 = Siguiente, 9 = Anterior,\n 10 = Recuperar," << endl;
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
		L1->Iniciar();
		L2->Iniciar();
		L3->Iniciar();
		cout << "Tiene a su disposicion 2 listas L1 y L2" << endl;
		cout << "Las funciones que puede realizar son: -1 = Salir, 1 = Agregar, 2 = Borrar, 3 = Primero,\n 4 = Siguiente, 5 = Ultimo, 6 = Anterior,\n 7 = Listar, 8 = Iguales, 9 = Copiar,\n 10 = Contenida, 11 = Pertenece, 12 = EliminarIntersec,\n 13 = Union1, 14 = Union2, 15 = Interseccion1, 16 = Interseccion2" << endl;
		cin >> salida;
		switch (salida)
		{
		case 1:
			cout << "En cual lista desea agregar elementos? 1 = L1, 2 = L2" << endl;
			cin >> e1;
			if (e1 = 1)
			{
				cout << "Cual elemento desea insertar?" << endl;
				cin >> e1;
				L1->Agregar(e1);
			}
			else
			{ 
				cout << "Cual elemento desea insertar?" << endl;
				cin >> e1;
				L2->Agregar(e1);
			}
			break;
		case 2:
			cout << "En cual lista desea borrar elementos? 1 = L1, 2 = L2" << endl;
			cin >> e1;
			if (e1 = 1)
			{
				cout << "Cual elemento desea borrar?" << endl;
				cin >> e1;
				L1->Borrar(e1);
			}
			else
			{
				cout << "Cual elemento desea borrar?" << endl;
				cin >> e1;
				L2->Borrar(e1);
			}
			break;
		case 3:
			cout << "El primer elemento de la lista es: " << L1->Primero() << endl;
			break;
		case 4:
			cout << "Ingrese el elemento para el que desea saber el siguiente" << endl;
			cin >> e1;
			cout << "El elemento siguiente a la posicion es: " << L1->Siguiente(e1) << endl;
			break;
		case 5:
			cout << "El ultimo elemento de la lista es: " << L1->Ultimo() << endl;
			break;
		case 6:
			cout << "Ingrese el elemento para el que desea saber el anterior" << endl;
			cin >> e1;
			cout << "El elemento anterior a la posicion es: " << L1->Anterior(e1) << endl;
			break;
		case 7:
			cout << "Cual lista desea imprimir? 1 = L1, 2 = L2" << endl;
				cin >> e1;
			if (e1 = 1)
			{
				L1->Listar();
			}
			else
			{
				L2->Listar();
			}
			break;
		case 8:
			iguales(L1, L2);
			break;
		case 9:
			copiar(L1, L2);
			break;
		case 10:
			contenida(L1, L2);
			break;
		case 11:
			cout << "En cual lista desea saber si el elemento pertenece? 1 = L1, 2 = L2" << endl;
				cin >> e1;
			if (e1 = 1)
			{
				cout << "Ingrese el elemento para saber si pertenece a la lista" << endl;
				cin >> e1;
				pertenece(L1, e1);
			}
			else
			{
				cout << "Ingrese el elemento para saber si pertenece a la lista" << endl;
				cin >> e1;
				pertenece(L2, e1);
			}
			break;
		case 12:
			eliminar(L1, L2);
			break;
		case 13:
			union1(L1, L1);
			break;
		case 14:
			union2(L1, L2, L3);
			break;
		case 15:
			interseccion1(L1, L2);
			break;
		case 16:
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
void listaIndexadaArreglo()
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
}


/**

Prueba de la Estructura de Datos Lista Ordenada implementada por Arreglo

*/
void listaOrdenadaArreglo()
{
	ListaOrdenada *lista = new ListaOrdenada;
	lista->Iniciar();
	cout << "---Lista Ordenada implementada por Arreglo---" << endl;
	cout << endl;
	cout << "Se agregan los elementos 3, 1, 2, 4, 8, 5 en este orden" << endl;
	lista->Agregar(3);
	lista->Agregar(1);
	lista->Agregar(2);
	lista->Agregar(4);
	lista->Agregar(8);
	lista->Agregar(5);
	lista->Listar();
	if (lista->Vacia() == true)
	{
		cout << "Lista vacia" << endl;
	}
	else
	{
		cout << "La lista no esta vacia" << endl;
	}

	cout << "Cantidad de elementos en la lista: " << lista->NumElem() << endl;

	cout << "Si eliminamos el primer elemento de la lista " << endl;
	lista->Borrar(1);
	lista->Listar();

	cout << "Si eliminamos el ultimo elemento de la lista " << endl;
	lista->Borrar(8);
	lista->Listar();

	cout << "Si eliminamos un elemento en medio de la lista " << endl;
	lista->Borrar(3);
	lista->Listar();

	cout << "Cantidad de elementos en la lista despues de borrar: " << lista->NumElem() << endl;

	cout << "Primer elemento en la lista: " << lista->Primero() << endl;
	cout << "El elemento siguiente al 4 es: " << lista->Siguiente(4) << endl;
	cout << "Ultimo elemento en la lista: " << lista->Ultimo() << endl;
	cout << "Elemento en la posicion anterior al 5: " << lista->Anterior(5) << endl;

	cout << "Al vaciar la lista" << endl;
	lista->Vaciar();
	cout << "Cantidad de elementos en la lista: " << lista->NumElem() << endl;

	lista->Destruir();
	cout << "Lista destruida" << endl;
	cout << endl;

}

/**

Prueba de la Estructura de Datos Lista Ordenada implementada por Lista Simplemente Enlazada

*/
void listaOrdenadaLSE()
{
	ListaOrdenada lista;
	lista.Iniciar();
	cout << "---Lista Ordenada implementada por Lista Simplemente Enlazada---" << endl;
	cout << endl;
	cout << "Se agregan los elementos 3, 1, 2, 4, 8, 5 en ese orden, pero se ordenan al mismo tiempo que se agregan" << endl;
	lista.Agregar(3);
	lista.Agregar(1);
	lista.Agregar(2);
	lista.Agregar(4);
	lista.Agregar(8);
	lista.Agregar(5);
	lista.Listar();
	if (lista.Vacia() == true)
	{
		cout << "Lista vacia" << endl;
	}
	else
	{
		cout << "La lista no esta vacia" << endl;
	}

	cout << "Cantidad de elementos en la lista: " << lista.NumElem() << endl;

	cout << "Si eliminamos el primer elemento de la lista " << endl;
	lista.Borrar(1);
	lista.Listar();

	cout << "Si eliminamos el ultimo elemento de la lista " << endl;
	lista.Borrar(8);
	lista.Listar();

	cout << "Si eliminamos un elemento en medio de la lista " << endl;
	lista.Borrar(3);
	lista.Listar();

	cout << "Cantidad de elementos en la lista despues de borrar: " << lista.NumElem() << endl;

	cout << "Primer elemento en la lista: " << lista.Primero() << endl;
	cout << "El elemento siguiente al 4 es: " << lista.Siguiente(4) << endl;
	cout << "Ultimo elemento en la lista: " << lista.Ultimo() << endl;
	cout << "Elemento en la posicion anterior al 5: " << lista.Anterior(5) << endl;

	cout << "Al vaciar la lista" << endl;
	lista.Vaciar();
	cout << "Cantidad de elementos en la lista: " << lista.NumElem() << endl;

	lista.Destruir();
	cout << endl;


}

/**

Prueba de la Estructura de Datos Lista Posicionada implementada por una Lista Simplemente Enlazada

*/
void listaPosicionadaSE()
{
	cout << "---Lista Posicionada implementada por una Lista Simplemente Enlazada---" << endl;
	cout << endl;
	Lista_Posicionada_SE Lista;
	Lista.iniciar();
	cout << "Se agregan los elementos 10,14,16,12,8 usanndo los métodos: insertar y agregarAlFinal" << endl;
	Lista.agregarAlFinal(10);
	Lista.agregarAlFinal(14);
	Lista.agregarAlFinal(16);
	Lista.insertar(12, Lista.siguiente(Lista.primera()));
	Lista.insertar(8, Lista.primera());
	posS p = Lista.primera();
	cout << "Los elementos de la Lista son:" << endl;
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Borramos el primer elemento de la Lista(8)" << endl;
	Lista.borrar(Lista.primera());
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Modificamos el segundo elemento de la Lista(12) por un 13" << endl;
	Lista.modificarElemento(13, Lista.siguiente(Lista.primera()));
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Intercambiamos el primer elemento(10) con el ultimno de la Lista(16)" << endl;
	Lista.intercambiar(Lista.primera(), Lista.ultima());
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Eliminamos la posicion anterior a la ultima de la Lista(14)" << endl;
	Lista.borrar((Lista.anterior(Lista.ultima())));
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Verificamos si la la lista no esta vacia" << endl;
	int elementos = Lista.numElem();
	if (Lista.vacia())
	{
		cout << "La lista se encuentra vacia" << endl;
	}
	else
	{
		cout << "La Lista no esta vacia, en realidad contiene: " << elementos << " elementos" << endl;
	}
	cout << "Ahora si vaciaremos la lista" << endl;
	Lista.vaciar();
	elementos = Lista.numElem();
	if (Lista.vacia())
	{
		cout << "Ahora la Lista si esta vacia, es decir contiene: " << elementos << " elementos" << endl;
	}
	else
	{
		cout << "La Lista no esta vacia" << endl;
	}
	cout << "Procederemos a destruir la Lista, gracias por probarla" << endl;
	Lista.destruir();
	cout << "Lista destruida" << endl;
	cout << endl;
	//LO QUE SIGUE ES PROBANDO QUE EL PROGRAMA SE CAE CUANDO SE LE AGREGA UN ELEMENTO DESPUES DE DESTRUIDA LA LISTA
	//    cout << "Los elementos de la Lista son:" << endl;
	//    p = Lista.primera();
	//    Lista.agregarAlFinal(12);
	//    for (int i = 0; i < Lista.numElem(); i++) {
	//        cout << Lista.recuperar(p) << endl;
	//        p = Lista.siguiente(p);
	//    }
}
/**

Prueba de la Estructura de Datos Lista Posicionada implementada por una Lista Doblemente Enlazada

*/

void listaPosicionadaDE()
{
	cout << "---Lista Posicionada implementada por una Lista Doblemente Enlazada---" << endl;
	cout << endl;
	Lista_Posicionada_DE Lista;
	Lista.iniciar();
	cout << "Se agregan los elementos 10,14,16,12,8 usanndo los métodos: insertar y agregarAlFinal" << endl;
	Lista.agregarAlFinal(10);
	Lista.agregarAlFinal(14);
	Lista.agregarAlFinal(16);
	Lista.insertar(12, Lista.siguiente(Lista.primera()));
	Lista.insertar(8, Lista.primera());
	pos p = Lista.primera();
	cout << "Los elementos de la Lista son:" << endl;
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Borramos el primer elemento de la Lista(8)" << endl;
	Lista.borrar(Lista.primera());
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Modificamos el segundo elemento de la Lista(12) por un 13" << endl;
	Lista.modificarElemento(13, Lista.siguiente(Lista.primera()));
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Intercambiamos el primer elemento(10) con el ultimno de la Lista(16)" << endl;
	Lista.intercambiar(Lista.primera(), Lista.ultima());
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Eliminamos la posicion anterior a la ultima de la Lista(14)" << endl;
	Lista.borrar((Lista.anterior(Lista.ultima())));
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Verificamos si la la lista no esta vacia" << endl;
	int elementos = Lista.numElem();
	if (Lista.vacia())
	{
		cout << "La lista se encuentra vacia" << endl;
	}
	else
	{
		cout << "La Lista no esta vacia, en realidad contiene: " << elementos << " elementos" << endl;
	}
	cout << "Ahora si vaciaremos la lista" << endl;
	Lista.vaciar();
	elementos = Lista.numElem();
	if (Lista.vacia())
	{
		cout << "Ahora la Lista si esta vacia, es decir contiene: " << elementos << " elementos" << endl;
	}
	else
	{
		cout << "La Lista no esta vacia" << endl;
	}
	cout << "Procederemos a destruir la Lista, gracias por probarla" << endl;
	Lista.destruir();
	cout << "Lista destruida" << endl;
	cout << endl;
	//LO QUE SIGUE ES PROBANDO QUE EL PROGRAMA SE CAE CUANDO SE LE AGREGA UN ELEMENTO DESPUES DE DESTRUIDA LA LISTA
	/*cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	Lista.agregarAlFinal(12);
	for (int i = 0; i < Lista.numElem(); i++) {
	cout << Lista.recuperar(p) << endl;
	p = Lista.siguiente(p);
	}
	*/
}

/**

Prueba de la Estructura de Datos Lista Posicionada implementada por un Arreglo

*/
void listaPosicionadaArreglo()
{
	cout << "---Lista Posicionada implementada por un Arreglo---" << endl;
	cout << endl;
	Lista_Posicionada_Arreglo Lista;
	Lista.iniciar();
	cout << "Se agregan los elementos 10,14,16,12,8 usanndo los métodos: insertar y agregarAlFinal" << endl;
	Lista.agregarAlFinal(10);
	Lista.agregarAlFinal(14);
	Lista.agregarAlFinal(16);
	Lista.insertar(12, Lista.siguiente(Lista.primera()));
	Lista.insertar(8, Lista.primera());
	posA p = Lista.primera();
	cout << "Los elementos de la Lista son:" << endl;
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Borramos el primer elemento de la Lista(8)" << endl;
	Lista.borrar(Lista.primera());
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Modificamos el segundo elemento de la Lista(12) por un 13" << endl;
	Lista.modificarElemento(13, Lista.siguiente(Lista.primera()));
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Intercambiamos el primer elemento(10) con el ultimno de la Lista(16)" << endl;
	Lista.intercambiar(Lista.primera(), Lista.ultima());
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Eliminamos la posicion anterior a la ultima de la Lista(14)" << endl;
	Lista.borrar((Lista.anterior(Lista.ultima())));
	cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	for (int i = 0; i < Lista.numElem(); i++)
	{
		cout << Lista.recuperar(p) << endl;
		p = Lista.siguiente(p);
	}
	cout << "Verificamos si la la lista no esta vacia" << endl;
	int elementos = Lista.numElem();
	if (Lista.vacia())
	{
		cout << "La lista se encuentra vacia" << endl;
	}
	else
	{
		cout << "La Lista no esta vacia, en realidad contiene: " << elementos << " elementos" << endl;
	}
	cout << "Ahora si vaciaremos la lista" << endl;
	Lista.vaciar();
	elementos = Lista.numElem();
	if (Lista.vacia())
	{
		cout << "Ahora la Lista si esta vacia, es decir contiene: " << elementos << " elementos" << endl;
	}
	else
	{
		cout << "La Lista no esta vacia" << endl;
	}
	cout << "Procederemos a destruir la Lista, gracias por probarla" << endl;
	Lista.destruir();
	cout << "Lista destruida" << endl;
	cout << endl;
	//LO QUE SIGUE ES PROBANDO QUE EL PROGRAMA SE CAE CUANDO SE LE AGREGA UN ELEMENTO DESPUES DE DESTRUIDA LA LISTA
	/*cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	Lista.agregarAlFinal(12);
	for (int i = 0; i < Lista.numElem(); i++) {
	cout << Lista.recuperar(p) << endl;
	p = Lista.siguiente(p);
	}*/
}

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
		cout << "No son iguales" << endl;
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
			cout << "Son iguales" << endl;
			return true;
		}
		else
		{
			cout << "No son iguales" << endl;
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
		cout << "La lista esta contenida" << endl;
		return true;
	}
	else
	{
		if (L1->NumElem() > L2->NumElem()) //si el numero de elementos de L1 es mayor, que el de L2 no puede estar contenida en L2
		{
			cout << "La lista no esta contenida" << endl;
			return false;
		}
		while (!contenida)
		{
			if (e1 == e2)
			{
				if (e1 == L1->Ultimo())
				{
					contenida = true;
					cout << "La lista esta contenida" << endl;
					return contenida;
				}
				else if (e2 == L2->Ultimo())
				{
					contenida = true;
					cout << "La lista esta contenida" << endl;
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
					cout << "La lista no esta contenida" << endl;
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
					cout << "La lista no esta contenida" << endl;
					return contenida;
				}
				else if (e2 == L2->Ultimo())
				{
					contenida = false;
					cout << "La lista no esta contenida" << endl;
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

