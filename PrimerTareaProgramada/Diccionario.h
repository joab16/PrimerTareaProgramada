#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "Caja.h"

#include <iostream>

using namespace std;
template <class Z>
class Diccionario
{
public:
	Diccionario();
	virtual ~Diccionario();
	void crear();
	void destruir();
	void vaciar();
	bool vacio();
	void agregar(Z);
	void eliminar(Z);
	bool pertenece(Z);
	Z siguiente(Z);
	int numElem();
	int cantidad;
	Caja<Z> *primero;

protected:

private:
};
template <class Z>
Diccionario<Z>::Diccionario()
{

}
template <class Z>
Diccionario<Z>::~Diccionario()
{

}
/**
Nombre: Crear
Parámetros:
Efecto: Inicializa el diccionario
Requiere: Diccionario no inicializado
Modifica:

*/
template <class Z>
void Diccionario<Z>::crear()
{
	primero = 0;
	cantidad = 0;
}
/**
Nombre: Destruir
Parámetros:
Efecto: Destruye el diccionario
Requiere: Diccionario inicializado
Modifica:

*/
template <class Z>
void Diccionario<Z>::destruir()
{

}
/**
Nombre: Vaciar
Parámetros:
Efecto: Vacia el diccionario
Requiere: Diccionario inicializado
Modifica:

*/
template <class Z>
void Diccionario<Z>::vaciar()
{

}
/**
Nombre: Vacio
Parámetros:
Efecto: Devuelve un bool si el diccionario esta vacío o no
Requiere: Diccionario inicializado
Modifica:

*/
template <class Z>
bool Diccionario<Z>::vacio()
{
	if (cantidad == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
Nombre: Pertenece
Parámetros: elem
Efecto: Devuelve un bool para saber si el elemento existe o no en el diccionario
Requiere: Diccionario inicializado
Modifica: Diccionario,

*/

template <class Z>
bool Diccionario<Z>::pertenece(Z elem)
{
	Caja<Z> *mover = primero;
	while (mover != 0)
	{
		if (mover->dato == elem)
		{
			return true;
		}
		else
		{
			mover = mover->ptr;
		}

	}
	return false;
}
/**
Nombre: Agregar
Parámetros: elem
Efecto: Agrega un elemento al diccionario
Requiere: Diccionario inicializado
Modifica: Diccionario, NumElem

*/
template <class Z>
void Diccionario<Z>::agregar(Z elem)
{
	if (pertenece(elem) == false)
	{
		Caja<Z> *caja = new Caja<Z>();
		caja->dato = elem;
		caja->ptr = 0;
		if (cantidad == 0)
		{
			primero = caja;
			cantidad++;
		}
		else
		{
			Caja<Z> *mover = primero;
			while (mover->ptr != 0)
			{
				mover = mover->ptr;
			}
			mover->ptr = caja;
			cantidad++;
		}

	}

}
/**
Nombre: Eliminar
Parámetros: elem
Efecto: Elimina un elemento al diccionario
Requiere: Diccionario inicializado
Modifica: Diccionario, NumElem

*/
template <class Z>
void Diccionario<Z>::eliminar(Z elem)
{
	Caja<Z> *mover = primero;
	Caja<Z> *contenedor = 0;
	Caja<Z> *borrar;
	bool eliminado = false;
	if (primero->dato == elem)
	{
		borrar = primero;
		primero = primero->ptr;
		delete borrar;
	}
	else
	{
		while (mover->ptr != 0 && !eliminado)
		{
			if (mover->ptr->dato == elem) {
				borrar = mover->ptr;
				mover->ptr = borrar->ptr;
				delete borrar;
				eliminado = true;
			}
			else {
				mover = mover->ptr;
			}
		}
	}
	cantidad--;
}

/**
Nombre: NumElem
Parámetros:
Efecto: Devuelve la cantidad de elementos en el diccionario
Requiere: Diccionario inicializado
Modifica:

*/
template <class Z>
int Diccionario<Z>::numElem()
{
	return cantidad;
}

template <class Z>
Z Diccionario<Z>::siguiente(Z elem)
{
	Caja<Z> *mover = primero;

	while ((mover != 0) && (mover->dato != elem))
	{
		mover = mover->ptr;
	}
	if (mover->ptr != 0)
	{
		cout << mover->ptr->dato << endl;
		return mover->ptr->dato;
	}
	else
	{
		return 0;
	}

}
#endif // DICCIONARIO_H