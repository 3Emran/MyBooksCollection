#include<stdio.h>
int main()
{
    int array[100], i, n, search;
    printf("Enter The Number of elements:");
    scanf("%d", &n);
    printf("Enter %d integer\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the number to search: \n");
    scanf("%d", &search);
    for(i=0;i<n;i++)
    {
        if(array[i] == search)
        {
            printf("%d is present at location %d\n", search, search);
            break;
        }
    }
    if(array[i] != search)
    {
        printf("%d is not present in the array\n", search);
    }
    return 0;
}
