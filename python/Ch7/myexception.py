# personal defined error must be derived from BaseException class!!
class MyError(BaseException): pass

def oops():
  raise MyError, "Internal error in oops function"

def boundary():
  try:
    oops()
  except MyError, message:
    print message
  except IndexError:
    print "IndexError"
  else:
    print "Success!"

if __name__ == '__main__':
  boundary()

