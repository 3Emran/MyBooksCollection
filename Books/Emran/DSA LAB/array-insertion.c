#include <stdio.h>

int main()
{
    int array[100];
    int n,e,p,i;
    printf("Array Elements:");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&array[i]);
    }
    for(i =0; i<n; i++){
        printf("%d",array[i]);
    }
    printf("The new element: ");
    scanf("%d",&e);
    printf("Enter the position: ");
    scanf("%d",&p);
    n=n+1;
    for(i=n-1; i>=p; i--){
        array[i]=array[i-1];
    }
    array[p-1]=e;
    for(i=0; i<n; i++){
        printf("%d",array[i]);
    }
}
