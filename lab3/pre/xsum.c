#include <stdio.h>
#include <unistd.h>

int main (int argc, char ** argv)
{
    while (1) {
        char c;

        c = getopt (argc, argv, "x:h");
        if (c == -1) {
            break;
        }
        switch (c) {
        case 'x':
            printf ("User has invoked with -x.\n");
	    FILE *fp;
	    fp = fopen(argv[2], "r");
	    unsigned int word;
	    unsigned int cksum;
	    fread(&cksum, sizeof(word), 1, fp);
	    printf ("%x\n",cksum);
	    while(fread(&word, sizeof(word), 1, fp)) {
	      cksum = cksum ^ word;
	    }	
	       fclose(fp);  
	    printf("%x\n",cksum);
            break;
        case 'h':
            printf ("OPTIONS\n   -h  print a summary of options and exit\n   -x  print the checksum as a hexadecimal rather than decimal number..\n");
            break;
        case '?':
        default:
            printf ("Usage: %s [-a] [-b <something>].\n", argv[0]);
        }
    }
    return 0;
}