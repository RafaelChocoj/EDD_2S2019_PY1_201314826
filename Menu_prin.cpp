#include <iostream>

#include "Leer_archivo.h"
//#include "Leer_archivo.cpp"

using namespace std;


int main()
{
	Leer_archivo read_ar;
	read_ar.prueba();
	
	
	int opcion;
    bool men = true;
    while(men)
    {
    	//system("cls");
	    cout <<"***********MENU***********\n\n";
		cout <<"1. Insert Image"<<endl;
		cout <<"2. Select Image"<<endl;
		cout <<"3. Apply Filters"<<endl;
		cout <<"4. Manual Editing"<<endl;
		cout <<"5. Eport Image"<<endl;
		cout <<"6. Reports"<<endl;
		cout <<"7. Exit"<<endl;
	
    	cout<<"Selecciona una opcion\n" ; cin>>opcion;
    	cout <<"opcion: "<<opcion<<endl;
    	if (opcion == 1)
    	{
    		int a;
    		//aqui importamos la archivo
			//Leer_archivo read_ar;
			//read_ar.prueba();

			

			//read_ar.leer_arhivo_ima("marioverde.csv");
    		
    		
			
		}    	
        


    }
    return 0;
}
