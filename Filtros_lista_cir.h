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
    
    NodeCir (int val, matrix mat_cub) {
        this->val = val;
        siguiente = NULL;
        anterior = NULL;
        
        mat = mat_cub;
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
	void Insert_nod(int val, matrix mat_cub);
	void Lista_imprimir_ade();
	void Lista_imprimir_atra();
	void Graf_filters();
};

#endif
