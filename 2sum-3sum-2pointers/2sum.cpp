// koliko ima parova brojeva ciji je zbir jednak datom broju
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int broj, n, br = 0;
    cin >> broj >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int l = 0, d = n - 1;
    while(l < d)
    {
        if(v[l] + v[d] == broj)
        {
            br++;
            l++;
            d--;
        }
        else if(v[l] + v[d] > broj)
            d--;
        else l++;
    }
    cout << br;
}
