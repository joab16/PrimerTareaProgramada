#ifndef LISTA_POSICIONADA_SE_H
#define LISTA_POSICIONADA_SE_H
using namespace std;
#include"Pila.h";

typedef int elemento;

struct NodoS {
    elemento dato;
    NodoS* sgt;

    NodoS(elemento x) : dato(x), sgt(0) {
    };
};
typedef NodoS* posS;

class Lista_Posicionada_SE {
public:
    Lista_Posicionada_SE() {}
    ~Lista_Posicionada_SE() {}
    //EFE: Inicializa la Lista L
    //REQ:
    //MOD:
    void iniciar();

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
    void insertar(elemento e, posS p);

    //EFE: Agrega el elemento e al final de la Lista L
    //REQ: L inicializada
    //MOD: L
    void agregarAlFinal(elemento e);

    //EFE: Borra el elemento de la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD: L
    void borrar(posS p);

    //EFE: Devuelve el elemento de la posicion p en la lIsta L
    //REQ: L inicializada y p valida
    //MOD:
    elemento recuperar(posS p);

    //EFE: Modifica el elemento de la posicion p por el elemento e en la Lista L
    //REQ: L inicializada y p valida
    //MOD: L
    void modificarElemento(elemento e, posS p);

    //EFE: Intercambia los elementos de las posiciones p1 y p2 de la Lista L
    //REQ: L inicializada y p1 p2 validos
    //MOD: L
    void intercambiar(posS p1, posS p2);

    //EFE: Devuelve la primer posicion de la Lista L
    //REQ: L inicializada
    //MOD:
    posS primera();

    //EFE: Devuelve la ultima posicion de la Lista L
    //REQ: L inicializada
    //MOD:
    posS ultima();

    //EFE: Devuelve la posicion siguiente a la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD:
    posS siguiente(posS p);

    //EFE: Devuelve la posicion anterior a la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD:
    posS anterior(posS p);

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
	bool subLista(Lista_Posicionada_SE* L1);

	//EFE: Devuelve true si L y L1 son iguales, de lo contrario devuelve falso
	//REQ: L y L1 inicializadas
	//MOD:
	bool iguales(Lista_Posicionada_SE* L1);

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
	void insercion(posS actual, posS ultima);

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
	Lista_Posicionada_SE* mergeSort();

	//EFE: Une la Lista L con L1
	//REQ: L y L1 inicializada
	//MOD: L
	void Union(Lista_Posicionada_SE* L1);

	//EFE: Devueleve una Lista con la interseccion de L1 y L
	//REQ: L y L1 inicializadas, ordenadas y sin elementos repetidos
	//MOD:
	Lista_Posicionada_SE* interseccionOrd(Lista_Posicionada_SE* L1);

	//EFE: Devuelve una Lista con la interseccion de L1 y L
	//REQ: L1 y L inicializadas y sin elementos repetidos
	//MOD:
	Lista_Posicionada_SE* interseccion(Lista_Posicionada_SE* L1);

	//EFE: Elimina de la Lista L la interseccion con L1
	//REQ: L y L1 inicializadas y ordenadas
	//MOD: L
	void eliminarIntrOrd(Lista_Posicionada_SE* L1);

	//EFE: Elimina de la Lista L la interseccion con L1
	//REQ: L y L1 inicializadas
	//MOD: L
	void eliminarIntr(Lista_Posicionada_SE* L1);


	posS EncuentraPivote(posS i, posS j);

	/*
	Nombre: Particion
	Parámetros: int i, int j, int pivote
	Efecto: Establece la particion a usar por el quick sort
	Requiere: Lista global inicializada
	Modifica:

	*/
	posS Particion(posS i, posS j, elemento pivote);

	/*
	Nombre: QuickSortAho
	Parámetros:
	Efecto: Llama al metodo de ordenamiento recursivo QuickSortAho
	Requiere: Lista global inicializada
	Modifica:

	*/
	void QuickSortAho();
	/**
	Nombre: QuickSortAho
	Parámetros:
	Efecto: Ordena una lista indexada usando el algoritmo Quick Sort version Aho
	Requiere: Lista global inicializada
	Modifica: Lista global

	*/
	void QuickSortAho(posS i, posS j);
	/**
	Nombre: QuickSort
	Parámetros:
	Efecto: Llama al metodo de ordenamiento recursivo QuickSort
	Requiere: Lista global inicializada
	Modifica:

	*/
	void QuickSort();
	/**
	Nombre: QuickSort
	Parámetros: ListaIndexada L, int i, int j
	Efecto: Ordena una lista, si la lista es de 50 elementos o menos usa insercion
	Requiere: Lista global inicializada
	Modifica:

	*/
	void QuickSort(posS i, posS j);

