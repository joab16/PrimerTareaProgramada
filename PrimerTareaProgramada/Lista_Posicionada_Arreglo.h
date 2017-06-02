#ifndef LISTA_POSICIONADA_ARREGLO_H
#define LISTA_POSICIONADA_ARREGLO_H

#include <array>
#include <iostream>
#include <stdlib.h>

using namespace std;
typedef int posA;
typedef int elemento;

class Lista_Posicionada_Arreglo
{
    public:
		//EFE: 
		//REQ: 
		//MOD: 

		Lista_Posicionada_Arreglo();

		virtual ~Lista_Posicionada_Arreglo();

		//EFE: Destruye la Lista L
		//REQ: L inicializada
		//MOD:
		void destruir();

		//EFE: Vacia la Lista L
		//REQ: L inicializada
		//MOD: L
		void vaciar();

		//EFE: Devuelve True cuando la Lista L esta vacia, de lo contrario devuelve falso
		//REQ: L inicializada
		//MOD:
		bool vacia();

		//EFE: Inserta el elemento e a la posicion p de la lista L
		//REQ: L inicializada y p valida
		//MOD: L
		void insertar(elemento e, posA p);

		//EFE: Agrega el elemento e al final de la Lista L
		//REQ: L inicializada
		//MOD: L
		void agregarAlFinal(elemento e);

		//EFE: Borra el elemento de la posicion p de la Lista L
		//REQ: L inicializada y p valida
		//MOD: L
		void borrar(posA p);

		//EFE: Devuelve el elemento de la posicion p en la lIsta L
		//REQ: L inicializada y p valida
		//MOD:
		elemento recuperar(posA p);

		//EFE: Modifica el elemento de la posicion p por el elemento e en la Lista L
		//REQ: L inicializada y p valida
		//MOD: L
		void modificarElemento(elemento e, posA p);

		//EFE: Intercambia los elementos de las posiciones p1 y p2 de la Lista L
		//REQ: L inicializada y p1 p2 validos
		//MOD: L
		void intercambiar(posA p1, posA p2);

		//EFE: Devuelve la primer posicion de la Lista L
		//REQ: L inicializada
		//MOD:
		posA primera();

		//EFE: Devuelve la ultima posicion de la Lista L
		//REQ: L inicializada
		//MOD:
		posA ultima();

		//EFE: Devuelve la posicion siguiente a la posicion p de la Lista L
		//REQ: L inicializada y p valida
		//MOD:
		posA siguiente(posA p);

		//EFE: Devuelve la posicion anterior a la posicion p de la Lista L
		//REQ: L inicializada y p valida
		//MOD:
		posA anterior(posA p);

		//EFE: Devuelve el numero de elementos en la lista L
		//REQ: L inicializada
		//MOD:
		int numElem();

		//EFE: Lista los elementos que contiene la Lista L
		//REQ: L inicializada
		//MOD:
		void listar();

		//EFE: Devuelve true si L es simetrica, de lo contrario devuelve false
		//REQ: L inicializada
		//MOD:
		bool simetrica();

		//EFE: Invierte los elementos de la Lista L
		//REQ: L inicializada
		//MOD: L
		void invertir();

		//EFE: Busca el elemento e en la Lista L
		//REQ: L inicializada
		//MOD:
		bool buscar(elemento e);

		//EFE: Elimina los elementos repetidos en L
		//REQ: L inicializada
		//MOD: L
		void elimElemRep();

		//EFE: Si L1 es sublista de L devuelve true, de lo contrario devuelve falso
		//REQ: L y L1 inicializadas
		//MOD:
		bool subLista(Lista_Posicionada_Arreglo* L1);

		//EFE: Devuelve true si L y L1 son iguales, de lo contrario devuelve falso
		//REQ: L y L1 inicializadas
		//MOD:
		bool iguales(Lista_Posicionada_Arreglo* L1);

		//EFE: Ordena L con Burbuja Original
		//REQ: L inicializadas
		//MOD: L
		void burbujaOriginal();

		//EFE: Ordena L con Burbuja Bidireccional
		//REQ: L inicializada
		//MOD: L
		void burbujaBiDir();

		//EFE: Ordena L con Seleccion de forma iterativa
		//REQ: L
		//MOD: L
		void selectIter();

