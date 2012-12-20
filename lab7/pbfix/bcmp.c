#include <stdio.h>
#include <unistd.h>

int main (int argc, char ** argv)
{
char c;
char flag;
int number=-1;
int location=0;
FILE *fp1;
FILE *fp2;
unsigned char buf1;
unsigned char buf2;
int q=1;
int change =0;
    while (1) {
        c = getopt (argc, argv, "n:qh");
	if (c == -1) {
            break;
        }
        switch (c) {
        case 'n':
            printf ("User has invoked with -n.\n");
	    number = atoi(optarg);
            break;
        case 'h':
            printf ("OPTIONS\n   -h  print a summary of options and exit\n   -n NUMBER  print first NUMBER differences and exit\n   -q do not print out the differences, exist with code 0\n      if the files are identical, 1 otherwise\n");
	    flag=c;
	    
            break;
	case 'q':
	    printf ("User has invoked with -q.\n");
	    q = 0;
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
    fp1 = fopen(argv[optind], "r");
    fp2 = fopen(argv[optind+1], "r");
      while(fread(&buf1, 1, 1, fp1) && fread(&buf2, 1, 1, fp2) && (number != location)){
      if (buf1 != buf2)
	if (q == 1){
	  fprintf(stdout,"byte %d -%d +%d\n",location,buf1,buf2);
	}else{
	  change =1;
	}	  
      location++;
    }
    if (q == 0){
      printf("%d\n",change);
    }
    fclose(fp1);
    fclose(fp2);
    }
    return 0;
}