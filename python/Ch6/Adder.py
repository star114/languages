class Adder:
  def __init__(self, data = []):
    self.data = data
  def add(self, x, y):
    print "Not Implemented"
  def __add__(self, other):
    return self.add(self.data, other)
class ListAdder(Adder):
  def add(self, x, y):
    lst = []
    for entry in x:
      lst.append(entry)
    for entry in y:
      lst.append(entry)
    return lst
class DictAdder(Adder):
  def add(self, x, y):
    dic = {}
    for entry in x:
      dic[entry] = x[entry]
    for entry in y:
      dic[entry] = y[entry]
    return dic

if __name__ == '__main__':
  adder = Adder()
  lstadder = ListAdder()
  dicadder = DictAdder()
  adder.add(1,2)
  print lstadder.add([1,2],[3,4])
  print dicadder.add({"test":1, "good":2},{"dict":2, "nice":4})
  x = ListAdder([1,2])
  y = DictAdder({1:1,2:2})
  print x + [3,4]
  print y + {"test":1, "3":3}
