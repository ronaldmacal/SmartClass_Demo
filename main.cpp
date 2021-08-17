//Compilar en linux: g++ -o "nombreDelEjecutable" programa.cpp
//Correr el archivo ""./nombreDelEjecutable
#include <iostream>
#include "./Estructuras/ListaTareas.cpp"
#include "./Estructuras/ListaEstudiantes.cpp"
#include "./Estructuras/cola.cpp"
#include "./Estructuras/listaTareasConError.cpp"
#include <sstream> //Librería para strings
#include <fstream> //Librería para los archivos
#include <cstdlib> //Librería para convertir strings a enteros
#include <bits/stdc++.h> //Librería para hacer split en la cadena fecha
#include <ctype.h>//Libreria para utilizar el isalpha
using namespace std;

//Metodos in scope
void menuprincipal();
void ingresoManual();
void pruebas();
void cargaestudiantes(string direccion);
void cargatareas(string direccion);
void reportes();
void manualEstudiantes();
void manualTareas();
void linealizartareas(string direccion);
void menudeErrores();

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
int contadorError=1;//Valor autoincremental que se guarda en los errores

//Metodos de ingreso manual de Estudiantes | Tareas
void Eingresar();
void Emodificar();
void Eeliminar();
void Tingresar();
void Tmodificar();
void Teliminar();

int main()
{
    menuprincipal();
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
    cout << "\n************ MENÚ ***********\n";
    cout << "*  1. Carga de estudiantes  *\n";
    cout << "*  2. Carga de tareas       *\n";
    cout << "*  3. Ingreso manual        *\n";
    cout << "*  4. Reportes              *\n";
    cout << "*  5. Menú errores          *\n";
    cout << "*  6. Salir                 *\n";
    cout << "*****************************\n";
    int opcion;
    cin >> opcion;

    //Switch para analizar la opcion ingresada
    
    string direccion;
    if(opcion==1){
        cin.ignore();
        cout << "\nIngrese el PATH o dirección del archivo a ingresar: ";
        getline(cin, direccion);
        cargaestudiantes(direccion);
    }else if(opcion==2){
        cin.ignore();
        cout << "\nIngrese el PATH o dirección del archivo a ingresar: ";
        getline(cin, direccion);
        cargatareas(direccion);
    }else if(opcion==3){
        ingresoManual();
    }else if(opcion==4){
        reportes();
    }else if(opcion==5){
        menudeErrores();
    }else if(opcion==6){
        cout << "Gracias por utilizar SmartClass...\n";
    }else{
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
void cargatareas(string direccion)
{
    //Ingreso de tareas directamente desde un archivo CSV + linealización
    try
    {
        /* code */
        //Primera lectura para capturar el tamaño del cubo (arreglo inicial)
        ifstream lectura(direccion);
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
        linealizartareas(direccion);
        menuprincipal();
    }
    catch (const std::exception &e)
    {
        cout << "\nError en la carga de tareas, vuelva a intentarlo.";
    }
}

//Funcionalidad: Carga masiva de estudiantes desde archivos
string descripcionErrDPI="Error en el DPI, no cumple con los requisitos. Debe tener solo números y 13 dígitos.";
string descripcionErrCarnet="Error en el Carnet del estudiante, no cumple con los requisitos. Debe tener solo números y 9 dígitos";
string descripcionErrCorreo="Error en el correo ingresado, no cumple con los requisitos y formato [usuario.@dominio.{com | org | es}]";
void cargaestudiantes(string direccion)
{
    //Ingreso de estudiantes directamente desde un archivo CSV
    ifstream archivo(direccion);
    string linea;
    char delimitador = ',';
    getline(archivo, linea);

    //Variables para buscar el error (DPI,Carnet,Correo)
    bool pruebaDpi=false;
    bool pruebaCarnet=false;
    bool pruebaCorreo=false;
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string Carnet, DPI, Nombre, Carrera, Password, Creditos, Edad, ICorreo,Correo;
        getline(stream, Carnet, delimitador);
        getline(stream, DPI, delimitador);
        getline(stream, Nombre, delimitador);
        getline(stream, Carrera, delimitador);
        getline(stream, Password, delimitador);
        getline(stream, Creditos, delimitador);
        getline(stream, Edad, delimitador);
        getline(stream, ICorreo, delimitador);
        //Verificar el error
        pruebaDpi=errorDpi(DPI);
        pruebaCarnet=errorCarnet(Carnet);

        //Eliminar el salto de linea del valor correo para poder trabajarlo en el metodo errorCorreo();
        for (int i = 0; i < ICorreo.size(); i++)
        {
            if(isalpha(ICorreo[i]) || ICorreo[i]=='@' || ICorreo[i]=='.'){
                Correo=Correo+ICorreo[i];
            }
        }
        pruebaCorreo=errorCorreo(Correo);
        //int Rid,string Rtipo,string RidTarEst,string Rdescripcion
        if(pruebaDpi==false){
            insertarError(contadorError,3,"Estudiante",Carnet,descripcionErrDPI);
            contadorError++;
        }
        if(pruebaCarnet==false){
            insertarError(contadorError,4,"Estudiante",Carnet,descripcionErrCarnet);
            contadorError++;
        }
        if(pruebaCorreo==false){
            insertarError(contadorError,5,"Estudiante",Carnet,descripcionErrCorreo);
            contadorError++;
        }
        LCinsertar(Carnet, DPI, Nombre, Carrera, Correo, Password, atoi(Creditos.c_str()), atoi(Edad.c_str()));
        cout << "\n Estudiante: "<<Carnet<<" guardado con éxito";
    }
    archivo.close();
    menuprincipal();
}

/*
*********************************************************************************
********************     Menu de corrección de errores     **********************
*********************************************************************************
*/
void menudeErrores(){
    cout<<"\nMenu de errores:"
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
    int opcion=0;
    cout<<"\nIngreso manual de estudiantes...";
    cout<<"\n1. Ingresar nuevo estudiante";
    cout<<"\n2. Modificar un estudiante existente";
    cout<<"\n3. Eliminar estudiante";
    cout<<"\n4. Volver\n";
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        Eingresar();
        break;
    case 2:
        Emodificar();
        break;
    case 3:
        Eeliminar();
        break;
    case 4:
        ingresoManual();
        break;
    default:
        cout<<"\nOpcion errónea, vuelva a ingresar un valor";
        manualEstudiantes();
        break;
    }
}

