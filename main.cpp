//Compilar en linux: g++ -o "nombreDelEjecutable" programa.cpp
//Correr el archivo ""./nombreDelEjecutable
#include <iostream>
//#include "listadoble.cpp"
//#include "listacircular.cpp"
//#include "cola.cpp"

using namespace std;
//Metodos in scope
void menuprincipal();
void ingresoManual();
void pruebas();

int main(){
    //menuprincipal();
    pruebas();
    return 0;
}

//Menú principal del programa en consola
void menuprincipal(){
    cout<<"********** Menu **********\n";
    cout<<"*  1. Carga de usuarios  *\n";
    cout<<"*  2. Carga de tareas    *\n";
    cout<<"*  3. Ingreso manual     *\n";
    cout<<"*  4. Reportes           *\n";
    cout<<"*  5. Salir              *\n";
    cout<<"**************************\n";
    int opcion;
    cin>>opcion;

    //Switch para analizar la opcion ingresada
    switch(opcion){
        case 1:
            cout<<"Caso 1, Carga de usuarios\n";
            break;
        case 2:
            cout<<"Caso 2, Carga de tareas\n";
            break;
        case 3:
            ingresoManual();
            break;
        case 4:
            cout<<"Caso 4, Reportes\n";
            break;
        case 5:
            cout<<"Gracias por utilizar SmartClass...\n";
            break;
        defalut:
            cout<<"Ingrese una opcion valida, vuelva a intentarlo\n";
            menuprincipal();
    }
}

//Funcionalidad: ingreso manual de tareas y estudiantes-
void ingresoManual(){
    //Ingreso manual de datos a los archivos.
}

//Esta parte esta reservada para pruebas con las EDD
void pruebas(){
    //Pruebas EDD
    cout<<"Pruebas EDD\n";
}
