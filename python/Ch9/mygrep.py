import fileinput, sys, string
# take the first argument out of sys.argv and assign it to searchterm
searchterm, sys.argv[1:] = sys.argv[1], sys.argv[2:]
for line in fileinput.input():
  num_matches = string.count(line, searchterm)
  if num_matches:
    print "found '%s' %d times in %s on line %d." % (searchterm, num_matches, fileinput.filename(), fileinput.filelineno())
