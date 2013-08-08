#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("log.txt", "a");
	if(fp){
		printf("file opened");
		fprintf(fp, "Testing...\n");
		fclose(fp);
	}else{
		perror("failed to open file");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
