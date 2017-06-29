#ifndef CONJUNTODECONJUNTOS_H
#define CONJUNTODECONJUNTOS_H

#include "Conjunto.h"
#include <list>
#include <iostream>
#include <stdlib.h>

using namespace std;

class ConjuntodeConjuntos
{
    public:
        ConjuntodeConjuntos();
        //virtual ~ConjuntodeConjuntos();
        void Crear();
        void Destruir();
        void Vaciar ();
        bool Vacio();
        void AgregarElementoAConjunto(elemento, int);
        void EliminarElemento(elemento);
        elemento ConjuntoAlQuePertenece(elemento);
        void AgregarConjunto(Conjunto);
        void EliminarConjunto(int);
        void UnirConjuntos(int, int);
        int NumConjuntos();

        void ImprimirConjuntos();


        int numConj;
        bool pertenece;
        std::list<Conjunto>CC;
        std::list<Conjunto>::iterator it;

    protected:

    private:
};
ConjuntodeConjuntos::ConjuntodeConjuntos()
{
    numConj = 0;
}
void ConjuntodeConjuntos::Crear()
{
    ConjuntodeConjuntos();
}
void ConjuntodeConjuntos::Destruir()
{
    CC.clear();
}
void ConjuntodeConjuntos::Vaciar ()
{
    CC.clear();
}
bool ConjuntodeConjuntos::Vacio()
{
    if (numConj == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ConjuntodeConjuntos::AgregarElementoAConjunto(elemento elem, int numDelConjunto)
{
    it = CC.begin();
    int contador = 1;
    while (contador < numDelConjunto)
    {
        it++;
    }
    it->conjunto.push_back(elem);
}
void ConjuntodeConjuntos::EliminarElemento(elemento elem)
{
    std::list<elemento> c;
    std::list<elemento>::iterator itC;
    bool encontrado = false;
    it = CC.begin();
    while ( (!encontrado) && (it != CC.end()) )
    {
        c = it->conjunto;

        itC = c.begin();
        while ( (!encontrado) && (itC != c.end()) )
        {
            if (*itC == elem)
            {
                it->conjunto.remove(elem);
                encontrado = true;
            }
            else {
                itC++;
            }
        }
        it++;
    }
}
elemento ConjuntodeConjuntos::ConjuntoAlQuePertenece(elemento elem)
{
    std::list<elemento> c;
    std::list<elemento>::iterator itC;
    bool encontrado = false;
    int numeroDelConjunto = 1;
    it = CC.begin();
    while ( (!encontrado) && (it != CC.end()) )
    {
        c = it->conjunto;
        itC = c.begin();
        while ((itC != c.end()) && (!encontrado) )
        {
            if (*itC == elem)
            {
                encontrado = true;
            }
            else {
                itC++;
            }
        }
        it++;
        numeroDelConjunto++;
    }
    return numeroDelConjunto;
}
void ConjuntodeConjuntos::AgregarConjunto(Conjunto conj)
{
    CC.push_back(conj);
    numConj++;
    conj.SetNumeroDelConjunto(numConj);
}
void ConjuntodeConjuntos::EliminarConjunto(int numConjunto)
{
    it = CC.begin();
    int contador = 1;
    while (contador < numConjunto)
    {
        it++;
    }
    CC.erase(it);
    numConjunto--;
}
void ConjuntodeConjuntos::UnirConjuntos(int Conjunto1, int Conjunto2)
{

    it = CC.begin();
    std::list<Conjunto>::iterator it2 = CC.begin();
    int posicionActual = 1;
    int posicionActual2 = 1;
    while (posicionActual < Conjunto1)
    {
        it++;
        posicionActual++;
    }
    while(posicionActual2 < Conjunto2)
    {
        it2++;
        posicionActual2++;
    }
    std::list<elemento> c;
    c = it2->conjunto;
    std::list<elemento>::iterator itC = c.begin();
    while(itC != c.end())
    {
        it->conjunto.push_back(*itC);
        itC++;
    }
    CC.erase(it2);
    numConj--;
}
int ConjuntodeConjuntos::NumConjuntos()
{
    return numConj;
}
void ConjuntodeConjuntos::ImprimirConjuntos()
{
    std::list<elemento> c;
    std::list<elemento>::iterator itC;
    it = CC.begin();
    while (it != CC.end())
    {
        c = it->conjunto;
        itC = c.begin();
        while (itC != c.end())
        {
            cout << *itC << " ";
            itC++;
        }
        cout << endl;
        it++;
    }
}
#endif // CONJUNTO DE CONJUNTOS_H
