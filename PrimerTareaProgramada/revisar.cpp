#include <iostream>
#include "GrafoMatrizDeAdyacencia.h"
//#include "GrafoLSE.h"

#include <limits>
#include "include/ColaDePrioridad.h"
#include "Diccionario.h"
#include "Conjunto de Conjuntos.h"
#include "Dupletas.h"
using namespace std;
void menu();
int contador = 0;

void ProfPrimero(vertice v);
bool AveriguarCiclos(vertice v);
void Floyd();
void Dijkstra(vertice v, Diccionario<vertice> D);
void Vendedor(vertice v);
void Kruskal(ConjuntodeConjuntos vertices, ColaDePrioridad<Par<vertice,vertice>> aristas);
void Prim();
void ColorearVertice(Grafo grafo, vertice v);
int color;
int i;
ConjuntodeConjuntos VerticesColoreados;
ConjuntodeConjuntos VerticesAdyacentes;
Diccionario <vertice> diccionarioVerticesVisitados;
std::vector<vertice> SolucionActual;
std::vector<vertice> SolucionMejor;
std::vector<Par<vertice,int>> Colores;
Diccionario<vertice> d;
Diccionario<vertice> verticesRecorridos;
//Diccionario<Par<vertice,vertice>> aristas;
Grafo grafo;

bool ciclo = false;

int costos[20];
vertice mapeo[20];

int costosF[20][20];
vertice maVert[20][20];
int adyacentes[20][20];
vertice mapa[20];

std::vector<vertice>::iterator it;
int menorCosto;
int costoActual;
int contadorV;
int costo;

std::vector<Dupletas> conjuntoAristas;
int menorPeso;

vertice Buscar(string etiqueta);

int imax = std::numeric_limits<int>::max();


int main()
{
    // Grafo hecho //
    grafo.Iniciar();
    grafo.AgregarVertice("a");
    grafo.AgregarVertice("b");
    grafo.AgregarVertice("c");
    grafo.AgregarVertice("d");
    grafo.AgregarVertice("e");
    grafo.AgregarArista(0,1,1);
    grafo.AgregarArista(0,2,3);
    grafo.AgregarArista(0,3,31);
    grafo.AgregarArista(1,2,4);
    grafo.AgregarArista(1,3,7);
    grafo.AgregarArista(2,4,8);
    grafo.AgregarArista(3,4,42);
    //             //
    //Prim();
    //ProfPrimero(0);
    //Vendedor(0);
    //cout << menorCosto << endl;

    menu();
    //Floyd();
    return 0;
}

