from mylist import Mylist

class MylistSub(Mylist):
  calls = 0
  def get_stats(self):
    return self.counts, MylistSub.calls
  def addcounts(self):
    self.counts = self.counts + 1
  def __init__(self, start =[]):
    self.counts = 0
    Mylist.__init__(self, start)
  def __add__(self, other):
    MylistSub.calls = MylistSub.calls + 1
    self.addcounts()
    return Mylist.__add__(self, other)

if __name__ == '__main__':
  x = MylistSub('spam')
  y = MylistSub('foo')
  print x[2]
  print x[1:]
  print x + ['eggs']
  print x + ['toast']
  print y + ['bar']
  print x.get_stats()
