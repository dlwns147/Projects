#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int main(){
    set<string> s;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s1[6] = { 0, };
        char s2[6] = { 0, };
        scanf("%s %s", s1, s2);
        if (!strcmp(s2, "enter")) s.insert(s1);
        else if (!strcmp(s2, "leave")) s.erase(s1);
    }

    for (auto i = s.rbegin(); i != s.rend(); i++)
        cout << *i << '\n';

    return 0;
}