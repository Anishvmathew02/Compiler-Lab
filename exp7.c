#include<stdio.h>
#include<time.h>

void func1(){
   for(int i=0; i<5; i++){
      printf("Hello\n");
   }
}

void func2(){
   printf("Hello\n");
   printf("Hello\n");
   printf("Hello\n");
   printf("Hello\n");
   printf("Hello\n");
}

int main(){
   clock_t t1, t2;
   
   t1 = clock();
   func1();
   t1 = clock() - t1;
   double timeTaken1 = ((double)t1)/CLOCKS_PER_SEC;
   printf("/Normal loop\n");
   printf("Time taken: %lf\n\n", timeTaken1);
   
   t2 = clock();
   func2();
   t2 = clock() - t2;
   double timeTaken2 = ((double)t2)/CLOCKS_PER_SEC;
   printf("/Unrolled loop\n");
   printf("Time taken: %lf\n", timeTaken2);
}






