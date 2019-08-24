#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

using namespace std;

class NodeCir {
public:
    NodeCir *siguiente;
    NodeCir *anterior;
    int val;
    
    NodeCir (int val) {
        this->val = val;
        siguiente = NULL;
        anterior = NULL;
    }
};

class Lista_cir {
public:
	int size;
	NodeCir *primero_head;
	NodeCir *ultimo;
	
	Lista_cir () {
	primero_head = NULL;
	ultimo = NULL;
	size=0;
	}
	bool esVacio();
	void Insert_nod(int val);
	void Lista_imprimir_ade();
	void Lista_imprimir_atra();
	void Graf_filters();
	 
	
};

bool Lista_cir :: esVacio() {
	return (primero_head ==NULL);
}	

void Lista_cir :: Insert_nod(int val) {
	NodeCir *new_nod = new NodeCir(val);
 
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
void Lista_cir :: Lista_imprimir_ade() {
	
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

//Imprimir lista atras
void Lista_cir :: Lista_imprimir_atra() {
	
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
void Lista_cir :: Graf_filters() {
	
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

int main()
{
	Lista_cir lis_c;
	
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

} 
