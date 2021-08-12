#include <iostream>
using namespace std;

//Scope
void Colainsertar();
void Colamostrar();
void Colabuscar();
void Colaeliminar();

struct NodoC{
    int data;
    NodoC* siguienteC;
}*primeroC,*ultimoC; 

void Colainsertar(){
    NodoC* nuevo=new NodoC();
    cout<<"Ingrese el dato: ";
    cin>>nuevo->data;

    if(primeroC==NULL){
        primeroC=nuevo;
        primeroC->siguienteC=NULL;
        ultimoC=primeroC;
    }else{
        ultimoC->siguienteC=nuevo;
        nuevo->siguienteC=NULL;
        ultimoC=nuevo;
    }
    cout<<endl<<"Nodo ingresado correctamente"<<endl<<endl;
}

void Colamostrar(){
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    if(primeroC!=NULL){
        while(auxiliar!=NULL){
            cout<<endl<<""<<auxiliar->data<<endl;
            auxiliar=auxiliar->siguienteC;
        }

    }else{
        cout<<endl<<"La Cola se encuentra vacía.";
    }
}

void Colabuscar(){
    int buscar;
    cout<<"Ingrese el valor a buscar: ";
    cin>>buscar;
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    bool encontrar=false;
    if(primeroC!=NULL){
        while(auxiliar!=NULL && encontrar!=true){
            if(auxiliar->data==buscar){
                encontrar=true;
            }
            auxiliar=auxiliar->siguienteC;
        }
    }else{
        cout<<"La cola actual no tiene elementos\n";
    }
    if(encontrar){
        cout<<"Nodo encontrado con éxito\n";
    }else{
        cout<<"Nodo no encontrado, ingrese otro valor\n";
    }
}

void Colaeliminar(){
    int buscar;
    bool encontrar=false;
    cout<<"Ingrese el valor a eliminar: ";
    cin>>buscar;
    NodoC* anterior=new NodoC();
    anterior=NULL;
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    if(primeroC!=NULL){
        while(auxiliar!=NULL && encontrar!=true){
            if(auxiliar->data==buscar){
                //Nodo encontrado
                encontrar=true;
                if(auxiliar==primeroC){
                    primeroC=primeroC->siguienteC;
                }else if(auxiliar==ultimoC){
                    anterior->siguienteC=NULL;
                    ultimoC=anterior;
                }else{
                    anterior->siguienteC=auxiliar->siguienteC;
                }
            }
            anterior=auxiliar;
            auxiliar=auxiliar->siguienteC;
        }
    }else{
        cout<<"La cola actual no tiene elementos\n";
    }
    if(encontrar){
        cout<<"El nodo fue eliminado con éxito\n";
    }else{
        cout<<"Nodo no encontrado, no fue eliminado\n";
    }
}