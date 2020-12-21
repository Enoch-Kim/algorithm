/*
    https://www.acmicpc.net/problem/2588
    2020-12-16
*/
#include <iostream>

using namespace std;



int main() {
    int A, B;
    cin >> A >> B;

    if(A/1000 || !A/100 || B/1000 || !B/100) {
        printf("A 또는 B가 세자리 수가 아닙니다.\n");
        exit(1);
    }

    cout 
    << A*(B%10) << '\n'
    << A*(B%100/10) << '\n'
    << A*(B%1000/100) << '\n'
    << A*B << '\n';
}