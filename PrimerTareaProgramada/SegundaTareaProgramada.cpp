#include <iostream>
#include <ctime>
#include <cstdlib>
#include "stdafx.h"
#include "Diccionario.h"
#include "Grafo_Lista.h"
//#include "GrafoMatrizDeAdyacencia.h"
#include "ColaDePrioridad.h"
#include "Conjunto de Conjuntos.h"
#include "Dupletas.h"
#include "Conjunto.h"

//typedef GrafoMatriz Grafo;
typedef Grafo_Lista Grafo;

//typedef vertice VerticeGen;
typedef Vertice VerticeGen;


using namespace std;

Grafo* grafo;

clock_t start;

int cantVertPintados = 0, cantColoresUsados = 0, mejorSol = std::numeric_limits<int>::max();

Diccionario<int> coloresUsados;

int contador = 0;
int i;

ConjuntodeConjuntos VerticesColoreados;
ConjuntodeConjuntos VerticesAdyacentes;
Diccionario <VerticeGen*> diccionarioVerticesVisitados;
std::vector<VerticeGen*> SolucionActual;
std::vector<VerticeGen*> SolucionMejor;
VerticeGen* primerVert;
std::vector<Par<VerticeGen*, int>> Colores;
Diccionario<VerticeGen*> d;
Diccionario<VerticeGen*> verticesRecorridos;

bool ciclo = false;
int costos[20];
VerticeGen* mapeo[20];

int costosF[20][20];
VerticeGen* maVert[20][20];
int adyacentes[20][20];
VerticeGen* mapa[20];

std::vector<VerticeGen*>::iterator it;
int menorCosto;
int costoActual;
int contadorV;
int costo;
int menorPeso;

std::vector<Dupletas<VerticeGen>> conjuntoAristas;

VerticeGen* Buscar(Grafo* g, string etiqueta);

int imax = std::numeric_limits<int>::max();

/**
Nombre: AveriguarCiclos
Parámetros: v(vértice), g (Grafo)
Efecto: Retorna un booleano si el grafo tiene ciclos o no
Requiere: Grafo inicializado, vertice valido.
Modifica:

**/
bool AveriguarCiclos(Grafo* g, VerticeGen* a)
{
	contador++;
	verticesRecorridos.agregar(a);
	VerticeGen* b = g->primerVerticeAdyacente(a);
	Par<VerticeGen*, VerticeGen*> arista(a, b);
	//aristas.Agregar(arista);
	while (b != g->VerticeNulo())
	{
		if (!(verticesRecorridos.pertenece(b)))
		{
			AveriguarCiclos(g, b);
		}
		b = g->siguienteVerticeAdyacente(a, b);
		Par<VerticeGen*, VerticeGen*> arista(a, b);
		//aristas.Agregar(arista);
		if (verticesRecorridos.pertenece(b))
		{
			contador = g->numVertices();
			return true;
		}
	}
	return false;
}