		//EFE: Ordena L con Seleccion de forma recursiva
		//REQ: L inicializada
		//MOD: L
		void selectRec();

		//EFE: Ordena L con Seleccion de forma recursiva pero con una Pila
		//REQ: L inicializada
		//MOD: L
		void selecRecPila();

		//EFE: Ordena L con Insercion
		//REQ: L inicializada
		//MOD: L
		void insercion();

		//EFE: Ordena L con Quick Sort de Aho
		//REQ: L incializada
		//MOD: L
		void quickSortAho();

		//EFE: Ordena L con Quick Sort
		//REQ: L inicializada
		//MOD: L
		void quickSort();

		//EFE: Ordena L con Merge Sort, devuelve la Lista ordenada
		//REQ: L incializada y el numero de elementos de L sea mayor a 1
		//MOD: L
		Lista_Posicionada_Arreglo* mergeSort();

		//EFE: Une la Lista L con L1
		//REQ: L y L1 inicializada
		//MOD: L
		void Union(Lista_Posicionada_Arreglo* L1);

		//EFE: Devueleve una Lista con la interseccion de L1 y L
		//REQ: L y L1 inicializadas, ordenadas y sin elementos repetidos
		//MOD:
		Lista_Posicionada_Arreglo* interseccionOrd(Lista_Posicionada_Arreglo* L1);

		//EFE: Devuelve una Lista con la interseccion de L1 y L
		//REQ: L1 y L inicializadas y sin elementos repetidos
		//MOD:
		Lista_Posicionada_Arreglo* interseccion(Lista_Posicionada_Arreglo* L1);

		//EFE: Elimina de la Lista L la interseccion con L1
		//REQ: L y L1 inicializadas y ordenadas
		//MOD: L
		void eliminarIntrOrd(Lista_Posicionada_Arreglo* L1);

		//EFE: Elimina de la Lista L la interseccion con L1
		//REQ: L y L1 inicializadas
		//MOD: L
		void eliminarIntr(Lista_Posicionada_Arreglo* L1);

protected:

	//EFE: Metodo Privado, complementario al metodo mergeSort de la Lista
	//REQ:
	//MOD:
	Lista_Posicionada_Arreglo* merge(Lista_Posicionada_Arreglo* L1, Lista_Posicionada_Arreglo* L2);

	//EFE: Metodo Privado, complementario al metodo selectRec de la Lista
	//REQ:
	//MOD:
	void selectRecursivo(posA primera);

private:
	elemento Lista[30];
	int numElementos;
};

#endif // LISTA_POSICIONADA_ARREGLO_H

Lista_Posicionada_Arreglo::Lista_Posicionada_Arreglo() {
	numElementos = 0;
}

Lista_Posicionada_Arreglo::~Lista_Posicionada_Arreglo() {
}

void Lista_Posicionada_Arreglo::destruir() {
}

void Lista_Posicionada_Arreglo::vaciar() {
	numElementos = 0;
}

bool Lista_Posicionada_Arreglo::vacia() {
	bool vacia = false;
	if (numElementos == 0) {
		vacia = true;
	}
	return vacia;
}

void Lista_Posicionada_Arreglo::insertar(elemento e, posA p) {
	if (numElementos - 1 >= p) {
		for (int i = (numElementos - 1); i >= p; i--) {
			Lista[i + 1] = Lista[i];
		}
	}
	Lista[p] = e;
	numElementos++;

}

void Lista_Posicionada_Arreglo::agregarAlFinal(elemento e) {
	Lista[numElementos] = e;
	numElementos++;
}

void Lista_Posicionada_Arreglo::borrar(posA p) {
	for (int i = p; i < numElementos; i++) {
		Lista[i] = Lista[i + 1];
	}
	numElementos--;
}

elemento Lista_Posicionada_Arreglo::recuperar(posA p) {
	return Lista[p];
}

void Lista_Posicionada_Arreglo::modificarElemento(elemento e, posA p) {
	Lista[p] = e;
}

void Lista_Posicionada_Arreglo::intercambiar(posA p1, posA p2) {
	elemento aux = Lista[p1];
	Lista[p1] = Lista[p2];
	Lista[p2] = aux;
}

posA Lista_Posicionada_Arreglo::primera() {
	return 0;
}

posA Lista_Posicionada_Arreglo::ultima() {
	return (numElementos - 1);
}

