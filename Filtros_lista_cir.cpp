#include "Filtros_lista_cir.h"

#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

#include "Matrix_cub.h"

bool Filtros_lista_cir :: esVacio() {
	return (primero_head ==NULL);
}	

void Filtros_lista_cir :: Insert_nod(int tipo, matrix mat_cub,  string filtro) {
	NodeCir *new_nod = new NodeCir(tipo, mat_cub, filtro);
 
	if (esVacio() == true)
	{
		primero_head = new_nod;
        ultimo = new_nod;

        primero_head->anterior = ultimo;
        ultimo->siguiente = primero_head;       

	} 
	else
	{
		ultimo->siguiente = new_nod;
        new_nod->anterior = ultimo;
        ultimo = new_nod;

        primero_head->anterior = ultimo;
        ultimo->siguiente = primero_head;
        
	} 
	size++;
	

}	

//Imprimir lista adelante
void Filtros_lista_cir :: Lista_imprimir_ade() {
	
	if (esVacio() == true)
	{
		cout<< "La  lista esta vacia \n";
	} 
	else
	{
		NodeCir *temp_prin = primero_head;
        while (temp_prin != ultimo)
		{   
			cout<<"emp_prin->val: "<< temp_prin->val <<endl;       
            temp_prin = temp_prin->siguiente;
        }
        cout<<"emp_prin->val: "<< temp_prin->val <<endl;  
        
	} 

}

//Imprimir lista de filtros
void Filtros_lista_cir :: Lista_print_filters() {
	
	if (esVacio() == true)
	{
		cout<< "La  lista esta vacia \n";
	} 
	else
	{
		int index = 0;
		NodeCir *temp_prin = primero_head;
        while (temp_prin != ultimo)
		{   index++;
			////cout<<"emp_prin->val: "<< temp_prin->val <<endl;   
			//cout<<index<<" - "<< temp_prin->filtro <<endl;     
			
			cout<<index<<" - "<< temp_prin->filtro; 
			if (temp_prin->val != 0){
				cout<<" Capa "<< temp_prin->val; 
			}
			
			cout<<endl; 
            temp_prin = temp_prin->siguiente;
        }
        index++;
        cout<<index<<" - "<< temp_prin->filtro; 
        if (temp_prin->val != 0){
				cout<<" Capa "<< temp_prin->val <<endl; 
			}
        
	} 

}


bool Filtros_lista_cir :: Buscando_ima(int in) {
    	int index = 0;
		NodeCir *temp_prin = primero_head;
    	while (temp_prin != ultimo){
		index++;	
		//cout<<"index : "<< index<<"*"<< temp_prin->filtro <<endl; 
			if (in == index){
				//cout<<"ee : "<< temp_prin->filtro <<endl; 
				filter_a_reportar = temp_prin;
				return true;
			}
	    	temp_prin = temp_prin->siguiente;
		}
		index++;	
		if (in == index){
			//cout<<"22 encontrado: "<< temp_prin->filtro <<endl; 
			filter_a_reportar = temp_prin;
			return true;
		}
		return false;
}

matrix Filtros_lista_cir :: return_mat_ima(int in) {

    	int index = 0;
		NodeCir *temp_prin = primero_head;
    	while (temp_prin != ultimo){
		index++;	
			if (in == index){
				
				name_actual = temp_prin->filtro; 
				if (temp_prin->val != 0){
					ostringstream cap;
			    	cap<<temp_prin->val;
					name_actual = name_actual +" Capa "+cap.str();
				}
				return temp_prin->mat;
			}
	    	temp_prin = temp_prin->siguiente;
		}
		index++;	
		if (in == index){
			
			name_actual = temp_prin->filtro; 
			if (temp_prin->val != 0){
				ostringstream cap;
		    	cap<<temp_prin->val;
				name_actual = name_actual +" Capa "+cap.str();
			}
			return temp_prin->mat;
		}
}

/*string Filtros_lista_cir :: return_name_fil(int in) {

    	int index = 0;
		NodeCir *temp_prin = primero_head;
    	while (temp_prin != ultimo){
		index++;	
			if (in == index){
				name_actual = temp_prin->filtro; 
				return name_actual;
			}
	    	temp_prin = temp_prin->siguiente;
		}
		index++;	
		if (in == index){
			name_actual = temp_prin->filtro; 
			return name_actual;
		}
}*/

