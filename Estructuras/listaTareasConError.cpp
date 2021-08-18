#include <iostream>
#include <cstring>
using namespace std;

//Scope
void insertarTareaErrores(int posicion,string Rmes, string Rdia,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado);
void mostrarTareaErrores();
void eliminarTareaErrores(int Rid);
void modTareaErroresFecha(int Rid,string Rmes,string Rdia,string Rfecha);
void modificarTareaErroresHora(int Rid,string Rhora);
string getFechaTareaErrores(int Rid);
string getHoraTareaErrores(int Rid);

string getCarnetTareaErrores(int Rid);
string getNombreTareaErrores(int Rid);
string getDescripcionTareaErrores(int Rid);
string getMateriaTareaErrores(int Rid);
string getEstadoTareaErrores(int Rid);
string getMesTareaErores(int Rid);
string getDiaTareaErores(int Rid);
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
    auxiliar->identificador=posicion;
    auxiliar->mes=Rmes;
    auxiliar->dia=Rdia;
    auxiliar->carnet=Rcarnet;
    auxiliar->nombre=Rnombre;
    auxiliar->descripcion=Rdescripcion;
    auxiliar->materia=Rmateria;
    auxiliar->fecha=Rfecha;
    auxiliar->hora=Rhora;
    auxiliar->estado=Restado;
    if(primeroE==NULL){
        primeroE=auxiliar;
        primeroE->siguienteE=NULL;
        primeroE->anteriorE=NULL;
        ultimoE=primeroE;
    }else{
        ultimoE->siguienteE=auxiliar;
        auxiliar->siguienteE=NULL;
        auxiliar->anteriorE=ultimoE;
        ultimoE=auxiliar;
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

void eliminarTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    NodoE* atras=new NodoE();
    atras=NULL;
    if (primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                if(auxiliar==primeroE){
                    primeroE=primeroE->siguienteE;
                    primeroE->anteriorE=NULL;
                }else if(auxiliar==ultimoE){
                    atras->siguienteE=NULL;
                    ultimoE=atras;
                }else{
                    atras->siguienteE=auxiliar->siguienteE;
                    auxiliar->siguienteE->anteriorE=atras;
                }
            }
            atras=auxiliar;
            auxiliar=auxiliar->siguienteE;
        }
    }else{
        cout<<"La lista de tareas está vacía\n";
    }
}

void modTareaErroresFecha(int Rid,string Rmes,string Rdia,string Rfecha){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    bool encontrar=false;
    if(primeroE!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                auxiliar->mes=Rmes;
                auxiliar->dia=Rdia;
                auxiliar->fecha=Rfecha;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
}

void modificarTareaErroresHora(int Rid,string Rhora){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    bool encontrar=false;
    if(primeroE!=NULL && encontrar!=true){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                auxiliar->hora=Rhora;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
}

string getFechaTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->fecha;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}

string getHoraTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->hora;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}

string getCarnetTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->carnet;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}
string getNombreTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->nombre;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}
string getDescripcionTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->descripcion;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}
string getMateriaTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->materia;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}
string getEstadoTareaErrores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->estado;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}

string getDiaTareaErores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->dia;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}

string getMesTareaErores(int Rid){
    NodoE* auxiliar=new NodoE();
    auxiliar=primeroE;
    string dato="";
    if(primeroE!=NULL){
        while(auxiliar!=NULL){
            if(auxiliar->identificador==Rid){
                dato=auxiliar->mes;
            }
            auxiliar=auxiliar->siguienteE;
        }
    }
    return dato;
}