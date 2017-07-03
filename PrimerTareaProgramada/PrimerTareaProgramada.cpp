#include <iostream>
#include <cstdlib>
#include "stdafx.h"
#include "Diccionario.h"
#include "Grafo_Lista.h"
//#include "GrafoMatrizDeAdyacencia.h"
#include "ColaDePrioridad.h"
#include "Conjunto de Conjuntos.h"
#include "Dupletas.h"
#define maximo 100

typedef Grafo_Lista Grafo;
//typedef GrafoMatriz Grafo;

typedef Vertice VerticeGen;
//typedef vertice VerticeGen;

using namespace std;

int contador = 0;
int color;
int i;
ConjuntodeConjuntos VerticesColoreados;
ConjuntodeConjuntos VerticesAdyacentes;
Diccionario <VerticeGen*> diccionarioVerticesVisitados;
std::vector<VerticeGen*> SolucionActual;
std::vector<VerticeGen*> SolucionMejor;
std::vector<Par<VerticeGen*, int>> Colores;
Diccionario<VerticeGen*> d;
Diccionario<VerticeGen*> verticesRecorridos;
//Diccionario<Par<vertice,vertice>> aristas;
Grafo* grafo;
bool ciclo = false;
int costos[20];
VerticeGen* mapeo[20];

int costosF[20][20];
VerticeGen* maVert[20][20];
int adyacentes[20][20];
VerticeGen* mapa[20];

std::vector<VerticeGen*>::iterator it;
int menorCosto;
int costoActual;
int contadorV;
int costo;

std::vector<Dupletas<VerticeGen>> conjuntoAristas;
int menorPeso;

VerticeGen* Buscar(Grafo* g, string etiqueta);

int imax = std::numeric_limits<int>::max();

/**
Nombre: AveriguarCiclos
Parámetros: v(vértice)
Efecto: Retorna un booleano si el grafo tiene ciclos o no
Requiere: Árbol inicializado.
Modifica:

**/
bool AveriguarCiclos(VerticeGen* a)
{
	contador++;
	verticesRecorridos.agregar(a);
	VerticeGen* b = grafo->primerVerticeAdyacente(a);
	Par<VerticeGen*, VerticeGen*> arista(a, b);
	//aristas.Agregar(arista);
	while (b != grafo->verticeNulo)
	{
		if (verticesRecorridos.pertenece(b) == false)
		{
			AveriguarCiclos(b);
		}
		b = grafo->siguienteVerticeAdyacente(a, b);
		Par<VerticeGen*, VerticeGen*> arista(a, b);
		//aristas.Agregar(arista);
		if (verticesRecorridos.pertenece(b) == true)
		{
			contador = grafo->numVertices();
			ciclo = true;
			return true;
		}
	}
	return false;
}

