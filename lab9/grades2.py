#!/usr/bin/env python

import sys

#for arg in reversed(sys.argv):
 
input = file("grades.csv")
try:
  input = file(sys.argv[1])
except: pass
d={}
count = -1
for line in input:
  if count == -1:
    count=0
  else:
    line = line.strip()
    myvec = line.split(',')
    try:
     d[myvec[2]]+=1
    except KeyError: d[myvec[2]]=1 
for kv in d.items():
   print "for grade %s num of student is :%s" % kv