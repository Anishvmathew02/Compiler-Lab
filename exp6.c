#include <stdio.h>
#include <string.h>

char a[16], stk[15];
int i = 0, j = 0, len = 0;

void check(){
    while(1) {
    	
        if (i>=2 && strncmp(&stk[i - 2], "id", 2) == 0) {
            stk[i - 2] = 'E';
            stk[i -= 1] = '\0'; 
            printf("\n$%s\t%s$\tREDUCE TO E", stk, &a[j]);
        } 
        else if (i>=3 &&
        	 (strncmp(&stk[i - 3],"E+E",3) == 0 || strncmp(&stk[i - 3],"E*E",3) == 0 || strncmp(&stk[i - 3],"(E)",3) == 0)
        	){
            stk[i - 3] = 'E';
            stk[i -= 2] = '\0';
            printf("\n$%s\t%s$\tREDUCE TO E", stk, &a[j]);
        }
        else {
            break;
        }
    }
}


int main() {
    printf("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id\n\nEnter input string: ");
    scanf("%s", a);
    len = strlen(a);

    printf("\nstack\tinput\taction\n");
    printf("$\t%s$", a);
    while (j < len) {  
        if (a[j] == 'i' && a[j + 1] == 'd') {
            stk[i++] = 'i';  
            stk[i++] = 'd';
            stk[i] = '\0';
            j += 2;  
            printf("\n$%s\t%s$\tSHIFT->id", stk, &a[j]);
        }
        else {
            stk[i++] = a[j++];
            stk[i] = '\0';
            printf("\n$%s\t%s$\tSHIFT->symbol", stk, &a[j]);
        }
        
        check();
    }
    
    printf("\n\n\t%s\n\n",strcmp(stk, "E")==0 ? "ACCEPT" : "REJECT");

    return 0;
}