/**
Nombre: ProfPrimero
Parámetros: v(vértice)
Efecto: Realiza un recorrido en profundidad primero a partir de un vértice dado
Requiere: Árbol inicializado, vértice válido
Modifica:

**/
void ProfPrimero(VerticeGen* v)
{
	ciclo = false;
	AveriguarCiclos(v);
	if (contador != grafo->numVertices())
	{
		VerticeGen* v2 = grafo->primerVertice();
		while (contador <= grafo->numVertices())
		{
			if (verticesRecorridos.pertenece(v2) == false)
			{
				AveriguarCiclos(v2);
			}
			v2 = grafo->siguienteVertice(v2);
		}
	}
}
/**
Nombre: Floyd
Parámetros:
Efecto: Encuentra el camino más corto entre todo par de vértices al resto  y lo retorna
Requiere: Árbol inicializado.
Modifica:

**/
void Floyd()
{
	int total = grafo->numVertices();
	VerticeGen* aux = grafo->primerVertice();
	for (int i = 0; i< total; i++)
	{
		mapa[i] = aux;
		aux = grafo->siguienteVertice(aux);
	}
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j< total; j++)
		{
			if (grafo->adyacentes(mapa[i], mapa[j]) == true)
			{
				adyacentes[i][j] = grafo->peso(mapa[i], mapa[j]);
			}
			else
			{
				adyacentes[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j< total; j++)
		{
			costosF[i][j] = adyacentes[i][j];
		}
	}
	for (int i = 0; i<total; i++)
	{
		costosF[i][i] = 0;
	}
	for (int k = 0; k<total; k++)
	{
		for (int i = 0; i<total; i++)
		{
			for (int j = 0; j<total; j++)
			{
				if (costosF[i][k] != -1 && costosF[k][j] != -1)
				{
					if (costosF[i][j] == -1)
					{
						costosF[i][j] = costosF[i][k] + costosF[k][j];
						maVert[i][j] = mapa[k];
					}
					else
					{
						if (costosF[i][k] + costosF[k][j] < costosF[i][j])
						{
							costosF[i][j] = costosF[i][k] + costosF[k][j];
							maVert[i][j] = mapa[k];
						}
					}
				}
			}
		}
	}
}
/**
Nombre: Dijkstra
Parámetros: v (vértice), d (Diccionario)
Efecto: Encuentra los caminos más cortos de un vértice al resto  y los retorna
Requiere: Árbol inicializado.
Modifica:

**/
void Dijkstra(VerticeGen* v, Diccionario<VerticeGen*> D)
{
	D.crear();
	contador = 0;
	for (VerticeGen* i = grafo->primerVertice(); i != grafo->verticeNulo; i = grafo->siguienteVertice(i))
	{
		mapeo[contador] = i;
		contador++;
	}
	D.agregar(v);
	for (int i = 0; i< grafo->numVertices(); i++)
	{
		if (grafo->etiqueta(mapeo[i]) != grafo->etiqueta(v))
		{
			if (grafo->adyacentes(v, mapeo[i]) == false)
			{
				costos[i] = imax;
			}
			else
			{
				costos[i] = grafo->peso(v, mapeo[i]);
			}
		}
	}
	for (int j = 0; j<grafo->numVertices(); j++)
	{
		if (D.pertenece(mapeo[j]) == false)
		{
			D.agregar(mapeo[j]);
			for (int h = 0; h<grafo->numVertices(); h++)
			{
				if (D.pertenece(mapeo[h]) == false)
				{
					if (grafo->peso(mapeo[j], mapeo[h]) + costos[j] < costos[h] && grafo->peso(mapeo[j], mapeo[h]) != -1) //hacer pesonulo en grafolista
					{
						costos[h] = grafo->peso(mapeo[j], mapeo[h]) + costos[j];
					}
				}
			}
		}
	}
}

/**
Nombre: Vendedor
Parámetros: g (grafo), v (vértice)
Efecto: Encuentra la solución al problema del vendedor mediante búsqueda exhaustiva pura
Requiere: Árbol inicializado.
Modifica:

**/
void Vendedor(Grafo* g, VerticeGen* v)
{
	diccionarioVerticesVisitados.agregar(v);
	VerticeGen* va = g->primerVerticeAdyacente(v);
	while (va != g->verticeNulo)
	{
		if (!diccionarioVerticesVisitados.pertenece(va))
		{
			//cout << "A" << endl;
			diccionarioVerticesVisitados.agregar(va);
			SolucionActual.push_back(va);
			costoActual += g->peso(v, va);
			if (diccionarioVerticesVisitados.numElem() == g->numVertices())
			{
				if (g->adyacentes(va, g->primerVertice()))
				{
					costo = costoActual + g->peso(va, g->primerVertice());
					if ((costo < menorCosto) || (menorCosto == -1))
					{
						SolucionMejor = SolucionActual;
						menorCosto = costo;
						contadorV++;
					}
				}
			}
			else
			{
				Vendedor(g, va);
			}
			//cout<< menorCosto <<endl;
			diccionarioVerticesVisitados.eliminar(va);
			//cout<< diccionarioVerticesVisitados.NumElem() <<endl;
			costoActual = costoActual - g->peso(v, va);
			SolucionActual.pop_back();
		}
		va = g->siguienteVerticeAdyacente(v, va);
		//cout << "caca" << endl;
		// cout << va << endl;
	}
}

