#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<int> s,ma;
    int m = -1;
    int q,t,v;
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> v;
            if(ma.empty())
                ma.push(v);
            else if(v > ma.top())
            {
                ma.push(v);
            }
            s.push(v);
        }
        else if(t == 2)
        {
            if(s.top() == ma.top())
            {
                ma.pop();
            }
            s.pop();
        }
        else if(t == 3)
        {
            cout << ma.top() << endl;
        }
    }
    return 0;
}
