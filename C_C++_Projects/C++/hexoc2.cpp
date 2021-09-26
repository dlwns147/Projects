#include <iostream>

using namespace std;

int main(){
    cout << "손님 몸매는 끝내줍니다!\n";
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "가슴둘레 : " << chest << " (10진수)\n" << hex;
    cout << "허리둘레 : " << waist << " (16진수)\n" << oct;
    cout << "인심길이 : " << inseam << " (8진수)\n";

    return 0;
}