/**
Nombre: Buscar
Parámetros: g grafo, etiqueta (string)
Efecto: Busca un vértice de acuerdo a su etiqueta, devuelve el vértice
Requiere: grafo inicializado.
Modifica:
**/
VerticeGen* Buscar(Grafo* g, string etiqueta)
{
	if (!g->vacio())
	{
		VerticeGen* encontrar = g->primerVertice();
		while (encontrar != g->verticeNulo)
		{
			if (etiqueta == g->etiqueta(encontrar))
			{
				return encontrar;
			}
			else
			{
				encontrar = g->siguienteVertice(encontrar);
			}
		}
		return g->verticeNulo;
	}
	return g->verticeNulo;
}

/**
Nombre: Iguales
Parámetros: g1 (grafo), g2 (grafo)
Efecto: Verifica si los dos grafos son iguales
Requiere: grafos inicializado.
Modifica:

**/
bool Iguales(Grafo* g1, Grafo* g2) 
{
	bool iguales = false;

	if (g1->numVertices() == g2->numVertices()) {
		VerticeGen* v1 = g1->primerVertice();
		VerticeGen* v2;
		iguales = true;
		while (v1 != 0 && iguales) {
			iguales = false;
			v2 = g2->primerVertice();
			while (v2 != 0 && !iguales) {
				if (g2->etiqueta(v2) == g1->etiqueta(v1) && (g2->numVerticesAdyacentes(v2) == g1->numVerticesAdyacentes(v1))) {
					iguales = true;
				}
				else {
					v2 = g2->siguienteVertice(v2);
				}
			}
			v1 = g1->siguienteVertice(v1);
		}
		if (iguales) {
			v1 = g1->primerVertice();
			v2 = g2->primerVertice();
			VerticeGen* ady1;
			VerticeGen* ady2;
			int numArst;
			while (v1 != 0 && iguales) {
				ady1 = g1->primerVerticeAdyacente(v1);
				ady2 = g2->primerVerticeAdyacente(v2);
				numArst = g1->numVerticesAdyacentes(v1);
				iguales = false;
				while (numArst > 0 && !iguales) {
					if (g1->etiqueta(ady1) == g2->etiqueta(ady2)) {
						if (g1->peso(v1, ady1) == g2->peso(v2, ady2)) {
							ady1 = g1->siguienteVerticeAdyacente(v1, ady1);
							ady2 = g2->primerVerticeAdyacente(v2);
							if (numArst == 1) {
								iguales = true;
							}
							numArst--;
						}
						else {
							numArst = 0;
						}
					}
					else {
						ady2 = g2->siguienteVerticeAdyacente(v2, ady2);
					}
				}
				v1 = g1->siguienteVertice(v1);
				v2 = g2->siguienteVertice(v2);
			}
		}
	}
	return iguales;
}

void copiarVertices(Grafo* g1, Vertice* v)
{
	if (v != 0) {
		copiarVertices(g1, g1->siguienteVertice(v));
		g1->agregarVertice(v->etiqueta);
	}
}

Grafo* Copiar(Grafo* g1) 
{
	VerticeGen* v1 = g1->primerVertice();
	VerticeGen* v2;
	Arista* a;
	Grafo* copiado = new Grafo();
	copiarVertices(copiado, v1);
	v2 = copiado->primerVertice();
	while (v1 != 0) {
		a = v1->aristas;
		while (a != 0) {
			VerticeGen* adyacente = copiado->primerVertice();
			while (a->vertice->etiqueta != adyacente->etiqueta) {
				adyacente = adyacente->sgt;
			}
			if (!(copiado->adyacentes(adyacente, v2))) {
				copiado->agregarArista(v2, adyacente, a->Peso);
			}
			a = a->sgt;
		}
		v1 = v1->sgt;
		v2 = v2->sgt;
	}

	return copiado;
}

void EliminarVerticeNoAislado(Grafo* g1, Vertice* v) 
{
	Arista* a = v->aristas;
	while (a != 0) {
		g1->eliminarArista(v, a->vertice);
		a = v->aristas;
	}
	g1->eliminarVertice(v);
}

