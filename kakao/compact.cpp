#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;
    for(int i=1; i<=len/2; ++i){
        int compact = 0;
        int count = 0;
        string prev = "";
        for(int j=0; j<len/i; ++j){
            string temp = s.substr(j*i, i);
            if(temp == prev){
                count++;
            }else{
                if(count) compact++;
                count = 0;
                prev = temp;
                compact+=temp.length();
            }
        }
        if(count) compact++;
        compact += len%i;
        cout << compact << '\n';
        answer = min(answer, compact);
    }
    return answer;
}
// 1:30

int main() {
    string s = "abcabcabcabcacbcscsd";
    cout << solution(s) << '\n';
    // cout << s.substr(17,3).length() << '\n';
    // cout << 17%1 << '\n';
}