class Mylist:
  def __init__(self, start = []):
    self.data = []#start[:]
    for x in start: self.data.append(x)
  def __add__(self, other):
    return Mylist(self.data + other)
  def __mul__(self, time):
    return Mylist(self.data * time)
  def __getitem__(self, index):
    return self.data[index]
  def __len__(self):
    return len(self.data)
  def __getslice__(self, low, high):
    return Mylist(self.data[low:high])
  def append(self, node):
    self.data.append(node)
  def __getattr__(self, name):
    return getattr(self.data, name)
  def __repr__(self):
    return `self.data`
  
if __name__ == '__main__':
  x = Mylist('spam')
  print x
  print x[2]
  print x[1:]
  print x + ['eggs']
#  print ['eggs'] + x
  print x * 3
  x.append('a')
  x.sort()
  for c in x: print c,
