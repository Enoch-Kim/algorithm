#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxCount = 30000;
void dinamic(vector<string>& strs, string& t, int len, int idx, int count) {
    if(idx > len) return;
    if(count >= maxCount) return;
    if(idx == len){
        maxCount = count;
        return;
    }
    for(int i=0; i<strs.size(); ++i){
        if(t.find(strs[i], idx) == idx){
            dinamic(strs, t, len, idx + strs[i].length(), count+1);
        }
    }
}

int solution(vector<string> strs, string t)
{
    int answer = 0;
    sort(strs.begin(), strs.end(), [](string a, string b) {
        return a.length() >= b.length();
    });
    dinamic(strs, t, t.length(), 0, 0);
    answer = maxCount;
    if(answer == 30000) return -1;
    return answer;
}

int main() {
    vector<string> strs = {"afsdfsd", "afdsdss", "asds", "dsds", "sdfdsf"};
    sort(strs.begin(), strs.end(), [](string a, string b) {
        return a.length() >= b.length();
    });
    for(int i=0; i<strs.size(); ++i){
        cout << strs[i] << '\n';
    }
}