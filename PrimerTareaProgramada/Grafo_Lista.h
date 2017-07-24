#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H
#include <string>
#include <iostream>
using namespace std;

struct Arista;
struct Vertice;

//Estructura arista
struct Arista 
{
	int Peso;
	Vertice* vertice;
	Arista* sgt;

	Arista(Vertice* v, int p) : vertice(v), Peso(p), sgt(0) {};
};

//Estructura v�rtice
struct Vertice 
{
	string etiqueta;
	Vertice* sgt;
	Arista* aristas;

	Vertice(string x) : etiqueta(x), sgt(0), aristas(0) {};
};


class Grafo_Lista
{
public:

	Vertice* verticeNulo;

	/**
	Nombre: Grafo_Lista
	Par�metros:
	Efecto: Metodo constructor de la clase
	Requiere:
	Modifica:
	*/
	Grafo_Lista();

	/**
	Nombre: ~Grafo_Lista
	Par�metros:
	Efecto: Destruye el grafo G
	Requiere: Grafo inicializado
	Modifica: Grafo
	*/
	virtual ~Grafo_Lista();

	/**
	Nombre: vaciar
	Par�metros:
	Efecto: Vac�a el grafo G
	Requiere: Grafo inicializado
	Modifica: Grafo
	*/
	void vaciar();

	/**
	Nombre: vacio
	Par�metros:
	Efecto: Averigua si un grafo est� vac�o, devuelve el booleano correspondiente
	Requiere: Grafo inicializado
	Modifica:
	*/
	bool vacio();
	
	/**
	Nombre: agregarVertice
	Par�metros: string etiqueta
	Efecto: Agrega un vertice con la etiqueta "etiqueta" al grafo G
	Requiere: Grafo inicializado
	Modifica: Grafo
	*/
	void agregarVertice(string etiqueta);

	/**
	Nombre: eliminarVertice
	Par�metros:
	Efecto: Elimina el vertice v del Grafo G
	Requiere: Grafo inicializado y vertice v valido
	Modifica: Grafo
	*/
	void eliminarVertice(Vertice* v);

	/**
	Nombre: modificarEtiqueta
	Par�metros: vertice v, string e
	Efecto: Modifica la etiqueta del vertice v
	Requiere: Grafo inicializado y vertice valido
	Modifica: Grafo, vertice
	*/
	void modificarEtiqueta(Vertice* v, string e);

	/**
	Nombre: etiqueta
	Par�metros: vertice v
	Efecto: Devuelve la etiqueta del vertice v
	Requiere: Grafo inicializado y vertice v valido
	Modifica: 
	*/
	string etiqueta(Vertice* v);

	/**
	Nombre: agregarArista
	Par�metros: vertice v1, vertice v2, int p
	Efecto: Agrega la arista v1,v2 con el peso p en el grafo G
	Requiere: Grafo inicializado, vertice v1 y vertice v2 v�lidos
	Modifica: Grafo g
	*/
	void agregarArista(Vertice* v1, Vertice* v2, int p);

	/**
	Nombre: eliminarArista
	Par�metros: vertice v1, vertice v2
	Efecto: Elimina la arista v1, v2 del grafo G
	Requiere: Grafo inicializado y v�rtice v1 y v�rtice v2 v�lidos
	Modifica: Grafo
	*/
	void eliminarArista(Vertice* v1, Vertice* v2);

	/**
	Nombre: modificarPeso
	Par�metros: vertice v1, vertice v2, int p
	Efecto: Modifica el peso de la arista v1,v2 en el grafo G
	Requiere: Grafo inicializado, v�rtice v1 y v�rtice v2 v�lidos y arista existente entre ambos
	Modifica: Grafo y peso de la arista que va de v1 a v2
	*/
	void modificarPeso(Vertice* v1, Vertice* v2, int p);

	/**
	Nombre: peso
	Par�metros: v�rtice v1, v�rtice v2
	Efecto: Devuelve el peso de la arista v1,v2 en el grafo G
	Requiere: Grafo inicializado y v�rtice v1 y v�rtice v2 v�lidos y arista existente entre ambos
	Modifica:
	*/
	int peso(Vertice* v1, Vertice* v2);

