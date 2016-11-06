L = [1,2,4,8,16,32,64]
X = 5

value = 2 ** X

if value in L:
   print 'at index', L.index(value)
else:
   print X, 'not found'
