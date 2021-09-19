class Nodo(object):
    def __init__(self,carnet=None,siguiente=None,anterior=None):
        self.carnet=carnet
        self.siguiente=siguiente
        self.anterior=anterior

class ListaTareas(object):
    def __init__(self):
        self.primero=None
        self.ultimo=None
        self.contador=0

    #Metodo de insertar en la cola
    def insertar(self,carnet):
        nodo_nuevo=Nodo(carnet)

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
            carnet=actual.carnet
            print(carnet)
            actual=actual.siguiente

    #Buscar un dato
    def buscar(self,carnet_buscar):
        actual = self.primero
        while actual:
            carnet = actual.carnet
            if(carnet_buscar==carnet):
                return True
            actual = actual.siguiente
        return False

    #Metodo para eliminar
    def eliminar(self,carnet):
        actual=self.primero
        eliminado=False
        if actual is None:
            eliminado=False
        elif actual.carnet==carnet:
            self.primero=actual.siguiente
            self.primero.anterior=None
            eliminado=True
        elif self.ultimo.carnet==carnet:
            self.ultimo=self.ultimo.anterior
            self.ultimo.siguiente=None
            eliminado=True
        else:
            while actual:
                if actual.carnet==carnet:
                    actual.anterior.siguiente=actual.siguiente
                    actual.siguiente.anterior=actual.anterior
                    eliminado=True
                actual=actual.siguiente
        if eliminado:
            self.contador-=1

