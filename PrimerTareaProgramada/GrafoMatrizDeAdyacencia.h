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

	/**
	Nombre: GrafoMatriz
	Par�metros:
	Efecto: M�todo constructor del grafo
	Requiere: Grafo no inicializado
	Modifica:
	*/
	GrafoMatriz();

	/**
	Nombre: GrafoMatriz
	Par�metros:
	Efecto: M�todo destructor del grafo
	Requiere: Grafo inicializado
	Modifica:
	*/
    virtual ~GrafoMatriz();

	/**
	Nombre: Iniciar
	Par�metros:
	Efecto: Inicializa el grafo
	Requiere: Grafo no inicializado
	Modifica:
	*/
    void iniciar();

	/**
	Nombre: Destruir
	Par�metros:
	Efecto: Destruye el grafo
	Requiere: Grafo inicializado
	Modifica:
	*/
    void destruir();

	/**
	Nombre: Vaciar
	Par�metros:
	Efecto: Elimina todos los elementos del grafo
	Requiere: Grafo inicializado
	Modifica: Grafo, numVert
	*/
    void vaciar();
	
	/**
	Nombre: Vacio
	Par�metros:
	Efecto: Devuelve un bool si el grafo esta vac�o o no
	Requiere: Grafo inicializado
	Modifica:
	*/
    bool vacio();
    
	/**
	Nombre: AgregarV�rtice
	Par�metros: e(etiqueta)
	Efecto: Agrega un v�rtice al grafo
	Requiere: Grafo inicializado
	Modifica: Grafo, numVert
	*/
    void agregarVertice(string);

	/**
	Nombre: EliminarV�rtice
	Par�metros: v(v�rtice)
	Efecto: Elimina el v�rtice v del grafo
	Requiere: Grafo inicializado, v debe existir en el grafo
	Modifica: Grafo, numVert
	*/
    void eliminarVertice(vertice*);

	/**
	Nombre: ModificarEtiqueta
	Par�metros: v(v�rtice), e(etiqueta)
	Efecto: Cambia la etiqueta del v�rtice en el grafo
	Requiere: Grafo inicializado, v debe ser un v�rtice existente en el grafo
	Modifica: etiqueta
	*/
    void modificarEtiqueta(vertice*, string);

	/**
	Nombre: Etiqueta
	Par�metros: v(v�rtice)
	Efecto: devuelve la etiqueta de un v�rtice
	Requiere: Grafo inicializado, v debe existir en el grafo
	Modifica:
	*/
    string etiqueta(vertice*);

	/**
	Nombre: AgregarArista
	Par�metros: v1(v�rtice), v2(v�rtice), p(peso)
	Efecto: Agrega una arista al grafo
	Requiere: Grafo inicializado
	Modifica: Grafo
	*/
    void agregarArista(vertice*, vertice*, int);

	/**
	Nombre: EliminarArista
	Par�metros: v1(v�rtice), v2(v�rtice)
	Efecto: Elimina la arista que une v1 y v2 en el grafo
	Requiere: Grafo inicializado, la arista debe existir en el grafo
	Modifica: Grafo
	*/
    void eliminarArista(vertice*, vertice*);

	/**
	Nombre: ModificarPeso
	Par�metros: v1(v�rtice), v2(v�rtice), p(peso)
	Efecto: Cambia el peso de una arista del grafo
	Requiere: Grafo inicializado, v1 y v2 deben existir en el grafo y adem�s ser adyacentes para que exista la arista y su peso
	Modifica: peso
	*/
    void modificarPeso(vertice*, vertice*, int);

	/**
	Nombre: Peso
	Par�metros: v1(v�rtice), v2(v�rtice)
	Efecto: devuelve el peso de la arista que conecta los v�rtices v1 y v2
	Requiere: Grafo inicializado, v1 y v2 deben existir en el grafo y adem�s ser adyacentes
	Modifica:
	*/
    int peso(vertice*, vertice*);

	/**
	Nombre: Adyacentes
	Par�metros: v1(v�rtice), v2(v�rtice)
	Efecto: devuelve un booleano si los v�rtices v1 y v2 son o no adyacentes
	Requiere: Grafo inicializado, v1 y v2 existentes en el grafo.
	Modifica:
	*/
    bool adyacentes(vertice*, vertice*);
	
	/**
	Nombre: PrimerV�rtice
	Par�metros:
	Efecto: devuelve el primer v�rtice del grafo
	Requiere: Grafo inicializado
	Modifica:
	*/
    vertice* primerVertice();

	/**
	Nombre: SiguienteV�rtice
	Par�metros: v(v�rtice)
	Efecto: devuelve el siguiente v�rtice de un v�rtice en el grafo
	Requiere: Grafo inicializado, v debe ser existente en el grafo
	Modifica:
	*/
    vertice* siguienteVertice(vertice*);

	/**
	Nombre: PrimerV�rticeAdyacente
	Par�metros: v(v�rtice)
	Efecto: devuelve el primer v�rtice adyacente de un v�rtice del grafo
	Requiere: Grafo inicializado, v debe ser existente en el grafo
	Modifica:
	*/
    vertice* primerVerticeAdyacente(vertice*);

	/**
	Nombre: SiguienteV�rticeAdyacente
	Par�metros: v1(v�rtice), v2(v�rtice)
	Efecto: retorna el siguiente v�rtice adyacente de un v�rtice del grafo
	Requiere: Grafo inicializado, v1 y v2 deben ser existentes en el grafo
	Modifica:
	*/
    vertice* siguienteVerticeAdyacente(vertice*, vertice*);

	/**
	Nombre: buscarVertice
	Par�metros: v (vertice)
	Efecto: retorna el indice donde se localiza el vertice dentro de la matriz
	Requiere: Grafo inicializado, vertice debe ser valido
	Modifica:
	*/
	int buscarVertice(vertice*);

	/**
	Nombre: NumVertices
	Par�metros:
	Efecto: retorna el n�mero de v�rtices en el grafo
	Requiere: Grafo inicializado
	Modifica:
	*/
    int numVertices();

	/**
	Nombre: NumerticesAdyacentes
	Par�metros: v (vertice)
	Efecto: retorna el n�mero de v�rtices adyacentes a un v�rtice
	Requiere: Grafo inicializado, v debe ser existente en el grafo
	Modifica:
	*/
    int numVerticesAdyacentes(vertice*);
	
	/**
	Nombre: VerticeNulo
	Par�metros:
	Efecto: Devuelve un v�rtice nulo
	Requiere: Grafo inicializado
	Modifica:
	*/
	vertice* VerticeNulo();	

