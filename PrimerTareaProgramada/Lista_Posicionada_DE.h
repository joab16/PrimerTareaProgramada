#ifndef LISTA_POSICIONADA_DE_H
#define LISTA_POSICIONADA_DE_H
using namespace std;
typedef int elemento;

struct Nodo {
    elemento dato;
    Nodo* sgt;
    Nodo* ant;

    Nodo(elemento x) : dato(x), sgt(0), ant(0) {
    };
};
typedef Nodo* pos;

class Lista_Posicionada_DE {
public:
    Lista_Posicionada_DE() {}
    ~Lista_Posicionada_DE() {}
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
    void insertar(elemento e, pos p);

    //EFE: Agrega el elemento e al final de la Lista L
    //REQ: L inicializada
    //MOD: L
    void agregarAlFinal(elemento e);

    //EFE: Borra el elemento de la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD: L
    void borrar(pos p);

    //EFE: Devuelve el elemento de la posicion p en la lIsta L
    //REQ: L inicializada y p valida
    //MOD:
    elemento recuperar(pos p);

    //EFE: Modifica el elemento de la posicion p por el elemento e en la Lista L
    //REQ: L inicializada y p valida
    //MOD: L
    void modificarElemento(elemento e, pos p);

    //EFE: Intercambia los elementos de las posiciones p1 y p2 de la Lista L
    //REQ: L inicializada y p1 p2 validos
    //MOD: L
    void intercambiar(pos p1, pos p2);

    //EFE: Devuelve la primer posicion de la Lista L
    //REQ: L inicializada
    //MOD:
    pos primera();

    //EFE: Devuelve la ultima posicion de la Lista L
    //REQ: L inicializada
    //MOD:
    pos ultima();

    //EFE: Devuelve la posicion siguiente a la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD:
    pos siguiente(pos p);

    //EFE: Devuelve la posicion anterior a la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD:
    pos anterior(pos p);

    //EFE: Devuelve el numero de elementos en la lista L
    //REQ: L inicializada
    //MOD:
    int numElem();

    protected:

    private:
        Nodo* inicio;
};

#endif // LISTA_POSICIONADA_DE_H

void Lista_Posicionada_DE::iniciar() {
    inicio = 0;
}

void Lista_Posicionada_DE::destruir() {
    Nodo* p = inicio;
    Nodo* q = 0;
    while (p != 0) {
        q = p->sgt;
        delete p;
        p = q;
    }
}

void Lista_Posicionada_DE::vaciar() {
    Nodo* p = inicio;
    Nodo* q = 0;
    while (p != 0) {
        q = p->sgt;
        delete p;
        p = q;
    }
    inicio = 0;
}

bool Lista_Posicionada_DE::vacia() {
    bool vacia = false;
    if (inicio == 0) {
        vacia = true;
    }
    return vacia;
}

void Lista_Posicionada_DE::insertar(elemento e, pos p) {
    if (p == inicio) {
        inicio->ant = new Nodo(e);
        (inicio->ant)->sgt = inicio;
        inicio = inicio->ant;
    } else {
        p->ant->sgt = new Nodo(e);
        p->ant = p->ant->sgt;
    }
}

void Lista_Posicionada_DE::agregarAlFinal(elemento e) {
    if (inicio == 0) {
        inicio = new Nodo(e);
    } else {
        bool agregado = false;
        pos p = inicio;
        while (!agregado) {
            if (p->sgt == 0) {
                p->sgt = new Nodo(e);
                p->sgt->ant = p;
                agregado = true;
            } else {
                p = p->sgt;
            }
        }
    }
}

void Lista_Posicionada_DE::borrar(pos p) {
    if (inicio == p) {
        inicio = p->sgt;
        delete p;
    } else {
        (p->ant)->sgt = p->sgt;
        (p->sgt)->ant = p->ant;
        delete p;
    }
}

elemento Lista_Posicionada_DE::recuperar(pos p) {
    elemento recuperado = p->dato;
    return recuperado;
}

void Lista_Posicionada_DE::modificarElemento(elemento e, pos p) {
    p->dato = e;
}

void Lista_Posicionada_DE::intercambiar(pos p1, pos p2) {
    elemento aux = p1->dato;
    p1->dato = p2->dato;
    p2->dato = aux;
}

pos Lista_Posicionada_DE::primera() {
    return inicio;
}

pos Lista_Posicionada_DE::ultima() {
    pos posicion = inicio;
    while (!(posicion->sgt == 0)) {
        posicion = posicion->sgt;
    }
    return posicion;
}

pos Lista_Posicionada_DE::siguiente(pos p) {
    return p->sgt;
}

pos Lista_Posicionada_DE::anterior(pos p) {
    return p->ant;
}

int Lista_Posicionada_DE::numElem() {
    pos p = inicio;
    int numElementos = 0;
    while (p != 0) {
        numElementos++;
        p = p->sgt;
    }
    return numElementos;
}
