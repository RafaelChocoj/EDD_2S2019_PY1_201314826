#ifndef ARBOL_IMAGES_H
#define ARBOL_IMAGES_H

#include <iostream>
#include <string.h> 
#include <fstream>

#include "Matrix_cub.h"

using namespace std;

class Node {
public:
    Node *n_der,*n_izq;
    string data;
    
    matrix mat;
    int pix_w, pix_h;
    int pix_ima_w, pix_ima_h;
    
    //Node (string name, valor2) 
    Node (string name, matrix mat_cub, int pix_an, int pix_al, int ima_an, int ima_al) {
        data = name;
        
        mat = mat_cub;
        pix_w = pix_an;
        pix_h = pix_al;
        pix_ima_w = ima_an;
        pix_ima_h = ima_al;
        
        n_izq = n_der = NULL;
    }
};

class arbol_images {
public:
    Node* root;
    int size=0;
    int index_root;
    arbol_images () {root = NULL; }
    bool insert(string data, matrix mat_cub, int pix_w, int pix_h, int pix_ima_w, int pix_ima_h) { 
        return insert(data,root, mat_cub, pix_w, pix_h, pix_ima_w, pix_ima_h); 
    };
    bool insert(string name, Node* raiz_actual, matrix mat_cub, int pix_w, int pix_h, int pix_ima_w, int pix_ima_h);
    
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
