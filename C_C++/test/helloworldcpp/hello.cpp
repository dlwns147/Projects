#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "push 3";
    cout << s.substr(5, s.size());
    return 0;
}