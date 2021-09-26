#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    stack <int> s;
    string str1;
    cin >> str1;
    if (str1.length() % 2)
    {
        cout << '0';
        exit(0);
    }

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == '(')
            s.push(-1);

        else if (str1[i] == '[')
            s.push(-2);

        else if (str1[i] == ')')
        {
            while (1)
            {
                if (!s.empty() && s.top() == -1)
                {
                    s.pop();
                    s.push(2);
                    break; 
                }

                else if (!s.empty() && s.top() >= 0)
                {
                    int a = s.top();
                    s.pop();
                    
                    if (!s.empty() && s.top() >= 0)
                    {
                        int b = s.top();
                        s.pop();
                        s.push(a + b);
                    }

                    else if (!s.empty() && s.top() == -1)
                    {
                        s.pop();
                        s.push(2 * a);
                        break;
                    }

                    else 
                    {
                        cout << '0';
                        exit(0);
                    }
                }

                else 
                {
                    cout << '0';
                    exit(0);
                }
            }
        }
        
        else if (str1[i] == ']')
        {
            while (1)
            {
                if (!s.empty() && s.top() == -2)
                {
                    s.pop();
                    s.push(3);
                    break; 
                }

                else if (!s.empty() && s.top() >= 0)
                {
                    int a = s.top();
                    s.pop();
                    
                    if (!s.empty() && s.top() >= 0)
                    {
                        int b = s.top();
                        s.pop();
                        s.push(a + b);
                    }

                    else if (!s.empty() && s.top() == -2)
                    {
                        s.pop();
                        s.push(3 * a);
                        break;
                    }
                    else 
                    {
                        cout << '0';
                        exit(0);
                    }
                }

                else 
                {
                    cout << '0';
                    exit(0);
                }
            }
        }
    }

    while(s.size() > 1)
    {
        int a = s.top();
        if (a < 0)
        {
            cout << '0';
            exit(0);
        }
        s.pop();
        int b = s.top();
        if (b < 0)
        {
            cout << '0';
            exit(0);
        }
        s.pop();
        s.push(a + b);
        
    }

    if (s.top() > 0)
        cout << s.top();
    else 
        cout << 0;
        
    return 0;
}