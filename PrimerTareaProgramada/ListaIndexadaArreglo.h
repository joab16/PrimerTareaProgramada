#ifndef LISTARREGLO
#define LISTARREGLO
#include <string>
#include <sstream>
#include <iostream>

class ListaIndexadaArreglo
{
public:
	ListaIndexadaArreglo();
	~ListaIndexadaArreglo();
	void Iniciar();
	void Destruir();
	void Vaciar();
	bool Vacia();
	void Insertar(int e, int i);
	void Borrar(int i);
	int Recuperar(int i);
	void ModificarElemento(int e, int i);
	void Intercambiar(int i1, int i2);
	int NumElem();

protected:
	static const int M = 20000;
	int numElem;
	int lista[M];
private:

};

#endif // LISTARREGLO

ListaIndexadaArreglo::ListaIndexadaArreglo()
{
}

ListaIndexadaArreglo::~ListaIndexadaArreglo()
{
}

/**
Nombre: Iniciar
Parámetros: L (lista)
Efecto: Inicializa una lista dada
Requiere: Lista no inicializada
Modifica:
*/
void ListaIndexadaArreglo::Iniciar()
{
	numElem = 0;
}

/**
Nombre: Destruir
Parámetros: L (lista)
Efecto: Destruye una lista dada
Requiere: Lista inicializada
Modifica:
*/
void ListaIndexadaArreglo::Destruir()
{

}

/**
Nombre: Vaciar
Parámetros: L (lista)
Efecto: Vacía una lista
Requiere: Lista inicializada
Modifica: L, numElem
*/
void ListaIndexadaArreglo::Vaciar()
{
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
bool ListaIndexadaArreglo::Vacia()
{
	if (numElem == 0)
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
void ListaIndexadaArreglo::Insertar(int e, int i)
{
	for (int j = numElem; j > i; j--)
	{
		lista[j] = lista[j - 1];
	}
	lista[i] = e;
	++numElem;
}

/**
Nombre: Borrar
Parámetros: L (lista), e (elemento)
Efecto: Borra el elemento e de la lista
Requiere: Lista inicializada
Modifica: L (lista) , numElem
*/
void ListaIndexadaArreglo::Borrar(int i)
{
	for (int j = i; j < numElem - 1; j++)
	{
		lista[j] = lista[j + 1];
	}
	--numElem;
}

/**
Nombre: Recuperar
Parámetros: i (índice), L(Lista)
Efecto: Devuelve el elemento ubicado en el índice i
Requiere: Lista inicializada, i debe ser un índice válido en la Lista
Modifica:
*/
int ListaIndexadaArreglo::Recuperar(int i)
{
	return lista[i];
}

/**
Nombre: ModificarElemento
Parámetros: i (índice), e(elemento), L(Lista)
Efecto: Modifica en la lista L, el elemento del índice i, por el elemento e
Requiere: Lista inicializada y que i sea un índice válido
Modifica: L(Lista)
*/
void ListaIndexadaArreglo::ModificarElemento(int e, int i)
{
	lista[i] = e;
}

/**
Nombre: Intercambiar
Parámetros: i1(índice), i2(índice), L(Lista)
Efecto: Intercambia el elemento en del índice i1, con el elemento en del índice i2
Requiere: Lista inicializada. i1 y i2 deben ser índices válidos de la Lista
Modifica: L(Lista)
*/
void ListaIndexadaArreglo::Intercambiar(int i1, int i2)
{
	int aux = lista[i1];
	lista[i1] = lista[i2];
	lista[i2] = aux;
}

/**
Nombre: NumElem
Parámetros: L(Lista)
Efecto: Devuelve el número de elementos de la lista
Requiere: Lista inicializada
Modifica:
*/
int ListaIndexadaArreglo::NumElem()
{
	return this->numElem;
}
