class Node:
    def __init__(self,label):
        self.label=label
        self._padre=None
        self._derecha=None
        self._izquierda=None
        self.altura=0

    @property
    def derecha(self):
        return self._derecha

    @derecha.setter
    def derecha(self,node):
        if node is not None:
            node._padre=self
            self._derecha=node

    @property
    def izquierda(self):
        return self._izquierda

    @izquierda.setter
    def izquierda(self,node):
        if node is not None:
            node._padre=self
            self._izquierda=node

    @property
    def padre(self):
        return self._padre

    @padre.setter
    def padre(self,node):
        if node is not None:
            self._padre=node
            self.altura=self.padre.altura+1
        else:
            self.altura=0

class ArbolAVL:
    def __init__(self):
        self.raiz=None
        self.tamano=0

    def raiz(self):
        return self.raiz

    def vacio(self):
        if self.raiz is None:
            return True
        return False

    def insertar(self,valor):
        node=Node(valor)
        if self.raiz is None:
            self.raiz=node
            self.raiz.altura=0
            self.size=1
        else:
            nodo_padre=None
            nodo_actual=self.raiz

            while True:
                if nodo_actual is not None:
                    nodo_padre=nodo_actual

                    if node.label < nodo_actual.label:
                        nodo_actual=nodo_actual.izquierda
                    else:
                        nodo_actual=nodo_actual.derecha
                else:
                    node.altura=nodo_padre.altura
                    nodo_padre.altura+=1
                    if node.label < nodo_padre.label:
                        nodo_padre.izquierda=node
                    else:
                        nodo_padre.derecha=node
                    self.balancear(node)
                    self.size +=1
                    break

    def rotacion_izquierda(self,node):
        print("Rota izquierda")
        auxiliar=node.padre.label
        node.padre.label=node.label
        node.padre.derecha=Node(auxiliar)
        node.padre.derecha.altura=node.padre.altura+1
        node.padre.izquierda=node.derecha

    def rotacion_derecha(self,node):
        print("Rota derecha")
        auxiliar=node.padre.label
        node.padre.label=node.label
        node.padre.izquierda=Node(auxiliar)
        node.padre.left.altura=node.padre.altura+1
        node.padre.derecha=node.derecha

    def doble_rotacion_izquierda(self,node):
        print("Doble rota izquierda")
        self.rotacion_derecha(node.getDerecha().getDerecha())
        self.rotacion_izquierda(node)

    def doble_rotacion_derecha(self,node):
        print("Doble rota derecha")
        self.rotacion_izquierda(node.getIzquierda().getIzquierda())
        self.rotacion_derecha(node)

    def balancear(self,node):
        newnode=node
        while newnode is not None:
            altura_derecha=newnode.altura
            altura_izquierda=newnode.altura
            if newnode.derecha is not None:
                altura_derecha=newnode.derecha.altura
            if newnode.izquierda is not None:
                altura_izquierda=newnode.izquierda.altura
            if abs(altura_izquierda-altura_derecha)>1:
                if altura_izquierda > altura_derecha:
                    izquierda_hijo=newnode.izquierda
                    if izquierda_hijo is not None:
                        a_derecha=(izquierda_hijo.derecha.altura
                                   if(izquierda_hijo.derecha is not None) else 0)
                        a_izquierda=(izquierda_hijo.izquierda.altura
                                     if(izquierda_hijo.izquierda is not None) else 0)
                        if(a_izquierda > a_derecha):
                            self.rotacion_izquierda(newnode)
                            break
                        else:
                            self.doble_rotacion_derecha(newnode)
                            break
                else:
                    derecha_hijo=newnode.derecha
                    if derecha_hijo is not None:
                        a_derecha=(derecha_hijo.derecha.altura
                                   if(derecha_hijo.derecha is not None) else 0)
                        a_izquierda=(derecha_hijo.izquierda.altura
                                     if(derecha_hijo.izquierda is not None) else 0)
                    if (a_izquierda > a_derecha):
                        self.doble_rotacion_izquierda(newnode)
                        break
                    else:
                        self.rotacion_derecha(newnode)
                        break
            newnode=newnode.padre

    #Muestra los datos En-orden
    def mostrar(self,actual):
        if actual is not None:
            self.mostrar(actual.izquierda)
            print(actual.label, end=" ")
            self.mostrar(actual.derecha)

    def preOrder(self,actual):
        if actual is not None:
            self.mostrar(actual.izquierda)
            self.mostrar(actual.derecha)
            print(actual.label, end=" ")

