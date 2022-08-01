//podskupovi v1
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int>& podskup)
{
    for (int i = 0; i < podskup.size(); i++)
        cout << podskup[i] << " ";
    cout << endl;
}

void obradiSvePodskupove(vector<int> skup, vector<int>& podskup)
{
    if (skup.size() == 0)
        obradi(podskup);
    else
    {
        int x = skup.back();
        skup.pop_back();
        obradiSvePodskupove(skup, podskup);
        podskup.push_back(x);
        obradiSvePodskupove(skup, podskup);
        podskup.pop_back();
    }
}

void obradiSvePodskupove(const vector<int>& skup)
{
    vector<int> podskup;
    podskup.reserve(skup.size());
    vector<int> kopijaSkupa;
    kopijaSkupa = skup;
    obradiSvePodskupove(kopijaSkupa, podskup);
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

1
2
2 1
3
3 1
3 2
3 2 1
*/
