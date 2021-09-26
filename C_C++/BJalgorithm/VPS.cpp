#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        stack<char> s;
        int e = 0;

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '(')
                s.push('(');
            else if (input[i] == ')')
            {
                if (!s.empty() && s.top() == '(') s.pop();
                else
                {
                    e++;
                    break;
                }
            }
        }

        if (!e && s.empty()) cout << "YES\n";
        else cout << "NO\n";
        while (!s.empty()) s.pop();
    }

    return 0;
}