#!/usr/bin/env python

import sys

#for arg in reversed(sys.argv):
 
input = file("grades.csv")
count = 0
counter = 0
for line in input:
   line = line.strip()
   myvec = line.split(',')
   try:
    count = count + float(myvec[2])
    counter+=1
   except: pass 
print count/counter