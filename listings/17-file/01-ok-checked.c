#include <stdio.h>

int main(){
	FILE *fp;
	fp = fopen("log.txt", "a");
	if(fp){
		printf("file opened");
		fprintf(fp, "Testing...\n");
		fclose(fp);
	}else{
		printf("error opening file");
	}
}