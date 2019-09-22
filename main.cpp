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

#include <direct.h> //para crear carpeta

using namespace std;

Leer_archivo read_ar; //para importacion
arbol_images arbol_im; //arbol de imagenes

Filtros_lista_cir list_filtros;

void MenuReport();
void Report_tran();

matrix mtx_actual;

//matrix mtx_filtros_actul;

void Select_images();
void menu_filters();
void Select_capas(string name_filtro);
void menu_mirror();

void Select_images_exports();
void Select_images_Report();

void tipo_graff(matrix mat_graph);
void Select_capas_ima_report(matrix mat_rep); //para capas de reporte 

void tipo_linealizacion(matrix mat_graph, int index);
void tipo_modificacion();
void datos_modificacion(matrix mat_modif);
int Select_capas_para_modif(matrix mat_modif); //para encontrar capa a modificar
void Select_filters_modif(); // para modificar el filtro

//tipo a graficar, matriz o lienal
string s_tipo_graf_mat;

void Select_filters_reportes();


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
    	system("cls");
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
		cout <<"7. Exit"<<endl;
		//cout <<"7. Exit"<<endl<<endl;
		cout <<"20. Insert Image (Carpetas)"<<endl<<endl;
		
		/*cout <<"8. prueba matriz"<<endl<<endl;
		cout <<"9. graficando matriz"<<endl<<endl;
		cout <<"10. verificando lista layes"<<endl<<endl;
		cout <<"11. leyendo lista layes"<<endl<<endl;*/
		cout <<"**************************\n\n";
		
    	cout<<"Selecciona opcion:\n" ; cin>>opcion;
    	cout <<"opcion: "<<opcion<<endl;
    	if (opcion == "1")
    	{
    		//aqui importamos la archivo
			read_ar.con_carpeta = "N";	
			read_ar.name_carpeta = "";	
			read_ar.read_path();
			//cout <<"read_ar.arbol.size: "<<read_ar.arbol.size <<endl;
			//cout <<"termina aqui****--- "<<endl<<endl;
			system("pause");
			
		}
		else if (opcion == "20")
    	{
    		system("cls");
    		string carpeta;
    		cout<<"Nombre carpeta:\n" ; cin>>carpeta;
    		read_ar.con_carpeta = "S";
    		read_ar.name_carpeta = carpeta;
    		read_ar.read_path();
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
		else if (opcion == "4")
    	{
    		if (arbol_im.imagen_actual_nod != NULL){
    			tipo_modificacion();
			} else {
				cout <<"No tiene una imagen seleccioanda. "<<endl;
				system("pause");
			}
		}
		/*para exportar el cubo*/
		else if (opcion == "5")
    	{
    		if (arbol_im.imagen_actual_nod != NULL){
    			Select_images_exports();
			} else {
				cout <<"No tiene una imagen seleccioanda. "<<endl;
				system("pause");
			}
			//mtx_actual.Generando_css(arbol_im.imagen_actual_nod->pix_ima_w,arbol_im.imagen_actual_nod->pix_ima_h, arbol_im.imagen_actual_nod->pix_w, arbol_im.imagen_actual_nod->pix_h, arbol_im.imagen_actual_nod->no_pixel_w, arbol_im.imagen_actual_nod->no_pixel_h);
			//system("pause");
		} 
		
		else if (opcion == "6")
    	{
    		MenuReport();
		} 
		/*else if (opcion == "8")
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
			mt.Tipo_a_Graficar(0);
	
		}
		else if (opcion == "9")
    	{
    		mtx_actual.Tipo_a_Graficar(0);
    	}
    	else if (opcion == "10")
    	{
    		Filtros_lista_cir lis_c;
	
			lis_c.Insert_nod(1, mtx_actual,"", 0,0);
			lis_c.Insert_nod(2, mtx_actual,"", 0,0);
			lis_c.Insert_nod(3, mtx_actual,"", 0,0);
			lis_c.Insert_nod(4, mtx_actual,"", 0,0);
			lis_c.Insert_nod(55, mtx_actual,"", 0,0);
			
			lis_c.Lista_imprimir_ade();
			
			cout<<"lis_c.size: "<<lis_c.size <<endl;  
			
			cout<<"--imprime atras-----"<<endl;
			lis_c.Lista_imprimir_atra();
			lis_c.Graf_filters();

    	}
    	else if (opcion == "11")
    	{
			list_filtros.Lista_print_filters();
			

    	}*/
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
	/*if(all_capa == 0){*/
		if(name_filtro == "NEGATIVE"){
			
			matrix mtx_negativo;
			mtx_negativo = mtx_actual.imagen_original("N", a_no_pixel_x, a_no_pixel_y, all_capa);
			
			list_filtros.Insert_nod(all_capa, mtx_negativo, "NEGATIVE", 0,0);
			
			//mtx_negativo.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y, "ejemplo", "ejemplo", "S");
			
		}
		else if(name_filtro == "GRAYSCALE"){
			
			matrix mtx_gray;
			mtx_gray = mtx_actual.imagen_original("G", a_no_pixel_x, a_no_pixel_y, all_capa);
			
			//mtx_gray.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y, "ejemplo", "ejemplo", "");
			
			list_filtros.Insert_nod(all_capa, mtx_gray, "GRAYSCALE", 0,0);
			
		}

		else if(name_filtro == "X-MIRROR"){
			
    		matrix mtx_espejo_x;
    		mtx_espejo_x = mtx_actual.imagen_original("EX", a_no_pixel_x, a_no_pixel_y, all_capa);
    		
    		//mtx_espejo_x.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y, "ejemplo", "ejemplo", "");
    		
    		list_filtros.Insert_nod(all_capa, mtx_espejo_x, "X-MIRROR", 0,0);
		}
		else if(name_filtro == "Y-MIRROR"){
			
    		matrix mtx_espejo_y;
    		mtx_espejo_y = mtx_actual.imagen_original("EY", a_no_pixel_x, a_no_pixel_y, all_capa);
    		
    		//mtx_espejo_y.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y, "ejemplo", "ejemplo", "");
			list_filtros.Insert_nod(all_capa, mtx_espejo_y, "Y-MIRROR", 0,0);
		}
		else if(name_filtro == "XY-DOUBLE MIRROR"){

    		matrix mtx_espejo_xy;
    		mtx_espejo_xy = mtx_actual.imagen_original("EXY", a_no_pixel_x, a_no_pixel_y, all_capa);
    		
    		//mtx_espejo_xy.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y, "ejemplo", "ejemplo", "");
			list_filtros.Insert_nod(all_capa, mtx_espejo_xy, "XY-DOUBLE MIRROR", 0,0);
		}
		
		if(all_capa == 0){
			cout <<"Filtro: "<<name_filtro<<" Aplicado."<<endl;
		} else{
			cout <<"Filtro: "<<name_filtro<<" Aplicado, Capa "<<all_capa<<endl;
		}
		system("pause");
		
	/*}*/
	/*else if(all_capa != 0){
		
		if(name_filtro == "X-MIRROR"){
			
    		matrix mtx_espejo_x_cap;
    		mtx_espejo_x_cap = mtx_actual.imagen_original("EX", a_no_pixel_x, a_no_pixel_y, all_capa);
    		
    		mtx_espejo_x_cap.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y);
    		
    		list_filtros.Insert_nod(all_capa, mtx_espejo_x_cap, "X-MIRROR capa ");
		}
		
		cout <<"Filtro: "<<name_filtro<<" Aplicado, Capa "<<all_capa<<endl;
		system("pause");
		
	}*/
}

