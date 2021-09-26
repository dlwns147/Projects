#include <iostream>
#include <cstdio>
#include <list>
#include <string>
using namespace std;

int main() {
    char s[100000] = { 0, };
    scanf("%s", s);
    list<char> vt;
    for (int i = 0; s[i] != 0; i++) vt.push_back(s[i]);
    auto it = vt.end();

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        char c[4] = { 0, };
        scanf(" %[^\n]s", c);
        if (c[0] == 'L' && it != vt.begin())
         it--;
        else if (c[0] == 'D' && it != vt.end())
         it++;
        else if (c[0] == 'B' && it != vt.begin())
         it = vt.erase(--it);
        else if (c[0] == 'P') it = ++vt.insert(it, c[2]);
    }

    for (auto i = vt.begin(); i != vt.end(); i++) cout << *i;
    
    return 0;
}