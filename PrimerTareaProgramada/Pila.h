#ifndef PILA_H
#define PILA_H

typedef int elemento;

class Pila {
public:
    void iniciar();

    void destruir();

    void vaciar();

    bool vacia();

    void poner(elemento e);

    elemento quitar();

    elemento tope();

    int numElem();


private:

    struct Nodo {
        elemento dato;
        Nodo* sgt;

        Nodo(elemento x) : dato(x), sgt(0) {
        };
    };
    Nodo* Tope;
};

#endif /* PILA_H */


void Pila::iniciar() {
    Tope = 0;
}

void Pila::destruir() {
    Nodo* p = Tope;
    Nodo* q = 0;
    while (p != 0) {
        q = p->sgt;
        delete p;
        p = q;
    }
}

void Pila::vaciar() {
    Nodo* p = Tope;
    Nodo* q = 0;
    while (p != 0) {
        q = p->sgt;
        delete p;
        p = q;
    }
    Tope = 0;
}

bool Pila::vacia() {
    bool vacio = false;
    if (Tope == 0) {
        vacio = true;
    }
    return vacio;
}

void Pila::poner(elemento e) {
    Nodo* nuevo = new Nodo(e);
    nuevo->sgt = Tope;
    Tope = nuevo;
}

elemento Pila::quitar() {
    Nodo* q = Tope;
    Tope = Tope->sgt;
    elemento eliminado = q->dato;
    delete q;
    return eliminado;
}

elemento Pila::tope() {
    return Tope->dato;
}

int Pila::numElem() {
    int contador = 0;
    Nodo* q = Tope;
    while (q != 0) {
        contador++;
        q = q->sgt;
    }
    return contador;
}