	void SeleccionRecursivoPila(pos primera);

protected:
	//EFE: Metodo Privado, complementario al metodo mergeSort de la Lista
	//REQ:
	//MOD:
	Lista_Posicionada_SE* merge(Lista_Posicionada_SE* L1, Lista_Posicionada_SE* L2);

	//EFE: Metodo Privado, complementario al metodo selectRec de la Lista
	//REQ:
	//MOD:
	void selectRecursivo(posS primera);

    private:
        NodoS* inicio;
};

#endif // LISTA_POSICIONADA_SE_H
Lista_Posicionada_SE::Lista_Posicionada_SE() {
	inicio = 0;
}

void Lista_Posicionada_SE::destruir() {
	NodoS* p = inicio;
	NodoS* q = 0;
	while (p != 0) {
		q = p->sgt;
		delete p;
		p = q;
	}
}

void Lista_Posicionada_SE::vaciar() {
	NodoS* p = inicio;
	NodoS* q = 0;
	while (p != 0) {
		q = p->sgt;
		delete p;
		p = q;
	}
	inicio = 0;
}

bool Lista_Posicionada_SE::vacia() {
	bool vacia = false;
	if (inicio == 0) {
		vacia = true;
	}
	return vacia;
}

void Lista_Posicionada_SE::insertar(elemento e, posS p) {
	posS q = inicio;
	NodoS* agregado = new NodoS(e);
	if (p == q) {
		agregado->sgt = q;
		inicio = agregado;
	}
	else {
		bool insertado = false;
		while (!insertado) {
			if (p == q->sgt) {
				agregado->sgt = q->sgt;
				q->sgt = agregado;
				insertado = true;
			}
			else {
				q = q->sgt;
			}
		}
	}
}

void Lista_Posicionada_SE::agregarAlFinal(elemento e) {
	if (inicio == 0) {
		inicio = new NodoS(e);
	}
	else {
		bool agregado = false;
		posS p = inicio;
		while (!agregado) {
			if (p->sgt == 0) {
				p->sgt = new NodoS(e);
				agregado = true;
			}
			else {
				p = p->sgt;
			}
		}
	}
}

void Lista_Posicionada_SE::borrar(posS p) {
	posS q = inicio;
	if (q == p) {
		inicio = q->sgt;
		delete q;
	}
	else {
		bool borrado = false;
		while (!borrado) {
			if (q->sgt == p) {
				posS aux = q->sgt;
				q->sgt = p->sgt;
				delete aux;
				borrado = true;
			}
			else {
				q = q->sgt;
			}
		}
	}
}

elemento Lista_Posicionada_SE::recuperar(posS p) {
	elemento recuperado = p->dato;
	return recuperado;
}

void Lista_Posicionada_SE::modificarElemento(elemento e, posS p) {
	p->dato = e;
}

void Lista_Posicionada_SE::intercambiar(posS p1, posS p2) {
	elemento aux = p1->dato;
	p1->dato = p2->dato;
	p2->dato = aux;
}

posS Lista_Posicionada_SE::primera() {
	return inicio;
}

posS Lista_Posicionada_SE::ultima() {
	posS posicion = inicio;
	while (!(posicion->sgt == 0)) {
		posicion = posicion->sgt;
	}
	return posicion;
}

posS Lista_Posicionada_SE::siguiente(posS p) {
	return p->sgt;
}

posS Lista_Posicionada_SE::anterior(posS p) {
	bool encontrado = false;
	posS anterior = inicio;
	while (!encontrado) {
		if (anterior->sgt == p) {
			encontrado = true;
		}
		else {
			anterior = anterior->sgt;
		}
	}
	return anterior;
}

int Lista_Posicionada_SE::numElem() {
	posS p = inicio;
	int numElementos = 0;
	while (p != 0) {
		numElementos++;
		p = p->sgt;
	}
	return numElementos;
}

