#include <iostream>

using namespace std;

class node {
public:
    node* right;
	node* left;
    node* down;
    node* up;
    
    int data;
    int cor_y;
    int cor_x;
    
    node (int data_ , int x, int y) {
        data = data_;
        //this->data = data;
        
        cor_y = y;
        cor_x = x;
        
        right  = NULL;
        left = NULL;
        down  = NULL;
        up = NULL;
        
    }
};


class matrix {
public:
    node *head;
    
    matrix () {
        //head  = NULL;  
		node *temp = new node(0, 0, 0);
		head = temp;  
    }
    
    void add (int value, int x, int y) {
    	//1 crear header
    	//1.1 creade x header
    	//cout<<"x: " <<x<<endl; 
    	add_x_header(x);
    	add_y_header(y);
    	//1.2 create y header
    	
    	//2 insert nodo
    	//node *new_node = new node(value);
    	node *new_node = new node(value, x, y);
    	//add_x(new_node, x);
    	//add_y(new_node, y, x);
    	
    	add_x(new_node, x, y);
    	add_y(new_node, x, y);
    	
    	//add_node(value, x, y);
          
    }
    
    void add_x(node *new_node, int x, int y){
    	node *tem= head;
    	while(tem->data != x){
    		tem = tem->right;
		}
		if(tem->down == NULL){
			tem->down = new_node;
			new_node->up = tem;
		} 
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
	
	void add_y(node *new_node, int x, int y){
		node *tem= head;		
		while(tem->data != y){
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
	
    
   /* void add_node(int value, int x, int y){
    	node *tem= head;
    	while(tem->data != x){
    		tem = tem->right;
		}
		cout <<"se ingrea en la cabecera x= "<<tem->data<<endl;   
		
	}*/

    
    void add_x_header(int x) {
    	if (head->right == NULL) { 
    		//cout<<"2x: " <<x<<endl; 
	    	//node *temp = new node(x);
	    	
	    	node *temp = new node(x,x,0);
	    	head->right = temp;
	    	temp->left = head; 
    	} else  {     	
		node *temp =head;
		while (temp->right != NULL && temp->right->data < x ) { 
			temp = temp->right;
    	} 
			 if (temp->right == NULL ) { 
		    	//node *new_temp = new node(x);
		    	node *new_temp = new node(x, x, 0);
		    	temp->right = new_temp;
		    	new_temp->left = temp; 
		    	
	    		}else if (temp->right != NULL && temp->right->data != x )
				{
	    			//node *new_temp = new node(x);
	    			node *new_temp = new node(x, x, 0);
	    			node *der = temp->right;
	    			
	    			temp->right =new_temp;
	    			new_temp->left = temp;
	    			new_temp->right = der;
	    			der->left = new_temp;
				
				}
    	
    	}
    }
    
    void add_y_header(int y) {
    	if (head->down == NULL) { 
	    	//node *temp = new node(y);
	    	node *temp = new node(y, 0, y);
	    	head->down = temp;
	    	temp->up = head; 
    	} else  {     	
		node *temp =head;
		while (temp->down != NULL && temp->down->data < y ) { 
			temp = temp->down;
	} 
			 if (temp->down == NULL ) { 
		    	//node *new_temp = new node(y);
		    	node *new_temp = new node(y, 0 , y);
		    	temp->down = new_temp;
		    	new_temp->up = temp; 
		    	
	    		}else if (temp->down != NULL && temp->down->data != y )
				{
	    			//node *new_temp = new node(y);
	    			node *new_temp = new node(y, 0,y);
	    			node *der = temp->down;
	    			
	    			temp->down =new_temp;
	    			new_temp->up = temp;
	    			new_temp->down = der;
	    			der->up = new_temp;
				
				}
    	
    	}
    }
    void print_headers(){
    	print_x_header();
    	print_y_header();
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
				
				if (temp != NULL)
		    	{
		    		cout<<"x: "<<temp->data<<" ";	
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
		    		cout<<"(x:"<<temp->cor_x<<" y:"<<temp->cor_y<<")";	
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
		
	/*	
	sm->add(10,2,1);
	sm->add(12,5,2);
	sm->add(25,3,4);
	sm->add(15,3,6);
	sm->add(35,5,3);
	sm->add(20,7,4);*/ 
	
	//sm->add(10,2,5);
	//sm->add(12,6,1);
	//sm->add(25,8,3);
	//sm->add(15,2,1);
	//sm->add(35,1,2);

	
	
	//sm->add(12,6,1);
	//sm->add(15,2,1);
	
	sm->add(56,4,5);
	sm->add(55,4,2);
	
	
	
	
	sm->print_headers();
	
	cout <<"va imprimir valores"<<endl;    
	cout <<"recorre der enlace abajo"<<endl;   
	sm->print_nodes_x();
	cout <<"recorre abajo enlace der"<<endl;   
	sm->print_nodes_y();
	
	cout<<endl<<endl<<"-"<<endl;   
	sm->print_node_cor();
	cout<<endl<<endl<<"cordenada abajo, derecha"<<endl; 
	sm->print_node_cor_orde();
	
	cout<<endl<<endl<<"cordenada derecha, abajo"<<endl; 
	sm->print_node_cor_orde_der_abaj();
}


