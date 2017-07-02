#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H
#include <string>
#include <iostream>
using namespace std;

struct Arista;
struct Vertice;

struct Arista {
	int Peso;
	Vertice* vertice;
	Arista* sgt;

	Arista(Vertice* v, int p) : vertice(v), Peso(p), sgt(0) {
	};
};

struct Vertice {
	string etiqueta;
	Vertice* sgt;
	Arista* aristas;

	Vertice(string x) : etiqueta(x), sgt(0), aristas(0) {
	};
};


class Grafo_Lista
{
public:

	Vertice* verticeNulo;

	//EFE: Crea el grafo G
	//REQ:
	//MOD:
	Grafo_Lista();

	//EFE: Destruye el grafo G
	//REQ: G inicializado
	//MOD:
	virtual ~Grafo_Lista();

	//EFE: Vacia el grafo G
	//REQ: G inicializado
	//MOD: G
	void vaciar();

	//EFE: Devuelve true si el grafo G esta vacio, de lo contrario devuelve false
	//REQ: G inicializado
	//MOD:
	bool vacio();

	//EFE: Agrega un vertice con la etiqueta "etiqueta" al grafo G
	//REQ: G inicializado
	//MOD: G
	void agregarVertice(string etiqueta);

	//EFE: Elimina el vertice v del Grafo G
	//REQ: G inicializado y v valido
	//MOD: G
	void eliminarVertice(Vertice* v);

	//EFE: Modifica la etiqueta del vertice v en G
	//REQ: G inicializado y v valido
	//MOD: G
	void modificarEtiqueta(Vertice* v, string e);

	//EFE: Devuelve la etiqueta del vertice v en G
	//REQ: G inicializado y v valido
	//MOD:
	string etiqueta(Vertice* v);

	//EFE: Agrega la arista v1,v2 con el peso p en el grafo G
	//REQ: G inicializado, y v1 y v2 incializados
	//MOD: G
	void agregarArista(Vertice* v1, Vertice* v2, int p);

	//EFE: Elimina la arista v1,v2 del grafo G
	//REQ: G incializada y la arista v1,v2 valida
	//MOD: G
	void eliminarArista(Vertice* v1, Vertice* v2);

	//EFE: Modifica el peso de la arista v1,v2 en el grafo G
	//REQ: G inicializado y v1 y v2 validos
	//MOD: G
	void modificarPeso(Vertice* v1, Vertice* v2, int p);

	//EFE: Devuelve el peso de la arista v1,v2 en el grafo G
	//REQ: G inicializado y la arista v1,v2 valida
	//MOD:
	int peso(Vertice* v1, Vertice* v2);

	//EFE: Devuelve verdadero si v1 y v2 son adyacentes, de lo contrario devuelve falso
	//REQ: G inicializado y v1 y v2 inicializados
	//MOD:
	bool adyacentes(Vertice* v1, Vertice* v2);

	//EFE: Devuelve el primer vertice en el grafo G
	//REQ: G inicializado
	//MOD:
	Vertice* primerVertice();

	//EFE: Devuelve el siguiente vertice de v en el grafo G
	//REQ: G inicializado y v valido
	//MOD:
	Vertice* siguienteVertice(Vertice* v);

	//EFE: Devuelve el primer vertice adyacente de v en el grafo G
	//REQ: G inicializado y v valido
	//MOD:
	Vertice* primerVerticeAdyacente(Vertice* v);

	//EFE: Devuelve el siguiente vertice adyacente de v2 en v1, en el grafo G
	//REQ: G inicializado y v1 y v2 validos
	//MOD:
	Vertice* siguienteVerticeAdyacente(Vertice* v1, Vertice* v2); //

												   //EFE: Devuelve el numero de vertices en G
												   //REQ: G inicializado
												   //MOD:
	int numVertices();

	//EFE: Devuelve el numero de vertices adyacente del vertice v en G
	//REQ: G inicializado y v valido
	//MOD:
	int numVerticesAdyacentes(Vertice* v);

	//EFE: Averigua si el grafo tiene ciclos, devuelve verdadero si es cierto, de lo contrario devuelve falso
	//REQ: G inicializado
	//MOD:
	//bool recorridoProfundidadPrimero();