posA Lista_Posicionada_Arreglo::siguiente(posA p) {
	return p + 1;
}

posA Lista_Posicionada_Arreglo::anterior(posA p) {
	return p - 1;
}

int Lista_Posicionada_Arreglo::numElem() {
	return numElementos;
}

void Lista_Posicionada_Arreglo::listar() {//YA!
	posA p = this->primera();
	cout << "Los elementos de la Lista son:" << endl;
	for (int i = 0; i < this->numElem(); i++) {
		cout << this->recuperar(p) << endl;
		p = this->siguiente(p);
	}
}

bool Lista_Posicionada_Arreglo::simetrica() {//YA!
	posA p = this->primera();
	posA q = this->ultima();
	int repeticion = 0;
	bool simetrica = true;
	while ((repeticion < ceil(numElem() / 2)) && simetrica) {
		if (this->recuperar(p) != this->recuperar(q)) {
			simetrica = false;
		}
		else {
			p = this->siguiente(p);
			q = this->anterior(q);
			repeticion++;
		}
	}
	return simetrica;
}

void Lista_Posicionada_Arreglo::invertir() {//YA!
	posA p = this->primera();
	posA q = this->ultima();
	int repeticion = 0;
	while (repeticion < ceil(numElem() / 2)) {
		this->intercambiar(p, q);
		p = this->siguiente(p);
		q = this->anterior(q);
		repeticion++;
	}
}

bool Lista_Posicionada_Arreglo::buscar(elemento e) {//YA!
	posA p = this->primera();
	bool encontrado = false;
	int i = this->numElem();
	while ((i > 0) && !encontrado) {
		if (this->recuperar(p) == e) {
			encontrado = true;
		}
		else {
			p = this->siguiente(p);
		}
		i--;
	}
	return encontrado;
}

void Lista_Posicionada_Arreglo::elimElemRep() {//YA!
	posA p = this->primera();
	posA q;
	bool borrado;
	while (p < this->numElem()) { //Cambiar para TODOS
		q = this->siguiente(p);
		borrado = false;
		while (q < this->numElem() && !(borrado)) {
			if (this->recuperar(q) == this->recuperar(p)) {
				this->borrar(q);
				borrado = true;
			}
			q = this->siguiente(q);
		}
		p = this->siguiente(p);
	}
}

bool Lista_Posicionada_Arreglo::subLista(Lista_Posicionada_Arreglo* L2) {//YA! AUN NO
	bool sub_lista = false;
	bool iguales;
	posA p = this->primera();
	posA q = L2->primera();
	while ((p < this->numElem()) && (q < L2->numElem()) && (!sub_lista)) {
		iguales = true;
		while (p < this->numElem() && (iguales)) {
			if (this->recuperar(p) == L2->recuperar(q)) {
				p = this->siguiente(p);
				q = L2->siguiente(q);
			}
			else {
				iguales = false;
				q = L2->primera();
				p = this->siguiente(p);
			}
		}
	}
	if (iguales && (q == L2->numElem())) {
		sub_lista = true;
	}
	return sub_lista;
}

bool Lista_Posicionada_Arreglo::iguales(Lista_Posicionada_Arreglo* L1) {//YA! AUN NO
	bool iguales = true;
	if (this->numElem() != L1->numElem()) {
		iguales = false;
	}
	else {
		posA p = this->primera();
		posA q = L1->primera();
		int i = 0;
		while (iguales && (i < this->numElem())) {
			if (this->recuperar(p) != this->recuperar(q)) {
				iguales = false;
			}
			else {
				p = this->siguiente(p);
				i++;
				q = L1->siguiente(q);
			}
		}
	}
	return iguales;
}

void Lista_Posicionada_Arreglo::burbujaOriginal() {//YA!
	posA p;
	posA q;
	for (int i = (this->numElem() - 1); i > 0; i--) {
		p = this->primera();
		q = this->siguiente(p);
		for (int j = i; j > 0; j--) {
			if (this->recuperar(p) > this->recuperar(q)) {
				this->intercambiar(p, q);
			}
			p = this->siguiente(p);
			q = this->siguiente(q);
		}
	}
}

