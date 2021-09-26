#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, m;
    int x = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<int> vt[n+1];
    deque<int> dq;
    bool visit[n+1] = { 0, };

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }

    dq.push_back(1);
    while(!dq.empty())
    {
        int c = dq.back();
        dq.pop_back();
        if (!visit[c])
        {
            visit[c] = 1;
            x++;
        }
        for (auto i = vt[c].begin(); i != vt[c].end(); i++)
            if (!visit[*i]) dq.push_back(*i);
    }
    cout << x - 1;
    return 0;
}