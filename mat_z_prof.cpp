#include <iostream>

using namespace std;

class node {
public:
    node* right;
	node* left;
    node* down;
    node* up;
    
    node* capa_up; // profundidad de la capa, arriba
    node* capa_down; // profundidad de la capa, abajo
    
    int data;
    int cor_y;
    int cor_x;
    int cor_z;
    
    node (int data_ , int x, int y, int z) {
        data = data_;
        //this->data = data;
        
        cor_y = y;
        cor_x = x;
        cor_z = z;
        
        right  = NULL;
        left = NULL;
        down  = NULL;
        up = NULL;
        
        capa_up = NULL;
        capa_down = NULL;
    }
};


class matrix {
public:
    node *head;
    
    matrix () {
        //head  = NULL;  
        //				   data, x, y, z
		node *temp = new node(0, 0, 0, 0);
		head = temp;  
    }
    
    void add (int value, int x, int y, int z) {
    	//1 crear header
    	//1.1 creade x header
    	//cout<<"x: " <<x<<endl; 
    	add_z_header(z);
    	add_x_header(x, z);
    	add_y_header(y, z);  	
    	//1.2 create y header
    	
    	
    	//2 insert nodo
    	//node *new_node = new node(value);
    	node *new_node = new node(value, x, y, z);
    	//add_x(new_node, x);
    	//add_y(new_node, y, x);
    	
    	//primero insertamos profundidad
    	//add_z(new_node, x, y);
    	
    	//add_x(new_node, x, y);
    	//add_y(new_node, x, y);
    	
    	///**********insertando nodos**************/////
    	add_x(new_node, x, y, z);
    	add_y(new_node, x, y, z);
    	
    	//add_z(new_node, x, y, z);
    	
  
          
    }
    
    void add_x(node *new_node, int x, int y, int z){
    	node *tem = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(tem->cor_z != z){
    		tem = tem->capa_up;
		}
		//cout<<"2222 z,x indice: "<<tem->data<<" "<<endl;				
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
	
	void add_y(node *new_node, int x, int y, int z){
		node *tem= head;
		/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(tem->cor_z != z){
    		tem = tem->capa_up;
		}
		//cout<<"2222 z,y indice: "<<tem->data<<" "<<endl;
		
		///////*********************************************1
				
		/*recorre por y, para insertar a la derecha (x)*/
		//while(tem->data != y){		
		while(tem->cor_y != y){
    		tem = tem->down;
		}
		if(tem->right == NULL){
			tem->right = new_node;
			new_node->left = tem;
		}
		else if(tem->right->cor_x >= x ){
		//else if( x < tem->right->cor_x ){
		   
		   	node *ul_der = tem->right;
		   	
			tem->right = new_node;
			new_node->left = tem;
			
			//para que enlace el que estaba antes
			new_node->right = ul_der;
			ul_der->left = new_node;
		}
		else
		{
			node *temp_der = tem->right;
			while (temp_der->right != NULL && temp_der->right->cor_x < x ) { 
				temp_der = temp_der->right;
    		}
    		temp_der->right = new_node;
			new_node->left = temp_der;
		}
	}
	
    //void add_x_header(int x){
    void add_x_header(int x,  int z) {
    	
    	node *head_x = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(head_x->cor_z != z){
    		head_x = head_x->capa_up;
		}
		//cout<<"222 z,x head_x: "<<head_x->data<<" "<<endl;
    	if (head_x->right == NULL) { 
	    	//node *temp = new node(x);    	
	    	node *temp = new node(x,x,0,z);
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
		    	node *new_temp = new node(x, x, 0, z);
		    	temp->right = new_temp;
		    	new_temp->left = temp; 
		    	
	    		}else if (temp->right != NULL && temp->right->data != x )
				{
	    			//node *new_temp = new node(x);
	    			node *new_temp = new node(x, x, 0, z);
	    			node *der = temp->right;
	    			
	    			temp->right =new_temp;
	    			new_temp->left = temp;
	    			new_temp->right = der;
	    			der->left = new_temp;
				
				}
    	
    	}
    }
    