	/**
	Nombre: adyacentes
	Par�metros: v�rtice v1 y v�rtice v2
	Efecto: Averigua si dos vertices son adyacentes y devuelve el booleano correspondiente
	Requiere: Grafo inicializado. v�rtice v1 y v�rtice v2 v�lidos
	Modifica:
	*/
	bool adyacentes(Vertice* v1, Vertice* v2);

	/**
	Nombre: primerVertice
	Par�metros:
	Efecto: Devuelve el primer vertice en el grafo G
	Requiere: Grafo inicializado
	Modifica:
	*/
	Vertice* primerVertice();

	/**
	Nombre: siguienteVertice
	Par�metros: v�rtice v
	Efecto: Devuelve el siguiente v�rtice de v en el grafo 
	Requiere: Grafo inicializado y v�rtice v valido
	Modifica:
	*/
	Vertice* siguienteVertice(Vertice* v);

	/**
	Nombre: primerVerticeAdyacente
	Par�metros: v�rtice v
	Efecto: Devuelve el primer vertice adyacente del v�rtice v en el grafo 
	Requiere: Grafo inicializado y v�rtice v valido
	Modifica:
	*/
	Vertice* primerVerticeAdyacente(Vertice* v);

	/**
	Nombre: siguienteVerticeAdyacente
	Par�metros: v�rtice v1, v�rtice v2
	Efecto: Devuelve el siguiente vertice adyacente de v2 en v1, en el grafo G
	Requiere: Grafo inicializado y v�rtices v1 y v2 v�lidos
	Modifica:
	*/
	Vertice* siguienteVerticeAdyacente(Vertice* v1, Vertice* v2); //

	/**
	Nombre: numVertices
	Par�metros:
	Efecto: Devuelve el numero de vertices del grafo
	Requiere: Grafo inicializado
	Modifica:
	*/
	int numVertices();

	/**
	Nombre: numVerticesAdyacentes
	Par�metros: v�rtice v
	Efecto: Devuelve el n�mero de v�rtices adyacentes del v�rtice v
	Requiere: Grafo inicializado, v�rtice v v�lido
	Modifica:
	*/
	int numVerticesAdyacentes(Vertice* v);
	
	/**
	Nombre: VerticeNulo
	Par�metros: 
	Efecto: Devuelve un v�rtice nulo
	Requiere: Grafo inicializado
	Modifica:
	*/
	Vertice* VerticeNulo();

private:
	Vertice* inicio;
};
#endif // GRAFO_LISTA_H

Grafo_Lista::Grafo_Lista() 
{
	inicio = new Vertice("0");
	verticeNulo = new Vertice("0");
}

Grafo_Lista::~Grafo_Lista() {
	Vertice* v1 = inicio;
	Vertice* v2 = 0;
	Arista* a1;
	Arista* a2;

	while (v1 != 0) 
	{
		a1 = v1->aristas;
		while (a1 != 0) 
		{
			a2 = a1->sgt;
			delete a1;
			a1 = a2;
		}
		v2 = v1->sgt;
		delete v1;
		v1 = v2;
	}
}

void Grafo_Lista::vaciar() 
{
	Vertice* v1 = inicio;
	Vertice* v2 = 0;
	Arista* a1;
	Arista* a2;

	while (v1->etiqueta != "0") 
	{
		a1 = v1->aristas;
		while (a1 != 0) 
		{
			a2 = a1->sgt;
			delete a1;
			a1 = a2;
		}
		v2 = v1->sgt;
		delete v1;
		v1 = v2;
	}
	inicio->etiqueta = "0";
}

bool Grafo_Lista::vacio() 
{
	bool vacia = false;
	if (inicio->etiqueta == "0") 
	{
		vacia = true;
	}
	return vacia;
}

void Grafo_Lista::agregarVertice(string e) 
{
	Vertice* p = inicio;
	Vertice* v = new Vertice(e);
	v->sgt = p;
	inicio = v;
}

void Grafo_Lista::eliminarVertice(Vertice* v) 
{
	Vertice* v1 = inicio;
	if (v == inicio) 
	{
		inicio = v1->sgt;
		delete v;
	}
	else 
	{
		bool encontrado = false;
		while (!encontrado) 
		{
			if (v1->sgt == v) 
			{
				v1->sgt = v->sgt;
				delete v;
				encontrado = true;
			}
			else
				v1 = v1->sgt;
		}
	}
}

