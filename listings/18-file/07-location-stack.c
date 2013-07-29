#include <stdio.h>
#include <stdlib.h>

FILE* myfopen(char* filename){
	FILE *fp;
	fp = fopen(filename, "a");
	if(fp == NULL){
		printf("Error opening file");
		exit(EXIT_FAILURE);
	}else{
		return fp;
	}
}

int main(){
	FILE *fp1;
	FILE *fp2;
	fp1 = myfopen("test1.txt");
	fp2 = myfopen("test2.txt"); // WARN: file is never closed

	fprintf(fp1, "Testing...\n");
	fclose(fp1);
	fprintf(fp2, "Testing...\n");
	// fclose(fp2);
} // WARN: unclosed files: fp2
