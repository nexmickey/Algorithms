#include <bits/stdc++.h>
using namespace std;

int main()
{
    int niz[] = {12, 1, 78, 90, 57, 89, 56};
    stack<int> S;
    queue<int> q;
    deque<int> d;
    int n = 7, k = 3;
    //int n = 16;
     for (int i=0; i<k; i++)
    {
         while ( (!d.empty()) && niz[i] <= niz[d.back()])
            d.pop_back();

         d.emplace_back(i);
    }
    for (int i=k; i<n; i++)
    {
        cout << niz[d.front()] << " ";
        while ( (!d.empty()) && d.front() <= i - k)
            d.pop_front();

        while ( (!d.empty()) && niz[i] <= niz[d.back()])
            d.pop_back();

        d.emplace_back(i);
    }
    cout << niz[d.front()];
}
