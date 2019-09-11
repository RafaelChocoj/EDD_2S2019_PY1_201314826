#ifndef FILTROS_LISTA_CIR_H
#define FILTROS_LISTA_CIR_H

#include <iostream>
#include <string>

#include "Matrix_cub.h"

using namespace std;

class NodeCir {
public:
    NodeCir *siguiente;
    NodeCir *anterior;
    int val;
    
    matrix mat;
    string filtro;//nombre del fitltro
    int tipo; //0 todo, diferente de 0, el numero de capa
    
    //NodeCir (int val, matrix mat_cub) {
    NodeCir (int tip, matrix mat_cub, string fil) {
        this->val = tip;
        //tipo = tip;
        
        siguiente = NULL;
        anterior = NULL;
        
        mat = mat_cub;
        filtro = fil;
    }
};

class Filtros_lista_cir
{
public:
	int size;
	NodeCir *primero_head;
	NodeCir *ultimo;
	
	Filtros_lista_cir () {
	primero_head = NULL;
	ultimo = NULL;
	size=0;
	}
	bool esVacio();
	void Insert_nod(int tipo, matrix mat_cub, string filtro);
	void Lista_imprimir_ade();
	void Lista_imprimir_atra();
	void Graf_filters();
	
	void Lista_print_filters();
};

#endif
