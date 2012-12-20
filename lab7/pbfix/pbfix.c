#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "diff.h"

int fixme(FILE *tochange,struct diff mydiff)
{
  printf("here in FIX\n");
  fseek(tochange, mydiff.offset, SEEK_SET );
  fwrite( &mydiff.new,1,1,tochange);
  return 0;
}

int main(int argc, char **argv) {
    FILE *changes;
    FILE *tochange;
    struct diff diff;
    char line[128];
    char ch[1]={'a'};
    int message = 0;
    char c;
    int reverse=0;
    int pid;
    int count = 0;
    int status;
    
    while (1) {
      c = getopt (argc, argv, "rmh");
      if (c == -1) {
	  break;
      }
      switch (c) {
      case 'r':
	  printf ("User has invoked with -r.\n");
	  reverse = 1;
	  break;
      case 'h':
	  printf ("OPTIONS\n   -h  print a summary of options and exit\n   -r  reverse the differences\n   -m  print a message each time a change is applied\n");
	  
	  break;
      case 'm':
	  printf ("User has invoked with -m.\n");
	  message = 1;
	  break;
      case '?':
      default:
	  printf ("Usage: %s [-a] [-b <something>].\n", argv[0]);
	  break;
	} 
    }
   if(argc != optind+2)
     printf("illigel input\n%d %d",argc,optind);
   else{

    tochange = fopen(argv[optind], "rb+");    
    changes = fopen(argv[optind+1], "r");
   
    
    while ( fgets ( line, 128, changes ) != NULL )
      {
	parsediff(line, &diff);
	fseek(tochange, diff.offset, SEEK_SET );
	ch[0] = (char)getc(tochange);
	if (!reverse){
	  if (ch[0] == diff.old){
		    
	    count++;
	    pid = fork();
	    if(pid == 0){
	        printf("%d\n",count);
	      fixme(tochange,diff);
	      exit(0);
	      }
	    }
	  }
	
     }
    fclose(tochange);
    fclose(changes);
   }
   	    if (pid != 0){

	      while (count > 0){
		wait(&status);
		printf("exit with status %ld\n",(long)status);
		count--;
	      }
	    }
    return 0;
}



