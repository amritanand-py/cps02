#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int RE(int n,int k)
{
    return n==1 ? 1 : (RE(n-1,k)+k-1)%n+1;
}

int main() 
{
    int n,k;
    scanf("%d %d",&n,&k);
    
    printf("%d",RE(n,k));
    return 0;
}
