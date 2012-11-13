#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "diff.h"

int main(int argc, char **argv) {
    FILE *changes;
    FILE *tochange;
    struct diff diff;
    char line[128];
    fpos_t file_pos;
    char ch[1]={'a'};
    int message = 0;
    char c;
    int reverse=0;
    
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
	  	  printf("ch[0] = %d   diff.new = %d\n",ch[0],diff.new);
	  if (ch[0] == diff.old){
	    fseek(tochange, diff.offset, SEEK_SET );
	    fwrite( &diff.new,1,1,tochange);
	    if(message){
	      printf("changed - %c with - %c\n",diff.old,diff.new);
	    }
	  }
	}else{
	  if (ch[0] == diff.new){
	    fseek(tochange, diff.offset, SEEK_SET );
	    fwrite( &diff.old,1,1,tochange);
	    if(message){
	      printf("changed - %c with - %c\n",diff.new,diff.old);
	    }
	  }
	}
     
    }
    fclose(tochange);
    fclose(changes);
   }
    return 0;
}


