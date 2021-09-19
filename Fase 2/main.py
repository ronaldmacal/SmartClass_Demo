#Importar archivos necesarios para el programa
from Estructuras.Estudiantes_avl import ArbolAVL
from Estructuras.Cursos_ArbolB import Arbol_B
from Estructuras.Grafo import Grafo

#Flask para el servidor de la API y librerías extras
from flask import Flask, jsonify, request
from Analizadores.Sintactico import parser,datos

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
    f = open('cargaMasiva.txt', "r", encoding="utf-8")
    mensaje = f.read()
    f.close()
    parser.parse(mensaje)
    lest = list()
    ltar = list()
    variable=datos[0]
    variable=variable.strip('"')

    for i in range(len(datos)):
        variable=datos[i].strip('"')
        if variable == "user":
            NE=Estudiante()
            NE.Carnet=datos[i + 1].strip('"')
            NE.DPI = datos[i + 2].strip('"')
            NE.Nombre = datos[i + 3].strip('"')
            NE.Carrera = datos[i + 4].strip('"')
            NE.Correo = datos[i + 5].strip('"')
            NE.Password = datos[i + 6].strip('"')
            NE.Creditos = datos[i + 7].strip('"')
            NE.Edad = datos[i + 8].strip('"')
            lest.append(NE)
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
    #Tipos de carga masiva: estudiante | recordatorio  | cursos
    return "Carga masiva de estudiantes y  mas datos"

@app.route('/reporte',methods=['GET'])
def reportes():
    #Tipos de reporte: AVL Estudiantes (Tipo=0), Matriz tareas (Tipo 1), Lista de tareas (Tipo 2)
    #Arbol B (Tipo 3), Arbol de cursos (Tipo 4)
    return "Reportes de la API"

@app.route('/estudiante',methods=['POST','UPDATE','DELETE','GET'])
def crudestudiantes():
    if request.method=='POST':
        #POST->Crear uno nuevo
        return "POST"
    elif request.method=='UPDATE':
        #UPDATE->Modificar
        return "UPDATE"
    elif request.method=='DELETE':
        #DELETE->eliminar un estudiante
        return "DELETE"
    elif request.method=='GET':
        #GET->mostrar estudiante
        return "GET"
    return "CRUD de estudiantes"

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

@app.route('/cursosEstudiante',methods=['POST'])
def cursosEstudiante():
    return "Cargar cursos para estudiantes"

@app.route('/cursosPensum',methods=['POST'])
def cursosPensum():
    return "Cargar cursos pensum"


if __name__=="__main__":
    print("Pruebas de las estructuras hechas")
    arbolB = Arbol_B(5)
    arbolB.insertar(6)
    arbolB.insertar(11)
    arbolB.insertar(5)
    arbolB.insertar(4)
    arbolB.insertar(8)
    arbolB.insertar(9)
    arbolB.insertar(12)
    arbolB.insertar(21)

    g = Grafo()
    g.generarGrafo(arbolB.raiz)
    #app.run(debug=True,port=3000)
