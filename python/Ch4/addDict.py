def addDict(dict1, dict2):
   dic = {}
   for key1 in dict1.keys():
      if key1 not in dic:
         dic[key1] = dict1[key1]
   for key2 in dict2.keys():
      if key2 not in dic:
         dic[key2] = dict2[key2]
   return dic

#test
print addDict({"1":1, "2":2, "3":5} , {"1":2, "6":6, "9":9})
