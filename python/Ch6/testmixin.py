from mytools import Lister

class Super:
  def __init__(self):
    self.data1 = "spam"

class Sub(Super, Lister):
  def __init__(self):
    Super.__init__(self)
    self.data2 = "eggs"
    self.data3 = 42

class Test(Lister):
  def __init__(self):
    self.data4 = 1

if __name__ == "__main__":
  X = Sub()
  print X
  Y = Test()
  print Y
  
