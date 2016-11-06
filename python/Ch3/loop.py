# 1.a
S = "abcd"
for x in S:
   print ord(x)

# 1.b
sum = 0
for x in S:
   sum += ord(x)
else:
   print sum

# 1.c
newS = []
for x in S:
   newS += [ord(x)]
else:
   print newS

print map(ord,S)
