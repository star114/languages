import sys
import traceback
def safe(func, *args):
  try:
    apply(func, *args)
  except:
    exc_type, exc_value = sys.exc_info()[:2]
    print exc_type, exc_value
    traceback.print_exc()

if __name__ == '__main__':
  import exception, myexception
  safe(exception.oops)
  safe(myexception.oops)
