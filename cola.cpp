#include <iostream>
using namespace std;

//Scope
void insertarCola();
void mostrarCola();
void buscarCola();

struct Nodo{
    int dato;
    Nodo* siguiente;
}*primero,*ultimo; 

int main(){
    //Metodo principal
    insertarCola();
    insertarCola();
    insertarCola();
    insertarCola();
    insertarCola();
    cout<<endl<<"La cola es: "<<endl;
    mostrarCola();
    buscarCola();
    buscarCola();
}

void insertarCola(){
    Nodo* nuevo=new Nodo();
    cout<<"Ingrese el dato: ";
    cin>>nuevo->dato;

    if(primero==NULL){
        primero=nuevo;
        primero->siguiente=NULL;
        ultimo=primero;
    }else{
        ultimo->siguiente=nuevo;
        nuevo->siguiente=NULL;
        ultimo=nuevo;
    }
    cout<<endl<<"Nodo ingresado correctamente"<<endl<<endl;
}

void mostrarCola(){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    if(primero!=NULL){
        while(auxiliar!=NULL){
            cout<<endl<<""<<auxiliar->dato<<endl;
            auxiliar=auxiliar->siguiente;
        }

    }else{
        cout<<endl<<"La Cola se encuentra vacía.";
    }
}

void buscarCola(){
    int buscar;
    cout<<"Ingrese el valor a buscar: ";
    cin>>buscar;
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    bool encontrar=false;
    if(primero!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->dato==buscar){
                encontrar=true;
            }
            auxiliar=auxiliar->siguiente;
        }
    }
    if(encontrar){
        cout<<"Nodo encontrado con éxito\n";
    }else{
        cout<<"Nodo no encontrado, ingrese otro valor\n";
    }
}