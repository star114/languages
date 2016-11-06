def addr(*args) :
   sum = args[0]
   for x in args[1:]:
      sum += x
   return sum

print addr("a","ddr")
print addr(1,2)
print addr([1,2,3],[4,5,6])
print addr(1.2,2.3)
print addr('a','b','c','d')
print addr(1,2,3,4,5)
print addr([1],[2],[3],[4,5])
print addr(1.1,2.2,3.3)
