#Importar archivos necesarios para el programa
from Estructuras.Estudiantes_avl import ArbolAVL,data_estudiante
from Estructuras.Cursos_ArbolB import Arbol_B
from Estructuras.Grafo import Grafo

#Flask para el servidor de la API y librerías extras
from flask import Flask, jsonify, request
from Analizadores.Sintactico import parser,datos

# Estructuras a utilizar
EstudiantesArbolAVL = ArbolAVL()
raiz_avl=None
PensumCursosGeneral = Arbol_B(5)

#Funcionalidades de API
app=Flask(__name__)
@app.route('/')
def index():
    return "Bienvenido a la Fase 2 del Proyecto"

#Clases usasdas para la captura de carga masiva de Estudiantes y Tareas (Recordatorios)
class Estudiante:
    Carnet=''
    DPI=''
    Nombre=''
    Carrera=''
    Correo=''
    Password=''
    Creditos=''
    Edad=''
class Tarea():
    Carnet = ''
    Nombre = ''
    Descripcion = ''
    Materia = ''
    Fecha = ''
    Hora = ''
    Estado =''

@app.route('/carga',methods=['POST'])
def cargamasiva():
    global raiz_avl
    carga=request.get_json()
    tipo=carga['tipo']
    direccion=carga['path']
    f = open(direccion, "r", encoding="utf-8")
    mensaje = f.read()
    f.close()
    parser.parse(mensaje)
    variable = datos[0]
    variable = variable.strip('"')
    lest = list()
    ltar = list()
    if tipo=='estudiante':
        for i in range(len(datos)):
            variable = datos[i].strip('"')
            if variable == "user":
                NE = Estudiante()
                NE.Carnet = datos[i + 1].strip('"')
                NE.DPI = datos[i + 2].strip('"')
                NE.Nombre = datos[i + 3].strip('"')
                NE.Carrera = datos[i + 4].strip('"')
                NE.Correo = datos[i + 5].strip('"')
                NE.Password = datos[i + 6].strip('"')
                NE.Creditos = datos[i + 7].strip('"')
                NE.Edad = datos[i + 8].strip('"')
                lest.append(NE)
        for a in range(len(lest)):
            raiz_avl=EstudiantesArbolAVL.insertar(raiz_avl, lest[a].Carnet, lest[a].DPI, lest[a].Nombre, lest[a].Carrera, lest[a].Correo, lest[a].Password, lest[a].Creditos, lest[a].Edad)
        return "Carga de estudiantes realizado con éxito"
    elif tipo=='recordatorio':
        for i in range(len(datos)):
            variable=datos[i].strip('"')
            if variable == "task":
                NT = Tarea()
                NT.Carnet=datos[i + 1].strip('"')
                NT.Nombre=datos[i + 2].strip('"')
                NT.Descripcion=datos[i + 3].strip('"')
                NT.Materia = datos[i + 4].strip('"')
                NT.Fecha = datos[i + 5].strip('"')
                NT.Hora = datos[i + 6].strip('"')
                NT.Estado = datos[i + 7].strip('"')
                ltar.append(NT)
            #Ya tengo los dos listados de estudiantes y tareas listos para la carga
    return "Carga de recordatorios realizada con éxito"

@app.route('/reporte',methods=['GET'])
def reportes():
    #Tipos de reporte: AVL Estudiantes (Tipo=0), Matriz tareas (Tipo 1), Lista de tareas (Tipo 2)
    #Arbol B (Tipo 3), Arbol de cursos (Tipo 4)
    return "Reportes de la API"

@app.route('/cursosEstudiante',methods=['POST'])
def cursosEstudiante():
    return "Cargar cursos para estudiantes"

@app.route('/recordatorios',methods=['POST','UPDATE','DELETE','GET'])
def crudrecordatorios():
    if request.method=='POST':
        #POST->Crear uno nuevo
        return "POST"
    elif request.method=='UPDATE':
        #UPDATE->Modificar
        return "UPDATE"
    elif request.method=='DELETE':
        #DELETE->eliminar un recordatorio
        return "DELETE"
    elif request.method=='GET':
        #GET->mostrar recordatorio
        return "GET"
    return "CRUD de recordatorios"

@app.route('/estudiante',methods=['POST','UPDATE','DELETE','GET'])
def crudestudiantes():
    global raiz_avl
    archivo = request.get_json()
    if request.method=='POST':
        raiz_avl = EstudiantesArbolAVL.insertar(raiz_avl, archivo['carnet'], archivo['DPI'], archivo['nombre'], archivo['carrera'],
                                               archivo['correo'], archivo['password'], archivo['creditos'], archivo['edad'])
        return "Estudiante creado con éxito"
    elif request.method=='UPDATE':
        raiz_avl=EstudiantesArbolAVL.modificar(raiz_avl, archivo['carnet'], archivo['DPI'], archivo['nombre'], archivo['carrera'],
                                               archivo['correo'], archivo['password'], archivo['creditos'], archivo['edad'])
        return "Estudiante actualizado con éxito, el carnet no puede modificarse"
    elif request.method=='DELETE':
        carnet=archivo['carnet']
        raiz_avl=EstudiantesArbolAVL.eliminar(raiz_avl,carnet)
        return "Estudiante: "+carnet+" eliminado con éxito"
    elif request.method=='GET':
        carnet = archivo['carnet']
        EstudiantesArbolAVL.buscarCarnet(raiz_avl, carnet)
        jsonparaenviar=""
        if len(data_estudiante)!=0:
            jsonparaenviar=jsonify(carnet=data_estudiante[0], DPI=data_estudiante[1], nombre=data_estudiante[2], carrera=data_estudiante[3], correo=data_estudiante[4], password=data_estudiante[5], creditos=data_estudiante[6], edad=data_estudiante[7])
            data_estudiante.clear()
        else:
            jsonparaenviar="No existe el estudiante: "+carnet
        EstudiantesArbolAVL.printHelper(raiz_avl, "", True)
        return jsonparaenviar
    return "Error, ninguna opcion enviada con éxito"

@app.route('/cursosPensum',methods=['POST'])
def cursosPensum():
    detallespensum=request.get_json()
    cursos=detallespensum['Cursos']
    for x in range(0,len(cursos)):
        linea=cursos[x]
        codigoc=linea["Codigo"]
        nombre=linea['Nombre']
        creditos=linea['Creditos']
        prereq=linea['Prerequisitos']
        obligatorio=linea['Obligatorio']
        PensumCursosGeneral.insertar(codigoc)
    return "Cargar cursos pensum hecha con exito"

if __name__=="__main__":
    app.run(debug=True, port=3000)
