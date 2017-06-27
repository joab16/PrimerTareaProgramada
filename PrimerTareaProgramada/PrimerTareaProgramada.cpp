#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "stdafx.h"

#include "Grafo_Lista.h"
#include "Diccionario.h"

typedef Grafo_Lista Grafo;
using namespace std;

void imprimirGrafo(Grafo* g) {
	Vrt v = g->primerVertice();
	Arista* a;
	while (v != 0) {
		cout << "Vertice: " << v->etiqueta << endl;
		a = v->aristas;
		while (a != 0) {
			cout << "Arista: " << a->vertice->etiqueta << " Peso: " << a->Peso << endl;
			a = a->sgt;
		}
		v = v->sgt;
	}
}

int main(int argc, char** argv) {
	cout << "" << endl;
	cout << "Creamos el grafo y vemos si esta vacio, lo cual es cierto" << endl;
	Grafo* grafo = new Grafo();
	if (grafo->vacio()) {
		cout << "El grafo esta vacio" << endl;
	}
	else {
		cout << "El grafo no esta vacio" << endl;
	}
	cout << "Agregamos los vertices v1,v2,v3,v4" << endl;
	grafo->agregarVertice("v1");
	grafo->agregarVertice("v2");
	grafo->agregarVertice("v3");
	grafo->agregarVertice("v4");
	cout << "Volvemos a preguntar si esta vacio, lo cual es falso ahora, y preguntamos el numero de vertices en el grafo" << endl;
	if (grafo->vacio()) {
		cout << "El grafo esta vacio" << endl;
	}
	else {
		cout << "El grafo no esta vacio" << endl;
	}
	cout << "El numero de vertices es: " << grafo->numVertices() << endl;

	Vrt v4 = grafo->primerVertice(); //new Vertice("v1");
	Vrt v3 = grafo->siguienteVertice(v4); //new Vertice("v2");
	Vrt v2 = grafo->siguienteVertice(v3); //new Vertice("v3");
	Vrt v1 = grafo->siguienteVertice(v2); //new Vertice("v4");

	cout << "Agregamos las aristas: v2,v4,5; v4,v3,7; v3,v1,2; v3,v2,1" << endl;
	grafo->agregarArista(v1, v4, 5);
	grafo->agregarArista(v4, v3, 7);
	grafo->agregarArista(v3, v1, 2);
	grafo->agregarArista(v3, v2, 1);

	cout << "Preguntamos por el numero de aristas de v3, lo cual es 3" << endl;
	cout << "El numero de aristas de v3 es: " << grafo->numVerticesAdyacentes(v3) << endl;

	cout << "Preguntamos por la etiqueta del primer vertice, deberia ser v4" << endl;
	cout << "La etiqueta del primer vertice es: " << grafo->primerVertice()->etiqueta << endl;

	Grafo* grafo2 = grafo->copiar();
	imprimirGrafo(grafo);
	cout << "-------------------------------------------------------------------" << endl;
	imprimirGrafo(grafo2);
	bool iguales = grafo->iguales(grafo2);
	if (iguales) {
		cout << "Ambos grafos son iguales" << endl;
	}
	else {
		cout << "Los grafos no son iguales" << endl;
	}
	cout << "El total de pesos en el grafo es: " << grafo->totalizarPesosAristas() << endl;
	cout << "Eliminamos v3, un vertice no aislado" << endl;
	grafo->eliminarVrtNoAislado(v3);
	cout << "El total de pesos en el grafo es: " << grafo->totalizarPesosAristas() << endl;
	//grafo->modificarEtiqueta("v7",v1);
	imprimirGrafo(grafo);
	cout << "-------------------------------------------------------------------" << endl;
	imprimirGrafo(grafo2);

	iguales = grafo->iguales(grafo2);
	if (iguales) {
		cout << "Ambos grafos son iguales" << endl;
	}
	else {
		cout << "Los grafos no son iguales" << endl;
	}

	cout << "Vaciamos el grafo y preguntamos por el numero de vertices" << endl;
	grafo->vaciar();
	cout << "El numero de vertices es: " << grafo->numVertices() << endl;
	return 0;
}

