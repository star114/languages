class Node:
    def __init__(self):
        self.parent = None
        self.index = -1
        self.rank = -1
    def __init__(self, i, r, p=None):
        self.parent = p
        self.index = i
        self.rank = r

class disjoint_set:
    def __init__(self):
        self.rank = 0
        self.

if __name__ == '__main__':
    n = Node(0,1)
    print n.parent, n.index, n.rank