	//EFE: Encuentra el camino mas corto desde v hacia los demas vertices del grafo G
	//REQ: G inicializado y v valido
	//MOD:
	//void algoritmoDijkstra(Vertice v);

	//EFE: Encuentra el camino mas corto entre todo par de vertices en G
	//REQ: G inicializdo
	//MOD:
	//void algortimoFloyd();

	//EFE: Devuelve verdadero si G y G2 son iguales, de lo contrario devuelve falso;
	//REQ: G y G2 inicializados
	//MOD:
	//bool iguales(Grafo_Lista* G2);

	//EFE: Copia el grafo G
	//REQ: G inicializado
	//MOD:
	//Grafo_Lista* copiar();

	//EFE: Elimina v (un vertice no aislado) de G
	//REQ: G inicializado y v valido
	//MOD: G
	//void eliminarVerticeNoAislado(Vertice v);

	//EFE: Devuelve el peso total de todas las aristas del grafo
	//REQ: G inicializado
	//MOD:
	//int totalizarPesosAristas();

	//EFE: Muestra el grafo G
	//REQ: G inicializado
	//MOD:
	//void mostrar();

	//EFE: Resuelve el problema de coloreo de grafos en G, usando busqueda eshaustiva pura
	//REQ: G inicializado
	//MOD:
	//void coloreoDeGrafos();

	//EFE: Resuelve el problema del vendedor usando busqueda exhaustiva pura
	//REQ:
	//MOD:
	//void circuitoHamiltonMenorCosto();

protected:
	//EFE: Metodo Complementario a copiar(), copia los vertices del grafo
	//REQ:
	//MOD:
	//void copiarVertices(Vertice v);

	//EFE: Metodo Complementario a totalizarPesosAristas(), devuelve el total de pesos
	// de las aristas del vertice v en el grafo G
	//REQ:
	//MOD:
	//int totalPesos(Vertice v);

private:
	Vertice* inicio;
};
#endif // GRAFO_LISTA_H

Grafo_Lista::Grafo_Lista() {//LISTO
	inicio = new Vertice(0);
	verticeNulo = new Vertice(0);
}

Grafo_Lista::~Grafo_Lista() {
	Vertice* v1 = inicio;
	Vertice* v2 = 0;
	Arista* a1;
	Arista* a2;

	while (v1 != 0) {
		a1 = v1->aristas;
		while (a1 != 0) {
			a2 = a1->sgt;
			delete a1;
			a1 = a2;
		}
		v2 = v1->sgt;
		delete v1;
		v1 = v2;
	}
}

void Grafo_Lista::vaciar() {
	Vertice* v1 = inicio;
	Vertice* v2 = 0;
	Arista* a1;
	Arista* a2;

	while (v1 != 0) {
		a1 = v1->aristas;
		while (a1 != 0) {
			a2 = a1->sgt;
			delete a1;
			a1 = a2;
		}
		v2 = v1->sgt;
		delete v1;
		v1 = v2;
	}
	inicio = 0;
}

bool Grafo_Lista::vacio() {//LISTO
	bool vacia = false;
	if (inicio == 0) {
		vacia = true;
	}
	return vacia;
}

void Grafo_Lista::agregarVertice(string e) {//LISTO
	Vertice* p = inicio;
	Vertice* v = new Vertice(e);
	v->sgt = p;
	inicio = v;
}

void Grafo_Lista::eliminarVertice(Vertice* v) {//LISTO
	Vertice* v1 = inicio;
	if (v == inicio) {
		inicio = v1->sgt;
		delete v;
	}
	else {
		bool encontrado = false;
		while (!encontrado) {
			if (v1->sgt == v) {
				v1->sgt = v->sgt;
				delete v;
				encontrado = true;
			}
			else {
				v1 = v1->sgt;
			}
		}
	}
}

void Grafo_Lista::modificarEtiqueta(Vertice* v, string e) {//LISTO
	v->etiqueta = e;
}

string Grafo_Lista::etiqueta(Vertice* v) {//LISTO
	return v->etiqueta;
}

void Grafo_Lista::agregarArista(Vertice* v1, Vertice* v2, int p) {//LISTO
	Arista* a1 = new Arista(v2, p);
	Arista* a2 = new Arista(v1, p);
	a1->sgt = v1->aristas;
	v1->aristas = a1;
	a2->sgt = v2->aristas;
	v2->aristas = a2;
}

