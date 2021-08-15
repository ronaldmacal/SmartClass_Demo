//Compilar en linux: g++ -o "nombreDelEjecutable" programa.cpp
//Correr el archivo ""./nombreDelEjecutable
#include <iostream>
#include "listadoble.cpp"
#include "listacircular.cpp"
#include "cola.cpp"
#include <sstream> //Librería para strings
#include <fstream> //Librería para los archivos
#include <cstdlib> //Librería para convertir strings a enteros
#include <bits/stdc++.h> //Librería para hacer split en la cadena fecha
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
void linealizartareas(string path);

//Metodos para capturar errores
bool errorFecha(string fecha);
bool errorHora(string hora);
bool errorDpi(string dpi);
bool errorCarnet(string carnet);
bool errorCorreo(string correo);

//Variables utilizadas para guardar los valores dimensionales del cubo
int maxmes = 0;
int maxdia = 0;
int maxhora = 0;

int main()
{
    //menuprincipal();
    //ingresoManual();
    //cargaestudiantes();
    //cargatareas();
    //linealizartareas();
    string horas;
    cout<<"\nIngrese Correo: ";
    getline(cin,horas);
    bool prueba=errorCorreo(horas);
    if(prueba==true){
        cout<<"\nCorreo valido";
    }else{
        cout<<"\nCorreo no Valido";
    }

    return 0;
}

/*
*********************************************************************************
***************************     Menú principal     ******************************
*********************************************************************************
*/
//Menú principal del programa en consola
void menuprincipal()
{
    cout << "************ MENÚ ***********\n";
    cout << "*  1. Carga de estudiantes  *\n";
    cout << "*  2. Carga de tareas       *\n";
    cout << "*  3. Ingreso manual        *\n";
    cout << "*  4. Reportes              *\n";
    cout << "*  5. Salir                 *\n";
    cout << "*****************************\n";
    int opcion;
    cin >> opcion;

    //Switch para analizar la opcion ingresada
    switch (opcion)
    {
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
        cout << "Gracias por utilizar SmartClass...\n";
        break;
    defalut:
        cout << "Ingrese una opcion valida, vuelva a intentarlo\n";
        menuprincipal();
    }
}

/*
*********************************************************************************
******************** Carga Masiva de tareas y estudiantes  **********************
*********************************************************************************
*/
//Funcionalidad: Carga masiva de tareas desde archivos
void cargatareas()
{
    //Ingreso de tareas directamente desde un archivo CSV + linealización
    string path;
    cout << "\nIngrese el PATH o dirección del archivo a ingresar: ";
    getline(cin, path);

    try
    {
        /* code */
        //Primera lectura para capturar el tamaño del cubo (arreglo inicial)
        ifstream lectura(path);
        string lineacap;
        char delimitador = ',';
        getline(lectura, lineacap);
        while (getline(lectura, lineacap))
        {
        }
        {
            stringstream stream(lineacap);
            string m, d, h;
            int auxm, auxd, auxh;
            getline(stream, m, delimitador);
            getline(stream, d, delimitador);
            getline(stream, h, delimitador);
            auxm = atoi(m.c_str());
            auxd = atoi(d.c_str());
            auxh = atoi(h.c_str());
            if (maxmes <= auxm)
            {
                maxmes = auxm;
            }
            if (maxdia <= auxd)
            {
                maxdia = auxd;
            }
            if (maxhora <= auxh)
            {
                maxhora = auxh;
            }
        }
        lectura.close();
        //Metodo encargado de linealizar las tareas
        linealizartareas(path);
    }
    catch (const std::exception &e)
    {
        cout << "\nError en la carga de tareas, vuelva a intentarlo.";
    }
}

//Funcionalidad: Carga masiva de estudiantes desde archivos
void cargaestudiantes()
{
    //Ingreso de estudiantes directamente desde un archivo CSV
    string path;
    cout << "\nIngrese el PATH o dirección del archivo a ingresar: ";
    getline(cin, path);
    ifstream archivo(path);
    string linea;
    char delimitador = ',';
    getline(archivo, linea);

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string Carnet, DPI, Nombre, Carrera, Password, Creditos, Edad, Correo;
        getline(stream, Carnet, delimitador);
        getline(stream, DPI, delimitador);
        getline(stream, Nombre, delimitador);
        getline(stream, Carrera, delimitador);
        getline(stream, Password, delimitador);
        getline(stream, Creditos, delimitador);
        getline(stream, Edad, delimitador);
        getline(stream, Correo, delimitador);
        cout << "\nCarné: " << Carnet;
        cout << "\nDPI: " << DPI;
        cout << "\nNombre: " << Nombre;
        cout << "\nCarrera: " << Carrera;
        cout << "\nPass: " << Password;
        cout << "\nCreditos: " << Creditos;
        cout << "\nEdad: " << Edad;
        cout << "\nCorreo: " << Correo << "\n";
        LCinsertar(Carnet, DPI, Nombre, Carrera, Correo, Password, atoi(Creditos.c_str()), atoi(Edad.c_str()));
    }
    archivo.close();
    cout << "\n Carga masiva creada con éxito. Puede probar con los nuevos datos.\n\n\n";
    LCmostrar();
    //menuprincipal();
}