/**
Nombre: ProfPrimero
Parámetros: g (grafo), v(vértice)
Efecto: Realiza un recorrido en profundidad primero a partir de un vértice dado
Requiere: Grafo inicializado, vértice válido
Modifica:

**/
void ProfPrimero(Grafo* g, VerticeGen* v)
{
	ciclo = AveriguarCiclos(g, v);	
	if (contador != g->numVertices())
	{
		VerticeGen* v2 = g->primerVertice();
		while (contador <= g->numVertices())
		{
			if (!(verticesRecorridos.pertenece(v2)))
			{
				AveriguarCiclos(g, v2);
			}
			v2 = g->siguienteVertice(v2);
		}
	}
}
/**
Nombre: Floyd
Parámetros: g (Grafo)
Efecto: Encuentra el camino más corto entre todo par de vértices al resto  y lo retorna
Requiere: Grafo inicializado.
Modifica:

**/
void Floyd(Grafo* g)
{
	int total = g->numVertices();
	VerticeGen* aux = g->primerVertice();
	for (int i = 0; i< total; i++)
	{
		mapa[i] = aux;
		aux = g->siguienteVertice(aux);
	}
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j < total; j++)
		{
			if (g->adyacentes(mapa[i], mapa[j]))
			{
				adyacentes[i][j] = g->peso(mapa[i], mapa[j]);
			}
			else
			{
				adyacentes[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j< total; j++)
		{
			costosF[i][j] = adyacentes[i][j];
		}
	}
	for (int i = 0; i < total; i++)
	{
		costosF[i][i] = 0;
	}
	for (int k = 0; k<total; k++)
	{
		for (int i = 0; i<total; i++)
		{
			for (int j = 0; j<total; j++)
			{
				if (costosF[i][k] != -1 && costosF[k][j] != -1)
				{
					if (costosF[i][j] == -1)
					{
						costosF[i][j] = costosF[i][k] + costosF[k][j];
						maVert[i][j] = mapa[k];
					}
					else
					{
						if (costosF[i][k] + costosF[k][j] < costosF[i][j])
						{
							costosF[i][j] = costosF[i][k] + costosF[k][j];
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
Parámetros: v (vértice), d (Diccionario) g (Grafo)
Efecto: Encuentra los caminos más cortos de un vértice al resto y los retorna
Requiere: Grafo inicializado, vertice valido.
Modifica:

**/
void Dijkstra(Grafo* g, VerticeGen* v, Diccionario<VerticeGen*> D)
{
	D.crear();
	contador = 0;
	for (VerticeGen* i = g->primerVertice(); g->etiqueta(i) != g->etiqueta(g->VerticeNulo()); i = g->siguienteVertice(i))
	{
		mapeo[contador] = i;
		contador++;
	}
	D.agregar(v);
	for (int i = 0; i < g->numVertices(); i++)
	{
		if (g->etiqueta(mapeo[i]) != g->etiqueta(v))
		{
			if (!(g->adyacentes(v, mapeo[i])))
			{
				costos[i] = imax;
			}
			else
			{
				costos[i] = g->peso(v, mapeo[i]);
			}
		}
	}
	for (int j = 0; j < g->numVertices(); j++)
	{
		if (!(D.pertenece(mapeo[j])))
		{
			D.agregar(mapeo[j]);
			for (int h = 0; h<g->numVertices(); h++)
			{
				if (!(D.pertenece(mapeo[h])))
				{
					if (g->peso(mapeo[j], mapeo[h]) + costos[j] < costos[h] && g->peso(mapeo[j], mapeo[h]) != -1)
					{
						costos[h] = g->peso(mapeo[j], mapeo[h]) + costos[j];
					}
				}
			}
		}
	}
}

/**
Nombre: Vendedor
Parámetros: g (grafo), v (vértice)
Efecto: Encuentra la solución al problema del vendedor mediante búsqueda exhaustiva pura
Requiere: Grafo inicializado, vertice valido.
Modifica:

**/
void Vendedor(Grafo* g, VerticeGen* v)
{
	if (diccionarioVerticesVisitados.numElem() == 0)
		diccionarioVerticesVisitados.agregar(v);

	VerticeGen* va = g->primerVerticeAdyacente(v);
	
	while (va != g->VerticeNulo())
	{
		if (!diccionarioVerticesVisitados.pertenece(va))
		{			
			diccionarioVerticesVisitados.agregar(va);
			SolucionActual.push_back(va);
			costoActual += g->peso(v, va);
			if (diccionarioVerticesVisitados.numElem() == g->numVertices())
			{
				if (g->adyacentes(va, primerVert))
				{
					costo = costoActual + g->peso(va, primerVert);
					if ((costo < menorCosto) || (menorCosto == -1))
					{
						SolucionMejor = SolucionActual;
						menorCosto = costo;
						costoActual = costo;
					}
					contadorV++;
				}
			}
			else
				Vendedor(g, va);

			diccionarioVerticesVisitados.eliminar(va);	
			costoActual = costoActual - g->peso(v, va);
			SolucionActual.pop_back();
		}
		va = g->siguienteVerticeAdyacente(v, va);
	}
}

/**
Nombre: Buscar
Parámetros: g (grafo), etiqueta (string)
Efecto: Busca un vértice de acuerdo a su etiqueta, devuelve el vértice
Requiere: Grafo inicializado, etiqueta valida.
Modifica:
**/
VerticeGen* Buscar(Grafo* g, string etiqueta)
{
	if (!g->vacio())
	{
		VerticeGen* encontrar = g->primerVertice();
		while (encontrar != g->VerticeNulo())
		{
			if (etiqueta == g->etiqueta(encontrar))
			{
				return encontrar;
			}
			else
			{
				encontrar = g->siguienteVertice(encontrar);
			}
		}
		return g->VerticeNulo();
	}
	return g->VerticeNulo();
}

/**
Nombre: Iguales
Parámetros: g1 (grafo), g2 (grafo)
Efecto: Verifica si los dos grafos son iguales
Requiere: Grafos inicializados.
Modifica:

**/
bool Iguales(Grafo* g1, Grafo* g2) 
{
	bool iguales = false;

	if (g1->numVertices() == g2->numVertices()) 
	{
		VerticeGen* v1 = g1->primerVertice();
		VerticeGen* v2;
		iguales = true;
		while (g1->etiqueta(v1) != "0" && iguales) 
		{
			iguales = false;
			v2 = g2->primerVertice();
			while (v2 != 0 && !iguales) 
			{
				if (g2->etiqueta(v2) == g1->etiqueta(v1) && (g2->numVerticesAdyacentes(v2) == g1->numVerticesAdyacentes(v1))) 
				{
					iguales = true;
				}
				else 
				{
					v2 = g2->siguienteVertice(v2);
				}
			}
			v1 = g1->siguienteVertice(v1);
		}
		if (iguales) 
		{
			v1 = g1->primerVertice();
			v2 = g2->primerVertice();
			VerticeGen* ady1;
			VerticeGen* ady2;
			int numArst;
			while (g1->etiqueta(v1) != "0" && iguales) 
			{
				ady1 = g1->primerVerticeAdyacente(v1);
				ady2 = g2->primerVerticeAdyacente(v2);
				numArst = g1->numVerticesAdyacentes(v1);
				iguales = false;
				while (numArst > 0 && !iguales) 
				{
					if (g1->etiqueta(ady1) == g2->etiqueta(ady2)) 
					{
						if (g1->peso(v1, ady1) == g2->peso(v2, ady2)) 
						{
							ady1 = g1->siguienteVerticeAdyacente(v1, ady1);
							ady2 = g2->primerVerticeAdyacente(v2);
							
							if (numArst == 1)
								iguales = true;

							numArst--;
						}
						else 
							numArst = 0;
					}
					else
						ady2 = g2->siguienteVerticeAdyacente(v2, ady2);
				}
				v1 = g1->siguienteVertice(v1);
				v2 = g2->siguienteVertice(v2);
			}
		}
	}
	return iguales;
}

/**
Nombre: CopiarVertices
Parámetros: g (grafo), v (vertice)
Efecto: Copia el vertice enviado
Requiere: Grafo inicializado, vertice valido
Modifica: g, NumVertices, NumAristas
*/
void copiarVertices(Grafo* g, VerticeGen* v)
{	
	if (g->etiqueta(v) != "0")
	{
		copiarVertices(g, g->siguienteVertice(v));
		g->agregarVertice(g->etiqueta(v));
	}
}

/**
Nombre: Copiar
Parámetros: G1(grafo)
Efecto: Hace una copia de un grafo
Requiere: Grafo inicializado
Modifica: g, NumVertices, NumAristas

**/
Grafo* Copiar(Grafo* g)
{
	VerticeGen* v1 = g->primerVertice();
	VerticeGen* ady1;
	VerticeGen* v2;	
	Grafo* copiado = new Grafo();
	copiarVertices(copiado, v1);
	v2 = copiado->primerVertice();
	while (g->etiqueta(v1) != "0") 
	{		
		ady1 = g->primerVerticeAdyacente(v1);
		while (g->etiqueta(ady1) != "0")
		{
			VerticeGen* ady2 = copiado->primerVertice();
			while (g->etiqueta(ady1) != copiado->etiqueta(ady2)) 
			{
				ady2 = copiado->siguienteVertice(ady2);
			}
			if (!(copiado->adyacentes(ady2, v2))) 
			{
				copiado->agregarArista(v2, ady2, g->peso(v1, ady1));
			}
			ady1 = g->siguienteVerticeAdyacente(v1, ady1);
		}
		v1 = g->siguienteVertice(v1);
		v2 = copiado->siguienteVertice(v2);
	}
	return copiado;
}

/**
Nombre: EliminarVerticeNoAislado
Parámetros: v (vértice), G (grafo)
Efecto: Elimina un vértice no aislado del grafo
Requiere: Grafo inicializado, vertice valido
Modifica: NumVertices, g, NumAristas

**/
void EliminarVerticeNoAislado(Grafo* g, VerticeGen* v)
{
	VerticeGen* ady = g->primerVerticeAdyacente(v);	
	while (ady != g->VerticeNulo())
	{
		g->eliminarArista(v, ady);
		ady = g->siguienteVerticeAdyacente(v, ady);
	}
	g->eliminarVertice(v);
}

/*
Nombre: TotalPesosVertice
Parámetros: G(grafo), v (vertice)
Efecto: Totaliza los pesos por vertice
Requiere: Grafo inicializado, vertice valido
Modifica:

*/
int TotalPesosVertice(Grafo* g, VerticeGen* v)
{
	int pesos = 0;
	VerticeGen* ady = g->primerVerticeAdyacente(v);	
	while (ady != g->VerticeNulo())
	{
		pesos += g->peso(v, ady);
		ady = g->siguienteVerticeAdyacente(v, ady);		
	}
	return pesos;
}

/**
Nombre: TotalizarPesosGrafo
Parámetros: G(grafo)
Efecto: Totaliza los pesos de todo el grafo
Requiere: Grafo inicializado
Modifica:

**/
int TotalizarPesosGrafo(Grafo* g)
{
	VerticeGen* v = g->primerVertice();
	int total = 0;
	while (g->etiqueta(v) != g->etiqueta(g->VerticeNulo()))
	{
		total += TotalPesosVertice(g, v);
		v = g->siguienteVertice(v);
	}
	return total / 2;
}

/**
Nombre: ColorearVertice
Parámetros: v (vértice), G (Grafo)
Efecto: Busca el menor número de colores que se necesitan para colorear el grafo
Requiere: Grafo inicializado, v debe ser un vertice valido en el grafo.
Modifica:

**/
void ColorearVertice(Grafo* g, VerticeGen* v)
{	
	cantVertPintados++;
	bool factible = true, colorNuevo = false;
	VerticeGen* va;	
	Conjunto conjuntoVerticesColor;
	for(int C = 0; C < g->numVertices() - 1; C++)
	{		
		factible = true;
		va = g->primerVerticeAdyacente(v);
		while (va != g->VerticeNulo() && factible)
		{
			if (VerticesColoreados.ConjuntoAlQuePertenece(g->etiqueta(va)) == std::to_string(C))
			{
				factible = false;
			}
			va = g->siguienteVerticeAdyacente(v, va);
		}
		if (factible)
		{
			if (!(coloresUsados.pertenece(C)))
			{
				coloresUsados.agregar(C);
				cantColoresUsados++;
				colorNuevo = true;				
				conjuntoVerticesColor.SetNumeroDelConjunto(std::to_string(C));
				conjuntoVerticesColor.AgregarElemento(g->etiqueta(v));
				VerticesColoreados.AgregarConjunto(conjuntoVerticesColor, std::to_string(C));
			}
			else
			{
				VerticesColoreados.AgregarElementoAConjunto(g->etiqueta(v), std::to_string(C));
			}
			if (cantVertPintados == g->numVertices()) 
			{
				if (cantColoresUsados < mejorSol)
				{
					mejorSol = cantColoresUsados;
				}
			}
			else
			{
				ColorearVertice(g, g->siguienteVertice(v));				
			}
			if (colorNuevo)
			{
				coloresUsados.eliminar(C);
				cantColoresUsados--;
				colorNuevo = false;
				VerticesColoreados.EliminarConjunto(std::to_string(C));
				conjuntoVerticesColor.EliminarElemento(g->etiqueta(v));
			}
			else
			{
				VerticesColoreados.EliminarElemento(g->etiqueta(v));				
			}			
		}
	}
	cantVertPintados--;
}

/**
Nombre: ColorearGrafo
Parámetros: G (Grafo)
Efecto: Busca el menor número de colores que se necesitan para colorear el grafo
Requiere: Grafo inicializado.
Modifica:

**/
void ColorearGrafo(Grafo* g)
{	
	cantVertPintados = 0;
	cantColoresUsados = 0;
	coloresUsados.crear();
	VerticesColoreados.Crear();
	ColorearVertice(g, g->primerVertice());
	VerticesColoreados.Destruir();
	coloresUsados.destruir();
}

/**
Nombre: imprimirGrafo
Parámetros: G (grafo)
Efecto: Imprime el grafo
Requiere: Grafo inicializado
Modifica:
**/
void imprimirGrafo(Grafo* g)
{
	VerticeGen* v = g->primerVertice();
	VerticeGen* sig = v;	
	int numVert = g->numVertices();
	int n = 0;	
	cout << "	";
	while (g->etiqueta(v) != g->etiqueta(g->VerticeNulo()))
	{
		cout << g->etiqueta(v) << "	";		
		v = g->siguienteVertice(v);
	}
	cout << endl;
	v = g->primerVertice();
	while (g->etiqueta(v) != g->etiqueta(g->VerticeNulo()))
	{
		cout << g->etiqueta(v) << "	";
		sig = g->primerVertice();
		while (g->etiqueta(sig) != g->etiqueta(g->VerticeNulo()))
		{
			if (g->adyacentes(v, sig))
			{
				cout << g->peso(v, sig) << "	";				
			}
			else
			{
				cout << "0	";
			}
			sig = g->siguienteVertice(sig);
		}
		cout << endl;
		v = g->siguienteVertice(v);
	}
}

/**
Nombre: crearGrafo
Parámetros: 
Efecto: Crea un grafo de prueba
Requiere:
Modifica: 
*/
void crearGrafo()
{
	cout << "Programa de implementacion de modelo grafo y distintos algoritmos." << endl;
	cout << "Se crea un grafo con 5 vertices: v1,v2,v3,v4,v5" << endl;
	grafo = new Grafo();

	grafo->agregarVertice("v1");
	grafo->agregarVertice("v2");
	grafo->agregarVertice("v3");
	grafo->agregarVertice("v4");
	grafo->agregarVertice("v5");

	VerticeGen* v5 = grafo->primerVertice();
	VerticeGen* v4 = grafo->siguienteVertice(v5);
	VerticeGen* v3 = grafo->siguienteVertice(v4);
	VerticeGen* v2 = grafo->siguienteVertice(v3);
	VerticeGen* v1 = grafo->siguienteVertice(v2);

	cout << "Se agregan las aristas del grafo." << endl;
	cout << endl;
	grafo->agregarArista(v5, v1, 7);
	grafo->agregarArista(v5, v4, 8);
	grafo->agregarArista(v5, v2, 10);
	grafo->agregarArista(v4, v1, 5);
	grafo->agregarArista(v4, v3, 4);
	grafo->agregarArista(v3, v2, 2);
	grafo->agregarArista(v2, v1, 4);
}

/**
Nombre: menu
Parámetros:
Efecto: Menu que permite probar el funcionamiento de los distintos algoritmos implementados
Requiere:
Modifica:
*/
void menu()
{	
	int salida = 0;
	string vertic;
	string etiq;
	VerticeGen* vert;
	VerticeGen* vert2;
	int peso;
	while (salida != -1)
	{
		cout << "Que desea utilizar" << endl;				
		cout << "Operadores basicos: \n" << endl;
		
		cout << "1 = Agregar Vertice  2 = Eliminar Vertice 3 = Modificar Etiqueta " << endl;
		cout << "4 = Obtener Etiqueta 5 = Agregar Arista   6 = Eliminar Arista, " << endl;
		cout << "7 = Modificar Peso   8 = Obtener Peso     9 = Vertices Adyacentes " << endl;
		cout << "10 = Primer Vertice  11 = SiguienteVertice 12 = Primer Vertice Adyacente \n13 = Siguiente Vertice Adyacente \n" << endl;
		
		
		cout << "Algoritmos: \n" << endl;
		
		cout << "14 = Averiguar si el grafo tiene ciclos 15 = Dijkstra 16 = Floyd " << endl;
		cout << "17 = Averiguar si dos grafos son iguales 18 = Copiar 19 = Eliminar vertice no aislado " << endl; 
		cout << "20 = Totalizar pesos, 21 = Mostrar grafo, 22 = Coloreo de Grafo, 23 = Vendedor \n" << endl;
		cin >> salida;
		switch (salida)
		{
		case 1: //Agregar Vertice
			cout << "Digite la etiqueta del nuevo vertice: ";
			cin >> vertic;
			grafo->agregarVertice(vertic);
			cout << "\nVertice creado correctamente." << endl;
			break;

		case 2: //Eliminar Vertice
			cout << "Digite la etiqueta del vertice a eliminar: " << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			grafo->eliminarVertice(vert);
			cout << "\nVertice eliminado." << endl;
			break;

		case 3: //Modificar Etiqueta
			cout << "Digite la etiqueta actual del vértice: ";
			cin >> vertic;
			cout << "\nDigite la nueva etiqueta: ";
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			grafo->modificarEtiqueta(vert, etiq);
			cout << "\nEtiqueta modificada correctamente " << endl;
			break;

		case 4: //Obtener Etiqueta
			cout << "De que vertice desea saber la etiqueta?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			grafo->etiqueta(vert);
			break;

		case 5: //Agregar Arista
			cout << "De que vertice a que vertice desea agregar una arista?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			cout << "Que peso desea ponerle?" << endl;
			cin >> peso;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->agregarArista(vert, vert2, peso);
			break;

		case 6: //Eliminar Arista
			cout << "La arista de que vertice a que vertice desea eliminar?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->eliminarArista(vert, vert2);
			break;

		case 7: //Modificar Peso
			cout << "A que aristas le desea modificar el peso?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			cout << "Que peso desea ponerle?" << endl;
			cin >> peso;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->modificarPeso(vert, vert2, peso);
			break;

		case 8: //Obtener Peso
			cout << "De cual arista desea saber el peso?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			grafo->peso(vert, vert2);
			break;

		case 9: //Vertices Adyacentes
			cout << "Que vertices desea averiguar si son adyacentes?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			cout << "Vertice entrada: ";
			cin >> etiq;
			vert = Buscar(grafo, vertic);
			vert2 = Buscar(grafo, etiq);
			if (grafo->adyacentes(vert, vert2))
			{
				cout << "Los vertices " << vertic << ", " << etiq << " son adyacentes" << endl;
			}
			else
			{
				cout << "Los vertices " << vertic << ", " << etiq << " no son adyacentes" << endl;
			}
			break;

		case 10: //Primer Vertice
			cout << "El primer vertice es: " << grafo->etiqueta(grafo->primerVertice()) << endl;
			break;

		case 11: //Siguiente Vertice
			cout << "A partir de cual vertice desea averigurar el siguiente?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			cout << "El siguiente vertice a partir de: " << grafo->etiqueta(vert) << " es: " << grafo->etiqueta(grafo->siguienteVertice(vert)) << endl;
			break;

		case 12: //Primer Vertice Adyacente
			cout << "De que vertice desea averiguar su primer vertice adyacente?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			cout << "El primer vertice adyacente de" << grafo->etiqueta(vert) << "es: " << grafo->etiqueta(grafo->primerVerticeAdyacente(vert)) << endl;
			break;

		case 13: //Siguiente Vertice Adyacente
			cout << "Que vertice desea eliminar?" << endl;
			cout << "Vertice salida: ";
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			cout << "Vertice adyacente a" << grafo->etiqueta(vert) << ": ";
			cin >> etiq;
			vert2 = Buscar(grafo, etiq);
			cout << "El siguiente vertice adyacente de " << grafo->etiqueta(vert) << " despues de: " << grafo->etiqueta(vert2) << " es: " << grafo->etiqueta(grafo->siguienteVerticeAdyacente(vert, vert2));
			break;

		case 14:
			verticesRecorridos.crear();
			cout << "A partir de cual vertice desea empezar la busqueda de un ciclo?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			ProfPrimero(grafo, vert);
			if (ciclo)
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
			cout << endl;
			vert = Buscar(grafo, vertic);
			Dijkstra(grafo, vert, d);			
			for (int i = 0; i < grafo->numVertices(); i++)
			{
				if (mapeo[i] != vert)
				{
					cout << "El camino de menor costo de " << grafo->etiqueta(vert) << " hasta " << grafo->etiqueta(mapeo[i]) << " es: " << costos[i] << endl;
				}

			}

			break;
		case 16:
			Floyd(grafo);			
			for (int i = 0; i<grafo->numVertices(); i++)
			{
				for (int j = 0; j<grafo->numVertices(); j++)
				{
					if (i != j)
					{
						cout << "El camino de menor costo de " << grafo->etiqueta(mapa[i]) << " hasta " << grafo->etiqueta(mapa[j]) << " es: " << costosF[i][j] << endl;
					}
				}
			}

			break;
		case 17:
			if (Iguales(grafo, grafo))
			{
				cout << "Los grafos son iguales" << endl;
			}
			else
			{
				cout << "Los grafos son diferentes" << endl;
			}
			break;
		case 18:
			Copiar(grafo);
			cout << "Mostrando el nuevo grafo:" << endl;
			imprimirGrafo(grafo);
			break;
		case 19:
			cout << "Cual vertice no aislado desea eliminar?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			EliminarVerticeNoAislado(grafo, vert);
			break;
		case 20:
			cout << "La suma de todos los pesos de las aristas es: " << TotalizarPesosGrafo(grafo) <<endl;
			break;
		case 21:
			cout << "Imprimimos el grafo como matriz de adyacencia" << endl;
			imprimirGrafo(grafo);
			break;
		case 22:			
			ColorearGrafo(grafo);			
			cout << "La cantidad minima de colores es: " << mejorSol << endl;
			break;
		case 23:
			cout << "A partir de cual vertice desea empezar Vendedor?" << endl;
			cin >> vertic;
			vert = Buscar(grafo, vertic);
			menorCosto = -1;
			costoActual = 0;
			contadorV = 0;
			SolucionActual.clear();
			SolucionMejor.clear();
			primerVert = vert;
			Vendedor(grafo, vert);			
			cout << "La mejor solucion es: ";
			cout << grafo->etiqueta(vert) << " -> ";
			for (it = SolucionMejor.begin(); it < SolucionMejor.end(); it++)
			{
				cout << grafo->etiqueta(*it) << " -> ";
			}
			cout << grafo->etiqueta(vert) << endl;
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

int main(int argc, char** argv) 
{
	crearGrafo();	
	menu();	
	return 0;
}

