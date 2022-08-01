//broj zabinih skokova - greedy
#include <bits/stdc++.h>
using namespace std;

int brojSkokova(const vector<int>& kamenje,int n,int r)
{
    int broj=0;
    int kamen=0;
    while(kamen<n-1)
    {
        int noviKamen=kamen;
        while (noviKamen+1<n && kamenje[noviKamen + 1]-kamenje[kamen]<=r)
            noviKamen++;
        if(noviKamen==kamen)
            return n;
        broj++;
        kamen=noviKamen;
    }
    return broj;
}

int main()
{
    int n,r;
    cin >> n >> r;
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    cout << brojSkokova(v,n,r);
}
/*
5 3
1 3 4 6 8
3
*/
