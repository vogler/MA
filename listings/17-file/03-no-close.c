#include <stdio.h>

FILE *fp;

int main(){
	fp = fopen("test.txt", "a");  // WARN: file is never closed
	fprintf(fp, "Testing...\n");
} // WARN: unclosed files: fp
