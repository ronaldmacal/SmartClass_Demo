class Nodo(object):
    def __init__(self,dato=None,siguiente=None,anterior=None):
        self.dato=dato
        self.siguiente=siguiente
        self.anterior=anterior

class ListaDoblementeEnlazada(object):
    def __init__(self):
        self.primero=None
        self.ultimo=None
        self.contador=0

    #Metodo de insertar en la cola
    def insertar(self,dato):
        nodo_nuevo=Nodo(dato)

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
            dato=actual.dato
            print(dato)
            actual=actual.siguiente

    #Buscar un dato
    def buscar(self,dato_buscar):
        actual = self.primero
        while actual:
            dato = actual.dato
            if(dato_buscar==dato):
                return True
            actual = actual.siguiente
        return False

    #Metodo para eliminar
    def eliminar(self,dato):
        actual=self.primero
        eliminado=False
        if actual is None:
            eliminado=False
        elif actual.dato==dato:
            self.primero=actual.siguiente
            self.primero.anterior=None
            eliminado=True
        elif self.ultimo.dato==dato:
            self.ultimo=self.ultimo.anterior
            self.ultimo.siguiente=None
            eliminado=True
        else:
            while actual:
                if actual.dato==dato:
                    actual.anterior.siguiente=actual.siguiente
                    actual.siguiente.anterior=actual.anterior
                    eliminado=True
                actual=actual.siguiente
        if eliminado:
            self.contador-=1

