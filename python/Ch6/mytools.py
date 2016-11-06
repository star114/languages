# tools


# Lister Class
# Mixin class with any classes
# it inherits __repr__ function to print formatting string for instance.
class Lister:
  def __repr__(self):
    return ("<Instance of %s(%s), address %s:\n:%s>" %
            (self.__class__.__name__,
             self.super(),
             id(self),
             self.attrnames()))
  def attrnames(self):
    result = ''
    for attr in self.__dict__.keys():
      if attr[:2] == '__':
        result += "\tname %s=<built-in>\n" % attr
      else:
        result += "\tname %s=%s\n" % (attr, self.__dict__[attr])
    return result
  def super(self):
    result = self.__class__.__bases__[0].__name__
    for name in self.__class__.__bases__[1:]:
      result = result + ", " + name.__name__
    return result
      


# factory function
# it can create any instance.
def factory(aClass, *args):
  return apply(aClass, *args)
