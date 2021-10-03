from Estructuras.Objetos.Dia import Dia
from Estructuras.Objetos.Hora import Hora
from Estructuras.Estruc.Encabezado import Encabezado
from Estructuras.ListaTareas_LD import ListaTareas

class Matriz:
    def __init__(self):
        self.encFila = Encabezado()
        self.encColumna = Encabezado()

    def insertar(self, _hora, _dia, carnet, nombre, descripcion, materia, fecha, hora, estado):
        # insertando en filas
        hora = Hora(_hora)
        resFila = self.encFila.insertar(hora)

        # insertando en columnas
        dia = Dia(_dia)
        resCol = self.encColumna.insertar(dia)

        # Encabezados nuevos
        if resFila.derecha == None and resCol.abajo == None:
            nuevolc = self.nuevaListaTareas(_hora, _dia, carnet, nombre, descripcion, materia, fecha, hora, estado)
            # ASOCIANDO CABECERAS
            resFila.derecha = nuevolc
            resCol.abajo = nuevolc
        elif resFila.derecha != None and resCol.abajo == None:  # FILA EXISTE  COLUMNA NO
            # enlazamos la nueva cabecera
            nuevolc = self.nuevaListaTareas(_hora, _dia, carnet, nombre, descripcion, materia, fecha, hora, estado)
            resCol.abajo = nuevolc
            # trabajo con el valor de las columnas
            # insercion al inicio
            if nuevolc.columna < resFila.derecha.columna:
                nuevolc.derecha = resFila.derecha
                resFila.derecha.izquierda = nuevolc
                resFila.derecha = nuevolc
            else:
                tmp = resFila.derecha
                flagInsercion = False
                while tmp.derecha != None:
                    if nuevolc.columna > tmp.columna and nuevolc.columna < tmp.derecha.columna:  # INERCION AL MEDIO
                        nuevolc.derecha = tmp.derecha
                        tmp.derecha.izquierda = nuevolc
                        tmp.derecha = nuevolc
                        nuevolc.izquierda = tmp
                        flagInsercion = True
                    tmp = tmp.derecha

                if not flagInsercion:  # INSERCION AL FINAL
                    tmp.derecha = nuevolc
                    nuevolc.izquierda = tmp

        elif resFila.derecha == None and resCol.abajo != None:  # COLUMNA EXISTE ; FILA NO
            # enlazamos la nueva cabecera
            nuevolc = self.nuevaListaTareas(_hora, _dia, carnet, nombre, descripcion, materia, fecha, hora, estado)
            resFila.derecha = nuevolc
            # trabajo con el valor de las columnas
            # insercion al inicio
            if nuevolc.fila < resCol.abajo.fila:
                nuevolc.abajo = resCol.abajo
                resCol.abajo.arriba = nuevolc
                resCol.abajo = nuevolc
            else:
                tmp = resCol.abajo
                flagInsercion = False
                while tmp.abajo != None:
                    if nuevolc.fila > tmp.fila and nuevolc.fila < tmp.abajo.fila:  # INERCION AL MEDIO
                        nuevolc.abajo = tmp.abajo
                        tmp.abajo.arriba = nuevolc
                        tmp.abajo = nuevolc
                        nuevolc.arriba = tmp
                        flagInsercion = True
                    tmp = tmp.abajo

                if not flagInsercion:  # INSERCION AL FINAL
                    tmp.abajo = nuevolc
                    nuevolc.arriba = tmp
        else:  # aca si existen las cabeceras
            nuevolc = self.nuevaListaTareas(_hora, _dia, carnet, nombre, descripcion, materia, fecha, hora, estado)
            flagInsFila = False
            flagInsCol = False

            # VALIDACIONES DEL INICIO
            # filas
            if nuevolc.columna < resFila.derecha.columna:
                nuevolc.derecha = resFila.derecha
                resFila.derecha.izquierda = nuevolc
                resFila.derecha = nuevolc
                flagInsFila = True
            if nuevolc.fila < resCol.abajo.fila:
                nuevolc.abajo = resCol.abajo
                resCol.abajo.arriba = nuevolc
                resCol.abajo = nuevolc
                flagInsCol = True

            if not flagInsFila and flagInsCol:
                # encontrar el nulo de la fila
                tmpFila = resFila.derecha
                while tmpFila.derecha != None:
                    tmpFila = tmpFila.derecha

                tmpFila.derecha = nuevolc
                nuevolc.izquierda = tmpFila

            elif not flagInsCol and flagInsFila:
                tmpCol = resCol.abajo
                while tmpCol.abajo != None:
                    tmpCol = tmpCol.abajo
                tmpCol.abajo = nuevolc
                nuevolc.arriba = tmpCol

            elif not flagInsCol and not flagInsFila:
                tmpFila = resFila.derecha
                tmpCol = resCol.abajo
                while tmpFila.derecha != None and tmpCol.abajo != None:
                    tmpFila = tmpFila.derecha
                    tmpCol = tmpCol.abajo

                tmpFila.derecha = nuevolc
                tmpCol.abajo = nuevolc
                nuevolc.arriba = tmpCol
                nuevolc.izquierda = tmpFila

    def nuevaListaTareas(self, _hora, _dia, carnet, nombre, descripcion, materia, fecha, hora, estado):
        listatareas = ListaTareas()
        listatareas.insertar(_hora, _dia, carnet, nombre, descripcion, materia, fecha, hora, estado)
        return listatareas