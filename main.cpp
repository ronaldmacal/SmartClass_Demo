//Compilar en linux: g++ -o "nombreDelEjecutable" programa.cpp
//Correr el archivo ""./nombreDelEjecutable
#include <iostream>
#include "listadoble.cpp"
#include "listacircular.cpp"
#include "cola.cpp"
#include <sstream> //Librería para strings
#include <fstream> //Librería para los archivos
#include <cstdlib> //Librería para convertir strings a enteros
using namespace std;

//Metodos in scope
void menuprincipal();
void ingresoManual();
void pruebas();
void cargaestudiantes();
void cargatareas();
void reportes();
void manualEstudiantes();
void manualTareas();

int main(){
    //menuprincipal();
    //ingresoManual();
    cargaestudiantes();
    //cargatareas();
    return 0;
}

/*
*********************************************************************************
***************************     Menú principal     ******************************
*********************************************************************************
*/
//Menú principal del programa en consola
void menuprincipal(){
    cout<<"************ MENÚ ***********\n";
    cout<<"*  1. Carga de estudiantes  *\n";
    cout<<"*  2. Carga de tareas       *\n";
    cout<<"*  3. Ingreso manual        *\n";
    cout<<"*  4. Reportes              *\n";
    cout<<"*  5. Salir                 *\n";
    cout<<"*****************************\n";
    int opcion;
    cin>>opcion;

    //Switch para analizar la opcion ingresada
    switch(opcion){
        case 1:
            cargaestudiantes();
            break;
        case 2:
            cargatareas();
            break;
        case 3:
            ingresoManual();
            break;
        case 4:
            reportes();
            break;
        case 5:
            cout<<"Gracias por utilizar SmartClass...\n";
            break;
        defalut:
            cout<<"Ingrese una opcion valida, vuelva a intentarlo\n";
            menuprincipal();
    }
}

/*
*********************************************************************************
******************** Carga Masiva de tareas y estudiantes  **********************
*********************************************************************************
*/
//Funcionalidad: Carga masiva de tareas desde archivos
void cargatareas(){
    //Ingreso de tareas directamente desde un archivo CSV + linealización
    string path;
    cout<<"\nIngrese el PATH o dirección del archivo a ingresar: ";
    getline(cin,path);
    ifstream archivo(path);
    string linea;
    char delimitador=',';
    getline(archivo,linea);

    while (getline(archivo,linea)){
        stringstream stream(linea);
        string Mes,Dia,Hora,Carnet,Nombre,Descripcion,Materia,Fecha,Estado;
        getline(stream,Mes,delimitador);
        getline(stream,Dia,delimitador);
        getline(stream,Hora,delimitador);
        getline(stream,Carnet,delimitador);
        getline(stream,Nombre,delimitador);
        getline(stream,Descripcion,delimitador);
        getline(stream,Materia,delimitador);
        getline(stream,Fecha,delimitador);
        getline(stream,Estado,delimitador);
        cout<<"\nMes: "<<Mes;
        cout<<"\nDia: "<<Dia;
        cout<<"\nHora: "<<Hora;
        cout<<"\nCarné: "<<Carnet;
        cout<<"\nNombre: "<<Nombre;
        cout<<"\nDescripción: "<<Descripcion;
        cout<<"\nMateria: "<<Materia;
        cout<<"\nFecha: "<<Fecha;
        cout<<"\nEstado: "<<Estado<<"\n";
        //El archivo ya está funcionando
    }
    archivo.close();
    cout<<"\n Carga masiva creada con éxito. Puede probar con los nuevos datos.\n\n\n";
    menuprincipal();
}

