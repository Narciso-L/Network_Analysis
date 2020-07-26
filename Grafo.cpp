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



#include "Grafo.h"


/******************************* CREAR GRAFO ***********************************/
Grafo::Grafo(int V){
    this->V = V;
    ady = new list<int>[V]; // se crea lista para cada vértice
}


/********************************* AGREGAR ARISTAS *****************************/
void Grafo::agregarArista(int v, int w) {
    ady[v].push_back(w); // se agrega w a la lista de v
}


/************************** MOSTRAR LISTA ADYACENCIA ***************************/
void Grafo::printListaAdy(int s){
    list<int>::iterator i;
    cout << s << "-> ";

    for(i = ady[s].begin(); i != ady[s].end(); ++i){    // mostrar cada lista de adyacencia
        cout << *i << "-> ";
    }
}


/******************************** MOSTRAR OUTDEGREE ****************************/
void Grafo::printOutdegree(int s){
    int sum = 0;
    list<int>::iterator i;
    cout << s << "-> ";

    for(i = ady[s].begin(); i != ady[s].end(); ++i){    // iterar por cada lista de adyacencia y sumar el grado de salida
        sum += *i;
    }
    cout << *i;
}


/************************************* BFS *************************************/
void Grafo::BFS(int s){
    bool *vis = new bool[V];     // marcar todos los vertices como no visitados
    for(int i = 0; i < V; i++)
        vis[i] = false;

    list<int> queue;             // crear cola para BFS

    vis[s] = true;               // marcar el nodo como visitado y encolarlo
    queue.push_back(s);

    list<int>::iterator i;       //obtener todos los vertices adyacentes a un vertice

    while(!queue.empty()){
        s = queue.front();       //desencolar un vertice de la cola y mostrarlo
        cout << s << " ";

        queue.pop_front();

        for(i = ady[s].begin(); i != ady[s].end(); ++i){
            if(!vis[*i]){                 // obtiene todos los vertices adyacentes del vertice desencolado s
                vis[*i] = true;          // si un adyacente no se ha visitado, se marca como tal
                queue.push_back(*i);    // y se encola
            }
        }
    }
}


/******************************** DFS *****************************************/
void Grafo::auxDFS(int v, bool vis[]){
    vis[v] = true;  // marca el nodo como visitado y se muestra
    cout << v << " ";

    list<int>::iterator i;
    for (i = ady[v].begin(); i != ady[v].end(); ++i)
        if (!vis[*i])
            auxDFS(*i, vis);
}


// Recorrido DFS de los vertices alcanzables desde v
void Grafo::DFS(int v){
    bool *vis = new bool[V];    //se marcan todos los vertices como no visitados
    for (int i = 0; i < V; i++)
        vis[i] = false;

    auxDFS(v, vis); //aux para mostrar el recorrido DFS
}


/***************************** CRONOLOGIA ***********************************/
void Grafo::aux(int v, bool vis[], stack<int> &S){
    vis[v] = true;  //marcar el nodo como visitado

    list<int>::iterator i;   //recorrer todos los vertices adyacentes del vertice
    for (i = ady[v].begin(); i != ady[v].end(); ++i)
        if (!vis[*i])
            aux(*i, vis, S);

    S.push(v);  //colocar el vertice en la pila que almacena el resultado
}


void Grafo::ordenarCronologia(){
    stack<int> S;

    bool *vis = new bool[V];    //se marcan todos los vertices como no visitados
    for (int i = 0; i < V; i++)
        vis[i] = false;

    for (int i = 0; i < V; i++) //almacenar el orden cronologico de todos los vertices
        if (vis[i] == false)
            aux(i, vis, S);

    while (S.empty() == false){ //mostrar la pila
        cout << S.top() << " ";
        S.pop();
    }
}


/******************** COMPONENTES CONEXAS Y COMUNIDADES ********************/
void Grafo::compConexos(){  //muestra todos los componentes fuertemente conexos
    stack<int> Stack;

    bool *vis = new bool[V];        //marcar todos los vertices como no visitados
    for(int i = 0; i < V; i++)
        vis[i] = false;

    for(int i = 0; i < V; i++)      //llenar vertices en la pila de acuerdo a su finalizacion
        if(vis[i] == false)
            aux(i, vis, Stack);

    Grafo gr = obtenerTranspuesta();//crear transpuesta

    for(int i = 0; i < V; i++)      //marcar todos los vertices como no visitados
        vis[i] = false;

    while (Stack.empty() == false){ //procesar todos los vertices en orden en la pila
        int v = Stack.top();        //quitar vertice de la pila
        Stack.pop();

        if (vis[v] == false){       // muestra componente fuertemente conexo del vertice que se ha quitado
            gr.auxDFS(v, vis);
            cout << endl;
        }
    }
}


Grafo Grafo::obtenerTranspuesta(){
    Grafo g(V);
    for (int v = 0; v < V; v++){
        list<int>::iterator i; // se recorren todos los vertices adyacentes al vertice
        for(i = ady[v].begin(); i != ady[v].end(); ++i){
            g.ady[*i].push_back(v);
        }
    }
    return g;
}


/******************************** ANCESTRO  *******************************/
void Grafo::auxAncestro(int v, vector<bool> &vis){
    vis[v] = true;  // marcar el nodo como visitado y mostrarlo

    list<int>::iterator i;  // recorrer todos los vertices adyacentes del vertice
    for (i = ady[v].begin(); i != ady[v].end(); ++i)
        if (!vis[*i])
            auxAncestro(*i, vis);
}


int Grafo::ancestro(){    // devuelve ancestro si existe, sino -1
    vector <bool> vis(V, false);    // inicialmente como no visitados

    int v = 0;  // almacenar el ultimo vertice (ancestro)

    for (int i = 0; i < V; i++){    // recorrido DFS para encontrar el ultimo vertice
        if (vis[i] == false){
            auxAncestro(i, vis);
            v = i;
        }
    }

    // si hay ancestro en el grafo, entonces v tiene que ser uno (o uno de ellos)
    // se comprueba si v es ancestro, por lo que hay que comprobar si cada vertice se alcanza desde v o no

    fill(vis.begin(), vis.end(), false);    // resetear valores a false
    auxAncestro(v, vis);                    // DFS desde v para comprobar si todos los vertices son alcanzables
    for (int i=0; i<V; i++)
        if (vis[i] == false)
            return -1;                      // sino hay ancestro devuelve 1

    return v;                               // devuelve ancestro de existir
}
