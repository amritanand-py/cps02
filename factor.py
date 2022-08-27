from math import sqrt
l=[]
def pthFactor(n, p):
    k=int(sqrt(n))+1
    for i in range(1,k,1):
        if n%i==0:
            l.append(i)
            if(i!=sqrt(n)):
                l.append(int(n/i))
    l.sort(reverse=False)
    if(p>len(l)):
        print("0")
    else:
        print(l[p-1])
    
n=int(input())
p=int(input())
pthFactor(n,p)