//Funcionalidad: Carga masiva de estudiantes desde archivos
void cargaestudiantes(){
    //Ingreso de estudiantes directamente desde un archivo CSV
    string path;
    cout<<"\nIngrese el PATH o dirección del archivo a ingresar: ";
    getline(cin,path);
    ifstream archivo(path);
    string linea;
    char delimitador=',';
    getline(archivo,linea);

    while (getline(archivo,linea)){
        stringstream stream(linea);
        string Carnet,DPI,Nombre,Carrera,Password,Creditos,Edad,Correo;
        getline(stream,Carnet,delimitador);
        getline(stream,DPI,delimitador);
        getline(stream,Nombre,delimitador);
        getline(stream,Carrera,delimitador);
        getline(stream,Password,delimitador);
        getline(stream,Creditos,delimitador);
        getline(stream,Edad,delimitador);
        getline(stream,Correo,delimitador);
        cout<<"\nCarné: "<<Carnet;
        cout<<"\nDPI: "<<DPI;
        cout<<"\nNombre: "<<Nombre;
        cout<<"\nCarrera: "<<Carrera;
        cout<<"\nPass: "<<Password;
        cout<<"\nCreditos: "<<Creditos;
        cout<<"\nEdad: "<<Edad;
        cout<<"\nCorreo: "<<Correo<<"\n";
        LCinsertar(Carnet,DPI,Nombre,Carrera,Correo,Password,atoi(Creditos.c_str()),atoi(Edad.c_str()));
    }
    archivo.close();
    cout<<"\n Carga masiva creada con éxito. Puede probar con los nuevos datos.\n\n\n";
    LCmostrar();
    menuprincipal();
}

/*
*********************************************************************************
*************************** Reportes del programa  ******************************
*********************************************************************************
*/
void reportes(){
    //Reportes del programa
}

/*
*********************************************************************************
******************************** Ingreso manual  ********************************
*********************************************************************************
*/
//Funcionalidad: ingreso manual de tareas y estudiantes-
void ingresoManual(){
    //Ingreso manual de datos a los archivos.
    int opcion=0;
    cout<<"\nIngreso manual...";
    cout<<"\nPor favor ingrese una de las siguientes opciones: ";
    cout<<"\n1. Estudiantes";
    cout<<"\n2. Tareas";
    cout<<"\n3. Volver\n";
    cin>>opcion;
    if(opcion==1){
        manualEstudiantes();
    }else if (opcion==2){
        manualTareas();
    }else if(opcion==3){
        menuprincipal();
    }else{
        cout<<"\nNo ingresó una opción válida. Vuelva a intentarlo";
        ingresoManual();
    }

}
void manualEstudiantes(){
    //Ingreso manual de estudiantes
    string Carnet,DPI,Nombre,Carrera,Password,Correo;
    int Creditos,Edad;
    cout<<"\nIngreso manual de estudiantes: ";
    cout<<"\nIngrese carnet: ";
    getline(cin,Carnet);
    cout<<"\nIngrese DPI: ";
    getline(cin,DPI);
    cout<<"\nIngrese Nombre: ";
    getline(cin,Nombre);
    cout<<"\nIngrese Carrera del estudiante: ";
    getline(cin,Carrera);
    cout<<"\nIngrese la contraseña: ";
    getline(cin,Password);
    cout<<"\nIngrese los Creditos del estudiante: ";
    cin>>Creditos;
    cout<<"\nIngrese Edad: ";
    cin>>Edad;
    cout<<"\nIngrese correo: ";
    getline(cin,Correo);
    try
    {
        /* code */
        // Rcarnet, Rdpi, Rnombre, Rcarrera, Rcorreo, Rcontra,int Rcreditos,int Redad
        LCinsertar(Carnet,DPI,Nombre,Carrera,Correo,Password,Creditos,Edad);
        cout<<"\nEstudiante ingresado con éxito\n";
    }
    catch(const std::exception& e)
    {
        cout<<"\n Error en el ingreso de datos del estudiante, vuelva a intentarlo";
    }
    //Preguntar por un nuevo ingreso
    int opcion=0;
    cout<<"\nDesea ingresar otro estudiante?";
    cout<<"\n1. Si";
    cout<<"\n2. No";
    cin>>opcion;
    if(opcion==1){
        manualEstudiantes();
    }else if(opcion==2){
        cout<<"\nVolviendo al menú principal...";
        menuprincipal();
    }else{
        cout<<"\nNo ingresó una opcion válida, se le devolverá al menú principal.";
        menuprincipal();
    }
}

void manualTareas(){
    //Ingreso manual de tareas
    string Mes,Dia,Hora,Carnet,Nombre,Descripcion,Materia,Fecha,Estado;
}
/*
*********************************************************************************
*************************    Linealización de Tareas    *************************
*********************************************************************************
*/


/*
*********************************************************************************
************** Validaciones del ingreso de datos para los errores  **************
*********************************************************************************
*/