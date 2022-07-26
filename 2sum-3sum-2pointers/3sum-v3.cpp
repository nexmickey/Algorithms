#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,br=0,x;
    cin >> n;
    vector<int> v(n);
    unordered_set<int> us;
    for (int i=0;i<n;i++)
        cin >> v[i];
    for (int i=0;i<n-1;i++)
    {
        us.clear();
        for (int j=i+1;j<n;j++)
        {
            x=-(v[i]+v[j]);
            if(us.find(x)!=us.end())
                br++;
            else
                us.emplace(v[j]);
        }
    }
    cout << br;
}
