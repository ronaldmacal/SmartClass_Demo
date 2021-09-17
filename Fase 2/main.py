#Flask para el servidor de la API y librerías extras
from flask import Flask, jsonify, request
from Analizadores.Sintactico import parser

#Funcionalidades de API
app=Flask(__name__)
@app.route('/')
def index():
    return "Bienvenido a la Fase 2 del Proyecto"

#Importar archivos necesarios para el programa
from Estructuras.listadoble import ListaDoblementeEnlazada
from Estructuras.arbolavl import ArbolAVL

if __name__=="__main__":
    f=open("cargaMasiva.txt","r",encoding="utf-8")
    contenido=f.read()
    f.close()
    parser.parse(contenido)
    app.run(debug=True,port=3000)
