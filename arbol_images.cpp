#include <iostream>
#include <string.h> 
#include <fstream>

using namespace std;

class Node {
public:
    Node *n_der,*n_izq;
    string data;
    string valor2;
    //Node (string name, valor2) {
    Node (string name) {
        data = name;
        n_izq = n_der = NULL;
    }
};

class arbol_images {
public:
    Node* root;
    int size=0;
    int index_root;
    arbol_images () {root = NULL; }
    bool insert(string data) { 
        return insert(data,root); 
    };
    bool insert(string name, Node* raiz_actual);
    
    void inorder()  { inorder(root);};
    void postorder()  { postorder(root);};
    void preorder()  { preorder(root);};
    void inorder( Node* actual) ;
    void postorder( Node*actual);
    void preorder( Node* actual) ;
    
    //print
    void print_inorder()  { print_inorder(root);};
    void print_inorder( Node* actual) ;
    
    void Graficando_inor();
    void Graficando_preor();
    void Graficando_posor();
    void Graficando_arbolbi();
    
    void create_archivo(string nombre, string contenido);
    
    string grafica_orden;
    
};

bool arbol_images :: insert(string name, Node *raiz_actual) {
	int compar_nombre;
	compar_nombre = 0;
	
    if (root == NULL) {
        root = new Node(name);
        size++;
        //cout << " \nsize " << size ;
        return true;
    //}else if (nombre < raiz_actual->data) {   
    }
		else if (compar_nombre = strcmp(name.c_str() ,raiz_actual->data.c_str()) < 0) {
        if (raiz_actual->n_izq == NULL) {
            raiz_actual->n_izq = new Node(name);
            size++;
            return true;
        }
        else {
            return insert(name, raiz_actual->n_izq);
        }
    //}else if (nombre > raiz_actual->data) {
    }
	else if (compar_nombre = strcmp(name.c_str() ,raiz_actual->data.c_str()) > 0) {
        if (raiz_actual->n_der == NULL) {
            raiz_actual->n_der = new Node(name);
            size++;
            return true;
        }
        else {
            return insert(name, raiz_actual->n_der);
        }
    }else {
        return false;
    }
}

void arbol_images :: inorder( Node *root) {
    if (root != NULL) {
        inorder(root -> n_izq);
        //cout << " " << root->data << " ->";
        //cout<< root->data <<endl;
        index_root++;
        if (index_root != size)
		{grafica_orden = grafica_orden + " \"" + root->data + "\" ->"; }
        else{grafica_orden = grafica_orden + " \"" + root->data + "\""; }
        
        //grafica_orden = grafica_orden + " " + root->data;
        inorder(root -> n_der);
    }
    
}


void arbol_images :: print_inorder( Node *root) {

    if (root != NULL) {
        print_inorder(root -> n_izq);
        index_root++;
        //cout<< root->data <<"/"<<index_root<<endl;
        if (index_root != size){
        	grafica_orden = grafica_orden + " " + root->data + " ->"; 
        	}	else	{grafica_orden = grafica_orden + "" + root->data; }
        //grafica_orden = grafica_orden + "" + root->data + " ->"; 
        
        //cout<< root->data <<endl;
        ////////////cout << " " << root->data << " ->";
        print_inorder(root -> n_der);
    }
    
}

void arbol_images::Graficando_inor() {
	index_root = 0;
	grafica_orden = grafica_orden + "digraph G { rankdir=LR\n";
	//print_inorder();
	inorder();
    grafica_orden = grafica_orden + "\n}\n";
    cout << "inorder: \n";
	//cout <<grafica_orden<<endl;
	//cout << "\n +index_root+ : " <<index_root<<endl;
	create_archivo("graf_in",grafica_orden);
	
}

/*graficando arbol binario*/
void arbol_images::Graficando_arbolbi() {
	index_root = 0;
	grafica_orden = grafica_orden + "digraph G { \n";
	grafica_orden = grafica_orden + "graph [ordering=\"out\"] \n";
	inorder();
    grafica_orden = grafica_orden + "\n}\n";
    cout << "arbol bonario: \n";
    cout << "grafica_orden: "<<grafica_orden <<endl;
	create_archivo("graf_arbol",grafica_orden);
	
}

void arbol_images::Graficando_preor() {
	index_root = 0;
	grafica_orden = grafica_orden + "digraph G { rankdir=LR\n";
	preorder();
    grafica_orden = grafica_orden + "\n}\n";
    cout << "preorder: \n";
	//cout <<grafica_orden<<endl;
	//cout << "\n +index_root+ : " <<index_root<<endl;
	create_archivo("graf_pre",grafica_orden);
}

void arbol_images::Graficando_posor() {
	index_root = 0;
	grafica_orden = grafica_orden + "digraph G { rankdir=LR\n";
	postorder();
    grafica_orden = grafica_orden + "\n}\n";
    cout << "posorder: \n";
	//cout <<grafica_orden<<endl;
	//cout << "\n +index_root+ : " <<index_root<<endl;
	create_archivo("graf_pos",grafica_orden);
}

void arbol_images :: preorder( Node *root) {
    if (root != NULL) {
        //cout << " " << root->data << " ->";
        index_root++;
        if (index_root != size)
		{grafica_orden = grafica_orden + "\"" + root->data + "\" ->"; }
        else{grafica_orden = grafica_orden + "\"" + root->data + "\""; }
        //cout<< root->data <<endl;
        preorder(root -> n_izq);
        preorder(root -> n_der);
    }
    
}
void arbol_images :: postorder( Node *root) {
    if (root != NULL) {
        postorder(root -> n_izq);
        postorder(root -> n_der);
        //cout << " " << root->data << " ->";
        //cout<< root->data <<endl;
        index_root++;
        if (index_root != size)
		{grafica_orden = grafica_orden + "\"" + root->data + "\" ->"; }
        else{grafica_orden = grafica_orden + "\"" + root->data + "\""; }
    }
    
}

void arbol_images::create_archivo(string nombre, string contenido) {
	
	nombre = nombre + ".txt";
	ofstream file;
	file.open(nombre.c_str());
	file <<contenido;
	file.close();
	string dot, ima;
	dot = "dot -Tpng "+ nombre + " -o "+nombre + ".jpg";
	ima = nombre + ".jpg";
	//cout << " \n dot *** " << dot ;
	//cout << " \n ima *** " << ima ;
	system(dot.c_str());
    system(ima.c_str());
	
}




int main()
{
    arbol_images ar_ima;
    
	ar_ima.insert("Mario1");
    ar_ima.insert("Pickachu");
    ar_ima.insert("Boo");
    ar_ima.insert("Geoff");
    ar_ima.insert("Mario2");
    ar_ima.insert("Mushroom");
    //ar_ima.insert("1Mushroom");
    
    /*ar_ima.insert("b");
    ar_ima.insert("a");
    ar_ima.insert("5");
    ar_ima.insert("6");
    ar_ima.insert("10");
    ar_ima.insert("4");
    ar_ima.insert("9");
    ar_ima.insert("15");*/
    //
	

    //ar_ima.Graficando_inor();
    //ar_ima.Graficando_preor();
    //ar_ima.Graficando_posor();
    ar_ima.Graficando_arbolbi();
    cout << " \n --- " << ar_ima.size ;
    
    
   /* //cout << "NULL\n";
    ar_ima.inorder();
    
    cout << "---\n";
    ar_ima.preorder();
   //// 
    cout << "---\n";
    ar_ima.postorder();*/
}

