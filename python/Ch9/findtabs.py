#! /usr/local/bin/python
# find files, search for tabs

import string, sys

# portability
if sys.platform == 'win32':
  try:
    import win32pipe
    popen = win32pipe.popen
  except ImportError:
    raise ImportError, "The win32pipe module could not be found"
else:
  import os
  popen = os.popen

cmd = 'find . -name "*.py" -print'
for file in popen(cmd).readlines():
  num = 1
  name = file[:-1]                    # remove \n
  for line in open(name).readlines(): # Read File
    pos = string.find(line, "\t")
    if pos >= 0:
      print name, num, pos
      print '. . ..', line[:-1]
      print '. . ..', ' '*pos + '*', '\n'
    num = num +1

