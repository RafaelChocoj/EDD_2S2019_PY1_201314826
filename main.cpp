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
void menu_mirror();

//para imagen actual
int a_pix_ima_w, a_pix_ima_h;
int a_pix_w, a_pix_h;
int a_no_pixel_x, a_no_pixel_y;

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
		cout <<"11. leyendo lista layes"<<endl<<endl;
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
    		if (arbol_im.imagen_actual_nod != NULL){
    			menu_filters();
			} else {
				cout <<"No tiene una imagen seleccioanda. "<<endl;
				system("pause");
			}
    		
		}
		/*para exportar el cubo*/
		else if (opcion == "5")
    	{
			mtx_actual.Generando_css(arbol_im.imagen_actual_nod->pix_ima_w,arbol_im.imagen_actual_nod->pix_ima_h, arbol_im.imagen_actual_nod->pix_w, arbol_im.imagen_actual_nod->pix_h, arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
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
    		Filtros_lista_cir lis_c;
	
			lis_c.Insert_nod(1, mtx_actual,"");
			lis_c.Insert_nod(2, mtx_actual,"");
			lis_c.Insert_nod(3, mtx_actual,"");
			lis_c.Insert_nod(4, mtx_actual,"");
			lis_c.Insert_nod(55, mtx_actual,"");
			
			lis_c.Lista_imprimir_ade();
			
			cout<<"lis_c.size: "<<lis_c.size <<endl;  
			
			cout<<"--imprime atras-----"<<endl;
			lis_c.Lista_imprimir_atra();
			lis_c.Graf_filters();

    	}
    	else if (opcion == "11")
    	{
			list_filtros.Lista_print_filters();

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

void aplicando_filter_mat(int all_capa, string name_filtro)
{
	if(all_capa == 0){
		

		if(name_filtro == "NEGATIVE"){
			
			matrix mtx_negativo;
			mtx_negativo = mtx_actual.imagen_original("N", a_no_pixel_x, a_no_pixel_y);
			list_filtros.Insert_nod(0, mtx_negativo, "NEGATIVE");
			
			mtx_negativo.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y);
			
		}
		
		else if(name_filtro == "X-MIRROR"){
			
    		matrix mtx_espejo_x;
    		mtx_espejo_x = mtx_actual.imagen_original("EX", arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
    		
    		mtx_espejo_x.Generando_css(arbol_im.imagen_actual_nod->pix_ima_w,arbol_im.imagen_actual_nod->pix_ima_h, arbol_im.imagen_actual_nod->pix_w, arbol_im.imagen_actual_nod->pix_h, arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
    		
    		list_filtros.Insert_nod(0, mtx_espejo_x, "X-MIRROR");
		}
		else if(name_filtro == "Y-MIRROR"){
			
    		matrix mtx_espejo_y;
    		mtx_espejo_y = mtx_actual.imagen_original("EY", arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
    		
    		mtx_espejo_y.Generando_css(arbol_im.imagen_actual_nod->pix_ima_w,arbol_im.imagen_actual_nod->pix_ima_h, arbol_im.imagen_actual_nod->pix_w, arbol_im.imagen_actual_nod->pix_h, arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
			list_filtros.Insert_nod(0, mtx_espejo_y, "Y-MIRROR");
		}
		else if(name_filtro == "XY-DOUBLE MIRROR"){

    		matrix mtx_espejo_xy;
    		mtx_espejo_xy = mtx_actual.imagen_original("EXY", arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
    		
    		mtx_espejo_xy.Generando_css(arbol_im.imagen_actual_nod->pix_ima_w,arbol_im.imagen_actual_nod->pix_ima_h, arbol_im.imagen_actual_nod->pix_w, arbol_im.imagen_actual_nod->pix_h, arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
			list_filtros.Insert_nod(0, mtx_espejo_xy, "XY-DOUBLE MIRROR");
		}
		
		cout <<"Filtro: "<<name_filtro<<" Aplicado."<<endl;
		system("pause");
		
	}
	else if(all_capa != 0){
		
	}
}

void tipo_filtro(string name_filtro)
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
    		aplicando_filter_mat(0, name_filtro);		
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
    		tipo_filtro("NEGATIVE");
		}
		else if (opcion == "b" || opcion == "B")
    	{
    		tipo_filtro("GRAYSCALE");
		}
		else if (opcion == "c" || opcion == "C")
    	{
    		menu_mirror();
			
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

void menu_mirror()
{
	string opcion;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********MIRROR***********\n\n";
		cout <<"x. X-MIRROR (ESPEJO EN EJE X)"<<endl;
		cout <<"y. Y-MIRROR (ESPEJO EN EJE Y)"<<endl;
		cout <<"xy. DOUBLE MIRROR (ESPEJO EN AMBOS EJES)"<<endl;
		cout <<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un Filtro:\n" ; cin>>opcion;
    	cout <<"Reporte: "<<opcion<<endl;
    	
    	if (opcion == "x" || opcion == "X")
    	{
    		tipo_filtro("X-MIRROR");
		}
		else if (opcion == "y" || opcion == "Y")
    	{
    		tipo_filtro("Y-MIRROR");
		}
		else if (opcion == "xy" || opcion == "XY")
    	{
    		tipo_filtro("XY-DOUBLE MIRROR");
		}
    	else if (opcion == "0")
    	{
    		men = false;
		}
		else
    	{
    		system("cls");
    		cout <<"(MIRROR) Tecla invalida, seleccione opcion valida "<<endl;
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
			bool encontrado;
			encontrado = false;
			
	    	index = atoi(opcion.c_str());
	    	
			encontrado = mtx_actual.Buscando_capa(index);
			
			if (encontrado == true)
	    	{

	    		cout <<"Capa Seleccionada: "<<index<<endl;
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
	    		
	    		a_pix_ima_w = arbol_im.imagen_actual_nod->pix_ima_w;
	    		a_pix_ima_h = arbol_im.imagen_actual_nod->pix_ima_h;
	    		
	    		a_pix_w = arbol_im.imagen_actual_nod->pix_w;
	    		a_pix_h = arbol_im.imagen_actual_nod->pix_h;
	    		
	    		a_no_pixel_x = arbol_im.imagen_actual_nod->no_pixel_w;
	    		a_no_pixel_y = arbol_im.imagen_actual_nod->no_pixel_h;
	    		
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
