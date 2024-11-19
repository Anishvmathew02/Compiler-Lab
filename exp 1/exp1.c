#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(const char *buffer) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", 
        "double", "else", "enum", "extern", "float", "for", "goto", "if", 
        "int", "long", "register", "return", "short", "signed", "sizeof", 
        "static", "struct", "switch", "typedef", "union", "unsigned", 
        "void", "volatile", "while", NULL
    };
    for (int i = 0; keywords[i]; i++){ 
    	if (strcmp(keywords[i], buffer) == 0) 
    	return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[15]; 
    int j = 0;
    FILE *fp = fopen("inp.txt", "r");
    if (!fp) {
    	printf("error while opening the file\n");
    	exit(0);
    }
    	

    while ((ch = fgetc(fp)) != EOF) {
        if (strchr("+-*/%=;", ch)) {
            if (j) { 
		    buffer[j] = '\0'; 
		    printf("%s is %s\n", buffer, isKeyword(buffer) ? "keyword" : "identifier"); 
		    j = 0; 
            }
            printf("%c is operator\n", ch);
        } 
        else if (isalnum(ch)) 
        	buffer[j++] = ch; 
        else if ((ch == ' ' || ch == '\n') && j) {
            buffer[j] = '\0'; 
            printf("%s is %s\n", buffer, isKeyword(buffer) ? "keyword" : "identifier"); 
            j = 0;
        }
    }
    
    fclose(fp);
    return 0;
}



