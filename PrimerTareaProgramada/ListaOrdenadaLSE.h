#ifndef LISTAORDENADALSE_H
#define LISTAORDENADALSE_H
#include "Posicion.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

typedef Posicion* posicion;
class ListaOrdenadaLSE
{
public:
    ListaOrdenadaLSE() {}
    virtual ~ListaOrdenadaLSE() {}
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
    int NumElem();
    void Listar();
    Posicion *posNula;
    int numElem;
    bool vacia;
    Posicion *primera;


protected:

private:
};

#endif // ListaOrdenadaLSE_H



/**
Nombre: Iniciar
Parámetros: L
Efecto: Inicializa la lista
Requiere: Lista no inicializada
Modifica:

*/
void ListaOrdenadaLSE::Iniciar()
{
    numElem = 0;
    posNula = 0;
    primera = 0;
    vacia = true;
}

/**
Nombre: Destruir
Parámetros: L
Efecto: Destruye la lista
Requiere: Lista inicializada
Modifica:

*/
void ListaOrdenadaLSE::Destruir()
{
    Posicion *p1 = primera;
    while(numElem != 0)
    {
        Posicion *aux = p1->siguiente;
        p1->siguiente = posNula;
        primera = aux;
        delete p1;
        p1 = primera;
        numElem--;
    }
    cout << "Lista destruida" <<endl;

}

/**
Nombre: Vaciar
Parámetros: L
Efecto: Elimina los elementos dentro de una Lista
Requiere: Lista inicializada
Modifica: Lista, NumElem

*/
void ListaOrdenadaLSE::Vaciar()
{
    Posicion *p1 = primera;
    while(numElem != 0)
    {
        Posicion *aux = p1->siguiente;
        p1->siguiente = posNula;
        primera = aux;
        delete p1;
        p1 = primera;
        numElem--;
    }
    primera = 0;
    vacia = true;
    numElem = 0;

}

/**
Nombre: Vacia
Parámetros: L
Efecto: Devuelve true si la lista esta vacia o false si no lo esta
Requiere: Lista inicializada
Modifica:

*/
bool ListaOrdenadaLSE::Vacia()
{
    return vacia;
}

/**
Nombre: Agregar
Parámetros: L, elemento e
Efecto: Inserta el elemento e en orden
Requiere: Lista inicializada, e no debe estar en la lista
Modifica: Lista, NumElem

*/
void ListaOrdenadaLSE::Agregar(elemento e)
{
    Posicion *nueva = new Posicion;
	Posicion *p1 = primera;
    if(vacia == true)
    {
        numElem = 1;
        nueva->elem = e;
        nueva->siguiente = posNula;
        primera = nueva;
        vacia = false;
    }
    else
    {
        if(p1->siguiente == posNula && p1->elem <e)
        {
            nueva->elem = e;
            nueva->siguiente = p1->siguiente;
            p1->siguiente = nueva;
            numElem++;
        }
        else if(p1->elem > e)
        {
            nueva->elem = e;
            nueva->siguiente = p1;
            primera = nueva;
            numElem++;

        }
        else
        {
            while(p1->siguiente != posNula && p1->elem <e && p1->siguiente->elem <e)
            {
                p1 = p1->siguiente;
            }
            if(p1->siguiente != posNula && p1->elem <e && p1->siguiente->elem >e)
            {
                nueva->elem = e;
                nueva->siguiente = p1->siguiente;
                p1->siguiente = nueva;
                numElem++;
            }
            else if(p1->siguiente == posNula)
            {
                nueva->elem = e;
                nueva->siguiente = p1->siguiente;
                p1->siguiente = nueva;
                numElem++;

            }

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
void ListaOrdenadaLSE::Borrar(elemento e)
{
    Posicion *p1 = primera;
    if(p1->elem == e && numElem == 1)
    {
        delete p1;
        primera = 0;
        numElem--;
        vacia = true;
    }
    else if(p1->elem == e && numElem >1)
    {
        Posicion *aux = p1->siguiente;
        p1->siguiente = posNula;
        primera = aux;
        delete p1;
        numElem--;
    }
    else if(p1->elem != e && numElem >1)
    {
        while(p1->siguiente != posNula && p1->siguiente->elem != e)
        {
            p1= p1->siguiente;
        }
        if(p1->siguiente->elem == e)
        {
            Posicion *borrar = p1->siguiente;
            Posicion *aux = borrar->siguiente;
            p1->siguiente = aux;
            delete borrar;
            numElem--;
        }
    }

}


/**
Nombre: Primero
Parámetros: L
Efecto: Retorna el primer elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaLSE::Primero()
{
    return primera->elem;
}

/**
Nombre: Siguiente
Parámetros: L, elemento e
Efecto: Devuelve el siguiente elemento despues del elemento e en la lista
Requiere: Lista inicializada, e debe estar en la lista
Modifica:

*/
elemento ListaOrdenadaLSE::Siguiente(elemento e)
{
    Posicion *p = primera;
    while(p->elem!= e && p->siguiente != posNula)
    {
        p = p->siguiente;
    }
    if(p->elem == e && p->siguiente != posNula)
    {
        return p->siguiente->elem;
    }
}

/**
Nombre: Ultimo
Parámetros: L
Efecto: Devuelve el ultimo elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaLSE::Ultimo()
{
    Posicion *p1 = primera;
    while(p1->siguiente != posNula)
    {
        p1= p1->siguiente;
    }
    if(p1->siguiente == posNula)
    {
        return p1->elem;
    }

}

/**
Nombre: Anterior
Parámetros: L, elemento e
Efecto: Devuelve el elemento anterior al elemento e en la lista
Requiere: Lista inicializada, e debe estar en la lista
Modifica:

*/
elemento ListaOrdenadaLSE::Anterior(elemento e)
{
    Posicion *p1 = primera;
    while(p1->siguiente->elem != e)
    {
        p1 = p1->siguiente;
    }
    if(p1->siguiente->elem == e)
    {
        return p1->elem;
    }
}


/**
Nombre: NumElem
Parámetros: L
Efecto: Devuelve un entero con la cantidad de elementos en la lista
Requiere: Lista inicializada
Modifica:

*/
int ListaOrdenadaLSE::NumElem()
{
    return numElem;
}

/**
Nombre: Listar
Parámetros: L
Efecto: Imprime la lista
Requiere: Lista inicializada
Modifica:

*/
void ListaOrdenadaLSE::Listar()
{
    Posicion *p = primera;
    int i = 0;
    if(numElem == 0)
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        cout << "Los elementos en la lista son: ";
        while(i!=numElem)
        {
            cout<< p->elem << " ";
            p = p->siguiente;
            i++;
        }
        cout << endl;
    }
}

