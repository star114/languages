L = [1,2,4,8,16,32,64]
X = 5

i = 0

for value in L:
   if 2 ** X == value:
      print 'at index', L.index(value)
      break
   else:
      i = i+1
else:
   print X, 'not found'
