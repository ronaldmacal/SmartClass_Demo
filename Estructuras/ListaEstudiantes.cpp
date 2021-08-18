#include <iostream>
#include<cstring>
using namespace std;

//Scope
void LCinsertar(string Rcarnet,string Rdpi,string Rnombre,string Rcarrera,string Rcorreo,string Rcontra,int Rcreditos,int Redad);
void LCmostrar();
void LCmodificar(string carnetOriginal,string NCarnet,string NDPI,string NNombre, string NCarrera,string NPassword,string NCorreo,string NCreditos,string NEdad);
void LCeliminar(string carnetEliminar);
bool LCverificarCarnet(string Rcarnet);

void LCCorregirDPI(string Rcarnet,string Rdpi);
void LCCorregirCarnet(string Rcarnet,string RcarnetNuevo);
void LCCorregirCorreo(string Rcarnet,string Rcorreo);

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

//Devuelve 1: si existe, 0: no existe en la lista
bool LCverificarCarnet(string Rcarnet){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==Rcarnet){
                return true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz);
        return false;
    }else{
        cout<<"\nLista vacía";
    }
    return false;
}

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

void LCmodificar(string carnetOriginal,string NCarnet,string NDPI,string NNombre, string NCarrera,string NPassword,string NCorreo,string NCreditos,string NEdad){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    bool encontrado=false;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==carnetOriginal){
                actual->carnet=NCarnet;
                actual->dpi=NDPI;
                actual->nombre=NNombre;
                actual->carrera=NCarrera;
                actual->contrasena=NPassword;
                actual->correo=NCorreo;
                actual->creditos=atoi(NCreditos.c_str());
                actual->edad=atoi(NEdad.c_str());
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Estudiante no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacía\n";
    }
}

void LCeliminar(string carnetEliminar){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    NodoCircular* anterior=new NodoCircular();
    anterior=NULL;
    bool encontrado=false;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==carnetEliminar){
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
                cout<<"Estudiante eliminado eliminado\n";
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
void LCCorregirDPI(string Rcarnet,string Rdpi){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    bool encontrado=false;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==Rcarnet){
                actual->dpi=Rdpi;
                cout<<"\nDPI actualizado con éxito.";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Estudiante no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacía\n";
    }
}

void LCCorregirCarnet(string Rcarnet,string RcarnetNuevo){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    bool encontrado=false;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==Rcarnet){
                actual->carnet=RcarnetNuevo;
                cout<<"\nCarnet actualizado con éxito.";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Estudiante no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacía\n";
    }
}

void LCCorregirCorreo(string Rcarnet,string Rcorreo){
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    bool encontrado=false;
    if(raiz!=NULL){
        do
        {
            /* code */
            if(actual->carnet==Rcarnet){
                actual->correo=Rcorreo;
                cout<<"\nCorreo actualizado con éxito.";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Estudiante no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacía\n";
    }
}

