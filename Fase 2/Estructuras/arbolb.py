class Nodo:
    def __init__(self, hoja=False):
        self.hoja = hoja
        self.datos = []
        self.hijos = []


class BTree:
    def __init__(self, t):
        self.root = Nodo(True)
        self.t = t

    # Insert a key
    def insert(self, k):
        root = self.root
        if len(root.datos) == (2 * self.t) - 1:
            temp = Nodo()
            self.root = temp
            temp.hijos.insert(0, root)
            self.split_child(temp, 0)
            self.insert_non_full(temp, k)
        else:
            self.insert_non_full(root, k)

    # Insert non full
    def insert_non_full(self, x, k):
        i = len(x.datos) - 1
        if x.hoja:
            x.datos.append((None, None))
            while i >= 0 and k[0] < x.datos[i][0]:
                x.datos[i + 1] = x.datos[i]
                i -= 1
            x.datos[i + 1] = k
        else:
            while i >= 0 and k[0] < x.datos[i][0]:
                i -= 1
            i += 1
            if len(x.hijos[i].datos) == (2 * self.t) - 1:
                self.split_child(x, i)
                if k[0] > x.datos[i][0]:
                    i += 1
            self.insert_non_full(x.hijos[i], k)

    # Split the child
    def split_child(self, x, i):
        t = self.t
        y = x.hijos[i]
        z = Nodo(y.hoja)
        x.hijos.insert(i + 1, z)
        x.datos.insert(i, y.datos[t - 1])
        z.datos = y.datos[t: (2 * t) - 1]
        y.datos = y.datos[0: t - 1]
        if not y.hoja:
            z.hijos = y.hijos[t: 2 * t]
            y.hijos = y.hijos[0: t - 1]









    # Delete a node
    def delete(self, x, k):
        t = self.t
        i = 0
        while i < len(x.datos) and k[0] > x.datos[i][0]:
            i += 1
        if x.hoja:
            if i < len(x.datos) and x.datos[i][0] == k[0]:
                x.datos.pop(i)
                return
            return

        if i < len(x.datos) and x.datos[i][0] == k[0]:
            return self.delete_internal_node(x, k, i)
        elif len(x.hijos[i].datos) >= t:
            self.delete(x.hijos[i], k)
        else:
            if i != 0 and i + 2 < len(x.hijos):
                if len(x.hijos[i - 1].datos) >= t:
                    self.delete_sibling(x, i, i - 1)
                elif len(x.hijos[i + 1].datos) >= t:
                    self.delete_sibling(x, i, i + 1)
                else:
                    self.delete_merge(x, i, i + 1)
            elif i == 0:
                if len(x.hijos[i + 1].datos) >= t:
                    self.delete_sibling(x, i, i + 1)
                else:
                    self.delete_merge(x, i, i + 1)
            elif i + 1 == len(x.hijos):
                if len(x.hijos[i - 1].datos) >= t:
                    self.delete_sibling(x, i, i - 1)
                else:
                    self.delete_merge(x, i, i - 1)
            self.delete(x.hijos[i], k)

    # Delete internal node
    def delete_internal_node(self, x, k, i):
        t = self.t
        if x.hoja:
            if x.datos[i][0] == k[0]:
                x.datos.pop(i)
                return
            return

        if len(x.hijos[i].datos) >= t:
            x.datos[i] = self.delete_predecessor(x.hijos[i])
            return
        elif len(x.hijos[i + 1].datos) >= t:
            x.datos[i] = self.delete_successor(x.hijos[i + 1])
            return
        else:
            self.delete_merge(x, i, i + 1)
            self.delete_internal_node(x.hijos[i], k, self.t - 1)

    # Delete the predecessor
    def delete_predecessor(self, x):
        if x.hoja:
            return x.pop()
        n = len(x.datos) - 1
        if len(x.hijos[n].datos) >= self.t:
            self.delete_sibling(x, n + 1, n)
        else:
            self.delete_merge(x, n, n + 1)
        self.delete_predecessor(x.hijos[n])

    # Delete the successor
    def delete_successor(self, x):
        if x.hoja:
            return x.datos.pop(0)
        if len(x.hijos[1].datos) >= self.t:
            self.delete_sibling(x, 0, 1)
        else:
            self.delete_merge(x, 0, 1)
        self.delete_successor(x.hijos[0])

    # Delete resolution
    def delete_merge(self, x, i, j):
        cnode = x.hijos[i]

        if j > i:
            rsnode = x.hijos[j]
            cnode.datos.append(x.datos[i])
            for k in range(len(rsnode.datos)):
                cnode.datos.append(rsnode.datos[k])
                if len(rsnode.hijos) > 0:
                    cnode.hijos.append(rsnode.hijos[k])
            if len(rsnode.hijos) > 0:
                cnode.hijos.append(rsnode.hijos.pop())
            new = cnode
            x.datos.pop(i)
            x.hijos.pop(j)
        else:
            lsnode = x.hijos[j]
            lsnode.datos.append(x.datos[j])
            for i in range(len(cnode.datos)):
                lsnode.datos.append(cnode.datos[i])
                if len(lsnode.hijos) > 0:
                    lsnode.hijos.append(cnode.hijos[i])
            if len(lsnode.hijos) > 0:
                lsnode.hijos.append(cnode.hijos.pop())
            new = lsnode
            x.datos.pop(j)
            x.hijos.pop(i)

        if x == self.root and len(x.datos) == 0:
            self.root = new

    # Delete the sibling
    def delete_sibling(self, x, i, j):
        cnode = x.hijos[i]
        if i < j:
            rsnode = x.hijos[j]
            cnode.datos.append(x.datos[i])
            x.datos[i] = rsnode.datos[0]
            if len(rsnode.hijos) > 0:
                cnode.hijos.append(rsnode.hijos[0])
                rsnode.hijos.pop(0)
            rsnode.datos.pop(0)
        else:
            lsnode = x.hijos[j]
            cnode.datos.insert(0, x.datos[i - 1])
            x.datos[i - 1] = lsnode.datos.pop()
            if len(lsnode.hijos) > 0:
                cnode.hijos.insert(0, lsnode.hijos.pop())

    # Print the tree
    def print_tree(self, x, l=0):
        print("Level ", l, " ", len(x.datos), end=":")
        for i in x.datos:
            print(i, end=" ")
        print()
        l += 1
        if len(x.hijos) > 0:
            for i in x.hijos:
                self.print_tree(i, l)



