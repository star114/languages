import sys,os,string

def listupdir(start, find_str):
  def listupdir_helper(arg, dirname, files):
    """ Helper function for listing directories up """
    # print "Directory %s has files:" % dirname
    for file in files:
      fullpath = os.path.join(dirname, file)
      if string.find(file, find_str) != -1:
        print ' ' + fullpath
  os.path.walk(start, listupdir_helper, None)

if __name__ == '__main__':
  listupdir(sys.argv[1], sys.argv[2])


