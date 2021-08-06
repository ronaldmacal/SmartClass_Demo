#include <iostream>
using namespace std;

//Scope
void LDinsertar();
void LDmostrar();
void LDbuscar();
void LDmodificar();
void LDeliminar();

struct Nodo{
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
}*primero,*ultimo;

void LDinsertar(){
    Nodo* nuevo=new Nodo();
    cout<<"Ingrese el dato que contendrá el nodo: ";
    cin>>nuevo->dato;

    if(primero==NULL){
        primero=nuevo;
        primero->siguiente=NULL;
        primero->anterior=NULL;
        ultimo=nuevo;
    }else{
        ultimo->siguiente=nuevo;
        nuevo->siguiente=NULL;
        nuevo->anterior=ultimo;
        ultimo=nuevo;
    }
    cout<<"Nodo ingresado\n";
}

void LDmostrar(){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    if (primero!=NULL){
        while(auxiliar!=NULL){
            cout<<"\n"<<auxiliar->dato<<"\n";
            auxiliar=auxiliar->siguiente;
        }
    }else{
        cout<<"La lista se encuentra vacía\n";
    }
}

void LDbuscar(){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    int valor;
    cout<<"Ingrese el valor a buscar\n";
    cin>>valor;
    bool encontrar=false;
    if (primero!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->dato==valor){
                encontrar=true;
            }
            auxiliar=auxiliar->siguiente;
        }
    }
    if (encontrar){
        cout<<"Nodo si existe\n";
    }else{
        cout<<"Nodo no existe\n";
    }
}

void LDmodificar(){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    int valor;
    cout<<"Ingrese el valor a modificar\n";
    cin>>valor;
    bool encontrar=false;
    if (primero!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->dato==valor){
                encontrar=true;
                cout<<"Ingrese el nuevo valor: \n";
                cin>>auxiliar->dato;
                cout<<"Modo modificado\n";
            }
            auxiliar=auxiliar->siguiente;
        }
    }
    if (encontrar){
        cout<<"Nodo modificado\n";
    }else{
        cout<<"Nodo no existe\n";
    }
}

void LDeliminar(){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    Nodo* atras=new Nodo();
    atras=NULL;
    int valor=0;
    cout<<"Ingrese el valor a eliminar\n";
    cin>>valor;
    bool encontrar=false;
    if (primero!=NULL){
        while(auxiliar!=NULL && encontrar!=true){
            if(auxiliar->dato==valor){
                encontrar=true;
                if(auxiliar==primero){
                    primero=primero->siguiente;
                    primero->anterior=NULL;
                }else if(auxiliar==ultimo){
                    atras->siguiente=NULL;
                    ultimo=atras;
                }else{
                    atras->siguiente=auxiliar->siguiente;
                    auxiliar->siguiente->anterior=atras;
                }
            }
            atras=auxiliar;
            auxiliar=auxiliar->siguiente;
        }
    }else{
        cout<<"La lista está vacía\n";
    }
    if (encontrar){
        cout<<"Nodo eliminado\n";
    }else{
        cout<<"Nodo no existe\n";
    }
}