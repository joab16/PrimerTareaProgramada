#ifndef LISTA_POSICIONADA_SE_H
#define LISTA_POSICIONADA_SE_H
using namespace std;

typedef int elemento;

struct NodoS {
    elemento dato;
    NodoS* sgt;

    NodoS(elemento x) : dato(x), sgt(0) {
    };
};
typedef NodoS* posS;

class Lista_Posicionada_SE {
public:
    Lista_Posicionada_SE() {}
    ~Lista_Posicionada_SE() {}
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
    void insertar(elemento e, posS p);

    //EFE: Agrega el elemento e al final de la Lista L
    //REQ: L inicializada
    //MOD: L
    void agregarAlFinal(elemento e);

    //EFE: Borra el elemento de la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD: L
    void borrar(posS p);

    //EFE: Devuelve el elemento de la posicion p en la lIsta L
    //REQ: L inicializada y p valida
    //MOD:
    elemento recuperar(posS p);

    //EFE: Modifica el elemento de la posicion p por el elemento e en la Lista L
    //REQ: L inicializada y p valida
    //MOD: L
    void modificarElemento(elemento e, posS p);

    //EFE: Intercambia los elementos de las posiciones p1 y p2 de la Lista L
    //REQ: L inicializada y p1 p2 validos
    //MOD: L
    void intercambiar(posS p1, posS p2);

    //EFE: Devuelve la primer posicion de la Lista L
    //REQ: L inicializada
    //MOD:
    posS primera();

    //EFE: Devuelve la ultima posicion de la Lista L
    //REQ: L inicializada
    //MOD:
    posS ultima();

    //EFE: Devuelve la posicion siguiente a la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD:
    posS siguiente(posS p);

    //EFE: Devuelve la posicion anterior a la posicion p de la Lista L
    //REQ: L inicializada y p valida
    //MOD:
    posS anterior(posS p);

    //EFE: Devuelve el numero de elementos en la lista L
    //REQ: L inicializada
    //MOD:
    int numElem();

    protected:

    private:
        NodoS* inicio;
};

#endif // LISTA_POSICIONADA_SE_H

void Lista_Posicionada_SE::iniciar() {
    inicio = 0;
}

void Lista_Posicionada_SE::destruir() {
    NodoS* p = inicio;
    NodoS* q = 0;
    while(p != 0){
        q = p->sgt;
        delete p;
        p = q;
    }
}

void Lista_Posicionada_SE::vaciar() {
    NodoS* p = inicio;
    NodoS* q = 0;
    while(p != 0){
        q = p->sgt;
        delete p;
        p = q;
    }
    inicio = 0;
}

bool Lista_Posicionada_SE::vacia() {
    bool vacia = false;
    if (inicio == 0) {
        vacia = true;
    }
    return vacia;
}

void Lista_Posicionada_SE::insertar(elemento e, posS p) {
    posS q = inicio;
    bool insertado = false;
    while (!insertado) {
        if (p == q->sgt) {
            posS aux = q->sgt;
            q->sgt = new NodoS(e);
            q->sgt->sgt = aux;
            insertado = true;
        } else {
            q = q->sgt;
        }
    }
}

void Lista_Posicionada_SE::agregarAlFinal(elemento e) {
    if (inicio == 0) {
        inicio = new NodoS(e);
    } else {
        bool agregado = false;
        posS p = inicio;
        while (!agregado) {
            if (p->sgt == 0) {
                p->sgt = new NodoS(e);
                agregado = true;
            } else {
                p = p->sgt;
            }
        }
    }
}

void Lista_Posicionada_SE::borrar(posS p) {
    posS q = inicio;
    if (q == p) {
        inicio = q->sgt;
        delete q;
    } else {
        bool borrado = false;
        while (!borrado) {
            if (q->sgt == p) {
                delete q->sgt;
                q->sgt = q->sgt->sgt;
                borrado = true;
            } else {
                q = q->sgt;
            }
        }
    }
}

elemento Lista_Posicionada_SE::recuperar(posS p) {
    elemento recuperado = p->dato;
    return recuperado;
}

void Lista_Posicionada_SE::modificarElemento(elemento e, posS p) {
    p->dato = e;
}

void Lista_Posicionada_SE::intercambiar(posS p1, posS p2) {
    elemento aux = p1->dato;
    p1->dato = p2->dato;
    p2->dato = aux;
}

posS Lista_Posicionada_SE::primera() {
    return inicio;
}

posS Lista_Posicionada_SE::ultima() {
    posS posicion = inicio;
    while (!(posicion->sgt == 0)) {
        posicion = posicion->sgt;
    }
    return posicion;
}

posS Lista_Posicionada_SE::siguiente(posS p) {
    return p->sgt;
}

posS Lista_Posicionada_SE::anterior(posS p) {
    bool encontrado = false;
    posS anterior = inicio;
    while (!encontrado) {
        if (anterior->sgt == p) {
            encontrado = true;
        } else {
            anterior = anterior->sgt;
        }
    }
    return anterior;
}

int Lista_Posicionada_SE::numElem() {
    posS p = inicio;
    int numElementos = 0;
    while (p != 0) {
        numElementos++;
        p = p->sgt;
    }
    return numElementos;
}


