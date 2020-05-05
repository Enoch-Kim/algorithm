#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

inline bool isSign(char a){
    return a>='a' && a<='z';
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    if(sentence.length() == 1){
        if(isSign(sentence[0]))
            return "invalid";
        else
            return sentence;
    }
    unordered_map<char, vector<int>> signMap;
    string answer = "";
    for(int i=0; i<sentence.length(); ++i)
    {
        if(isSign(sentence[i]))
        {
            signMap[sentence[i]]
        }
    }
        
        
    
    
    return answer;
}

int main(){

}
// 2:00