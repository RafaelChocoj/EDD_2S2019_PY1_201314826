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
    
    int rep_x; ////para repeticiones del collage
    int rep_y; 
    
    //NodeCir (int val, matrix mat_cub) {
    NodeCir (int tip, matrix mat_cub, string fil, int r_x, int r_y) {
        this->val = tip;
        //tipo = tip;
        
        siguiente = NULL;
        anterior = NULL;
        
        mat = mat_cub;
        filtro = fil;
        
        rep_x = r_x;
        rep_y = r_y;
    }
};

class Filtros_lista_cir
{
public:
	int size;
	NodeCir *primero_head;
	NodeCir *ultimo;
	
	NodeCir *filter_a_reportar;
	
	string name_actual;
	
	Filtros_lista_cir () {
	primero_head = NULL;
	ultimo = NULL;
	size=0;
	}
	bool esVacio();
	void Insert_nod(int tipo, matrix mat_cub, string filtro, int rep_x, int rep_y);
	void Lista_imprimir_ade();
	void Lista_imprimir_atra();
	void Graf_filters();
	void Graf_filters_all();
	
	void Lista_print_filters();
	
	bool Buscando_ima(int i);
	matrix return_mat_ima(int in);
	
	NodeCir* return_node_ima(int in);
};

#endif