void Lista_Posicionada_SE::listar() {//YA!
	posS p = this->primera();
	cout << "Los elementos de la Lista son:" << endl;
	for (int i = 0; i < this->numElem(); i++) {
		cout << this->recuperar(p) << endl;
		p = this->siguiente(p);
	}
}

bool Lista_Posicionada_SE::simetrica() {//YA!
	posS p = this->primera();
	posS q = this->ultima();
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

void Lista_Posicionada_SE::invertir() {//YA!
	posS p = this->primera();
	posS q = this->ultima();
	int repeticion = 0;
	while (repeticion < ceil(numElem() / 2)) {
		this->intercambiar(p, q);
		p = this->siguiente(p);
		q = this->anterior(q);
		repeticion++;
	}
}

bool Lista_Posicionada_SE::buscar(elemento e) {//YA!
	posS p = this->primera();
	bool encontrado = false;
	while ((p != 0) && !encontrado) {
		if (this->recuperar(p) == e) {
			encontrado = true;
		}
		else {
			p = this->siguiente(p);
		}
	}
	return encontrado;
}

void Lista_Posicionada_SE::elimElemRep() {//YA!
	posS p = this->primera();
	posS q;
	while (!(p == 0)) {
		q = this->siguiente(p);
		while (!(q == 0)) {
			if (this->recuperar(q) == this->recuperar(p)) {
				this->borrar(q);
				q = this->siguiente(p);
			}
			q = this->siguiente(q);
		}
		p = this->siguiente(p);
	}
}

bool Lista_Posicionada_SE::subLista(Lista_Posicionada_SE* L2) {//YA!
	bool sub_lista = false;
	bool iguales;
	posS p = this->primera();
	posS q = L2->primera();
	while (p != 0 && (q != 0) && (!sub_lista)) {
		iguales = true;
		while (p != 0 && (iguales)) {
			if (this->recuperar(p) == this->recuperar(q)) {
				p = this->siguiente(p);
				q = L2->siguiente(q);
			}
			else {
				iguales = false;
				q = L2->primera();
				if (!(this->recuperar(p) == this->recuperar(q))) {
					p = this->siguiente(p);
				}
			}
		}
		if (iguales && (q == 0)) {
			sub_lista = true;
		}
	}
	return sub_lista;
}

bool Lista_Posicionada_SE::iguales(Lista_Posicionada_SE* L1) {//YA!
	bool iguales = true;
	if (this->numElem() != L1->numElem()) {
		iguales = false;
	}
	else {
		posS p = this->primera();
		posS q = L1->primera();
		while (iguales && (p != 0)) {
			if (this->recuperar(p) != this->recuperar(q)) {
				iguales = false;
			}
			else {
				p = this->siguiente(p);
				q = L1->siguiente(q);
			}
		}
	}
	return iguales;
}

void Lista_Posicionada_SE::burbujaOriginal() {//YA!
	posS p;
	posS q;
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

void Lista_Posicionada_SE::burbujaBiDir() {//YA!
	posS p = this->primera();
	posS q;
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

void Lista_Posicionada_SE::selectIter() {//YA!
	posS actual = this->primera();
	posS menor;
	posS recorrido;
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

void Lista_Posicionada_SE::selectRec() {//YA!
	this->selectRecursivo(this->primera());
}

void Lista_Posicionada_SE::selectRecursivo(posS primera) {//YA!
	if (primera == this->ultima()) {
		return;
	}
	posS menor = primera;
	posS recorrido = this->siguiente(primera);
	while (recorrido != 0) {
		if (this->recuperar(recorrido) < this->recuperar(menor)) {
			menor = recorrido;
		}
		recorrido = this->siguiente(recorrido);
	}
	this->intercambiar(primera, menor);
	this->selectRecursivo(this->siguiente(primera));
}

void Lista_Posicionada_SE::insercion(posS actual, posS ultima) {//YA!
	posS p;
	posS q;
	bool ordenado;
	int iP;
	int jQ;
	int kActual = 0;
	int numElem = 0;
	q = actual;
	while (q != ultima) {
		numElem++;
		q = this->siguiente(q);
	}
	while (kActual < numElem) {
		ordenado = false;
		p = actual;
		iP = kActual;
		q = this->anterior(p);
		jQ = (iP - 1);
		while ((jQ < numElem && jQ > 0) && !ordenado) {
			if (this->recuperar(q) > this->recuperar(p)) {
				this->intercambiar(p, q);
				jQ--;
				q = this->anterior(q);
				p = this->anterior(p);
				iP--;
			}
			else {
				ordenado = true;
			}
		}
		actual = this->siguiente(actual);
		kActual++;
	}
}

/*void Lista_Posicionada_SE::insercion() {//YA!
posS actual = this->primera();
posS p;
posS q;
bool ordenado;
while (actual != 0) {
ordenado = false;
p = actual;
q = this->anterior(p);
while (q != 0 && !ordenado) {
if (this->recuperar(q) > this->recuperar(p)) {
this->intercambiar(p, q);
q = this->anterior(q);
p = this->anterior(p);
} else {
ordenado = true;
}
}
actual = this->siguiente(actual);
}
}*/

Lista_Posicionada_SE* Lista_Posicionada_SE::mergeSort() {//YA!
	if (this->numElem() > 1) {
		Lista_Posicionada_SE* ListaDerecha = new Lista_Posicionada_SE();
		Lista_Posicionada_SE* ListaIzquierda = new Lista_Posicionada_SE();
		posS p = this->primera();
		for (int i = 0; i<this->numElem(); i++) {
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
		Lista_Posicionada_SE* ordenada = new Lista_Posicionada_SE();
		ordenada = merge(ListaIzquierda, ListaDerecha);
		ListaIzquierda->destruir();
		ListaDerecha->destruir();
		return ordenada;
	}
	else {
		return this;
	}
}

Lista_Posicionada_SE* Lista_Posicionada_SE::merge(Lista_Posicionada_SE* L1, Lista_Posicionada_SE* L2) {//YA!
	Lista_Posicionada_SE* mezcla = new Lista_Posicionada_SE();
	posS p = L1->primera();
	posS q = L2->primera();
	while ((p != 0) && (q != 0)) {
		if (this->recuperar(p) <= this->recuperar(q)) {
			mezcla->agregarAlFinal(this->recuperar(p));
			p = L1->siguiente(p);
		}
		else {
			mezcla->agregarAlFinal(this->recuperar(q));
			q = L2->siguiente(q);
		}
	}
	while (p != 0) {
		mezcla->agregarAlFinal(this->recuperar(p));
		p = L1->siguiente(p);
	}
	while (q != 0) {
		mezcla->agregarAlFinal(this->recuperar(q));
		q = L2->siguiente(q);
	}
	return mezcla;
}

void Lista_Posicionada_SE::Union(Lista_Posicionada_SE* L1) {//YA
	posS p = this->primera();
	posS q = L1->primera();
	bool encontrado;
	while (q != 0) {
		encontrado = false;
		while ((p != 0) && !encontrado) {
			if (this->recuperar(q) != this->recuperar(p)) {
				p = this->siguiente(p);
			}
			else {
				encontrado = true;
			}
		}
		if (!encontrado) {
			this->agregarAlFinal(this->recuperar(q));
		}
		q = L1->siguiente(q);
		p = this->primera();
	}
}

Lista_Posicionada_SE* Lista_Posicionada_SE::interseccionOrd(Lista_Posicionada_SE* L1) {//YA!
	posS p = this->primera();
	posS q = L1->primera();
	Lista_Posicionada_SE* L3 = new Lista_Posicionada_SE();
	while ((p != 0) && (q != 0)) {
		if (this->recuperar(p) == L1->recuperar(q)) {
			L3->agregarAlFinal(this->recuperar(p));
			p = this->siguiente(p);
			q = L1->siguiente(q);
		}
		else {
			if (this->recuperar(p) > L1->recuperar(q)) {
				q = L1->siguiente(q);
			}
			else {
				p = this->siguiente(p);
			}
		}
	}
	return L3;
}

Lista_Posicionada_SE* Lista_Posicionada_SE::interseccion(Lista_Posicionada_SE* L1) {//YA!
	Lista_Posicionada_SE* L3 = new Lista_Posicionada_SE();
	posS p = L1->primera();
	posS q;
	bool encontrado;
	while (p != 0) {
		encontrado = false;
		q = this->primera();
		while (!encontrado && (q != 0)) {
			if (this->recuperar(p) == this->recuperar(q)) {
				L3->agregarAlFinal(this->recuperar(p));
				encontrado = true;
			}
			else {
				q = this->siguiente(q);
			}
		}
		p = L1->siguiente(p);
	}
	return L3;
}

void Lista_Posicionada_SE::eliminarIntrOrd(Lista_Posicionada_SE* L2) {//YA!
	posS p = this->primera();
	posS q = L2->primera();
	int posSicionP = 1;
	while ((p != 0) && (q != 0)) {
		if (this->recuperar(p) == L2->recuperar(q)) {
			this->borrar(p);
			p = this->primera();
			for (int i = 1; i < posSicionP; i++) {
				p = this->siguiente(p);
			}
			q = L2->siguiente(q);
		}
		else {
			if (this->recuperar(p) > L2->recuperar(q)) {
				q = L2->siguiente(q);
			}
			else {
				p = this->siguiente(p);
				posSicionP++;
			}
		}
	}
}

void Lista_Posicionada_SE::eliminarIntr(Lista_Posicionada_SE* L2) { //YA!
	posS p;
	posS q = L2->primera();
	bool encontrado;
	while ((q != 0)) {
		encontrado = false;
		p = this->primera();
		while (p != 0 && !encontrado) {
			if (this->recuperar(p) == L2->recuperar(q)) {
				this->borrar(p);
				encontrado = true;
			}
			else {
				p = this->siguiente(p);
			}
		}
		q = L2->siguiente(q);
	}
}

posS Lista_Posicionada_SE::EncuentraPivote(posS i, posS j) {
	elemento primeraClave = this->recuperar(i);
	posS pivote;
	posS k = this->siguiente(i);
	while (k != j) {
		if (this->recuperar(k) > primeraClave) {
			pivote = k;
		}
		else if (this->recuperar(k) < primeraClave) {
			pivote = i;
		}
		k = this->siguiente(k);
	}
	return pivote;
}

posS Lista_Posicionada_SE::Particion(posS i, posS j, elemento pivote) {
	posS z = i, d = j;
	do {
		this->intercambiar(z, d);
		while (this->recuperar(z) != pivote) {
			z = this->siguiente(z);
		}
		while (this->recuperar(d) != pivote) {
			d = this->anterior(d);
		}
	} while (z != d);
	return z;
}

void Lista_Posicionada_SE::QuickSortAho() {
	QuickSortAho(this->primera(), this->ultima());
}

void Lista_Posicionada_SE::QuickSortAho(posS i, posS j) {
	elemento pivote;
	posS indicePivote;
	posS k;

	indicePivote = this->EncuentraPivote(i, j);
	pivote = this->recuperar(indicePivote);
	k = this->Particion(i, j, pivote);
	this->QuickSortAho(i, this->anterior(k));
	this->QuickSortAho(k, j);
}

void Lista_Posicionada_SE::QuickSort() {
	QuickSort(this->primera(), this->ultima());
}

void Lista_Posicionada_SE::QuickSort(posS i, posS j) {
	posS elemento = i;
	int numElemento = 1;
	while (i != j) {
		numElemento++;
		this->siguiente(elemento);
	}
	if (numElemento <= 50) {
		//TODO: Llamar al metodo insercion
	}
	else {

		posS indicePivote;
		posS k;

		indicePivote = this->EncuentraPivote(i, j);
		if (indicePivote == this->primera()) {
			k = this->Particion(i, j, this->recuperar(indicePivote));
			this->QuickSort(i, this->anterior(k));
			this->QuickSort(k, j);
		}
	}
}

/**
Nombre: SeleccionRecursivoPila
Parámetros: ListaIndexada L
Efecto: Ordena los elementos de la lista usando el algoritmo Selección Recursivo pero sin usar la pila del compilador
Requiere: Lista L inicializada
Modifica: L

*/
void Lista_Posicionada_SE::SeleccionRecursivoPila(posS primera) {
	if (primera != 0) {
		Pila *pilaAux = new Pila();
		pilaAux->iniciar();
		pilaAux->poner(primera);
		while (!pilaAux->vacia()) {
			posS posSicionActual = pilaAux->quitar();
			if (posSicionActual != 0) {
				pilaAux->poner(this->siguiente(posSicionActual));
				posS minimo = posSicionActual;
				posS posSicion = posSicionActual;
				while (posSicion != 0) {
					if (this->recuperar(posSicion) < this->recuperar(minimo))
						minimo = posSicion;
					posSicion = this->siguiente(posSicion)
				}
				this->intercambiar(indiceActual, minimo);
			}
		}
	}
}