void menu()
{
    int salida = 0;

    string vertic;
    string etiq;
    vertice vert;
    vertice vert2;
    int peso;
    while(salida != -1)
    {
        cout << "                   Que desea utilizar" << endl;
        cout << "Operadores basicos: 1 = Agregar Vertice, 2 = Eliminar Vertice, 3 = Modificar Etiqueta,\n 4 = Etiqueta, 5 = Agregar Arista, 6 = Eliminar Arista,\n 7 = Modificar Peso, 8 = Peso, 9 = Adyacentes,\n 10 = Primer Vertice, 11 = SiguienteVertice, 12 = Primer Vertice Adyacente,\n 13 = Siguiente Vertice Adyacente" << endl;
        cout << "Algoritmos: 14 = Averiguar si el grafo tiene ciclos, 15 = Dijkstra, 16 = Floyd,\n 17 = Vendedor" << endl;
        cin >> salida;
        switch(salida)
        {
        case 1:
            cout << "Que etiqueta le quieres poner al vertice?" << endl;
            cin >> vertic;
            grafo.AgregarVertice(vertic);
            break;
        case 2:
            cout << "Que vertice desea eliminar?" << endl;
            cin >> vertic;
            vert = Buscar(vertic);
            grafo.EliminarVertice(vert);
            break;
        case 3:
            cout << "A cual vertice desea cambiarle su etiqueta?" << endl;
            cin >> vertic;
            cout << "Cual etiqueta desea ponerle?" << endl;
            cin >> etiq;
            vert = Buscar(vertic);
            grafo.ModificarEtiqueta(vert, etiq);
            break;
        case 4:
            cout << "De que vertice desea saber la etiqueta?" << endl;
            cin >> vertic;
            vert = Buscar(vertic);
            grafo.Etiqueta(vert);
            break;
        case 5:
            cout << "De que vertice a que vertice desea agregar una arista?" << endl;
            cout << "Vertice salida: ";
            cin >> vertic;
            cout << "Vertice entrada: ";
            cin >> etiq;
            cout << "Que peso desea ponerle?" << endl;
            cin >> peso;
            vert = Buscar(vertic);
            vert2 = Buscar(etiq);
            grafo.AgregarArista(vert,vert2,peso);
            break;
        case 6:
            cout << "La arista de que vertice a que vertice desea eliminar?" << endl;
            cout << "Vertice salida: ";
            cin >> vertic;
            cout << "Vertice entrada: ";
            cin >> etiq;
            vert = Buscar(vertic);
            vert2 = Buscar(etiq);
            grafo.EliminarArista(vert,vert2);
            break;
        case 7:
            cout << "A que aristas le desea modificar el peso?" << endl;
            cout << "Vertice salida: ";
            cin >> vertic;
            cout << "Vertice entrada: ";
            cin >> etiq;
            cout << "Que peso desea ponerle?" << endl;
            cin >> peso;
            vert = Buscar(vertic);
            vert2 = Buscar(etiq);
            grafo.ModificarPeso(vert,vert2,peso);
            break;
        case 8:
            cout << "De cual arista desea saber el peso?" << endl;
            cout << "Vertice salida: ";
            cin >> vertic;
            cout << "Vertice entrada: ";
            cin >> etiq;
            vert = Buscar(vertic);
            vert2 = Buscar(etiq);
            grafo.Peso(vert,vert2);
            break;
        case 9:
            cout << "Que vertices desea averiguar si son adyacentes?" << endl;
            cout << "Vertice salida: ";
            cin >> vertic;
            cout << "Vertice entrada: ";
            cin >> etiq;
            vert = Buscar(vertic);
            vert2 = Buscar(etiq);
            if(grafo.Adyacentes(vert,vert2) == true)
            {
                cout << "Los vertices " << vertic << ", " << etiq << " son adyacentes" << endl;
            }
            else
            {
                cout << "Los vertices " << vertic << ", " << etiq << " no son adyacentes" << endl;
            }
            break;
        case 10:
            cout << "El primer vertice es: " << grafo.Etiqueta(grafo.PrimerVertice()) <<  endl;
            break;
        case 11:
            cout << "A partir de cual vertice desea averigurar el siguiente?" << endl;
            cin >> vertic;
            vert = Buscar(vertic);
            cout << "El siguiente vertice a partir de: " << grafo.Etiqueta(vert) << " es: " << grafo.Etiqueta(grafo.SiguienteVertice(vert)) << endl;
            break;
        case 12:
            cout << "De que vertice desea averiguar su primer vertice adyacente?" << endl;
            cin >> vertic;
            vert = Buscar(vertic);
            cout << "El primer vertice adyacente de" << grafo.Etiqueta(vert) <<  "es: " << grafo.Etiqueta(grafo.PrimerVerticeAdyacente(vert)) <<  endl;
            break;
        case 13:
            cout << "Que vertice desea eliminar?" << endl;
            cout << "Vertice salida: ";
            cin >> vertic;
            vert = Buscar(vertic);
            cout << "Vertice adyacente a" << grafo.Etiqueta(vert) << ": ";
            cin >> etiq;
            vert2 = Buscar(etiq);
            cout << "El siguiente vertice adyacente de " << grafo.Etiqueta(vert) << " despues de: " << grafo.Etiqueta(vert2) << " es: " << grafo.Etiqueta(grafo.SiguienteVerticeAdyacente(vert,vert2));
            break;
        case 14:
            verticesRecorridos.Crear();
            cout << "A partir de cual vertice desea empezar la busqueda de un ciclo?" << endl;
            cin >> vertic;
            vert = Buscar(vertic);
            ProfPrimero(vert);
            if(ciclo == true)
            {
                cout << "El grafo tiene un ciclo" << endl;
            }
            else
            {
                cout << "El grafo no tiene un ciclo" << endl;
            }

            break;
        case 15:
            cout << "Desde cual vertice desea saber el menor costo con respecto a todos los demas?" << endl;
            cin >> vertic;
            vert = Buscar(vertic);
            Dijkstra(vert,d);
            for(int i = 0; i < grafo.NumVertices(); i++)
            {
                if(mapeo[i] != vert)
                {
                    cout << "El camino de menor costo de " << grafo.Etiqueta(vert) << " hasta " << grafo.Etiqueta(mapeo[i]) << " es: " << costos[i] << endl;
                }

            }

            break;
        case 16:
            Floyd();
            for(int i = 0; i<grafo.NumVertices(); i++)
            {
                for(int j = 0; j<grafo.NumVertices(); j++)
                {
                    if(i != j)
                    {
                        cout << "El camino de menor costo de " << grafo.Etiqueta(mapa[i]) << " hasta " << grafo.Etiqueta(mapa[j]) << " es: " << costosF[i][j] << endl;
                    }
                }
            }

            break;
        case 17:
            cout << "A partir de cual vertice desea empezar Vendedor?" << endl;
            cin >> vertic;
            vert = Buscar(vertic);
            menorCosto = -1;
            costoActual = 0;
            contadorV = 0;
            SolucionActual.clear();
            SolucionMejor.clear();
            Vendedor(vert);
            cout << "La mejor solucion es: ";
            cout << grafo.Etiqueta(vert) << " -> ";
            for(it=SolucionMejor.begin(); it < SolucionMejor.end(); it++)
            {
                cout << grafo.Etiqueta(*it) << " -> ";
            }
            cout << grafo.vec[vert] << endl;
            cout << "\n Esta tiene un costo de: " << menorCosto << endl;
            cout << "La cantidad total de soluciones factibles son " << contadorV << endl;


            break;

        default:
            cout << "Digito una opcion invalida" << endl;

        }
        cout << "Desea seguir utilizando el grafo?\n" << "1 = si, -1 = no" << endl;
        cin >> salida;
    }
}
/**
Nombre: AveriguarCiclos
Parámetros: v(vértice)
Efecto: Retorna un booleano si el grafo tiene ciclos o no
Requiere: Árbol inicializado.
Modifica:

**/
bool AveriguarCiclos(vertice a)
{
    contador++;
    verticesRecorridos.Agregar(a);
    vertice b = grafo.PrimerVerticeAdyacente(a);
    Par<vertice,vertice> arista(a,b);
    //aristas.Agregar(arista);
    while(b != grafo.verticeNulo)
    {
        if(verticesRecorridos.Pertenece(b) == false )
        {
            AveriguarCiclos(b);
        }
        b = grafo.SiguienteVerticeAdyacente(a,b);
        Par<vertice,vertice> arista(a,b);
        //aristas.Agregar(arista);
        if(verticesRecorridos.Pertenece(b) == true)
        {
            contador = grafo.NumVertices();
            ciclo = true;
            return true;
        }
    }
    return false;
}

