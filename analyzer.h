#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//unions
union semantic_info {
	char* s;
	int i;
} SEMANTIC_INFO;

//functions

int yylex(FILE* fpointer, union semantic_info* sem); 
void AssempleSemanticInfo(union semantic_info* sem, char* str, int type); // creating the union
FILE* openfile(const char* str, const char* mode); // open the file and check if there is
void isFileExist(int file); // for the arguments variables
void printSemastic_Info(union semantic_info* sem,int type); // print the result


