#include "analyzer.h"



int main(int argc, char* argv[]) {
	
	isFileExist(argc);

	FILE* fp = openfile(argv[1], "r");
	int shownum = 0, showchar = 0;
	union semantic_info sem;

	int tokentype;
	while ((tokentype = yylex(fp, &sem)) != 0) {
		
		printSemastic_Info(&sem, tokentype);
		
		if (tokentype == 1) {
			showchar++;
		}
		else {
			shownum++;
		}
	}

	printf("\ntotal strings are %d\n", showchar);
	printf("total numbers are %d\n", shownum);
	
	fclose(fp);
	
	
	return 0;
}