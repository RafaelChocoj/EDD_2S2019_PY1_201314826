#include "Matrix_cub.h"

#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <fstream>

#include <stdlib.h> 


using namespace std;


string file_css;
string file_html;

string name_capa;
    	
void matrix :: add (int value, int x, int y, int z, string valor, string file_capa) {
    	//1 crear header
    	//1.1 creade x header
    	//cout<<"x: " <<x<<endl; 
    	add_z_header(z, file_capa);
    	add_x_header(x, z);
    	add_y_header(y, z);  	
    	//1.2 create y header
    	
    	
    	//2 insert nodo
    	//node *new_node = new node(value);
    	node *new_node = new node(value, x, y, z, "N", valor);
    	//add_x(new_node, x);
    	//add_y(new_node, y, x);
    	
    	//primero insertamos profundidad
    	//add_z(new_node, x, y);
    	
    	//add_x(new_node, x, y);
    	//add_y(new_node, x, y);
    	
    	/* inicio para insertar nodo de profunidad inserta 0 en z	*/
    	node *new_z0 = new node(0, x, y, 0, "C", "C");
    	//node *new_z0 = new node(value, x, y, 0);

    	/* fin para insertar nodo de profunidad inserta 0 en z	*/
    	
    	///**********insertando nodos**************/////
    	add_x_header_z0(x, z);
    	add_y_header_z0(y, z);  
    	
    	//add_x(new_node, x, y, z);
    	//add_y(new_node, x, y, z);
    	
    	add_x_z0(new_z0, x, y, z);
    	add_y_z0(new_z0, x, y, z);
    	
    	add_x(new_node, x, y, z);
    	add_y(new_node, x, y, z);
    	
    	add_z(new_node, x, y, z);
    	
  
          
    }
    
    /*nodo en z*/
	void matrix :: add_z(node *new_node, int x, int y, int z){
    	node *tem = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		/*while(tem->cor_z != z){
    		tem = tem->capa_up;
		}	*/	
		//////////////*************************
		
    	/*recorre por x, la derecha*/	
    	while(tem->cor_x != x){
    		tem = tem->right;
		}
		
		/*recorre por y, abajo*/	
    	while(tem->cor_y != y){
    		tem = tem->down;
		}
		///****
		//cout<<"tem-x: "<< tem->cor_x <<" tem-y: "<< tem->cor_y <<endl;
		
		/*if(tem->down == NULL){
			tem->down = new_node;
			new_node->up = tem;
		}*/				
		if(tem->capa_up == NULL){
			tem->capa_up = new_node;
			new_node->capa_down = tem;
		} 
		
		/*si y es mejor al ultimo*/
		
		/*
			else if(tem->down->cor_y >= y ){
			
			node *ul_down = tem->down;
		   	
			tem->down = new_node;
			new_node->up = tem;
			
			//para que enlace el que estaba antes
			new_node->down = ul_down;
			ul_down->up = new_node;
		*/
		else if(tem->capa_up->cor_z >= z ){
			
			node *ul_down = tem->capa_up;
		   	
			tem->capa_up = new_node;
			new_node->capa_down = tem;
			
			//para que enlace el que estaba antes
			new_node->capa_up = ul_down;
			ul_down->capa_down = new_node;
		
		}
		else
		{
			/*
			node *temp_abaj = tem->down;
			while (temp_abaj->down != NULL && temp_abaj->down->cor_y < y ) { 
				temp_abaj = temp_abaj->down;
    		}
    		temp_abaj->down = new_node;
			new_node->up = temp_abaj;
			*/
			node *temp_abaj = tem->capa_up;
			while (temp_abaj->capa_up != NULL && temp_abaj->capa_up->cor_z < z ) { 
				temp_abaj = temp_abaj->capa_up;
    		}
    		temp_abaj->capa_up = new_node;
			new_node->capa_down = temp_abaj;
		}
		
	}
    
    
    void matrix :: add_x(node *new_node, int x, int y, int z){
    	node *tem = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(tem->cor_z != z){
    		tem = tem->capa_up;
		}		
		//////////////*************************
		
    	/*recorre por x, para insertar a abajo (y)*/	
    	//while(tem->data != x){
    	while(tem->cor_x != x){
    		tem = tem->right;
		}
		if(tem->down == NULL){
			tem->down = new_node;
			new_node->up = tem;
		} 
		/*si y es mejor al ultimo*/
		else if(tem->down->cor_y >= y ){
			

			node *ul_down = tem->down;
		   	
			tem->down = new_node;
			new_node->up = tem;
			
			//para que enlace el que estaba antes
			new_node->down = ul_down;
			ul_down->up = new_node;
		
		}
		else
		{
			node *temp_abaj = tem->down;
			while (temp_abaj->down != NULL && temp_abaj->down->cor_y < y ) { 
				temp_abaj = temp_abaj->down;
    		}
    		temp_abaj->down = new_node;
			new_node->up = temp_abaj;
		}
		
	}
	
	void matrix :: add_y(node *new_node, int x, int y, int z){
		node *tem= head;
		/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(tem->cor_z != z){
    		tem = tem->capa_up;
		}
		//cout<<"2222 z,y indice: "<<tem->data<<" "<<endl;
		//if( 4 == y && 7 == x ){cout<<"entra z: "<<z<<endl;}
		///////*********************************************1
				
		/*recorre por y, para insertar a la derecha (x)*/
		//while(tem->data != y){		
		while(tem->cor_y != y){
    		tem = tem->down;
		}
		if(tem->right == NULL){
			tem->right = new_node;
			new_node->left = tem;
			//if( 4 == y && 7 == x ){cout<<"y if 1"<<endl;}
		}
		else if(tem->right->cor_x >= x ){
		//else if( x < tem->right->cor_x ){
		   //if( 4 == y && 7 == x ){cout<<"y if 2"<<endl;}
		   	node *ul_der = tem->right;
		   	
			tem->right = new_node;
			new_node->left = tem;
			
			//para que enlace el que estaba antes
			new_node->right = ul_der;
			ul_der->left = new_node;
		}
		else
		{
			//if( 4 == y && 7 == x ){cout<<"y if 3"<<endl;}
			node *temp_der = tem->right;
			while (temp_der->right != NULL && temp_der->right->cor_x < x ) { 
				//cout<<"y fi temp_der-x: "<< temp_der->cor_x <<"y fi temp_der-y: "<< temp_der->cor_y <<endl;
				temp_der = temp_der->right;
    		}
    		//cout<<"y afu temp_der-x: "<< temp_der->cor_x <<"y afu temp_der-y: "<< temp_der->cor_y <<endl;
    		temp_der->right = new_node;
			new_node->left = temp_der;
		}
	}
	
	/***********inicio***X*y***nodos 0 en z***********************/
	
	void matrix :: add_x_header_z0(int x,  int z) {
    	string nombre_cab = "";
    	ostringstream num;
    	num<<x;
    	nombre_cab = "X"+num.str();
    	
		//cout<<"num.str(): "<<num.str()<<endl;
    	
    	node *head_x = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		/*while(head_x->cor_z != z){
    		head_x = head_x->capa_up;
		}*/
		
		//cout<<"222 z,x head_x: "<<head_x->data<<" "<<endl;
    	if (head_x->right == NULL) { 
	    	//node *temp = new node(x);    	
	    	node *temp = new node(x,x,0,z,"C", nombre_cab );
	    	head_x->right = temp;
	    	temp->left = head_x; 
    	} else  {     
			
		/*recorre por z, para insertar a la derecha*/		
		node *temp = head;
				
		/*while(temp->cor_z != z){
    		temp = temp->capa_up;
		}*/
		
		while (temp->right != NULL && temp->right->data < x ) { 
			temp = temp->right;
    	} 
			 if (temp->right == NULL ) { 
		    	//node *new_temp = new node(x);
		    	node *new_temp = new node(x, x, 0, z, "C", nombre_cab);
		    	temp->right = new_temp;
		    	new_temp->left = temp; 
		    	
	    		}else if (temp->right != NULL && temp->right->data != x )
				{
	    			//node *new_temp = new node(x);
	    			node *new_temp = new node(x, x, 0, z, "C", nombre_cab);
	    			node *der = temp->right;
	    			
	    			temp->right =new_temp;
	    			new_temp->left = temp;
	    			new_temp->right = der;
	    			der->left = new_temp;				
				}
    	}
    }
    
    void matrix :: add_y_header_z0(int y, int z) {
    	
    	string nombre_cab = "";
    	ostringstream num;
    	num<<y;
    	nombre_cab = "Y"+num.str();
    	
    	node *head_y = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		/*while(head_y->cor_z != z){
    		head_y = head_y->capa_up;
		}	*/
    		
    	if (head_y->down == NULL) { 
	    	//node *temp = new node(y);
	    	node *temp = new node(y, 0, y, 0, "C", nombre_cab);
	    	head_y->down = temp;
	    	temp->up = head_y; 
    	} else  {     	
		node *temp =head;
		/*nuevo inicio*/
		/*while(temp->cor_z != z){
    		temp = temp->capa_up;
		}*/
		/*nuevo fin*/
		while (temp->down != NULL && temp->down->data < y ) { 
			temp = temp->down;
	} 
			 if (temp->down == NULL ) { 
		    	//node *new_temp = new node(y);
		    	node *new_temp = new node(y, 0 , y,0, "C", nombre_cab);
		    	temp->down = new_temp;
		    	new_temp->up = temp; 
		    	
	    		}else if (temp->down != NULL && temp->down->data != y )
				{
	    			//node *new_temp = new node(y);
	    			node *new_temp = new node(y, 0,y, 0, "C", nombre_cab);
	    			node *der = temp->down;
	    			
	    			temp->down =new_temp;
	    			new_temp->up = temp;
	    			new_temp->down = der;
	    			der->up = new_temp;				
				}
    	}
    }
    
	void matrix :: add_x_z0(node *new_node, int x, int y, int z){
    	node *tem = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		/*while(tem->cor_z != z){
    		tem = tem->capa_up;
		}	*/	
		//////////////*************************
		
    	/*recorre por x, para insertar a abajo (y)*/	
    	//while(tem->data != x){
    	while(tem->cor_x != x){
    		tem = tem->right;
		}
		if(tem->down == NULL){
			tem->down = new_node;
			new_node->up = tem;
		} 
		/*si y es mejor al ultimo*/
		else if(tem->down->cor_y >= y ){
		//else if(tem->down->cor_y > y ){
			
			if(tem->down->cor_y == y && tem->down->cor_x == x ){
			}else{
			
				node *ul_down = tem->down;
			   	
				tem->down = new_node;
				new_node->up = tem;
				
				//para que enlace el que estaba antes
				new_node->down = ul_down;
				ul_down->up = new_node;
			}
		
		}
		else
		{
			node *temp_abaj = tem->down;
			while (temp_abaj->down != NULL && temp_abaj->down->cor_y < y ) { 
				temp_abaj = temp_abaj->down;
    		}
    		if(temp_abaj->cor_y == y && temp_abaj->cor_x == x ){
    		}else{
	    		temp_abaj->down = new_node;
				new_node->up = temp_abaj;
			}
		}
		
	}
	
	void matrix :: add_y_z0(node *new_node, int x, int y, int z){
		node *tem= head;
		/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		/*while(tem->cor_z != z){
    		tem = tem->capa_up;
		}*/
		//if( 4 == y && 7 == x ){cout<<"zz entra z: "<<z<<endl;}
		///////*********************************************1
				
		/*recorre por y, para insertar a la derecha (x)*/
		//while(tem->data != y){		
		while(tem->cor_y != y){
    		tem = tem->down;
		}
		if(tem->right == NULL){
			
			tem->right = new_node;
			new_node->left = tem;
		
			//if( 4 == y && 7 == x ){cout<<"if1"<<endl;}
		}
		//else if(tem->right->cor_x >= x ){
		else if(tem->right->cor_x >= x ){
		//else if( x < tem->right->cor_x ){
		   //if( 4 == y && 7 == x ){cout<<"if 2"<<endl;}
		   
		   	if(tem->right->cor_y == y && tem->right->cor_x == x ){
    		}else{	
			   	node *ul_der = tem->right;
			   	
				tem->right = new_node;
				new_node->left = tem;
				
				//para que enlace el que estaba antes
				new_node->right = ul_der;
				ul_der->left = new_node;
			}
		}
		else
		{
			//if( 4 == y && 7 == x ){cout<<"if 3"<<endl;}
			
			node *temp_der = tem->right;
			while (temp_der->right != NULL && temp_der->right->cor_x < x ) { 
				//cout<<"yy fi temp_der-x: "<< temp_der->cor_x <<"yy fi temp_der-y: "<< temp_der->cor_y <<endl;
				temp_der = temp_der->right;
    		}
    		
    		//cout<<"afuu fi temp_der-x: "<< temp_der->cor_x <<" y afi temp_der-y: "<< temp_der->cor_y <<endl;
    		//cout<<"afu x: "<< x <<" afu y: "<< y <<endl;
	    	
			//if(temp_der->cor_y != y && temp_der->cor_x != x ){	
    		if(temp_der->cor_y == y && temp_der->cor_x == x ){
    		}else{
    			
    			
    			
    			node *ul_der = NULL;
    			if (temp_der->right != NULL ){
    				ul_der = temp_der->right;
    				
    				/*if (y == 6 && x == 7)
	    			{
	    				cout<<endl;
	    				cout<<"ccx: "<< x <<" cc y: "<< y <<endl;
	    				cout<<"temp_der->right->cor_y: "<< temp_der->right->cor_y <<" temp_der->right->cor_x: "<< temp_der->right->cor_x <<endl;
	    				cout<<"ul_der->cor_y: "<< ul_der->cor_y <<" ul_der->cor_x: "<< ul_der->cor_x <<endl;
	    				system("pause");
					}*/
				}
    			
    			temp_der->right = new_node;
				new_node->left = temp_der;
				
				//para que enlace el que estaba antes
				if (ul_der != NULL ){
										
    				new_node->right = ul_der;
					ul_der->left = new_node;
				}
				
				
				
			}
		}
	}

	/***********fin***X*y***nodos 0 en z***********************/
	
    //void add_x_header(int x){
    void matrix :: add_x_header(int x,  int z) {
    	
    	string nombre_cab = "";
    	ostringstream num;
    	num<<x;
    	nombre_cab = "X"+num.str();
    	
    	node *head_x = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(head_x->cor_z != z){
    		head_x = head_x->capa_up;
		}
		//cout<<"222 z,x head_x: "<<head_x->data<<" "<<endl;
    	if (head_x->right == NULL) { 
	    	//node *temp = new node(x);    	
	    	node *temp = new node(x,x,0,z, "C", nombre_cab);
	    	head_x->right = temp;
	    	temp->left = head_x; 
    	} else  {     
			
		/*recorre por z, para insertar a la derecha*/		
		node *temp = head;
				
		while(temp->cor_z != z){
    		temp = temp->capa_up;
		}
		
		while (temp->right != NULL && temp->right->data < x ) { 
			temp = temp->right;
    	} 
			 if (temp->right == NULL ) { 
		    	//node *new_temp = new node(x);
		    	node *new_temp = new node(x, x, 0, z, "C", nombre_cab);
		    	temp->right = new_temp;
		    	new_temp->left = temp; 
		    	
	    		}else if (temp->right != NULL && temp->right->data != x )
				{
	    			//node *new_temp = new node(x);
	    			node *new_temp = new node(x, x, 0, z, "C", nombre_cab);
	    			node *der = temp->right;
	    			
	    			temp->right =new_temp;
	    			new_temp->left = temp;
	    			new_temp->right = der;
	    			der->left = new_temp;
				
				}
    	
    	}
    }
    
    //void add_y_header(int y) {
    void matrix :: add_y_header(int y, int z) {
    	
    	string nombre_cab = "";
    	ostringstream num;
    	num<<y;
    	nombre_cab = "Y"+num.str();
    	
    	node *head_y = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(head_y->cor_z != z){
    		head_y = head_y->capa_up;
		}	
    		
    	if (head_y->down == NULL) { 
	    	//node *temp = new node(y);
	    	node *temp = new node(y, 0, y, 0, "C", nombre_cab);
	    	head_y->down = temp;
	    	temp->up = head_y; 
    	} else  {     	
		node *temp =head;
		/*nuevo inicio*/
		while(temp->cor_z != z){
    		temp = temp->capa_up;
		}
		/*nuevo fin*/
		while (temp->down != NULL && temp->down->data < y ) { 
			temp = temp->down;
	} 
			 if (temp->down == NULL ) { 
		    	//node *new_temp = new node(y);
		    	node *new_temp = new node(y, 0 , y,0, "C", nombre_cab);
		    	temp->down = new_temp;
		    	new_temp->up = temp; 
		    	
	    		}else if (temp->down != NULL && temp->down->data != y )
				{
	    			//node *new_temp = new node(y);
	    			node *new_temp = new node(y, 0,y, 0, "C", nombre_cab);
	    			node *der = temp->down;
	    			
	    			temp->down =new_temp;
	    			new_temp->up = temp;
	    			new_temp->down = der;
	    			der->up = new_temp;				
				}
    	}
    }
    
       void matrix :: add_z_header(int z, string file_capa) {
    	  	
    	string nombre_cab = "";
    	//ostringstream num;
    	//num<<z;
    	//nombre_cab = "Z"+num.str();
    	
    	nombre_cab = file_capa;
    	
    	if (head->capa_up == NULL) { 
	    	//node *temp = new node(x);    	
	    	node *temp = new node(z,0,0,z, "C", nombre_cab);
	    	head->capa_up = temp;
	    	temp->capa_down = head; 
    	} else  {     	
		node *temp =head;
		while (temp->capa_up != NULL && temp->capa_up->data < z ) { 
			temp = temp->capa_up;
    	}

			 if (temp->capa_up == NULL ) { 
		    	//node *new_temp = new node(z);
		    	node *new_temp = new node(z, 0, 0, z, "C", nombre_cab);
		    	temp->capa_up = new_temp;
		    	new_temp->capa_down = temp; 
		    	
	    		}else if (temp->capa_up != NULL && temp->capa_up->data != z )
				{
	    			//node *new_temp = new node(z);
	    			node *new_temp = new node(z, 0, 0, z, "C", nombre_cab);
	    			node *c_up = temp->capa_up;
	    			
	    			temp->capa_up =new_temp;
	    			new_temp->capa_down = temp;
	    			
	    			new_temp->capa_up = c_up;
	    			c_up->capa_down = new_temp;
	    			
				
				}
    	
    	}
    }
    
    void matrix :: print_headers(){
    	//print_x_header();
    	//print_y_header();
    	
    	//cout<<"cor en z, profundidad"<<endl; 
    	//print_z_header();
    	//cout<<endl<<endl; 
    	
    	cout <<"impriendo matrix por capas"<<endl; 
    	
    	print_z_header_capas_z();
	}
    
    /*print*/
    void matrix :: print_x_header() {
    	node *temp = head;
    	while (temp->right != NULL) { 
	    	cout<<temp->data<<"->";
	    	//cout<<temp->data<<endl;
	    	temp = temp->right;
		}  	
		//cout<<temp->data<<"->";
		cout <<temp->data<<endl;    
    }
    
      void matrix :: print_y_header() {
    	node *temp = head;
    	while (temp->down != NULL) { 
	    	cout<<temp->data<<endl;
	    	temp = temp->down;
		}  	
		cout <<temp->data<<endl;    
    }
    
    /*print por profundidad*/
     void matrix :: print_x_header_capas_z(node *nodo_cap) {
    	//node *temp = head;
    	node *temp = nodo_cap;
    	while (temp->right != NULL) { 
	    	//cout<<temp->data<<"->";
	    	cout<<temp->cor_x<<"->";
	    	//cout<<temp->data<<endl;
	    	temp = temp->right;
		}  	
		//cout <<temp->data<<endl;   
		cout <<temp->cor_x<<endl;  
    }
    
    void matrix :: print_y_header_capas_z(node *nodo_cap) {
    	//node *temp = head;
    	node *temp = nodo_cap;
    		
    	while (temp->down != NULL) { 
	    	//cout<<temp->data<<endl;
	    	cout<<temp->cor_y<<endl;
	    	temp = temp->down;
		}  	
		//cout <<temp->data<<endl;   
		cout <<temp->cor_y<<endl;     
    }
    
    ///cap
    void matrix :: print_z_header_capas_z() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"capa_z: "<<temp->data<<endl;
	    	print_x_header_capas_z(temp);
	    	print_y_header_capas_z(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"capa_z: "<<temp->data<<endl;
		print_x_header_capas_z(temp);
		print_y_header_capas_z(temp);
		
    }
    
      void matrix :: print_z_header() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<temp->data<<endl;
	    	temp = temp->capa_up;
		}  	
		cout <<temp->data<<endl;    
    }
    
    
    
	void matrix :: print_nodes_x() {
    	node *temp = head;
    	while (temp->right != NULL) { 
	    	cout<<temp->data<<"->";
	    	//if (temp->down != NULL)
	    	//{
	    		cout <<temp->down->data;    
			//}
	    	cout<<endl;  
	    	temp = temp->right;
		}  	
		cout<<temp->data<<"->";
		if (temp->down != NULL)
    	{
    		cout <<temp->down->data;    
		}  
    	
    }
    
    void matrix :: print_nodes_y() {
    	node *temp = head;
    	while (temp->down != NULL) { 
	    	cout<<temp->data<<"->";
	    	//if (temp->right != NULL)
	    	//{
	    		cout <<temp->right->data;    
			//}
	    	cout<<endl;  
	    	temp = temp->down;
		}  	
		cout<<temp->data<<"->";
		if (temp->right != NULL)
    	{
    		cout <<temp->right->data;    
		}  
    	
    }
    /////****inicio******para*imprimir*matriz*en*grapiz******************//
    void matrix :: create_archivo(string nombre, string contenido) {
    	
    	string nom_ar = "";
		nom_ar = nombre + ".txt";
		ofstream file;
		file.open(nom_ar.c_str());
		file <<contenido;
		file.close();
		string dot, ima;
		//os.system("fdp -Tpng -o graph-g.png ejemplo.dot")
		//dot = "fdp -Tpng "+ nom_ar + " -o "+nombre + ".jpg";
		dot = "neato -Tpng "+ nom_ar + " -o "+nombre + ".jpg";
		ima = nombre + ".jpg";
		system(dot.c_str());
	    system(ima.c_str());
	    
	    system(nom_ar.c_str());
	}
	
	void matrix :: create_archivo_linear(string nombre, string contenido) {
    	
    	string nom_ar = "";
		nom_ar = nombre + ".txt";
		ofstream file;
		file.open(nom_ar.c_str());
		file <<contenido;
		file.close();
		string dot, ima;
		dot = "dot -Tpng "+ nom_ar + " -o "+nombre + ".jpg";
		ima = nombre + ".jpg";
		system(dot.c_str());
	    system(ima.c_str());
	    
	    system(nom_ar.c_str());
	}
    
    int matrix :: alto_mat(){
    	int alt = 0;
    	
    	node *temp = head;
    	while (temp->down != NULL) { 
    		temp = temp->down;
    	}
    	alt = temp->cor_y;
    	return alt;
	}
	
	int matrix :: alto_mat_x_cap(node *matrix_head){
    	int alt = 0;
    	
    	node *temp = matrix_head;
    	while (temp->down != NULL) { 
    		temp = temp->down;
    	}
    	alt = temp->cor_y;
    	return alt;
	}
    
    int matrix :: ancho_mat_x_cap(node *matrix_head){
    	int anch = 0;
    	
    	node *temp = matrix_head;
    	while (temp->right != NULL) { 
    		temp = temp->right;
    	}
    	anch = temp->cor_x;
    	return anch;
	}
    void matrix :: Tipo_a_Graficar_back() {
    	
    	//node *temp = head;
    	//print_Grafica_matrix(temp);
    	
    	string name_cap;
    	
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	//cout<<"c_o_z: "<<temp->data<<endl;
	    	ostringstream cap;
	    	cap<<temp->cor_z;
    		name_cap = "cap"+cap.str();
	    	print_Grafica_matrix(temp, name_cap);
	    	
	    	temp = temp->capa_up;
		}  	
		//cout<<"c_o_z: "<<temp->data<<endl;
		
		ostringstream cap;
		cap<<temp->cor_z;
    	name_cap = "cap"+cap.str();
		print_Grafica_matrix(temp, name_cap);
		
	}
    
    void matrix :: Tipo_a_Graficar(int capa) {
    	
    	//node *temp = head;
    	//print_Grafica_matrix(temp);
    	
    	string name_cap;
    	
    	node *temp = head;
    	//while (temp->capa_up != NULL) { 
    	while (temp != NULL) { 
	    	//cout<<"c_o_z: "<<temp->data<<endl;
	    	
	    	if (capa == 0){
	    		ostringstream cap;
		    	cap<<temp->cor_z;
	    		name_cap = "cap"+cap.str();
		    	print_Grafica_matrix(temp, name_cap);
			}
	    	else if (capa != 0 && capa == temp->cor_z ){
	    		ostringstream cap;
		    	cap<<temp->cor_z;
	    		name_cap = "cap"+cap.str();
		    	print_Grafica_matrix(temp, name_cap);
			} 
	    	
	    	
	    	temp = temp->capa_up;
		}  	
		//cout<<"c_o_z: "<<temp->data<<endl;
		
		//ostringstream cap;
		//cap<<temp->cor_z;
    	//name_cap = "cap"+cap.str();
		//print_Grafica_matrix(temp, name_cap);
		
	}
	
	bool matrix :: Buscando_cordenadas(int capa, int x, int y) {
    	
    	//node *temp = head;
    	//print_Grafica_matrix(temp);
    	bool encontrado = false;

    	node *temp = head;
    	//while (temp->capa_up != NULL) { 
    	while (temp != NULL) { 
	    	//cout<<"c_o_z: "<<temp->data<<endl;
			//if (capa != 0 && capa == temp->cor_z ){
			if (capa == temp->cor_z ){
		    	encontrado = Buscando_matrix_xy(temp, x, y);
		    	if (encontrado == true){
		    		return encontrado;
				}
			} 
	    	temp = temp->capa_up;
		}  	
		//cout<<"c_o_z: "<<temp->data<<endl;
	}
