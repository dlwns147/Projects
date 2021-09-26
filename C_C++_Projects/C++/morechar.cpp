#include <iostream>

int main(){
    using namespace std;
    char ch = 'M';
    int i = ch;
    cout << ch << "의 ASCII 코드는 " << i << "입니다.\n";
    cout << "이 문자에 1을 더하면\n";
    i = ++ch;
    cout << ch << "의 ASCII 코드는 " << i << "입니다.\n";

    cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력 : ";
    cout.put(ch); cout.put('!');

    return 0;

}