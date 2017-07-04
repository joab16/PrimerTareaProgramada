#ifndef Grafo_H
#define Grafo_H
#include <vector>
#define maximo 100
#include <iostream>
#include <string>
#include <iostream>

using namespace std;
typedef string vertice;

class GrafoMatriz
{
public:
	GrafoMatriz();
    virtual ~GrafoMatriz();
    void iniciar();
    void destruir();
    void vaciar();
    bool vacio();
    int pesoNulo = -1;
    void agregarVertice(string);
    void eliminarVertice(vertice*);
    void modificarEtiqueta(vertice*, string);
    string etiqueta(vertice*);
    void agregarArista(vertice*, vertice*, int);
    void eliminarArista(vertice*, vertice*);
    void modificarPeso(vertice*, vertice*, int);
    int peso(vertice*, vertice*);
    bool adyacentes(vertice*, vertice*);
    vertice* primerVertice();
    vertice* siguienteVertice(vertice*);
    vertice* primerVerticeAdyacente(vertice*);
    vertice* siguienteVerticeAdyacente(vertice*, vertice*);
	int buscarVertice(vertice*);
    int numVertices();
    int numVerticesAdyacentes(vertice*);
	vertice* VerticeNulo();
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
GrafoMatriz::GrafoMatriz()
{
	iniciar();
}
GrafoMatriz::~GrafoMatriz()
{
	
}
/**
Nombre: Iniciar
Parámetros:
Efecto: Inicializa el grafo
Requiere: Grafo no inicializado
Modifica:

*/
void GrafoMatriz::iniciar()
{
    ultimo = -1;
    vertices = 0;
	verticeNulo = std::to_string(NULL);
	for (int i = 0; i < maximo; i++)
	{
		vec[i] = verticeNulo;
	}
}
/**
Nombre: Destruir
Parámetros:
Efecto: Destruye el grafo
Requiere: Grafo inicializado
Modifica:

*/
void GrafoMatriz::destruir()
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
void GrafoMatriz::vaciar()
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
bool GrafoMatriz::vacio()
{
    if(ultimo == -1)
		return true;  
	return false;
}
/**
Nombre: AgregarVértice
Parámetros: e(etiqueta)
Efecto: Agrega un vértice al grafo
Requiere: Grafo inicializado
Modifica: Grafo, numVert

*/
void GrafoMatriz::agregarVertice(string etiq)
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
    //return ultimo;
}
/**
Nombre: EliminarVértice
Parámetros: v(vértice)
Efecto: Elimina el vértice v del grafo
Requiere: Grafo inicializado, v debe existir en el grafo
Modifica: Grafo, numVert

*/
void GrafoMatriz::eliminarVertice(vertice* v)
{
	if (*v == vec[ultimo])
    {
        ultimo--;
    }
    else
    {
		int aux = buscarVertice(v);
        for(int h = aux; h < ultimo; h++)
        {
            vec[h] = vec[h+1];
        }
        for(int i = aux; i < ultimo; i++)
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
void GrafoMatriz::modificarEtiqueta(vertice* v, string etiq)
{
	int aux = buscarVertice(v);
    vec[aux] = etiq;
}
/**
Nombre: Etiqueta
Parámetros: v(vértice)
Efecto: devuelve la etiqueta de un vértice
Requiere: Grafo inicializado, v debe existir en el grafo
Modifica:

*/
string GrafoMatriz::etiqueta(vertice* v)
{
	int aux = buscarVertice(v);
	if (aux == -1)
		return "-1";
    return vec[aux];
}
/**
Nombre: AgregarArista
Parámetros: v1(vértice), v2(vértice), p(peso)
Efecto: Agrega una arista al grafo
Requiere: Grafo inicializado
Modifica: Grafo

*/
void GrafoMatriz::agregarArista(vertice* v1, vertice* v2,int peso)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
    matriz[aux1][aux2] = peso;
    matriz[aux2][aux1] = peso;
}
/**
Nombre: EliminarArista
Parámetros: v1(vértice), v2(vértice)
Efecto: Elimina la arista que une v1 y v2 en el grafo
Requiere: Grafo inicializado, la arista debe existir en el grafo
Modifica: Grafo
*/
void GrafoMatriz::eliminarArista(vertice* v1, vertice* v2)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
	matriz[aux1][aux2] = -1;
	matriz[aux2][aux1] = -1;
}
/**
Nombre: ModificarPeso
Parámetros: v1(vértice), v2(vértice), p(peso)
Efecto: Cambia el peso de una arista del grafo
Requiere: Grafo inicializado, v1 y v2 deben existir en el grafo y además ser adyacentes para que exista la arista y su peso
Modifica: peso

*/
void GrafoMatriz::modificarPeso(vertice* v1, vertice* v2, int peso)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
	matriz[aux1][aux2] = peso;
	matriz[aux2][aux1] = peso;

}
/**
Nombre: Peso
Parámetros: v1(vértice), v2(vértice)
Efecto: devuelve el peso de la arista que conecta los vértices v1 y v2
Requiere: Grafo inicializado, v1 y v2 deben existir en el grafo y además ser adyacentes
Modifica:

*/
int GrafoMatriz::peso(vertice* v1, vertice* v2)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
    return matriz[aux1][aux2];
}
/**
Nombre: Adyacentes
Parámetros: v1(vértice), v2(vértice)
Efecto: devuelve un booleano si los vértices v1 y v2 son o no adyacentes
Requiere: Grafo inicializado, v1 y v2 existentes en el grafo.
Modifica:
*/
bool GrafoMatriz::adyacentes(vertice* v1, vertice* v2)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
    if(matriz[aux1][aux2] == -1)
        return false;
    return true;

}
/**
Nombre: PrimerVértice
Parámetros:
Efecto: devuelve el primer vértice del grafo
Requiere: Grafo inicializado
Modifica:

*/
vertice* GrafoMatriz::primerVertice()
{
    if(ultimo == -1)
        return &verticeNulo;
    return &vec[0];
}
/**
Nombre: SiguienteVértice
Parámetros: v(vértice)
Efecto: devuelve el siguiente vértice de un vértice en el grafo
Requiere: Grafo inicializado, v debe ser existente en el grafo
Modifica:

*/
vertice* GrafoMatriz::siguienteVertice(vertice* v)
{
	int aux = buscarVertice(v);
    if(aux+1 <= ultimo)
    {
        return &vec[aux+1];
    }
    else
    {
        return &verticeNulo;
    }
}
/**
Nombre: PrimerVérticeAdyacente
Parámetros: v(vértice)
Efecto: devuelve el primer vértice adyacente de un vértice del grafo
Requiere: Grafo inicializado, v debe ser existente en el grafo
Modifica:

*/
vertice* GrafoMatriz::primerVerticeAdyacente(vertice* v)
{
	int aux = buscarVertice(v);
    for(int i = 0; i <= ultimo; i++)
    {
        if(matriz[aux][i] != -1)
        {
            return &vec[i];
        }
    }    
    return &verticeNulo;
}
/**
Nombre: SiguienteVérticeAdyacente
Parámetros: v1(vértice), v2(vértice)
Efecto: retorna el siguiente vértice adyacente de un vértice del grafo
Requiere: Grafo inicializado, v1 y v2 deben ser existentes en el grafo
Modifica:

*/
vertice* GrafoMatriz::siguienteVerticeAdyacente(vertice* v1, vertice* v2)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
    for(int i = aux2+1; i <= ultimo; i++)
    {
        if(matriz[aux1][i] != -1)
        {
            return &vec[i];
        }
    }
    //cout << "El vertice " << v1 << " no tiene vertices adyacentes despues del vertice " << v2 << endl;
    return &verticeNulo;
}
/**
Nombre: buscarVertice
Parámetros: v (vertice)
Efecto: retorna el indice donde se localiza el vertice dentro de la matriz
Requiere: Grafo inicializado, vertice debe ser valido
Modifica:

*/
int GrafoMatriz::buscarVertice(vertice* v)
{
	int k = 0, aux = -1;
	while (k <= ultimo)
	{
		if (vec[k] == *v)
		{
			aux = k;
		}
		k++;
	}
	return aux;
}
/**
Nombre: NumVertices
Parámetros:
Efecto: retorna el número de vértices en el grafo
Requiere: Grafo inicializado
Modifica:

*/
int GrafoMatriz::numVertices()
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
int GrafoMatriz::numVerticesAdyacentes(vertice* v)
{
	int aux = buscarVertice(v);
    int verticesady = 0;
    for(int i = 0; i <= ultimo; i++)
    {
        if(matriz[aux][i] != -1)
        {
            verticesady++;
        }
    }
    return verticesady;
}

vertice* GrafoMatriz::VerticeNulo()
{
	return &verticeNulo;
}

#endif // Grafo_H
