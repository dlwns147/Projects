#include <iostream>
#define ZERO 0
#include <climits>

int main(){
    using namespace std;
    short Dohee = SHRT_MAX;
    unsigned short Insuk = Dohee;

    cout << "도희의 계좌에는 " << Dohee << "원이 들어 있고, 인숙의 계좌에도 " << Insuk << "원이 들어 있다.\n";
    cout << "각각의 계좌에 1원씩 입금한다.\n이제 ";
    Dohee++; Insuk++;
    cout << "도희의 잔고에는 " << Dohee << "원이 되었고, 인숙의 잔고는 " << Insuk << "원이 되었다.\n";
    cout << "이럴수가! 도희가 나 몰래 대출 했나?\n";
    Dohee = Insuk = ZERO;
    cout << "도희의 계좌에는 " << Dohee << "원이 있고, 인숙의 계좌에는 " << Insuk << "원이 있다.\n";
    cout << "각각의 계좌에서 1원씩 인출한다.\n이제";
    Dohee--; Insuk--;
    cout << "도희의 잔고는 " << Dohee << "원이 되었고, 인숙의 잔고는 " << Insuk << "원이 되었다\n";
    cout << "이럴수가! 인숙이가 복권에 당첨됬나?\n";

    return 0;

}