void ProfPrimero(vertice v)
{
    ciclo = false;
    AveriguarCiclos(v);
    if(contador != grafo.NumVertices())
    {
        vertice v2 = grafo.PrimerVertice();
        while(contador <= grafo.NumVertices())
        {
            if(verticesRecorridos.Pertenece(v2) == false)
            {
                AveriguarCiclos(v2);
            }
            v2 = grafo.SiguienteVertice(v2);
        }
    }
}
/**
Nombre: Floyd
Parámetros:
Efecto: Encuentra el camino más corto entre todo par de vértices al resto  y lo retorna
Requiere: Árbol inicializado.
Modifica:

**/
void Floyd()
{
    int total = grafo.NumVertices();
    vertice aux = grafo.PrimerVertice();
    for(int i=0; i< total; i++)
    {
        mapa[i]= aux;
        aux = grafo.SiguienteVertice(aux);
    }
    for(int i=0; i < total; i++)
    {
        for(int j=0; j< total; j++)
        {
            if(grafo.Adyacentes(mapa[i], mapa[j]) == true)
            {
                adyacentes[i][j] = grafo.Peso(mapa[i], mapa[j]);
            }
            else
            {
                adyacentes[i][j] = -1;
            }
        }
    }
    for(int i=0; i < total; i++)
    {
        for(int j=0; j< total; j++)
        {
            costosF[i][j] = adyacentes[i][j];
        }
    }
    for(int i=0; i<total; i++)
    {
        costosF[i][i] = 0;
    }
    for(int k=0; k<total; k++)
    {
        for(int i=0; i<total; i++)
        {
            for(int j=0; j<total; j++)
            {
                if(costosF[i][k] != -1 && costosF[k][j] != -1)
                {
                    if(costosF[i][j] == -1)
                    {
                        costosF[i][j] = costosF[i][k]+ costosF[k][j];
                        maVert[i][j] = mapa[k];
                    }
                    else
                    {
                        if(costosF[i][k] + costosF[k][j] < costosF[i][j])
                        {
                            costosF[i][j] = costosF[i][k]+ costosF[k][j];
                            maVert[i][j] = mapa[k];
                        }
                    }
                }
            }
        }
    }
}
/**
Nombre: Dijkstra
Parámetros: v (vértice), d (Diccionario)
Efecto: Encuentra los caminos más cortos de un vértice al resto  y los retorna
Requiere: Árbol inicializado.
Modifica:

**/
void Dijkstra(vertice v, Diccionario<vertice> D)
{
    D.Crear();
    contador = 0;
    for(vertice i = grafo.PrimerVertice(); i != grafo.verticeNulo; i = grafo.SiguienteVertice(i))
    {
        mapeo[contador] = i;
        contador++;
    }
    D.Agregar(v);
    for(int i = 0; i< grafo.NumVertices(); i++)
    {
        if(grafo.Etiqueta(mapeo[i]) != grafo.Etiqueta(v))
        {
            if(grafo.Adyacentes(v,mapeo[i]) == false)
            {
                costos[i] = imax;
            }
            else
            {
                costos[i] = grafo.Peso(v,mapeo[i]);
            }
        }
    }
    for(int j = 0; j<grafo.NumVertices(); j++)
    {
        if(D.Pertenece(mapeo[j]) == false)
        {
            D.Agregar(mapeo[j]);
            for(int h = 0; h<grafo.NumVertices(); h++)
            {
                if(D.Pertenece(mapeo[h]) == false)
                {
                    if(grafo.Peso(mapeo[j],mapeo[h])+costos[j] < costos[h] && grafo.Peso(mapeo[j],mapeo[h]) != grafo.pesoNulo)
                    {
                        costos[h] = grafo.Peso(mapeo[j],mapeo[h])+costos[j];
                    }
                }
            }
        }
    }
}
/**
Nombre: Vendedor
Parámetros: v (vértice), g (grafo)
Efecto: Encuentra la solución al problema del vendedor mediante búsqueda exhaustiva pura
Requiere: Árbol inicializado.
Modifica:

**/
void Vendedor(vertice v)
{
    diccionarioVerticesVisitados.Agregar(v);
    vertice va = grafo.PrimerVerticeAdyacente(v);
    while (va != grafo.verticeNulo)
    {
        if (!diccionarioVerticesVisitados.Pertenece(va))
        {
            //cout << "A" << endl;
            diccionarioVerticesVisitados.Agregar(va);
            SolucionActual.push_back(va);
            costoActual += grafo.Peso(v,va);
            if (diccionarioVerticesVisitados.NumElem() == grafo.NumVertices())
            {
                if (grafo.Adyacentes(va, grafo.PrimerVertice()))
                {
                    costo = costoActual + grafo.Peso(va,grafo.PrimerVertice());
                    if((costo < menorCosto) || (menorCosto == -1))
                    {
                        SolucionMejor = SolucionActual;
                        menorCosto = costo;
                        contadorV++;
                    }
                }
            }
            else
            {
                Vendedor(va);
            }
            //cout<< menorCosto <<endl;
            diccionarioVerticesVisitados.Eliminar(va);
            //cout<< diccionarioVerticesVisitados.NumElem() <<endl;
            costoActual = costoActual - grafo.Peso(v,va);
            SolucionActual.pop_back();
        }
        va = grafo.SiguienteVerticeAdyacente(v,va);
        //cout << "caca" << endl;
       // cout << va << endl;
    }
}
/**
Nombre: Kruskal
Parámetros:
Efecto: Encuentra el árbol de mínimo costo
Requiere: Árbol inicializado.
Modifica:

**/
void Kruskal(ConjuntodeConjuntos vertices, ColaDePrioridad<Par<vertice,vertice>> aristas)
{


}
/**
Nombre: Prim
Parámetros: grafo
Efecto: Encuentra el árbol de mínimo costo
Requiere: Árbol inicializado.
Modifica:

**/
void Prim()
{
    conjuntoAristas.clear();
    Diccionario <vertice> diccionario;
    diccionario.Crear();
    diccionario.Agregar(grafo.PrimerVertice());
    vertice actual = grafo.PrimerVertice();
    vertice iterador;
    Dupletas mejorArista;
    while (diccionario.NumElem() != grafo.NumVertices()-1)
    {
        iterador = diccionario.primero->dato;
        menorPeso = -1;
        while (iterador != grafo.verticeNulo)
        {
            actual = grafo.PrimerVerticeAdyacente(actual);
            while (actual != grafo.verticeNulo)
            {
                cout<<"hace algo"<<endl;
                if(menorPeso == -1 || (grafo.Peso(actual, iterador) < grafo.Peso(mejorArista.origen,mejorArista.adyacente) && !diccionario.Pertenece(actual)))
                {
                    menorPeso = grafo.Peso(actual, iterador);
                    mejorArista.origen = iterador;
                    mejorArista.adyacente = actual;
                    cout<<"Encontro algo"<<endl;
                }
                actual = grafo.SiguienteVerticeAdyacente(iterador, actual);

            }
            diccionario.Agregar(mejorArista.origen);
            diccionario.Agregar(mejorArista.adyacente);
            iterador = diccionario.Siguiente(iterador);
            cout << iterador << endl;

        }
        diccionario.Agregar(mejorArista.origen);
        diccionario.Agregar(mejorArista.adyacente);
        conjuntoAristas.push_back(Dupletas(mejorArista.origen,mejorArista.adyacente));
    }
    cout << "llegue al final" << endl;
}