bool matrix :: Buscando_matrix_xy(node *matrix_capa, int x, int y) {

    	////node *temp = head;
    	node *temp = matrix_capa;

    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;
    	
    	node *temp_sup_ini;
		   	
    	/*para recorrer para la derecha*/
    	while (temp != NULL) { 
	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	while (temp != NULL) { 
				if (temp->tipo == "N"){
						if (temp->cor_x == x && temp->cor_y == y){
							cout<<"color actual: "<<temp->valor<<" ";	
							//system("pause");
							return true;
						}
					}
						
				    	
		    	temp = temp->right;
			}
			//cout<<"x: "<<temp->data<<" ";			
			temp = temp_inicio;
	    	temp = temp->down;  	
	    	//cout<<endl;
		}  	
    }
	////ya modificando
	
	bool matrix :: Modificando_cordenadas(int capa, int x, int y, string nuevo_color) {
    	
    	bool encontrado = false;

    	node *temp = head;
    	//while (temp->capa_up != NULL) { 
    	while (temp != NULL) { 
			if (capa == temp->cor_z ){
		    	encontrado = Modificando_matrix_xy(temp, x, y, nuevo_color);
		    	if (encontrado == true){
		    		return encontrado;
				}
			} 
	    	temp = temp->capa_up;
		}  	
	}
	
	bool matrix :: Modificando_matrix_xy(node *matrix_capa, int x, int y, string nuevo_color) {

    	////node *temp = head;
    	node *temp = matrix_capa;

    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;
    	
    	node *temp_sup_ini;
		   	
    	/*para recorrer para la derecha*/
    	while (temp != NULL) { 
	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	while (temp != NULL) { 
				if (temp->tipo == "N"){
						if (temp->cor_x == x && temp->cor_y == y){
							//cout<<"color actual: "<<temp->valor<<" ";	
							temp->valor = nuevo_color;
							//system("pause");
							return true;
						}
					}
						
				    	
		    	temp = temp->right;
			}
			//cout<<"x: "<<temp->data<<" ";			
			temp = temp_inicio;
	    	temp = temp->down;  	
	    	//cout<<endl;
		}  	
    }
	void matrix :: Tipo_a_Graficar_linear(int capa, string tipo_lin) {
    	string name_cap;
    	
    	node *temp = head;
    	//while (temp->capa_up != NULL) { 
    	while (temp != NULL) { 
	    	if (capa == 0){
	    		ostringstream cap;
		    	cap<<temp->cor_z;
	    		name_cap = "cap"+cap.str();
		    	print_Grafica_matrix_linear(temp, name_cap, tipo_lin);
			}
	    	else if (capa != 0 && capa == temp->cor_z ){
	    		ostringstream cap;
		    	cap<<temp->cor_z;
	    		name_cap = "cap"+cap.str();
		    	print_Grafica_matrix_linear(temp, name_cap, tipo_lin);
			} 
	    	temp = temp->capa_up;
		}  	
	}
	
	void matrix :: print_Grafica_matrix_linear(node *matrix_capa, string name_cap, string tipo_lin) {
    	
		string graf_matrix_lin_filas;
    	string xx, yy;
    	string xx2, yy2;
    	
    	string nodo_name, nodo_name_sig;
		int nod = 0; 
		    			
    	int alto;
    	int ancho;
    	
    	graf_matrix_lin_filas = "";
		graf_matrix_lin_filas = graf_matrix_lin_filas + "digraph G { rankdir=LR\n";
		graf_matrix_lin_filas = graf_matrix_lin_filas + "node [shape=record dir=both];\n";
		//graf_matrix_lin_filas = graf_matrix_lin_filas + "node [shape=record dir=both];\n";
    	
    	graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+"0"+"[label = \"{<f0>|<f1> " + "Inicio" + "|<f2> }\"];\n";  
							
    	graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+"0" +" -> ";    
		graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+"1" +";\n";	
							
    	////node *temp = head;
    	node *temp = matrix_capa;
    	
    	//alto = alto_mat();
    	alto = alto_mat_x_cap(temp);
    	ancho = ancho_mat_x_cap(temp);
    	
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;
    	node *temp_sup_ini;
		   	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	while (temp != NULL) { 
				//if (temp != NULL){
		    		//cout<<"x: "<<temp->data<<" ";	

						if (temp->tipo == "N"){
							nod++;
		    			//cout<<"temp->cor_x ("<<temp->cor_x<<")";
		    			ostringstream co_x,  co_y, nod_n, nod_n_s;
		    			
		    			co_x<<temp->cor_x;
		    			co_y<<temp->cor_y;
		    			
		    			////para normales
		    			//y_gr<<alto - temp->cor_y;

		    			
		    			//xx =""; yy ="";
    					xx = co_x.str(); 
						yy = co_y.str();
						//y_grap = y_gr.str();
						//cout<<"xx ("<<xx<<")";
		    			//cout<<"yy ("<<yy<<")";
		    			nod_n<<nod;
		    			nod_n_s<<nod+1;
		    			
		    			nodo_name = nod_n.str();
            			nodo_name_sig  = nod_n_s.str();
            
		    			
			    			//cout<<"("<<xx<<","<<yy<<") "<<temp->valor<<"->"<<endl;
			    			////graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+xx+"_"+yy +"[label = \"{<f0>|<f1> " + "("+xx+","+yy+") "+temp->valor + "|<f2> }\"];\n";  
							graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+nodo_name+"[label = \"{<f0>|<f1> " + "("+xx+","+yy+") "+temp->valor + "|<f2> }\"];\n";  
							
							
							//flechas
							/*graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+xx+"_"+yy +" -> ";
							if (temp->right != NULL //&& temp->down != NULL){
								ostringstream co_x2,  co_y2;
								co_x2<<temp->right->cor_x;
			    				co_y2<<temp->right->cor_y;
			    				
			    				xx2 = co_x2.str(); 
								yy2 = co_y2.str();

								graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+xx2+"_"+yy2 +";\n";
							}*/  
							
							if (tipo_lin == "LIN")
					    	{
					    		if (alto == temp->cor_y && temp->right == NULL){
								//cout<<"alto:"<<alto<<", temp->cor_z"<<temp->cor_y<<endl;
								}else{
		
									graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+nodo_name +" -> ";    
									graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+nodo_name_sig +";\n";
								}
							}
							else if (tipo_lin == "COL")
					    	{
					    		if (ancho == temp->cor_x && temp->down == NULL){
								}else{
		
									graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+nodo_name +" -> ";    
									graf_matrix_lin_filas = graf_matrix_lin_filas + "p"+nodo_name_sig +";\n";
								}
							}
							
							
							
											
						}
						    	
		    	//temp = temp->right;
		    	if (tipo_lin == "LIN"){
		    		temp = temp->right;
				}
				else if (tipo_lin == "COL"){
		    		temp = temp->down;
				}
			}		
			temp = temp_inicio;
	    	//temp = temp->down;
	    	
	    	if (tipo_lin == "LIN"){
	    		temp = temp->down;
			}
			else if (tipo_lin == "COL"){
	    		temp = temp->right;
			}
	    	//cout<<endl;
		}  	
		
		if (tipo_lin == "LIN")
    	{name_cap = name_cap + "_lin";}
		else if (tipo_lin == "COL")
    	{name_cap = name_cap + "_col";}
		
		graf_matrix_lin_filas = graf_matrix_lin_filas + "\n}\n";
		create_archivo_linear(name_cap, graf_matrix_lin_filas);
 	
    }
    
    void matrix :: print_Grafica_matrix(node *matrix_capa, string name_cap) {
    	string graf_matrix;
    	string xx, yy;
    	string xx2, yy2;
    	
    	int alto;
    	string y_grap;
    	//ostringstream co_x;
		//ostringstream co_y;
		
    	//cor_x<<x;
    	//xx = cor_x.str();
    	
    	graf_matrix = "";
		graf_matrix = graf_matrix + "digraph{ \n";
		graf_matrix = graf_matrix + "rankdir=BT;\n";
		//graf_matrix = graf_matrix + "graph [nodesep=5.5]; \n";
		graf_matrix = graf_matrix + "node[shape=record]; \n";
		//graf_matrix = graf_matrix + "node[shape=record ,width=2.0]; \n";
		graf_matrix = graf_matrix + "graph[pencolor=transparent]; \n";
		graf_matrix = graf_matrix + "node [style=filled]; \n";
    	
    	////node *temp = head;
    	node *temp = matrix_capa;
    	
    	//alto = alto_mat();
    	alto = alto_mat_x_cap(temp);
    	//cout<<"alto_nod: "<<alto<<endl;
    	
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;
    	
    	node *temp_sup_ini;
		   	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 
	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				//temp_sup_ini = temp;
				//if (temp != NULL){
		    		//cout<<"x: "<<temp->data<<" ";	
						   		
		    			//cout<<"("<<temp->data<<")";
		    			
		    			//cout<<"temp->cor_x ("<<temp->cor_x<<")";
		    			ostringstream co_x,  co_y, y_gr;
		    			
		    			co_x<<temp->cor_x;
		    			co_y<<temp->cor_y;
		    			
		    			////para normales
		    			y_gr<<alto - temp->cor_y;
		    			
		    			//para collage
		    			//y_gr<<2*alto - temp->cor_y;
		    			
		    			//xx =""; yy ="";
    					xx = co_x.str(); 
						yy = co_y.str();
						y_grap = y_gr.str();
						
						//cout<<"xx ("<<xx<<")";
		    			//cout<<"yy ("<<yy<<")";
		    			
		    			//graf_matrix = graf_matrix + "p"+xx+yy +"[label=\"{<data>"+xx+","+yy+"|<next>}\" pos=\""+xx+","+y_grap+"!\"]; \n";
						
						graf_matrix = graf_matrix + "p"+xx+"_"+yy +"[label=\"{<data>"+xx+","+yy+"|<next>"+ temp->valor+ "}\" pos=\""+xx+","+y_grap+"!\"]; \n";
						
						
						//print_node_superiores(temp);
						
						/*para imprimir las flechas de la derecha*/
						if (temp->right != NULL){
							ostringstream co_x2,  co_y2;
							co_x2<<temp->right->cor_x;
		    				co_y2<<temp->right->cor_y;
		    				
		    				xx2 = co_x2.str(); 
							yy2 = co_y2.str();
						
							graf_matrix = graf_matrix + "p"+xx+"_"+yy + "->p"+ xx2+"_"+yy2+"[dir=both]; \n";
						}
						
						/*para imprimir las flechas de abajo*/
						if (temp->down != NULL){
							ostringstream co_x2,  co_y2;
							co_x2<<temp->down->cor_x;
		    				co_y2<<temp->down->cor_y;
		    				
		    				xx2 = co_x2.str(); 
							yy2 = co_y2.str();
						
							graf_matrix = graf_matrix + "p"+xx+"_"+yy + "->p"+ xx2+"_"+yy2+"[dir=both]; \n";
						}
						
						
					
				//	}
											    	
		    	temp = temp->right;
			}
			//cout<<"x: "<<temp->data<<" ";			
			temp = temp_inicio;
	    	temp = temp->down;  	
	    	//cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    		
		//cout <<"termina"<<endl;   
		graf_matrix = graf_matrix + "\n}\n";
		
		//create_archivo("cap0", graf_matrix);
		create_archivo(name_cap, graf_matrix);
 	
    }
    
    /////****fin******para*imprimir*matriz*en*grapiz******************//
    
    ///capas de cordenadas
    void matrix :: print_node_cor_z() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"c_o_z: "<<temp->data<<endl;
	    	print_node_cor_mat(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"c_o_z: "<<temp->data<<endl;
		print_node_cor_mat(temp);
		
    }
    
    ///imprimiendo superiores
    void matrix :: print_node_superiores(node *nodo_sup_arriba) {
    	//node *temp = head;
    	node *temp = nodo_sup_arriba;
    	//temp = temp->capa_up; ///para que no me imprima el actual
    	
    	while (temp->capa_up != NULL) { 
    	//while (temp != NULL) { 
	    	//cout<<"c_o_sup: "<<temp->data<<endl;
	    	//print_node_cor_mat(temp);
	    	if (temp->tipo == "N"){
		    	cout<<"*"<<temp->data<<"->*";	
		    }
			temp = temp->capa_up;
		    
		}  	
		if (temp->tipo == "N"){
		    	cout<<"*"<<temp->data<<"->*";
		    }
		
		//print_node_cor_mat(temp);
		
    }
    
    void matrix :: print_node_cor_mat(node *nodo_x_nivel) {
    	//node *temp = head;
    	node *temp = nodo_x_nivel;
    	node *temp_inicio;
    	
    	node *temp_sup_ini;
		   	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 
	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				//temp_sup_ini = temp;
				//if (temp != NULL){
		    		//cout<<"x: "<<temp->data<<" ";		    		
		    			cout<<"("<<temp->data<<")";
						print_node_superiores(temp);
					
				//	}
											    	
		    	temp = temp->right;
			}
			
			//cout<<"x: "<<temp->data<<" ";			
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    		
		//cout <<"termina"<<endl;   
 	
    }
    
    void matrix :: print_mt_ejemplo() {
    	node *temp = head;
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;
    	
    	node *temp_sup_ini;
		   	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 
	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				temp_sup_ini = temp;
				
				//if (temp != NULL){
		    		//cout<<"x: "<<temp->data<<" ";
		    		cout<<"("<<temp->data<<")";	
		    		while (temp != NULL) { 
		    		
					cout<<" - "<<temp->data<<"-> ";	
					temp = temp->capa_up;
					
					}
				//}
					//print_node_superiores(temp);
				temp = temp_sup_ini;		    	
		    	temp = temp->right;
			}
			
			//cout<<"x: "<<temp->data<<" ";			
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    		
		//cout <<"termina"<<endl;   
 	
    }
    
    
    void matrix :: print_node_cor() {
    	node *temp = head;
    	
    	node *temp_inicio;
		   	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 
	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				
				if (temp != NULL){
		    		//cout<<"x: "<<temp->data<<" ";
					cout<<" "<<temp->data<<" ";	}	    	
		    	temp = temp->right;
			}
			//cout<<"x: "<<temp->data<<" ";			
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    		
		cout <<"termina"<<endl;   
 	
    }
    
    ///capas de cordenadas
    void matrix :: print_node_cor_orde_zz() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"c_mm_z: "<<temp->data<<endl;
	    	print_node_cor_orde_mat(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"c_mm_z: "<<temp->data<<endl;
		print_node_cor_orde_mat(temp);
		
    }
    
    
     ///recorriendo capas por profinidad, por cada nodo encontrado
    void matrix :: print_node_z_cap() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"z: "<<temp->data<<endl;
	    	print_mat_sup(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"z: "<<temp->data<<endl;
		print_mat_sup(temp);		
    }
    
    
    void matrix :: buscabdo_nodo_superior(node *nodo_actual, int x, int y) {
    	//node *temp = head;
    	node *temp = nodo_actual;
    	
    	while (temp->capa_up != NULL) { 
	    	//cout<<"z: "<<temp->data<<endl;
	    	print_mat_sup_superior(temp);
	    	temp = temp->capa_up;
		}  	
		//cout<<"z: "<<temp->data<<endl;
		print_mat_sup(temp);		
    }
    
    void matrix :: print_mat_sup(node *nodo_x_nivel) {
    	//node *temp = head;
    	node *temp = nodo_x_nivel;   	
    	node *temp_inicio;
		   	
    	/*para recorrer para la derecha*/
    	while (temp != NULL) { 
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	while (temp != NULL) { 				
				if (temp != NULL){
					cout<<"* "<<temp->data<<" -> ";}	
					//buscabdo_nodo_superior(temp, temp->cor_x, temp->cor_y);    	
		    	temp = temp->right;
			}	
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	cout<<endl;
		}  		
    }
    
    
     void matrix :: print_mat_sup_superior(node *nodo_x_nivel) {
    	//node *temp = head;
    	node *temp = nodo_x_nivel;   	
    	node *temp_inicio;
		   	
    	/*para recorrer para la derecha*/
    	while (temp != NULL) { 
	    	temp_inicio = temp;
	    	/*para recorrer para abajo*/
	    	while (temp != NULL) { 				
				if (temp != NULL){
					cout<<"* "<<temp->data<<" -> ";}	
					//buscabdo_nodo_superior(temp, temp->cor_x, temp->cor_y);    	
		    	temp = temp->right;
			}	
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	cout<<endl;
		}  		
    }

    
     void matrix :: print_node_cor_orde_der_abaj_z() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"c_yy_z: "<<temp->data<<endl;
	    	print_node_cor_orde_der_abaj_mat(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"c_yy_z: "<<temp->data<<endl;
		print_node_cor_orde_der_abaj_mat(temp);
		
    }
    
    void matrix :: print_node_cor_orde_mat(node *nodo_x_nivel) {
    	//node *temp = head;
    	node *temp = nodo_x_nivel;
    	
    	node *temp_inicio;
		   	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 

	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				
				if (temp != NULL)
		    	{
		    		cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";	
		    		//cout<<"(x:"<<temp->cor_x<<" y:"<<temp->cor_y<<")";
				}	    	
		    	temp = temp->right;
			}
			//cout<<"x: "<<temp->data<<" ";
				
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	//cout<<"+++ temp y: "<<temp->data<<endl;
	    	//cout<<"+++ temp_inicio y: "<<temp_inicio->data<<endl;
	    	
	    	cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    
		
		cout <<"termina"<<endl;   
    	
    }
    
    void matrix :: print_node_cor_orde() {
    	node *temp = head;
    	
    	node *temp_inicio;
		   	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 

	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				
				if (temp != NULL)
		    	{
		    		cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";	
		    		//cout<<"(x:"<<temp->cor_x<<" y:"<<temp->cor_y<<")";
				}	    	
		    	temp = temp->right;
			}
			//cout<<"x: "<<temp->data<<" ";
				
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	//cout<<"+++ temp y: "<<temp->data<<endl;
	    	//cout<<"+++ temp_inicio y: "<<temp_inicio->data<<endl;
	    	
	    	cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    
		
		cout <<"termina"<<endl;   
    	
    }
    
     ///para recorer de derecha hacia abajo
    void matrix :: print_node_cor_orde_der_abaj_mat(node *nodo_x_nivel) {
    	//node *temp = head;
    	node *temp = nodo_x_nivel;
	
    	node *temp_inicio; 	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 

	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				
				if (temp != NULL)
		    	{
		    		cout<<"(x:"<<temp->cor_x<<" y:"<<temp->cor_y<<")";	
				}	    	
		    	temp = temp->down;
			}
			//cout<<"x: "<<temp->data<<" ";
				
			temp = temp_inicio;
	    	temp = temp->right;
	    	
	    	//cout<<"+++ temp y: "<<temp->data<<endl;
	    	//cout<<"+++ temp_inicio y: "<<temp_inicio->data<<endl;
	    	
	    	cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    
		
	//	cout <<"termina reco der abaj"<<endl;   
    	
    }
    
    ///para recorer de derecha hacia abajo
    void matrix :: print_node_cor_orde_der_abaj() {
    	node *temp = head;
	
    	node *temp_inicio; 	
    	/*para recorrer para la derecha*/
    	//while (temp->down != NULL) { 
    	while (temp != NULL) { 

	    	////////cout<<"y: "<<temp->data<<endl;
	    	temp_inicio = temp;
	    	
	    	/*para recorrer para abajo*/
	    	//while (temp->right != NULL) { 
	    	while (temp != NULL) { 
		    	//cout<<temp->data<<"   -";	
				
				if (temp != NULL)
		    	{
		    		cout<<"(x:"<<temp->cor_x<<" y:"<<temp->cor_y<<")";	
				}	    	
		    	temp = temp->down;
			}
			//cout<<"x: "<<temp->data<<" ";
				
			temp = temp_inicio;
	    	temp = temp->right;
	    	
	    	//cout<<"+++ temp y: "<<temp->data<<endl;
	    	//cout<<"+++ temp_inicio y: "<<temp_inicio->data<<endl;
	    	
	    	cout<<endl;
		}  	
		//cout <<temp->data<<"   ";    
		
		cout <<"termina reco der abaj"<<endl;   
    	
    }
    
    
    ////**********************inicio*****para*crear*imagen*****************************************////
    
    int matrix :: no_columnas_mat(){
    	int no_col = 0;
    	
    	node *temp = head;
    	while (temp->right != NULL) { 
    		temp = temp->right;
    	}
    	no_col = temp->cor_x;
    	return no_col;
	}
	
    void matrix :: Generando_css(int canvas_w, int canvas_h, int pix_w, int pix_h, int no_pix_ancho, int no_pix_alto, string nam_completo, string nombre) {
    	
    	//node *temp = head;
    	//print_Grafica_matrix(temp);
    	string name_cap;
    	
    	//string file_css;
    	//string file_html;
    	
 		///***para css*****///
    	file_css = "";
    	
    	file_css = file_css + "body {\n";
		file_css = file_css + "  background: #333333; \n";    
		file_css = file_css + "  height: 100vh; \n";        
		file_css = file_css + "  display: flex; \n";         
		file_css = file_css + "  justify-content: center; \n";
		file_css = file_css + "  align-items: center; \n";   
		file_css = file_css + " }\n";
		
		ostringstream can_w, can_h;
		can_w<<canvas_w;
		can_h<<canvas_h;
		
    	//name_cap = "cap"+cap.str();

		file_css = file_css + ".canvas {\n";  
		file_css = file_css + "  width: "+ can_w.str() +"px; \n";    
		file_css = file_css + "  height: "+can_h.str() +"px;\n";  
		//file_css = file_css + "  width: "+  "360" +"px; \n";    
		//file_css = file_css + "  height: "+  "360" +"px;\n";   
		  
		file_css = file_css + " }\n";  
		
		ostringstream px_w, px_h;
		px_w<<pix_w;
		px_h<<pix_h;
			
		file_css = file_css + ".pixel {\n"; 
		file_css = file_css + "  width: "+ px_w.str() + "px;\n"; 
		file_css = file_css + "  height:"+ px_h.str() + "px;\n"; 
		file_css = file_css + "  float: left;  \n"; 
		file_css = file_css + "  box-shadow: 0px 0px 1px #fff;\n"; 
		file_css = file_css + "}\n"; 


		///***para html*****///
		file_html = "";
		
		file_html = file_html + "<!DOCTYPE html>\n";
		file_html = file_html + "<html>\n";
		file_html = file_html + "<head>\n";
		//file_html = file_html + "  <link rel=\"stylesheet\" href=\"geoff.css\">\n";
		//file_html = file_html + "  <link rel=\"stylesheet\" href=\"ejemplo.css\">\n";
		file_html = file_html + "  <link rel=\"stylesheet\" href=\""+nombre+".css\">\n";
		file_html = file_html + "</head>\n";
		file_html = file_html + "<body>\n";
		file_html = file_html + "<div class=\"canvas\"> \n";
		
		////////////////////
		//no_pix_ancho = no_columnas_mat();
    	
    	node *temp = head;
    	while (temp->capa_up != NULL) { 

    		
    		if (temp->valor != "RAIZ"){
    			read_matrix_css_html(temp, canvas_w, canvas_h, pix_w, pix_h, no_pix_ancho, no_pix_alto);
			}
	    	
	    	temp = temp->capa_up;
		}  	
		
		read_matrix_css_html(temp, canvas_w, canvas_h, pix_w, pix_h, no_pix_ancho, no_pix_alto);
		
		
		////creando los divs
		for(int y = 0; y<no_pix_alto ; y++){
			for(int x = 0; x<no_pix_ancho ; x++){
				///para html
				file_html = file_html + "  <div class=\"pixel\"></div>\n";
			}
		}
		
		
		
		
		file_html = file_html + "</div>\n";
		file_html = file_html + "</body>\n";
		file_html = file_html + "</html> \n";
		
		
		//create_file_images(name_cap, file_css);
		create_file_images( nam_completo +".css", file_css);
		create_file_images( nam_completo +".html", file_html);
		
		string na_html;
		na_html = nam_completo +".html";
		//na_html = nombre +".html";
		cout<<"Imagen exportada a "<<na_html;
		system(na_html.c_str());
		
	}
	
	void matrix :: read_matrix_css_html(node *matrix_capa, int canvas_w, int canvas_h, int pix_w, int pix_h, int no_pix_ancho, int no_pix_alto) {
		
		string c_r, c_g, c_b;
		
		
    	////node *temp = head;
    	node *temp = matrix_capa;
    	
    	string color_completo;
    	string color_hexa;
    	int no_col;
    	int k;
    	//no_col = no_columnas_mat();
    	no_col = no_pix_ancho;

    	
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;	
    	node *temp_sup_ini;
		   	

    	while (temp != NULL) { 

	    	temp_inicio = temp;

	    	while (temp != NULL) { 
						
						if (temp->tipo == "N")
						{

							ostringstream k_str;
							k = 0;
							//k = i(y) * Numero Columnas + j(x)
							//k = temp->cor_y  * no_col + temp->cor_x; 
							k = ((temp->cor_y - 1 ) * no_col ) + (temp->cor_x - 1); 
							k = k +1;
							k_str<<k;
							
							//cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";
							color_completo = temp->valor;
							//cout<<color_completo<<endl;
							 
							
							stringstream col(color_completo);
							getline(col, c_r, '-');
							getline(col, c_g, '-');
							getline(col, c_b, '-');
							
							//if (color_completo == "230-138-0")
							/*if (k_str.str() == "200" || k_str.str() == "207" || k_str.str() == "226" || k_str.str() == "245" || k_str.str() == "290")
							*/
							
							if ( atoi(c_r.c_str()) > 255 || atoi(c_g.c_str()) > 255 || atoi(c_b.c_str()) > 255  )
							{
								//cout<<"k_str.str(): "<<k_str.str()<<endl;
								cout<<"c_r: "<<c_r<<endl;
								cout<<"c_g: "<<c_g<<endl;
								cout<<"c_b: "<<c_b<<endl;
								cout<<"capa: "<<temp->cor_z<<endl;
								cout<<"color_completo: "<<color_completo<<endl;
								cout<<"x,y: "<<temp->cor_x<<","<<temp->cor_y<<endl;
								system("pause");
							}
							
							
							color_hexa = RGBToHex( atoi(c_r.c_str()), atoi(c_g.c_str()), atoi(c_b.c_str()) );
							//cout<<"color_hexa: "<<color_hexa<<endl;
							
							//para css
							file_css = file_css + ".pixel:nth-child("+ k_str.str() + ") { \n";
							
							//file_css = file_css + "  background: #"+color_hexa+"; \n"; //para exadeciaml
							file_css = file_css + "  background: rgb("+c_r.c_str()+ ","+ c_g.c_str() + "," +c_b.c_str() +"); \n"; // para color rgb
							
							file_css = file_css + "} \n";
							
							///para html
							//file_html = file_html + "  <div class=\"pixel\"></div>\n";

						}
						
											    	
		    	temp = temp->right;
			}
			
		
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	//cout<<endl;
		}  	


 	
    }
    
    void matrix :: create_file_images(string nombre, string contenido) {
    	
    	string nom_ar = "";
		//nom_ar = nombre + ".css";
		nom_ar = nombre;
		
		ofstream file;
		file.open(nom_ar.c_str());
		file <<contenido;
		file.close();
		
	    //system(nom_ar.c_str());

	}
	
	string matrix :: RGBToHex(int r_int, int g_int, int b_int)
	{
		string color_hexa;
	
		char r[255];	
		sprintf(r, "%.2X", r_int);
		//cout<<"r: "<<r<<endl;
		color_hexa.append(r );
	
		char g[255];	
		sprintf(g, "%.2X", g_int);
		//cout<<"g: "<<g<<endl;
		color_hexa.append(g );
	
		char b[255];	
		sprintf(b, "%.2X", b_int);
		//cout<<"b: "<<b<<endl;
		color_hexa.append(b );
		//color_hexa = r+g+b;
		
		return color_hexa;
	}
	
	void matrix :: Capas_para_select() {
    	
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
    	
    		if (temp->valor != "RAIZ"){
	    		cout<<temp->cor_z<<" - "<<temp->valor<<endl;}
	    	
	    	temp = temp->capa_up;
		}  	
		
		cout<<temp->cor_z<<" - "<<temp->valor<<endl;
		
	}
	
	bool matrix :: Buscando_capa(int z) {
    	
    	node *temp = head;
    	while (temp != NULL) {
    	
    		if (temp->valor != "RAIZ"){
    			//cout<<temp->cor_z<<"--"<<endl;
    			if (z ==temp->cor_z){
    				//cout<<temp->cor_z<<" encontrado "<<endl;
    				return true;
					}
				}
	    	temp = temp->capa_up;
		}  		
	}
	
	////**********************fin*****para*crear*imagen*****************************************////
	
	
