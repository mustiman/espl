#!/usr/bin/env python

import os, os.path, sys, getpass, shlex, subprocess

home=os.getenv('HOME')

def getcwd():
    "like os.getcwd(), but collapses the home directory prefix into ~"
    cwd = os.getcwd()
    if cwd.startswith(home):
        cwd = '~'+cwd[len(home):]
    return cwd
    
def exeInOut():
    inp = sys.stdin
    outp = sys.stdout
    ar = argv
    if len(argv) >= 3 :
      if argv[-2]=='<': #input
	inp = open(argv[-1],'r')
      elif argv[-2]=='>': #output
	outp = open(argv[-1],'w')
      ar = argv[:-2]
    
    subprocess.call(ar, stdin=inp, stdout=outp)
    

def passThePipe(pipeIndex):
  pipe1 = argv[:pipeIndex]
  pipe2 = argv[pipeIndex+1:]
  p1 = subprocess.Popen(pipe1, stdout=subprocess.PIPE)
  subprocess.call(pipe2,stdin=p1.stdout,stdout=sys.stdout)
   
while True:
    print "%s@%s>" % (getpass.getuser(), getcwd()),

    argv = None
    try:
        argv = shlex.split(raw_input())
    except EOFError:
        print
        break                             # end of file from user, e.g. Ctrl-D

    if not argv:
        continue # empty command

    if argv[0] in ['exit', 'quit', 'bye']:
        break
    elif argv[0]=='cd':
        try:
            os.chdir(os.path.expanduser(argv[1])) # expand ~ to home directory
        except IndexError:                   # no arguments, chdir to home dir
            os.chdir(home)
        except OSError, s:
            print >>sys.stderr, "chdir: %s" % s
    # in case there is a pipe
    else:
      try:
	checkIfPipe = argv.index('|')
	passThePipe(pipeIndex=checkIfPipe)
      # in case there is no pipe
      except ValueError:
	exeInOut()

# goodbye message
goodbye = "have a good sunny day, see you back soon"
print "*"+"-"*(len(goodbye)+2)+"*"
print "| %s |" % goodbye
print "*"+"-"*(len(goodbye)+2)+"*" 
