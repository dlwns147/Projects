#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m ,v;
    scanf("%d %d %d", &n, &m, &v);
    vector<int> vt[n + 1];
    deque<int> dq;
    bool visit[n + 1] = { 0, };

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a ,&b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    dq.push_back(v);
    while(!dq.empty())
    {
        int c = dq.back();
        dq.pop_back();
        if (!visit[c])
        {
            visit[c] = 1;
            cout << c << ' ';
        }
        sort(vt[c].rbegin(), vt[c].rend());
        for (auto i = vt[c].begin(); i != vt[c].end(); i++)
            if (!visit[*i]) dq.push_back(*i);
    }

    dq.clear();
    cout << "\n";
    fill_n(visit, sizeof(visit), 0);

    dq.push_back(v);
    while(!dq.empty())
    {
        int c = dq.front();
        dq.pop_front();
        if (!visit[c])
        {
            visit[c] = 1;
            cout << c << ' ';
        }
        sort(vt[c].begin(), vt[c].end());
        for (auto i = vt[c].begin(); i != vt[c].end(); i++)
            if (!visit[*i]) dq.push_back(*i);
    }

    return 0;
}