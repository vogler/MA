#include <stdio.h>

int main(){
	FILE *fp;
	fp = fopen("log.txt", "a");
	fprintf(fp, "Testing...\n"); // log something
	fclose(fp);
	// do important things
}
