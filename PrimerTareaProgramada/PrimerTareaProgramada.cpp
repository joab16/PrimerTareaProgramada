#include <iostream>
#include <stdlib.h>
#include "stdafx.h"
//#include "Lista_Posicionada_Arreglo.h"
#include "Lista_Posicionada_DE.h"
//#include "Lista_Posicionada_SE.h"
#include "ListaIndexadaArreglo.h"
#include "ListaIndexadaSE.h"
#include "ListaOrdenadaArreglo.h"
//#include "ListaOrdenadaLSE.h"
#include "Posicion.h"


typedef ListaOrdenadaArreglo ListaOrdenada;
//typedef ListaOrdenadaLSE ListaOrdenada;
typedef Lista_Posicionada_DE ListaPosicionada;
//typedef Lista_Posicionada_Arreglo ListaPosicionada;
//typedef Lista_Posicionada_SE ListaPosicionada;
using namespace std;

void menu();
void listaOrdenadaArreglo();
void listaOrdenadaLSE();
void listaIndexadaArreglo();
void listaIndexadaSE();
void listaPosicionada();

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

void listaPosicionada()
{
	cout << "---Lista Posicionada implementada por una Lista Doblemente Enlazada---" << endl;
	ListaPosicionada* Lista = new ListaPosicionada();
	cout << "Se agregan los elementos 10,14,16,12,8 usanndo los m�todos: insertar y agregarAlFinal" << endl;
	Lista->agregarAlFinal(10);
	Lista->agregarAlFinal(14);
	Lista->agregarAlFinal(16);
	Lista->insertar(12, Lista->siguiente(Lista->primera()));
	Lista->insertar(8, Lista->primera());
	Lista->listar();
	cout << "Borramos el primer elemento de la Lista(8)" << endl;
	Lista->borrar(Lista->primera());
	Lista->listar();
	cout << "Modificamos el segundo elemento de la Lista(12) por un 13" << endl;
	Lista->modificarElemento(13, Lista->siguiente(Lista->primera()));
	Lista->listar();
	cout << "Intercambiamos el primer elemento(10) con el ultimno de la Lista(16)" << endl;
	Lista->intercambiar(Lista->primera(), Lista->ultima());
	Lista->listar();
	cout << "Eliminamos la posicion anterior a la ultima de la Lista(14)" << endl;
	Lista->borrar((Lista->anterior(Lista->ultima())));
	Lista->listar();
	cout << "Verificamos si la la lista no esta vacia" << endl;
	int elementos = Lista->numElem();
	if (Lista->vacia()) {
		cout << "La lista se encuentra vacia" << endl;
	}
	else {
		cout << "La Lista no est� vacia, en realidad contiene: " << elementos << " elementos" << endl;
	}
	cout << "Ahora s� vaciaremos la lista" << endl;
	Lista->vaciar();
	elementos = Lista->numElem();
	if (Lista->vacia()) {
		cout << "Ahora la Lista s� est� vacia, es decir contiene: " << elementos << " elementos" << endl;
	}
	else {
		cout << "La Lista no est� vacia" << endl;
	}
	cout << "Procederemos a destruir la Lista, gracias por probarla" << endl;
	Lista->destruir();
	//LO QUE SIGUE ES PROBANDO QUE EL PROGRAMA SE CAE CUANDO SE LE AGREGA UN ELEMENTO DESPUES DE DESTRUIDA LA LISTA
	/*cout << "Los elementos de la Lista son:" << endl;
	p = Lista.primera();
	Lista.agregarAlFinal(12);
	for (int i = 0; i < Lista.numElem(); i++) {
	cout << Lista.recuperar(p) << endl;
	p = Lista.siguiente(p);
	}*/
	cout << "Creamos una Lista L para probar mas algoritmos" << endl;
	ListaPosicionada* L = new ListaPosicionada();
	L->agregarAlFinal(7);
	L->agregarAlFinal(1);
	L->agregarAlFinal(5);
	L->agregarAlFinal(0);
	L->listar();
	cout << "Ahora usaremos el metodo simetrica en L(lo cual no es cierto)" << endl;
	if (L->simetrica()) {
		cout << "La lista L es simetrica" << endl;
	}
	else {
		cout << "La lista L no es simetrica" << endl;
	}
	cout << "Invertimos L" << endl;
	L->invertir();
	L->listar();
	cout << "Buscamos el elemento 10(el cual no esta en la lista L)" << endl;
	if (L->buscar(10)) {
		cout << "El elemento 10 si esta en la lista L" << endl;
	}
	else {
		cout << "El elemento 10 no esta en la lista L" << endl;
	}
	cout << "De la misma manera buscamos el elemento 7 que si se encuentra en L" << endl;
	if (L->buscar(7)) {
		cout << "El elemento 7 si esta en la lista L" << endl;
	}
	else {
		cout << "El elemento 7 no esta en la lista L" << endl;
	}
	cout << "Agregamos otra vez el elemento 1" << endl;
	L->agregarAlFinal(1);
	L->listar();
	cout << "borramos los elementos repetidos" << endl;
	L->elimElemRep();
	L->listar();
	int otros;
	otros = L->numElem();
	cout << "Creamos una lista L2 con los elementos 1 y 7" << endl;
	otros = L->numElem();
	ListaPosicionada* L2 = new ListaPosicionada();
	otros = L->numElem();
	otros = L->numElem();
	L2->agregarAlFinal(1);
	otros = L->numElem();
	L2->agregarAlFinal(7);
	otros = L->numElem();
	cout << "Los elementos de L2 son: " << endl;
	L2->listar();
	otros = L->numElem();
	cout << "Vemos si L2 es subLista de L, lo cual es cierto" << endl;
	if (L->subLista(L2)) {
		cout << "L2 es subLista de L" << endl;
	}
	else {
		cout << "L2 no es subLista de L" << endl;
	}
	cout << "Invertimos L2" << endl;
	L2->invertir();
	cout << "Los elementos de L2 son: " << endl;
	L2->listar();
	cout << "Volvemos a preguntar si L2 es subLista de L, lo cual ahora no sera cierto" << endl;
	bool subLista = L->subLista(L2);
	if (subLista) {
		cout << "L2 es subLista de L" << endl;
	}
	else {
		cout << "L2 no es subLista de L" << endl;
	}
	cout << "Preguntamos si L y L2 son iguales, lo cual es falso" << endl;
	if (L->iguales(L2)) {
		cout << "L2 es igual a L" << endl;
	}
	else {
		cout << "L2 no es igual a L" << endl;
	}
	cout << "Ahora agregamos 5 y 0 a L2 para que contenga los mismos elementos de L" << endl;
	L2->agregarAlFinal(5);
	L2->agregarAlFinal(0);
	cout << "Listamos L2" << endl;
	L2->listar();
	cout << "Ordemamos L con Burbuja Original" << endl;
	L->burbujaOriginal();
	L->listar();
	cout << "Ordenamos L2 con Burbuja Bidireccional" << endl;
	L2->burbujaBiDir();
	L2->listar();
	cout << "Volvemos a preguntar si L es igual  L2" << endl;
	if (L->iguales(L2)) {
		cout << "L2 es igual a L" << endl;
	}
	else {
		cout << "L2 no es igual a L" << endl;
	}
	cout << "Invertimos ambas Listas" << endl;
	L->invertir();
	L2->invertir();
	cout << "Listamos L" << endl;
	L->listar();
	cout << "Listamos L2" << endl;
	L2->listar();
	cout << "Ordenamos L con seleccion iterativo y L2 con seleccion recursivo" << endl;
	L->selectIter();
	L2->selectRec();
	cout << "Listamos L" << endl;
	L->listar();
	cout << "Listamos L2" << endl;
	L2->listar();
	cout << "Creamos una Lista L3 con los elementos 10,2,4" << endl;
	ListaPosicionada* L3 = new ListaPosicionada();
	L3->agregarAlFinal(10);
	L3->agregarAlFinal(2);
	L3->agregarAlFinal(4);
	L3->listar();
	cout << "Ordenamos L3 con mergeSort" << endl;
	L3 = L3->mergeSort();
	L3->listar();
	cout << "Destruimos L y unimos L2 con L3" << endl;
	L->destruir();
	L2->Union(L3);
	//Podriamos Destruir L3
	L2->listar();
	cout << "Ahora vemos cual es la interseccion entre L2 y L3, seria L3(2,4,10), y la listamos" << endl;
	L2->interseccion(L3)->listar();
	cout << "Ordenamos L2 con insercion y preguntamos cual es la interseccion ordenada con L3,deberia ser igual a la interseccion(desordenada)" << endl;
	L2->insercion();
	L2->listar();
	cout << "La interseccion ordenada es la siguiente" << endl;
	L2->interseccionOrd(L3)->listar();
	cout << "Ahora con el metodo eliminarInterseccionOrdenada eliminamos la interseccion entre L2 y L3 y dejamos el resultado en L2" << endl;
	L2->eliminarIntrOrd(L3);
	L2->listar();
	cout << "Unimos L2 con L3 nuevamente, ordenamos la lista y la invertimos" << endl;
	L2->Union(L3);
	L2->selectRec();
	L2->invertir();
	L2->listar();
	cout << "Ahora eliminamos la interseccion(desordenada) de L2 y L3" << endl;
	L2->eliminarIntr(L3);
	L2->listar();
	cout << "Por ultimo destruimos L2 y L3" << endl;
	L2->destruir();
	L3->destruir();
}

