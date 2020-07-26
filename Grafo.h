/*Copyright (C) <2016>  <Narciso López-López>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef GRAFOS_GRAPH_H
#define GRAFOS_GRAPH_H


#include<iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;


// grafo dirigido con lista de adyacencia
class Grafo{
    int V;              // numero de vertices
    list<int> *ady;     // puntero al array que tiene las listas de adyacencia

    void aux(int v, bool vis[], stack<int> &S);     // aux de cronologia y comunidades

    void auxDFS(int v, bool vis[]);             // aux de DFS

    void auxAncestro(int v, vector<bool> &vis);     // mostrar DFS desde v


public:

    Grafo(int V);   // constructor

    void agregarArista(int v, int w);   // agregar una arista al grafo

    void printListaAdy(int s);  // muestra la lista de adyacencia de todos los vertices

    void printOutdegree(int s); // muestra el outdegree de un vertice

    void BFS(int s);    // recorrido BFS desde un vertice s

    void DFS(int v);    // recorrido DFS de los vertices alcanzables desde v

    /************************** CRONOLOGIA ***************************/
    void ordenarCronologia();   // muestra el orden cronologico del grafo

    /********************** CONEXOS/COMUNIDADES **********************/
    Grafo obtenerTranspuesta(); // devuelve el grafo reverso/transpuesto
    void compConexos();         // muestra los componentes conexos

    /**************************** ANCESTRO ****************************/
    int ancestro();

};


#endif