void Grafo_Lista::modificarEtiqueta(Vertice* v, string e) 
{
	v->etiqueta = e;
}

string Grafo_Lista::etiqueta(Vertice* v)
{
	return v->etiqueta;
}

void Grafo_Lista::agregarArista(Vertice* v1, Vertice* v2, int p) 
{
	Arista* a1 = new Arista(v2, p);
	Arista* a2 = new Arista(v1, p);
	a1->sgt = v1->aristas;
	v1->aristas = a1;
	a2->sgt = v2->aristas;
	v2->aristas = a2;
}

void Grafo_Lista::eliminarArista(Vertice* v1, Vertice* v2) 
{
	bool eliminada1 = false;
	Arista* a1 = v1->aristas;
	while (!eliminada1 && a1 != NULL) 
	{
		if (a1->vertice == v2) 
		{
			if (a1 == v1->aristas) 
			{
				v1->aristas = a1->sgt;
				delete a1;
				eliminada1 = true;
			}
			else 
			{
				if (a1->sgt->vertice == v2) 
				{
					Arista* eliminada = a1->sgt;
					a1->sgt = a1->sgt->sgt;
					v1->aristas = a1;
					delete eliminada;
					eliminada1 = true;
				}
			}
		}
		else
			a1 = a1->sgt;
	}
}

void Grafo_Lista::modificarPeso(Vertice* v1, Vertice* v2, int p) 
{
	bool modificada = false;
	Arista* a1 = v1->aristas;
	while (!modificada) 
	{
		if (a1->vertice == v2) 
		{
			a1->Peso = p;
			modificada = true;
		}
		else
			a1 = a1->sgt;		
	}
	
	modificada = false;
	Arista* a2 = v2->aristas;
	while (!modificada) 
	{
		if (a2->vertice == v1) 
		{
			a2->Peso = p;
			modificada = true;
		}
		else
			a2 = a2->sgt;
	}
}

int Grafo_Lista::peso(Vertice* v1, Vertice* v2) 
{
	bool encontrada = false;
	int peso = -1;
	Arista* a = v1->aristas;
	while (!encontrada && a != NULL) 
	{
		if (a->vertice == v2) 
		{
			peso = a->Peso;
			encontrada = true;
		}
		else 
			a = a->sgt;
	}
	return peso;
}

bool Grafo_Lista::adyacentes(Vertice* v1, Vertice* v2) 
{ 
	bool encontrada = false;
	Arista* a = v1->aristas;
	while (a != 0 && !encontrada) 
	{
		if (a->vertice == v2) 
		{
			encontrada = true;
		}
		else
			a = a->sgt;
	}
	return encontrada;
}

Vertice* Grafo_Lista::primerVertice() 
{
	return inicio;
}

Vertice* Grafo_Lista::siguienteVertice(Vertice* v) 
{
	return v->sgt;
}

Vertice* Grafo_Lista::primerVerticeAdyacente(Vertice* v) 
{
	return v->aristas->vertice;
}

Vertice* Grafo_Lista::siguienteVerticeAdyacente(Vertice* v1, Vertice* v2) 
{
	Vertice* siguiente = verticeNulo;
	bool encontrada = false;
	Arista* a = v1->aristas;
	while (!encontrada && a != NULL) 
	{
		if (a->vertice == v2) 
		{
			encontrada = true;
			if (a->sgt != 0) 
				siguiente = a->sgt->vertice;			
		}
		else
			a = a->sgt;
	}
	return siguiente;
}

int Grafo_Lista::numVertices()
{
	Vertice* v = inicio->sgt;
	int cnt = 0;
	while (v != 0)
	{
		cnt++;
		v = v->sgt;
	}	
	return cnt;
}

int Grafo_Lista::numVerticesAdyacentes(Vertice* v) 
{
	Arista* a = v->aristas;
	int cnt = 0;
	while (a != 0) 
	{
		cnt++;
		a = a->sgt;
	}
	return cnt;
}

Vertice * Grafo_Lista::VerticeNulo()
{
	return verticeNulo;
}