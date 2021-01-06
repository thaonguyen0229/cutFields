// source: cutfuncs.c
#include <stdio.h>
#include <stdlib.h>
/*
  param: program name, max num of fields
  purpose: print error message, exit the program
*/
void printError(char *prgname, int max) {
	fprintf(stderr,"%s:  specify input_delimiter output_delimiter and 1-%d fields in order\n",prgname, max);
	exit(1);
}
