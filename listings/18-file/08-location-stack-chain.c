#include <stdio.h>

FILE* myfopen(char* filename){
	int b;
	if(b)
		return myfopen(filename);
	else
		return fopen(filename, "a");
}

int main(){
	FILE *fp;
	fp = myfopen("test.txt");
	fprintf(fp, "Testing...\n");
	fclose(fp);
}
