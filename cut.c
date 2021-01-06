/* source: cut.c
   CLAs: input,  output delimiters, fields
   purpose: cut fields of text from stdin
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cutfuncs.h"
#define MAX 100
int main(int argc, char *argv[]){
	char indlmt, outdlmt; /*input, output delimiters*/
	
	//check for valid 1st, 2nd args and number of args
	if (argc < 4 || strlen(argv[1]) != 1 || strlen(argv[2]) != 1)
		printError(argv[0],MAX);
	indlmt = argv[1][0]; 
	outdlmt = argv[2][0];
	
	int fields[MAX]; /*fields will be outputed */
	//check for valid input fields
	for (int i = 3 ; i < argc; i++) {
		for (int j = 0; j < strlen(argv[i]); j++){
			if (!isdigit(argv[i][j])) printError(argv[0], MAX);
		}
		int num = atoi(argv[i]);
		if (i > 3  && num <= fields[i-4]) printError(argv[0], MAX);
		else fields[i-3] = num;
	}

	int count=1,	/*order of fields from stdin*/
	i=0, 		/*index of fields[]*/
	fwc = 0;	/*index of str for first field*/
	char c;		/*reading char*/
	char first[100];/*first field*/


	while ((c = getchar()) != EOF) {
		//save first field
		if (count == 1 && fields[0] != 1){
			if (c == '\n') first[fwc] = '\0';
			else first[fwc] = c;
			fwc++;
		}
		

		//next field
		if (c == '\n'){
			if (count == 1 && fields[0] != 1)
				printf("%s", first); 
			count = 1; i = 0; fwc = 0;
			putchar('\n');
			continue;
		}

		//output fields
		if (count == fields[i] && c != indlmt) putchar(c);
		if (c == indlmt) {
			if (count == fields[i] && i < argc - 3) i++;
			count++;
			if (count == fields[i] && i != 0) putchar(outdlmt);
		} 
	}
	exit(0);
}
