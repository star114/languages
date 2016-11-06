#import mymod
#mymod.test("mymod.py")

from mymod import countLines, countChars
print countLines("mymod.py"), countChars("mymod.py")