///**********************inicio*****para*crear*negativo imagen***********************////

//void matrix :: imagen_negativo(matrix *mat_neg) {
matrix matrix :: imagen_original(string tipo, int no_col, int no_lin, int all_capa) {
    	
    	matrix mat_mod;

    	node *temp = head;
    	//while (temp->capa_up != NULL) { 
    	while (temp != NULL) { 
    	
			//cout<<temp->cor_z<<endl;
			name_capa = temp->valor;
    		if (temp->valor != "RAIZ"){
    			
    			if (tipo == "N"){
    				read_matrix_negativ(temp, mat_mod, all_capa);
    			}
    			else if (tipo == "G"){
    				read_matrix_gris(temp, mat_mod, all_capa);
    			}
    			/*else if (tipo == "C"){
    				read_matrix_collage(temp, mat_mod, no_col, no_lin, all_capa );
    			}*/
    			else if (tipo == "EX"){
    				read_matrix_espejo_x(temp, mat_mod, no_col, all_capa );
    			}
    			else if (tipo == "EY"){
    				read_matrix_espejo_y(temp, mat_mod, no_lin, all_capa);
    			}
    			else if (tipo == "EXY"){
    				read_matrix_espejo_xy(temp, mat_mod, no_col, no_lin, all_capa);
    			}
			}
	    	temp = temp->capa_up;
		}  	
		//cout<<temp->cor_z<<endl;
		//read_matrix_original(temp, mat_neg);
		name_capa ="";
		return mat_mod;
	}
	
