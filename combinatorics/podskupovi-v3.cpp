//podskupovi v3
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int>& podskup)
{
    for (int i = 0; i < podskup.size(); i++)
        cout << podskup[i] << " ";
    cout << endl;
}

bool sledeciPodskup(vector<int>& podskup, int n)
{
    if (podskup.empty())
    {
        podskup.push_back(1);
        return true;
    }
    if (podskup.back() < n)
    {
        podskup.push_back(podskup.back() + 1);
        return true;
    }
    podskup.pop_back();
    if (podskup.empty())
        return false;
    podskup.back()++;
    return true;
}

void obradiPodskupove(int n)
{
    vector<int> podskup;
    do
    {
        obradi(podskup);
    }
    while (sledeciPodskup(podskup, n));
}

int main()
{
    int n;
    cin >> n;
    obradiPodskupove(n);
}

/*
3

1
1 2
1 2 3
1 3
2
2 3
3
*/