void Lista_Posicionada_Arreglo::burbujaBiDir() {//YA!
	posA p = this->primera();
	posA q;
	bool derecha = true;
	for (int i = (this->numElem() - 1); i > 0; i--) {
		if (derecha) {
			q = this->siguiente(p);
			for (int j = i; j > 0; j--) {
				if (this->recuperar(p) > this->recuperar(q)) {
					this->intercambiar(p, q);
				}
				if (j > 1) {
					p = this->siguiente(p);
					q = this->siguiente(q);
				}
			}
		}
		else {
			q = this->anterior(p);
			for (int k = i; k > 0; k--) {
				if (this->recuperar(p) < this->recuperar(q)) {
					this->intercambiar(p, q);
				}
				if (k > 1) {
					p = this->anterior(p);
					q = this->anterior(q);
				}
			}
		}
		derecha = !derecha;
	}
}

void Lista_Posicionada_Arreglo::selectIter() {//YA!
	posA actual = this->primera();
	posA menor;
	posA recorrido;
	for (int i = 0; i < (this->numElem() - 1); i++) {
		menor = actual;
		recorrido = this->siguiente(menor);
		for (int j = i + 1; j < this->numElem(); j++) {
			if (this->recuperar(menor) > this->recuperar(recorrido)) {
				menor = recorrido;
			}
			recorrido = this->siguiente(recorrido);
		}
		this->intercambiar(actual, menor);
		actual = this->siguiente(actual);
	}
}

void Lista_Posicionada_Arreglo::selectRec() {//YA!
	this->selectRecursivo(this->primera());
}

void Lista_Posicionada_Arreglo::selectRecursivo(posA primera) {//YA!
	if (primera < this->ultima()) {
		posA menor = primera;
		posA recorrido = this->siguiente(primera);
		while (recorrido < this->numElem()) {
			if (this->recuperar(recorrido) < this->recuperar(menor)) {
				menor = recorrido;
			}
			recorrido = this->siguiente(recorrido);
		}
		this->intercambiar(primera, menor);
		this->selectRecursivo(this->siguiente(primera));
	}

}

void Lista_Posicionada_Arreglo::insercion() {//YA!
	posA actual = this->primera();
	posA p;
	posA q;
	int i;
	int j;
	int k = 0;
	bool ordenado;
	while (k < this->numElem()) {
		ordenado = false;
		p = actual;
		i = k;
		q = this->anterior(p);
		j = (p - 1);
		while (j < this->numElem() && !ordenado) {
			if (this->recuperar(q) > this->recuperar(p)) {
				this->intercambiar(p, q);
				q = this->anterior(q);
				j--;
				p = this->anterior(p);
				i--;
			}
			else {
				ordenado = true;
			}
		}
		actual = this->siguiente(actual);
		k++;
	}
}

Lista_Posicionada_Arreglo* Lista_Posicionada_Arreglo::mergeSort() {//YA!
	if (this->numElem() > 1) {
		Lista_Posicionada_Arreglo* ListaDerecha = new Lista_Posicionada_Arreglo();
		Lista_Posicionada_Arreglo* ListaIzquierda = new Lista_Posicionada_Arreglo();
		posA p = this->primera();
		for (int i = 0; i < this->numElem(); i++) {
			if (i < (this->numElem() / 2)) {
				ListaIzquierda->agregarAlFinal(this->recuperar(p));
			}
			else {
				ListaDerecha->agregarAlFinal(this->recuperar(p));
			}
			p = this->siguiente(p);
		}
		ListaIzquierda = ListaIzquierda->mergeSort();
		ListaDerecha = ListaDerecha->mergeSort();

		Lista_Posicionada_Arreglo* ordenada = new Lista_Posicionada_Arreglo();
		ordenada = merge(ListaIzquierda, ListaDerecha);
		ListaIzquierda->destruir();
		ListaDerecha->destruir();
		return ordenada;
	}
	else {
		return this;
	}
}

