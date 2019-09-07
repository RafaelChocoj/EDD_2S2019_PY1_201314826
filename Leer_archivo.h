#ifndef LEER_ARCHIVO_H
#define LEER_ARCHIVO_H

#include <iostream>
#include "arbol_images.h" //para importar arbol de imagenes
#include "arbol_layers.h" //layers

//arbol_layers ar_leyers;
using namespace std;

class Leer_archivo
{
	/*private:
		std::string archiv;
		std::string file;*/
	
	public:
		//NodeLay* root;
		
		void leer_arhivo_ima(std::string);
		//void leer_arhivo_ima();
		void read_path();
		void Read_config(std::string);
		//Read_config();
		
		void solo_ejemplo2();
		
		void Read_capas(string files, int layer);
		
		//arbol_images arbol;	
		arbol_images Retornando_arbol();	
		
		//void inorder_layer()  { inorder_layer(ar_leyers.root);};
    	void inorder_layer( NodeLay* actual);
    	
    	

		
};
#endif