void Eingresar()
{
    //Ingresar valores
    cin.ignore();
    string Carnet, DPI, Nombre, Carrera, Password, Correo;
    int Creditos, Edad;
    cout << "\nIngreso manual de estudiantes ";
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
    cin.ignore();
    cout << "\nIngrese correo: ";
    getline(cin, Correo);
    try
    {
        /* code */
        // Rcarnet, Rdpi, Rnombre, Rcarrera, Rcorreo, Rcontra,int Rcreditos,int Redad
        bool pruebaDpi=errorDpi(DPI);
        bool pruebaCarnet=errorCarnet(Carnet);
        bool pruebaCorreo=errorCorreo(Correo);
        if(pruebaDpi==false){
            insertarError(contadorError,3,"Estudiante",Carnet,descripcionErrDPI);
            contadorError++;
        }
        if(pruebaCarnet==false){
            insertarError(contadorError,4,"Estudiante",Carnet,descripcionErrCarnet);
            contadorError++;
        }
        if(pruebaCorreo==false){
            insertarError(contadorError,5,"Estudiante",Carnet,descripcionErrCorreo);
            contadorError++;
        }
        LCinsertar(Carnet, DPI, Nombre, Carrera, Correo, Password, Creditos, Edad);
        cout << "\nEstudiante ingresado con éxito\n";
    }
    catch (const std::exception &e)
    {
        cout << "\n Error en el ingreso de datos del estudiante, vuelva a intentarlo";
    }
    manualEstudiantes();
}