int TotalPesos(Grafo* g1, Vertice* v)
{
	int pesos = 0;
	Arista* a = v->aristas;
	while (a != 0) {
		pesos += a->Peso;
		a = a->sgt;
	}
	return pesos;
}

int TotalizarPesosAristas(Grafo* g1) 
{
	VerticeGen* v = g1->primerVertice();
	int total = 0;
	while (v->etiqueta != "0") {
		total += TotalPesos(g1, v);
		v = v->sgt;
	}
	return total / 2;
}

//Colorear no sirve
/*void ColorearVertice(Grafo grafo, VerticeGen v)
{
	bool factible = true;
	VerticeGen va;
	for (color = 0; color < grafo->numVertices() - 1; color++)
	{
		factible = true;
		va = grafo->primerVerticeAdyacente(v);
		while (va != grafo->verticeNulo && factible == true)
		{
			if (VerticesAdyacentes.ConjuntoAlQuePertenece(va->etiqueta) == i)
			{
				factible = false;
			}
			va = grafo->siguienteVerticeAdyacente(v, va);
		}
		if (factible)
		{
			VerticesColoreados.AgregarElementoAConjunto(v, color);
			if (color == grafo->numVertices())
			{

			}
			else {
				ColorearVertice(grafo, va);
			}
		}
	}
}*/

/* diccionarioVerticesVisitados.Agregar(v);
vertice va = grafo->PrimerVerticeAdyacente(v);
while (va != grafo->verticeNulo)
{
if (!diccionarioVerticesVisitados.Pertenece(va))
{
//cout << "A" << endl;
diccionarioVerticesVisitados.Agregar(va);
SolucionActual.push_back(va);
costoActual += grafo->Peso(v,va);
if (i == grafo->NumVertices()-1)
{
if (grafo->Adyacentes(va, grafo->PrimerVertice()))
{
int costo = costoActual + grafo->Peso(va,grafo->PrimerVertice());
if((costo < menorCosto) || (menorCosto == -1))
{
SolucionMejor = SolucionActual;
menorCosto = costo;
contadorV++;
}
}
}
else
{
Vendedor(va,i+1);
}
//cout<< menorCosto <<endl;
diccionarioVerticesVisitados.Eliminar(va);
//cout<< diccionarioVerticesVisitados.NumElem() <<endl;
costoActual = costoActual - grafo->Peso(v,va);
SolucionActual.pop_back();
}
va = grafo->SiguienteVerticeAdyacente(v,va);
//cout << "caca" << endl;
// cout << va << endl;
}*/

void imprimirGrafo(Grafo* g)
{
	VerticeGen* v = g->primerVertice();
	VerticeGen* sig = v;	
	int numVert = g->numVertices();
	int n = 0;	
	cout << "	";
	while (v->etiqueta != g->verticeNulo->etiqueta)
	{
		cout << g->etiqueta(v) << "	";		
		v = g->siguienteVertice(v);
	}
	cout << endl;
	v = g->primerVertice();
	while (v->etiqueta != g->verticeNulo->etiqueta)
	{
		cout << g->etiqueta(v) << "	";
		sig = g->primerVertice();
		while (sig->etiqueta != g->verticeNulo->etiqueta)
		{
			if (g->adyacentes(v, sig))
			{
				cout << g->peso(v, sig) << "	";				
			}
			else
			{
				cout << "0	";
			}
			sig = g->siguienteVertice(sig);
		}
		cout << endl;
		v = g->siguienteVertice(v);
	}
}

