#include <stdio.h>
#include <string.h>

char op[2],arg1[5],arg2[5],result[5];

void main(){
	FILE *fp1,*fp2;
	char f[100];
	printf("Enter input file name: ");
	scanf("%s",f);
	fp1=fopen(f,"r");
	fp2=fopen("output.txt","w");
	

	while(!feof(fp1)){
		fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result);
		
		if(strcmp(op,"+")==0){
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nADD R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",result);
		}
		if(strcmp(op,"*")==0){
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nMUL R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",result);
		}
		if(strcmp(op,"-")==0){
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nSUB R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",result);
		}
		if(strcmp(op,"/")==0){
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nDIV R0,%s",arg2);
			fprintf(fp2,"\nMOV %s,R0",result);
		}
		if(strcmp(op,"=")==0){
			fprintf(fp2,"\nMOV R0,%s",arg1);
			fprintf(fp2,"\nMOV %s,R0",result);
		}
	}
	fprintf(fp2,"\n");
	fclose(fp1);
	fclose(fp2);
	getchar();
}





