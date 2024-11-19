#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char expression[50], leftOperand[5], rightOperand[5];
int operatorCounter=0, tempChar=90;

struct operatorStruct{
   int pos;
   char op;
}operators[10];

void findLeftOperand(int position){
   int charIndex = 0;
   position--;
   while(expression[position]!=':' && expression[position]!='/' && expression[position]!='*' && expression[position]!='+' && expression[position]!='-'){
        if(expression[position]!='$'){
           leftOperand[charIndex++] = expression[position];
           leftOperand[charIndex] = '\0';
           expression[position] = '$';
        }
        position--;
   }
}

void findRightOperand(int position){
   int charIndex = 0;
   position++;
   while(expression[position]!=':' && expression[position]!='/' && expression[position]!='*' && expression[position]!='+' && expression[position]!='-' && expression[position]!='\0'){
        if(expression[position]!='$'){
           rightOperand[charIndex++] = expression[position];
           rightOperand[charIndex] = '\0';
           expression[position] = '$';
        }
        position++;
   }
}

void generateCode(){
   for(int i=1; i<operatorCounter; i++){
       findLeftOperand(operators[i].pos);
       findRightOperand(operators[i].pos);
       expression[operators[i].pos] = tempChar--;
       printf("%c := %s %c %s\n", expression[operators[i].pos], leftOperand, operators[i].op, rightOperand);
   }
   findRightOperand(-1);
   findLeftOperand(strlen(expression));
   printf("%s := %s\n", rightOperand, leftOperand);
}


void findOperators(){
   for(int i=0; expression[i]!='\0'; i++){
      if(expression[i]==':'){
         operators[operatorCounter].pos = i;
         operators[operatorCounter++].op = ';';
      }
   }
   for(int i=0; expression[i]!='\0'; i++){
      if(expression[i]=='/'){
         operators[operatorCounter].pos = i;
         operators[operatorCounter++].op = '/';
      }
   }
   for(int i=0; expression[i]!='\0'; i++){
      if(expression[i]=='*'){
         operators[operatorCounter].pos = i;
         operators[operatorCounter++].op = '*';
      }
   }
   for(int i=0; expression[i]!='\0'; i++){
      if(expression[i]=='+'){
         operators[operatorCounter].pos = i;
         operators[operatorCounter++].op = '+';
      }
   }
   for(int i=0; expression[i]!='\0'; i++){
      if(expression[i]=='-'){
         operators[operatorCounter].pos = i;
         operators[operatorCounter++].op = '-';
      }
   }
}


int main(){
   printf("Intermediate code generation\n\n");
   printf("Enter the expression:  ");
   scanf("%s", expression);
   
   findOperators();
   generateCode();
   
   return 0;
}







