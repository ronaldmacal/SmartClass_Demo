#include <iostream>
#include <cstring>
using namespace std;

//Scope
void LDgenerarLista();
//void LDmostrar();
//void LDbuscar();
void LDingresarLinealizado();
//void LDeliminar();

struct Nodo{
    int identificador;//secuencial
    string carnet;
    string nombre;
    string descripcion;
    string materia;
    string fecha;
    string hora;
    string estado;
    Nodo* siguiente;
    Nodo* anterior;
}*primero,*ultimo;

void LDgenerarLista(int Ltam){
    Nodo* nuevo=new Nodo();
    nuevo->identificador=Ltam;
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
}

void LDingresarLinealizado(int posicion,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    bool encontrar=false;
    if (primero!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==posicion){
                encontrar=true;
                auxiliar->carnet=Rcarnet;
                auxiliar->nombre=Rnombre;
                auxiliar->descripcion=Rdescripcion;
                auxiliar->materia=Rmateria;
                auxiliar->fecha=Rfecha;
                auxiliar->hora=Rhora;
                auxiliar->estado=Restado;
            }
            auxiliar=auxiliar->siguiente;
        }
    }
}

void LDmostrar(){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    cout<<"\nMostrar Tareas";
    if (primero!=NULL){
        while(auxiliar!=NULL){
            if(!(auxiliar->carnet.empty())){
                cout<<"\nPos: "<<auxiliar->identificador<<". Carnet: "<<auxiliar->carnet;
            }else{
                cout<<"\nPos: "<<auxiliar->identificador;
            }
            auxiliar=auxiliar->siguiente;
        }
    }else{
        cout<<"La lista de tareas se encuentra vacía\n";
    }
}

/*
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
*/