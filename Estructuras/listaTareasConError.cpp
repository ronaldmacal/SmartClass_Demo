#include <iostream>
#include <cstring>
using namespace std;

//Scope
void insertarTareaErrores(int posicion,string Rmes, string Rdia,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado);
//void LDmostrar();
//void LDbuscar();
void LDingresarLinealizado();
//void LDeliminar();

/*
Codigo de errores:
1. Error de fecha
2. Error de hora
*/

struct NodoE{
    int identificador;//secuencial
    string mes;
    string dia;
    string carnet;
    string nombre;
    string descripcion;
    string materia;
    string fecha;
    string hora;
    string estado;
    NodoE* siguienteE;
    NodoE* anteriorE;
}*primeroE,*ultimoE;

void insertarTareaErrores(int posicion,string Rmes, string Rdia, string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    bool encontrar=false;
    if (primeroE!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==posicion){
                encontrar=true;
                auxiliar->dia=Rdia;
                auxiliar->mes=Rmes;
                auxiliar->carnet=Rcarnet;
                auxiliar->nombre=Rnombre;
                auxiliar->descripcion=Rdescripcion;
                auxiliar->materia=Rmateria;
                auxiliar->fecha=Rfecha;
                auxiliar->hora=Rhora;
                auxiliar->estado=Restado;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
}

void mostrarTareaErrores(){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    cout<<"\nMostrar Tareas";
    if (primeroE!=NULL){
        while(auxiliar!=NULL){
            if(!(auxiliar->carnet.empty())){
                cout<<"\nPos: "<<auxiliar->identificador<<". Carnet: "<<auxiliar->carnet;
            }else{
                cout<<"\nPos: "<<auxiliar->identificador;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }else{
        cout<<"La lista de tareas se encuentra vacía\n";
    }
}