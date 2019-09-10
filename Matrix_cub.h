#ifndef MATRIX_CUB_H
#define MATRIX_CUB_H

#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <fstream>

using namespace std;


class node
{
public:
    node* right;
	node* left;
    node* down;
    node* up;
    
    node* capa_up; // profundidad de la capa, arriba
    node* capa_down; // profundidad de la capa, abajo
    
    int data;
    int cor_y;
    int cor_x;
    int cor_z;
    
    //valores
    string tipo;
    string valor;
    
    node (int data_ , int x, int y, int z, string tipo_n, string valor_n) {
        data = data_;
        //this->data = data;
        
        cor_y = y;
        cor_x = x;
        cor_z = z;
        
        right  = NULL;
        left = NULL;
        down  = NULL;
        up = NULL;
        
        capa_up = NULL;
        capa_down = NULL;
        
        tipo = tipo_n;
        valor = valor_n;
    }
};

class matrix {
public:
    node *head;
    
    matrix () {
        //head  = NULL;  
        //				   data, x, y, z, tipo, valor
		node *temp = new node(0, 0, 0, 0, "R", "RAIZ");
		head = temp;  
    }
    
    void add (int value, int x, int y, int z, string valor, string file_capa);
    /*nodo en z*/
    void add_z(node *new_node, int x, int y, int z);
    
    void add_x(node *new_node, int x, int y, int z);
	
	void add_y(node *new_node, int x, int y, int z);
	
	/***********inicio***X*y***nodos 0 en z***********************/
	
	void add_x_header_z0(int x,  int z);
    
    void add_y_header_z0(int y, int z);
    
	void add_x_z0(node *new_node, int x, int y, int z);
	
	void add_y_z0(node *new_node, int x, int y, int z);
	
	/***********fin***X*y***nodos 0 en z***********************/
	
    //void add_x_header(int x){
    void add_x_header(int x,  int z);
    
    //void add_y_header(int y) {
    void add_y_header(int y, int z);
    
    void add_z_header(int z, string file_capa);
    
    void print_headers();
    
    /*print*/
    void print_x_header();
    
    void print_y_header();
    
    /*print por profundidad*/
    void print_x_header_capas_z(node *nodo_cap);
    
    void print_y_header_capas_z(node *nodo_cap);
    
    ///cap
    void print_z_header_capas_z();
    
    void print_z_header();
    
    
    
	void print_nodes_x();
    
    void print_nodes_y();
    
    /////****inicio******para*imprimir*matriz*en*grapiz******************//
    void create_archivo(string nombre, string contenido);
    
    int alto_mat();
    
    int alto_mat_x_cap(node *matrix_head);
    
    void Tipo_a_Graficar();
    
    void print_Grafica_matrix(node *matrix_capa, string name_cap);

    /////****fin******para*imprimir*matriz*en*grapiz******************//
    
    ///capas de cordenadas
    void print_node_cor_z();
    
    ///imprimiendo superiores
    void print_node_superiores(node *nodo_sup_arriba);
    
    void print_node_cor_mat(node *nodo_x_nivel);
    
    void print_mt_ejemplo();
    
    
    void print_node_cor();
    
    ///capas de cordenadas
    void print_node_cor_orde_zz();
    
    
    ///recorriendo capas por profinidad, por cada nodo encontrado
    void print_node_z_cap();
    
    
    void buscabdo_nodo_superior(node *nodo_actual, int x, int y);
    
    void print_mat_sup(node *nodo_x_nivel);
    
    
    void print_mat_sup_superior(node *nodo_x_nivel);
    
    void print_node_cor_orde_der_abaj_z();
    
    void print_node_cor_orde_mat(node *nodo_x_nivel);
    
    void print_node_cor_orde();
    
     ///para recorer de derecha hacia abajo
    void print_node_cor_orde_der_abaj_mat(node *nodo_x_nivel);
    
    ///para recorer de derecha hacia abajo
    void print_node_cor_orde_der_abaj();
    
    int no_columnas_mat();
    
    void Generando_css(int canvas_w, int canvas_h, int pix_w, int pix_h, int no_pix_ancho, int no_pix_alto);
    void read_matrix_css_html(node *matrix_capa, int canvas_w, int canvas_h, int pix_w, int pix_, int no_pix_ancho, int no_pix_alto);
    
    void create_file_images(string nombre, string contenido);
    
    string RGBToHex(int r_int, int g_int, int b_int);
    	
    void Capas_para_select();
    
    
    
    
};

#endif