void Emodificar()
{
    //Modificar estudiante
    cin.ignore();
    string dato;
    cout<<"\nListado de estudiantes:";
    LCmostrar();
    cout<<"\nIngrese el carnet del estudiante a modificar: ";
    getline(cin,dato);
    bool existe=false;
    existe=LCverificarCarnet(dato);
    if(existe==true)
    {
        bool wellCarnet,wellDpi,wellCorreo;
        string Carnet, DPI, Nombre, Carrera, Password, Correo, Creditos, Edad;
        cout<<"\nIngrese el nuevo carnet: ";
        getline(cin,Carnet);
        wellCarnet=LCverificarCarnet(Carnet);
        if(wellCarnet==false){
            wellCarnet=errorCarnet(Carnet);
            if(wellCarnet==false){
                cout<<"\nEl carnet no cumple con los requisitos. Vuelva a intentarlo.";
                manualEstudiantes();
            }
        }else{
            cout<<"\nEl carnet está repetido. Vuelva a intentarlo.";
            manualEstudiantes();
        }
        cout<<"\nIngrese el nuevo DPI: ";
        getline(cin,DPI);
        wellDpi=errorDpi(DPI);
        if(wellDpi==false){
            cout<<"\nError en el DPI, no cumple con los requisitos.";
            manualEstudiantes();
        }
        cout<<"\nIngrese el nuevo nombre: ";
        getline(cin,Nombre);
        cout<<"\nIngrese la nueva carrera: ";
        getline(cin,Carrera);
        cout<<"\nIngrese la nueva contraseña: ";
        getline(cin,Password);
        cout<<"\nIngrese el nuevo correo: ";
        getline(cin,Correo);
        wellCorreo=errorCorreo(Correo);
        if(wellCorreo==false){
            cout<<"\nCorreo nuevo no cumple con los requisitos. Vuelva a intentarlo";
        }
        cout<<"\nIngrese la cantidad de créditos: ";
        getline(cin,Creditos);
        cout<<"\nIngrese la nueva edad:";
        getline(cin,Edad);
        //string carnetOriginal,string NCarnet,string NDPI,string NNombre, string NCarrera,string NPassword,string NCorreo,string NCreditos,string NEdad
        LCmodificar(dato,Carnet,DPI,Nombre,Carrera,Password,Correo,Creditos,Edad);
        cout<<"\nDato modificado con éxito";
    }
    else
    {
        cout<<"\nEl estudiante ingresado no existe, vuelva a intentarlo.";
    }
    manualEstudiantes();
}

void Eeliminar()
{
    //Eliminar estudiante
    cin.ignore();
    string dato;
    LCmostrar();
    cout<<"\nIngrese el carnet del estudiante a eliminar: ";
    getline(cin,dato);
    LCeliminar(dato);
    manualEstudiantes();

}

void manualTareas()
{
    //Ingreso manual de tareas
    int opcion=0;
    cout<<"\nAdvertencia: Antes de ingresar datos manual de Tareas. Asegurese de haber realizado la carga masiva."
    cout<<"\nManejo manual de tareas...";
    cout<<"\n1. Ingresar nueva tarea";
    cout<<"\n2. Modificar un tarea existente";
    cout<<"\n3. Eliminar tarea";
    cout<<"\n4. Volver\n";
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        Tingresar();
        break;
    case 2:
        Tmodificar();
        break;
    case 3:
        Teliminar();
        break;
    case 4:
        ingresoManual();
        break;
    default:
        cout<<"\nOpcion errónea, vuelva a ingresar un valor";
        manualTareas();
        break;
    }
}

void Tingresar()
{
    //Ingresar tarea
    cin.ignore();
    cout<<"\nIngresar datos de tarea";
    string Mes, Dia, Hora, Carnet, Nombre, Descripcion, Materia, Fecha, Estado;
    cout<<"\nIngresar carnet de tarea: ";
    getline(cin,Carnet);
    bool paso=false;
    paso=LCverificarCarnet(Carnet);
    if(paso==true){
        cout<<"\nIngrese la hora de la tarea: ";
        getline(cin,Hora);
        cout<<"\nIngrese el mes de la tarea: ";
        getline(cin,Mes);
        cout<<"\nIngrese el día de la tarea: ";
        getline(cin,Dia);
        cout<<"\nIngrese la fecha de la tarea en formato YYYY/MM/DD";
        getline(cin,Fecha);
        cout<<"\nIngrese nombre de la tarea: ";
        getline(cin,Nombre);
        cout<<"\nIngrese la descripción de la tarea: ";
        getline(cin,Descripcion);
        cout<<"\nIngrese materia de la tarea: ";
        getline(cin,Materia);
        cout<<"\nIngrese estado de la materia: ";
        getline(cin,Estado);
        bool phora=errorHora(Hora);
        bool pfecha=errorFecha(Fecha);
        if(phora==true && pfecha==true){
            posicionLinealizado=(atoi(Dia.c_str())*maxdia*(maxhora-7))+(atoi(Mes.c_str())*(maxhora-7))+atoi(Hora.c_str());          
            LDingresarLinealizado(posicionLinealizado,Carnet,Nombre,Descripcion,Materia,Fecha,Hora,Estado);
        }else{

        }
    }else{
        cout<<"\nEl carnet no existe en el programa. Ingrese ese nuevo estudiante o verifique los datos.";
        manualTareas();
    }
}

