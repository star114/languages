def countLines(name):
   file = open(name, "r")
   data = file.readlines()
   n = len(data)
   file.close()
   return n

def countChars(name):
   file = open(name, "r")
   data = file.read()
   n = len(data)
   file.close()
   return n

def test(name):
   print "countLines:", countLines(name)
   print "countChars:", countChars(name)

if __name__ == "__main__":
   import mymod
   mymod.test("mymod.py")
