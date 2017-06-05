#ifndef LISTAINDEXADASE
#define LISTAINDEXADASE

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

typedef int elemento;

struct NodoI {
	elemento dato;
	int indice;
	NodoI* sgt;

	NodoI(elemento e, int i) : dato(e), indice(i), sgt(0) {
	};
};
typedef NodoI* posI;

class ListaIndexadaSE
{
public:
	ListaIndexadaSE();
	~ListaIndexadaSE();
	void Iniciar();
	void Destruir();
	void Vaciar();
	bool Vacia();
	void Insertar(elemento e, int i);
	void Borrar(int i);
	elemento Recuperar(int i);
	void ModificarElemento(elemento e, int i);
	void Intercambiar(int i1, int i2);
	int NumElem();

protected:
	int numElem;
	NodoI* inicio;
	NodoI* NodoNulo;
private:

};

#endif // LISTAINDEXADASE

ListaIndexadaSE::ListaIndexadaSE()
{
}

ListaIndexadaSE::~ListaIndexadaSE()
{
}

/**
Nombre: Iniciar
Parámetros: L (lista)
Efecto: Inicializa una lista dada
Requiere: Lista no inicializada
Modifica:
*/
void ListaIndexadaSE::Iniciar()
{
	inicio = new NodoI(0,0);
	NodoNulo = 0;
	numElem = 0;
}

/**
Nombre: Destruir
Parámetros: L (lista)
Efecto: Destruye una lista dada
Requiere: Lista inicializada
Modifica:
*/
void ListaIndexadaSE::Destruir()
{
	NodoI* p = inicio;
	NodoI* q = 0;
	while (p != NodoNulo)
	{
		q = p->sgt;
		delete p;
		p = q;
	}
	delete p;
	delete q;
}

/**
Nombre: Vaciar
Parámetros: L (lista)
Efecto: Vacía una lista
Requiere: Lista inicializada
Modifica: L, numElem
*/
void ListaIndexadaSE::Vaciar()
{
	NodoI* p = inicio->sgt;
	NodoI* q = 0;
	while (p != NodoNulo)
	{
		q = p->sgt;
		p->sgt = NodoNulo;
		delete p;
		p = q;
		numElem--;
		/*posicion aux = p1->siguiente;
        p1->siguiente = posNula;
        primera = aux;
        delete p1;
        p1 = primera;
        numElem--;*/
	}
	inicio = 0;
	NodoNulo = 0;
	numElem = 0;
}

/**
Nombre: Vacía
Parámetros: L (lista)
Efecto: Devuelve un booleano indicando si la lista está vacía o no
10
Requiere: Lista inicializada
Modifica:
*/
bool ListaIndexadaSE::Vacia()
{
	if (inicio == 0)
		return true;
	return false;
}

/**
Nombre: Insertar
Parámetros: L (lista), e (elemento)
Efecto: Inserta el elemento e en la lista, e debe ser un elemento válido.
Requiere: Lista inicializada
Modifica: L (lista), numElem
*/
void ListaIndexadaSE::Insertar(elemento e, int i)
{
	NodoI* nuevoNodo = new NodoI(e, i);
	NodoI* temp = inicio;
	bool insertado = false;
	if (temp->sgt == NodoNulo)
    {
        temp->sgt = nuevoNodo;
        insertado = true;
        ++numElem;
    }
	while (!insertado)
	{
	    temp = temp->sgt;
	    if (temp->sgt == NodoNulo)
        {
            temp->sgt = nuevoNodo;
            insertado = true;
            ++numElem;
        }
        else if (temp->indice == i)
        {
            NodoI* aux = temp->sgt;
            temp->sgt = nuevoNodo;
            nuevoNodo->sgt = aux;
            insertado = true;
            ++numElem;
            while (aux != NodoNulo)
            {
                aux->indice = ++aux->indice;
                aux = aux->sgt;
            }
        }
	}
}

/**
Nombre: Borrar
Parámetros: L (lista), e (elemento)
Efecto: Borra el elemento e de la lista
Requiere: Lista inicializada
Modifica: L (lista) , numElem
*/
void ListaIndexadaSE::Borrar(int i)
{
	NodoI* temp = inicio;
	bool borrado = false;
	while (!borrado)
    {
        if (temp == NodoNulo)
        {
            borrado = true;
        }
		else if (temp->sgt != NodoNulo && temp->sgt->indice == i)
		{
			NodoI* aux = temp->sgt;
			if (aux->sgt != NodoNulo)
			{
				temp->sgt = aux->sgt;
				aux->sgt = NodoNulo;
				delete aux;
				--numElem;
				temp = temp->sgt;
				while (temp != NodoNulo)
				{
					temp->indice = temp->indice - 1;
					temp = temp->sgt;
				}
			}
			else
			{
				temp->sgt = NodoNulo;
				--numElem;
				delete aux;
			}
		}
			/*if (temp->indice == i)

        {
            NodoI* aux = temp->sgt;
			if (aux != NodoNulo)
			{
				temp->sgt = aux->sgt;
				aux->sgt = NodoNulo;
				delete aux;
				--numElem;
				temp = temp->sgt;
				while (temp != NodoNulo)
				{
					temp->indice = --aux->indice;
					temp = temp->sgt;
				}
			}
			else
			{
				delete temp;
			}
			borrado = true;
        }*/
        else
        {
            temp = temp->sgt;
        }
    }
}

/**
Nombre: Recuperar
Parámetros: i (índice), L(Lista)
Efecto: Devuelve el elemento ubicado en el índice i
Requiere: Lista inicializada, i debe ser un índice válido en la Lista
Modifica:
*/
elemento ListaIndexadaSE::Recuperar(int i)
{
	NodoI* temp = inicio->sgt;
	while (temp != NodoNulo && temp->indice < i)
	{
		temp = temp->sgt;
	}
	if (temp->indice == i)
		return temp->dato;
	return 0;
}

/**
Nombre: ModificarElemento
Parámetros: i (índice), e(elemento), L(Lista)
Efecto: Modifica en la lista L, el elemento del índice i, por el elemento e
Requiere: Lista inicializada y que i sea un índice válido
Modifica: L(Lista)
*/
void ListaIndexadaSE::ModificarElemento(elemento e, int i)
{
	NodoI* temp = inicio->sgt;
	while (temp != NodoNulo && temp->indice < i)
	{
		temp = temp->sgt;
	}
	if (temp->indice == i)
		temp->dato = e;
}

/**
Nombre: Intercambiar
Parámetros: i1(índice), i2(índice), L(Lista)
Efecto: Intercambia el elemento en del índice i1, con el elemento en del índice i2
Requiere: Lista inicializada. i1 y i2 deben ser índices válidos de la Lista
Modifica: L(Lista)
*/
void ListaIndexadaSE::Intercambiar(int i1, int i2)
{
	NodoI* temp1 = inicio->sgt;
	NodoI* temp2 = inicio->sgt;
	while (temp1 != NodoNulo && temp1->indice < i1)
	{
		temp1 = temp1->sgt;
	}
	while (temp2 != NodoNulo && temp2->indice < i2)
	{
		temp2 = temp2->sgt;
	}
	elemento aux = temp1->dato;
	temp1->dato = temp2->dato;
	temp2->dato = aux;
}

/**
Nombre: NumElem
Parámetros: L(Lista)
Efecto: Devuelve el número de elementos de la lista
Requiere: Lista inicializada
Modifica:
*/
int ListaIndexadaSE::NumElem()
{
	return numElem;
}
