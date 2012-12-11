#include <stdio.h>
#include <unistd.h>


int old_main2(FILE *fp1,FILE *fp2){
  int location=0;
  unsigned char buf1;
  unsigned char buf2;
      while(fread(&buf1, 1, 1, fp1) && fread(&buf2, 1, 1, fp2)){
      if (buf1 != buf2)
	  fprintf(stdout,"byte %d -%d +%d\n",location,buf1,buf2);
        location++;
    }
    fclose(fp1);
    fclose(fp2);
  return 0;
}

