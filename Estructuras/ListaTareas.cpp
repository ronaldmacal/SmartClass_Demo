#include <iostream>
#include <cstring>
using namespace std;

//Scope
void LDgenerarLista();
void LDingresarLinealizado(int posicion,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado);
void LDmostrar();
bool buscarId(int id);
void LDModificarTarea(int posicion,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado);
void LDeliminar(int posicion);
void LDreporte3(int posicion);

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
void LDModificarTarea(int posicion,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Restado){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    bool encontrar=false;
    if(primero!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==posicion){
                if(!(auxiliar->carnet.empty())){
                    auxiliar->carnet=Rcarnet;
                    auxiliar->nombre=Rnombre;
                    auxiliar->descripcion=Rdescripcion;
                    auxiliar->materia=Rmateria;
                    auxiliar->estado=Restado;
                }
            }
            auxiliar=auxiliar->siguiente;
        }
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
                cout<<"\nPos: "<<auxiliar->identificador<<". Carnet: "<<auxiliar->carnet<<" Nombre: "<<auxiliar->nombre;
            }else{
                cout<<"\nPos: "<<auxiliar->identificador;
            }
            auxiliar=auxiliar->siguiente;
        }
    }else{
        cout<<"La lista de tareas se encuentra vacía\n";
    }
}

bool buscarId(int id){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    bool encontrar=false;
    if(primero!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==id){
                if(!(auxiliar->carnet.empty())){
                    return true;
                }
            }
            auxiliar=auxiliar->siguiente;
        }
    }
    return false;
}

void LDeliminar(int posicion){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    Nodo* atras=new Nodo();
    atras=NULL;
    if (primero!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==posicion){
                auxiliar->carnet="";
                auxiliar->nombre="";
                auxiliar->descripcion="";
                auxiliar->materia="";
                auxiliar->fecha="";
                auxiliar->hora="";
                auxiliar->estado="";
                cout<<"\nTarea eliminada";
            }
            atras=auxiliar;
            auxiliar=auxiliar->siguiente;
        }
    }else{
        cout<<"La lista de tareas está vacía\n";
    }
}

void LDreporte3(int posicion){
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    bool encontrar=false;
    if(primero!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==posicion){
                if(!(auxiliar->carnet.empty())){
                    cout<<"\nReporte 3:";
                    cout<<"\nCarnet: "<<auxiliar->carnet;
                    cout<<"\nNombre: "<<auxiliar->nombre;
                    cout<<"\nDescripcion: "<<auxiliar->descripcion;
                    cout<<"\nMateria: "<<auxiliar->materia;
                    cout<<"\nFecha: "<<auxiliar->fecha;
                    cout<<"\nHora: "<<auxiliar->hora;
                    cout<<"\nEstado: "<<auxiliar->estado;
                    encontrar=true;
                }
            }
            auxiliar=auxiliar->siguiente;
        }
    }
    if(encontrar==false){
        cout<<"\nNo existe la tarea dentro de la lista linealizada. Vuelva a intentarlo";
    }
}
