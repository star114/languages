import string
class mywrapper:
  def __init__(self, filename = None, filetext = None):
    if filetext == None: 
      handle = open(filename, "r")
      self._filetext = handle.read()
      handle.close()
    else:
      self._filetext = filetext
    self._paragraphs = string.split(self._filetext, '\n\n')
    self._lines = string.split(self._filetext, '\n')
    self._words = string.split(self._filetext)
  def __repr__(self):
    return self._filetext
  def paragraph(self, index):
    return mywrapper(filetext = self._paragraphs[index])
  def line(self, index):
    return mywrapper(filetext = self._lines[index])
  def word(self, index):
    return self._words[index]
  def get_line_count(self):
    return len(self._lines)
  def get_paragraph_count(self):
    return len(self._paragraphs)
  def get_word_count(self):
    return len(self._words)
  def get_lines(self):
    return self._lines

if __name__ == '__main__':
  print '====test.txt===='
  FileData = mywrapper('test.txt')
  s =FileData.paragraph(1)
  print 's:', s
  print 's.word(2)',s.word(2)
  print 'data.word(2)', FileData.word(2)
  print 'data.line(1)', FileData.line(1)
  print '====counts===='
  print 'lines :',FileData.get_line_count()
  print 'paragraph :', FileData.get_paragraph_count()
  print 'word :', FileData.get_word_count()
  print '====lines===='
  index = 0
  for line in FileData.get_lines():
    index = index + 1
    print index, line
