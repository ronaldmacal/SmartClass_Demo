#include <iostream>
#include<cstring>
#include <sstream>
#include <fstream>
using namespace std;

//Scope
void LDgenerarLista();
void LDingresarLinealizado(int posicion,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado);
void LDmostrar();
bool buscarId(int id);
void LDModificarTarea(int posicion,string Rcarnet,string Rnombre,string Rdescripcion,string Rmateria,string Rfecha,string Rhora,string Restado);
void LDeliminar(int posicion);
void LDreporte3(int posicion);
void graficartareas();

//Reportes
string reporteTareasTXT();

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

string reporteTareasTXT(){
    string cadena="";
    Nodo* auxiliar=new Nodo();
    auxiliar=primero;
    if (primero!=NULL){
        while(auxiliar!=NULL){
            if(!(auxiliar->carnet.empty())){
                //Mostrar tareas
                cadena+="\t¿element type=\"task\"?\n";
                cadena+="\t\t¿item Carnet = \""+auxiliar->carnet+"\" $?\n";
                cadena+="\t\t¿item Nombre = \""+auxiliar->nombre+"\" $?\n";
                cadena+="\t\t¿item Descripcion = \""+auxiliar->descripcion+"\" $?\n";
                cadena+="\t\t¿item Materia = \""+auxiliar->materia+"\" $?\n";
                cadena+="\t\t¿item Fecha = \""+auxiliar->fecha+"\" $?\n";
                cadena+="\t\t¿item Hora = \""+auxiliar->hora+":00\" $?\n";
                cadena+="\t\t¿item Estado = \""+auxiliar->estado+"\" $?\n";
                cadena+="\t¿$element?\n";
            }
            auxiliar=auxiliar->siguiente;
        }
    }else{
        cout<<"La lista de tareas se encuentra vacía\n";
    }
    return cadena;
}

//Graficar las tareas
void graficartareas(){
    string acum = "digraph G{\n rankdir = TB; \nnode [shape=box]; \ncompound=true; \n";
    string nodos = "";
    string conexiones = "";
    Nodo* actual=new Nodo();
    actual=primero;
    int contador=0;
    int contadorimagenes=0;
    if(primero!=NULL){
        while (actual!=NULL)
        {
            /* code */
            nodos+= "\"" + to_string(actual->identificador) + "\"" + "[label=\"" + to_string(actual->identificador)+ "\"];\n";
            contadorimagenes++;
            if(!(actual->carnet.empty())){
                //Si hay datos en la posicion
                nodos+= "\"" + actual->carnet + "\"" + "[label=\"" + actual->carnet+"\n"+actual->fecha+ "\"];\n";
                conexiones+="\"" +  to_string(actual->identificador) + "\" -> \"" + actual->carnet+ "\"[dir=\"both\"];\n";
            }
            contador++;
            if(contador==20 || actual==ultimo){
                //Crear el archivo
                acum+=nodos+conexiones+"\n}\n";
                string nombrearchivo="./Tareas/TareasTo"+to_string(contadorimagenes)+".dot";
                string filename(nombrearchivo);
                fstream file_out;

                file_out.open(filename, std::ios_base::out);
                if(!file_out.is_open()){
                    cout << "Error al abrir el archivo: " <<filename << '\n';
                }else{
                    file_out << acum << endl;
                    cout << "La escritura fue un exito" << endl;
                }
                string cmd = "dot -Tpng ./Tareas/TareasTo"+to_string(contadorimagenes)+".dot -o "+to_string(contadorimagenes)+".png";
                system(cmd.c_str());
                contador=0;
                nodos="";
                conexiones="";
                file_out.close();
                acum= "digraph G{\n rankdir = TB; \nnode [shape=box]; \ncompound=true; \n";
                if(actual==ultimo){
                    actual=actual->siguiente;
                }
            }else{
                if(actual->siguiente!=NULL){
                    conexiones+="\"" +  to_string(actual->identificador) + "\" -> \"" + to_string(actual->siguiente->identificador) + "\"[dir=\"both\"];\n";
                }
                actual=actual->siguiente;
            } 
        }
    }else{
        cout<<"Lista vacia\n";
    }  
}

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
        cout<<"La lista de tareas esta vacia\n";
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
