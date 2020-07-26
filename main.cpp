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



#include <fstream>
#include "Grafo.h"
#include <sstream>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp>


int main(int argc, char *argv[]){

    vector<string> V;
    string line;

    ifstream filein (argv[1]);        // leer fichero de entrada
    if (filein.is_open()){
        while ( getline (filein,line) ){
			boost:split(V, line, boost:is_any_of("\t"));  // parsear linea de entrada al vector V
           
        }
        filein.close();              // se cierra fichero
    }
    else cout << "Unable to open file";


    vector<int> vI;
    int x;
    for (int i=0; i<V.size(); i++){    // convertir a ints
        stringstream str(V.at(i));
        str >> x;
        vI.push_back(x);
    }
    cout << endl;


    Grafo g(atoi(argv[2]));         //7 para prueba.txt, 265214 número de nodos en el grafo email.txt

    // agregar aristas entre nodos
    int j = 1;
    for(int i=0; i<vI.size(); i=i+2){
        g.agregarArista(vI[i], vI[j]);
        j=j+2;
    }


    // Mostrar lista de adyacencia del grafo
 /*   cout << "Lista de Adyacencia" << endl;
    cout << endl;
    for(int i=0;i<atoi(argv[2]);i++){
        g.printListaAdy(i);
        cout << endl;
    }
    cout << endl;*/

    // Grado de salida de los nodos
  /*  cout << "Número de aristas salientes" << endl;
    cout << endl;
    for(int i=0;i<atoi(argv[2]);i++){
        g.printOutdegree(i);
        cout << endl;
    }
    cout << endl;*/

    // BFS general TEST;
  /*  cout << "BFS ALL" << endl;
    cout << endl;
    for(int i=0;i<atoi(argv[2]);i++){
        g.BFS(i);
        cout << endl;
    }*/

    /* cout << "TEST BFS\n";
    g.BFS(0);
    cout << endl;

    cout << "TEST DFS\n";
    g.DFS(0);
    cout << endl;*/

    /******************************** PREGUNTAS "RELEVANTES" ********************************/

    cout << "********* PREGUNTA 1 *************" << endl;
    cout << "* Cronología temporal de emails  *" << endl << endl;
    g.ordenarCronologia();
    cout << "\n\n**********************************" << endl;
    cout << endl << endl << endl;

    cout << "************* PREGUNTA 2 ************" << endl;
    cout << "*   Cadena de correos reenviados    * " << endl << endl;
    cout << "El nodo ancestro es el " << g.ancestro() << endl << endl;
    cout << "*************************************" << endl;
    cout << endl << endl << endl;

    cout << "************* PREGUNTA 3 ************" << endl;
    cout << "* Comunidades y componentes conexas * \n\n";
    g.compConexos();
    cout << "\n************************************" << endl;
    cout << endl << endl << endl;


    return 0; 

}