void Grafo_Lista::eliminarArista(Vertice* v1, Vertice* v2) {//LISTO
	bool eliminada1 = false;
	Arista* a1 = v1->aristas;
	while (!eliminada1) {
		if (a1->vertice == v2) {
			if (a1 == v1->aristas) {
				v1->aristas = a1->sgt;
				delete a1;
				eliminada1 = true;
			}
			else {
				if (a1->sgt->vertice == v2) {
					Arista* eliminada = a1->sgt;
					a1->sgt = a1->sgt->sgt;
					v1->aristas = a1;
					delete eliminada;
					eliminada1 = true;
				}
			}
		}
		else {
			a1 = a1->sgt;
		}
	}
	bool eliminada2 = false;
	Arista* a2 = v2->aristas;
	while (!eliminada2) {
		if (a2->vertice == v1) {
			if (a2 == v2->aristas) {
				v2->aristas = a2->sgt;
				delete a2;
				eliminada2 = true;
			}
			else {
				if (a2->sgt->vertice == v1) {
					Arista* eliminada = a2->sgt;
					a2->sgt = a2->sgt->sgt;
					v2->aristas = a2;
					delete eliminada;
					eliminada2 = true;
				}
			}
		}
		else {
			a2 = a2->sgt;
		}
	}
}

void Grafo_Lista::modificarPeso(Vertice* v1, Vertice* v2, int p) {//LISTO
	bool modificada1 = false;
	Arista* a1 = v1->aristas;
	while (!modificada1) {
		if (a1->vertice == v2) {
			a1->Peso = p;
			modificada1 = true;
		}
		else {
			a1 = a1->sgt;
		}
	}
	bool modificada2 = false;
	Arista* a2 = v2->aristas;
	while (!modificada2) {
		if (a2->vertice == v1) {
			a2->Peso = p;
			modificada2 = true;
		}
		else {
			a2 = a2->sgt;
		}
	}
}

int Grafo_Lista::peso(Vertice* v1, Vertice* v2) {//LISTO
	bool encontrada = false;
	int peso;
	Arista* a = v1->aristas;
	while (!encontrada) {
		if (a->vertice == v2) {
			peso = a->Peso;
			encontrada = true;
		}
		else {
			a = a->sgt;
		}
	}
	return peso;
}

bool Grafo_Lista::adyacentes(Vertice* v1, Vertice* v2) { //LISTO
	bool encontrada = false;
	Arista* a = v1->aristas;
	while (a != 0 && !encontrada) {
		if (a->vertice == v2) {
			encontrada = true;
		}
		else {
			a = a->sgt;
		}
	}
	return encontrada;
}

Vertice* Grafo_Lista::primerVertice() {//LISTO
	return inicio;
}

Vertice* Grafo_Lista::siguienteVertice(Vertice* v) {//LISTO
	return v->sgt;
}

Vertice* Grafo_Lista::primerVerticeAdyacente(Vertice* v) {//LISTO
	return v->aristas->vertice;
}

Vertice* Grafo_Lista::siguienteVerticeAdyacente(Vertice* v1, Vertice* v2) {//LISTO
	Vertice* siguiente = 0;
	bool encontrada = false;
	Arista* a = v1->aristas;
	while (!encontrada) {
		if (a->vertice == v2) {
			encontrada = true;
			if (a->sgt != 0) {
				siguiente = a->sgt->vertice;
			}
		}
		else {
			a = a->sgt;
		}
	}
	return siguiente;
}

int Grafo_Lista::numVertices() {//LISTO
	Vertice* v = inicio;
	int cnt = 0;
	while (v != 0) {
		cnt++;
		v = v->sgt;
	}
	const int cantidad = cnt;
	return cantidad;
}

int Grafo_Lista::numVerticesAdyacentes(Vertice* v) {//LISTO
	Arista* a = v->aristas;
	int cnt = 0;
	while (a != 0) {
		cnt++;
		a = a->sgt;
	}
	return cnt;
}

