def copyDic (dic):
   ref_dic = {}
   for key in dic.keys():
      ref_dic[key] = dic[key]
   return ref_dic


#test
T = {"Tom":1, "Messi":2, "Lucas":3}
S = copyDic(T)
S["Tom"] = 5
print T
print S
