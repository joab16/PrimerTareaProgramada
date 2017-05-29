#include <iostream>
#include <stdlib.h>
#include "stdafx.h"
#include "Lista_Posicionada_Arreglo.h"
#include "Lista_Posicionada_DE.h"
#include "Lista_Posicionada_SE.h"
#include "ListaIndexadaArreglo.h"
#include "ListaIndexadaSE.h"
#include "ListaOrdenadaArreglo.h"
//#include "ListaOrdenadaLSE.h"
#include "Posicion.h"
#include "Pila.h"


typedef ListaOrdenadaArreglo ListaOrdenada;
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

bool iguales(ListaOrdenada *L1, ListaOrdenada *L2);
void copiar(ListaOrdenada *L1, ListaOrdenada *L2);
bool contenida(ListaOrdenada *L1, ListaOrdenada *L2);
bool pertenece(elemento elem);
void eliminar(ListaOrdenada *L1, ListaOrdenada *L2);
void union1(ListaOrdenada *L1, ListaOrdenada *L2);
void union2(ListaOrdenada *L1, ListaOrdenada *L2);
void interseccion1(ListaOrdenada *L1, ListaOrdenada *L2);
void interseccion2(ListaOrdenada *L1, ListaOrdenada *L2);
//holi
int main()
{
	//menu();	
	L1->Iniciar();
	L1->Agregar(1);
	L1->Agregar(3);
	L1->Agregar(5);
	L1->NumElem();
	L1->Listar();
	L2->Iniciar();
	copiar(L1, L2);
	iguales(L1, L2);	
	return 0;
}

