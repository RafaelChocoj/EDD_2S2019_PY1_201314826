#include "arbol_layers.h"


#include <iostream>
#include <string.h> 

using namespace std;


bool arbol_layers :: insert(int layer, string file, NodeLay *raiz_actual) {

    if (root == NULL) {
        root = new NodeLay(layer,file );
        size++;
        //cout << " \nsize " << size ;
        return true;
    }
	else if (layer < raiz_actual->layer) {
        if (raiz_actual->n_izq == NULL) {
            raiz_actual->n_izq = new NodeLay(layer,file);
            size++;
            return true;
        }
        else {
            return insert(layer,file, raiz_actual->n_izq);
        }
    //}else if (nombre > raiz_actual->data) {
    }
	else if (layer > raiz_actual->layer) {
        if (raiz_actual->n_der == NULL) {
            raiz_actual->n_der = new NodeLay(layer,file);
            size++;
            return true;
        }
        else {
            return insert(layer,file, raiz_actual->n_der);
        }
    }else {
        return false;
    }
}

void arbol_layers :: inorder( NodeLay *root) {
    if (root != NULL) {
        inorder(root -> n_izq);
        //cout << " " << root->data << " ->";
        //cout<< root->data <<endl;
        index_root++;
        //if (index_root != size)
		//{grafica_orden = grafica_orden + " \"" + root->data + "\" ->"; }
        //else{grafica_orden = grafica_orden + " \"" + root->data + "\""; }
        
        cout<< root->layer <<"- "<<root->file <<endl;
        
        inorder(root -> n_der);
    }
    
}




/*
void arbol_images::Graficando_arbol() {
	//index_root = 0;
	
	grafica_orden = "";
	grafica_orden = grafica_orden + "digraph G { \n";
	grafica_orden = grafica_orden + "rankdir=TB;\n";
	//grafica_orden = grafica_orden + "graph [splines=ortho, nodesep=0.5];\n";
	grafica_orden = grafica_orden + "graph [nodesep=0.5 ];\n";
	//grafica_orden = grafica_orden + "node [shape = record, fillcolor=seashell2, width=0.7,height=0.2];\n";
	grafica_orden = grafica_orden + "node [shape = record, fillcolor=seashell2];\n";
	VerArbol();
    grafica_orden = grafica_orden + "\n}\n";
    cout << "arbol bonario: \n";
    cout << "grafica_orden: "<<grafica_orden <<endl;
	create_archivo("graf_arbol",grafica_orden);
	
}
*/



