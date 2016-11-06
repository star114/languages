import sys,os,stat

def listupdir(start):
  def listupdir_helper(arg, dirname, files):
    """ Helper function for listing directories up """
    print "Directory %s has files:" % dirname
    for file in files:
      fullpath = os.path.join(dirname, file)
      if os.path.isdir(fullpath):
        print ' ' + file + ' (subdir)'
      else:
        size = os.stat(fullpath)[stat.ST_SIZE]
        print ' ' + file + ' size=' + `size`
  os.path.walk(start, listupdir_helper, None)

if __name__ == '__main__':
  listupdir(sys.argv[1])

""" My own code
def listup(strPath):
  lst = []
  for _list in os.listdir(strPath):
    strFullPath = strPath + "/" + _list
    if os.path.isdir(strFullPath):
      #print "dir", _list
      lst = lst + (listup(strFullPath))
    else:
      #print "not dir", _list
      lst.append(_list)
  return lst

print listup(sys.argv[1]);
""" 