matrix matrix :: imagen_original_col_mos(string tipo, int no_col, int no_lin, int all_capa, int rep_x, int rep_y) {
    	
    	matrix mat_mod;

    	node *temp = head;
    	//while (temp->capa_up != NULL) { 
    	while (temp != NULL) { 
    	
			//cout<<temp->cor_z<<endl;
    		if (temp->valor != "RAIZ"){
    			
				if (tipo == "C"){
    				read_matrix_collage(temp, mat_mod, no_col, no_lin, all_capa, rep_x, rep_y );
    			}
			}
	    	temp = temp->capa_up;
		}  			
		return mat_mod;
	}
	
/*	
matrix matrix :: imagen_original_una_cap(string tipo, int no_col, int no_lin, int all_capa, int rep_x, int rep_y) {
    	
    	matrix mat_mod;

    	node *temp = head;
    	//while (temp->capa_up != NULL) { 
    	while (temp != NULL) { 	
			//cout<<temp->cor_z<<endl;
    		if (temp->valor != "RAIZ"){
    			
				if (tipo == "M"){
    				read_matrix_collage(temp, mat_mod, no_col, no_lin, all_capa, rep_x, rep_y );
    			}
			}
	    	temp = temp->capa_up;
		}  			
		return mat_mod;
	}*/
	
	void matrix :: read_matrix_negativ(node *matrix_capa, matrix mat_mod, int all_capa) {
		
		string c_r, c_g, c_b;
		string rgb_negative = "";
		int r_neg, g_neg, b_neg;
		
    	////node *temp = head;
    	node *temp = matrix_capa;
    	
    	string color_completo;
    	string color_hexa;
    	int no_col;
    	int k;
    	
    	//string name_capa;
    	
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;	
    	node *temp_sup_ini;
		   	
    	while (temp != NULL) { 
	    	temp_inicio = temp;
	    	
	    	while (temp != NULL) { 
						
						if (temp->tipo == "N")
						{
							//cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";
							color_completo = temp->valor;
							//cout<<"color_completo"<<color_completo<<endl;
							 
							if (all_capa == 0 || temp->cor_z == all_capa){
								stringstream col(color_completo);
								getline(col, c_r, '-');
								getline(col, c_g, '-');
								getline(col, c_b, '-');
								
								r_neg = 255 -  atoi(c_r.c_str());
								g_neg = 255 -  atoi(c_g.c_str());
								b_neg = 255 -  atoi(c_b.c_str());
								
						    	ostringstream neg_r, neg_g, neg_b;
						    	neg_r<<r_neg;
						    	neg_g<<g_neg;
						    	neg_b<<b_neg;
						    	rgb_negative = neg_r.str() + "-" + neg_g.str() + "-" +neg_b.str();
								//cout<<"rgb_negative"<<rgb_negative<<endl; 
							}
							//mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, rgb_negative , "tempo");
							
							//all_capa == 0 , entonces es para toda la capa
							if (all_capa == 0)
							{mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, rgb_negative , name_capa);	}
							else /// entonces es solo una capa
							{
								if (temp->cor_z == all_capa){
									mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, rgb_negative , name_capa + " ***");
								} else {
									mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , name_capa);
								}
								
							}
						}					    	
		    	temp = temp->right;
			}
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	//cout<<endl;
		}  	
    }
    
    void matrix :: read_matrix_gris(node *matrix_capa, matrix mat_mod, int all_capa) {
		
		string c_r, c_g, c_b;
		string rgb_gris = "";
		int r_neg, g_neg, b_neg;
		
    	////node *temp = head;
    	node *temp = matrix_capa;
    	
    	string color_completo;
    	string color_hexa;
    	int no_col;
    	int es_gris;
    	
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;	
    	node *temp_sup_ini;
		   	
    	while (temp != NULL) { 
	    	temp_inicio = temp;
	    	while (temp != NULL) { 
						
						if (temp->tipo == "N")
						{
							//cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";
							color_completo = temp->valor;
							//cout<<"color_completo"<<color_completo<<endl;
							 
							if (all_capa == 0 || temp->cor_z == all_capa){
								stringstream col(color_completo);
								getline(col, c_r, '-');
								getline(col, c_g, '-');
								getline(col, c_b, '-');
								
								/*r_neg = 255 -  atoi(c_r.c_str());
								g_neg = 255 -  atoi(c_g.c_str());
								b_neg = 255 -  atoi(c_b.c_str());*/
								
								es_gris = (atoi(c_r.c_str()) + atoi(c_g.c_str()) +atoi(c_b.c_str()) )/3;
								
						    	ostringstream gris_color;
						    	gris_color<<es_gris;
						    	
						    	rgb_gris = gris_color.str() + "-" + gris_color.str() + "-" +gris_color.str();
								//cout<<"rgb_negative"<<rgb_negative<<endl; 
							}
							//mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, rgb_negative , "tempo");
							
							//all_capa == 0 , entonces es para toda la capa
							if (all_capa == 0)
							{mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, rgb_gris , name_capa);	}
							else /// entonces es solo una capa
							{
								if (temp->cor_z == all_capa){
									mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, rgb_gris , name_capa+ " ***");
								} else {
									mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , name_capa );
								}
								
							}
						}					    	
		    	temp = temp->right;
			}
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	//cout<<endl;
		}  	
    }
    
	void matrix :: read_matrix_collage(node *matrix_capa, matrix mat_mod, int no_col, int no_lin, int all_capa, int rep_x, int rep_y) {
		
		int co_x, co_y;
		
		int no_x, no_y;
		//no_x = 2;
		//no_y = 2;
		
		no_x = rep_x;
		no_y = rep_y;
		
		for(int y = 1; y<=no_y ; y++){
			for(int x = 1; x<=no_x ; x++){

		
    	///node *temp = head;
    	node *temp = matrix_capa;
    	
    	node *temp_inicio;	
    	node *temp_sup_ini;
		   	

    	while (temp != NULL) { 
	    	temp_inicio = temp;
	    	while (temp != NULL) { 
						
					if (temp->tipo == "N")
					{
						//cout<<"("<<x<<","<<y<<") ";
						
						co_x = (x-1)*no_col; //para columnas x
						co_y = (y-1)*no_lin; //para lienas y
						
						
						mat_mod.add(temp->data, co_x + temp->cor_x, co_y + temp->cor_y, temp->cor_z, temp->valor , name_capa);
						////all_capa == 0 , entonces es para toda la capa
						//if (all_capa == 0)
						//{mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , "tempo");	}
						//else /// entonces es solo una capa
						//{
						//	if (temp->cor_z == all_capa){
						//		mat_mod.add(temp->data, no_col - temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , "tempo");
						//	} else {
						//		mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , "tempo");
						//	}	
						//}
					}					    	
		    	temp = temp->right;
			}
			
			temp = temp_inicio;
	    	temp = temp->down;
	    	//cout<<endl;
		}  	
		
		
			}
			//cout<<endl;
		}
    }
    
    void matrix :: read_matrix_espejo_x(node *matrix_capa, matrix mat_mod, int no_col,int all_capa) {
		
    	///node *temp = head;
    	node *temp = matrix_capa;
    	no_col = no_col + 1;
    	
    	node *temp_inicio;	
    	node *temp_sup_ini;
		   	

    	while (temp != NULL) { 

	    	temp_inicio = temp;
	    	while (temp != NULL) { 
						
					if (temp->tipo == "N")
					{
						//cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";
						//all_capa == 0 , entonces es para toda la capa
						if (all_capa == 0)
						{mat_mod.add(temp->data, no_col - temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , name_capa);	}
						else /// entonces es solo una capa
						{
							if (temp->cor_z == all_capa){
								mat_mod.add(temp->data, no_col - temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , name_capa +" ***");
							} else {
								mat_mod.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , name_capa);
							}
							
						}
					}					    	
		    	temp = temp->right;
			}
			
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	//cout<<endl;
		}  	
    }
    
     void matrix :: read_matrix_espejo_y(node *matrix_capa, matrix mat_neg, int no_lin, int all_capa) {
		
    	////node *temp = head;
    	node *temp = matrix_capa;
    	
    	no_lin = no_lin + 1;
    	
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;	
    	node *temp_sup_ini;
		   	

    	while (temp != NULL) { 
	    	temp_inicio = temp;
	    	while (temp != NULL) { 
						
						if (temp->tipo == "N")
						{
							//cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";
							//mat_neg.add(temp->data, temp->cor_x, no_lin - temp->cor_y, temp->cor_z, temp->valor , "tempo");
							
							//all_capa == 0 , entonces es para toda la capa
							if (all_capa == 0)
							{mat_neg.add(temp->data, temp->cor_x, no_lin - temp->cor_y, temp->cor_z, temp->valor , name_capa);	}
							else /// entonces es solo una capa
							{
								if (temp->cor_z == all_capa){
									mat_neg.add(temp->data, temp->cor_x, no_lin - temp->cor_y, temp->cor_z, temp->valor , name_capa +" ***");
								} else {
									mat_neg.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , name_capa);
								}
								
							}
							
						}
					    	
		    	temp = temp->right;
			}
			temp = temp_inicio;
	    	temp = temp->down;
	    	
	    	//cout<<endl;
		}  	
    }
    
    void matrix :: read_matrix_espejo_xy(node *matrix_capa, matrix mat_neg, int no_col, int no_lin, int all_capa) {
		
    	////node *temp = head;
    	node *temp = matrix_capa;
    	
    	no_col = no_col + 1;
    	no_lin = no_lin + 1;
    	
    	//node *temp = nodo_x_nivel;
    	node *temp_inicio;	
    	node *temp_sup_ini;
		   	

    	while (temp != NULL) { 

	    	temp_inicio = temp;

	    	while (temp != NULL) { 
						
						if (temp->tipo == "N")
						{
							//cout<<"("<<temp->cor_x<<","<<temp->cor_y<<")";
							//mat_neg.add(temp->data, no_col - temp->cor_x, no_lin - temp->cor_y, temp->cor_z, temp->valor , "tempo");
							
							//all_capa == 0 , entonces es para toda la capa	
							if (all_capa == 0)
							{mat_neg.add(temp->data, no_col - temp->cor_x, no_lin - temp->cor_y, temp->cor_z, temp->valor , name_capa);	}
							else //// entonces es solo una capa
							{
								if (temp->cor_z == all_capa){
									mat_neg.add(temp->data, no_col - temp->cor_x, no_lin - temp->cor_y, temp->cor_z, temp->valor , name_capa+" ***");
								} else {
									mat_neg.add(temp->data, temp->cor_x, temp->cor_y, temp->cor_z, temp->valor , name_capa);
								}
								
							}	
						
						}				    	
		    	temp = temp->right;
			}

			temp = temp_inicio;
	    	temp = temp->down;
	    	//cout<<endl;
		}  	
    }

///**********************fin*****para*crear*negativo imagen***********************////
