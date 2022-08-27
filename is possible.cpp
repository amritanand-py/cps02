#include <bits/stdc++.h>
using namespace std;
bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (sx < tx && sy < ty)
      if (tx > ty)
        tx %= ty;
      else
        ty %= tx;

    return sx == tx && sy <= ty && (ty - sy) % sx == 0 ||
           sy == ty && sx <= tx && (tx - sx) % sy == 0;
  }
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(reachingPoints(a,b,c,d))
        cout<<"Yes";
        else cout<<"No";
}