Lista_Posicionada_Arreglo* Lista_Posicionada_Arreglo::merge(Lista_Posicionada_Arreglo* L1, Lista_Posicionada_Arreglo* L2) {//YA!
	Lista_Posicionada_Arreglo* mezcla = new Lista_Posicionada_Arreglo();
	;
	posA p = L1->primera();
	posA q = L2->primera();
	int i = 0;
	int j = 0;
	while ((i < L1->numElem()) && (j < L2->numElem())) {
		if (L1->recuperar(p) <= L2->recuperar(q)) {
			mezcla->agregarAlFinal(L1->recuperar(p));
			p = L1->siguiente(p);
			i++;
		}
		else {
			mezcla->agregarAlFinal(L2->recuperar(q));
			q = L2->siguiente(q);
			j++;
		}
	}
	while (i < L1->numElem()) {
		mezcla->agregarAlFinal(L1->recuperar(p));
		p = L1->siguiente(p);
		i++;
	}
	while (j < L2->numElem()) {
		mezcla->agregarAlFinal(L2->recuperar(q));
		q = L2->siguiente(q);
		j++;
	}
	return mezcla;
}

void Lista_Posicionada_Arreglo::Union(Lista_Posicionada_Arreglo* L1) {//YA
	posA p = this->primera();
	posA q = L1->primera();
	bool encontrado;
	int i = 0;
	int j = 0;
	while (j < L1->numElem()) {
		encontrado = false;
		while ((i < this->numElem()) && !encontrado) {
			if (L1->recuperar(q) != this->recuperar(p)) {
				p = this->siguiente(p);
				i++;
			}
			else {
				encontrado = true;
			}
		}
		if (!encontrado) {
			this->agregarAlFinal(L1->recuperar(q));
		}
		q = L1->siguiente(q);
		j++;
		p = this->primera();
		i = 0;
	}
}

Lista_Posicionada_Arreglo* Lista_Posicionada_Arreglo::interseccionOrd(Lista_Posicionada_Arreglo* L1) {//YA!
	posA p = this->primera();
	posA q = L1->primera();
	int i = 0;
	int j = 0;
	Lista_Posicionada_Arreglo* L3 = new Lista_Posicionada_Arreglo();
	while ((i < this->numElem()) && (j < L1->numElem())) {
		if (this->recuperar(p) == L1->recuperar(q)) {
			L3->agregarAlFinal(this->recuperar(p));
			p = this->siguiente(p);
			i++;
			q = L1->siguiente(q);
			j++;
		}
		else {
			if (this->recuperar(p) > L1->recuperar(q)) {
				q = L1->siguiente(q);
				j++;
			}
			else {
				p = this->siguiente(p);
				i++;
			}
		}
	}
	return L3;
}

Lista_Posicionada_Arreglo* Lista_Posicionada_Arreglo::interseccion(Lista_Posicionada_Arreglo* L1) {//YA!
	Lista_Posicionada_Arreglo* L3 = new Lista_Posicionada_Arreglo();
	posA p = L1->primera();
	posA q;
	bool encontrado;
	int i = 0;
	while (i < L1->numElem()) {
		encontrado = false;
		q = this->primera();
		int j = 0;
		while (!encontrado && (j < this->numElem())) {
			if (L1->recuperar(p) == this->recuperar(q)) {
				L3->agregarAlFinal(L1->recuperar(p));
				encontrado = true;
			}
			else {
				q = this->siguiente(q);
				j++;
			}
		}
		p = L1->siguiente(p);
		i++;
	}
	return L3;
}

void Lista_Posicionada_Arreglo::eliminarIntrOrd(Lista_Posicionada_Arreglo* L2) {//YA!
	posA p = this->primera();
	posA q = L2->primera();
	int i = 0;
	int j = 0;
	while ((i < this->numElem()) && (j < L2->numElem())) {
		if (this->recuperar(p) == L2->recuperar(q)) {
			this->borrar(p);
			q = L2->siguiente(q);
			j++;
		}
		else {
			if (this->recuperar(p) > L2->recuperar(q)) {
				q = L2->siguiente(q);
				j++;
			}
			else {
				p = this->siguiente(p);
				i++;
			}
		}
	}
}

void Lista_Posicionada_Arreglo::eliminarIntr(Lista_Posicionada_Arreglo* L2) { //YA!
	posA p;
	posA q = L2->primera();
	int j = 0;
	bool encontrado;
	while ((j < L2->numElem())) {
		encontrado = false;
		p = this->primera();
		int i = 0;
		while (p < this->numElem() && !encontrado) {
			if (this->recuperar(p) == L2->recuperar(q)) {
				this->borrar(p);
				encontrado = true;
			}
			else {
				p = this->siguiente(p);
				i++;
			}
		}
		q = L2->siguiente(q);
		j++;
	}
}