protected:
	string vec[maximo];
	int matriz[maximo][maximo];
	int ultimo;
	int vertices;
	vertice verticeNulo;
	int pesoNulo = -1;
private:

};

GrafoMatriz::GrafoMatriz()
{
	iniciar();
}

GrafoMatriz::~GrafoMatriz()
{
	
}

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

void GrafoMatriz::destruir()
{  
}

void GrafoMatriz::vaciar()
{
    ultimo = -1;
}

bool GrafoMatriz::vacio()
{
    if(ultimo == -1)
		return true;  
	return false;
}

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
}

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

void GrafoMatriz::modificarEtiqueta(vertice* v, string etiq)
{
	int aux = buscarVertice(v);
    vec[aux] = etiq;
}

string GrafoMatriz::etiqueta(vertice* v)
{
	int aux = buscarVertice(v);
	if (aux == -1)
		return "-1";
    return vec[aux];
}

void GrafoMatriz::agregarArista(vertice* v1, vertice* v2,int peso)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
    matriz[aux1][aux2] = peso;
    matriz[aux2][aux1] = peso;
}

void GrafoMatriz::eliminarArista(vertice* v1, vertice* v2)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
	matriz[aux1][aux2] = -1;
	matriz[aux2][aux1] = -1;
}

void GrafoMatriz::modificarPeso(vertice* v1, vertice* v2, int peso)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
	matriz[aux1][aux2] = peso;
	matriz[aux2][aux1] = peso;

}

int GrafoMatriz::peso(vertice* v1, vertice* v2)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
    return matriz[aux1][aux2];
}

bool GrafoMatriz::adyacentes(vertice* v1, vertice* v2)
{
	int aux1 = buscarVertice(v1);
	int aux2 = buscarVertice(v2);
    if(matriz[aux1][aux2] == -1)
        return false;
    return true;

}

vertice* GrafoMatriz::primerVertice()
{
    if(ultimo == -1)
        return &verticeNulo;
    return &vec[0];
}

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
    return &verticeNulo;
}

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

int GrafoMatriz::numVertices()
{
    return vertices;
}

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

#endif