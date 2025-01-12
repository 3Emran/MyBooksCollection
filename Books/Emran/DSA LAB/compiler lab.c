#include<stdio.h>
int main(){
char input[100];
int i = 0;
printf("Enter a string in the format A ->aB: ");
fgets(input,sizeof(input),stdin);
while(input[i]!='\0'){
    if(input[i]=='-'&&input[i+1]=='>'){
        printf("Output:%s\n",&input[i+2]);
        return 0;
     }
        i++;
     }
     printf("Error:The input does not contain '->'.\n");
     return 1;
}
