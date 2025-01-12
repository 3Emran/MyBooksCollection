#include<stdio.h>
int main()
{
    int array[100];
    int i, n, e, p;
    printf(" Array Elements:");
    scanf(" %d", &n);
    for(i=0;i<n;i++)
    {
        scanf(" %d", &array[i]);
    }
    for(i=0;i<n;i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n The New Element:");
    scanf(" %d", &e);
    printf("\n Enter The Position:");
    scanf(" %d", &p);
    n=n+1;
    for(i=n-1; i>p; i--)
    {
        array[i]=array[i-1];
    }
    array[p-1] = e;
    for(i=0; i<n; i++)
    {
        printf(" %d", array[i]);
    }
    return 0;
}
