import sys, os
class myPrompt:
  def __init__(self, subprompt = ">>> "):
    self.lineno = 0
    self.subprompt = subprompt
  def __repr__(self):
    self.lineno = self.lineno + 1
    return os.getcwd() + '|' + `self.lineno` + self.subprompt

sys.ps1 = myPrompt()
sys.ps2 = myPrompt('...')
