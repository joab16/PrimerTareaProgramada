#ifndef LISTARREGLO
#define LISTARREGLO
#include <string>
#include <sstream>
#include <iostream>

class ListaArreglo
{
public:
	ListaArreglo();
	~ListaArreglo();
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
	static const int M = 17;
	int numElem;
	int lista[M];
private:

};

#endif // LISTARREGLO

ListaArreglo::ListaArreglo()
{
}

ListaArreglo::~ListaArreglo()
{
}

/**
Nombre: Iniciar
Parámetros: L (lista)
Efecto: Inicializa una lista dada
Requiere: Lista no inicializada
Modifica:
*/
void ListaArreglo::Iniciar()
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
void ListaArreglo::Destruir()
{

}

/**
Nombre: Vaciar
Parámetros: L (lista)
Efecto: Vacía una lista
Requiere: Lista inicializada
Modifica: L, numElem
*/
void ListaArreglo::Vaciar()
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
bool ListaArreglo::Vacia()
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
void ListaArreglo::Insertar(int e, int i)
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
void ListaArreglo::Borrar(int i)
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
int ListaArreglo::Recuperar(int i)
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
void ListaArreglo::ModificarElemento(int e, int i)
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
void ListaArreglo::Intercambiar(int i1, int i2)
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
int ListaArreglo::NumElem()
{
	return numElem;
}
