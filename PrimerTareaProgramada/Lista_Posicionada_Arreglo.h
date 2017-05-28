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
    Lista_Posicionada_Arreglo() {}
    ~Lista_Posicionada_Arreglo() {}
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

    protected:

    private:
};

#endif // LISTA_POSICIONADA_ARREGLO_H

//std::array<elemento, 30> Lista;
elemento Lista[30];
int numElementos;

void Lista_Posicionada_Arreglo::iniciar() {
    numElementos = 0;
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
        if (numElementos-1 >= p) {
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
