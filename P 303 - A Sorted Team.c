#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int players[n], i, j, index;
    for(i=0;i<n;i++)
        scanf("%d",&players[i]);
    
    for(i=0;i<n-1;i++)
    {
        index = i;
        for(j=i+1;j<n;j++)
        {
            if(players[j] < players[index])
                index = j;
        }
        if(index != i)
        {
            int temp = players[index];
            players[index] = players[i];
            players[i] = temp;
        }
    }
    
    for(i=0;i<n;i++)
        printf("%d ",players[i]);
    
    return 0;
}
