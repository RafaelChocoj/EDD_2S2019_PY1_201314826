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
    
    int no_pixel_w, no_pixel_h;
    
    //Node (string name, valor2) 
    Node (string name, matrix mat_cub, int pix_an, int pix_al, int ima_an, int ima_al, int no_p_an, int no_p_al) {
        data = name;
        
        mat = mat_cub;
        pix_w = pix_an;
        pix_h = pix_al;
        pix_ima_w = ima_an;
        pix_ima_h = ima_al;
        
        no_pixel_w = no_p_an;
        no_pixel_h = no_p_al;
        
        n_izq = n_der = NULL;
    }
};

class arbol_images {
public:
    Node* root;
    
    Node* imagen_actual_nod;
    
    int size=0;
    int index_root;
    arbol_images () {root = NULL; }
    bool insert(string data, matrix mat_cub, int pix_w, int pix_h, int pix_ima_w, int pix_ima_h, int no_pixel_w, int no_pixel_h) { 
        return insert(data,root, mat_cub, pix_w, pix_h, pix_ima_w, pix_ima_h, no_pixel_w, no_pixel_h); 
    };
    bool insert(string name, Node* raiz_actual, matrix mat_cub, int pix_w, int pix_h, int pix_ima_w, int pix_ima_h,  int no_pixel_w, int no_pixel_h);
    
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
    
    /*para buscar por index*/
    void Buscando_x_index(int index)  {  Buscando_x_index(root, index);};
    void Buscando_x_index( Node* actual, int index);
    
    //Node Retorno_nodo_imagen(Node *root_nod);
    
    //int Buscando_x_index(int index)  {  Buscando_x_index(root, index);};
    //int Buscando_x_index( Node* actual, int index) ;
    
};

#endif
