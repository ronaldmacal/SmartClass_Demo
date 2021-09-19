from Semestres_LD import ListaSemestres
from Meses_LD import ListaMeses

class Nodo(object):
    def __init__(self,anio=None,siguiente=None,anterior=None,ListaSemestres=None,ListaMeses=None):
        self.anio=anio
        self.ListaMeses=ListaMeses()
        self.ListaSemestres=ListaSemestres()
        self.siguiente=siguiente
        self.anterior=anterior

class ListaAnios(object):
    def __init__(self):
        self.primero=None
        self.ultimo=None
        self.contador=0

    #Metodo de insertar en la cola
    def insertar(self,anio):
        nodo_nuevo=Nodo(anio)
        if self.primero is None:
            self.primero=nodo_nuevo
            self.ultimo=self.primero
        else:
            nodo_nuevo.anterior=self.ultimo
            self.ultimo.siguiente=nodo_nuevo
            self.ultimo=nodo_nuevo
        self.contador+=1

    #Mostrar años de la lista
    def mostrar(self):
        actual=self.primero
        while actual:
            anio=actual.anio
            print(anio)
            actual=actual.siguiente

    #Buscar un año
    def buscar(self,anio_buscar):
        actual = self.primero
        while actual:
            anio = actual.anio
            if(anio_buscar==anio):
                return True
            actual = actual.siguiente
        return False

    #Metodo para eliminar
    def eliminar(self,anio):
        actual=self.primero
        eliminado=False
        if actual is None:
            eliminado=False
        elif actual.anio==anio:
            self.primero=actual.siguiente
            self.primero.anterior=None
            eliminado=True
        elif self.ultimo.anio==anio:
            self.ultimo=self.ultimo.anterior
            self.ultimo.siguiente=None
            eliminado=True
        else:
            while actual:
                if actual.anio==anio:
                    actual.anterior.siguiente=actual.siguiente
                    actual.siguiente.anterior=actual.anterior
                    eliminado=True
                actual=actual.siguiente
        if eliminado:
            self.contador-=1