#include <iostream>
#include <climits>

int main(){
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int는 " << sizeof(int) << "바이트 입니다\n";
    cout << "short는 " << sizeof n_short << "바이트 입니다\n";
    cout << "long은 " << sizeof sizeof n_long << "바이트 입니다.\n";
    cout << "long long은 " << sizeof n_llong << "바이트 입니다.\n\n";

    cout << "최댓값\n";
    cout << "int : " << INT_MAX << endl;
    cout << "short : " << n_short << endl;
    cout << "long : " << n_long << endl;
    cout << "long long : " << n_llong << endl;
    cout << "int 최솟값 : " << INT_MIN << endl;
    cout << "바이트 당 비트 수 : " << CHAR_BIT << endl;

    return 0;
}