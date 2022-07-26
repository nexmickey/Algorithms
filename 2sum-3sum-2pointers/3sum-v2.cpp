#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,br=0,l,d,x;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    for (int i=0;i<n-1;i++)
    {
        l=i+1;
        d=n-1;
        x=v[i];
        while(l<d)
        {
            if(v[i]+v[l]+v[d]==0)
            {
                cout << v[i] << " " << v[l] << " " << v[d] << endl;
                l++;
                d--;
                br++;
            }
            else if(v[i]+v[l]+v[d]>0)
                d--;
            else l++;
        }
    }
    cout << br;
}