    //void add_y_header(int y) {
    void add_y_header(int y, int z) {
    	node *head_y = head;
    	
    	/*primero recorre prufundidad*/
		/*recorre por z, para insertar a la derecha*/	
		while(head_y->cor_z != z){
    		head_y = head_y->capa_up;
		}	
    		
    	if (head_y->down == NULL) { 
	    	//node *temp = new node(y);
	    	node *temp = new node(y, 0, y, 0);
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
		    	node *new_temp = new node(y, 0 , y,0);
		    	temp->down = new_temp;
		    	new_temp->up = temp; 
		    	
	    		}else if (temp->down != NULL && temp->down->data != y )
				{
	    			//node *new_temp = new node(y);
	    			node *new_temp = new node(y, 0,y, 0);
	    			node *der = temp->down;
	    			
	    			temp->down =new_temp;
	    			new_temp->up = temp;
	    			new_temp->down = der;
	    			der->up = new_temp;				
				}
    	}
    }
    
       void add_z_header(int z) {
    	  	
    	if (head->capa_up == NULL) { 
	    	//node *temp = new node(x);    	
	    	node *temp = new node(z,0,0,z);
	    	head->capa_up = temp;
	    	temp->capa_down = head; 
    	} else  {     	
		node *temp =head;
		while (temp->capa_up != NULL && temp->capa_up->data < z ) { 
			temp = temp->capa_up;
    	}

			 if (temp->capa_up == NULL ) { 
		    	//node *new_temp = new node(z);
		    	node *new_temp = new node(z, 0, 0, z);
		    	temp->capa_up = new_temp;
		    	new_temp->capa_down = temp; 
		    	
	    		}else if (temp->capa_up != NULL && temp->capa_up->data != z )
				{
	    			//node *new_temp = new node(z);
	    			node *new_temp = new node(z, 0, 0, z);
	    			node *c_up = temp->capa_up;
	    			
	    			temp->capa_up =new_temp;
	    			new_temp->capa_down = temp;
	    			
	    			new_temp->capa_up = c_up;
	    			c_up->capa_down = new_temp;
	    			
				
				}
    	
    	}
    }
    
    void print_headers(){
    	//print_x_header();
    	//print_y_header();
    	
    	//cout<<"cor en z, profundidad"<<endl; 
    	//print_z_header();
    	//cout<<endl<<endl; 
    	
    	cout <<"impriendo matrix por capas"<<endl; 
    	
    	print_z_header_capas_z();
	}
    
    /*print*/
    void print_x_header() {
    	node *temp = head;
    	while (temp->right != NULL) { 
	    	cout<<temp->data<<"->";
	    	//cout<<temp->data<<endl;
	    	temp = temp->right;
		}  	
		//cout<<temp->data<<"->";
		cout <<temp->data<<endl;    
    }
    
      void print_y_header() {
    	node *temp = head;
    	while (temp->down != NULL) { 
	    	cout<<temp->data<<endl;
	    	temp = temp->down;
		}  	
		cout <<temp->data<<endl;    
    }
    
    /*print por profundidad*/
     void print_x_header_capas_z(node *nodo_cap) {
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
    
      void print_y_header_capas_z(node *nodo_cap) {
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
    void print_z_header_capas_z() {
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
    
      void print_z_header() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<temp->data<<endl;
	    	temp = temp->capa_up;
		}  	
		cout <<temp->data<<endl;    
    }
    
    
    
    /*void print_nodes_x() {
    	node *temp = head;
    	while (temp->down != NULL) { 
	    	cout<<temp->data<<endl;
	    	temp = temp->down;
		}  	
		cout <<temp->data<<endl;    
    	
    }*/
    
	void print_nodes_x() {
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
    
    void print_nodes_y() {
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
    
    ///capas de cordenadas
    void print_node_cor_z() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"c_o_z: "<<temp->data<<endl;
	    	print_node_cor_mat(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"c_o_z: "<<temp->data<<endl;
		print_node_cor_mat(temp);
		
    }
    
    void print_node_cor_mat(node *nodo_x_nivel) {
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
		//cout <<"termina"<<endl;   
 	
    }
    
    
    void print_node_cor() {
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
    void print_node_cor_orde_zz() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"c_mm_z: "<<temp->data<<endl;
	    	print_node_cor_orde_mat(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"c_mm_z: "<<temp->data<<endl;
		print_node_cor_orde_mat(temp);
		
    }
    
     void print_node_cor_orde_der_abaj_z() {
    	node *temp = head;
    	while (temp->capa_up != NULL) { 
	    	cout<<"c_yy_z: "<<temp->data<<endl;
	    	print_node_cor_orde_der_abaj_mat(temp);
	    	temp = temp->capa_up;
		}  	
		cout<<"c_yy_z: "<<temp->data<<endl;
		print_node_cor_orde_der_abaj_mat(temp);
		
    }
    
    void print_node_cor_orde_mat(node *nodo_x_nivel) {
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
    
    void print_node_cor_orde() {
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
    void print_node_cor_orde_der_abaj_mat(node *nodo_x_nivel) {
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
		
		cout <<"termina reco der abaj"<<endl;   
    	
    }
    
    ///para recorer de derecha hacia abajo
    void print_node_cor_orde_der_abaj() {
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
    
    
};

int main(){
	
	matrix *sm = new matrix;
	//sm->add(12,3,2);
	//sm->add(99,0,0);
		
		
	sm->add(10,2,1,2);
	sm->add(12,5,2,2);
	sm->add(25,3,4,2);
	sm->add(15,3,6,5);
	sm->add(35,5,3,2);
	sm->add(20,7,4,4);
	sm->add(1212,5,2,4);
	
	sm->add(22,2,2,4);
	
	/*sm->add(10,2,5);
	sm->add(12,6,1);
	sm->add(25,8,3);
	sm->add(15,2,1);
	sm->add(35,1,2);*/

	
	
	//sm->add(12,6,1);
	//sm->add(15,2,1);
	
	//sm->add(56,4,5);
	//sm->add(55,4,2);
	

	sm->print_headers();
	
	//cout <<"va imprimir valores"<<endl;    
	//cout <<"recorre der enlace abajo"<<endl;   
	//sm->print_nodes_x();
	//cout <<"recorre abajo enlace der"<<endl;   
	//sm->print_nodes_y();
	
	cout<<endl<<endl<<"-"<<endl;   
	cout<<"print_node_cor_z"<<endl; 
	//sm->print_node_cor();
	sm->print_node_cor_z();
	cout<<endl<<endl<<"cordenada abajo, derecha"<<endl; 
	//sm->print_node_cor_orde();
	sm->print_node_cor_orde_zz();
	
	
	//cout<<endl<<endl<<"cordenada derecha, abajo"<<endl; 
	////sm->print_node_cor_orde_der_abaj();
	//sm->print_node_cor_orde_der_abaj_z();
}


