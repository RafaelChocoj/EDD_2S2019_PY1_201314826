/*#include <iostream>
int main(int argc, char** argv) {
	return 0;
}
*/
#include <iostream>
#include <string> 
//#include <stdlib.h> 

#include "Leer_archivo.h" // para leer archivos
#include "arbol_images.h" //importar arbol de imagenes


using namespace std;

Leer_archivo read_ar; //para importacion
arbol_images arbol_im; //arbol de imagenes
void MenuReport();
void Report_tran();

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
		cout <<"5. Export Image"<<endl;
		cout <<"6. Reports"<<endl;
		cout <<"7. Exit"<<endl<<endl;
		cout <<"**************************\n\n";
		
    	cout<<"Selecciona opcion:\n" ; cin>>opcion;
    	cout <<"opcion: "<<opcion<<endl;
    	if (opcion == 1)
    	{
    		//aqui importamos la archivo		
			read_ar.read_path();
			//cout <<"read_ar.arbol.size: "<<read_ar.arbol.size <<endl;
			//cout <<"termina aqui****--- "<<endl<<endl;
			system("pause");
			
		}
		else if (opcion == 2)
    	{
    		system("cls");
    		//seleccion de imagenes cargadas
    		//arbol.inorder();	
    		//arbol_im.inorder();
    		//read_ar.arbol.inorder();
    		arbol_im = read_ar.Retornando_arbol();
    		arbol_im.inorder();
    		
    		
    		//read_ar.arbol.inorder();
    		//cout <<"read_ar.arbol.size: "<<read_ar.arbol.size <<endl;
    		system("pause");
					
    
		}
		else if (opcion == 6)
    	{
    		MenuReport();
		} 
		else if (opcion == 7)
    	{
    		men = false;
		}   
		else
    	{
    		system("cls");
    		cout <<"(MENU) Tecla invalida, selecciona opcion valida "<<endl;
    		system("pause");
		} 	
        

    }
    return 0;
}


void MenuReport()
{
	arbol_im = read_ar.Retornando_arbol();
	string repor;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********REPORTS***********\n\n";
		cout <<"a. IMPORTED IMAGES REPORT"<<endl;
		cout <<"b. IMAGE LAYER REPORT"<<endl;
		cout <<"c. LINEAR MATRIX REPORT"<<endl;
		cout <<"d. TRAVERSAL REPORT"<<endl;
		cout <<"e. FILTERS REPORT"<<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un Reporte:\n" ; cin>>repor;
    	cout <<"Reporte: "<<repor<<endl;
    	
    	if (repor == "a" || repor == "A")
    	{
    		arbol_im.Graficando_arbol();
		}
		else if (repor == "d" || repor == "D")
    	{
    		Report_tran();
		}
    	else if (repor == "0")
    	{
    		men = false;
		}
		else
    	{
    		system("cls");
    		cout <<"(REPORTS) Tecla invalida, selecciona opcion valida "<<endl;
    		system("pause");
					
    
		} 
    	
	}
}

void Report_tran()
{
	string repor;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********TRAVERSAL REPORT***********\n\n";
		cout <<"1. Inorder Traversal"<<endl;
		cout <<"2. Preorder Traversal"<<endl;
		cout <<"3. Posorder Traversal"<<endl<<endl;
		
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un Reporte:\n" ; cin>>repor;
    	cout <<"Reporte: "<<repor<<endl;
    	
    	if (repor == "1")
    	{
			arbol_im.Graficando_inor();
		}
		else if (repor == "2" )
    	{
			arbol_im.Graficando_preor();
		}
		else if (repor == "3" )
    	{
			arbol_im.Graficando_posor();
		}
    	else if (repor == "0")
    	{
    		men = false;
		}
		else
    	{
    		system("cls");
    		cout <<"(TRAVERSAL REPORT) Tecla invalida, selecciona opcion valida "<<endl;
    		system("pause");
					
    
		} 
    	
	}
}
