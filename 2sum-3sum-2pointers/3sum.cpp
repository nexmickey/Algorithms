//koliko ima trojki ciji je zbir jednak 0 - O(n^2 * log n)

#include<bits/stdc++.h>
using namespace std;

bool BinarnaPretraga(const vector <int> &v,const &trazeniBroj,const &n,const &granica)
{
    int l=granica,d=n-1,s;
    while(l<=d)
    {
        s=l+(d-l)/2;
        if(v[s]==trazeniBroj)
            return true;
        else if(v[s]>trazeniBroj)
            d=s-1;
        else l=s+1;
    }
    return false;
}

int main()
{
    int n, br=0,trazeniBroj;
    cin >> n;
    vector <int> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    for (int i=0;i<n-2;i++)
    {
        if(v[i]>0)
            break;
        for (int j=i+1;j<n-1;j++)
        {
            if(v[i]+v[j]>0)
                break;
            trazeniBroj=0-(v[i]+v[j]);
            if(BinarnaPretraga(v,trazeniBroj,n,j+1))
                br++;
        }
    }
    cout << br;
}
