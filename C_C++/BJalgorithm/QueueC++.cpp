#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        string order;
        getline(cin, order);

        if (order.find("push") != string::npos)
            q.push(stoi(order.substr(5, order.size())));
        else if (order == "pop") {
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }

        else if (order == "size") cout << q.size() << endl;
        else if (order == "empty") cout << q.empty() << endl;
        else if (order == "front"){
            if(!q.empty()) cout << q.front() << endl;
            else cout << "-1\n";
        }
        else if (order == "back"){
            if(!q.empty()) cout << q.back() << endl;
            else cout << "-1\n";
        }
    }
    return 0;
}