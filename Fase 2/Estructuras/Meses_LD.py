class Nodo(object):
    def __init__(self,mes=None,siguiente=None,anterior=None):
        self.mes=mes
        #Aqui va la matriz
        self.siguiente=siguiente
        self.anterior=anterior

class ListaMeses(object):
    def __init__(self):
        self.primero=None
        self.ultimo=None
        self.contador=0

    #Metodo de insertar en la cola
    def insertar(self,mes):
        nodo_nuevo=Nodo(mes)

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
            mes=actual.mes
            print(mes)
            actual=actual.siguiente

    #Buscar un dato
    def buscar(self,mes_buscar):
        actual = self.primero
        while actual:
            mes = actual.mes
            if(mes_buscar==mes):
                return True
            actual = actual.siguiente
        return False

    #Metodo para eliminar
    def eliminar(self,mes):
        actual=self.primero
        eliminado=False
        if actual is None:
            eliminado=False
        elif actual.mes==mes:
            self.primero=actual.siguiente
            self.primero.anterior=None
            eliminado=True
        elif self.ultimo.mes==mes:
            self.ultimo=self.ultimo.anterior
            self.ultimo.siguiente=None
            eliminado=True
        else:
            while actual:
                if actual.mes==mes:
                    actual.anterior.siguiente=actual.siguiente
                    actual.siguiente.anterior=actual.anterior
                    eliminado=True
                actual=actual.siguiente
        if eliminado:
            self.contador-=1