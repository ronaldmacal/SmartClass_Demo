#include <iostream>
#include<cstring>
using namespace std;

//Scope
void LCinsertar();
void LCmostrar();
void LCbuscar();
void LCmodificar();
void LCeliminar();

struct NodoCircular{
    string carnet;
    string dpi;
    string nombre;
    string carrera;
    string correo;
    string contrasena;
    int creditos;
    int edad;
    NodoCircular* siguienteCircular;
    NodoCircular* anteriorCircular;
}*raiz,*tope;

void LCinsertar(string Rcarnet,string Rdpi,string Rnombre,string Rcarrera,string Rcorreo,string Rcontra,int Rcreditos,int Redad){
    NodoCircular* nuevo=new NodoCircular();
    nuevo->carnet=Rcarnet;
    nuevo->dpi=Rdpi;
    nuevo->nombre=Rnombre;
    nuevo->carrera=Rcarrera;
    nuevo->correo=Rcorreo;
    nuevo->contrasena=Rcontra;
    nuevo->creditos=Rcreditos;
    nuevo->edad=Redad;

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
    int contador=0;
    cout<<"\nLos valores de estudiantes actualmente en la lista son: \n";
    if(raiz!=NULL){
        do
        {
            /* code */
            contador++;
            cout<<"\n\nEstudiante: "<<contador;
            cout<<"\nCarnet: "<<actual->carnet;
            cout<<"\nDPI: "<<actual->dpi;
            cout<<"\nNombre: "<<actual->nombre;
            cout<<"\nCarrera: "<<actual->carrera;
            cout<<"\nContra: "<<actual->contrasena;
            cout<<"\nCreditos: "<<actual->creditos;
            cout<<"\nEdad: "<<actual->edad;
            cout<<"\nCorreo: "<<actual->correo;
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
    string nodoBuscado;
    cout<<"Ingrese el Carnet a buscar en la lista: \n";
    getline(cin,nodoBuscado);
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==nodoBuscado){
                cout<<"\nEstudiante encontrado\n";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"El estudiante no existe, verifique los datos y vuelva a intentarlo\n";
        }
    }else{
        cout<<"\nLa lista de estudiantes se encuentra vacía\n";
    }
}

void LCmodificar(){
    //Metodo por ahora no funcional debido a que se pueden pedir modificar varias atributos, no solo uno. Dependerá de las funcionalidades del programa.
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    bool encontrado=false;
    string nodoBuscado;
    cout<<"Ingrese el dato a modificar\n";
    cin>>nodoBuscado;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==nodoBuscado){
                cout<<"\nNodo encontrado\n";
                cout<<"Ingrese el nuevo dato para este Nodo: \n";
                getline(cin,actual->carnet);
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
    string nodoBuscado;
    cout<<" Ingrese el carnet del estudiante a eliminar: \n";
    getline(cin,nodoBuscado);
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==nodoBuscado){
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
            cout<<"Estudiante no encontrado vuelva a intentarlo.\n";
        }
    }else{
        cout<<"La lista de estudiantes está vacía\n";
    }
}
