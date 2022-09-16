#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int stack[100005], top = -1;

void push(int n)
{
    stack[++top] = n;
}

int pop()
{
    return stack[top--];
}

int main() 
{
    int ngc;
    scanf("%d",&ngc);
    
    int bag[ngc],i;
    for(i=0;i<ngc;i++)
        scanf("%d",&bag[i]);
    int nop, total;
    scanf("%d %d",&nop,&total);
    int sum = 0;
    i = 0;
    while(nop--)
    {
        char str[10];
        scanf("%s",str);
        if(strcmp(str,"Harry") == 0)
        {
            push(bag[i]);
            sum = sum + bag[i];
            if(sum == total)
            {
                printf("%d",top+1);
                return 0;
            }
            i++;
        }
        if(strcmp(str,"Remove") == 0)
        {
            sum = sum - pop();
        }
    }
    return 0;
}