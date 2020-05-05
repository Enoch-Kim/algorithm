#include <iostream>
using namespace std;



void countThree(int& ans, int n,int maxMult , int mult, int plus){
    if(maxMult<mult || maxMult*2<plus || mult*2 > plus || n<3)
        return;
    if(n%3==0){
        
        if(n == 3 && ((mult+1)*2 == plus)){
            cout << "mult+1*2 is " << (mult+1)*2 << '\n';
            cout << "plus is" << plus << '\n';
            ans++;
            return;
        }
        countThree(ans, n/3,maxMult, mult+1, plus);
        countThree(ans, n-3,maxMult, mult, plus+3);
    }else{
        countThree(ans, n-(n%3),maxMult, mult, plus+n%3);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    int answer = 0;
    int maxMult =1;
    for(int i=n; i>0; i/=3){
        maxMult++;
    }
    countThree(answer, n, maxMult, 0, 0);
    return answer;
}

// 5:03


int main() {
    cout << solution(2147483647) << '\n'; 

}