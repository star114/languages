class Stack:
  def __init__(self, data = None):
    if data == None:
      self._data = []
    else:
      self._data = list(data)
  def push(self, item):
    self._data.append(item)
  def pop(self):
    if self._data == []:
      item = None
    else:
      item = self._data[-1]
      del self._data[-1]
    return item
  def size(self):
    return len(self._data)

if __name__ == '__main__':
  stack = Stack()
  stack.push(1)
  stack.push(2)
  stack.push(3)
  print stack.size()
  print stack.pop()
  print stack.pop()
  print stack.pop()
  print stack.pop()
  
