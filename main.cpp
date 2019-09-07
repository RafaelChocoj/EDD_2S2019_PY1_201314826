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


#include "Matrix_cub.h"

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
		cout <<"8. prueba matriz"<<endl<<endl;
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
		else if (opcion == 8)
    	{
    		matrix mt;
    		mt.add(10,2,1,2, "");
			mt.add(12,5,2,2, "");
			mt.add(25,3,4,2, "");
			mt.add(15,3,6,5, "");
			mt.add(35,5,3,2, "");
			mt.add(20,7,4,4, "");

			mt.add(1212,5,2,4, "");
			
			mt.add(22,2,2,4, "");
			
			mt.add(34,3,4,5, "");
			
			
		
			mt.print_headers();
			
			//cout <<"va imprimir valores"<<endl;    
			//cout <<"recorre der enlace abajo"<<endl;   
			//sm->print_nodes_x();
			//cout <<"recorre abajo enlace der"<<endl;   
			//sm->print_nodes_y();
			
			cout<<endl<<endl<<"-"<<endl;   
			cout<<"print_node_cor_z"<<endl; 
			//sm->print_node_cor();
			mt.print_node_cor_z();
			cout<<endl<<endl<<"cordenada abajo, derecha"<<endl; 
			//sm->print_node_cor_orde();
			mt.print_node_cor_orde_zz();
			
			//cout<<endl<<endl<<"imprimiendo si tiene superior"<<endl; 
			//sm->print_node_z_cap();
			
			//cout<<endl<<endl<<"cordenada derecha, abajo"<<endl; 
			////sm->print_node_cor_orde_der_abaj();
			//sm->print_node_cor_orde_der_abaj_z();
			
			///////////////////sm->print_mt_ejemplo();
			//mt.print_Grafica_matrix();
			mt.Tipo_a_Graficar();
	
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
