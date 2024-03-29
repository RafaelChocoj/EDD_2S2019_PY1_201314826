#include "Leer_archivo.h"

#include "arbol_images.h" //para importar arbol de imagenes
#include "arbol_layers.h"  /// para guardar las capas en orden, depues leer todo

#include <iostream>
#include <fstream>
#include <string> 
#include <string.h> 

#include "Matrix_cub.h"

#include <stdlib.h> 

#include <sstream>


using namespace std;
arbol_images arbol;
arbol_layers ar_leyers;

/*para valores de config de la imagen*/
int ima_h, ima_w;
int pix_h, pix_w;
int pix_ima_h, pix_ima_w;

int no_pixel_w, no_pixel_h;

matrix mt; //para la matrix dispersa cubica
/*
class Leer_archivo
{

	public:
		void leer_arhivo_ima(string);
		void read_path();
		Read_config(string);
		Read_capas(string, int);
};
*/


//void Leer_archivo::leer_arhivo_ima(string archiv){
bool Leer_archivo::leer_arhivo_ima(string archiv){
	bool encontrado = false;
	string layer;
	string file;
	int layar_val = 0;
	int linea = 0;
	
	if(con_carpeta == "S"){
		archiv = name_carpeta +"\\"+ archiv;
	}
	
	//para limpiar layers
	arbol_layers ar_leyers_limpio;
	ar_leyers = ar_leyers_limpio;
	
	//fstream data_ar(archiv);
	ifstream data_ar;
	//data_ar.open("archivo1.csv", ios::in);
	data_ar.open(archiv.c_str() , ios::in);
	
	 if(!data_ar.is_open() ) 
	 {
	 	cout << "\n No se encuentra el archivo" << '\n';
	 	encontrado = false;
	 }
	 else
	 {
		//while(data_ar.good())
		while(!data_ar.fail())
	 	{
	 		linea++;
	 		layer = "";
	 		file = "";
	 		
	 			/////para csv con punto y coma
	 			//getline(data_ar, layer, ';');
		 		//getline(data_ar, file, '\n');
		 		
		 		///para csv con coma
		 		getline(data_ar, layer, ',');
		 		getline(data_ar, file, '\n');
		 		
		 		////cout<<linea<<' ';
		 		//cout<<layer<<' ';
		 		//cout<<file<<endl;
		 		
		 		if (layer == "" || layer == "Layer" )
		 		{
		 			//cout<<"--------"<<layer<<endl;
		 			}else{
		 			
			 		layar_val = atoi(layer.c_str());
			 		//cout<<"layar_val: "<<layar_val<<endl;
			 		/*if (layar_val == 0)
			 		{
			 			Read_config(file);
			 		}*/			 		
			 		//insertando en arbol los arhivos a leer
	
			 		ar_leyers.insert(layar_val, file);
		 		}
	 	}
	 	data_ar.close();
	 	encontrado = true;
	 }
	
	return encontrado;
}

void Leer_archivo::read_path()
{
	bool encontrado;
	system("cls");
	getchar();
	string aceptar;
	string path_archivo ="";
	string nombre_ima = "";
	
	int pun;
	bool yapun = false;


	cout <<"Ingrese nombre del arhivo (.CSV)"<<endl;
	//cin>>path_archivo;
	getline(cin,path_archivo);
	
	cout<<"path_archivo: "<<path_archivo<<endl;
	
	encontrado = leer_arhivo_ima(path_archivo);
	if (encontrado == true){
		//cout<<"strlen(path_archivo.c_str()): "<<strlen(path_archivo.c_str())<<endl;	
		pun = path_archivo.find(".csv");
		//cout<<"encontrado: "<<encontrado<<endl;
		
		nombre_ima = path_archivo.substr(0, pun);
		//cout<<"nombre_ima: "<<nombre_ima<<endl;
		
		
		matrix mt_blanco; //limpiando la matrix
		mt = mt_blanco;
		
		inorder_layer(ar_leyers.root);
	
		//mt.print_node_cor_orde_zz();
		/////mt.Tipo_a_Graficar();
		
		//////guardando nombre en arbol
		arbol.insert(nombre_ima.c_str(),mt, pix_w, pix_h,  pix_ima_w, pix_ima_h, no_pixel_w, no_pixel_h);
		//arbol.Graficando_arbol();
		cout <<"Archivo "<<nombre_ima.c_str()<<" Cargado."<<endl;
	}
}

void Leer_archivo :: solo_ejemplo2( ) {
}


void Leer_archivo :: inorder_layer( NodeLay *root_lay) {
    if (root_lay != NULL) {  	
        inorder_layer(root_lay -> n_izq);
        /*leyenado archivos*/
        if (root_lay->layer == 0)
 		{
 			Read_config(root_lay->file);
 		}	
 		else
 		{
 			Read_capas(root_lay->file, root_lay->layer);
 		}
 		
        cout<< root_lay->layer <<" - "<<root_lay->file <<endl;
        inorder_layer(root_lay -> n_der);
    }
    
}



arbol_images Leer_archivo::Retornando_arbol()
{
	return arbol;
}


