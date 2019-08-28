#ifndef ARBOL_IMAGES_H
#define ARBOL_IMAGES_H

#include <iostream>
#include <string.h> 
#include <fstream>

using namespace std;

class Node {
public:
    Node *n_der,*n_izq;
    string data;
    string valor2;
    //Node (string name, valor2) 
    Node (string name) {
        data = name;
        n_izq = n_der = NULL;
    }
};

class arbol_images {
public:
    Node* root;
    int size=0;
    int index_root;
    arbol_images () {root = NULL; }
    bool insert(string data) { 
        return insert(data,root); 
    };
    bool insert(string name, Node* raiz_actual);
    
    void inorder()  { inorder(root);};
    void postorder()  { postorder(root);};
    void preorder()  { preorder(root);};
    void inorder( Node* actual) ;
    void postorder( Node*actual);
    void preorder( Node* actual) ;
    
    //print
    void print_inorder()  { print_inorder(root);};
    void print_inorder( Node* actual) ;
    
    void Graficando_inor();
    void Graficando_preor();
    void Graficando_posor();
    void Graficando_arbol();
    
    void create_archivo(string nombre, string contenido);
    
    void VerArbol( Node *actual);
    void VerArbol()  { VerArbol(root);};
    
    
    string grafica_orden;
    
};

#endif
