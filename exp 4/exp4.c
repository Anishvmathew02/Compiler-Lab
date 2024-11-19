#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char state[5][10], closure[5][10][10];
int n;

void print_closure(char *c_state) {
    for (int i = 0; i < n; i++) {
        if (strcmp(c_state, state[i]) == 0) {
            printf("%s ", closure[i][0]);
            print_closure(closure[i][0]);
        }
    }
}

int main() {
    FILE *fp = fopen("transitions.txt", "r");
    char trans[5][3];
    if (!fp) {
        perror("Error opening file");
        exit(0);
    }
    
    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the states:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", state[i]);
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (fscanf(fp, "%s%s%s", trans[0], trans[1], trans[2]) != EOF) {
            if (strcmp(trans[1], "e") == 0 && strcmp(trans[0], state[i]) == 0) {
                strcpy(closure[i][j++], trans[2]);
            }
        }
        rewind(fp);
    }

    for (int i = 0; i < n; i++) {
    	printf("\nEpsilon closure of %s= ", state[i]);
        printf("%s ", state[i]);
        print_closure(state[i]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}