void Leer_archivo::Read_config(string file)
{
	cout <<"leyendo configuraciones"<<endl;
	cout<<endl;
	
	if(con_carpeta == "S"){
		file = name_carpeta +"\\"+ file;
	}
	
	string config;
	string value;
	
	//int ima_h, ima_w;
	//int pix_h, pix_w;
	//int pix_ima_h, pix_ima_w;
	
	ima_h, ima_w = 0;
	pix_h, pix_w = 0;
	pix_ima_h, pix_ima_w = 0;
	
	//fstream data_ar(archiv );
	ifstream data_config;
	//data_ar.open("archivo1.csv", ios::in);
	data_config.open(file.c_str() , ios::in);
	
	 if(!data_config.is_open() ) 
	 {
	 	cout << "\n No se encuentra el archivo de configuracion" << '\n';
	 }
	 else
	 
	 {
		//while(data_config.good())
		while(!data_config.fail())
	 	{
	 		config = "";
	 		value = "";
	 		
	 			//////para csv con punto y coma
		 		//getline(data_config, config, ';');
		 		//getline(data_config, value, '\n');
		 		
		 		////para csv con punto y coma
		 		getline(data_config, config, ',');
		 		getline(data_config, value, '\n');
		 		
		 		//cout<<linea<<' ';
		 		
		 		cout<<config<<'=';
		 		cout<<value<<endl;
		 		
		 		/*obtemiendo los valores del tama�a*/
		 		if (config == "image_width")
		 		{
		 			ima_w = atoi(value.c_str());
		 			//cout <<"ima_w: "<<ima_w<<endl;
		 		}
		 		else if (config == "image_height")
		 		{
					ima_h = atoi(value.c_str());
					//cout <<"ima_h: "<<ima_h<<endl;
		 		}
		 		/*tam de pixel*/
		 		else if (config == "pixel_width")
		 		{
		 			pix_w = atoi(value.c_str());
		 			//cout <<"pix_w: "<<pix_w<<endl;
		 		}
		 		else if (config == "pixel_height")
		 		{
		 			pix_h = atoi(value.c_str());
		 			//cout <<"pix_h: "<<pix_h<<endl;
		 		}
	 	}
	 	data_config.close();
	 	pix_ima_w = pix_w*ima_w;
 		pix_ima_h = pix_h*ima_h;
 		
 		no_pixel_w = ima_w;
		no_pixel_h = ima_h;
 		
 		//cout <<"pix_ima_w: "<<pix_ima_w<<endl;
 		//cout <<"pix_ima_h: "<<pix_ima_h<<endl;
	 }
}

void Leer_archivo::Read_capas(string files, int layer)
{
	cout <<"leyendo archivos de capas"<<endl;
	cout<<endl;
	
	if(con_carpeta == "S"){
		files = name_carpeta +"\\"+ files;
	}
	
	string val;
	
	ifstream data_capas;
	data_capas.open(files.c_str() , ios::in);
	
	 if(!data_capas.is_open() ) 
	 {
	 	cout << "\n No se encuentra el archivo capa: " << files <<'\n';
	 }
	 else
	 
	 {
		/*//while(data_capas.good())
		while(!data_capas.fail())
	 	{
	 		//config = "";
	 		val = "";
		 		getline(data_capas, val, ';');
		 		//getline(data_capas, val, '\n');
		 		
		 		//cout<<linea<<' ';
		 		cout<<"*"<<val<<"*";//<<endl;;
		 		//cout<<value<<endl;	 		
	 	}
	 	data_capas.close();*/
	 	
	 	//int linea_y = 0;
	 	int linea_y = 1;  // para que inicie  en 1, porque 0 esta reservado para raices
	 	int colum_x;
	 	/*para recorrer por linea*/
	 	for (string linea; getline(data_capas,linea);)
	 	{
	 		//cout<<"linea_y: "<<linea_y<<endl<<endl;
	 		stringstream reg_x_linea(linea);
	 		//cout<<"*"<<linea<<"*"<<endl;
	 		
	 		/*para recorer por dato*/
	 		//colum_x = 0;
	 		colum_x = 1; // para que inicie  en 1, porque 0 esta reservado para raices
	 		
	 		/////si el archivo csv es con putno y coma
	 		//for(string dat; getline(reg_x_linea, dat, ';');)	
			 	
	 		///si el archivo csv es coma
	 		for(string dat; getline(reg_x_linea, dat, ',');)
	 		
	 		{
	 			//cout<<"cl_x: "<<colum_x<<"  ";
	 			
	 			//cout<<"cor(y,x)-: "<<linea_y<<","<<colum_x;
	 			//cout<<"-dato-"<<dat<<'\t';
				 
				//cout<<"y,x: "<<linea_y<<","<<colum_x;
	 			//cout<<"-dat: "<<dat<<'\t'<<"     "; 	
				
				/*****inicio bloque agregando a matrix*****/
				
				///////////cout<<dat<<'\t'<<"     "; 
				
				if (dat == "x" || dat == "X")
				{}else {
					mt.add(0, colum_x, linea_y, layer, dat, files);
				}
				
				/*****fin bloque agregando a matrix*****/
				
				 //<<endl<<endl;
	 			//cout<<"dato-"<<dat<<"-"<<'\t';
	 			colum_x++;
			}
			///////cout<<endl;
			linea_y++;	 		
		}

	 }
}

	/*
int main()
{
	Leer_archivo read_ar;
	read_ar.read_path();
	//return 0;
}*/


/*void leer_arhivo_ima(string archiv){
	string layer;
	string file;
	int linea = 0;
	
	//fstream data_ar(archiv );
	ifstream data_ar;
	//data_ar.open("archivo1.csv", ios::in);
	data_ar.open(archiv.c_str() , ios::in);
	
	 if(!data_ar.is_open() ) 
	 {
	 	cout << "No se encuentra el archivo" << '\n';
	 }
	 else
	 
	 {
		while(data_ar.good())
		//while(!data_ar.fail())
	 	{
	 		linea++;
	 		layer = "";
	 		file = "";
		 		getline(data_ar, layer, ';');
		 		getline(data_ar, file, '\n');
		 		
		 		cout<<linea<<' ';
		 		cout<<layer<<' ';
		 		cout<<file<<endl;

	 	}
	 	data_ar.close();
	 }
	
	
}*/
