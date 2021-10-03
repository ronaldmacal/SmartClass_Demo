import sys
from Estructuras.Anios_LD import ListaAnios
data_estudiante=[]
class Nodo(object):
    def __init__(self, carnet,dpi,nombre,carrera,correo,password,creditos,edad):
        self.carnet = carnet
        self.dpi=dpi
        self.nombre=nombre
        self.carrera=carrera
        self.correo=correo
        self.password=password
        self.creditos=creditos
        self.edad=edad
        self.ListaAnios=ListaAnios()
        self.izquierda = None
        self.derecha = None
        self.altura = 1

class ArbolAVL(object):
    #Metodo para obtener la altura de la raiz
    def obtenerAltura(self, raiz):
        if not raiz:
            return 0
        return raiz.altura

    #Metodo de balanceo, realiza la resta
    def balancear(self, raiz):
        if not raiz:
            return 0
        return self.obtenerAltura(raiz.izquierda) - self.obtenerAltura(raiz.derecha)

    #Metodo busca el ultimo nodo
    def nodoMinimo(self, raiz):
        if raiz is None or raiz.izquierda is None:
            return raiz
        return self.nodoMinimo(raiz.izquierda)

    #Rotación por la izquierda
    def rotarIzquierda(self, z):
        y = z.derecha
        T2 = y.izquierda
        y.izquierda = z
        z.derecha = T2
        z.altura = 1 + max(self.obtenerAltura(z.izquierda),
                           self.obtenerAltura(z.derecha))
        y.altura = 1 + max(self.obtenerAltura(y.izquierda),
                           self.obtenerAltura(y.derecha))
        return y

    #Rotación por la derecha
    def rotarDerecha(self, z):
        y = z.izquierda
        T3 = y.derecha
        y.derecha = z
        z.izquierda = T3
        z.altura = 1 + max(self.obtenerAltura(z.izquierda),
                           self.obtenerAltura(z.derecha))
        y.altura = 1 + max(self.obtenerAltura(y.izquierda),
                           self.obtenerAltura(y.derecha))
        return y

    def insertar(self, raiz, carnet,dpi,nombre,carrera,correo,password,creditos,edad):
        #Buscar la posicion donde colocar el nuevo nodo Mayor->derecha, Menor->izquierda
        if not raiz:
            return Nodo(carnet,dpi,nombre,carrera,correo,password,creditos,edad)
        elif carnet < raiz.carnet:
            raiz.izquierda = self.insertar(raiz.izquierda, carnet,dpi,nombre,carrera,correo,password,creditos,edad)
        else:
            raiz.derecha = self.insertar(raiz.derecha, carnet,dpi,nombre,carrera,correo,password,creditos,edad)

        raiz.altura = 1 + max(self.obtenerAltura(raiz.izquierda),
                              self.obtenerAltura(raiz.derecha))

        #Balance del arbol para equilibrarlo
        factor = self.balancear(raiz)
        if factor > 1:
            if carnet < raiz.izquierda.carnet:
                return self.rotarDerecha(raiz)
            else:
                raiz.izquierda = self.rotarIzquierda(raiz.izquierda)
                return self.rotarDerecha(raiz)

        if factor < -1:
            if carnet > raiz.derecha.carnet:
                return self.rotarIzquierda(raiz)
            else:
                raiz.derecha = self.rotarDerecha(raiz.derecha)
                return self.rotarIzquierda(raiz)
        return raiz

    #Metodo para la eliminacion de un nodo
    def eliminar(self, raiz, carnet):
        # encontrar el nodo
        if not raiz:
            return raiz
        elif carnet < raiz.carnet:
            raiz.izquierda = self.eliminar(raiz.izquierda, carnet)
        elif carnet > raiz.carnet:
            raiz.derecha = self.eliminar(raiz.derecha, carnet)
        else:
            if raiz.izquierda is None:
                temp = raiz.derecha
                raiz = None
                return temp
            elif raiz.derecha is None:
                temp = raiz.izquierda
                raiz = None
                return temp
            temp = self.nodoMinimo(raiz.derecha)
            raiz.carnet = temp.carnet
            raiz.derecha = self.eliminar(raiz.derecha,
                                          temp.carnet)
        if raiz is None:
            return raiz

        #Agrega la altura del nodo
        raiz.altura = 1 + max(self.obtenerAltura(raiz.izquierda),
                              self.obtenerAltura(raiz.derecha))

        factor = self.balancear(raiz)

        #Balance del arbol para equilibrarlo
        if factor > 1:
            if self.balancear(raiz.izquierda) >= 0:
                return self.rotarDerecha(raiz)
            else:
                raiz.izquierda = self.rotarIzquierda(raiz.izquierda)
                return self.rotarDerecha(raiz)
        if factor < -1:
            if self.balancear(raiz.derecha) <= 0:
                return self.rotarIzquierda(raiz)
            else:
                raiz.derecha = self.rotarDerecha(raiz.derecha)
                return self.rotarIzquierda(raiz)
        return raiz

    #Modificar un valor
    def modificar(self, raiz, carnet, dpi, nombre, carrera, correo, password, creditos, edad):
        if not raiz:
            return raiz
        elif carnet < raiz.carnet:
            raiz.izquierda = self.modificar(raiz.izquierda, carnet, dpi, nombre, carrera, correo, password, creditos, edad)
        elif carnet > raiz.carnet:
            raiz.derecha = self.modificar(raiz.derecha, carnet, dpi, nombre, carrera, correo, password, creditos, edad)
        else:
            if raiz.izquierda is None:
                temp = raiz.derecha
                raiz = None
                return temp
            elif raiz.derecha is None:
                temp = raiz.izquierda
                raiz = None
                return temp
            temp = self.nodoMinimo(raiz.derecha)
            raiz.dpi = dpi
            raiz.nombre = nombre
            raiz.carrera = carrera
            raiz.correo = correo
            raiz.password = password
            raiz.creditos = creditos
            raiz.edad = edad
        if raiz is None:
            return raiz

    # Recorrido Post-Orden
    def postOrden(self, raiz):
        if not raiz:
            return
        self.postOrden(raiz.izquierda)
        self.postOrden(raiz.derecha)
        print("{0} ".format(raiz.carnet), end="")

    #Recorrido En-Orden
    def enOrden(self, raiz):
        if not raiz:
            return
        self.enOrden(raiz.izquierda)
        print("{0} ".format(raiz.carnet), end="")
        self.enOrden(raiz.derecha)

    #Recorrido Pre-Orden
    def preOrden(self, raiz):
        if not raiz:
            return
        print("{0} ".format(raiz.carnet), end="")
        self.preOrden(raiz.izquierda)
        self.preOrden(raiz.derecha)

    def buscarCarnet(self, raiz, carnet_buscar):
        global data_estudiante
        if not raiz:
            return
        if raiz.carnet==carnet_buscar:
            data_estudiante.append(raiz.carnet)
            data_estudiante.append(raiz.dpi)
            data_estudiante.append(raiz.nombre)
            data_estudiante.append(raiz.carrera)
            data_estudiante.append(raiz.correo)
            data_estudiante.append(raiz.password)
            data_estudiante.append(raiz.creditos)
            data_estudiante.append(raiz.edad)
        self.buscarCarnet(raiz.izquierda, carnet_buscar)
        self.buscarCarnet(raiz.derecha, carnet_buscar)

    #Muestra una estructura del arbol
    def printHelper(self, currPtr, indent, last):
        if currPtr != None:
            sys.stdout.write(indent)
            if last:
                sys.stdout.write("R----")
                indent += "     "
            else:
                sys.stdout.write("L----")
                indent += "|    "
            print(currPtr.carnet)
            self.printHelper(currPtr.izquierda, indent, False)
            self.printHelper(currPtr.derecha, indent, True)