void menu()
{

	listaOrdenadaArreglo();
	//listaOrdenadaLSE();
	//listaPosicionadaDE();
	//listaPosicionadaSE();
	//pila();
	//listaPosicionadaArreglo();
	//listaIndexadaArreglo();
	//listaIndexadaSE();




	/*int salida = 0;
	posicion p1;
	posicion p2;
	elemento e1;
	elemento e2;
	int modelo = 0;
	while(salida != -1)
	{   //Solo probar la opcion 3 del menu principal
	cout << "                Que herramienta desea utilizar?" << endl;
	cout << "Las herramientas son: 1-Lista Posicionada, 2-Lista Indexada, 3-Lista Ordenada 4-Pila"<<endl;
	cin>> modelo;
	switch(modelo)
	{
	case 1:
	cout << "Las funciones que puede realizar son: 1 = Insertar, 3 = Borrar,\n 4 = ModificarElemento, 5 = Intercambiar, 6 = Primera,\n 7 = Ultima, 8 = Siguiente, 9 = Anterior,\n 10 = Recuperar," << endl;
	cin >> salida;
	switch(salida)
	{
	case 1:
	cout << "Cual elemento desea insertar?" << endl;
	cin >> e1;
	lista.Agregar(e1);
	break;
	case 3:
	cout << "A cual nodo le quiere agregar el hijo? (etiqueta)" << endl;
	cin >> e1;
	cout << "Cual es la etiqueta del nodo que quiere agregar=" << endl;
	cin >> e2;
	//traductor
	nodoA= buscar(etiq1,arbol);
	arbol.AgregarUltimoHijo(nodoA,etiq2);
	break;
	case 4:
	cout << "Cual hoja quiere borrar? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	arbol.BorrarHoja(nodoA);
	break;
	case 5:
	cout << "A cual nodo le quiere modificar la etiqueta? (etiqueta)" << endl;
	cin >> etiq1;
	cout << "Cual es la etiqueta del nodo que quiere agregar=" << endl;
	cin >> etiq2;
	//traductor
	nodoA= buscar(etiq1,arbol);
	arbol.ModificaEtiqueta(nodoA,etiq2);
	break;
	case 6:
	cout <<  "La raiz es: " << arbol.Etiqueta(arbol.Raiz()) << endl;
	break;
	case 7:
	cout << "A cual nodo le quiere encontrar el padre? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "El padre de " << etiq1 << " es " << arbol.Etiqueta(arbol.Padre(nodoA)) << endl;
	break;
	case 8:
	cout << "A cual nodo le quiere encontrar el hijo mas izquierdo? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "El hijo mas izquierdo de " <<  etiq1 << " es: " << arbol.Etiqueta(arbol.HijoMasIzquierdo(nodoA)) << endl;
	break;
	case 9:
	cout << "A cual nodo le quiere encontrar el hermano derecho? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "El hermano derecho de " << etiq1 << " es " << arbol.Etiqueta(arbol.HermanoDerecho(nodoA)) << endl;
	break;
	case 10:
	cout << "A cual nodo le quiere encontrar la etiqueta? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "La etiqueta es: " << arbol.Etiqueta(nodoA) << endl;
	break;
	case 11:
	cout << "A cual nodo desea encontrarle su hermano izquierdo?" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "El hermano izquierdo de " << etiq1 << " es: " << hermanoIzq(nodoA) << endl;
	break;
	case 12:
	EtiquetaRepetida(arbol);
	break;
	default:
	cout << "Digito una opcion invalida" << endl;
	break;
	}
	case 2:
	cout << "Las funciones que puede realizar son: 1 = Insertar, 2 = AgregarAlFinal, 3 = Borrar,\n 4 = ModificarElemento, 5 = Intercambiar, 6 = Primera,\n 7 = Ultima, 8 = Siguiente, 9 = Anterior,\n 10 = Recuperar," << endl;
	cin >> salida;
	switch(salida)
	{
	case 1:
	cout << "Cual elemento desea insertar?" << endl;
	cin >> e1;
	lista.Agregar(e);
	break;
	case 2:
	cout << "A cual nodo le quiere agregar el hijo? (etiqueta)" << endl;
	cin >> etiq1;
	cout << "Cual es la etiqueta del nodo que quiere agregar=" << endl;
	cin >> etiq2;
	//traductor
	nodoA= buscar(etiq1,arbol);
	arbol.AgregarHijo(nodoA,etiq2);

	break;
	case 3:
	cout << "A cual nodo le quiere agregar el hijo? (etiqueta)" << endl;
	cin >> etiq1;
	cout << "Cual es la etiqueta del nodo que quiere agregar=" << endl;
	cin >> etiq2;
	//traductor
	nodoA= buscar(etiq1,arbol);
	arbol.AgregarUltimoHijo(nodoA,etiq2);
	break;
	case 4:
	cout << "Cual hoja quiere borrar? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	arbol.BorrarHoja(nodoA);
	break;
	case 5:
	cout << "A cual nodo le quiere modificar la etiqueta? (etiqueta)" << endl;
	cin >> etiq1;
	cout << "Cual es la etiqueta del nodo que quiere agregar=" << endl;
	cin >> etiq2;
	//traductor
	nodoA= buscar(etiq1,arbol);
	arbol.ModificaEtiqueta(nodoA,etiq2);
	break;
	case 6:
	cout <<  "La raiz es: " << arbol.Etiqueta(arbol.Raiz()) << endl;
	break;
	case 7:
	cout << "A cual nodo le quiere encontrar el padre? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "El padre de " << etiq1 << " es " << arbol.Etiqueta(arbol.Padre(nodoA)) << endl;
	break;
	case 8:
	cout << "A cual nodo le quiere encontrar el hijo mas izquierdo? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "El hijo mas izquierdo de " <<  etiq1 << " es: " << arbol.Etiqueta(arbol.HijoMasIzquierdo(nodoA)) << endl;
	break;
	case 9:
	cout << "A cual nodo le quiere encontrar el hermano derecho? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "El hermano derecho de " << etiq1 << " es " << arbol.Etiqueta(arbol.HermanoDerecho(nodoA)) << endl;
	break;
	case 10:
	cout << "A cual nodo le quiere encontrar la etiqueta? (etiqueta)" << endl;
	cin >> etiq1;
	nodoA= buscar(etiq1,arbol);
	cout << "La etiqueta es: " << arbol.Etiqueta(nodoA) << endl;
	break;
	default:
	cout << "Digito una opcion invalida" << endl;
	break;
	}
	case 3:
	cout << "Las funciones que puede realizar son: 1 = Agregar, 2 = Borrar, 3 = Primero,\n 4 = Siguiente, 5 = Ultimo, 6 = Anterior," << endl;
	cin >> salida;
	switch(salida)
	{
	case 1:

	cout << "Cual elemento desea insertar?" << endl;
	cin >> e1;
	lista.Agregar(e1);
	break;
	case 2:
	cout << "Cual elemento desea borrar?" << endl;
	cin >> e1;
	lista.Borrar(e);
	break;
	case 3:
	cout << "El primer elemento de la lista es: " << lista.Primero()<<endl;
	break;
	case 4:
	cout << "Ingrese el elemento para el que desea saber el siguiente" <<endl;
	cin >> e;
	cout << "El elemento siguiente a la posicion es: " << lista.Siguiente(e)<<endl;
	break;
	case 5:
	cout << "El ultimo elemento de la lista es: " << lista.Ultimo()<<endl;
	break;
	case 6:
	cout << "Ingrese el elemento para el que desea saber el anterior" <<endl;
	cin >> e;
	cout << "El elemento anterior a la posicion es: " << lista.Anterior(e)<<endl;
	break;
	default:
	cout << "Digito una opcion invalida" << endl;
	break;
	}
	break;
	}




	}
	cout << "Desea seguir utilizando el arbol?\n" << "1 = si, -1 = no" << endl;
	cin >> salida;*/
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
	ListaOrdenada lista;
	lista.Iniciar();
	cout << "---Lista Ordenada implementada por Arreglo---" << endl;
	cout << endl;
	cout << "Se agregan los elementos 3, 1, 2, 4, 8, 5 en este orden" << endl;
	lista.Agregar(3);
	lista.Agregar(1);
	lista.Agregar(2);
	lista.Agregar(4);
	lista.Agregar(8);
	lista.Agregar(0);
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
Nombre: Iguales
Parámetros: L1, L2
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
Nombre: Copiar
Parámetros: L1, L2
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
	L2->Listar();
}