void Tmodificar()
{
    //Modificar tarea
    cout<<"\nModificar tarea";
}

void Teliminar()
{
    //Eliminar tarea
    cout<<"\nEliminar tarea";
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
string descripcionErrCarnetE="Error, el Carnet no existe dentro del programa, revise los datos de ingreso. La tarea no se guardará en el programa.";
string descripcionErrFecha="Error en la fecha, no coincide en el formato YYYY/MM/DD o los valores están fuera de rango. Meses deben ser Julio-Noviembre y un máximo de 30 días.";
string descripcionErrHora="Error en la hora ingresada. De debe cumplir con el rango entero de 8am a 16pm";
void linealizartareas(string direccion)
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
    ifstream archivo(direccion);
    string linea;
    char delimitador=',';
    getline(archivo,linea);
    while (getline(archivo,linea)){
        stringstream stream(linea);
        string Mes,Dia,Hora,Carnet,Nombre,Descripcion,Materia,Fecha,IEstado,Estado;
        getline(stream,Mes,delimitador);
        getline(stream,Dia,delimitador);
        getline(stream,Hora,delimitador);
        getline(stream,Carnet,delimitador);
        getline(stream,Nombre,delimitador);
        getline(stream,Descripcion,delimitador);
        getline(stream,Materia,delimitador);
        getline(stream,Fecha,delimitador);
        getline(stream,IEstado,delimitador);
        for (int i = 0; i < IEstado.size(); i++)
        {
            if(isalpha(IEstado[i])){
                Estado=Estado+IEstado[i];
            }
        }
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
                    //Captura de errores en las tareas.
                    bool errCarnetExiste=LCverificarCarnet(cuboDatos[i][j][w].Tcarnet);
                    if(errCarnetExiste==true){
                        bool errfecha=errorFecha(cuboDatos[i][j][w].Tfecha);
                        bool errhora=errorHora(cuboDatos[i][j][w].Thora);

                        //Hay que hacer modificaciones de lista cambiable
                        /*if(errfecha==false)
                        {
                            insertarError(contadorError,,"Tarea",to_string(posicionLinealizado),descripcionErrFecha);
                            contadorError++;
                        }
                        if(errhora==false)
                        {
                            insertarError(contadorError,"Tarea",to_string(posicionLinealizado),descripcionErrHora);
                            contadorError++;
                        }*/
                        LDingresarLinealizado(posicionLinealizado,cuboDatos[i][j][w].Tcarnet,cuboDatos[i][j][w].Tnombre,cuboDatos[i][j][w].Tdescripcion,cuboDatos[i][j][w].Tmateria,cuboDatos[i][j][w].Tfecha,cuboDatos[i][j][w].Thora,cuboDatos[i][j][w].Testado);
                    }else{
                        cout<<"\n"<<descripcionErrCarnetE;
                    }
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
            cout<<"\nError: la hora ingresada no está en el rango (8am-16pm): ";
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
        if(tokens.size()!=2){
            return false;
        }
        string final=tokens[1];
        //Todo correcto hasta aqui
        vector <string> tokens2;
        stringstream check2(final);
        string inter;
        while (getline(check2,inter,'.'))
        {
            tokens2.push_back(inter);
        }
        string dom=tokens2[tokens2.size()-1];
        //Eliminar el salto de línea
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