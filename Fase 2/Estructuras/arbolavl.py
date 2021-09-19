class Nodo(object):
    def __init__(self,carnet):
        self.carnet=carnet
        self.izquierda=None
        self.derecha=None
        self.altura=1

class ArbolAVL(object):
    def obtenerAltura(self,raiz):
        if not raiz:
            return 0
        return raiz.altura

    def obtenerBalance(self,raiz):
        if not raiz:
            return 0
        return self.obtenerAltura(raiz.izquierda)-self.obtenerAltura(raiz.derecha)

    #Modo de rotación por izquierda
    def rotarIzquierda(self,nodo):
        nodoy=nodo.derecha
        nodox=nodoy.izquierda
        nodoy.izquierda=nodo
        nodo.derecha=nodox
        nodo.altura=1+ max(self.obtenerAltura(nodo.izquierda),
                           self.obtenerAltura(nodo.derecha))
        nodoy.altura=1+max(self.obtenerAltura(nodoy.izquierda),
                           self.obtenerAltura(nodoy.derecha))
        return nodoy

    #Modo de rotación por derecha
    def rotarDerecha(self,nodo):
        nodoy=nodo.izquierda
        nodox=nodoy.derecha
        nodoy.derecha=nodo
        nodo.izquierda=nodox
        nodo.altura=1+max(self.obtenerAltura(nodo.izquierda),
                          self.obtenerAltura(nodo.derecha))
        nodoy.altura=1+max(self.obtenerAltura(nodoy.izquierda),
                           self.obtenerAltura(nodoy.derecha))
        return nodoy

    #Metodo para obtener el valor minimo del nodo
    def minimoNodo(self,raiz):
        if raiz is None or raiz.izquierda is None:
            return raiz
        return self.minimoNodo(raiz.izquierda)

    #Metodo de insertar
    def insertar(self,raiz,carnet):
        if not raiz:
            return Nodo(carnet)
        elif carnet < raiz.carnet:
            raiz.izquierda=self.insertar(raiz.izquierda,carnet)
        else:
            raiz.derecha=self.insertar(raiz.derecha,carnet)
        raiz.altura=1+max(self.obtenerAltura(raiz.izquierda),
                          self.obtenerAltura(raiz.derecha))

        #Balancear el árbol AVL
        balance=self.obtenerBalance(raiz)
        if balance>1:
            if carnet < raiz.izquierda.carnet:
                return self.rotarDerecha(raiz)
            else:
                raiz.izquierda=self.rotarIzquierda(raiz.izquierda)
                return self.rotarDerecha(raiz)
        if balance<-1:
            if carnet>raiz.derecha.carnet:
                return self.rotarIzquierda(raiz)
            else:
                raiz.derecha=self.rotarDerecha(raiz.derecha)
                return self.rotarIzquierda(raiz)
        return raiz

    #Metodo de eliminar
    def eliminar(self,carnet,raiz):
        if not raiz:
            return raiz
        elif carnet<raiz.carnet:
            raiz.izquierda=self.eliminar(raiz.izquierda,carnet)
        elif carnet>raiz.carnet:
            raiz.derecha=self.eliminar(raiz.derecha,carnet)
        else:
            if raiz.izquierda is None:
                temp=raiz.derecha
                raiz=None
                return temp
            elif raiz.derecha is None:
                temp=raiz.izquierda
                raiz=None
                return temp
            temp=self.minimoNodo(raiz.derecha)
            raiz.carnet=temp.carnet
            raiz.derecha=self.eliminar(raiz.derecha,temp.carnet)

        if raiz is None:
            return raiz

        #Medir alturas del ALV
        raiz.altura=1+max(self.obtenerAltura(raiz.izquierda),
                          self.obtenerAltura(raiz.derecha))
        balance=self.obtenerBalance(raiz)

        #Balancear el arbol AVL
        if balance>1:
            if self.obtenerBalance(raiz.izquierda)>=0:
                return self.rotarDerecha(raiz)
            else:
                raiz.izquierda=self.rotarIzquierda(raiz.izquierda)
                return self.rotarDerecha(raiz)
        if balance<-1:
            if self.obtenerBalance(raiz.derecha)<=0:
                return self.rotarIzquierda(raiz)
            else:
                raiz.derecha=self.rotarDerecha(raiz.derecha)
                return self.rotarIzquierda(raiz)
        return raiz

    #Metodo PreOrder
    def preOrder(self,raiz):
        if not raiz:
            return
        print("{0} ".format(raiz.carnet),end="")
        self.preOrder(raiz.izquierda)
        self.preOrder(raiz.derecha)

    #Metodo mostrar datos
    def mostrar(self,actual,acum,ultimo):
        if actual!=None:
            print(acum)
            if ultimo:
                print("R-----")
                acum+="       "
            else:
                print("L-----")
                acum+="|    "
            print(actual.carnet)
            self.mostrar(actual.izquierda,acum,False)
            self.mostrar(actual.derecha,acum,True)