vertice Buscar(string etiqueta)
{
    if(!grafo.Vacio())
    {
        vertice encontrar= grafo.PrimerVertice();
        while(encontrar != grafo.verticeNulo)
        {
            if(etiqueta==grafo.Etiqueta(encontrar))
            {
                return encontrar;
            }
            else
            {
                encontrar = grafo.SiguienteVertice(encontrar);
            }
        }
        return grafo.verticeNulo;
    }
    return grafo.verticeNulo;
}
/**
Nombre: Kruskal
Parámetros:
Efecto: Encuentra el árbol de mínimo costo
Requiere: Árbol inicializado.
Modifica:

*/

void ColorearVertice(Grafo grafo, vertice v)
{
    bool factible = true;
    vertice va;
    for(color =0; color < grafo.NumVertices()-1; color++)
    {
        factible = true;
        va = grafo.PrimerVerticeAdyacente(v);
        while (va != grafo.verticeNulo && factible==true)
        {
            if (VerticesAdyacentes.ConjuntoAlQuePertenece(va) == i)
            {
                    factible = false;
            }
            va = grafo.SiguienteVerticeAdyacente(v,va);
        }
        if(factible)
        {
            VerticesColoreados.AgregarElementoAConjunto(v,color);
            if (color == grafo.NumVertices())
            {

            }else{
                ColorearVertice(grafo, va);
            }
        }
    }
}

   /* diccionarioVerticesVisitados.Agregar(v);
    vertice va = grafo.PrimerVerticeAdyacente(v);
    while (va != grafo.verticeNulo)
    {
        if (!diccionarioVerticesVisitados.Pertenece(va))
        {
            //cout << "A" << endl;
            diccionarioVerticesVisitados.Agregar(va);
            SolucionActual.push_back(va);
            costoActual += grafo.Peso(v,va);
            if (i == grafo.NumVertices()-1)
            {
                if (grafo.Adyacentes(va, grafo.PrimerVertice()))
                {
                    int costo = costoActual + grafo.Peso(va,grafo.PrimerVertice());
                    if((costo < menorCosto) || (menorCosto == -1))
                    {
                        SolucionMejor = SolucionActual;
                        menorCosto = costo;
                        contadorV++;
                    }
                }
            }
            else
            {
                Vendedor(va,i+1);
            }
            //cout<< menorCosto <<endl;
            diccionarioVerticesVisitados.Eliminar(va);
            //cout<< diccionarioVerticesVisitados.NumElem() <<endl;
            costoActual = costoActual - grafo.Peso(v,va);
            SolucionActual.pop_back();
        }
        va = grafo.SiguienteVerticeAdyacente(v,va);
        //cout << "caca" << endl;
       // cout << va << endl;
    }*/

