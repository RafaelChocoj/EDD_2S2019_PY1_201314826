#ifndef ARBOL_LAYERS_H
#define ARBOL_LAYERS_H
 
#include <iostream>
#include <string.h> 

using namespace std;

class NodeLay {	
public:
    NodeLay *n_der,*n_izq;
    int layer;
    string file;
    NodeLay (int layer_, string file_) {
        layer = layer_;
        file = file_;
        n_izq = n_der = NULL;
    }
};


class arbol_layers {
public:
    NodeLay* root;
    int size=0;
    int index_root;
    
    arbol_layers () {root = NULL; }
    bool insert(int layer, string file) { 
        return insert(layer,file, root); 
    };
    bool insert(int layer, string file, NodeLay* raiz_actual);
    
    void inorder()  { inorder(root);};
    void inorder( NodeLay* actual) ;
    
 
};

#endif
