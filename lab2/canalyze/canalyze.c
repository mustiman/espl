#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "fgetname.h"

int main(int argc, char **argv) {

  char *keywords[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","un","igned","void","volatile","while"};
  int counter[32];
  int i;
  for(i=0;i<32;++i){
    counter[i] = 0;
  }	

  for(i=1;i<argc;++i){
    FILE *stream = fopen(argv[i], "r");
    char name[64];
    int j;
    while(fgetname(name, sizeof(name), stream)){
	for(j=0;j<32;++j){
	  if(strncmp(name,keywords[j] , 64) == 0){
	    counter[j]++;
	  }
	}
    }
    fclose(stream);
  }
  for(i=0;i<32;++i){
    if(counter[i] == 1){
      printf("%s\n",keywords[i]);
    }
  }
  return 0;
  }

