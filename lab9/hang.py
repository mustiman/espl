#!/usr/bin/env python

import sys
import random
#for arg in reversed(sys.argv):

turns = 5


line = random.choice(file("long-words.txt").readlines()).strip()
letters = [c for c in line]
g_letters=[]
while(turns > 0):
  gussed = [c in g_letters and c or '-' for c in letters]
  var = raw_input("Enter something: ")
  g_letters.append(var)
  gussed = [c in g_letters and c or '-' for c in letters]
  turns-=1
  print gussed
