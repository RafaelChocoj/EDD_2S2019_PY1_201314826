/*#include <iostream>
int main(int argc, char** argv) {
	return 0;
}
*/
#include <iostream>
#include <string> 
#include <stdlib.h> //para convertir string a int

#include "Leer_archivo.h" // para leer archivos
#include "arbol_images.h" //importar arbol de imagenes

#include "Filtros_lista_cir.h" // para lista doble de layers


#include "Matrix_cub.h"

using namespace std;

Leer_archivo read_ar; //para importacion
arbol_images arbol_im; //arbol de imagenes

Filtros_lista_cir list_filtros;

void MenuReport();
void Report_tran();

matrix mtx_actual;

void Select_images();
void menu_filters();
void Select_capas();

int main(int argc, char** argv)
{
	
	
	//int opcion;
	string opcion;
    bool men = true;
    while(men)
    {
    	//system("cls");
    	cout <<"***********MENU***********";
    	if (arbol_im.imagen_actual_nod != NULL)
    	{ cout<<"  (Imagen Actual: "<< arbol_im.imagen_actual_nod->data<<")" <<endl; }
    	
    	cout <<endl<<endl;
	    //cout <<"***********MENU***********\n\n";
		cout <<"1. Insert Image"<<endl;
		cout <<"2. Select Image"<<endl;
		cout <<"3. Apply Filters"<<endl;
		cout <<"4. Manual Editing"<<endl;
		cout <<"5. Export Image"<<endl;
		cout <<"6. Reports"<<endl;
		cout <<"7. Exit"<<endl<<endl;
		cout <<"8. prueba matriz"<<endl<<endl;
		cout <<"9. graficando matriz"<<endl<<endl;
		cout <<"10. verificando lista layes"<<endl<<endl;
		cout <<"**************************\n\n";
		
    	cout<<"Selecciona opcion:\n" ; cin>>opcion;
    	cout <<"opcion: "<<opcion<<endl;
    	if (opcion == "1")
    	{
    		//aqui importamos la archivo		
			read_ar.read_path();
			//cout <<"read_ar.arbol.size: "<<read_ar.arbol.size <<endl;
			//cout <<"termina aqui****--- "<<endl<<endl;
			system("pause");
			
		}
		else if (opcion == "2")
    	{
    		Select_images();
		}
		else if (opcion == "3")
    	{
    		menu_filters();
		}
		/*para exportar el cubo*/
		else if (opcion == "5")
    	{
			mtx_actual.Generando_css(arbol_im.imagen_actual_nod->pix_ima_w,arbol_im.imagen_actual_nod->pix_ima_h, arbol_im.imagen_actual_nod->pix_w, arbol_im.imagen_actual_nod->pix_h, arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
			//cout <<"pix_ima_w: "<<arbol_im.imagen_actual_nod->pix_ima_w<<endl;
			//cout <<"pix_ima_h: "<<arbol_im.imagen_actual_nod->pix_ima_h<<endl;
			//cout <<"pix_w: "<<arbol_im.imagen_actual_nod->pix_w<<endl;
			//cout <<"pix_h: "<<arbol_im.imagen_actual_nod->pix_h<<endl;
			system("pause");
		
		} 
		
		else if (opcion == "6")
    	{
    		MenuReport();
		} 
		else if (opcion == "8")
    	{
    		matrix mt;
    		mt.add(10,2,1,2, "", "");
			mt.add(12,5,2,2, "", "");
			mt.add(25,3,4,2, "", "");
			mt.add(15,3,6,5, "", "");
			mt.add(35,5,3,2, "", "");
			mt.add(20,7,4,4, "", "");

			mt.add(1212,5,2,4, "", "");
			
			mt.add(22,2,2,4, "", "");
			
			mt.add(34,3,4,5, "", "");
			
			
		
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
		else if (opcion == "9")
    	{
    		mtx_actual.Tipo_a_Graficar();
    	}
    	else if (opcion == "10")
    	{
    		/*Filtros_lista_cir lis_c;
	
			lis_c.Insert_nod(1, NULL);
			lis_c.Insert_nod(2);
			lis_c.Insert_nod(3);
			lis_c.Insert_nod(4);
			lis_c.Insert_nod(55);
			
			lis_c.Lista_imprimir_ade();
			
			cout<<"lis_c.size: "<<lis_c.size <<endl;  
			
			cout<<"--imprime atras-----"<<endl;
			lis_c.Lista_imprimir_atra();
			lis_c.Graf_filters();*/

    	}
		else if (opcion == "7")
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

void tipo_filtro()
{
	string opcion;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    //cout <<"***********FILTERS***********\n\n";
		cout <<"1. Imagen Completa"<<endl;
		cout <<"2. Por Capa"<<endl;
		cout<<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		//cout <<"**************************\n\n";
		
		cout<<"Selecciona un Filtro:\n" ; cin>>opcion;
    	cout <<"Reporte: "<<opcion<<endl;
    	
    	if (opcion == "1")
    	{
    		//convirtiendo toda la matriz
    		matrix mtx_invertido;
    		//mtx_actual
		}
		else if (opcion == "2")
    	{Select_capas();
		}
    	else if (opcion == "0")
    	{
    		men = false;
		}
		else
    	{
    		system("cls");
    		cout <<"(TIPO FILTRO) Tecla invalida, seleccione opcion valida "<<endl;
    		system("pause");
					
    
		} 
    	
	}
}

void menu_filters()
{
	string opcion;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********FILTERS***********\n\n";
		cout <<"a. NEGATIVE (NEGATIVO)"<<endl;
		cout <<"b. GRAYSCALE (ESCALA DE GRISES)"<<endl;
		cout <<"c. MIRROR (ESPEJO)"<<endl;
		cout <<"d. COLLAGE (COLLAGE)"<<endl;
		cout <<"e. MOSAIC (MOSAICO)"<<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un Filtro:\n" ; cin>>opcion;
    	cout <<"Reporte: "<<opcion<<endl;
    	
    	if (opcion == "a" || opcion == "A")
    	{
    		tipo_filtro();
		}
		else if (opcion == "b" || opcion == "B")
    	{
    		tipo_filtro();
		}
    	else if (opcion == "0")
    	{
    		men = false;
		}
		else
    	{
    		system("cls");
    		cout <<"(FILTERS) Tecla invalida, seleccione opcion valida "<<endl;
    		system("pause");
					
    
		} 
    	
	}
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

void Select_capas()
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********LAYERS***********\n\n";
	    
    	mtx_actual.Capas_para_select();
		
		cout <<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un capa:\n" ; cin>>opcion;
    	//cout <<"imagen: "<<opcion<<endl;
    	
		if (opcion == "0")
    	{
    		men = false;
		}
		else if (opcion != "0" )
    	{
			arbol_im.index_root = 0;
	    	index = atoi(opcion.c_str());
	    	
			arbol_im.Buscando_x_index(index);
			
			if (arbol_im.imagen_actual_nod != NULL)
	    	{
	    		//cout <<"arbol_im.imagen_actual_nod->data: "<<arbol_im.imagen_actual_nod->data<<endl;
	    		
	    		cout <<"Imagen Seleccionada: "<<arbol_im.imagen_actual_nod->data<<endl;
	    		mtx_actual = arbol_im.imagen_actual_nod->mat;
				system("pause");
				men = false;
			}
			else
			{
				cout <<"Imagen no encontrada, selecciona una imagen valida"<<endl;
				system("pause");
			}
    	
    		
		}
		else
    	{
    		system("cls");
    		cout <<"(Images) Tecla invalida, selecciona opcion valida "<<endl;
    		system("pause");
					
    
		} 
    	
	}
}

void Select_images()
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********IMAGES***********\n\n";
	    
	    arbol_im = read_ar.Retornando_arbol();
    	arbol_im.inorder();
		
		cout <<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un imagen:\n" ; cin>>opcion;
    	//cout <<"imagen: "<<opcion<<endl;
    	
		if (opcion == "0")
    	{
    		men = false;
		}
		else if (opcion != "0" )
    	{
			arbol_im.index_root = 0;
	    	index = atoi(opcion.c_str());
	    	
			arbol_im.Buscando_x_index(index);
			
			if (arbol_im.imagen_actual_nod != NULL)
	    	{
	    		//cout <<"arbol_im.imagen_actual_nod->data: "<<arbol_im.imagen_actual_nod->data<<endl;
	    		
	    		cout <<"Imagen Seleccionada: "<<arbol_im.imagen_actual_nod->data<<endl;
	    		mtx_actual = arbol_im.imagen_actual_nod->mat;
				system("pause");
				men = false;
			}
			else
			{
				cout <<"Imagen no encontrada, selecciona una imagen valida"<<endl;
				system("pause");
			}
    	
    		
		}
		else
    	{
    		system("cls");
    		cout <<"(Images) Tecla invalida, selecciona opcion valida "<<endl;
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
