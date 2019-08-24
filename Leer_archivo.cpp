#include "Leer_archivo.h"

#include <iostream>
#include <fstream>
#include <string> 
//#include <stdlib.h> 


using namespace std;

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

void Leer_archivo::leer_arhivo_ima(string archiv){
	string layer;
	string file;
	int layar_val = 0;
	int linea = 0;
	
	//fstream data_ar(archiv);
	ifstream data_ar;
	//data_ar.open("archivo1.csv", ios::in);
	data_ar.open(archiv.c_str() , ios::in);
	
	 if(!data_ar.is_open() ) 
	 {
	 	cout << "\n No se encuentra el archivo" << '\n';
	 }
	 else
	 
	 {
		//while(data_ar.good())
		while(!data_ar.fail())
	 	{
	 		linea++;
	 		layer = "";
	 		file = "";
		 		getline(data_ar, layer, ';');
		 		getline(data_ar, file, '\n');
		 		
		 		//cout<<linea<<' ';
		 		cout<<layer<<' ';
		 		cout<<file<<endl;
		 		
		 		if (layer == "" || layer == "Layer" )
		 		{
		 			//cout<<"--------"<<layer<<endl;
		 			}else{
		 			
			 		layar_val = atoi(layer.c_str());
			 		//cout<<"layar_val: "<<layar_val<<endl;
			 		//if (layer == "0")
			 		if (layar_val == 0)
			 		{
			 			Read_config(file);
			 		}
		 		}

	 	}
	 	data_ar.close();
	 }
	
	
}

void Leer_archivo::read_path()
{
	system("cls");
	string aceptar;
	string path_archivo ="";
	//cin>>aceptar;
	cout <<"Ingrese nombre del arhivo (.CSV)"<<endl;
	cin>>path_archivo;
	//getline(cin,path_archivo);
	cout<<"path_archivo: "<<path_archivo<<endl;
	leer_arhivo_ima(path_archivo);
	
}

void Leer_archivo::prueba()
{

	cout <<"para ver si entra en guncion"<<endl;	
	read_path();
}

void Leer_archivo::Read_config(string file)
{
	cout <<"leyendo configuraciones"<<endl;
	cout<<endl;
	
	string config;
	string value;
	int ima_h, ima_w;
	int pix_h, pix_w;
	int pix_ima_h, pix_ima_w;
	
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
		 		getline(data_config, config, ';');
		 		getline(data_config, value, '\n');
		 		
		 		//cout<<linea<<' ';
		 		cout<<config<<'=';
		 		cout<<value<<endl;
		 		
		 		/*obtemiendo los valores del tamaña*/
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
 		
 		cout <<"pix_ima_w: "<<pix_ima_w<<endl;
 		cout <<"pix_ima_h: "<<pix_ima_h<<endl;
	 }
}

/*Leer_archivo::Read_capas(string file_cap, int layer)
{
}*/

/*	
int main()
{
	Leer_archivo read_ar;
	read_ar.read_path();
	//return 0;
}
*/

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
