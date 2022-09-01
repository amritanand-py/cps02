#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    unsigned int list[100000], n, i;
    scanf("%d",&n);
    for(i=0;i<n;i++)    scanf("%d",&list[i]);
    unsigned int minIndex = 0, minHeight = list[0];
    for(i=0;i<n;i++)
        if(minHeight > list[i])
        {
            minHeight = list[i];
            minIndex = i;
        }
    //printf("Index: %d\n\nHeight: %d",minIndex,minHeight);
    int temp = list[minIndex];
    list[minIndex] = list[0];
    list[0] = temp;
    
    for(i=0;i<n;i++)    printf("%d ",list[i]);
    return 0;
}