/*
*********************************************************************************
*************************** Reportes del programa  ******************************
*********************************************************************************
*/
void reportes()
{
    //Reportes del programa
}

/*
*********************************************************************************
******************************** Ingreso manual  ********************************
*********************************************************************************
*/
//Funcionalidad: ingreso manual de tareas y estudiantes-
void ingresoManual()
{
    //Ingreso manual de datos a los archivos.
    int opcion = 0;
    cout << "\nIngreso manual...";
    cout << "\nPor favor ingrese una de las siguientes opciones: ";
    cout << "\n1. Estudiantes";
    cout << "\n2. Tareas";
    cout << "\n3. Volver\n";
    cin >> opcion;
    if (opcion == 1)
    {
        manualEstudiantes();
    }
    else if (opcion == 2)
    {
        manualTareas();
    }
    else if (opcion == 3)
    {
        menuprincipal();
    }
    else
    {
        cout << "\nNo ingresó una opción válida. Vuelva a intentarlo";
        ingresoManual();
    }
}
void manualEstudiantes()
{
    //Ingreso manual de estudiantes
    string Carnet, DPI, Nombre, Carrera, Password, Correo;
    int Creditos, Edad;
    cout << "\nIngreso manual de estudiantes: ";
    cout << "\nIngrese carnet: ";
    getline(cin, Carnet);
    cout << "\nIngrese DPI: ";
    getline(cin, DPI);
    cout << "\nIngrese Nombre: ";
    getline(cin, Nombre);
    cout << "\nIngrese Carrera del estudiante: ";
    getline(cin, Carrera);
    cout << "\nIngrese la contraseña: ";
    getline(cin, Password);
    cout << "\nIngrese los Creditos del estudiante: ";
    cin >> Creditos;
    cout << "\nIngrese Edad: ";
    cin >> Edad;
    cout << "\nIngrese correo: ";
    getline(cin, Correo);
    try
    {
        /* code */
        // Rcarnet, Rdpi, Rnombre, Rcarrera, Rcorreo, Rcontra,int Rcreditos,int Redad
        LCinsertar(Carnet, DPI, Nombre, Carrera, Correo, Password, Creditos, Edad);
        cout << "\nEstudiante ingresado con éxito\n";
    }
    catch (const std::exception &e)
    {
        cout << "\n Error en el ingreso de datos del estudiante, vuelva a intentarlo";
    }
    //Preguntar por un nuevo ingreso
    int opcion = 0;
    cout << "\nDesea ingresar otro estudiante?";
    cout << "\n1. Si";
    cout << "\n2. No";
    cin >> opcion;
    if (opcion == 1)
    {
        manualEstudiantes();
    }
    else if (opcion == 2)
    {
        cout << "\nVolviendo al menú principal...";
        menuprincipal();
    }
    else
    {
        cout << "\nNo ingresó una opcion válida, se le devolverá al menú principal.";
        menuprincipal();
    }
}
void manualTareas()
{
    //Ingreso manual de tareas
    string Mes, Dia, Hora, Carnet, Nombre, Descripcion, Materia, Fecha, Estado;
}
/*
*********************************************************************************
*************************    Linealización de Tareas    *************************
*********************************************************************************
*/
class Tarea
{
public:
    int Tid;
    string Tcarnet;
    string Tnombre;
    string Tdescripcion;
    string Tmateria;
    string Tfecha;
    string Thora;
    string Testado;

