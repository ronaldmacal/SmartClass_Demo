#include <iostream>
#include<cstring>
#include <sstream>
#include <fstream>
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
void graficarEstudiantes();

//Reportes
string reporteEstudiantesTXT();
void graficarEstudiantes();

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
//Metodos para el reporte 
string reporteEstudiantesTXT(){
    string cadena="";
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    if(raiz!=NULL){
        do
        {
            /* code */
            cadena+="\t¿element type=\"user\"?\n";
            cadena+="\t\t¿item Carnet = \""+actual->carnet+"\" $?\n";
            cadena+="\t\t¿item DPI = \""+actual->dpi+"\" $?\n";
            cadena+="\t\t¿item Nombre = \""+actual->nombre+"\" $?\n";
            cadena+="\t\t¿item Carrera = \""+actual->carrera+"\" $?\n";
            cadena+="\t\t¿item Password = \""+actual->contrasena+"\" $?\n";
            cadena+="\t\t¿item Creditos = \""+to_string(actual->creditos)+"\" $?\n";
            cadena+="\t\t¿item Edad = \""+to_string(actual->edad)+"\" $?\n";
            cadena+="\t¿$element?\n";
            actual=actual->siguienteCircular;
        } while (actual!=raiz);
    }else{
        cout<<"Lista vacia\n";
    }
    return cadena;
}

//Metodo para generar el .dot
void graficarEstudiantes(){
    string acum = "digraph G{\n rankdir = TB; \nnode [shape=box]; \ncompound=true; \n";
    string nodos = "";
    string conexiones = "";
    NodoCircular* actual=new NodoCircular();
    actual=raiz;
    if(raiz!=NULL){
        while (actual->siguienteCircular!=raiz)
        {
            /* code */
            nodos+= "\"" + actual->carnet + "\"" + "[label=\"" + actual->carnet+ "\n"+actual->nombre+ "\"];\n";
            conexiones+="\"" +  actual->carnet + "\" -> \"" + actual->siguienteCircular->carnet + "\"[dir=\"both\"];\n";
            actual=actual->siguienteCircular;
        }
    }else{
        cout<<"Lista vacia\n";
    }   
    nodos += "\"" + actual->carnet + "\"" + "[label=\"" + actual->carnet+ "\n"+actual->nombre+ "\"];\n";
    conexiones+="\"" +  actual->carnet + "\" -> \"" + actual->siguienteCircular->carnet + "\"[dir=\"both\"];\n";
    acum += nodos + conexiones + "\n}\n";
    
    //Crear el archivo
    string filename("estudiantes.dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if(!file_out.is_open()){
        cout << "Error al abrir el archivo: " <<filename << '\n';
    }else{
        file_out << acum << endl;
        cout << "La escritura fue un exito" << endl;
    }
    string cmd = "dot -Tpng estudiantes.dot -o estudiantes.png";
    system(cmd.c_str());  
}

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
        cout<<"\nLista vacia";
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
        cout<<"Lista vacia\n";
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
        cout<<"\nLa lista se encuentra vacia\n";
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
        cout<<"La lista de estudiantes esta vacia\n";
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
                cout<<"\nDPI actualizado con exito.";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Estudiante no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacia\n";
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
                cout<<"\nCarnet actualizado con exito.";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Estudiante no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacia\n";
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
                cout<<"\nCorreo actualizado con exito.";
                encontrado=true;
            }
            actual=actual->siguienteCircular;
        } while (actual!=raiz && encontrado!=true);
        if(!encontrado){
            cout<<"Estudiante no encontrado\n";
        }
    }else{
        cout<<"\nLa lista se encuentra vacia\n";
    }
}

