from Estructuras.Cursos_ArbolB import Arbol_B

class Nodo(object):
    def __init__(self, semestre=None, siguiente=None, anterior=None):
        self.semestre=semestre
        self.ArbolCursos=Arbol_B(5)
        self.siguiente=siguiente
        self.anterior=anterior

class ListaSemestres(object):
    def __init__(self):
        self.primero=None
        self.ultimo=None
        self.contador=0

    #Metodo de insertar en la cola
    def insertar(self,semestre):
        nodo_nuevo=Nodo(semestre)

        if self.primero is None:
            self.primero=nodo_nuevo
            self.ultimo=self.primero
        else:
            nodo_nuevo.anterior=self.ultimo
            self.ultimo.siguiente=nodo_nuevo
            self.ultimo=nodo_nuevo
        self.contador+=1

    #Mostrar datos de la lista
    def mostrar(self):
        actual=self.primero
        while actual:
            semestre=actual.semestre
            print(semestre)
            actual=actual.siguiente

    #Buscar un dato
    def buscar(self,semestre_buscar):
        actual = self.primero
        while actual:
            semestre = actual.semestre
            if(semestre_buscar==semestre):
                return True
            actual = actual.siguiente
        return False

    #Metodo para eliminar
    def eliminar(self,semestre):
        actual=self.primero
        eliminado=False
        if actual is None:
            eliminado=False
        elif actual.semestre==semestre:
            self.primero=actual.siguiente
            self.primero.anterior=None
            eliminado=True
        elif self.ultimo.semestre==semestre:
            self.ultimo=self.ultimo.anterior
            self.ultimo.siguiente=None
            eliminado=True
        else:
            while actual:
                if actual.semestre==semestre:
                    actual.anterior.siguiente=actual.siguiente
                    actual.siguiente.anterior=actual.anterior
                    eliminado=True
                actual=actual.siguiente
        if eliminado:
            self.contador-=1