void aplicando_filter_mat(int all_capa, string name_filtro, int rep_x, int rep_y)
{
		if(name_filtro == "COLLAGE"){
			
    		matrix mtx_collage;
    		mtx_collage = mtx_actual.imagen_original_col_mos("C", a_no_pixel_x, a_no_pixel_y, all_capa, rep_x, rep_y);
    		
    
			//mtx_collage.Generando_css(rep_x*a_pix_ima_w, rep_y*a_pix_ima_h, a_pix_w, a_pix_h, rep_x*a_no_pixel_x, rep_y*a_no_pixel_y, "ejemplo", "ejemplo", "");
    		
    		list_filtros.Insert_nod(all_capa, mtx_collage, "COLLAGE", rep_x, rep_y);
    		
    		//mtx_collage.Tipo_a_Graficar();
    		//mtx_collage.print_node_cor_orde_zz();
		}
		else if(name_filtro == "MOSAIC"){
			
    		matrix mtx_mosaic;
    		mtx_mosaic = mtx_actual.imagen_original_una_capa("M", a_no_pixel_x, a_no_pixel_y, all_capa);
    		
    		/////////////mtx_mosaic.Generando_css(rep_x*a_pix_ima_w, rep_y*a_pix_ima_h, a_pix_w, a_pix_h, rep_x*a_no_pixel_x, rep_y*a_no_pixel_y, "ejemplo", "ejemplo");
    		
    		mtx_mosaic = mtx_mosaic.imagen_original_col_mos("M", a_no_pixel_x, a_no_pixel_y, all_capa, a_no_pixel_x, a_no_pixel_y);
    		
    		
    		list_filtros.Insert_nod(all_capa, mtx_mosaic, "MOSAIC",0 ,0);
    		
    		//cout<<endl<<endl<<"cordenada abajo, derecha"<<endl; 
			//mtx_mosaic.print_node_cor_orde_zz();
			
			
			//cout<<endl<<endl<<"cordenada derecha, abajo"<<endl; 
			////sm->print_node_cor_orde_der_abaj();
			//mtx_mosaic.print_node_cor_orde_der_abaj_z();
			
    		//mtx_collage.Tipo_a_Graficar();
    		//mtx_collage.print_node_cor_orde_zz();
		}
		else if(name_filtro == "MOSAICF2"){
			
    		matrix mtx_mosaic_f2;
    		mtx_mosaic_f2 = mtx_actual.imagen_original_una_capa("M2", a_no_pixel_x, a_no_pixel_y, all_capa);
    		
    		//mtx_mosaic_f2 = mtx_mosaic_f2.imagen_original_col_mos("M2", a_no_pixel_x, a_no_pixel_y, all_capa, a_no_pixel_x, a_no_pixel_y);
    		
    		list_filtros.Insert_nod(all_capa, mtx_mosaic_f2, "MOSAICF2",0 ,0);
    		
    		//cout<<endl<<endl<<"cordenada abajo, derecha"<<endl; 
			//mtx_mosaic.print_node_cor_orde_zz();
		}
		
		if(all_capa == 0){
			cout <<"Filtro: "<<name_filtro<<" Aplicado."<<endl;
		} else{
			cout <<"Filtro: "<<name_filtro<<" Aplicado, Capa "<<all_capa<<endl;
		}
		system("pause");
		
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
    	{Select_capas(name_filtro);
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

void tipo_linealizacion(matrix mat_rep, int index)
{
	string opcion;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********TIPO LINEALIZACION***********\n\n";
		cout <<"1. por Fila"<<endl;
		cout <<"2. por Columna"<<endl;
		cout <<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un tipo de linealizacion:\n" ; cin>>opcion;
    	cout <<"Reporte: "<<opcion<<endl;
    	
    	if (opcion == "1")
    	{
    		string tip_lin = "1";
    		cout<<"tipo\n" ;
    		cout<<"1 = a la derecha y abajo:\n" ;
    		cout<<"2 = todo a la derecha (puede que no pueda grapiz no soporte todo a la fecha):\n" ; cin>>tip_lin;
    		if (tip_lin == "1")
    		{
				mat_rep.Tipo_a_Graficar_linear(index, "LIN");
			}
			else if (tip_lin == "2")
    		{
				mat_rep.Tipo_a_Graficar_linear_f2(index, "LIN");
			}
    		
		}
		else if (opcion == "2")
    	{
    		string tip_lin = "1";
    		cout<<"tipo\n" ;
    		cout<<"1 = a la derecha y abajo:\n" ;
    		cout<<"2 = todo a la derecha (puede que no pueda grapiz no soporte todo a la fecha):\n" ; cin>>tip_lin;
    		if (tip_lin == "1")
    		{
    		mat_rep.Tipo_a_Graficar_linear(index, "COL");
    		}
			else if (tip_lin == "2")
    		{
				mat_rep.Tipo_a_Graficar_linear_f2(index, "COL");
			}
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

/////edicion original o por filtros
void tipo_modificacion()
{
	string opcion;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********MANUAL EDITING***********\n\n";
		cout <<"1. Original Image"<<endl;
		cout <<"2. Filters"<<endl;
		cout <<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un de modificacion:\n" ; cin>>opcion;
    	cout <<"Reporte: "<<opcion<<endl;
    	
    	if (opcion == "1")
    	{
    		datos_modificacion(mtx_actual);
		}
		else if (opcion == "2")
    	{
    		if (list_filtros.size <= 1){
    			cout <<"No se han aplicado filtros a la imagen seleccionada. "<<endl;
    			system("pause");
			}else{
				Select_filters_modif();
			}
		}
    	else if (opcion == "0")
    	{
    		men = false;
		}
		else
    	{
    		system("cls");
    		cout <<"(MANUAL EDITING) Tecla invalida, seleccione opcion valida "<<endl;
    		system("pause");
					
		}     	
	}
}

void datos_modificacion(matrix mat_modif)
{
	string opcion;
	string new_color;
	int x;
	int y;
	int r, g,b;
	int capa;
	bool men = true;
	bool encon_corde = false;
    //while(men)
    //{
    	//capa = Select_capas_para_modif(mtx_actual);
    	capa = Select_capas_para_modif(mat_modif);
    	
		system("cls");
	    cout <<"***********DATA EDITING***********\n\n";
		
		while(encon_corde == false)
    	{
    		cout<<"Desea Salir? S/N:\n" ; cin>>opcion;
    		if (opcion =="S" || opcion =="s"){
    			break;
			}
    		
    		system("cls");
	    	cout <<"***********DATA EDITING***********\n\n";
	    	
			cout<<"Ingrese Coordenada en X:\n" ; cin>>x;
	    	//cout <<"Reporte: "<<x<<endl;
	    	cout<<"Ingrese Coordenada en Y:\n" ; cin>>y;
	    	//cout <<"Reporte: "<<y<<endl;
	    	
    	///buscando cordeanas en la capa de la matriz
	    	//encon_corde = mtx_actual.Buscando_cordenadas(capa, x, y);
	    	encon_corde = mat_modif.Buscando_cordenadas(capa, x, y);
	    	cout <<endl;
	    	if (encon_corde == false){
	    		cout <<"la cordenada: ("<<x<<","<<y<<") No se ha encontrado"<<endl;
	    		system("pause");
			}
	    }
    	
    	if (encon_corde == true){
	    	cout<<"*** Color Formato RGB ***\n" ;
	    	cout<<"valor R:\n" ; cin>>r;
	    	//cout <<"Reporte: "<<r<<endl;
	    	cout<<"valor G:\n" ; cin>>g;
	    	//cout <<"Reporte: "<<g<<endl;
	    	cout<<"valor B:\n" ; cin>>b;
	    	//cout <<"Reporte: "<<b<<endl;
	    	
	    	//modificando valor
	    	ostringstream ne_r, ne_g, ne_b;
	    	ne_r<<r;
	    	ne_g<<g;
	    	ne_b<<b;
	    	new_color = ne_r.str() + "-" + ne_g.str() + "-" +ne_b.str();
	    	//mtx_actual.Modificando_cordenadas(capa, x, y, new_color);
	    	mat_modif.Modificando_cordenadas(capa, x, y, new_color);
			cout <<"Se actualizo a nuevo color ingresado"<<endl;
	    	system("pause");
    	}
		cout <<endl<<endl;
		//cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
}

void tipo_filter_rep()
{
	string opcion;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********TIPO FILTER REPORT***********\n\n";
		cout <<"1. All filters report"<<endl;
		cout <<"2. Individual Filter Report"<<endl;
		cout <<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un tipo de reporte de filtro:\n" ; cin>>opcion;
    	cout <<"Reporte: "<<opcion<<endl;
    	
    	if (opcion == "1")
    	{
    		if (list_filtros.size <= 1){
    			cout <<"No se han aplicado filtros a la imagen seleccionada. "<<endl;
    			system("pause");
			}else{
				list_filtros.Graf_filters_all();
			}
    		
		}
		else if (opcion == "2")
    	{
			if (list_filtros.size <= 1){
    			cout <<"No se han aplicado filtros a la imagen seleccionada. "<<endl;
    			system("pause");
			}else{
				Select_filters_reportes();
			}
			
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

void tipo_graff(matrix mat_graph)
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
    		//mat_graph.Tipo_a_Graficar();
    		if (s_tipo_graf_mat == "MAT"){
    			mat_graph.Tipo_a_Graficar(0);	
			}
			else if (s_tipo_graf_mat == "LIN"){
				//mat_graph.Tipo_a_Graficar_linear(0);
				tipo_linealizacion(mat_graph, 0);
			}
			cout <<"Reporte Generado "<<endl;
		}
		else if (opcion == "2")
    	{Select_capas_ima_report(mat_graph);
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

int Select_capas_para_modif(matrix mat_modif)
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {	
		system("cls");
	    cout <<"***********LAYERS EDITING***********\n\n";
	    
    	mat_modif.Capas_para_select();
		
		cout <<endl<<endl;
		cout <<"0. Regresar"<<endl<<endl;
		cout <<"**************************\n\n";
		
		cout<<"Selecciona un capa:\n" ; cin>>opcion;
    	//cout <<"imagen: "<<opcion<<endl;
    	
		if (opcion == "0")
    	{
    		return -1;
    		men = false;
		}
		else if (opcion != "0" )
    	{
			bool encontrado;
			encontrado = false;
			
	    	index = atoi(opcion.c_str());
			encontrado = mat_modif.Buscando_capa(index);
			
			if (encontrado == true)
	    	{
	    		return index;
			}
			else
			{
				cout <<"Capa no encontrada, selecciona una capa valida"<<endl;
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

void Select_filters_modif()
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {
		system("cls");
	    cout <<"*********** FILTER EDITING";
	    if (arbol_im.imagen_actual_nod != NULL)
    	{ cout<<" ("<< arbol_im.imagen_actual_nod->data<<") "; }
    	cout <<"***********\n\n";
	    
    	list_filtros.Lista_print_filters();
		
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
			bool encontrado;
			encontrado = false;
			
	    	index = atoi(opcion.c_str());
	    	
			encontrado = list_filtros.Buscando_ima(index);
			if (encontrado == true)
	    	{
	    		datos_modificacion(list_filtros.filter_a_reportar->mat);
	    		//mtx_filtros_actul = list_filtros.filter_a_reportar->mat;
	    		//datos_modificacion(mtx_filtros_actul);
			}
			else
			{
				cout <<"imagen no encontrada, selecciona una imagen valida"<<endl;
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
void Select_capas_ima_report(matrix mat_rep)
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {	
		system("cls");
	    cout <<"***********LAYERS***********\n\n";
	    
    	mat_rep.Capas_para_select();
		
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
			encontrado = mat_rep.Buscando_capa(index);
			
			if (encontrado == true)
	    	{
	    		//cout <<"Capa Seleccionada: "<<index<<endl;
	    		if (s_tipo_graf_mat == "MAT"){
    				mat_rep.Tipo_a_Graficar(index);	
				}
				else if (s_tipo_graf_mat == "LIN"){
					//mat_rep.Tipo_a_Graficar_linear(index);
					tipo_linealizacion(mat_rep, index);
				}
	    		
				//system("pause");
				cout <<"Reporte Generado "<<endl;
				men = false;
			}
			else
			{
				cout <<"Capa no encontrada, selecciona una capa valida"<<endl;
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
		cout <<"f. MOSAIC F2 (MOSAICO FORMA 2)"<<endl<<endl;
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
		else if (opcion == "d" || opcion == "D")
    	{
    		int rep_x, rep_y;
    		system("cls");
    		cout<<"Cantidad de repeticiones en X:\n" ; cin>>rep_x;
    		cout<<"Cantidad de repeticiones en Y:\n" ; cin>>rep_y;
    		
    		aplicando_filter_mat(0,"COLLAGE", rep_x, rep_y);
    		//tipo_filtro("GRAYSCALE");
		}	
		else if (opcion == "e" || opcion == "E")
    	{
    		int rep_x, rep_y;
    		//system("cls");
    		//cout<<"m Cantidad de repeticiones en X:\n" ; cin>>rep_x;
    		//cout<<"m Cantidad de repeticiones en Y:\n" ; cin>>rep_y;
    		
    		aplicando_filter_mat(0,"MOSAIC", rep_x, rep_y);
		}
		else if (opcion == "f" || opcion == "F")
    	{ 
    		int rep_x, rep_y;
    		aplicando_filter_mat(0,"MOSAICF2", rep_x, rep_y);
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
	//////arbol_im = read_ar.Retornando_arbol();
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
    		//arbol_im = read_ar.Retornando_arbol();
    		arbol_im = read_ar.Retornando_arbol();
    		arbol_im.Graficando_arbol();
    		cout <<"Reporte Generado "<<endl;
    		system("pause");
		}
		else if (repor == "b" || repor == "B")
    	{
    		s_tipo_graf_mat = "MAT";
    		Select_images_Report();
    		//cout <<"Reporte Generado "<<endl;
    		//system("pause");
		}
		else if (repor == "c" || repor == "C")
    	{
    		s_tipo_graf_mat = "LIN";
    		Select_images_Report();
		}
		else if (repor == "d" || repor == "D")
    	{
    		Report_tran();
		}
		else if (repor == "e" || repor == "E")
    	{
    		tipo_filter_rep();
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
///creaidno los archivos
void creando_file_imagen(matrix mtx_export, NodeCir *nod_fil)
{
	////creando carpeta de export preder
	string carpeta_ima, ima_ac, nombre_completo;
	ima_ac = arbol_im.imagen_actual_nod->data;
	mkdir("Exports");
	carpeta_ima = "Exports\\" + ima_ac;
	mkdir(carpeta_ima.c_str());
	nombre_completo = carpeta_ima + "\\" + list_filtros.name_actual;
	//cout <<"nombre_completo: "<<nombre_completo <<endl;
	//cout <<"nod_fil->filtro: "<<nod_fil->filtro <<endl;
	
	//cout <<"a_no_pixel_x* a_no_pixel_x: "<<a_no_pixel_x*a_no_pixel_x <<endl;
	//cout <<"a_no_pixel_x * a_no_pixel_x: "<<a_no_pixel_x * a_no_pixel_x <<endl;
	
	//cout <<"a_pix_ima_w: "<<a_pix_ima_w<<endl;
	//cout <<"a_pix_ima_h: "<<a_pix_ima_h <<endl;
	
	int pix_x, pix_y;
	int canvas_m_x, canvas_m_y;

	
	if(nod_fil->filtro == "MOSAIC"){ 
		//matrix mtx_export_tempo;
		//mtx_export_tempo = mtx_export;
		
		pix_x = a_pix_w*0.15;
		pix_y = a_pix_h*0.15;
		
		//cout <<"a_pix_w: "<<a_pix_w<<endl;
		//cout <<"a_pix_h: "<<a_pix_h <<endl;
		
		//cout <<"2 pix_x: "<<pix_x<<endl;
		//cout <<"2 pix_y: "<<pix_y <<endl;
		
		//cout <<"canvas_x: "<<a_pix_ima_w*a_no_pixel_x<<endl;
		//cout <<"canvas_y: "<<a_pix_ima_h*a_no_pixel_y <<endl;
		
		canvas_m_x = pix_x*a_no_pixel_x*a_no_pixel_x;
		canvas_m_y = pix_y*a_no_pixel_y*a_no_pixel_y;
		//cout <<"2 canvas_x: "<<canvas_m_x<<endl;
		//cout <<"2 canvas_y: "<<canvas_m_y<<endl;
		
    	mtx_export.Generando_css(canvas_m_x, canvas_m_y, pix_x, pix_y, a_no_pixel_x * a_no_pixel_x, a_no_pixel_y * a_no_pixel_y, nombre_completo, list_filtros.name_actual, "");
		//mtx_export.Generando_css(rep_x*a_pix_ima_w, rep_y*a_pix_ima_h, a_pix_w, a_pix_h, rep_x*a_no_pixel_x, rep_y*a_no_pixel_y, "ejemplo", "ejemplo");
    }
	else if(nod_fil->filtro == "MOSAICF2"){ 
	
		int pix_peq_x, pix_peq_y;
		
		pix_peq_x = a_pix_w/a_no_pixel_x;
		pix_peq_y = a_pix_h/a_no_pixel_y;
		
		pix_peq_x = pix_peq_x*2;
		pix_peq_y = pix_peq_y*2;
		//cout <<"pix_peq_x: "<<pix_peq_x <<endl;
		//cout <<"pix_peq_y: "<<pix_peq_y<<endl;
		
		pix_x = pix_peq_x * a_no_pixel_x;
		pix_y = pix_peq_y * a_no_pixel_y;

		//cout <<"pix_x: "<<pix_x <<endl;
	//	cout <<"pix_y: "<<pix_y<<endl;

		canvas_m_x = a_no_pixel_x*pix_x;
		canvas_m_y = a_no_pixel_y*pix_y;
		
		//cout <<"canvas_m_x: "<<canvas_m_x <<endl;
		//cout <<"canvas_m_y: "<<canvas_m_y<<endl;
	
    	//mtx_export.Generando_css_mosaic(canvas_m_x, canvas_m_y, pix_x, pix_y, a_no_pixel_x * a_no_pixel_x, a_no_pixel_y * a_no_pixel_y, nombre_completo, list_filtros.name_actual, "", pix_peq_x, pix_peq_y );
    	mtx_export.Generando_css_mosaic(canvas_m_x,canvas_m_y, pix_x, pix_y, a_no_pixel_x, a_no_pixel_y, nombre_completo, list_filtros.name_actual, "", pix_peq_x, pix_peq_y);
    	
	}		
	else if(nod_fil->filtro == "COLLAGE"){ 
	
		int rep_x, rep_y;
		rep_x =nod_fil->rep_x;
		rep_y =nod_fil->rep_y;

    	mtx_export.Generando_css(rep_x*a_pix_ima_w, rep_y*a_pix_ima_h, a_pix_w, a_pix_h, rep_x*a_no_pixel_x, rep_y*a_no_pixel_y, nombre_completo, list_filtros.name_actual, "");
	
	}
	else if(nod_fil->filtro == "NEGATIVE"){ 
		//verificando si es toda la capa
		string neg_all ="";
		if(nod_fil->val == 0){ 
			neg_all = "S";
		}
		
		mtx_export.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y, nombre_completo, list_filtros.name_actual,neg_all);
	
	} else {
		mtx_export.Generando_css(a_pix_ima_w,a_pix_ima_h, a_pix_w, a_pix_h, a_no_pixel_x, a_no_pixel_y, nombre_completo, list_filtros.name_actual, "");
	
	}
	
	//cout <<"*yrtmina la exportacion*"<<endl;
	//system("pause");	
	
}
//////////////para imagen
void Select_images_exports()
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********EXPORT IMAGE";
	    if (arbol_im.imagen_actual_nod != NULL)
    	{ cout<<" ("<< arbol_im.imagen_actual_nod->data<<") "; }
    	cout <<"***********\n\n";
	    
    	list_filtros.Lista_print_filters();
		
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
			bool encontrado;
			encontrado = false;
			
	    	index = atoi(opcion.c_str());
	    	
			encontrado = list_filtros.Buscando_ima(index);
			if (encontrado == true)
	    	{
	    		
	    		matrix mtx_export;
				mtx_export = list_filtros.return_mat_ima(index);
				
				NodeCir *nod_fil;
				nod_fil = list_filtros.return_node_ima(index);
				
				//cout <<"antes de exportar nod_fil->filtro: "<<nod_fil->filtro <<endl;
				//system("pause");
				
				//nombre de filtro
				string fil_name;
	    		
	    		creando_file_imagen(mtx_export, nod_fil);
	    		
	    		cout <<"imagen exportada: "<<index<<endl;
				system("pause");
				//men = false;
			}
			else
			{
				cout <<"imagen no encontrada, selecciona una imagen valida"<<endl;
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

////reporte filter matrix
void Select_filters_reportes()
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {
		system("cls");
	    cout <<"***********INDIVIDUAL FILTER REPORT";
	    if (arbol_im.imagen_actual_nod != NULL)
    	{ cout<<" ("<< arbol_im.imagen_actual_nod->data<<") "; }
    	cout <<"***********\n\n";
	    
    	list_filtros.Lista_print_filters();
		
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
			bool encontrado;
			encontrado = false;
			
	    	index = atoi(opcion.c_str());
	    	
			encontrado = list_filtros.Buscando_ima(index);
			if (encontrado == true)
	    	{
	    		//cout <<"list_filtros.filter_a_reportar->: "<<list_filtros.filter_a_reportar->filtro<<endl;
	    		s_tipo_graf_mat = "MAT";
	    		tipo_graff(list_filtros.filter_a_reportar->mat);	
				//system("pause");
				//men = false;
			}
			else
			{
				cout <<"imagen no encontrada, selecciona una imagen valida"<<endl;
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

void Select_capas(string name_filtro)
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
	    		aplicando_filter_mat(index, name_filtro);
				//system("pause");
				men = false;
			}
			else
			{
				cout <<"Capa no encontrada, selecciona una capa valida"<<endl;
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
	    		
	    		///agregando por defecto la imagen por defecto
	    		//primero limpiando lista
	    		Filtros_lista_cir fil_clean;
	    		list_filtros = fil_clean;
	    		list_filtros.Insert_nod(0, mtx_actual, arbol_im.imagen_actual_nod->data, 0, 0);
	    		
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

void Select_images_Report()
{
	string opcion;
	int index;
	bool men = true;
    while(men)
    {
    	
		system("cls");
	    cout <<"***********IMAGES REPORTS***********\n\n";
	    
	    arbol_images arbol_rep; 
	    arbol_rep = read_ar.Retornando_arbol();
    	arbol_rep.inorder();
		
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
			arbol_rep.index_root = 0;
	    	index = atoi(opcion.c_str());
	    	
			arbol_rep.Buscando_x_index_report(index);
			
			if (arbol_rep.imagen_a_reportar != NULL)
	    	{
	    		cout <<"Imagen Seleccionada: "<<arbol_rep.imagen_a_reportar->data<<endl;
	    		tipo_graff(arbol_rep.imagen_a_reportar->mat);
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
		arbol_im = read_ar.Retornando_arbol();
		
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