void menu(Grafo* grafo)
{
	int salida = 0;

	string vertic;
	string etiq;
	VerticeGen* vert;
	VerticeGen* vert2;
	int peso;
	while (salida != -1)
	{
		cout << "                   Que desea utilizar" << endl;
		cout << "Operadores basicos: 1 = Agregar Vertice, 2 = Eliminar Vertice, 3 = Modificar Etiqueta,\n 4 = Etiqueta, 5 = Agregar Arista, 6 = Eliminar Arista, " << endl;
		cout << "7 = Modificar Peso, 8 = Peso, 9 = Adyacentes,\n 10 = Primer Vertice, 11 = SiguienteVertice, 12 = Primer Vertice Adyacente,\n 13 = Siguiente Vertice Adyacente" << endl;
		cout << "Algoritmos: 14 = Averiguar si el grafo tiene ciclos, 15 = Dijkstra, 16 = Floyd,\n 17 = Vendedor 18 = Imprimir grafo" << endl;
		cin >> salida;
		switch (salida)
		{
		case 1:
			cout << "Que etiqueta le quieres poner al vertice?" << endl;
			cin >> vertic;
			grafo->agregarVertice(vertic);
			break;
		case 2:
			cout << "Que vertice desea eliminar?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			grafo->eliminarVertice(vert);
			break;
		case 3:
			cout << "A cual vertice desea cambiarle su etiqueta?" << endl;
			cin >> vertic;
			cout << "Cual etiqueta desea ponerle?" << endl;
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			grafo->modificarEtiqueta(vert, etiq);
			break;
		case 4:
			cout << "De que vertice desea saber la etiqueta?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			grafo->etiqueta(vert);
			break;
		case 5:
			cout << "De que vertice a que vertice desea agregar una arista?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			cout << "Que peso desea ponerle?" << endl;
			cin >> peso;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->agregarArista(vert, vert2, peso);
			break;
		case 6:
			cout << "La arista de que vertice a que vertice desea eliminar?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->eliminarArista(vert, vert2);
			break;
		case 7:
			cout << "A que aristas le desea modificar el peso?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			cout << "Que peso desea ponerle?" << endl;
			cin >> peso;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->modificarPeso(vert, vert2, peso);
			break;
		case 8:
			cout << "De cual arista desea saber el peso?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->peso(vert, vert2);
			break;
		case 9:
			cout << "Que vertices desea averiguar si son adyacentes?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			if (grafo->adyacentes(vert, vert2) == true)
			{
				cout << "Los vertices " << vertic << ", " << etiq << " son adyacentes" << endl;
			}
			else
			{
				cout << "Los vertices " << vertic << ", " << etiq << " no son adyacentes" << endl;
			}
			break;
		case 10:
			cout << "El primer vertice es: " << grafo->etiqueta(grafo->primerVertice()) << endl;
			break;
		case 11:
			cout << "A partir de cual vertice desea averigurar el siguiente?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			cout << "El siguiente vertice a partir de: " << grafo->etiqueta(vert) << " es: " << grafo->etiqueta(grafo->siguienteVertice(vert)) << endl;
			break;
		case 12:
			cout << "De que vertice desea averiguar su primer vertice adyacente?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			cout << "El primer vertice adyacente de" << grafo->etiqueta(vert) << "es: " << grafo->etiqueta(grafo->primerVerticeAdyacente(vert)) << endl;
			break;
		case 13:
			cout << "Que vertice desea eliminar?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			cout << "Vertice adyacente a" << grafo->etiqueta(vert) << ": ";
			cin >> etiq;
			vert2 = Buscar(grafo, etiq);
			cout << "El siguiente vertice adyacente de " << grafo->etiqueta(vert) << " despues de: " << grafo->etiqueta(vert2) << " es: " << grafo->etiqueta(grafo->siguienteVerticeAdyacente(vert, vert2));
			break;
		case 14:
			verticesRecorridos.crear();
			cout << "A partir de cual vertice desea empezar la busqueda de un ciclo?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			ProfPrimero(vert);
			if (ciclo == true)
			{
				cout << "El grafo tiene un ciclo" << endl;
			}
			else
			{
				cout << "El grafo no tiene un ciclo" << endl;
			}

			break;
		case 15:
			cout << "Desde cual vertice desea saber el menor costo con respecto a todos los demas?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			Dijkstra(vert, d);
			for (int i = 0; i < grafo->numVertices(); i++)
			{
				if (mapeo[i] != vert)
				{
					cout << "El camino de menor costo de " << grafo->etiqueta(vert) << " hasta " << grafo->etiqueta(mapeo[i]) << " es: " << costos[i] << endl;
				}

			}

			break;
		case 16:
			Floyd();
			for (int i = 0; i<grafo->numVertices(); i++)
			{
				for (int j = 0; j<grafo->numVertices(); j++)
				{
					if (i != j)
					{
						cout << "El camino de menor costo de " << grafo->etiqueta(mapa[i]) << " hasta " << grafo->etiqueta(mapa[j]) << " es: " << costosF[i][j] << endl;
					}
				}
			}

			break;
		case 17:
			cout << "A partir de cual vertice desea empezar Vendedor?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			menorCosto = -1;
			costoActual = 0;
			contadorV = 0;
			SolucionActual.clear();
			SolucionMejor.clear();
			Vendedor(grafo, vert);
			cout << "La mejor solucion es: ";
			cout << grafo->etiqueta(vert) << " -> ";
			for (it = SolucionMejor.begin(); it < SolucionMejor.end(); it++)
			{
				cout << grafo->etiqueta(*it) << " -> ";
			}
			cout << grafo->etiqueta(vert) << endl;
			cout << "\n Esta tiene un costo de: " << menorCosto << endl;
			cout << "La cantidad total de soluciones factibles son " << contadorV << endl;


			break;
		case 18:
			cout << "Imprimimos el grafo como matriz de adyacencia" << endl;
			imprimirGrafo(grafo);
		default:
			cout << "Digito una opcion invalida" << endl;

		}
		cout << "Desea seguir utilizando el grafo?\n" << "1 = si, -1 = no" << endl;
		cin >> salida;
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

	VerticeGen* v4 = grafo->primerVertice(); //new Vertice("v1");
	VerticeGen* v3 = grafo->siguienteVertice(v4); //new Vertice("v2");
	VerticeGen* v2 = grafo->siguienteVertice(v3); //new Vertice("v3");
	VerticeGen* v1 = grafo->siguienteVertice(v2); //new Vertice("v4");

	cout << "Agregamos las aristas: v2,v4,5; v4,v3,7; v3,v1,2; v3,v2,1" << endl;
	grafo->agregarArista(v2, v4, 5);
	grafo->agregarArista(v4, v3, 7);
	grafo->agregarArista(v3, v1, 2);
	grafo->agregarArista(v3, v2, 1);

	cout << "Preguntamos por el numero de aristas de v3, lo cual es 3" << endl;
	cout << "El numero de aristas de v3 es: " << grafo->numVerticesAdyacentes(v3) << endl;

	cout << "Preguntamos por la etiqueta del primer vertice, deberia ser v4" << endl;
	cout << "La etiqueta del primer vertice es: " << grafo->primerVertice()->etiqueta << endl;

	menu(grafo);
	/*
	Grafo* grafo2 = Copiar(grafo);
	imprimirGrafo(grafo);
	cout << "-------------------------------------------------------------------" << endl;
	imprimirGrafo(grafo2);
	bool iguales = Iguales(grafo, grafo2);
	if (iguales) {
		cout << "Ambos grafos son iguales" << endl;
	}
	else {
		cout << "Los grafos no son iguales" << endl;
	}
	cout << "El total de pesos en el grafo es: " << TotalizarPesosAristas(grafo) << endl;
	cout << "Eliminamos v3, un vertice no aislado" << endl;
	EliminarVerticeNoAislado(grafo, v3);
	cout << "El total de pesos en el grafo es: " << TotalizarPesosAristas(grafo) << endl;
	//grafo->modificarEtiqueta("v7",v1);
	imprimirGrafo(grafo);
	cout << "-------------------------------------------------------------------" << endl;
	imprimirGrafo(grafo2);

	iguales = Iguales(grafo, grafo2);
	if (iguales) {
		cout << "Ambos grafos son iguales" << endl;
	}
	else {
		cout << "Los grafos no son iguales" << endl;
	}

	cout << "Vaciamos el grafo y preguntamos por el numero de vertices" << endl;
	grafo->vaciar();
	cout << "El numero de vertices es: " << grafo->numVertices() << endl;*/
	return 0;
}

