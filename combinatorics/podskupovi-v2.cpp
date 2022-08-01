//podskupovi v2
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int>& podskup, int n)
{
    for (int i = 0; i < n; i++)
        cout << podskup[i] << " ";
    cout << endl;
}

void obradiSvePodskupove( vector<int>& skup, int i, vector<int>& podskup, int j)
{

    if (i == skup.size())
        obradi(podskup, j);
    else
    {
        obradiSvePodskupove(skup, i + 1, podskup, j);
        podskup[j] = skup[i];
        obradiSvePodskupove(skup, i + 1, podskup, j + 1);
    }
}

void obradiSvePodskupove( vector<int>& skup)
{
    vector<int> podskup(skup.size());
    obradiSvePodskupove(skup, 0, podskup, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<int> skup(n);
    for (int i = 0; i < n; i++)
        cin >> skup[i];
    obradiSvePodskupove(skup);
}

/*
3
1 2 3

3
2
2 3
1
1 3
1 2
1 2 3
*/
