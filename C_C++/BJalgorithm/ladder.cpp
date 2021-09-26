#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int x = 0;
        int n;
        scanf("%d", &n);
        char c[2 * n] = { 0, };
        getline(cin, )
        int l[n];
        for (int j = 0; j < 2 * n; j += 2) l[j/2] = atoi(c[j]);
        for (int j = 0; j < n-1; j++)
            for (int k = 0; k < n - (j + 1); k++)
                if (l[k] > l[k + 1])
                {
                    int temp = l[k];
                    l[k] = l[k+1];
                    l[k+1] = temp;
                    x++;
                }

        cout << x << '\n';
    }

    return 0;
}