class Board():
    def __init__(self, height, width):
        self.height = height
        self.width = width
        self.data = [ [0]*width for _ in range(height) ]
    def print_(self):
        print self.height, self.width, self.data
    def setValueInternal(self, block, row, col, type):
        check = True
        for i in range(block.getHeight()):
            for j in range(block.getWidth()):
                if type == 1:
                    self.data[row + i][col + j] += block.getValue(i, j)
                else:
                    self.data[row + i][col + j] -= block.getValue(i, j)
                if self.data[row + i][col + j] > 1:
                    check = False
        return check

    def setValue(self, block, row, col, type):
        if row + block.getHeight() > self.height or col + block.getWidth() > self.width:
            return False
        Ret = True
        if self.setValueInternal(block, row, col, type) == False:
            self.setValueInternal(block, row, col, 0)
            Ret = False
        return Ret
class Block():
    def __init__(self, height, width):
        self.height = height
        self.width = width
        self.rotate = 0
        self.data = [ [0]*width for _ in range(height) ]
    def print_(self):
        print self.height, self.width, self.data
    def getValue(self, row, col):
        if self.rotate == 0:
            return self.data[row][col]
        if self.rotate == 1:
            return self.data[col][height-row]
        if self.rotate == 2:
            return self.data[height-row][width-col]
        if self.rotate == 3:
            return self.data[width-col][row]
    def getHeight(self):
        if self.rotate % 2 == 0:
            return self.height
        else:
            return self.width
    def getWidth(self):
        if self.rotate % 2 == 0:
            return self.width
        else:
            return self.height

cases = int(raw_input(""))
for _ in range(cases):
    input = [int(x) for x in raw_input("").split()]
    H = input[0]
    W = input[1]
    R = input[2]
    C = input[3]
    board = Board(H,W)
    for i in range(H):
        line = raw_input("")
        for j in range(W):
            if line[j] == '#':
                board.data[i][j] = 1
    board.print_()

    block = Block(R,C)
    for i in range(R):
        line = raw_input("")
        for j in range(C):
            if line[j] == '#':
                block.data[i][j] = 1
    block.print_()

    board.setValue(block, 0, 2, 1)
    board.print_()

