#include "analyzer.h"

void AssempleSemanticInfo(union semantic_info* sem, char *str, int type) {
	
	if (type == 1) { // string
		sem->s = (char*)malloc((strlen(str) + 1) * sizeof(char));
		if (sem->s == NULL) {
			printf("Memory allocation failed!\n");
			exit(EXIT_FAILURE);
		}

		strcpy_s(sem->s, strlen(str) + 1, str);
	} else {
		sem->i = atoi(str);
	}
	
	
	
	
}

FILE* openfile(const char* str, const char* mode) {

	FILE* fp; 
	fopen_s(&fp,str, mode);

	if (fp == NULL) {
		fprintf(stderr, "file not found");
		exit(EXIT_FAILURE);
	}
	return fp;
}

void isFileExist(int file) {
	if (file == 1) {
		fprintf(stderr, "you did not put a file to read\n");
		exit(EXIT_FAILURE);
	}
}

void printSemastic_Info(union semantic_info* sem,int type) {
	switch (type) {
	case 1:
		printf("String: %s\n", sem->s);
		free(sem->s);
		break;
	case 2:
		printf("number: %d\n", sem->i);
		break;
	}
}