/**

/**
Nombre: Iguales
Par�metros: L1, L2
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
Par�metros: L1, L2
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
Par�metros: L1, L2
Efecto: Averigua si todos los elementos de L1 est�n en L2
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
Par�metros: L, elemento e
Efecto: Averigua si un elemento est� en L
Requiere: Lista inicializada
Modifica:

*/
bool pertenece(elemento e)
{
	return true;
}


/**
Nombre: Eliminar
Par�metros: L1, L2
Efecto: Elimina de L1 los elementos que est�n en L2
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
Par�metros: L1, L2
Efecto: Le agrega a L1 los elementos que est�n en  L2
Requiere: Listas inicializadas
Modifica:

*/
void union1(ListaOrdenada *L1, ListaOrdenada *L2)
{

}


/**
Nombre: Union2
Par�metros: L1, L2
Efecto: Deja en L3 el resultado de la uni�n de L1 y L2
Requiere: Listas inicializadas
Modifica:

*/
void union2(ListaOrdenada *L1, ListaOrdenada *L2)
{

}


/**
Nombre: Interseccion1
Par�metros: L1, L2
Efecto: Crea la lista L3, de manera que L3 tendr� los elementos que est�n tanto en L1 como en L2.
Se usa el algoritmo auxiliar de b�squeda Pertenece
Requiere: Listas inicializadas
Modifica:

*/
void interseccion1(ListaOrdenada *L1, ListaOrdenada *L2)
{

}


/**
Nombre: interseccion2
Par�metros: L1, L2
Efecto: Crea la lista L3, de manera que L3 tendr� los elementos que est�n tanto en L1 como en L2.
El algoritmo se mueve simult�neamente en ambas listas.
Requiere: Listas inicializadas
Modifica:

*/
void interseccion2(ListaOrdenada *L1, ListaOrdenada *L2)
{

}

