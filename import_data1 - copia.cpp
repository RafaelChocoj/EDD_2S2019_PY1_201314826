#include <iostream>
#include <fstream>
#include <string> 

using namespace std;
void leer_arhivo_ima(string);

int main(){
	string path_archivo ="";
	cout <<"Ingrese nombre del arhivo (.CSV)"<<endl;
	getline(cin,path_archivo);
	leer_arhivo_ima(path_archivo);
}

void leer_arhivo_ima(string archiv){
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
	
	
}
