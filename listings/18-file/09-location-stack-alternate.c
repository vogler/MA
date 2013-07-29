#include <stdio.h>

FILE* myfopen2(int i);
FILE* myfopen1(int i){
	if(i>0)
		return myfopen2(i-1);
	else
		return fopen("test-even.txt", "a");
}
FILE* myfopen2(int i){
	if(i>0)
		return myfopen1(i-1);
	else
		return fopen("test-odd.txt", "a");
}

int main(){
	FILE *fp1;
	fp1 = myfopen1(5);
	fprintf(fp1, "Testing...\n");
	fclose(fp1);
}