/*bool Grafo_Lista::recorridoProfundidadPrimero() {
}

bool Grafo_Lista::iguales(Grafo_Lista* g2) {//LISTO
	bool iguales = false;

	if (this->numVertices() == g2->numVertices()) {
		Vertice v1 = this->primerVertice();
		Vertice v2;
		iguales = true;
		while (v1 != 0 && iguales) {
			iguales = false;
			v2 = g2->primerVertice();
			while (v2 != 0 && !iguales) {
				if (g2->etiqueta(v2) == this->etiqueta(v1) && (g2->numVerticesAdyacentes(v2) == this->numVerticesAdyacentes(v1))) {
					iguales = true;
				}
				else {
					v2 = g2->siguienteVertice(v2);
				}
			}
			v1 = this->siguienteVertice(v1);
		}
		if (iguales) {
			v1 = this->primerVertice();
			v2 = g2->primerVertice();
			Vertice ady1;
			Vertice ady2;
			int numArst;
			while (v1 != 0 && iguales) {
				ady1 = this->primerVerticeAdyacente(v1);
				ady2 = g2->primerVerticeAdyacente(v2);
				numArst = this->numVerticesAdyacentes(v1);
				iguales = false;
				while (numArst > 0 && !iguales) {
					if (this->etiqueta(ady1) == g2->etiqueta(ady2)) {
						if (this->peso(v1, ady1) == g2->peso(v2, ady2)) {
							ady1 = this->siguienteVerticeAdyacente(v1, ady1);
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
				v1 = this->siguienteVertice(v1);
				v2 = g2->siguienteVertice(v2);
			}
		}
	}
	return iguales;
}

Grafo_Lista* Grafo_Lista::copiar() {//LISTO
	Vertice v1 = inicio;
	Vertice v2;
	Arista* a;
	Grafo_Lista* copiado = new Grafo_Lista();
	copiado->copiarVertices(v1);
	v2 = copiado->primerVertice();
	while (v1 != 0) {
		a = v1->aristas;
		while (a != 0) {
			Vertice adyacente = copiado->primerVertice();
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

void Grafo_Lista::copiarVertices(Vertice v) {//LISTO
	if (v != 0) {
		this->copiarVertices(this->siguienteVertice(v));
		this->agregarVertice(v->etiqueta);
	}
}

void Grafo_Lista::eliminarVerticeNoAislado(Vertice v) {//LISTO
	Arista* a = v->aristas;
	while (a != 0) {
		this->eliminarArista(v, a->vertice);
		a = v->aristas;
	}
	this->eliminarVertice(v);
}

int Grafo_Lista::totalizarPesosAristas() {
	Vertice v = inicio;
	int total = 0;
	while (v != 0) {
		total += this->totalPesos(v);
		v = v->sgt;
	}
	return total / 2;
}

int Grafo_Lista::totalPesos(Vertice v) {
	int pesos = 0;
	Arista* a = v->aristas;
	while (a != 0) {
		pesos += a->Peso;
		a = a->sgt;
	}
	return pesos;
}

void Grafo_Lista::mostrar() {
}

void Grafo_Lista::coloreoDeGrafos() {
}

void Grafo_Lista::circuitoHamiltonMenorCosto() {
}

void Grafo_Lista::algoritmoDijkstra(Vertice* v) {
	Vertice* v2;
	int numVertice = (this->numVertices() - 1);
	string vertices[numVertice];
	Vertice camino[numVertice];
	int pesos[numVertice];
	Diccionario* recorridos = new Diccionario();
	v2 = this->primerVertice();
	int inicializar = 0;
	while (inicializar < numVertice) { //Inicializacion de Estructuras Auxiliares
		if (v2 != v) {
			vertices[inicializar] = this->etiqueta(v2);
			camino[inicializar] = 0;
			pesos[inicializar] = this->totalizarPesosAristas();
			inicializar++;
		}
		v2 = this->siguienteVertice(v2);
	}
	int numArst = 0;
	while (recorridos->numElem() <= (numVertice + 1)) {
		recorridos->agregar(v);
		numArst = this->numVerticesAdyacentes(v);
		v2 = this->primerVerticeAdyacente(v);
		for (int i = 0; i < numArst; i++) {
			if (recorridos->pertenece(v2)) {
				v2 = this->siguienteVerticeAdyacente(v, v2);
			}
			else {
				bool encontrado;
			}
		}
	}
}*/