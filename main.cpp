/*#include <iostream>
int main(int argc, char** argv) {
	return 0;
}
*/
#include <iostream>
#include <string> 
//#include <stdlib.h> 

#include "Leer_archivo.h"
//#include "Leer_archivo.cpp"

using namespace std;


int main(int argc, char** argv)
{
	
	
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
		cout <<"7. Exit"<<endl<<endl;
		cout <<"**************************\n\n";
		
    	cout<<"Selecciona opcion:\n" ; cin>>opcion;
    	cout <<"opcion: "<<opcion<<endl;
    	if (opcion == 1)
    	{
    		//aqui importamos la archivo	
			Leer_archivo read_ar;	
			//read_ar.read_path();
			read_ar.prueba();
    				
			cout <<"termina aqui****--- "<<endl<<endl;
			
		}    	
        

    }
    return 0;
}
