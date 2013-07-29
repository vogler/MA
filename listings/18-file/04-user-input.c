#include <stdio.h>

FILE *fp;

int main(){
	char text[20];
	fp = fopen("test.txt", "w");
	fprintf(fp, "Testing...");
	// fclose();
	printf("enter some text: ");
	fgets(text, sizeof text, stdin);
	printf("text = \"%s\"\n", text);
}