#include <iostream>
using namespace std;

//Scope
void insertarError(int Rid,int Rclase, string Rtipo,string RidTarEst,string Rdescripcion);
void Colamostrar();
void Colaeliminar(int Rid);
bool ColaVerificarId(int Rid);
int ColaDevClase(int Rid);
string ColaDevRidTarEst(int Rid);

struct NodoC{
    int id;
    int clase;
    string tipo;
    string idTarEst;
    string descripcion;
    NodoC* siguienteC;
}*primeroC,*ultimoC; 


void insertarError(int Rid, int Rclase,string Rtipo,string RidTarEst,string Rdescripcion) {
    //Crea el ticket de error
    NodoC* nuevo=new NodoC();
    nuevo->id=Rid;
    nuevo->tipo=Rtipo;
    nuevo->clase=Rclase;
    nuevo->idTarEst=RidTarEst;
    nuevo->descripcion=Rdescripcion;

    if(primeroC==NULL){
        primeroC=nuevo;
        primeroC->siguienteC=NULL;
        ultimoC=primeroC;
    }else{
        ultimoC->siguienteC=nuevo;
        nuevo->siguienteC=NULL;
        ultimoC=nuevo;
    }
}


void Colamostrar(){
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    cout<<"\nCOLA DE ERRORES:";
    if(primeroC!=NULL){
        while(auxiliar!=NULL){
            cout<<"\nError: #"<<auxiliar->id;
            cout<<"\nID: "<<auxiliar->idTarEst;
            cout<<"\nDescripción: "<<auxiliar->descripcion<<"\n";
            auxiliar=auxiliar->siguienteC;
        }

    }else{
        cout<<endl<<"La Cola de errores se encuentra vacía.";
    }
}

void Colaeliminar(int Rid){
    bool encontrar=false;
    NodoC* anterior=new NodoC();
    anterior=NULL;
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    if(primeroC!=NULL){
        while(auxiliar!=NULL && encontrar!=true){
            if(auxiliar->id==Rid){
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
        cout<<"La cola de errores actual no tiene elementos\n";
    }
    if(encontrar){
        cout<<"El error fue eliminado con éxito\n";
    }
}
bool ColaVerificarId(int Rid){
    bool encontrar=false;
    NodoC* anterior=new NodoC();
    anterior=NULL;
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    if(primeroC!=NULL){
        while(auxiliar!=NULL && encontrar!=true){
            if(auxiliar->id==Rid){
                //Nodo encontrado
                return true;
            }
            auxiliar=auxiliar->siguienteC;
        }
    }else{
        cout<<"La cola de errores actual no tiene elementos\n";
    }
    return false;
}

int ColaDevClase(int Rid){
    int valor=0;
    bool encontrar=false;
    NodoC* anterior=new NodoC();
    anterior=NULL;
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    if(primeroC!=NULL){
        while(auxiliar!=NULL && encontrar!=true){
            if(auxiliar->id==Rid){
                //Nodo encontrado
                valor=auxiliar->clase;
            }
            auxiliar=auxiliar->siguienteC;
        }
    }else{
        cout<<"La cola de errores actual no tiene elementos\n";
    }
    return valor;
}

string ColaDevRidTarEst(int Rid){
    string valor="";
    bool encontrar=false;
    NodoC* anterior=new NodoC();
    anterior=NULL;
    NodoC* auxiliar=new NodoC();
    auxiliar=primeroC;
    if(primeroC!=NULL){
        while(auxiliar!=NULL && encontrar!=true){
            if(auxiliar->id==Rid){
                //Nodo encontrado
                valor=auxiliar->idTarEst;
            }
            auxiliar=auxiliar->siguienteC;
        }
    }else{
        cout<<"La cola de errores actual no tiene elementos\n";
    }
    return valor;
}