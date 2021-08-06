#include <iostream>
using namespace std;

//Scope
void LCinsertar();
void LCmostrar();
void LCbuscar();
void LCmodificar();
void LCeliminar();

struct NodoCircular{
    int info;
    NodoCircular* siguienteCircular;
    NodoCircular* anteriorCircular;
}*raiz,*tope;

void LCinsertar(){
    NodoCircular* nuevo=new NodoCircular();
    cout<<"Ingrese el dato que contendrá el nuevo Nodo\n";
    cin>>nuevo->info;

    if(raiz==NULL){
        raiz=nuevo;
        tope=nuevo;
        raiz->siguienteCircular=raiz;
        raiz->anteriorCircular=tope;
    }else{
        tope->siguienteCircular=nuevo;
        nuevo->anteriorCircular=tope;
        nuevo->siguienteCircular=raiz;
        tope=nuevo;
        raiz->anteriorCircular=tope;
    }
    cout<<"Nodo insertado\n";
}

void LCmostrar(){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    if(raiz!=NULL){
        do
        {
            /* code */
            cout<<"\n"<<actual->info;
            actual=actual->siguienteCircular;
        } while (actual!=raiz);
        cout<<"\n\n";
    }else{
        cout<<"Lista vacía\n";
    }
}

void LCbuscar(){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    bool encontrado=false;
    int nodoBuscado=0;
    cout<<"Ingrese el dato a buscar\n";
    cin>>nodoBuscado;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->info==nodoBuscado){
                cout<<"\nNodo encontrado\n";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Nodo no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacía\n";
    }
}

void LCmodificar(){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    bool encontrado=false;
    int nodoBuscado=0;
    cout<<"Ingrese el dato a modificar\n";
    cin>>nodoBuscado;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->info==nodoBuscado){
                cout<<"\nNodo encontrado\n";
                cout<<"Ingrese el nuevo dato para este Nodo: \n";
                cin>>actual->info;
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Nodo no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacía\n";
    }
}

void LCeliminar(){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    NodoCircular* anterior=new NodoCircular();
    anterior=NULL;
    bool encontrado=false;
    int nodoBuscado=0;
    cout<<" Ingrese el dato a eliminar: \n";
    cin>>nodoBuscado;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->info==nodoBuscado){
                if(actual==raiz){
                    raiz=raiz->siguienteCircular;
                    raiz->anteriorCircular=tope;
                    tope->siguienteCircular=raiz;
                }else if(actual==tope){
                    tope=anterior;
                    tope->siguienteCircular=raiz;
                    raiz->anteriorCircular=tope;
                }else{
                    anterior->siguienteCircular=actual->siguienteCircular;
                    actual->siguienteCircular->anteriorCircular=anterior;
                }
                cout<<"Nodo eliminado\n";
                encontrado=true;
            }
            anterior=actual;
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);

        if(!encontrado){
            cout<<"Nodo no encontrado\n";
        }
    }else{
        cout<<"La lista está vacía\n";
    }
}
