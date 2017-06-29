#ifndef COLADEPRIORIDAD_H
#define COLADEPRIORIDAD_H
//#include <tuple>
#define tamano 70
#include "Par.h"

#include <iostream>


using namespace std;

template <class T>
class ColaDePrioridad
{
public:
    ColaDePrioridad();
    virtual ~ColaDePrioridad();
    void Crear();
    void Destruir();
    void Vaciar();
    bool Vacio();
    void Agregar(T,int);
    T Sacar();
    void ModificarPrioridad(T,int);
    int NumElem();
    Par<T,T> heap[tamano];
    int ultimo;
    int cantidad;



protected:

private:
};

template <class T>
ColaDePrioridad<T>::ColaDePrioridad()
{
    Par<T,int> par(0,0);
    heap[0] = par;

}
template <class T>
ColaDePrioridad<T>::~ColaDePrioridad()
{

}
template <class T>
void ColaDePrioridad<T>::Crear()
{
    ultimo = -1;
}
template <class T>
void ColaDePrioridad<T>::Destruir()
{
    //delete heap;
}
template <class T>
void ColaDePrioridad<T>::Vaciar()
{

    ultimo = -1;
}
template <class T>
bool ColaDePrioridad<T>::Vacio()
{
    if (ultimo == -1 || ultimo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void ColaDePrioridad<T>::Agregar(T elem, int priori)
{
    Par<T,int> par(elem, priori);
    if(ultimo == -1)
    {
        heap[1] = par;
        ultimo +=2;
        cantidad++;
    }
    else
    {
        ultimo++;
        heap[ultimo] = par;
        int tem = ultimo;
        while(heap[tem/2].GetPrioridad() >= heap[tem].GetPrioridad())
        {
            if(heap[tem/2].GetPrioridad() == heap[tem].GetPrioridad())
            {
                auto espe = heap[(tem/2)+1];
                heap[(tem/2)+1] = heap[tem];
                heap[tem] = espe;
                tem = tem/2;
            }
            else
            {
                auto espe = heap[tem/2];
                heap[tem/2] = heap[tem];
                heap[tem] = espe;
                tem = tem/2;
            }
        }
        cantidad++;
    }
}

template <class T>
T ColaDePrioridad<T>::Sacar()
{

        Par <T,int> fuera = heap[1];
        heap[1] = heap[ultimo];
        ultimo--;
        int pos = 1;
        while((heap[pos].GetPrioridad() > heap[pos*2].GetPrioridad() || heap[pos].GetPrioridad() > heap[(pos*2)+1].GetPrioridad()) && (pos*2)+1 <= NumElem())
        {
            if (heap[pos*2].GetPrioridad() < heap[(pos*2)+1].GetPrioridad())
            {
                auto espe = heap[pos];
                heap[pos] = heap[pos*2];
                heap[pos*2] = espe;
                pos = pos*2;
            }
            else
            {
                auto espe = heap[pos];
                heap[pos] = heap[(pos*2)+1];
                heap[(pos*2)+1] = espe;
                pos = (pos*2)+1;
            }
        }
        //if()
        return fuera.GetDato();
}

template <class T>
void ColaDePrioridad<T>::ModificarPrioridad(T elem, int priori)
{
    for(int i = 1; i <= ultimo; i++)
    {
        if((heap[i].GetDato()) == elem)
        {
            heap[i].prioridad = priori;
            while(heap[i/2].GetPrioridad() >= heap[i].GetPrioridad())
            {
                if(heap[i/2].GetPrioridad() == heap[i].GetPrioridad())
                {
                    auto espe = heap[(i/2)+1];
                    heap[(i/2)+1] = heap[i];
                    heap[i] = espe;
                    i = i/2;
                }
                else
                {
                    auto espe = heap[i/2];
                    heap[i/2] = heap[i];
                    heap[i] = espe;
                    i = i/2;
                }
            }
        }
    }

}
template <class T>
int ColaDePrioridad<T>::NumElem()
{
    return cantidad;
}


#endif // COLADEPRIORIDAD_H
