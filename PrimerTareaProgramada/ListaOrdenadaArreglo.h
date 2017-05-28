#ifndef ListaOrdenadaARREGLO_H
#define LISTAORDENADAARREGLO_H
//#include "Posicion.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int posicion;

class ListaOrdenadaArreglo
{
    public:
        ListaOrdenadaArreglo() {}
        ~ListaOrdenadaArreglo() {}
        void Iniciar();
        void Destruir();
        void Vaciar();
        bool Vacia();
        void Agregar(elemento e);
        void Borrar(elemento e);
        elemento Primero();
        elemento Siguiente(elemento e);
        elemento Ultimo();
        elemento Anterior(elemento e);
        void Listar();
        int NumElem();
        posicion posNula;
        elemento arreglo[17];
        int ultimoLleno;

    protected:

    private:
};

#endif // ListaOrdenadaArreglo_H



/**
Nombre: Iniciar
Parámetros: L
Efecto: Inicializa la lista
Requiere: Lista no inicializada
Modifica:

*/
void ListaOrdenadaArreglo::Iniciar()
{
	ultimoLleno = -1;
    posNula = -1;
	for (int i = 0; i < 17; ++i)
	{
		arreglo[i] = -1;
	}
}

/**
Nombre: Destruir
Parámetros: L
Efecto: Destruye la lista
Requiere: Lista inicializada
Modifica:

*/
void ListaOrdenadaArreglo::Destruir()
{
    ultimoLleno = -1;
}

/**
Nombre: Vaciar
Parámetros: L
Efecto: Elimina los elementos dentro de una Lista
Requiere: Lista inicializada
Modifica: Lista, NumElem

*/
void ListaOrdenadaArreglo::Vaciar()
{
    ultimoLleno = -1;
}

/**
Nombre: Vacia
Parámetros: L
Efecto: Devuelve true si la lista esta vacia o false si no lo esta
Requiere: Lista inicializada
Modifica:

*/
bool ListaOrdenadaArreglo::Vacia()
{
    if(ultimoLleno == -1){
        return true;
    }
    else{
        return false;
    }
}

/**
Nombre: Agregar
Parámetros: L, elemento e
Efecto: Inserta el elemento e en orden
Requiere: Lista inicializada, e no debe estar en la lista
Modifica: Lista, NumElem

*/
void ListaOrdenadaArreglo::Agregar(elemento e)
{
	if (ultimoLleno == -1)
	{
		arreglo[0] = e;
		ultimoLleno++;
	}
	else
	{
		int i = 0;
		while (arreglo[i] != posNula && arreglo[i] < e)
		{
			i++;
		}
		if (arreglo[i] > e)
		{
			int j = ultimoLleno + 1;
			while (j > i)
			{
				arreglo[j] = arreglo[j - 1];
				j--;
			}
			arreglo[i] = e;
			ultimoLleno++;
		}
		else
		{
			arreglo[i] = e;
			ultimoLleno++;
		}
	}
}

/**
Nombre: Borrar
Parámetros: L, elemento e
Efecto: Borra el elemento e de la lista
Requiere: Lista inicializada, e debe estar en la lista
Modifica: Lista, NumElem

*/

void ListaOrdenadaArreglo::Borrar(elemento e)
{
    int i=0;
    while(arreglo[i] !=e)
    {
        i++;

    }
    if(arreglo[i] == e)
    {
        int p = i;
        while(p < ultimoLleno)
        {
            arreglo[p] = arreglo[p+1];
            p++;

        }
        ultimoLleno--;
    }

}

/**
Nombre: Primero
Parámetros: L
Efecto: Retorna el primer elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaArreglo::Primero()
{
    return arreglo[0];
}

/**
Nombre: Siguiente
Parámetros: L, elemento e
Efecto: Devuelve el siguiente elemento despues del elemento e en la lista
Requiere: Lista inicializada, e debe estar en la lista
Modifica:

*/
elemento ListaOrdenadaArreglo::Siguiente(elemento e)
{
    int p = 0;
    while(arreglo[p]!= e)
    {
        p++;
    }
    if(arreglo[p] == e)
    {
        return arreglo[p+1];
    }
	return -1;
}

/**
Nombre: Ultimo
Parámetros: L
Efecto: Devuelve el ultimo elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaArreglo::Ultimo()
{
    return arreglo[ultimoLleno];
}

/**
Nombre: Anterior
Parámetros: L, elemento e
Efecto: Devuelve el elemento anterior al elemento e en la lista
Requiere: Lista inicializada, e debe estar en la lista
Modifica:

*/
elemento ListaOrdenadaArreglo::Anterior(elemento e)
{
    int p = 0;
    while(arreglo[p]!= e)
    {
        p++;
    }
    if(arreglo[p] == e)
    {
        return arreglo[p-1];
    }
	return -1;
}


/**
Nombre: NumElem
Parámetros: L
Efecto: Devuelve un entero con la cantidad de elementos en la lista
Requiere: Lista inicializada
Modifica:

*/
int ListaOrdenadaArreglo::NumElem()
{
    return ultimoLleno+1;
}

void ListaOrdenadaArreglo::Listar()
{
    int i=0;
    cout<< "Los elementos en la lista son: " ;
    while(i != ultimoLleno+1)
    {
        cout<< arreglo[i] << " ";
        i++;
    }
    cout<<endl;
}
