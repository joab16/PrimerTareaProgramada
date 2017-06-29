#ifndef DICCIONARIO_H
#define DICCIONARIO_H
using namespace std;
#include"Grafo_Lista.h"

typedef Vrt elemento;

struct Nodo {
	elemento elm;
	Nodo* sgt;

	Nodo(elemento x) : elm(x), sgt(0) {
	};
};

class Diccionario
{
public:

public:
	//EFE: Inicializa el diccionario D
	//REQ: 
	//MOD: 
	Diccionario();
	//EFE: Destruye el diccionario D
	//REQ: D inicializado
	//MOD: 
	virtual ~Diccionario();
	//EFE: Elimina los elementos de D
	//REQ: D inicializado
	//MOD: D
	void vaciar();
	//EFE: Devuelve verdadero cuando D esta vacio, de lo contrario devuelve falso
	//REQ: D inicializado
	//MOD: 
	bool vacio();
	//EFE: Agrega el elemento e al diccionario D
	//REQ: D inicializado
	//MOD: D
	void agregar(elemento e);
	//EFE: Elimina el elemento e del diccionario D
	//REQ: D inicializado
	//MOD: D
	void eliminar(elemento e);
	//EFE: Devuelve verdadero si e pertenece a D
	//REQ: D inicializado
	//MOD: 
	bool pertenece(elemento e);
	//EFE: Devuelve el numero de elementos de D
	//REQ: D inicializado
	//MOD: 
	int numElem();
private:
	Nodo* inicio;
};
#endif // DICCIONARIO_H
Diccionario::Diccionario() {
	inicio = 0;
}

Diccionario::~Diccionario() {
	Nodo* p = inicio;
	Nodo* q = 0;
	while (p != 0) {
		q = p->sgt;
		delete p;
		p = q;
	}
}

void Diccionario::vaciar() {
	Nodo* p = inicio;
	Nodo* q = 0;
	while (p != 0) {
		q = p->sgt;
		delete p;
		p = q;
	}
	inicio = 0;
}

bool Diccionario::vacio() {
	bool vacia = false;
	if (inicio == 0) {
		vacia = true;
	}
	return vacia;
}

void Diccionario::agregar(elemento e) {
	Nodo* n = new Nodo(e);
	n->sgt = inicio;
	inicio = n;
}

void Diccionario::eliminar(elemento e) {
	Nodo* d = inicio;
	bool eliminado = false;
	if (d->elm == e && d == inicio) {
		inicio = d->sgt;
		delete d;
	}
	else {
		while (d != 0 && !eliminado) {
			if (d->sgt->elm == e) {
				Nodo* eliminado = d->sgt;
				d->sgt = d->sgt->sgt;
				delete eliminado;
			}
			else {
				d = d->sgt;
			}
		}
	}
}

bool Diccionario::pertenece(elemento e) {
	Nodo* d = inicio;
	bool encontrado = false;
	while (d != 0 && !encontrado) {
		if (d->elm == e) {
			encontrado = true;
		}
		else {
			d = d->sgt;
		}
	}
	return encontrado;
}

int Diccionario::numElem() {
	Nodo* d = inicio;
	int elementos = 0;
	while (d != 0) {
		elementos++;
		d = d->sgt;
	}
}