#def oops():
#  try:
#    x = [1,2,3]
#    x[3]
#  except IndexError:
#    print "IndexError"
#  except KeyError:
#    print "KeyError"
#  else:
#    print "Success"

def oops():
  raise IndexError
def boundary():
  try:
    oops()
  except IndexError:
    print "IndexError"
  except KeyError:
    print "KeyError"
  else:
    print "Success"


if __name__ == '__main__':
  boundary()

