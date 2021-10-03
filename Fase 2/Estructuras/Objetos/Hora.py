from Estructuras.Estruc.Nodo import Nodo

class Hora(Nodo):
    def __init__(self, hour):
        Nodo.__init__(self)
        self.hora=hour

    def imprimir(self):
        return 'La hora es: '+str(self.hora)

    def getValue(self):
        return self.hora
