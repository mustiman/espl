#include <stdlib.h>
#include <stdio.h>

extern int malami();

int main(int argc, char **argv) {
	int ans = malami(argv[1]);
	printf("the value is: %d\n",ans);

	return 0;
}