    void guardarTarea(string Hora,string Carnet,string Nombre,string Descripcion,string Materia,string Fecha,string Estado); //
    void vacio(); //Metodo que llena los espacios vacios en -1
};
void Tarea::vacio(){
    Tid=-1;
}
void Tarea::guardarTarea(string Hora,string Carnet,string Nombre,string Descripcion,string Materia,string Fecha,string Estado)
{
    Tid=1;
    Tcarnet=Carnet;
    Thora=Hora;
    Tnombre=Nombre;
    Tdescripcion=Descripcion;
    Tmateria=Materia;
    Tfecha=Fecha;
    Testado=Estado;
}
void linealizartareas(string path)
{
    //Crear un arreglo con los datos del programa
    Tarea cuboDatos[maxdia][maxmes-6][maxhora-7];
    
    //Recorrer el arreglo para poner todos los datos como vacíos (-1)
    for (int i = 0; i < maxdia; i++)
    {
        /* code */
        for (int j = 0; j< (maxmes-6); j++)
        {
            /* code */
            for (int w = 0; w < (maxhora-7); w++)
            {
                /* code */
                cuboDatos[i][j][w].vacio();
            }
        }
    }
    
    //Hacer la lista del tamaño indicado (maxdia*(maxmes-6)*(maxhora-7))
    int tamalista=maxdia*(maxmes-6)*(maxhora-7);
    for (int i = 0; i < tamalista; i++)
    {
        /* code */
        LDgenerarLista(i);
    }
    cout<<"\nLista generada con éxito. Tamaño: "<<tamalista<<"\n";

    //Ingresar los datos al arreglo en su respectiva posicion
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
        //cuboDatos[dia-1][mes-7][hora-8]
        int RealDia=(atoi(Dia.c_str()))-1;
        int RealMes=(atoi(Mes.c_str()))-7;
        int RealHora=(atoi(Hora.c_str()))-8;
        cuboDatos[RealDia][RealMes][RealHora].guardarTarea(Hora,Carnet,Nombre,Descripcion,Materia,Fecha,Estado);
    }
    archivo.close();

    //Recorrer el arreglo cuboDatos e ir linealizando donde si se encuentren datos.
    int posicionLinealizado=0;
    for (int i = 0; i < maxdia; i++)
    {
        /* code */
        for (int j = 0; j< (maxmes-6); j++)
        {
            /* code */
            for (int w = 0; w < (maxhora-7); w++)
            {
                /* code */
                if(cuboDatos[i][j][w].Tid==1){
                    posicionLinealizado=(j*maxdia*(maxhora-7))+(i*(maxhora-7))+w;
                    LDingresarLinealizado(posicionLinealizado,cuboDatos[i][j][w].Tcarnet,cuboDatos[i][j][w].Tnombre,cuboDatos[i][j][w].Tdescripcion,cuboDatos[i][j][w].Tmateria,cuboDatos[i][j][w].Tfecha,cuboDatos[i][j][w].Thora,cuboDatos[i][j][w].Testado);
                }
            }
        }
    }
}

/*
*********************************************************************************
************** Validaciones del ingreso de datos para los errores  **************
*********************************************************************************
*/
//Metodo para verificar si existe en el listado el Carnet: LCverificarCarnet(string carnet);
//Verifica si la fecha es coherente
bool errorFecha(string fecha){
    vector <string> tokens;
    stringstream check1(fecha);
    string intermediate;
    while (getline(check1,intermediate,'/'))
    {
        /* code */
        tokens.push_back(intermediate);
    }
    try
    {
        string anio=tokens[0];
        string mes=tokens[1];
        string dia=tokens[2];

        //Ya tengo los datos verificar la validez
        if(!(anio.length()==4)){
            cout<<"\nError: Año no ingresado correctamente.";
            return false;
        }
        int mesE=atoi(mes.c_str());
        int diaE=atoi(dia.c_str());
        //Valida que el mes esté entre 7 y 11
        if(!(mesE>=7 && mesE<=11)){
            cout<<"\nError: Mes no está entre el rango Julio-Noviembre";
            return false;
        }

        //Valida que los días estén entre 1 y 30 días.
        if(!(diaE>=1 && diaE<=30)){
            cout<<"\nError: los días en la fecha no están en el rango de días (0-30)";
            return false;
        }else{
            return true;
        }

    }
    catch(const std::exception& e)
    {
        return false;
    }
    return false;
}

//Verifica si la hora ingresada es válida, entre 8am-16pm
bool errorHora(string hora){
    try
    {
        int horaR=atoi(hora.c_str());
        if(!(horaR>=8 && horaR<=16)){
            cout<<"\nError: la hora ingresada no está en el rango (8am-16pm)";
            return false;
        }else{
            return true;
        }
    }
    catch(const std::exception& e)
    {
        cout<<"\nError en la hora ingresada";
        return false;
    }
}

//Revisa si es digito
bool esNumero(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

//Verifica si el DPI es correcto
bool errorDpi(string dpi){
    if(dpi.length()==13){
        if(esNumero(dpi)){
            return true;
        }else{
            cout<<"\nError: El DPI contiene letras.";
        }
    }else{
        cout<<"\nError: El DPI no tiene 13 dígitos.";
        return false;
    }
    return false;
}

//Verifica si el carnet es correcto
bool errorCarnet(string carnet){
    if(carnet.length()==9){
        if(esNumero(carnet)){
            return true;
        }else{
            cout<<"\nError: El Carnet contiene letras.";
        }
    }else{
        cout<<"\nError: El Carnet no tiene 9 dígitos.";
        return false;
    }
    return false;
}

//Verifica si el correo es correcto
bool errorCorreo(string correo){
    vector <string> tokens;
    stringstream check1(correo);
    string intermediate;
    try
    {
        while (getline(check1,intermediate,'@'))
        {
            tokens.push_back(intermediate);
        }
        if(tokens.size()==1 || tokens.size()>2){
            return false;
        }
        string final=tokens[1];
        vector <string> tokens2;
        stringstream check2(final);
        string inter;
        while (getline(check2,inter,'.'))
        {
            tokens2.push_back(inter);
        }
        string dom=tokens2[tokens2.size()-1];
        if(dom=="com" || dom=="es" || dom=="org"){
            return true;
        }
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return false;
}