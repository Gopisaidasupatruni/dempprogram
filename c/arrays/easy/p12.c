#include<stdio.h>

int main()
{
    char arr[] = {'A', 'B', 'c', 'd', 'E', 'f'};
    int *p = (int *)arr;
    int size = 0;  
    while ((char *)p < (char *)(arr + sizeof(arr))) {
        size++;
        p++;
    }
    printf("%d\n", size);
    return 0;
}

