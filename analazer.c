/*if you want to put a file you can go to main and put a file that you want*/
#include "analyzer.h"

int yylex(FILE* fpointer, union semantic_info* sem) {

	int nextcharacter, state = 0, put_index = 1;;
	char lexeme[100];
	while ((nextcharacter = fgetc(fpointer)) != EOF) {
		switch (state) {
		case 0: // state 0
			if (isalpha(nextcharacter)) { // going to state 1 (string)
				state = 1;
				fseek(fpointer, -1, SEEK_CUR); // we need to go back so we can read the character again
			}
			else if (isdigit(nextcharacter)) { // going to state 2 (number)
				state = 2;
				fseek(fpointer, -1, SEEK_CUR); // we need to go back so we can read the character again
			}
			else {
				continue;
			}
			break;
		case 1: // state 1 (string)
			
			lexeme[0] = nextcharacter;
			while ((nextcharacter = fgetc(fpointer)) != ' ') { // we know that if we see a space we need stop
				if (nextcharacter == EOF || nextcharacter == '\n') { // we are done with reading the file
					lexeme[put_index] = '\0';
					AssempleSemanticInfo(sem, lexeme, state);
					return state;
				}
				lexeme[put_index] = nextcharacter;
				put_index++;
			}
			lexeme[put_index] = '\0';
			

			AssempleSemanticInfo(sem, lexeme, state);
			return state;

		case 2: // state 2 (number)

			lexeme[0] = nextcharacter;
			while ((nextcharacter = fgetc(fpointer)) != ' ') { // we know that if we see a space we need stop
				if (nextcharacter == EOF || nextcharacter == '\n') { // we are done with reading the file or we found a new line
					lexeme[put_index] = '\0';
					AssempleSemanticInfo(sem, lexeme, state);
					return state;
				}
				else if (!isdigit(nextcharacter)) {
					lexeme[put_index] = '\0';
					AssempleSemanticInfo(sem, lexeme, state);
					fseek(fpointer, -1, SEEK_CUR); // we readed a character while reading a number so we need to go back one character
					return state;
				}
				else {
					lexeme[put_index] = nextcharacter;
					put_index++;
				}

			}
			lexeme[put_index] = '\0';
			AssempleSemanticInfo(sem, lexeme, 2);
			return state;
		}

		
	}

		return 0;
}

