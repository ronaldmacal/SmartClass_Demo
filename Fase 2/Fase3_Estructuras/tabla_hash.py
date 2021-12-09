class tabla_hash:
    def __init__(self):
        self.tabla = [None]* 127

    #Funcion Hash:
    def funcion_hash(self,valor):
        key=0
        for i in range(0,len(valor)):
            key+= ord(valor[i])
        return key % 127

    def ingresar_nuevo(self,valor):
        hash=self.funcion_hash(valor)
        if self.tabla[hash] is None:
            self.tabla[hash]=valor

    def buscar_valor(self,valor):
        hash=self.funcion_hash(valor)
        if self.tabla[hash] is None:
            return None
        else:
            return self.tabla[hash]
            #return hex(id(self.tabla[hash]))

    def eliminar_valor(self,valor):
        hash=self.funcion_hash(valor)
        if self.tabla[hash] is None:
            print("No existe ese valor", valor)
        else:
            print("Elemento: ",valor," eliminado.")
            self.tabla[hash] is None