//Imprimir lista atras
void Filtros_lista_cir :: Lista_imprimir_atra() {
	
	if (esVacio() == true)
	{
		cout<< "La  lista esta vacia \n";
	} 
	else
	{
		NodeCir *temp_prin = ultimo;
        while (temp_prin != primero_head)  
		{   cout<<"emp_prin->val: "<< temp_prin->val <<endl;              
            temp_prin = temp_prin->anterior;
        }
        cout<<"emp_prin->val: "<< temp_prin->val <<endl;
        
	} 

}
//Imprimir lista atras
void Filtros_lista_cir :: Graf_filters() {
	
	//f = open("user_list.txt", "w")
    //f.write("digraph G { rankdir=LR\n")
    //f.write("node [shape=record];\n")
    string nodo_name = "";
    string nodo_name_sig = "";
    int nod = 0;
    
    ofstream file;
	file.open("filters.txt");
	file <<"digraph G { rankdir=LR\n";
    file <<"node [shape=record dir=both];\n";

    if (esVacio() == true){
        cout<< "La  lista esta vacia, no se puede graficar\n"; } 
	else {
        NodeCir *temp_prin = primero_head;
        while (temp_prin != ultimo) {    
			//nodo_name =  str(temp_prin.iduser)
            //nodo_name_sig = str(temp_prin.siguiente.iduser)  
            nodo_name = static_cast<ostringstream*>(&(ostringstream()<<nod ))->str();
            nodo_name_sig = static_cast<ostringstream*>(&(ostringstream()<<nod+1 ))->str(); 
            file <<"node" << nodo_name << "[label = \"{<f0>|<f1> "<< temp_prin->val <<"|<f2> }\"];\n";           
            
            file <<"node"+ nodo_name +" -> ";
            file <<"node"+ nodo_name_sig +" ;\n"; 

            file <<"node"+ nodo_name_sig +" -> ";
            file <<"node"+ nodo_name +" ;\n";

            temp_prin = temp_prin->siguiente;
            nod++;
        	}
        //nodo_name =  str(temp_prin.iduser)
        //nodo_name_sig = str(temp_prin.siguiente.iduser)
        nodo_name = static_cast<ostringstream*>(&(ostringstream()<< nod ))->str();
        nodo_name_sig =  static_cast<ostringstream*>(&(ostringstream()<<0 ))->str(); 

        file <<"node" << nodo_name <<"[label = \"{<f0>|<f1> "<< temp_prin->val <<"|<f2> }\"];\n";

        file <<"node"+ nodo_name +" -> ";
        file <<"node"+ nodo_name_sig +";\n"; 

        file <<"node"+ nodo_name_sig +" -> ";
        file <<"node"+ nodo_name +";\n";

	}
    file <<"}";
	file.close();

    system("dot -Tpng filters.txt -o filters.jpg");
    system("filters.jpg");
    
}	

void Filtros_lista_cir :: Graf_filters_all() {
	
	//f = open("user_list.txt", "w")
    //f.write("digraph G { rankdir=LR\n")
    //f.write("node [shape=record];\n")
    string nodo_name = "";
    string nodo_name_sig = "";
    int nod = 0;
    string name_filter;
    
    ofstream file;
	file.open("filters.txt");
	file <<"digraph G { rankdir=LR\n";
    file <<"node [shape=record dir=both];\n";

    if (esVacio() == true){
        //cout<< "La  lista esta vacia, no se puede graficar\n"; 
		} 
	else {
        NodeCir *temp_prin = primero_head;
        while (temp_prin != ultimo) {    
			//nodo_name =  str(temp_prin.iduser)
            //nodo_name_sig = str(temp_prin.siguiente.iduser)  
            nodo_name = static_cast<ostringstream*>(&(ostringstream()<<nod ))->str();
            nodo_name_sig = static_cast<ostringstream*>(&(ostringstream()<<nod+1 ))->str(); 
            
			name_filter =  temp_prin->filtro; 
			if (temp_prin->val != 0){
				ostringstream cap;
            	cap<<temp_prin->val;
				name_filter = name_filter + " Capa " + cap.str(); 
			}
			
			
			file <<"node" << nodo_name << "[label = \"{<f0>|<f1> "<< name_filter <<"|<f2> }\"];\n";           
            
            file <<"node"+ nodo_name +" -> ";
            file <<"node"+ nodo_name_sig +" ;\n"; 

            file <<"node"+ nodo_name_sig +" -> ";
            file <<"node"+ nodo_name +" ;\n";

            temp_prin = temp_prin->siguiente;
            nod++;
        	}
        //nodo_name =  str(temp_prin.iduser)
        //nodo_name_sig = str(temp_prin.siguiente.iduser)
        nodo_name = static_cast<ostringstream*>(&(ostringstream()<< nod ))->str();
        nodo_name_sig =  static_cast<ostringstream*>(&(ostringstream()<<0 ))->str(); 

		name_filter =  temp_prin->filtro; 
			if (temp_prin->val != 0){
				ostringstream cap;
            	cap<<temp_prin->val;
				name_filter = name_filter + " Capa " + cap.str(); 
			}
        file <<"node" << nodo_name <<"[label = \"{<f0>|<f1> "<< name_filter <<"|<f2> }\"];\n";

        file <<"node"+ nodo_name +" -> ";
        file <<"node"+ nodo_name_sig +";\n"; 

        file <<"node"+ nodo_name_sig +" -> ";
        file <<"node"+ nodo_name +";\n";

	}
    file <<"}";
	file.close();

    system("dot -Tpng filters.txt -o filters.jpg");
    system("filters.jpg");
    
}
/*
int main()
{
	Filtros_lista_cir lis_c;
	
	lis_c.Insert_nod(1);
	lis_c.Insert_nod(2);
	lis_c.Insert_nod(3);
	lis_c.Insert_nod(4);
	lis_c.Insert_nod(55);
	lis_c.Lista_imprimir_ade();
	
	cout<<"lis_c.size: "<<lis_c.size <<endl;  
	
	cout<<"--imprime atras-----"<<endl;
	lis_c.Lista_imprimir_atra();
	lis_c.Graf_filters();

} */
