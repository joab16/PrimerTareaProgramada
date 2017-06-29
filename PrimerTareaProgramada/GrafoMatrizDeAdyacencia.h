#ifndef Grafo_H
#define Grafo_H
#include <vector>
#define maximo 100
#include <iostream>

typedef int vertice;
using namespace std;

class Grafo
{
public:
    Grafo();
    virtual ~Grafo();
    void Iniciar();
    void Destruir();
    void Vaciar();
    bool Vacio();
    int pesoNulo = -1;
    vertice AgregarVertice(string);
    void EliminarVertice(vertice);
    void ModificarEtiqueta(vertice, string);
    string Etiqueta(vertice);
    void AgregarArista(vertice,vertice,int);
    void EliminarArista(vertice, vertice);
    void ModificarPeso(vertice,vertice,int);
    int Peso(vertice,vertice);
    bool Adyacentes(vertice,vertice);
    vertice PrimerVertice();
    vertice SiguienteVertice(vertice);
    vertice PrimerVerticeAdyacente(vertice);
    vertice SiguienteVerticeAdyacente(vertice,vertice);
    int NumVertices();
    int NumVerticesAdyacentes(vertice);
    string vec[maximo];
    int matriz[maximo][maximo];
    int ultimo;
    int vertices;
    vertice verticeNulo;





protected:

private:
};
/**
Nombre: Grafo
Parámetros:
Efecto: Constructor del grafo
Requiere: Grafo no inicializado
Modifica:

*/
Grafo::Grafo()
{

}
Grafo::~Grafo()
{

}
/**
Nombre: Iniciar
Parámetros:
Efecto: Inicializa el grafo
Requiere: Grafo no inicializado
Modifica:

*/
void Grafo::Iniciar()
{
    ultimo = -1;
    vertices = 0;
    verticeNulo = -1;
}
/**
Nombre: Destruir
Parámetros:
Efecto: Destruye el grafo
Requiere: Grafo inicializado
Modifica:

*/
void Grafo::Destruir()
{
  /**  delete vec;
    delete matriz;*/
}
/**
Nombre: Vaciar
Parámetros:
Efecto: Elimina todos los elementos del grafo
Requiere: Grafo inicializado
Modifica: Grafo, numVert

*/
void Grafo::Vaciar()
{
    ultimo = -1;
}
/**
Nombre: Vacio
Parámetros:
Efecto: Devuelve un bool si el grafo esta vacío o no
Requiere: Grafo inicializado
Modifica:

*/
bool Grafo::Vacio()
{
    if(ultimo == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
Nombre: AgregarVértice
Parámetros: e(etiqueta)
Efecto: Agrega un vértice al grafo
Requiere: Grafo inicializado
Modifica: Grafo, numVert

*/
vertice Grafo::AgregarVertice(string etiq)
{
    if(ultimo == -1)
    {
        ultimo++;
        vec[ultimo] = etiq;
        matriz[ultimo][ultimo] = -1;
    }
    else
    {
        ultimo++;
        vec[ultimo] = etiq;
        matriz[ultimo][ultimo] = -1;
        for(int i = 0; i < ultimo; i++)
        {
            matriz[ultimo][i] = -1;
            matriz[i][ultimo] = -1;
        }
    }
    vertices++;
    return ultimo;
}
/**
Nombre: EliminarVértice
Parámetros: v(vértice)
Efecto: Elimina el vértice v del grafo
Requiere: Grafo inicializado, v debe existir en el grafo
Modifica: Grafo, numVert

*/
void Grafo::EliminarVertice(vertice v)
{
    if(v == ultimo)
    {
        ultimo--;
    }
    else
    {
        for(int h = v; h < ultimo; h++)
        {
            vec[h] = vec[h+1];
        }
        for(int i = v; i < ultimo; i++)
        {
            for(int j = 0; j < ultimo; j++)
            {
                matriz[i][j] = matriz[i+1][j];
                matriz[j][i] = matriz[j][i+1];
            }
        }
        ultimo--;
    }
}
/**
Nombre: ModificarEtiqueta
Parámetros: v(vértice), e(etiqueta)
Efecto: Cambia la etiqueta del vértice en el grafo
Requiere: Grafo inicializado, v debe ser un vértice existente en el grafo
Modifica: etiqueta

*/
void Grafo::ModificarEtiqueta(vertice v, string etiq)
{
    vec[v] = etiq;
}
/**
Nombre: Etiqueta
Parámetros: v(vértice)
Efecto: devuelve la etiqueta de un vértice
Requiere: Grafo inicializado, v debe existir en el grafo
Modifica:

*/
string Grafo::Etiqueta(vertice v)
{
    return vec[v];
}
/**
Nombre: AgregarArista
Parámetros: v1(vértice), v2(vértice), p(peso)
Efecto: Agrega una arista al grafo
Requiere: Grafo inicializado
Modifica: Grafo

*/
void Grafo::AgregarArista(vertice v1,vertice v2,int peso)
{
    matriz[v1][v2] = peso;
    matriz[v2][v1] = peso;
}
/**
Nombre: EliminarArista
Parámetros: v1(vértice), v2(vértice)
Efecto: Elimina la arista que une v1 y v2 en el grafo
Requiere: Grafo inicializado, la arista debe existir en el grafo
Modifica: Grafo
*/
void Grafo::EliminarArista(vertice v1, vertice v2)
{
    matriz[v1][v2] = -1;
    matriz[v2][v1] = -1;
}
/**
Nombre: ModificarPeso
Parámetros: v1(vértice), v2(vértice), p(peso)
Efecto: Cambia el peso de una arista del grafo
Requiere: Grafo inicializado, v1 y v2 deben existir en el grafo y además ser adyacentes para que exista la arista y su peso
Modifica: peso

*/
void Grafo::ModificarPeso(vertice v1,vertice v2,int peso)
{
    matriz[v1][v2] = peso;
    matriz[v2][v1] = peso;

}
/**
Nombre: Peso
Parámetros: v1(vértice), v2(vértice)
Efecto: devuelve el peso de la arista que conecta los vértices v1 y v2
Requiere: Grafo inicializado, v1 y v2 deben existir en el grafo y además ser adyacentes
Modifica:

*/
int Grafo::Peso(vertice v1,vertice v2)
{
    return matriz[v1][v2];
}
/**
Nombre: Adyacentes
Parámetros: v1(vértice), v2(vértice)
Efecto: devuelve un booleano si los vértices v1 y v2 son o no adyacentes
Requiere: Grafo inicializado, v1 y v2 existentes en el grafo.
Modifica:
*/
bool Grafo::Adyacentes(vertice v1,vertice v2)
{
    if(matriz[v1][v2] == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/**
Nombre: PrimerVértice
Parámetros:
Efecto: devuelve el primer vértice del grafo
Requiere: Grafo inicializado
Modifica:

*/
vertice Grafo::PrimerVertice()
{
    if(ultimo == -1)
    {
        return verticeNulo;
    }
    else
    {
        return 0;
    }
}
/**
Nombre: SiguienteVértice
Parámetros: v(vértice)
Efecto: devuelve el siguiente vértice de un vértice en el grafo
Requiere: Grafo inicializado, v debe ser existente en el grafo
Modifica:

*/
vertice Grafo::SiguienteVertice(vertice v)
{
    if(v+1 <= ultimo)
    {
        return v+1;
    }
    else
    {
        //cout << "No quedan más vertices" << endl;
        return -1;
    }
}
/**
Nombre: PrimerVérticeAdyacente
Parámetros: v(vértice)
Efecto: devuelve el primer vértice adyacente de un vértice del grafo
Requiere: Grafo inicializado, v debe ser existente en el grafo
Modifica:

*/
vertice Grafo::PrimerVerticeAdyacente(vertice v)
{
    for(int i = 0; i <= ultimo; i++)
    {
        if(matriz[v][i] != -1)
        {
            return i;
        }
    }
    //cout << "El vertice " << v << " no tiene vertices adyacentes" << endl;
    return -1;
}
/**
Nombre: SiguienteVérticeAdyacente
Parámetros: v1(vértice), v2(vértice)
Efecto: retorna el siguiente vértice adyacente de un vértice del grafo
Requiere: Grafo inicializado, v1 y v2 deben ser existentes en el grafo
Modifica:

*/
vertice Grafo::SiguienteVerticeAdyacente(vertice v1,vertice v2)
{
    for(int i = v2+1; i <= ultimo; i++)
    {
        if(matriz[v1][i] != -1)
        {
            return i;
        }
    }
    //cout << "El vertice " << v1 << " no tiene vertices adyacentes despues del vertice " << v2 << endl;
    return -1;
}
/**
Nombre: NumVertices
Parámetros:
Efecto: retorna el número de vértices en el grafo
Requiere: Grafo inicializado
Modifica:

*/
int Grafo::NumVertices()
{
    return vertices;
}
/**
Nombre: NumerticesAdyacentes
Parámetros: v (vertice)
Efecto: retorna el número de vértices adyacentes a un vértice
Requiere: Grafo inicializado, v debe ser existente en el grafo
Modifica:

*/
int Grafo::NumVerticesAdyacentes(vertice v)
{
    int verticesady = 0;
    for(int i = 0; i <= ultimo; i++)
    {
        if(matriz[v][i] != -1)
        {
            verticesady++;
        }
    }
    return verticesady;
}

#endif // Grafo_H
