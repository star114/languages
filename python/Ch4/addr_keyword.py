def addr(good = 0,bad = 1, ugly = 2) :
   return good + bad + ugly

def addr_general(good, bad = 0, **args):
   sum = good+bad
   for key in args.keys():
      sum += args[key]
   return sum

print addr(1,2,3)
print addr(1.2,2.3)
print addr(bad = 100, ugly = 5)
print addr_general(good=1, bad=2, handsome=4)
print addr_general(0, handsome = 5)
