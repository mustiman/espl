#include <stdio.h>
 
void main(int argc, char **argv) {
  int lineCount=0;
  FILE *fp;
  fp = fopen("test.txt", "r");
  char line[128];
  while ( fgets ( line, 128, fp ) != NULL )
  {
      ++lineCount;
  } 
  srand ( (unsigned)time ( NULL ) );
  int ran = rand () % lineCount;

    lineCount=0;
   fclose(fp);   
      fp = fopen("test.txt", "r");
  while ( fgets ( line, 128, fp ) != NULL )
  {
      if(lineCount == ran){
      printf("%d: %s\n",lineCount,line);
      }
	
      ++lineCount;
  }

  fclose(fp);
  
}