/**
Nombre: Contenida
Parámetros: L1, L2
Efecto: Averigua si todos los elementos de L1 están en L2
Requiere: Listas inicializadas
Modifica:

*/
bool contenida(ListaOrdenada *L1, ListaOrdenada *L2)
{
	elemento e1 = L1->Primero();
	return true;
}


/**
Nombre: Pertenece
Parámetros: L, elemento e
Efecto: Averigua si un elemento está en L
Requiere: Lista inicializada
Modifica:

*/
bool pertenece(elemento e)
{
	return true;
}


/**
Nombre: Eliminar
Parámetros: L1, L2
Efecto: Elimina de L1 los elementos que están en L2
Requiere: Listas inicializadas
Modifica:

*/
void eliminar(ListaOrdenada *L1, ListaOrdenada *L2)
{
	elemento e1 = L1->Primero();
	elemento e2 = L2->Primero();
	int i = 0, i2 = 1;
	while (i < L1->NumElem())
	{
		while (i2<L2->NumElem())
		{
			if (e1 == e2)
			{
				L1->Borrar(e1);
				e2 = L2->Siguiente(e2);
			}
			i2++;
		}
		i++;
		e1 = L1->Siguiente(e1);
		//i++;
	}
	//    for (e1 = L1.Primero(); e1 == L1.Ultimo(); e1 = L1.Siguiente(e1))
	//    {
	//        for (e2 = L2.Primero(); e2 == L2.Ultimo(); e2= L2.Siguiente(e2))
	//        {
	//            if( e1 == e2)
	//            {
	//                L1.Borrar(e1);
	//            }
	//        }
	//    }
}


/**
Nombre: Union1
Parámetros: L1, L2
Efecto: Le agrega a L1 los elementos que están en  L2
Requiere: Listas inicializadas
Modifica:

*/
void union1(ListaOrdenada *L1, ListaOrdenada *L2)
{

}


/**
Nombre: Union2
Parámetros: L1, L2
Efecto: Deja en L3 el resultado de la unión de L1 y L2
Requiere: Listas inicializadas
Modifica:

*/
void union2(ListaOrdenada *L1, ListaOrdenada *L2)
{

}


/**
Nombre: Interseccion1
Parámetros: L1, L2
Efecto: Crea la lista L3, de manera que L3 tendrá los elementos que están tanto en L1 como en L2.
Se usa el algoritmo auxiliar de búsqueda Pertenece
Requiere: Listas inicializadas
Modifica:

*/
void interseccion1(ListaOrdenada *L1, ListaOrdenada *L2)
{

}


/**
Nombre: interseccion2
Parámetros: L1, L2
Efecto: Crea la lista L3, de manera que L3 tendrá los elementos que están tanto en L1 como en L2.
El algoritmo se mueve simultáneamente en ambas listas.
Requiere: Listas inicializadas
Modifica:

*/
void interseccion2(ListaOrdenada *L1, ListaOrdenada *L2)
{

}

